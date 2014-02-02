/* 
 * File: MethodImplAttributes.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_METHODIMPLATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_METHODIMPLATTRIBUTES_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace MethodImplAttributesDetail {

        struct MethodImplAttributesDef
        {
            enum type
            {
                MIA_CODE_TYPE_MASK = miCodeTypeMask, 
                MIA_IL = miIL, 
                MIA_NATIVE = miNative, 
                MIA_OPT_IL = miOPTIL, 
                MIA_RUNTIME = miRuntime, 
                MIA_MANAGED_MASK = miManagedMask, 
                MIA_UNMANAGED = miUnmanaged, 
                MIA_MANAGED = miManaged, 
                MIA_FORWARD_REF = miForwardRef, 
                MIA_PRESERVE_SIG = miPreserveSig, 
                MIA_INTERNAL_CALL = miInternalCall, 
                MIA_SYNCHRONIZED = miSynchronized, 
                MIA_NO_INLINING = miNoInlining, 
                MIA_NO_OPTIMIZATION = miNoOptimization, 
                MIA_UNREACHED = miMaxMethodImplVal
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)
        };

    }   // MethodImplAttributesDetail

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<MethodImplAttributesDetail::MethodImplAttributesDef> MethodImplAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_METHODIMPLATTRIBUTES_HPP
