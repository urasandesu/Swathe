#pragma once
#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYQUERYTYPES_H
#define URASANDESU_SWATHE_FUSION_ASSEMBLYQUERYTYPES_H

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion {

    namespace AssemblyQueryTypesDetail {

        struct AssemblyQueryTypesDef
        {
            enum type
            {
                AQT_DEFAULT = 0,
                AQT_VALIDATE = QUERYASMINFO_FLAG_VALIDATE, 
                AQT_GET_SIZE = QUERYASMINFO_FLAG_GETSIZE,
                AQT_UNREACHED
            };
        };

    }   // AssemblyQueryTypesDetail

    typedef SafeEnum<AssemblyQueryTypesDetail::AssemblyQueryTypesDef> AssemblyQueryTypes;

}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_ASSEMBLYQUERYTYPES_H