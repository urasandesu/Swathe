#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEKINDS_HPP
#define URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEKINDS_HPP

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting {

    namespace PortableExecutableKindsDetail {

        struct PortableExecutableKindsDef
        {
            enum type
            {
                PEK_NONE = 0,
                PEK_NOTA_PORTABLE_EXECUTABLE_IMAGE = 0x00000001, 
                PEK_IL_ONLY = 0x00000002, 
                PEK_REQUIRED32_BIT = 0x00000004, 
                PEK_PE32_PLUS = 0x00000008, 
                PEK_UNMANAGED32_BIT = 0x00000010, 
                PEK_UNREACHED
            };

            friend type operator |(type lhs, type rhs)
            {
                return static_cast<type>(+lhs | +rhs);
            }
        };

    }   // PortableExecutableKindsDetail

    typedef SafeEnum<PortableExecutableKindsDetail::PortableExecutableKindsDef> PortableExecutableKinds;

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // #ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEKINDS_HPP