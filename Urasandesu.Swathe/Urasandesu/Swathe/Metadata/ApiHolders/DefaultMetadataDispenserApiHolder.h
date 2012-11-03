#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATADISPENSERFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMetadataDispenserApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultMetadataDispenserApiHolderDetail {
        
        using boost::mpl::map;
        using boost::mpl::pair;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultMetadataDispenserApiHolderImpl
        {
            typedef map<
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<MetadataDispenserPersistedHandlerLabel, MetadataDispenserPersistedHandler>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>
            > api_cartridges;
        };

    }   // namespace DefaultMetadataDispenserApiHolderDetail {

    struct DefaultMetadataDispenserApiHolder : 
        DefaultMetadataDispenserApiHolderDetail::DefaultMetadataDispenserApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H