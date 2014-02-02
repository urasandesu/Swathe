/* 
 * File: AssemblyFlags.h
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
#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYFLAGS_H
#define URASANDESU_SWATHE_METADATA_ASSEMBLYFLAGS_H

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace AssemblyFlagsDetail {

        using Urasandesu::CppAnonym::SafeFlagsEnum;

        struct AssemblyFlagsDef
        {
            enum type
            {
                AF_PUBLIC_KEY = afPublicKey, 
                AF_PA_NONE = afPA_None, 
                AF_PA_MSIL = afPA_MSIL, 
                AF_PA_X86 = afPA_x86, 
                AF_PA_IA64 = afPA_IA64, 
                AF_PA_AMD64 = afPA_AMD64, 
                AF_PA_NOPLATFORM = afPA_NoPlatform, 
                AF_PA_SPECIFIED = afPA_Specified, 
                AF_PA_MASK = afPA_Mask, 
                AF_PA_FULLMASK = afPA_FullMask, 
                AF_PA_SHIFT = afPA_Shift, 
                AF_ENABLE_JIT_COMPILE_TRACKING = afEnableJITcompileTracking, 
                AF_DISABLE_JIT_COMPILE_OPTIMIZER = afDisableJITcompileOptimizer, 
                AF_RETARGETABLE = afRetargetable, 
                AF_UNREACHED = 0xF000
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)

        };

    }   // namespace AssemblyFlagsDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<AssemblyFlagsDetail::AssemblyFlagsDef> AssemblyFlags;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYFLAGS_H
