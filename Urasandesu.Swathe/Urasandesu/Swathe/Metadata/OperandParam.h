#pragma once
#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAM_H
#define URASANDESU_SWATHE_METADATA_OPERANDPARAM_H

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMTYPES_H
#include "Urasandesu/Swathe/Metadata/OperandParamTypes.h"
#endif

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMFWD_H
#include <Urasandesu/Swathe/Metadata/OperandParamFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OperandParam
    {
    public:
        inline OperandParam(OperandParamTypes const &type) : 
            m_type(type)
        { }

        inline OperandParamTypes const &GetType() const { return m_type; }

    private:
        OperandParamTypes m_type;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAM_H