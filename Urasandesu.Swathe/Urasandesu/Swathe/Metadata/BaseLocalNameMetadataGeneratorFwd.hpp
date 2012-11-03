#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTLOCALNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultLocalNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class LocalNameMetadataGeneratorApiHolder = ApiHolders::DefaultLocalNameMetadataGeneratorApiHolder
    >
    class BaseLocalNameMetadataGenerator;

    typedef BaseLocalNameMetadataGenerator<> LocalNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP