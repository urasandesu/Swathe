#pragma once
#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDS_HPP
#define URASANDESU_SWATHE_METADATA_OPCODEKINDS_HPP

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKIND_H
#include <Urasandesu/Swathe/Metadata/OpCodeKind.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OpCodeKinds
    {
    public:
        inline static OpCodeKind const &IInternal() { static OpCodeKind k(OpCodeKindTypes::OKT_I_INTERNAL); return k; }
        inline static OpCodeKind const &IMacro() { static OpCodeKind k(OpCodeKindTypes::OKT_I_MACRO); return k; }
        inline static OpCodeKind const &IObjModel() { static OpCodeKind k(OpCodeKindTypes::OKT_I_OBJ_MODEL); return k; }
        inline static OpCodeKind const &IPrefix() { static OpCodeKind k(OpCodeKindTypes::OKT_I_PREFIX); return k; }
        inline static OpCodeKind const &IPrimitive() { static OpCodeKind k(OpCodeKindTypes::OKT_I_PRIMITIVE); return k; }
    private:
        OpCodeKinds() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDS_HPP