#pragma once
#ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#define URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDER_H

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

    namespace DefaultStrongNameInfoApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::StrongNaming::Interfaces;

        struct DefaultStrongNameInfoApiHolderImpl
        {
            typedef map<
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<StrongNameKeyLabel, StrongNameKey>
            > api_cartridges;
        };

    }   // namespace DefaultStrongNameInfoApiHolderDetail {

    struct DefaultStrongNameInfoApiHolder : 
        DefaultStrongNameInfoApiHolderDetail::DefaultStrongNameInfoApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDER_H