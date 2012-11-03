#pragma once
#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace FieldAttributesDetail {

        struct FieldAttributesDef
        {
            enum type
            {
                FA_FIELD_ACCESS_MASK = fdFieldAccessMask, 
                FA_PRIVATE_SCOPE = fdPrivateScope, 
                FA_PRIVATE = fdPrivate, 
                FA_FAMAND_ASSEM = fdFamANDAssem, 
                FA_ASSEMBLY = fdAssembly, 
                FA_FAMILY = fdFamily, 
                FA_FAMOR_ASSEM = fdFamORAssem, 
                FA_PUBLIC = fdPublic, 
                FA_STATIC = fdStatic, 
                FA_INIT_ONLY = fdInitOnly, 
                FA_LITERAL = fdLiteral, 
                FA_NOT_SERIALIZED = fdNotSerialized, 
                FA_SPECIAL_NAME = fdSpecialName, 
                FA_PINVOKE_IMPL = fdPinvokeImpl, 
                FA_RESERVED_MASK = fdReservedMask, 
                FA_RT_SPECIAL_NAME = fdRTSpecialName, 
                FA_HAS_FIELD_MARSHAL = fdHasFieldMarshal, 
                FA_HAS_DEFAULT = fdHasDefault, 
                FA_HAS_FIELDRVA = fdHasFieldRVA, 
                FA_UNREACHED
            };

            friend type operator |(type lhs, type rhs)
            {
                return static_cast<type>(+lhs | +rhs);
            }
        };

    }   // namespace FieldAttributesDetail {

    typedef SafeEnum<FieldAttributesDetail::FieldAttributesDef> FieldAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP