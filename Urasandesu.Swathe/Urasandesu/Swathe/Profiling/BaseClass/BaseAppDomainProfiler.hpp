/* 
 * File: BaseAppDomainProfiler.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEAPPDOMAINPROFILER_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEAPPDOMAINPROFILER_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEAPPDOMAINPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseAppDomainProfiler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAppDomainProfiler<ApiHolder>::BaseAppDomainProfiler()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(app_domain_profiler_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(app_domain_profiler_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())app_domain_profiler_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseAppDomainProfiler<ApiHolder>::~BaseAppDomainProfiler()
    {
        Pimpl()->~app_domain_profiler_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseAppDomainProfiler<ApiHolder>::app_domain_profiler_pimpl_label_type *BaseAppDomainProfiler<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<app_domain_profiler_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAppDomainProfiler<ApiHolder>::app_domain_profiler_pimpl_label_type const *BaseAppDomainProfiler<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_APP_DOMAIN_PROFILER_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    UINT_PTR BaseAppDomainProfiler<ApiHolder>::GetID() const
    {
        return Pimpl()->GetID();
    }

    template<class ApiHolder>    
    typename BaseAppDomainProfiler<ApiHolder>::metadata_dispenser_label_type *BaseAppDomainProfiler<ApiHolder>::GetMetadataDispenser()
    {
        return Pimpl()->GetMetadataDispenser();
    }

    template<class ApiHolder>    
    AnyPtr BaseAppDomainProfiler<ApiHolder>::GetData(wstring const &name)
    {
        return Pimpl()->GetData(name);
    }

    template<class ApiHolder>    
    void BaseAppDomainProfiler<ApiHolder>::SetData(wstring const &name, AnyPtr const &pData)
    {
        Pimpl()->SetData(name, pData);
    }

    template<class ApiHolder>    
    void BaseAppDomainProfiler<ApiHolder>::Initialize(process_profiler_label_type *pProcProf, metadata_info_label_type *pMetaInfo)
    {
        Pimpl()->Initialize(pProcProf, pMetaInfo);
    }

    template<class ApiHolder>    
    void BaseAppDomainProfiler<ApiHolder>::SetID(UINT_PTR id)
    {
        Pimpl()->SetID(id);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEAPPDOMAINPROFILER_HPP

