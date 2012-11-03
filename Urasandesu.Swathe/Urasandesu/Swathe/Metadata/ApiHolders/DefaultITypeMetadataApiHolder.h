#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ITYPEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ITypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseITypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultITypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultITypeMetadataApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultITypeMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<IModuleMetadataHashLabel, IModuleMetadataHash>
            > api_cartridges;
        };

    }   // namespace DefaultITypeMetadataApiHolderDetail {

    struct DefaultITypeMetadataApiHolder : 
        DefaultITypeMetadataApiHolderDetail::DefaultITypeMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDER_H