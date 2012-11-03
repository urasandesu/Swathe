#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ITYPEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ITypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseITypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultModuleMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultModuleMetadataApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultModuleMetadataApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<TypeMetadataPersistedHandlerLabel, TypeMetadataPersistedHandler>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataEqualToLabel, ITypeMetadataEqualTo>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace DefaultModuleMetadataApiHolderDetail {
    
    struct DefaultModuleMetadataApiHolder : 
        DefaultModuleMetadataApiHolderDetail::DefaultModuleMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H