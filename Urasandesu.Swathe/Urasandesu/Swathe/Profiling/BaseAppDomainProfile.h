#pragma once
#ifndef URASANDESU_SWATHE_PROFILING_BASEAPPDOMAINPROFILE_H
#define URASANDESU_SWATHE_PROFILING_BASEAPPDOMAINPROFILE_H

#ifndef URASANDESU_SWATHE_TRAITS_REPLACE_H
#include <Urasandesu/Swathe/Traits/Replace.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling {

#ifdef UNT
#error This .h reserves the word "UNT" that means "Urasandesu::Swathe::Traits".
#endif
#define UNT Urasandesu::Swathe::Traits

    template<
        class HeapManagerType,
        class ApiType
    >        
    class ATL_NO_VTABLE IProfilingApiOperable;

    template<
        class InfoProfilingApiType
    >
    class BaseProcessProfile;

    struct DefaultInfoProfilingApi;

    template<
        class InfoProfilingApiType = boost::use_default
    >
    class BaseAppDomainProfile : 
        public IProfilingApiOperable<
            BaseProcessProfile<InfoProfilingApiType>, 
            typename UNT::Replace<InfoProfilingApiType, boost::use_default, DefaultInfoProfilingApi>::type
        >
    {
    };

    typedef BaseAppDomainProfile<boost::use_default> AppDomainProfile;

#undef UNT

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_BASEAPPDOMAINPROFILE_H