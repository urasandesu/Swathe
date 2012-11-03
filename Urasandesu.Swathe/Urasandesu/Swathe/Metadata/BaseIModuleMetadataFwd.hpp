#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIMODULEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultIModuleMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadata;

    typedef BaseIModuleMetadata<> IModuleMetadata;




    
    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataHash;

    typedef BaseIModuleMetadataHash<> IModuleMetadataHash;

    
    
    
    
    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataEqualTo;

    typedef BaseIModuleMetadataEqualTo<> IModuleMetadataEqualTo;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATAFWD_HPP