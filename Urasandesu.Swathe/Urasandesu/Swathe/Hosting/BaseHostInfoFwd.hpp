#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_BASEHOSTINFOFWD_HPP
#define URASANDESU_SWATHE_HOSTING_BASEHOSTINFOFWD_HPP

#ifndef URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Hosting/ApiHolders/DefaultHostInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting {

    template<
        class HostInfoApiHolder = ApiHolders::DefaultHostInfoApiHolder
    >    
    class BaseHostInfo;

    typedef BaseHostInfo<> HostInfo;

    
    
    
    
    template<
        class HostInfoApiHolder = ApiHolders::DefaultHostInfoApiHolder
    >    
    class BaseHostInfoPersistedHandler;

    typedef BaseHostInfoPersistedHandler<> HostInfoPersistedHandler;

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // URASANDESU_SWATHE_HOSTING_BASEHOSTINFOFWD_HPP