#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAGENERATORAPIHOLDER_H

//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseAssemblyMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseAssemblyNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEMODULEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseModuleMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseTypeNameMetadataFwd.hpp>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPENAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/TypeNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseTypeNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultModuleNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultModuleNameMetadataGeneratorApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;
        
        struct DefaultModuleNameMetadataGeneratorApiHolderImpl
        {
            //typedef map<
            //    pair<MetadataInfoLabel, MetadataInfo>, 
            //    pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>, 
            //    pair<AssemblyMetadataLabel, AssemblyMetadata>, 
            //    pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
            //    pair<AssemblyNameMetadataGeneratorLabel, AssemblyNameMetadataGenerator> 
            //> api_cartridges;
            typedef map<
                pair<AssemblyNameMetadataGeneratorLabel, AssemblyNameMetadataGenerator>, 
                pair<IAssemblyNameMetadataHashLabel, IAssemblyNameMetadataHash>,
                pair<IAssemblyNameMetadataEqualToLabel, IAssemblyNameMetadataEqualTo>,
                pair<AssemblyMetadataGeneratorLabel, AssemblyMetadataGenerator>,
                pair<IModuleNameMetadataLabel, IModuleNameMetadata>,
                pair<ModuleMetadataGeneratorLabel, ModuleMetadataGenerator>,
                pair<TypeNameMetadataGeneratorLabel, TypeNameMetadataGenerator>
            > api_cartridges;
        };

    }   // namespace DefaultModuleNameMetadataGeneratorApiHolderDetail {

    struct DefaultModuleNameMetadataGeneratorApiHolder : 
        DefaultModuleNameMetadataGeneratorApiHolderDetail::DefaultModuleNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAGENERATORAPIHOLDER_H