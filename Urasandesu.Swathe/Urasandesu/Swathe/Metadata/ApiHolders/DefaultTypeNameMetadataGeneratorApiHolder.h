#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H

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
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseModuleNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASETYPEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseTypeMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseMethodNameMetadataFwd.hpp>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseModuleNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_FIELDNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/FieldNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseFieldNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMethodNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_PROPERTYNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/PropertyNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BasePropertyNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultTypeNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultTypeNameMetadataGeneratorApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultTypeNameMetadataGeneratorApiHolderImpl
        {
            //typedef map<
            //    pair<AssemblyMetadataLabel, AssemblyMetadata>,
            //    pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
            //    pair<AssemblyNameMetadataHashLabel, AssemblyNameMetadataHash>,
            //    pair<AssemblyNameMetadataEqualToLabel, AssemblyNameMetadataEqualTo>,
            //    pair<ModuleMetadataLabel, ModuleMetadata>,
            //    pair<ModuleNameMetadataLabel, ModuleNameMetadata>,
            //    pair<ModuleNameMetadataHashLabel, ModuleNameMetadataHash>,
            //    pair<ModuleNameMetadataEqualToLabel, ModuleNameMetadataEqualTo>,
            //    pair<TypeMetadataLabel, TypeMetadata>,
            //    pair<MethodNameMetadataLabel, MethodNameMetadata>,
            //    pair<IMetaDataImport2, IMetaDataImport2>
            //> api_cartridges;
            typedef map<
                pair<ModuleNameMetadataGeneratorLabel, ModuleNameMetadataGenerator>, 
                pair<ModuleMetadataGeneratorLabel, ModuleMetadataGenerator>, 
                pair<TypeMetadataLabel, TypeMetadata>, 
                pair<FieldNameMetadataGeneratorLabel, FieldNameMetadataGenerator>, 
                pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>, 
                pair<IModuleNameMetadataHashLabel, IModuleNameMetadataHash>, 
                pair<IModuleNameMetadataEqualToLabel, IModuleNameMetadataEqualTo>, 
                pair<PropertyNameMetadataGeneratorLabel, PropertyNameMetadataGenerator>,
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
                pair<TypeMetadataGeneratorLabel, TypeMetadataGenerator>
            > api_cartridges;
        };

    }   // namespace DefaultTypeNameMetadataGeneratorApiHolderDetail {

    struct DefaultTypeNameMetadataGeneratorApiHolder : 
        DefaultTypeNameMetadataGeneratorApiHolderDetail::DefaultTypeNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H