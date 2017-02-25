/* 
 * File: BaseAssemblyCachePimpl.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPL_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPL_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPL_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyCachePimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAssemblyCachePimpl<ApiHolder>::BaseAssemblyCachePimpl(assembly_cache_label_type *pClass) : 
        m_pClass(pClass), 
        m_pFuInfo(nullptr)
    { }

#define SWATHE_DECLARE_BASE_ASSEMBLY_CACHE_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    AutoPtr<typename BaseAssemblyCachePimpl<ApiHolder>::assembly_info_label_type> BaseAssemblyCachePimpl<ApiHolder>::QueryAssemblyInfo(AssemblyQueryTypes const &type, wstring const &assemblyFullName) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comAsmCache = m_pClass->GetCOMAssemblyCache();

        auto buffer = array<WCHAR, MAX_PATH>();
        auto asmInfo = ASSEMBLY_INFO();
        ::ZeroMemory(&asmInfo, sizeof(ASSEMBLY_INFO));
        asmInfo.cbAssemblyInfo = sizeof(ASSEMBLY_INFO);
        asmInfo.pszCurrentAssemblyPathBuf = buffer.data();
        asmInfo.cchBuf = MAX_PATH;
        auto hr = comAsmCache.QueryAssemblyInfo(type.Value(), assemblyFullName.c_str(), &asmInfo);
        if (FAILED(hr)) 
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        auto assemblySizeInKB = static_cast<ULONGLONG>(0);
        ::memcpy_s(&assemblySizeInKB, sizeof(ULONGLONG), 
                   &asmInfo.uliAssemblySizeInKB, sizeof(ULARGE_INTEGER));

        return m_pFuInfo->NewAssemblyInfo(assemblySizeInKB, asmInfo.pszCurrentAssemblyPathBuf);
    }



    template<class ApiHolder>    
    void BaseAssemblyCachePimpl<ApiHolder>::InstallAssembly(AssemblyCacheInstallFlags const &flag, path const &asmPath)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comAsmCache = m_pClass->GetCOMAssemblyCache();

        auto hr = comAsmCache.InstallAssembly(flag.Value(), asmPath.native().c_str(), nullptr);
        if (FAILED(hr)) 
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    AssemblyCacheUninstallDispositions BaseAssemblyCachePimpl<ApiHolder>::UninstallAssembly(wstring const &fullName)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comAsmCache = m_pClass->GetCOMAssemblyCache();

        auto ulDisposition = ULONG();
        auto hr = comAsmCache.UninstallAssembly(0, fullName.c_str(), nullptr, &ulDisposition);
        if (FAILED(hr)) 
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        return AssemblyCacheUninstallDispositions(ulDisposition);
    }



    template<class ApiHolder>    
    void BaseAssemblyCachePimpl<ApiHolder>::Initialize(fusion_info_label_type const *pFuInfo)
    {
        _ASSERTE(!m_pFuInfo);
        _ASSERTE(pFuInfo);
        m_pFuInfo = pFuInfo;
    }



    template<class ApiHolder>    
    IAssemblyCache &BaseAssemblyCachePimpl<ApiHolder>::GetCOMAssemblyCache()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::CppAnonymSystemException;

        if (m_pComAsmCache.p == NULL)
        {
            auto hmodFusion = m_pFuInfo->GetFusionHandle();

            typedef HRESULT (__stdcall *CreateAsmCachePtr)(IAssemblyCache **ppAsmCache, DWORD dwReserved);
            auto *pfnCreateAsmCache = reinterpret_cast<CreateAsmCachePtr>(::GetProcAddress(hmodFusion, "CreateAssemblyCache"));
            if (!pfnCreateAsmCache)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        
            auto hr = pfnCreateAsmCache(&m_pComAsmCache, 0);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComAsmCache;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPL_HPP

