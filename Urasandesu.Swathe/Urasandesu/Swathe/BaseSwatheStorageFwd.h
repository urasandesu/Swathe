#pragma once
#ifndef URASANDESU_SWATHE_BASESWATHESTORAGEFWD_H
#define URASANDESU_SWATHE_BASESWATHESTORAGEFWD_H

#ifndef URASANDESU_SWATHE_APIHOLDERS_DEFAULTSWATHESTORAGEAPIHOLDERFWD_H
#include <Urasandesu/Swathe/ApiHolders/DefaultSwatheStorageApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe {

    template<
        class SwatheStorageApiHolder = ApiHolders::DefaultSwatheStorageApiHolder
    >    
    class BaseSwatheStorage;

    typedef BaseSwatheStorage<> SwatheStorage;

}}   // namespace Urasandesu { namespace Swathe {

#endif  // URASANDESU_SWATHE_BASESWATHESTORAGEFWD_H