﻿/* 
 * File: ParameterAttributes.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_PARAMETERATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_PARAMETERATTRIBUTES_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace ParameterAttributesDetail {

        struct ParameterAttributesDef
        {
            enum type
            {
                PA_NONE = 0x0000, 
                PA_IN = pdIn, 
                PA_OUT = pdOut, 
                PA_OPTIONAL = pdOptional, 
                PA_RESERVED_MASK = pdReservedMask, 
                PA_HAS_DEFAULT = pdHasDefault, 
                PA_HAS_FIELD_MARSHAL = pdHasFieldMarshal, 
                PA_UNREACHED = pdUnused
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)
        };

    }   // namespace ParameterAttributesDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<ParameterAttributesDetail::ParameterAttributesDef> ParameterAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_PARAMETERATTRIBUTES_HPP
