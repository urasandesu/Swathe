#pragma once
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP

#ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming {

    template<
        class StrongNameInfoApiHolder = ApiHolders::DefaultStrongNameInfoApiHolder
    >    
    class BaseStrongNameInfo;

    typedef BaseStrongNameInfo<> StrongNameInfo;

}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming {

#endif  // #ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP