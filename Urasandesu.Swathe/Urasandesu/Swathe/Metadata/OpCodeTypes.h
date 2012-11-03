#pragma once
#ifndef URASANDESU_SWATHE_METADATA_OPCODETYPES_H
#define URASANDESU_SWATHE_METADATA_OPCODETYPES_H

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace OpCodeTypesDetail {

        struct OpCodeTypesDef
        {
            enum type
            {
#define OPDEF(canonicalName, stringName, stackBehaviour0, stackBehaviour1, \
                operandParams, opcodeKind, length, byte1, byte2, controlFlow) \
                canonicalName,
#include "opcode.def"
#undef OPDEF
                CEE_UNREACHED
            };
        };

    }   // namespace OpCodeTypesDetail {

    typedef SafeEnum<OpCodeTypesDetail::OpCodeTypesDef> OpCodeTypes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPCODETYPES_H