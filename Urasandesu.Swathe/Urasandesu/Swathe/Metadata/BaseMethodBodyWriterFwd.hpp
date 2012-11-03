#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITERFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITERFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODBODYWRITERAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMethodBodyWriterApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class MethodBodyWriterApiHolder = ApiHolders::DefaultMethodBodyWriterApiHolder
    >    
    class BaseMethodBodyWriter;

    typedef BaseMethodBodyWriter<> MethodBodyWriter;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITERFWD_HPP