/* 
 * File: OperandParamTypes.h
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
#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMTYPES_H
#define URASANDESU_SWATHE_METADATA_OPERANDPARAMTYPES_H

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace OperandParamTypesDetail {

        struct OperandParamTypesDef
        {
            enum type
            {
                OPT_INLINE_BR_TARGET, 
                OPT_INLINE_FIELD, 
                OPT_INLINE_I, 
                OPT_INLINE_I8, 
                OPT_INLINE_METHOD, 
                OPT_INLINE_NONE, 
                OPT_INLINE_R, 
                OPT_INLINE_SIG, 
                OPT_INLINE_STRING, 
                OPT_INLINE_SWITCH, 
                OPT_INLINE_TOK, 
                OPT_INLINE_TYPE, 
                OPT_INLINE_VAR, 
                OPT_SHORT_INLINE_BR_TARGET, 
                OPT_SHORT_INLINE_I, 
                OPT_SHORT_INLINE_R, 
                OPT_SHORT_INLINE_VAR, 
                OPT_UNREACHED
            };
        };

    }   // namespace OperandParamTypesDetail {

    typedef Urasandesu::CppAnonym::SafeEnum<OperandParamTypesDetail::OperandParamTypesDef> OperandParamTypes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMTYPES_H
