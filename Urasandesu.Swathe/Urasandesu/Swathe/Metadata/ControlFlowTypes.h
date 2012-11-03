#pragma once
#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWTYPES_H
#define URASANDESU_SWATHE_METADATA_CONTROLFLOWTYPES_H

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace ControlFlowTypesDetail {

        struct ControlFlowTypesDef
        {
            enum type
            {
                CFT_BRANCH, 
                CFT_BREAK, 
                CFT_CALL, 
                CFT_COND_BRANCH, 
                CFT_META, 
                CFT_NEXT, 
                CFT_RETURN, 
                CFT_THROW, 
                CFT_UNREACHED
            };
        };

    }   // namespace ControlFlowTypesDetail {

    typedef SafeEnum<ControlFlowTypesDetail::ControlFlowTypesDef> ControlFlowTypes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWTYPES_H