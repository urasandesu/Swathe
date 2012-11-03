#pragma once
#ifndef URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFOFWD_HPP
#define URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFOFWD_HPP

#ifndef URASANDESU_SWATHE_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Fusion/ApiHolders/DefaultAssemblyInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion {

    template<
        class AssemblyInfoApiHolder = ApiHolders::DefaultAssemblyInfoApiHolder
    >    
    class BaseAssemblyInfo;

    typedef BaseAssemblyInfo<> AssemblyInfo;

}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFOFWD_HPP