/* 
 * File: BaseAppDomainProfilerPimpl.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseAppDomainProfilerPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAppDomainProfilerPimpl<ApiHolder>::BaseAppDomainProfilerPimpl(app_domain_profiler_label_type *pClass) : 
        m_pClass(pClass), 
        m_pProcProf(nullptr), 
        m_pMetaInfo(nullptr), 
        m_id(static_cast<UINT_PTR>(-1)), 
        m_pDisp(nullptr)
    { }

    template<class ApiHolder>    
    BaseAppDomainProfilerPimpl<ApiHolder>::~BaseAppDomainProfilerPimpl()
    {
        if (m_pDisp)
        {
            m_pMetaInfo->UnloadDispenser(m_pDisp);
            m_pDisp = nullptr;
        }
    }

#define SWATHE_DECLARE_BASE_APP_DOMAIN_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    UINT_PTR BaseAppDomainProfilerPimpl<ApiHolder>::GetID() const
    {
        _ASSERTE(m_id != static_cast<UINT_PTR>(-1));
        return m_id;
    }



    template<class ApiHolder>    
    typename BaseAppDomainProfilerPimpl<ApiHolder>::metadata_dispenser_label_type *BaseAppDomainProfilerPimpl<ApiHolder>::GetMetadataDispenser()
    {
        if (!m_pDisp)
            m_pDisp = m_pMetaInfo->CreateDispenser();
        return m_pDisp;
    }



    template<class ApiHolder>    
    AnyPtr BaseAppDomainProfilerPimpl<ApiHolder>::GetData(wstring const &name)
    {
        typedef decltype(m_dataEntries) DataEntries;
        typedef DataEntries::iterator Iterator;

        auto result = Iterator();
        if ((result = m_dataEntries.find(name)) != m_dataEntries.end())
        {
            return (*result).second;
        }
        else
        {
            return AnyPtr();
        }
    }



    template<class ApiHolder>    
    void BaseAppDomainProfilerPimpl<ApiHolder>::SetData(wstring const &name, AnyPtr const &pData)
    {
        m_dataEntries[name] = pData;
    }



    template<class ApiHolder>    
    void BaseAppDomainProfilerPimpl<ApiHolder>::Initialize(process_profiler_label_type *pProcProf, metadata_info_label_type *pMetaInfo)
    {
        _ASSERTE(pProcProf != nullptr);
        _ASSERTE(m_pProcProf == nullptr);
        m_pProcProf = pProcProf;

        _ASSERTE(pMetaInfo != nullptr);
        _ASSERTE(m_pMetaInfo == nullptr);
        m_pMetaInfo = pMetaInfo;
    }



    template<class ApiHolder>    
    void BaseAppDomainProfilerPimpl<ApiHolder>::SetID(UINT_PTR id)
    {
        _ASSERTE(id != static_cast<UINT_PTR>(-1));
        _ASSERTE(m_id == static_cast<UINT_PTR>(-1));
        m_id = id;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPL_HPP

