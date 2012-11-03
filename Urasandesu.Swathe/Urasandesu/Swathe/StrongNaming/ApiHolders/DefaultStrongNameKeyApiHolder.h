#pragma once
#ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#define URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDERFWD_H
#include <Urasandesu/Swathe/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

    namespace DefaultStrongNameKeyApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::StrongNaming::Interfaces;

        struct DefaultStrongNameKeyApiHolderImpl
        {
            typedef map<
                pair<StrongNameInfoLabel, StrongNameInfo>
            > api_cartridges;
        };

    }   // namespace DefaultStrongNameKeyApiHolderDetail {

    struct DefaultStrongNameKeyApiHolder : 
        DefaultStrongNameKeyApiHolderDetail::DefaultStrongNameKeyApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H