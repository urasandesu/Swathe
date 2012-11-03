#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOSTFWD_HPP
#define URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOSTFWD_HPP

#ifndef URASANDESU_SWATHE_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting {

    template<
        class RuntimeHostApiHolder = ApiHolders::DefaultRuntimeHostApiHolder
    >
    class BaseRuntimeHost;

    typedef BaseRuntimeHost<> RuntimeHost;

    
    
    
    
    template<
        class RuntimeHostApiHolder = ApiHolders::DefaultRuntimeHostApiHolder
    >    
    class BaseRuntimeHostPersistedHandler;

    typedef BaseRuntimeHostPersistedHandler<> RuntimeHostPersistedHandler;

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOSTFWD_HPP