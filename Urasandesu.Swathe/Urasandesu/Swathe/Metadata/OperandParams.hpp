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