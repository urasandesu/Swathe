#pragma once
#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#define URASANDESU_SWATHE_METADATA_TYPEKINDS_H

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace TypeKindsDetail {

        struct TypeKindsDef
        {
            enum type
            {
                TK_END = ELEMENT_TYPE_END, 
                TK_VOID = ELEMENT_TYPE_VOID, 
                TK_BOOLEAN = ELEMENT_TYPE_BOOLEAN, 
                TK_CHAR = ELEMENT_TYPE_CHAR, 
                TK_I1 = ELEMENT_TYPE_I1, 
                TK_U1 = ELEMENT_TYPE_U1, 
                TK_I2 = ELEMENT_TYPE_I2, 
                TK_U2 = ELEMENT_TYPE_U2, 
                TK_I4 = ELEMENT_TYPE_I4, 
                TK_U4 = ELEMENT_TYPE_U4, 
                TK_I8 = ELEMENT_TYPE_I8, 
                TK_U8 = ELEMENT_TYPE_U8, 
                TK_R4 = ELEMENT_TYPE_R4, 
                TK_R8 = ELEMENT_TYPE_R8, 
                TK_STRING = ELEMENT_TYPE_STRING, 
                TK_PTR = ELEMENT_TYPE_PTR, 
                TK_BYREF = ELEMENT_TYPE_BYREF, 
                TK_VALUETYPE = ELEMENT_TYPE_VALUETYPE, 
                TK_CLASS = ELEMENT_TYPE_CLASS, 
                TK_VAR = ELEMENT_TYPE_VAR, 
                TK_ARRAY = ELEMENT_TYPE_ARRAY, 
                TK_GENERICINST = ELEMENT_TYPE_GENERICINST, 
                TK_TYPEDBYREF = ELEMENT_TYPE_TYPEDBYREF, 
                TK_I = ELEMENT_TYPE_I, 
                TK_U = ELEMENT_TYPE_U, 
                TK_FNPTR = ELEMENT_TYPE_FNPTR, 
                TK_OBJECT = ELEMENT_TYPE_OBJECT, 
                TK_SZARRAY = ELEMENT_TYPE_SZARRAY, 
                TK_MVAR = ELEMENT_TYPE_MVAR, 
                TK_CMOD_REQD = ELEMENT_TYPE_CMOD_REQD, 
                TK_CMOD_OPT = ELEMENT_TYPE_CMOD_OPT, 
                TK_INTERNAL = ELEMENT_TYPE_INTERNAL, 
                TK_MAX = ELEMENT_TYPE_MAX, 
                TK_MODIFIER = ELEMENT_TYPE_MODIFIER, 
                TK_SENTINEL = ELEMENT_TYPE_SENTINEL, 
                TK_PINNED = ELEMENT_TYPE_PINNED, 
                TK_R4_HFA = ELEMENT_TYPE_R4_HFA, 
                TK_R8_HFA = ELEMENT_TYPE_R8_HFA, 
                TK_UNREACHED
            };

            std::vector<COR_SIGNATURE> const &GetSignatures() const
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
        };

    }   // namespace TypeKindsDetail {

    typedef SafeEnum<TypeKindsDetail::TypeKindsDef> TypeKinds;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H