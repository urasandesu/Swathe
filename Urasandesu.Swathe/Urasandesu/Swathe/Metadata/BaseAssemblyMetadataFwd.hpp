#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultAssemblyMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class AssemblyMetadataApiHolder = ApiHolders::DefaultAssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadata;

    typedef BaseAssemblyMetadata<> AssemblyMetadata;

    
    
    
    
    template<
        class AssemblyMetadataApiHolder = ApiHolders::DefaultAssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadataPersistedHandler;

    typedef BaseAssemblyMetadataPersistedHandler<> AssemblyMetadataPersistedHandler;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATAFWD_HPP