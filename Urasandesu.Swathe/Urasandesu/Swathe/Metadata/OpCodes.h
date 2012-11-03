#pragma once
#ifndef URASANDESU_SWATHE_METADATA_OPCODES_H
#define URASANDESU_SWATHE_METADATA_OPCODES_H

#ifndef URASANDESU_SWATHE_METADATA_OPCODE_H
#include <Urasandesu/Swathe/Metadata/OpCode.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OpCodes
    {
    public:
#define OPDEF_EX(canonicalName, canonicalNameEx) \
        static const OpCodeDetail::OpCode_<OpCodeTypes::canonicalName> canonicalNameEx;
#include <Urasandesu/Swathe/Metadata/OpCodeEx.def>
#undef OPDEF_EX
    private:
        OpCodes() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPCODES_H