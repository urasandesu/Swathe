/* 
 * File: ComImageFlags.h
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
#ifndef URASANDESU_SWATHE_HOSTING_COMIMAGEFLAGS_H
#define URASANDESU_SWATHE_HOSTING_COMIMAGEFLAGS_H

namespace Urasandesu { namespace Swathe { namespace Hosting {

    namespace ComImageFlagsDetail {

        using Urasandesu::CppAnonym::SafeFlagsEnum;

        struct ComImageFlagsDef
        {
            enum type
            {
                CIF_ILONLY = COMIMAGE_FLAGS_ILONLY, 
                CIF_32BITREQUIRED = COMIMAGE_FLAGS_32BITREQUIRED, 
                CIF_IL_LIBRARY = COMIMAGE_FLAGS_IL_LIBRARY, 
                CIF_STRONGNAMESIGNED = COMIMAGE_FLAGS_STRONGNAMESIGNED, 
                CIF_NATIVE_ENTRYPOINT = COMIMAGE_FLAGS_NATIVE_ENTRYPOINT, 
                CIF_TRACKDEBUGDATA = COMIMAGE_FLAGS_TRACKDEBUGDATA, 
                //CIF_ISIBCOPTIMIZED = COMIMAGE_FLAGS_ISIBCOPTIMIZED, 
                CIF_UNREACHED = 0xFFFFFFFF
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)

        };

    }   // namespace ComImageFlagsDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<ComImageFlagsDetail::ComImageFlagsDef> ComImageFlags;

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // #ifndef URASANDESU_SWATHE_HOSTING_COMIMAGEFLAGS_H
