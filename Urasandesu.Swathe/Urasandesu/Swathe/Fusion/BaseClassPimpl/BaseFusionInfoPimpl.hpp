/* 
 * File: BaseFusionInfoPimpl.hpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPL_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPL_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPL_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseFusionInfoPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseFusionInfoPimpl<ApiHolder>::BaseFusionInfoPimpl(fusion_info_label_type *pClass) : 
        m_pClass(pClass), 
        m_pRuntime(nullptr), 
        m_hmodFusion(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseFusionInfoPimpl<ApiHolder>::~BaseFusionInfoPimpl()
    {
        Finalize();
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseFusionInfoPimpl<ApiHolder>::base_heap_provider_type *BaseFusionInfoPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseFusionInfoPimpl<ApiHolder>::base_heap_provider_type const *BaseFusionInfoPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_FUSION_INFO_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_cache_label_type> BaseFusionInfoPimpl<ApiHolder>::NewAssemblyCache() const
    {
        auto pAsmCache = NewAssemblyCacheCore();
        return pAsmCache;
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_name_label_type> BaseFusionInfoPimpl<ApiHolder>::NewAssemblyName(wstring const &displayName, NewAssemblyNameFlags const &flags) const
    {
        auto pAsmName = NewAssemblyNameCore();
        pAsmName->SetDisplayName(displayName);
        pAsmName->SetFlags(flags);
        return pAsmName;
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_name_range_label_type> BaseFusionInfoPimpl<ApiHolder>::EnumerateAssemblyName(AutoPtr<assembly_name_label_type> const &pCondition, AssemblyCacheFlags const &flags) const
    {
        auto pAsmNameRng = NewAssemblyNameRangeCore();
        pAsmNameRng->SetCondition(pCondition);
        pAsmNameRng->SetFlags(flags);
        return pAsmNameRng;
    }



    template<class ApiHolder>    
    void BaseFusionInfoPimpl<ApiHolder>::Initialize(runtime_host_label_type const *pRuntime)
    {
        _ASSERTE(pRuntime != nullptr);
        _ASSERTE(m_pRuntime == nullptr);
        m_pRuntime = pRuntime;
    }

    

    template<class ApiHolder>    
    void BaseFusionInfoPimpl<ApiHolder>::Finalize()
    {
        if (m_hmodFusion)
        {
            ::FreeLibrary(m_hmodFusion);
            m_hmodFusion = nullptr;
        }
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_cache_label_type> BaseFusionInfoPimpl<ApiHolder>::NewAssemblyCacheCore() const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<assembly_cache_label_type>();
        auto pAsmCache = provider.NewObject();
        pAsmCache->Initialize(m_pClass);
        return pAsmCache;
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_info_label_type> BaseFusionInfoPimpl<ApiHolder>::NewAssemblyInfo(ULONGLONG assemblySizeInKB, path const &assemblyPath) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<assembly_info_label_type>();
        auto pAsmInfo = provider.NewObject();
        pAsmInfo->SetAssemblySizeInKB(assemblySizeInKB);
        pAsmInfo->SetAssemblyPath(assemblyPath);
        return pAsmInfo;
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_name_label_type> BaseFusionInfoPimpl<ApiHolder>::NewAssemblyName(IAssemblyName *pComAsmName) const
    {
        auto pAsmName = NewAssemblyNameCore();
        pAsmName->SetCOMAssemblyName(pComAsmName);
        return pAsmName;
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_name_label_type> BaseFusionInfoPimpl<ApiHolder>::NewAssemblyNameCore() const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<assembly_name_label_type>();
        auto pAsmName = provider.NewObject();
        pAsmName->Initialize(m_pClass);
        return pAsmName;
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfoPimpl<ApiHolder>::assembly_name_range_label_type> BaseFusionInfoPimpl<ApiHolder>::NewAssemblyNameRangeCore() const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<assembly_name_range_label_type>();
        auto pAsmNameRng = provider.NewObject();
        pAsmNameRng->Initialize(m_pClass);
        return pAsmNameRng;
    }



    template<class ApiHolder>    
    HMODULE BaseFusionInfoPimpl<ApiHolder>::GetFusionHandle() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::CppAnonymSystemException;

        if (!m_hmodFusion)
        {
            auto const &corSysDirPath = m_pRuntime->GetCORSystemDirectoryPath();
            auto fusionPath = corSysDirPath;
            fusionPath /= L"fusion.dll";

            m_hmodFusion = ::LoadLibraryW(fusionPath.c_str());
            if (!m_hmodFusion)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        }
        return m_hmodFusion;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPL_HPP

