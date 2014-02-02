/* 
 * File: FieldAttributes.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP

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
                FA_UNREACHED = 0xF000
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)
        };

    }   // namespace FieldAttributesDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<FieldAttributesDetail::FieldAttributesDef> FieldAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
