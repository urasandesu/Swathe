#pragma once
#ifndef URASANDESU_SWATHE_METADATA_OPCODEKIND_H
#define URASANDESU_SWATHE_METADATA_OPCODEKIND_H

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDTYPES_H
#include <Urasandesu/Swathe/Metadata/OpCodeKindTypes.h>
#endif

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDFWD_H
#include <Urasandesu/Swathe/Metadata/OpCodeKindFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OpCodeKind
    {
    public:
        inline OpCodeKind(OpCodeKindTypes const &type) : 
            m_type(type)
        { }

        inline OpCodeKindTypes const &GetType() const { return m_type; }

    private:
        OpCodeKindTypes m_type;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPCODEKIND_H