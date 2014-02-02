/* 
 * File: BaseProfilingInfoPimpl.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseProfilingInfoPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseProfilingInfoPimpl<ApiHolder>::BaseProfilingInfoPimpl(profiling_info_label_type *pClass) : 
        m_pClass(pClass), 
        m_pRuntime(nullptr), 
        m_procProfIndex(static_cast<SIZE_T>(-1))
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseProfilingInfoPimpl<ApiHolder>::~BaseProfilingInfoPimpl()
    {
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseProfilingInfoPimpl<ApiHolder>::base_heap_provider_type *BaseProfilingInfoPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseProfilingInfoPimpl<ApiHolder>::base_heap_provider_type const *BaseProfilingInfoPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_PROFILING_INFO_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::process_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::AttachToCurrentProcess(IUnknown *pComProfInfoUnk)
    {
        if (m_procProfIndex == static_cast<SIZE_T>(-1))
        {
            return NewProcessProfiler(pComProfInfoUnk);
        }
        else
        {
            _ASSERTE(&m_pCurrentProcProf->GetCOMProfilerInfoUnknown() == pComProfInfoUnk);
            return m_pCurrentProcProf;
        }
    }



    template<class ApiHolder>    
    typename BaseProfilingInfoPimpl<ApiHolder>::process_profiler_label_type *BaseProfilingInfoPimpl<ApiHolder>::GetCurrentProcessProfiler()
    {
        _ASSERTE(m_procProfIndex != static_cast<SIZE_T>(-1));
        return m_pCurrentProcProf.Get();
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromCurrentProcess()
    {
        if (m_procProfIndex == static_cast<SIZE_T>(-1))
            return;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<process_profiler_label_type>();
        provider.DeleteObject(m_procProfIndex);
        
        m_procProfIndex = static_cast<SIZE_T>(-1);
    }



    template<class ApiHolder>    
    typename BaseProfilingInfoPimpl<ApiHolder>::runtime_host_label_type const *BaseProfilingInfoPimpl<ApiHolder>::GetRuntime() const
    {
        return m_pRuntime;
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::Initialize(runtime_host_label_type const *pRuntime)
    {
        _ASSERTE(pRuntime != nullptr);
        _ASSERTE(m_pRuntime == nullptr);
        m_pRuntime = pRuntime;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::process_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewProcessProfiler(IUnknown *pComProfInfoUnk)
    {
        auto pProcProf = NewProcessProfilerCore();
        pProcProf->SetCOMProfilerInfoUnknown(pComProfInfoUnk);
        return pProcProf;
    }


    
    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::process_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewProcessProfilerCore()
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<process_profiler_label_type>();
        auto pProcProf = provider.NewObject();
        pProcProf->Initialize(m_pClass);
        auto handler = process_profiler_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pProcProf, handler);
        return pProcProf;
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::RegisterProcessProfiler(TempPtr<process_profiler_label_type> &pProcProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<process_profiler_label_type>();
        m_procProfIndex = provider.RegisterObject(pProcProf);
        m_pCurrentProcProf = pProcProf;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_HPP

