#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultIAssemblyMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadata;

    typedef BaseIAssemblyMetadata<> IAssemblyMetadata;




    
    template<
        class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataHash;

    typedef BaseIAssemblyMetadataHash<> IAssemblyMetadataHash;

    
    
    
    
    template<
        class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataEqualTo;

    typedef BaseIAssemblyMetadataEqualTo<> IAssemblyMetadataEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATAFWD_HPP