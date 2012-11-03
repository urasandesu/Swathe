#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_IASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/IAssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseIAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATADISPENSERFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultIAssemblyMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultIAssemblyMetadataApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;
        using namespace Urasandesu::Swathe::StrongNaming;
        using namespace Urasandesu::Swathe::StrongNaming::Interfaces;

        struct DefaultIAssemblyMetadataApiHolderImpl
        {
            typedef map<
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<StrongNameKeyLabel, StrongNameKey>
            > api_cartridges;
        };

    }   // namespace DefaultIAssemblyMetadataApiHolderDetail {

    struct DefaultIAssemblyMetadataApiHolder : 
        DefaultIAssemblyMetadataApiHolderDetail::DefaultIAssemblyMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDER_H