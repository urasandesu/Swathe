/* 
 * File: CallingConventions.h
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
#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#define URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace CallingConventionsDetail {

        using Urasandesu::CppAnonym::SafeFlagsEnum;
        
        struct ATL_NO_VTABLE CallingConventionsDef
        {
            enum type
            {
                CC_STANDARD = IMAGE_CEE_CS_CALLCONV_DEFAULT, 
                CC_VAR_ARGS = IMAGE_CEE_CS_CALLCONV_VARARG, 
                CC_GENERIC_INST = IMAGE_CEE_CS_CALLCONV_GENERICINST, 
                CC_ANY = IMAGE_CEE_CS_CALLCONV_DEFAULT | IMAGE_CEE_CS_CALLCONV_VARARG, 
                CC_HAS_THIS = IMAGE_CEE_CS_CALLCONV_HASTHIS, 
                CC_EXPLICIT_THIS = IMAGE_CEE_CS_CALLCONV_EXPLICITTHIS, 
                CC_FIELD = IMAGE_CEE_CS_CALLCONV_FIELD,
                CC_LOCAL_SIG = IMAGE_CEE_CS_CALLCONV_LOCAL_SIG, 
                CC_PROPERTY = IMAGE_CEE_CS_CALLCONV_PROPERTY, 
                CC_GENERIC = IMAGE_CEE_CS_CALLCONV_GENERIC, 
                CC_UNREACHED = 0xF0
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)
        };

    }   // namespace CallingConventionsDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<CallingConventionsDetail::CallingConventionsDef> CallingConventions;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
