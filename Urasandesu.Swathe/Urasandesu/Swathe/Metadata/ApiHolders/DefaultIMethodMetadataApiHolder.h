#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_IMETHODMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/IMethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseIMethodMetadataFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ITYPEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ITypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseITypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultIMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultIMethodMetadataApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultIMethodMetadataApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataLabel, ITypeMetadata>
            > api_cartridges;
        };

    }   // namespace DefaultIMethodMetadataApiHolderDetail {

    struct DefaultIMethodMetadataApiHolder : 
        DefaultIMethodMetadataApiHolderDetail::DefaultIMethodMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDER_H