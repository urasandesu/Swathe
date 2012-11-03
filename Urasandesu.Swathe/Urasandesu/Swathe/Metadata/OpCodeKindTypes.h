#pragma once
#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDTYPES_H
#define URASANDESU_SWATHE_METADATA_OPCODEKINDTYPES_H

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace OpCodeKindTypesDetail {

        struct OpCodeKindTypesDef
        {
            enum type
            {
                OKT_I_INTERNAL, 
                OKT_I_MACRO, 
                OKT_I_OBJ_MODEL, 
                OKT_I_PREFIX, 
                OKT_I_PRIMITIVE, 
                OKT_UNREACHED
            };
        };

    }   // namespace OpCodeKindTypesDetail {

    typedef SafeEnum<OpCodeKindTypesDetail::OpCodeKindTypesDef> OpCodeKindTypes;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDTYPES_H