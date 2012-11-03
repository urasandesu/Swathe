#pragma once
#ifndef URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIATFWD_H
#define URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIATFWD_H

namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

    namespace SwatheStorageApiAtDetail {

        template<class ApiCartridgesHolder, class ApiLabel>
        struct SwatheStorageApiAtImpl;

    }   // namespace SwatheStorageApiAtDetail {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct SwatheStorageApiAt;

}}}   // namespace Urasandesu { namespace Swathe { namespace SwatheStorageDetail {

#endif  // URASANDESU_SWATHE_SWATHESTORAGEDETAIL_SWATHESTORAGEAPIATFWD_H