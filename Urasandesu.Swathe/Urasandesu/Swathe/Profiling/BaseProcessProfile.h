#pragma once
#ifndef URASANDESU_SWATHE_PROFILING_BASEPROCESSPROFILE_H
#define URASANDESU_SWATHE_PROFILING_BASEPROCESSPROFILE_H

#ifndef URASANDESU_SWATHE_TRAITS_REPLACE_H
#include <Urasandesu/Swathe/Traits/Replace.h>
#endif

#ifndef URASANDESU_SWATHE_HEAPPROVIDER_HPP
#include <Urasandesu/Swathe/HeapProvider.hpp>
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

    struct DefaultInfoProfilingApi;

    template<
        class InfoProfilingApiType
    >
    class BaseAppDomainProfile;

    template<
        class InfoProfilingApiType
    >
    class BaseAssemblyProfile;

    template<
        class InfoProfilingApiType
    >
    class BaseModuleProfile;

    template<
        class InfoProfilingApiType
    >
    class BaseTypeProfile;

    template<
        class InfoProfilingApiType
    >
    class BaseMethodProfile;

    template<
        class InfoProfilingApiType
    >
    class BaseMethodBodyProfile;

    template<
        class InfoProfilingApiType = boost::use_default
    >
    class BaseProcessProfile : 
        public IProfilingApiOperable<
            BaseProcessProfile<InfoProfilingApiType>, 
            typename UNT::Replace<InfoProfilingApiType, boost::use_default, DefaultInfoProfilingApi>::type
        >
    {
        SWATHE_BEGIN_HEAP_PROVIDER_DECLARATION()
            SWATHE_HEAP_PROVIDER(BaseAppDomainProfile<InfoProfilingApiType>, UINT_PTR, m_pDomainProfFactory);
            SWATHE_HEAP_PROVIDER(BaseAssemblyProfile<InfoProfilingApiType>, UINT_PTR, m_pAsmProfFactory);
            SWATHE_HEAP_PROVIDER(BaseModuleProfile<InfoProfilingApiType>, UINT_PTR, m_pModProfFactory);
            SWATHE_HEAP_PROVIDER(BaseTypeProfile<InfoProfilingApiType>, UINT_PTR, m_pTypeProfFactory);
            SWATHE_HEAP_PROVIDER(BaseMethodProfile<InfoProfilingApiType>, UINT_PTR, m_pMethodProfFactory);
            SWATHE_HEAP_PROVIDER(BaseMethodBodyProfile<InfoProfilingApiType>, UINT_PTR, m_pMethodBodyProfFactory);
        SWATHE_END_HEAP_PROVIDER_DECLARATION()
        
    public:
        BaseAppDomainProfile<InfoProfilingApiType> *GetPseudoDomain()
        {
            return CreatePseudo<BaseAppDomainProfile<InfoProfilingApiType>>();
        }
        
        BaseAppDomainProfile<InfoProfilingApiType> *GetCurrentDomain()
        {
            return GetHeapManager()->Peek<BaseAppDomainProfile<InfoProfilingApiType>>();
        }
    };

    typedef BaseProcessProfile<boost::use_default> ProcessProfile;

#undef UNT

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_BASEPROCESSPROFILE_H