#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATADISPENSERFWD_H
#define URASANDESU_SWATHE_METADATA_BASEMETADATADISPENSERFWD_H

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMetadataDispenserApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class MetadataDispenserApiHolder = ApiHolders::DefaultMetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser;

    typedef BaseMetadataDispenser<> MetadataDispenser;

    
    
    
    
    template<
        class MetadataDispenserApiHolder = ApiHolders::DefaultMetadataDispenserApiHolder
    >    
    class BaseMetadataDispenserPersistedHandler;

    typedef BaseMetadataDispenserPersistedHandler<> MetadataDispenserPersistedHandler;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETADATADISPENSERFWD_H