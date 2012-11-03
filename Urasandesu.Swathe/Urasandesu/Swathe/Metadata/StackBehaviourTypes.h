#pragma once
#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURTYPES_H
#define URASANDESU_SWATHE_METADATA_STACKBEHAVIOURTYPES_H

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace StackBehaviourTypesDetail {

        struct StackBehaviourTypesDef
        {
            enum type
            {
                SBT_POP0, 
                SBT_POP1, 
                SBT_POP_I, 
                SBT_POP_I8, 
                SBT_POP_R4, 
                SBT_POP_R8, 
                SBT_POP_REF, 
                SBT_PUSH0, 
                SBT_PUSH1, 
                SBT_PUSH_I, 
                SBT_PUSH_I8, 
                SBT_PUSH_R4, 
                SBT_PUSH_R8, 
                SBT_PUSH_REF, 
                SBT_VAR_POP, 
                SBT_VAR_PUSH, 
                SBT_UNREACHED
            };
        };

    }   // namespace StackBehaviourTypesDetail {

    typedef SafeEnum<StackBehaviourTypesDetail::StackBehaviourTypesDef> StackBehaviourTypes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURTYPES_H