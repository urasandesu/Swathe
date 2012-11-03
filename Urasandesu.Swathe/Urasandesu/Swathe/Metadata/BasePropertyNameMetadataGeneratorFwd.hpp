#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTPROPERTYNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultPropertyNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class PropertyNameMetadataGeneratorApiHolder = ApiHolders::DefaultPropertyNameMetadataGeneratorApiHolder
    >
    class BasePropertyNameMetadataGenerator;

    typedef BasePropertyNameMetadataGenerator<> PropertyNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP