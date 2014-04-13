
#ifndef _NETWORK_BROFILER_H_
#define _NETWORK_BROFILER_H_

#include <stack>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/shared_ptr.hpp>

#include "brofiler_dyn_network/ActivityResult.h"
#include "brofiler_dyn_network/common.h"
#include "brofiler_static/IDynBrofiler.h"


class Brofiler_Dyn_Network_EXPORT NetworkBrofiler : public IDynBrofiler
{
public:
    NetworkBrofiler();
    virtual ~NetworkBrofiler();
    
    boost::shared_ptr<IActivity> createActivity(const std::string& name);
    std::string toString() const;
    
private:
    void addResult(const ActivityResult& result);
    void printDepth();
    
    unsigned int actCounter_;
    std::stack<unsigned int> activeActivity_;
    boost::posix_time::ptime profilingStart_;

    //NOTE: Tried shared-ptrs here, which should work but did not...
    void* zmqContext_;
    void* zmqSender_;
};

#endif //_NETWORK_BROFILER_H_