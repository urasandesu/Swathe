#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultIMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadata;

    typedef BaseIMethodMetadata<> IMethodMetadata;




    
    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataHash;

    typedef BaseIMethodMetadataHash<> IMethodMetadataHash;

    
    
    
    
    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataEqualTo;

    typedef BaseIMethodMetadataEqualTo<> IMethodMetadataEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATAFWD_HPP