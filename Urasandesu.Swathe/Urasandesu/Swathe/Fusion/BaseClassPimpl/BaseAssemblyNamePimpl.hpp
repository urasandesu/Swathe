/* 
 * File: BaseAssemblyNamePimpl.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPL_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPL_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPL_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyNamePimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAssemblyNamePimpl<ApiHolder>::BaseAssemblyNamePimpl(assembly_name_label_type *pClass) : 
        m_pClass(pClass), 
        m_pFuInfo(nullptr), 
        m_flags(NewAssemblyNameFlags::NANF_UNREACHED), 
        m_platform(Platform::PF_UNREACHED)
    { }

#define SWATHE_DECLARE_BASE_ASSEMBLY_NAME_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    wstring const &BaseAssemblyNamePimpl<ApiHolder>::GetFullName() const
    {
        using std::vector;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::Utilities::StackAllocator;

        typedef vector<WCHAR, StackAllocator<WCHAR> > WCharVector;

        if (m_fullName.empty())
        {
            auto &comAsmName = m_pClass->GetCOMAssemblyName();

            auto wzname = WCharVector();
            auto wznameSize = 0ul;
            auto dwDisplayFlags = static_cast<DWORD>(ASM_DISPLAYF_FULL);
            auto hr = E_FAIL;
            hr = comAsmName.GetDisplayName(nullptr, &wznameSize, dwDisplayFlags);
            if (FAILED(hr) && hr != HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            wzname.resize(wznameSize);
            hr = comAsmName.GetDisplayName(&wzname[0], &wznameSize, dwDisplayFlags);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_fullName = &wzname[0];
        }
        return m_fullName;
    }



    template<class ApiHolder>    
    wstring const &BaseAssemblyNamePimpl<ApiHolder>::GetName() const
    {
        using std::vector;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::Utilities::StackAllocator;

        typedef vector<WCHAR, StackAllocator<WCHAR> > WCharVector;

        if (m_name.empty())
        {
            auto &comAsmName = m_pClass->GetCOMAssemblyName();

            auto wzname = WCharVector();
            auto wznameSize = 0ul;
            auto hr = E_FAIL;
            hr = comAsmName.GetName(&wznameSize, nullptr);
            if (FAILED(hr) && hr != HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            wzname.resize(wznameSize);
            hr = comAsmName.GetName(&wznameSize, &wzname[0]);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_name = &wzname[0];
        }
        return m_name;
    }



    template<class ApiHolder>    
    Platform BaseAssemblyNamePimpl<ApiHolder>::GetPlatform() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_platform == Platform::PF_UNREACHED)
        {
            auto &comAsmName = m_pClass->GetCOMAssemblyName();

            auto dwplatform = peNone;
            auto dwplatformSize = static_cast<DWORD>(sizeof(PEKIND));
            auto hr = comAsmName.GetProperty(ASM_NAME_ARCHITECTURE, reinterpret_cast<LPBYTE>(&dwplatform), &dwplatformSize);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            m_platform = Platform(dwplatform);
        }
        return m_platform;
    }



    template<class ApiHolder>    
    void BaseAssemblyNamePimpl<ApiHolder>::Initialize(fusion_info_label_type const *pFuInfo)
    {
        _ASSERTE(!m_pFuInfo);
        _ASSERTE(pFuInfo);
        m_pFuInfo = pFuInfo;
    }



    template<class ApiHolder>    
    void BaseAssemblyNamePimpl<ApiHolder>::SetDisplayName(wstring const &displayName)
    {
        _ASSERTE(m_displayName.empty());
        _ASSERTE(!displayName.empty());
        m_displayName = displayName;
    }



    template<class ApiHolder>    
    void BaseAssemblyNamePimpl<ApiHolder>::SetFlags(NewAssemblyNameFlags const &flags)
    {
        _ASSERTE(m_flags == NewAssemblyNameFlags::NANF_UNREACHED);
        _ASSERTE(flags != NewAssemblyNameFlags::NANF_UNREACHED);
        m_flags = flags;
    }



    template<class ApiHolder>    
    void BaseAssemblyNamePimpl<ApiHolder>::SetCOMAssemblyName(IAssemblyName *pComAsmName)
    {
        _ASSERTE(!m_pComAsmName);
        _ASSERTE(pComAsmName);
        m_pComAsmName = pComAsmName;
    }



    template<class ApiHolder>    
    IAssemblyName &BaseAssemblyNamePimpl<ApiHolder>::GetCOMAssemblyName()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::CppAnonymSystemException;

        if (!m_pComAsmName)
        {
            _ASSERTE(!m_displayName.empty());
            _ASSERTE(m_flags != NewAssemblyNameFlags::NANF_UNREACHED);

            auto hmodFusion = m_pFuInfo->GetFusionHandle();
            
            typedef HRESULT (__stdcall *CreateAssemblyNameObjectPtr)(LPASSEMBLYNAME *ppAssemblyNameObj, LPCWSTR szAssemblyName, DWORD dwFlags, LPVOID pvReserved);
            auto *pfnCreateAssemblyNameObject = reinterpret_cast<CreateAssemblyNameObjectPtr>(::GetProcAddress(hmodFusion, "CreateAssemblyNameObject"));
            if (!pfnCreateAssemblyNameObject)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        
            auto const *szAssemblyName = m_displayName.c_str();
            auto dwflags = m_flags.Value();
            auto hr = pfnCreateAssemblyNameObject(&m_pComAsmName, szAssemblyName, dwflags, nullptr);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComAsmName;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPL_HPP

