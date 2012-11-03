#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#define URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/Swathe/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

    namespace DefaultRuntimeHostApiHolderDetail {
        
        using boost::mpl::map;
        using boost::mpl::pair;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultRuntimeHostApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>,
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<RuntimeHostPersistedHandlerLabel, RuntimeHostPersistedHandler>,
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<MetadataInfoPersistedHandlerLabel, MetadataInfoPersistedHandler>
            > api_cartridges;
        };

    }   // namespace DefaultRuntimeHostApiHolderDetail {

    struct DefaultRuntimeHostApiHolder : 
        DefaultRuntimeHostApiHolderDetail::DefaultRuntimeHostApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

#endif  // URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H