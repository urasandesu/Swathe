#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#define URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/Swathe/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Hosting/ApiHolders/DefaultHostInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

    namespace DefaultHostInfoApiHolderDetail {
        
        using boost::mpl::map;
        using boost::mpl::pair;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;

        struct DefaultHostInfoApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>,
                pair<HostInfoPersistedHandlerLabel, HostInfoPersistedHandler>,
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<RuntimeHostPersistedHandlerLabel, RuntimeHostPersistedHandler>
            > api_cartridges;
        };

    }   // namespace DefaultHostInfoApiHolderDetail {

    struct DefaultHostInfoApiHolder : 
        DefaultHostInfoApiHolderDetail::DefaultHostInfoApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

#endif  // URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H