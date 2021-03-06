
#ifndef _I_DYN_CXXPROF_PROVIDER_H_
#define _I_DYN_CXXPROF_PROVIDER_H_

#include <Pluma/Pluma.hpp>
#include "cxxprof_static/IDynCxxProf.h"

namespace CxxProf
{
    /**
     * This is needed for Pluma in order to load the DynCxxProf plugins
     */
    PLUMA_PROVIDER_HEADER(IDynCxxProf);
    PLUMA_PROVIDER_SOURCE(IDynCxxProf, 1, 1);

} //namespace CxxProf

#endif //_I_DYN_CXXPROF_PROVIDER_H_
