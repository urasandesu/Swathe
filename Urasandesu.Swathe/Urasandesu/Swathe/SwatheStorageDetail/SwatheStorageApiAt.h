#pragma once
#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIAT_H
#define URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIAT_H

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_SWATHE_INTERFACES_SWATHESTORAGEAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Interfaces/SwatheStorageApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIATFWD_H
#include <Urasandesu/Swathe/SwatheStorageDetail/SwatheStorageApiAtFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

    namespace SwatheStorageApiAtDetail {

        using Urasandesu::Swathe::Interfaces::SwatheStorageApiHolderLabel;
        using Urasandesu::CppAnonym::Traits::ApiAt;

        template<class ApiCartridgesHolder, class ApiLabel>
        struct SwatheStorageApiAtImpl : 
            ApiAt<ApiCartridgesHolder, SwatheStorageApiHolderLabel, ApiLabel>
        {
        };

    }   // namespace SwatheStorageApiAtDetail {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct SwatheStorageApiAt : 
        SwatheStorageApiAtDetail::SwatheStorageApiAtImpl<ApiCartridgesHolder, ApiLabel>
    {
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

#endif  // URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIAT_H