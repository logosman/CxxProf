
#include "brofiler_dyn/NetworkBrofiler.h"
#include "brofiler_dyn/NetworkActivity.h"

#include <zhelpers.h>
#include <boost/bind.hpp>
#include <iostream>

NetworkBrofiler::NetworkBrofiler() :
    actCounter_(1),
    profilingStart_(boost::posix_time::microsec_clock::local_time()),
    zmqContext_(zmq_ctx_new()),
    zmqSender_(zmq_socket(zmqContext_, ZMQ_PUSH))
{
    zmq_connect(zmqSender_, "tcp://localhost:15232");
}

NetworkBrofiler::~NetworkBrofiler()
{
    zmq_close(zmqSender_);
    zmq_ctx_destroy(zmqContext_);
}

boost::shared_ptr<IActivity> NetworkBrofiler::createActivity(const std::string& name)
{
    unsigned int newActId = actCounter_++;

    boost::shared_ptr<NetworkActivity> newAct(new NetworkActivity(  name, 
                                                                    newActId, 
                                                                    0, //TODO: Get a Thread-ID
                                                                    0, //we're setting the parentId later
                                                                    profilingStart_,
                                                                    boost::bind(&NetworkBrofiler::addResult, this, _1)));
    
    //check if this is the newest Activity
    if (activeActivity_.empty())
    {
        newAct->setParentId(0);
    }
    else
    {
        newAct->setParentId(activeActivity_.top());
    }

    //make the new activity the active one
    newAct->start();
    activeActivity_.push(newActId);

    printDepth();
    std::cout << name << " started" << std::endl;
    
    return newAct;
}

void NetworkBrofiler::addResult(const ActivityResult& result)
{
    printDepth();
    std::cout << result.Name << " ended: " << result.StopTime - result.StartTime << " millisec" << std::endl;
    activeActivity_.pop();

    //send the activity data via network
    s_send(zmqSender_, "YEAH!");
}

void NetworkBrofiler::printDepth()
{
    for (unsigned int depth = 0; depth < activeActivity_.size(); ++depth)
    {
        std::cout << "| ";
    }
}

std::string NetworkBrofiler::toString() const
{
    return "NetworkBrofiler";
}
