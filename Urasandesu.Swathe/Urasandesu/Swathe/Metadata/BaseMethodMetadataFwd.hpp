#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODMETADATAFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEMETHODMETADATAFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class MethodMetadataApiHolder = ApiHolders::DefaultMethodMetadataApiHolder
    >    
    class BaseMethodMetadata;

    typedef BaseMethodMetadata<> MethodMetadata;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETHODMETADATAFWD_HPP