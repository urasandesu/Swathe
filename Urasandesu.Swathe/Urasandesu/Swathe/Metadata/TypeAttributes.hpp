/* 
 * File: TypeAttributes.hpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace TypeAttributesDetail {

        using Urasandesu::CppAnonym::SafeFlagsEnum;

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
                TA_UNREACHED = 0xFF000000
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)

        };

    }   // namespace TypeAttributesDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<TypeAttributesDetail::TypeAttributesDef> TypeAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
