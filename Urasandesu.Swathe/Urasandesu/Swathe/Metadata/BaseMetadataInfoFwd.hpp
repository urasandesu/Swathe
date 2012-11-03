#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATAINFOFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEMETADATAINFOFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMetadataInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class MetadataInfoApiHolder = ApiHolders::DefaultMetadataInfoApiHolder
    >    
    class BaseMetadataInfo;

    typedef BaseMetadataInfo<> MetadataInfo;

    
    
    
    
    template<
        class MetadataInfoApiHolder = ApiHolders::DefaultMetadataInfoApiHolder
    >    
    class BaseMetadataInfoPersistedHandler;

    typedef BaseMetadataInfoPersistedHandler<> MetadataInfoPersistedHandler;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETADATAINFOFWD_HPP