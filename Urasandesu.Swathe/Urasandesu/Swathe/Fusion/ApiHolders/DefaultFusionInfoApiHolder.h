#pragma once
#ifndef URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H
#define URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/Swathe/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_FUSION_INTERFACES_ASSEMBLYINFOLABEL_HPP
#include <Urasandesu/Swathe/Fusion/Interfaces/AssemblyInfoLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFOFWD_HPP
#include <Urasandesu/Swathe/Fusion/BaseAssemblyInfoFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Fusion/ApiHolders/DefaultFusionInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {
    
    namespace DefaultFusionInfoApiHolderDetail {
        
        //using namespace boost::mpl;
        //using namespace Urasandesu::Swathe::Hosting::Interfaces;
        //using namespace Urasandesu::Swathe::Hosting;
        //using namespace Urasandesu::Swathe::Fusion::Interfaces;

        //struct DefaultFusionInfoApiHolderImpl
        //{
        //    typedef map<
        //        pair<IAssemblyCache, IAssemblyCache>,
        //        pair<RuntimeHostLabel, RuntimeHost>,
        //        pair<FusionInfoLabel, FusionInfo>,
        //        pair<AssemblyInfoLabel, AssemblyInfo>
        //    > api_cartridges;
        //};

    }   // namespace DefaultFusionInfoApiHolderDetail {

    struct DefaultFusionInfoApiHolder
        //DefaultFusionInfoApiHolderDetail::DefaultFusionInfoApiHolderImpl
    {
    };
        
}}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {

#endif  // URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H