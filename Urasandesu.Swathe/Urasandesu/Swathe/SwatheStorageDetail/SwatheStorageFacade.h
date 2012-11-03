#pragma once
#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADE_H
#define URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADE_H

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_HOSTINFOLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/HostInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
#endif

#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIAT_H
#include <Urasandesu/Swathe/SwatheStorageDetail/SwatheStorageApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADEFWD_H
#include <Urasandesu/Swathe/SwatheStorageDetail/SwatheStorageFacadeFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

    namespace SwatheStorageFacadeDetail {

        using Urasandesu::CppAnonym::StaticDependentObjectsStorage;
        using Urasandesu::Swathe::Hosting::Interfaces::HostInfoLabel;

        template<
            class SwatheStorageApiHolder
        >    
        struct SwatheStorageFacadeImpl
        {
            typedef typename SwatheStorageApiAt<SwatheStorageApiHolder, HostInfoLabel>::type host_info_type;
            typedef StaticDependentObjectsStorage<host_info_type> base_type;
        };

    }   // namespace SwatheStorageFacadeDetail {

    template<
        class SwatheStorageApiHolder
    >    
    struct SwatheStorageFacade : 
        SwatheStorageFacadeDetail::SwatheStorageFacadeImpl<SwatheStorageApiHolder>
    {
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

#endif  // URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADE_H