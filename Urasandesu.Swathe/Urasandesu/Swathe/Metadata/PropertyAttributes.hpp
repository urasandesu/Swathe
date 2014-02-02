/* 
 * File: PropertyAttributes.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace PropertyAttributesDetail {

        struct PropertyAttributesDef
        {
            enum type
            {
                PA_NONE = 0,
                PA_SPECIAL_NAME = prSpecialName, 
                PA_RESERVED_MASK = prReservedMask, 
                PA_RT_SPECIAL_NAME = prRTSpecialName, 
                PA_HAS_DEFAULT = prHasDefault, 
                PA_UNUSED = prUnused, 
                PA_UNREACHED = 0xFFFF
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)
        };

    }   // namespace PropertyAttributesDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<PropertyAttributesDetail::PropertyAttributesDef> PropertyAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
