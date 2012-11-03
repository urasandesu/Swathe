#pragma once
#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP
#define URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOW_H
#include <Urasandesu/Swathe/Metadata/ControlFlow.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class ControlFlows
    {
    public:
        inline static ControlFlow const &Branch() { static ControlFlow f(ControlFlowTypes::CFT_BRANCH); return f; }
        inline static ControlFlow const &Break() { static ControlFlow f(ControlFlowTypes::CFT_BREAK); return f; }
        inline static ControlFlow const &Call() { static ControlFlow f(ControlFlowTypes::CFT_CALL); return f; }
        inline static ControlFlow const &CondBranch() { static ControlFlow f(ControlFlowTypes::CFT_COND_BRANCH); return f; }
        inline static ControlFlow const &Meta() { static ControlFlow f(ControlFlowTypes::CFT_META); return f; }
        inline static ControlFlow const &Next() { static ControlFlow f(ControlFlowTypes::CFT_NEXT); return f; }
        inline static ControlFlow const &Return() { static ControlFlow f(ControlFlowTypes::CFT_RETURN); return f; }
        inline static ControlFlow const &Throw() { static ControlFlow f(ControlFlowTypes::CFT_THROW); return f; }
    private:
        ControlFlows() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP