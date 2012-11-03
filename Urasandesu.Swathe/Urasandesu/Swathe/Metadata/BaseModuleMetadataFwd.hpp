#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMODULEMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEMODULEMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultModuleMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {
    
    template<
        class ModuleMetadataApiHolder = ApiHolders::DefaultModuleMetadataApiHolder
    >    
    class BaseModuleMetadata;

    typedef BaseModuleMetadata<> ModuleMetadata;

    
    
    
    
    template<
        class ModuleMetadataApiHolder = ApiHolders::DefaultModuleMetadataApiHolder
    >    
    class BaseModuleMetadataPersistedHandler;

    typedef BaseModuleMetadataPersistedHandler<> ModuleMetadataPersistedHandler;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMODULEMETADATAFWD_HPP