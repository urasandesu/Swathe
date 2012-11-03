#pragma once
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP

#ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDERFWD_H
#include <Urasandesu/Swathe/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming {

    template<
        class StrongNameKeyApiHolder = ApiHolders::DefaultStrongNameKeyApiHolder
    >    
    class BaseStrongNameKey;

    typedef BaseStrongNameKey<> StrongNameKey;

}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming {

#endif  // #ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP