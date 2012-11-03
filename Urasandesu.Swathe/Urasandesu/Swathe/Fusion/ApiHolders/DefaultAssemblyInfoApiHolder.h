#pragma once
#ifndef URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDER_H
#define URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDER_H

#ifndef URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Fusion/ApiHolders/DefaultAssemblyInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {
    
    namespace DefaultAssemblyInfoApiHolderDetail {
        
        using boost::mpl::map;
        using boost::mpl::pair;
        using namespace Urasandesu::Swathe::Fusion::Interfaces;

        struct DefaultAssemblyInfoApiHolderImpl
        {
            typedef map<
                pair<FusionInfoLabel, FusionInfo>
            > api_cartridges;
        };

    }   // namespace DefaultAssemblyInfoApiHolderDetail {

    struct DefaultAssemblyInfoApiHolder : 
        DefaultAssemblyInfoApiHolderDetail::DefaultAssemblyInfoApiHolderImpl
    {
    };
        
}}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {

#endif  // URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDER_H