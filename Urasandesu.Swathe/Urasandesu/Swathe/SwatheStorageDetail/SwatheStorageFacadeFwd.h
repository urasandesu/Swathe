#pragma once
#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADEFWD_H
#define URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADEFWD_H

namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

    namespace SwatheStorageFacadeDetail {

        template<
            class SwatheStorageApiHolder
        >    
        struct SwatheStorageFacadeImpl;

    }   // namespace SwatheStorageFacadeDetail {

    template<
        class SwatheStorageApiHolder
    >    
    struct SwatheStorageFacade;

}}}   // namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

#endif  // URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEFACADEFWD_H