#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_IMETHODMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/IMethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseIMethodMetadataFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultTypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultTypeMetadataApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultTypeMetadataApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataEqualToLabel, ITypeMetadataEqualTo>,
                pair<NestedTypeMetadataPersistedHandlerLabel, NestedTypeMetadataPersistedHandler>,
                pair<MethodMetadataLabel, MethodMetadata>,
                pair<IMethodMetadataHashLabel, IMethodMetadataHash>,
                pair<IMethodMetadataEqualToLabel, IMethodMetadataEqualTo>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace DefaultTypeMetadataApiHolderDetail {
    
    struct DefaultTypeMetadataApiHolder : 
        DefaultTypeMetadataApiHolderDetail::DefaultTypeMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H