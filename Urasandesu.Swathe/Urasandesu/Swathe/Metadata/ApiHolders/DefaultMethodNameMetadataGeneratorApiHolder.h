#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H

//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASETYPEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseTypeMetadataFwd.hpp>
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
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
//#include <Urasandesu/Swathe/Metadata/BaseMethodNameMetadataFwd.hpp>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODBODYWRITERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodBodyWriterLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITERFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMethodBodyWriterFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMethodNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultMethodNameMetadataGeneratorApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultMethodNameMetadataGeneratorApiHolderImpl
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
                pair<TypeNameMetadataGeneratorLabel, TypeNameMetadataGenerator>, 
                pair<ITypeNameMetadataHashLabel, ITypeNameMetadataHash>,
                pair<ITypeNameMetadataEqualToLabel, ITypeNameMetadataEqualTo>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<TypeMetadataGeneratorLabel, TypeMetadataGenerator>, 
                pair<TypeMetadataLabel, TypeMetadata>, 
                pair<MethodMetadataGeneratorLabel, MethodMetadataGenerator>, 
                pair<IMethodNameMetadataLabel, IMethodNameMetadata>, 
                pair<MethodBodyWriterLabel, MethodBodyWriter>
            > api_cartridges;
        };

    }   // namespace DefaultMethodNameMetadataGeneratorApiHolderDetail {

    struct DefaultMethodNameMetadataGeneratorApiHolder : 
        DefaultMethodNameMetadataGeneratorApiHolderDetail::DefaultMethodNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H