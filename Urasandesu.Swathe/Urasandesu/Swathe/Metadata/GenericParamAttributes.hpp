/* 
 * File: GenericParamAttributes.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_GENERICPARAMATTRIBUTES_HPP
#define URASANDESU_SWATHE_METADATA_GENERICPARAMATTRIBUTES_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace GenericParamAttributesDetail {

        using Urasandesu::CppAnonym::SafeFlagsEnum;

        struct GenericParamAttributesDef
        {
            enum type
            {
                GPA_VARIANCE_MASK = gpVarianceMask, 
                GPA_NON_VARIANT = gpNonVariant, 
                GPA_COVARIANT = gpCovariant, 
                GPA_CONTRAVARIANT = gpContravariant, 
                GPA_SPECIAL_CONSTRAINT_MASK = gpSpecialConstraintMask, 
                GPA_NO_SPECIAL_CONSTRAINT = gpNoSpecialConstraint, 
                GPA_REFERENCE_TYPE_CONSTRAINT = gpReferenceTypeConstraint, 
                GPA_NOT_NULLABLE_VALUE_TYPE_CONSTRAINT = gpNotNullableValueTypeConstraint, 
                GPA_DEFAULT_CONSTRUCTOR_CONSTRAINT = gpDefaultConstructorConstraint, 
                GPA_UNREACHED = 0xFF00
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)

        };

    }   // namespace GenericParamAttributesDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<GenericParamAttributesDetail::GenericParamAttributesDef> GenericParamAttributes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_GENERICPARAMATTRIBUTES_HPP
