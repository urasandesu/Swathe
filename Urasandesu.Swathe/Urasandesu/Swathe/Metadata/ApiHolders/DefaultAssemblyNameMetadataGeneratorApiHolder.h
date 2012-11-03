#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H

//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataDispenserLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATADISPENSERFWD_H
//#include <Urasandesu/Swathe/Metadata/BaseMetadataDispenserFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseAssemblyMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseModuleNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
//#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
//#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameInfoFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
//#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseTypeNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
//#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameKeyFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_FUSION_INTERFACES_FUSIONINFOLABEL_HPP
//#include <Urasandesu/Swathe/Fusion/Interfaces/FusionInfoLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_FUSION_BASEFUSIONINFOFWD_HPP
//#include <Urasandesu/Swathe/Fusion/BaseFusionInfoFwd.hpp>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseModuleNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultAssemblyNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultAssemblyNameMetadataGeneratorApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;
        
        struct DefaultAssemblyNameMetadataGeneratorApiHolderImpl
        {
            //typedef map<
            //    pair<MetadataInfoLabel, MetadataInfo>, 
            //    pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>, 
            //    pair<AssemblyMetadataLabel, AssemblyMetadata>, 
            //    pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
            //    pair<AssemblyNameMetadataGeneratorLabel, AssemblyNameMetadataGenerator> 
            //> api_cartridges;
            typedef map<
                pair<IAssemblyNameMetadataLabel, IAssemblyNameMetadata>,
                //pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataGeneratorLabel, AssemblyMetadataGenerator>,
                pair<ModuleNameMetadataGeneratorLabel, ModuleNameMetadataGenerator>
                //pair<StrongNameKeyLabel, StrongNameKey>
            > api_cartridges;
        };

    }   // namespace DefaultAssemblyNameMetadataGeneratorApiHolderDetail {

    struct DefaultAssemblyNameMetadataGeneratorApiHolder : 
        DefaultAssemblyNameMetadataGeneratorApiHolderDetail::DefaultAssemblyNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H