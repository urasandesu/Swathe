#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASETYPEMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASETYPEMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultTypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {
    
    template<
        class TypeMetadataApiHolder = ApiHolders::DefaultTypeMetadataApiHolder
    >    
    class BaseTypeMetadata;

    typedef BaseTypeMetadata<> TypeMetadata;

    
    
    
    
    template<
        class TypeMetadataApiHolder = ApiHolders::DefaultTypeMetadataApiHolder
    >    
    class BaseTypeMetadataPersistedHandler;

    typedef BaseTypeMetadataPersistedHandler<> TypeMetadataPersistedHandler;

    
    
    
    
    template<
        class TypeMetadataApiHolder = ApiHolders::DefaultTypeMetadataApiHolder
    >    
    class BaseNestedTypeMetadataPersistedHandler;

    typedef BaseNestedTypeMetadataPersistedHandler<> NestedTypeMetadataPersistedHandler;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASETYPEMETADATAFWD_HPP