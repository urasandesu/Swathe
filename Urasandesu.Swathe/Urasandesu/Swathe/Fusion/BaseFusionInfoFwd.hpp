#pragma once
#ifndef URASANDESU_SWATHE_FUSION_BASEFUSIONINFOFWD_HPP
#define URASANDESU_SWATHE_FUSION_BASEFUSIONINFOFWD_HPP

#ifndef URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Fusion/ApiHolders/DefaultFusionInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion {

    template<
        class FusionInfoApiHolder = ApiHolders::DefaultFusionInfoApiHolder
    >    
    class BaseFusionInfo;

    typedef BaseFusionInfo<> FusionInfo;

    
    
    
    
    template<
        class FusionInfoApiHolder = ApiHolders::DefaultFusionInfoApiHolder
    >    
    class BaseFusionInfoPersistedHandler;

    typedef BaseFusionInfoPersistedHandler<> FusionInfoPersistedHandler;

}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_BASEFUSIONINFOFWD_HPP