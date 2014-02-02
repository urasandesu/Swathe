/* 
 * File: OperandParams.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMS_HPP
#define URASANDESU_SWATHE_METADATA_OPERANDPARAMS_HPP

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAM_H
#include <Urasandesu/Swathe/Metadata/OperandParam.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OperandParams
    {
    public:
        inline static OperandParam const &InlineBrTarget() { static OperandParam p(OperandParamTypes::OPT_INLINE_BR_TARGET); return p; }
        inline static OperandParam const &InlineField() { static OperandParam p(OperandParamTypes::OPT_INLINE_FIELD); return p; }
        inline static OperandParam const &InlineI() { static OperandParam p(OperandParamTypes::OPT_INLINE_I); return p; }
        inline static OperandParam const &InlineI8() { static OperandParam p(OperandParamTypes::OPT_INLINE_I8); return p; }
        inline static OperandParam const &InlineMethod() { static OperandParam p(OperandParamTypes::OPT_INLINE_METHOD); return p; }
        inline static OperandParam const &InlineNone() { static OperandParam p(OperandParamTypes::OPT_INLINE_NONE); return p; }
        inline static OperandParam const &InlineR() { static OperandParam p(OperandParamTypes::OPT_INLINE_R); return p; }
        inline static OperandParam const &InlineSig() { static OperandParam p(OperandParamTypes::OPT_INLINE_SIG); return p; }
        inline static OperandParam const &InlineString() { static OperandParam p(OperandParamTypes::OPT_INLINE_STRING); return p; }
        inline static OperandParam const &InlineSwitch() { static OperandParam p(OperandParamTypes::OPT_INLINE_SWITCH); return p; }
        inline static OperandParam const &InlineTok() { static OperandParam p(OperandParamTypes::OPT_INLINE_TOK); return p; }
        inline static OperandParam const &InlineType() { static OperandParam p(OperandParamTypes::OPT_INLINE_TYPE); return p; }
        inline static OperandParam const &InlineVar() { static OperandParam p(OperandParamTypes::OPT_INLINE_VAR); return p; }
        inline static OperandParam const &ShortInlineBrTarget() { static OperandParam p(OperandParamTypes::OPT_SHORT_INLINE_BR_TARGET); return p; }
        inline static OperandParam const &ShortInlineI() { static OperandParam p(OperandParamTypes::OPT_SHORT_INLINE_I); return p; }
        inline static OperandParam const &ShortInlineR() { static OperandParam p(OperandParamTypes::OPT_SHORT_INLINE_R); return p; }
        inline static OperandParam const &ShortInlineVar() { static OperandParam p(OperandParamTypes::OPT_SHORT_INLINE_VAR); return p; }
    private:
        OperandParams() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMS_HPP
