#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEITYPEMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultITypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadata;

    typedef BaseITypeMetadata<> ITypeMetadata;




    
    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadataHash;

    typedef BaseITypeMetadataHash<> ITypeMetadataHash;

    
    
    
    
    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadataEqualTo;

    typedef BaseITypeMetadataEqualTo<> ITypeMetadataEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATAFWD_HPP