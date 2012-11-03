#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H

#ifndef URASANDESU_SWATHE_FUSION_INTERFACES_ASSEMBLYINFOLABEL_HPP
#include <Urasandesu/Swathe/Fusion/Interfaces/AssemblyInfoLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFOFWD_HPP
#include <Urasandesu/Swathe/Fusion/BaseAssemblyInfoFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_IMODULEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/IModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseIModuleMetadataFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultAssemblyMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultAssemblyMetadataApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;
        using namespace Urasandesu::Swathe::Fusion::Interfaces;
        using namespace Urasandesu::Swathe::Fusion;

        struct DefaultAssemblyMetadataApiHolderImpl
        {
            typedef map<
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<AssemblyInfoLabel, AssemblyInfo>,
                pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>,
                pair<IMetaDataImport2, IMetaDataImport2>,
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<ModuleMetadataPersistedHandlerLabel, ModuleMetadataPersistedHandler>,
                pair<IModuleMetadataHashLabel, IModuleMetadataHash>,
                pair<IModuleMetadataEqualToLabel, IModuleMetadataEqualTo>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<MethodMetadataLabel, MethodMetadata>
            > api_cartridges;
        };

    }   // namespace DefaultAssemblyMetadataApiHolderDetail {
    
    struct DefaultAssemblyMetadataApiHolder : 
        DefaultAssemblyMetadataApiHolderDetail::DefaultAssemblyMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H