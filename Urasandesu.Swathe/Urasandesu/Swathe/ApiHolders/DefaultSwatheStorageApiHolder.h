#pragma once
#ifndef URASANDESU_SWATHE_APIHOLDERS_DEFAULTSWATHESTORAGEAPIHOLDER_H
#define URASANDESU_SWATHE_APIHOLDERS_DEFAULTSWATHESTORAGEAPIHOLDER_H

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_HOSTINFOLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/HostInfoLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASEHOSTINFOFWD_HPP
#include <Urasandesu/Swathe/Hosting/BaseHostInfoFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_APIHOLDERS_DEFAULTSWATHESTORAGEAPIHOLDERFWD_H
#include <Urasandesu/Swathe/ApiHolders/DefaultSwatheStorageApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace ApiHolders {
    
    namespace DefaultSwatheStorageApiHolderDetail {

        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using boost::mpl::map;
        using boost::mpl::pair;

        struct DefaultSwatheStorageApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>
            > api_cartridges;
        };

    }   // namespace DefaultSwatheStorageApiHolderDetail {

    struct DefaultSwatheStorageApiHolder : 
        DefaultSwatheStorageApiHolderDetail::DefaultSwatheStorageApiHolderImpl
    {
    };
        
}}}  // namespace Urasandesu { namespace Swathe { namespace ApiHolders {

#endif  // URASANDESU_SWATHE_APIHOLDERS_DEFAULTSWATHESTORAGEAPIHOLDER_H