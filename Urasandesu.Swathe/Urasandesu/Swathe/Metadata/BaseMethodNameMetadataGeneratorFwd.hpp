#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMethodNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class MethodNameMetadataGeneratorApiHolder = ApiHolders::DefaultMethodNameMetadataGeneratorApiHolder
    >
    class BaseMethodNameMetadataGenerator;

    typedef BaseMethodNameMetadataGenerator<> MethodNameMetadataGenerator;

    
    
    
    
    template<
        class MethodNameMetadataGeneratorApiHolder = ApiHolders::DefaultMethodNameMetadataGeneratorApiHolder
    >    
    class BaseMethodNameMetadataGeneratorHash;

    typedef BaseMethodNameMetadataGeneratorHash<> MethodNameMetadataGeneratorHash;

    
    
    
    
    template<
        class MethodNameMetadataGeneratorApiHolder = ApiHolders::DefaultMethodNameMetadataGeneratorApiHolder
    >    
    class BaseMethodNameMetadataGeneratorEqualTo;

    typedef BaseMethodNameMetadataGeneratorEqualTo<> MethodNameMetadataGeneratorEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP