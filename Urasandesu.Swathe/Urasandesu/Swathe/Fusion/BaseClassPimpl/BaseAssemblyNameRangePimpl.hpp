/* 
 * File: BaseAssemblyNameRangePimpl.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPL_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPL_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPL_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyNameRangePimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAssemblyNameRangePimpl<ApiHolder>::BaseAssemblyNameRangePimpl(assembly_name_range_label_type *pClass) : 
        m_pClass(pClass), 
        m_pFuInfo(nullptr), 
        m_flags(AssemblyCacheFlags::ACF_UNREACHED)
    { }

#define SWATHE_DECLARE_BASE_ASSEMBLY_NAME_RANGE_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    typename BaseAssemblyNameRangePimpl<ApiHolder>::iterator BaseAssemblyNameRangePimpl<ApiHolder>::begin()
    {
        m_pClass->Reset();
        auto i = iterator(m_pClass);
        ++i;
        return i;
    }



    template<class ApiHolder>    
    typename BaseAssemblyNameRangePimpl<ApiHolder>::const_iterator BaseAssemblyNameRangePimpl<ApiHolder>::begin() const
    {
        m_pClass->Reset();
        auto i = const_iterator(m_pClass);
        ++i;
        return i;
    }



    template<class ApiHolder>    
    typename BaseAssemblyNameRangePimpl<ApiHolder>::const_iterator BaseAssemblyNameRangePimpl<ApiHolder>::cbegin() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    typename BaseAssemblyNameRangePimpl<ApiHolder>::iterator BaseAssemblyNameRangePimpl<ApiHolder>::end()
    {
        return iterator(m_pClass, false);
    }



    template<class ApiHolder>    
    typename BaseAssemblyNameRangePimpl<ApiHolder>::const_iterator BaseAssemblyNameRangePimpl<ApiHolder>::end() const
    {
        return const_iterator(m_pClass, false);
    }



    template<class ApiHolder>    
    typename BaseAssemblyNameRangePimpl<ApiHolder>::const_iterator BaseAssemblyNameRangePimpl<ApiHolder>::cend() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    AutoPtr<typename BaseAssemblyNameRangePimpl<ApiHolder>::assembly_name_label_type const> &BaseAssemblyNameRangePimpl<ApiHolder>::GetCurrent()
    {
        return m_pCurrent;
    }



    template<class ApiHolder>    
    void BaseAssemblyNameRangePimpl<ApiHolder>::Reset()
    {
        m_pComAsmEnum.Release();
    }



    template<class ApiHolder>    
    bool BaseAssemblyNameRangePimpl<ApiHolder>::MoveNext()
    {
        using ATL::CComPtr;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comAsmEnum = m_pClass->GetCOMAssemblyEnum();

        auto pAsmName = CComPtr<IAssemblyName>();
        auto hr = comAsmEnum.GetNextAssembly(nullptr, &pAsmName, 0);
        if (FAILED(hr)) 
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        if (hr == S_FALSE)
            m_pCurrent = AutoPtr<assembly_name_label_type>();
        else
            m_pCurrent = m_pFuInfo->NewAssemblyName(pAsmName);

        return hr != S_FALSE;
    }



    template<class ApiHolder>    
    void BaseAssemblyNameRangePimpl<ApiHolder>::Initialize(fusion_info_label_type const *pFuInfo)
    {
        _ASSERTE(!m_pFuInfo);
        _ASSERTE(pFuInfo);
        m_pFuInfo = pFuInfo;
    }



    template<class ApiHolder>    
    void BaseAssemblyNameRangePimpl<ApiHolder>::SetCondition(AutoPtr<assembly_name_label_type> const &pCondition)
    {
        _ASSERTE(!m_pCondition);
        _ASSERTE(pCondition);
        m_pCondition = pCondition;
    }

    
    
    template<class ApiHolder>    
    void BaseAssemblyNameRangePimpl<ApiHolder>::SetFlags(AssemblyCacheFlags const &flags)
    {
        _ASSERTE(m_flags == AssemblyCacheFlags::ACF_UNREACHED);
        _ASSERTE(flags != AssemblyCacheFlags::ACF_UNREACHED);
        m_flags = flags;
    }



    template<class ApiHolder>    
    IAssemblyEnum &BaseAssemblyNameRangePimpl<ApiHolder>::GetCOMAssemblyEnum()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::CppAnonymSystemException;

        if (!m_pComAsmEnum)
        {
            auto hmodFusion = m_pFuInfo->GetFusionHandle();

            typedef HRESULT (__stdcall *CreateAssemblyEnumPtr)(IAssemblyEnum **pEnum, IUnknown *pUnkReserved, IAssemblyName *pName, DWORD dwFlags, LPVOID pvReserved);      
            auto *pfnCreateAssemblyEnum = reinterpret_cast<CreateAssemblyEnumPtr>(::GetProcAddress(hmodFusion, "CreateAssemblyEnum"));
            if (!pfnCreateAssemblyEnum)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        
            auto &comAsmName = m_pCondition->GetCOMAssemblyName();
            auto dwflags = m_flags.Value();
            auto hr = pfnCreateAssemblyEnum(&m_pComAsmEnum, nullptr, &comAsmName, dwflags, nullptr);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComAsmEnum;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPL_HPP

