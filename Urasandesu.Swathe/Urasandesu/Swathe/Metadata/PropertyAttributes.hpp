#pragma once
#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace PropertyAttributesDetail {

        struct PropertyAttributesDef
        {
            enum type
            {
                PA_NONE = 0,
                PA_SPECIAL_NAME = prSpecialName, 
                PA_RESERVED_MASK = prReservedMask, 
                PA_RT_SPECIAL_NAME = prRTSpecialName, 
                PA_HAS_DEFAULT = prHasDefault, 
                PA_UNUSED = prUnused, 
                PA_UNREACHED
            };

            friend type operator |(type lhs, type rhs)
            {
                return static_cast<type>(+lhs | +rhs);
            }
        };

    }   // namespace PropertyAttributesDetail {

    typedef SafeEnum<PropertyAttributesDetail::PropertyAttributesDef> PropertyAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP