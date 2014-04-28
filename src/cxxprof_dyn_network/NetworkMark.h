
#ifndef _NETWORK_MARK_H_
#define _NETWORK_MARK_H_

#include "cxxprof_dyn_network/common.h"
#include <stdint.h>
#include <string>

namespace CxxProf
{

    struct CxxProf_Dyn_Network_EXPORT NetworkMark
    {
        std::string Name;
        uint64_t Timestamp;

        NetworkMark() :
            Name(""),
            Timestamp(0)
        {}
    };

}

#endif //_NETWORK_MARK_H_
