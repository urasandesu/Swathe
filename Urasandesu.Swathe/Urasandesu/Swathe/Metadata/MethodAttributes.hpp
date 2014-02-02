/* 
 * File: MethodAttributes.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace MethodAttributesDetail {

        struct MethodAttributesDef
        {
            enum type
            {
                MA_MEMBER_ACCESS_MASK = mdMemberAccessMask, 
                MA_PRIVATE_SCOPE = mdPrivateScope, 
                MA_PRIVATE = mdPrivate, 
                MA_FAMAND_ASSEM = mdFamANDAssem, 
                MA_ASSEM = mdAssem, 
                MA_FAMILY = mdFamily, 
                MA_FAMOR_ASSEM = mdFamORAssem, 
                MA_PUBLIC = mdPublic, 
                MA_STATIC = mdStatic, 
                MA_FINAL = mdFinal, 
                MA_VIRTUAL = mdVirtual, 
                MA_HIDE_BY_SIG = mdHideBySig, 
                MA_VTABLE_LAYOUT_MASK = mdVtableLayoutMask, 
                MA_REUSE_SLOT = mdReuseSlot, 
                MA_NEW_SLOT = mdNewSlot, 
                MA_CHECK_ACCESS_ON_OVERRIDE = mdCheckAccessOnOverride, 
                MA_ABSTRACT = mdAbstract, 
                MA_SPECIAL_NAME = mdSpecialName, 
                MA_PINVOKE_IMPL = mdPinvokeImpl, 
                MA_UNMANAGED_EXPORT = mdUnmanagedExport, 
                MA_RESERVED_MASK = mdReservedMask, 
                MA_RT_SPECIAL_NAME = mdRTSpecialName, 
                MA_HAS_SECURITY = mdHasSecurity, 
                MA_REQUIRE_SEC_OBJECT = mdRequireSecObject, 
                MA_UNREACHED = 0xFF00
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)
        };

    }   // MethodAttributesDetail

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<MethodAttributesDetail::MethodAttributesDef> MethodAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
