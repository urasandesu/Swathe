#pragma once
#ifndef URASANDESU_SWATHE_BASESWATHESTORAGE_H
#define URASANDESU_SWATHE_BASESWATHESTORAGE_H

#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADE_H
#include <Urasandesu/Swathe/SwatheStorageDetail/SwatheStorageFacade.h>
#endif

#ifndef URASANDESU_SWATHE_BASESWATHESTORAGEFWD_H
#include <Urasandesu/Swathe/BaseSwatheStorageFwd.h>
#endif

namespace Urasandesu { namespace Swathe {

    template<
        class SwatheStorageApiHolder
    >    
    class BaseSwatheStorage : 
        public SwatheStorageDetail::SwatheStorageFacade<SwatheStorageApiHolder>::base_type
    {
    };

}}   // namespace Urasandesu { namespace Swathe {

#endif  // URASANDESU_SWATHE_BASESWATHESTORAGE_H