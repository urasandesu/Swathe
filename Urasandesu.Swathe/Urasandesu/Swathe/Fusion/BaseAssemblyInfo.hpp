#pragma once
#ifndef URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFO_HPP
#define URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFO_HPP

#ifndef URASANDESU_SWATHE_FUSION_INTERFACES_ASSEMBLYINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Fusion/Interfaces/AssemblyInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFOFWD_HPP
#include <Urasandesu/Swathe/Fusion/BaseAssemblyInfoFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyInfoApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyInfoApiHolder
    >    
    class BaseAssemblyInfo
    {
    public:
        typedef BaseAssemblyInfo<AssemblyInfoApiHolder> this_type;

        typedef typename AssemblyInfoApiAt<AssemblyInfoApiHolder, Interfaces::FusionInfoLabel>::type fusion_info_type;

        BaseAssemblyInfo() :
            m_assemblySizeInKB(0)
        { }
        
        ULONGLONG GetAssemblySizeInKB() const 
        { 
            return m_assemblySizeInKB; 
        }
        
        boost::filesystem::path const &GetAssemblyPath() const 
        { 
            return m_assemblyPath; 
        }

    private:
        friend typename fusion_info_type;

        void SetAssemblySizeInKB(ULONGLONG assemblySizeInKB)
        { 
            m_assemblySizeInKB = assemblySizeInKB; 
        }
        
        void SetAssemblyPath(boost::filesystem::path const &assemblyPath)
        { 
            m_assemblyPath = assemblyPath; 
        }

        ULONGLONG m_assemblySizeInKB;
        boost::filesystem::path m_assemblyPath;
    };
        
}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_BASEASSEMBLYINFO_HPP