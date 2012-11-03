#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultAssemblyNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class AssemblyNameMetadataGeneratorApiHolder = ApiHolders::DefaultAssemblyNameMetadataGeneratorApiHolder
    >    
    class BaseAssemblyNameMetadataGenerator;

    typedef BaseAssemblyNameMetadataGenerator<> AssemblyNameMetadataGenerator;

    
    
    
    
    //template<
    //    class AssemblyNameMetadataGeneratorApiHolder = ApiHolders::DefaultAssemblyNameMetadataGeneratorApiHolder
    //>    
    //class BaseAssemblyNameMetadataGeneratorHash;

    //typedef BaseAssemblyNameMetadataGeneratorHash<> AssemblyNameMetadataGeneratorHash;

    //
    //
    //
    //
    //template<
    //    class AssemblyNameMetadataGeneratorApiHolder = ApiHolders::DefaultAssemblyNameMetadataGeneratorApiHolder
    //>    
    //class BaseAssemblyNameMetadataGeneratorEqualTo;

    //typedef BaseAssemblyNameMetadataGeneratorEqualTo<> AssemblyNameMetadataGeneratorEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP