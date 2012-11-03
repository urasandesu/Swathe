#pragma once
#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace TypeAttributesDetail {

        struct TypeAttributesDef
        {
            enum type
            {
                TA_VISIBILITY_MASK = tdVisibilityMask, 
                TA_NOT_PUBLIC = tdNotPublic, 
                TA_PUBLIC = tdPublic, 
                TA_NESTED_PUBLIC = tdNestedPublic, 
                TA_NESTED_PRIVATE = tdNestedPrivate, 
                TA_NESTED_FAMILY = tdNestedFamily, 
                TA_NESTED_ASSEMBLY = tdNestedAssembly, 
                TA_NESTED_FAMAND_ASSEM = tdNestedFamANDAssem, 
                TA_NESTED_FAMOR_ASSEM = tdNestedFamORAssem, 
                TA_LAYOUT_MASK = tdLayoutMask, 
                TA_AUTO_LAYOUT = tdAutoLayout, 
                TA_SEQUENTIAL_LAYOUT = tdSequentialLayout, 
                TA_EXPLICIT_LAYOUT = tdExplicitLayout, 
                TA_CLASS_SEMANTICS_MASK = tdClassSemanticsMask, 
                TA_CLASS = tdClass, 
                TA_INTERFACE = tdInterface, 
                TA_ABSTRACT = tdAbstract, 
                TA_SEALED = tdSealed, 
                TA_SPECIAL_NAME = tdSpecialName, 
                TA_IMPORT = tdImport, 
                TA_SERIALIZABLE = tdSerializable, 
                TA_STRING_FORMAT_MASK = tdStringFormatMask, 
                TA_ANSI_CLASS = tdAnsiClass, 
                TA_UNICODE_CLASS = tdUnicodeClass, 
                TA_AUTO_CLASS = tdAutoClass, 
                TA_CUSTOM_FORMAT_CLASS = tdCustomFormatClass, 
                TA_CUSTOM_FORMAT_MASK = tdCustomFormatMask, 
                TA_BEFORE_FIELD_INIT = tdBeforeFieldInit, 
                TA_FORWARDER = tdForwarder, 
                TA_RESERVED_MASK = tdReservedMask, 
                TA_RT_SPECIAL_NAME = tdRTSpecialName, 
                TA_HAS_SECURITY = tdHasSecurity, 
                TA_UNREACHED
            };

            friend type operator |(type lhs, type rhs)
            {
                return static_cast<type>(+lhs | +rhs);
            }
        };

    }   // namespace TypeAttributesDetail {

    typedef SafeEnum<TypeAttributesDetail::TypeAttributesDef> TypeAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP