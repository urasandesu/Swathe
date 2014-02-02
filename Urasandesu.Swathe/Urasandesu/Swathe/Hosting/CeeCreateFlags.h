/* 
 * File: CeeCreateFlags.h
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
#ifndef URASANDESU_SWATHE_HOSTING_CEECREATEFLAGS_H
#define URASANDESU_SWATHE_HOSTING_CEECREATEFLAGS_H

namespace Urasandesu { namespace Swathe { namespace Hosting {

    namespace CeeCreateFlagsDetail {

        using Urasandesu::CppAnonym::SafeFlagsEnum;

        struct CeeCreateFlagsDef
        {
            enum type
            {
                CCF_PE32 = ICEE_CREATE_FILE_PE32, 
                CCF_PE64 = ICEE_CREATE_FILE_PE64, 
                CCF_CORMAIN_STUB = ICEE_CREATE_FILE_CORMAIN_STUB, 
                CCF_STRIP_RELOCS = ICEE_CREATE_FILE_STRIP_RELOCS, 
                CCF_EMIT_FIXUPS = ICEE_CREATE_FILE_EMIT_FIXUPS, 
                CCF_MASK = ICEE_CREATE_MACHINE_MASK, 
                CCF_ILLEGAL = ICEE_CREATE_MACHINE_ILLEGAL, 
                CCF_I386 = ICEE_CREATE_MACHINE_I386, 
                CCF_IA64 = ICEE_CREATE_MACHINE_IA64, 
                CCF_AMD64 = ICEE_CREATE_MACHINE_AMD64, 
                CCF_PURE_IL = ICEE_CREATE_FILE_PE32 | ICEE_CREATE_FILE_CORMAIN_STUB | ICEE_CREATE_MACHINE_I386, 
                CCF_UNREACHED = 0xFFFFFFFF
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)

        };

    }   // namespace CeeCreateFlagsDetail {
    
    typedef Urasandesu::CppAnonym::SafeFlagsEnum<CeeCreateFlagsDetail::CeeCreateFlagsDef> CeeCreateFlags;

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // #ifndef URASANDESU_SWATHE_HOSTING_CEECREATEFLAGS_H
