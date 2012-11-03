#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATADISPENSERFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMetadataInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultMetadataInfoApiHolderDetail {
        
        using boost::mpl::map;
        using boost::mpl::pair;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultMetadataInfoApiHolderImpl
        {
            typedef map<
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<MetadataInfoPersistedHandlerLabel, MetadataInfoPersistedHandler>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<MetadataDispenserPersistedHandlerLabel, MetadataDispenserPersistedHandler>
            > api_cartridges;
        };

    }   // namespace DefaultMetadataInfoApiHolderDetail {

    struct DefaultMetadataInfoApiHolder : 
        DefaultMetadataInfoApiHolderDetail::DefaultMetadataInfoApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H