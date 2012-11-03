#pragma once
#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOW_H
#define URASANDESU_SWATHE_METADATA_CONTROLFLOW_H

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWTYPES_H
#include <Urasandesu/Swathe/Metadata/ControlFlowTypes.h>
#endif

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWFWD_H
#include <Urasandesu/Swathe/Metadata/ControlFlowFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class ControlFlow
    {
    public:
        inline ControlFlow(ControlFlowTypes const &type) : 
            m_type(type)
        { }

        inline ControlFlowTypes const &GetType() const { return m_type; }

    private:
        ControlFlowTypes m_type;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOW_H