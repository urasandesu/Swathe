#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultTypeNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class TypeNameMetadataGeneratorApiHolder = ApiHolders::DefaultTypeNameMetadataGeneratorApiHolder
    >
    class BaseTypeNameMetadataGenerator;

    typedef BaseTypeNameMetadataGenerator<> TypeNameMetadataGenerator;




    
    //template<
    //    class TypeNameMetadataGeneratorApiHolder = ApiHolders::DefaultTypeNameMetadataGeneratorApiHolder
    //>    
    //class BaseTypeNameMetadataGeneratorHash;

    //typedef BaseTypeNameMetadataGeneratorHash<> TypeNameMetadataGeneratorHash;

    //
    //
    //
    //
    //template<
    //    class TypeNameMetadataGeneratorApiHolder = ApiHolders::DefaultTypeNameMetadataGeneratorApiHolder
    //>    
    //class BaseTypeNameMetadataGeneratorEqualTo;

    //typedef BaseTypeNameMetadataGeneratorEqualTo<> TypeNameMetadataGeneratorEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP