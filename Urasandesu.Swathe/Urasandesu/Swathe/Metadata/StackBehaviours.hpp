#pragma once
#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP
#define URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOUR_H
#include <Urasandesu/Swathe/Metadata/StackBehaviour.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class StackBehaviours
    {
    public:
        inline static StackBehaviour const &Pop0() { static StackBehaviour b(StackBehaviourTypes::SBT_POP0); return b; }
        inline static StackBehaviour const &Pop1() { static StackBehaviour b(StackBehaviourTypes::SBT_POP1); return b; }
        inline static StackBehaviour const &PopI() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_I); return b; }
        inline static StackBehaviour const &PopI8() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_I8); return b; }
        inline static StackBehaviour const &PopR4() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_R4); return b; }
        inline static StackBehaviour const &PopR8() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_R8); return b; }
        inline static StackBehaviour const &PopRef() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_REF); return b; }
        inline static StackBehaviour const &Push0() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH0); return b; }
        inline static StackBehaviour const &Push1() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH1); return b; }
        inline static StackBehaviour const &PushI() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_I); return b; }
        inline static StackBehaviour const &PushI8() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_I8); return b; }
        inline static StackBehaviour const &PushR4() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_R4); return b; }
        inline static StackBehaviour const &PushR8() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_R8); return b; }
        inline static StackBehaviour const &PushRef() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_REF); return b; }
        inline static StackBehaviour const &VarPop() { static StackBehaviour b(StackBehaviourTypes::SBT_VAR_POP); return b; }
        inline static StackBehaviour const &VarPush() { static StackBehaviour b(StackBehaviourTypes::SBT_VAR_PUSH); return b; }
    private:
        StackBehaviours() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP