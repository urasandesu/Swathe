#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultFieldNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class FieldNameMetadataGeneratorApiHolder = ApiHolders::DefaultFieldNameMetadataGeneratorApiHolder
    >
    class BaseFieldNameMetadataGenerator;

    typedef BaseFieldNameMetadataGenerator<> FieldNameMetadataGenerator;

    
    
    
    
    template<
        class FieldNameMetadataGeneratorApiHolder = ApiHolders::DefaultFieldNameMetadataGeneratorApiHolder
    >    
    class BaseFieldNameMetadataGeneratorHash;

    typedef BaseFieldNameMetadataGeneratorHash<> FieldNameMetadataGeneratorHash;

    
    
    
    
    template<
        class FieldNameMetadataGeneratorApiHolder = ApiHolders::DefaultFieldNameMetadataGeneratorApiHolder
    >    
    class BaseFieldNameMetadataGeneratorEqualTo;

    typedef BaseFieldNameMetadataGeneratorEqualTo<> FieldNameMetadataGeneratorEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP