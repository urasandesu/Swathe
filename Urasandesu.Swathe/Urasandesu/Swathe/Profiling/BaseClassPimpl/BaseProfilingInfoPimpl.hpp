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
        m_pRuntime(nullptr)
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
        DetachFromCurrentProcess();
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
    void BaseProfilingInfoPimpl<ApiHolder>::Initialize(runtime_host_label_type *pRuntime)
    {
        _ASSERTE(!m_pRuntime);
        _ASSERTE(pRuntime);
        m_pRuntime = pRuntime;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::process_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::AttachToCurrentProcess(IUnknown *pComProfInfoUnk)
    {
        if (!m_pCurrentProcProf)
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
        _ASSERTE(m_pCurrentProcProf);
        return m_pCurrentProcProf.Get();
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromCurrentProcess()
    {
        if (!m_pCurrentProcProf)
            return;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<process_profiler_label_type>();
        provider.DeleteObject(m_pCurrentProcProf.Get());
        
        m_pCurrentProcProf = TempPtr<process_profiler_label_type>();
    }



    template<class ApiHolder>    
    typename BaseProfilingInfoPimpl<ApiHolder>::runtime_host_label_type const *BaseProfilingInfoPimpl<ApiHolder>::GetRuntime() const
    {
        return m_pRuntime;
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
        provider.RegisterObject(pProcProf);
        m_pCurrentProcProf = pProcProf;
    }

    
    
    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::app_domain_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewAppDomainProfilerCore(process_profiler_label_type *pProcProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<app_domain_profiler_label_type>();
        auto pDomainProf = provider.NewObject();
        auto const *pRuntime = GetRuntime();
        auto *pMetaInfo = pRuntime->GetInfo<metadata_info_label_type>();
        pDomainProf->Initialize(pProcProf, pMetaInfo);
        auto handler = app_domain_profiler_persisted_handler_label_type(pProcProf);
        provider.AddPersistedHandler(pDomainProf, handler);
        return pDomainProf;
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::RegisterAppDomainProfilerCore(TempPtr<app_domain_profiler_label_type> &pDomainProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<app_domain_profiler_label_type>();
        provider.RegisterObject(pDomainProf);
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromAppDomainCore(app_domain_profiler_label_type *pDomainProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<app_domain_profiler_label_type>();
        provider.DeleteObject(pDomainProf);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::assembly_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewAssemblyProfilerCore(process_profiler_label_type *pProcProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_profiler_label_type>();
        auto pAsmProf = provider.NewObject();
        pAsmProf->Initialize(pProcProf);
        auto handler = assembly_profiler_persisted_handler_label_type(pProcProf);
        provider.AddPersistedHandler(pAsmProf, handler);
        return pAsmProf;
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::RegisterAssemblyProfilerCore(TempPtr<assembly_profiler_label_type> &pAsmProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_profiler_label_type>();
        provider.RegisterObject(pAsmProf);
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromAssemblyCore(assembly_profiler_label_type *pAsmProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_profiler_label_type>();
        provider.DeleteObject(pAsmProf);
    }


        
    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::module_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewModuleProfilerCore(process_profiler_label_type *pProcProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_profiler_label_type>();
        auto pModProf = provider.NewObject();
        pModProf->Initialize(pProcProf);
        auto handler = module_profiler_persisted_handler_label_type(pProcProf);
        provider.AddPersistedHandler(pModProf, handler);
        return pModProf;
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::RegisterModuleProfilerCore(TempPtr<module_profiler_label_type> &pModProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_profiler_label_type>();
        provider.RegisterObject(pModProf);
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromModuleCore(module_profiler_label_type *pModProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_profiler_label_type>();
        provider.DeleteObject(pModProf);
    }


        
    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::class_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewClassProfilerCore(process_profiler_label_type *pProcProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<class_profiler_label_type>();
        auto pClsProf = provider.NewObject();
        pClsProf->Initialize(pProcProf);
        auto handler = class_profiler_persisted_handler_label_type(pProcProf);
        provider.AddPersistedHandler(pClsProf, handler);
        return pClsProf;
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::RegisterClassProfilerCore(TempPtr<class_profiler_label_type> &pClsProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<class_profiler_label_type>();
        provider.RegisterObject(pClsProf);
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromClassCore(class_profiler_label_type *pClsProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<class_profiler_label_type>();
        provider.DeleteObject(pClsProf);
    }


        
    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::function_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewFunctionProfilerCore(process_profiler_label_type *pProcProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_profiler_label_type>();
        auto pFuncProf = provider.NewObject();
        pFuncProf->Initialize(pProcProf);
        auto handler = function_profiler_persisted_handler_label_type(pProcProf);
        provider.AddPersistedHandler(pFuncProf, handler);
        return pFuncProf;
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::RegisterFunctionProfilerCore(TempPtr<function_profiler_label_type> &pFuncProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_profiler_label_type>();
        provider.RegisterObject(pFuncProf);
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromFunctionCore(function_profiler_label_type *pFuncProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_profiler_label_type>();
        provider.DeleteObject(pFuncProf);
    }


        
    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfoPimpl<ApiHolder>::function_body_profiler_label_type> BaseProfilingInfoPimpl<ApiHolder>::NewFunctionBodyProfilerCore(process_profiler_label_type *pProcProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_body_profiler_label_type>();
        auto pBodyProf = provider.NewObject();
        pBodyProf->Initialize(pProcProf);
        auto handler = function_body_profiler_persisted_handler_label_type(pProcProf);
        provider.AddPersistedHandler(pBodyProf, handler);
        return pBodyProf;
    }


    
    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::RegisterFunctionBodyProfilerCore(TempPtr<function_body_profiler_label_type> &pBodyProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_body_profiler_label_type>();
        provider.RegisterObject(pBodyProf);
    }



    template<class ApiHolder>    
    void BaseProfilingInfoPimpl<ApiHolder>::DetachFromFunctionBodyCore(function_body_profiler_label_type *pBodyProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_body_profiler_label_type>();
        provider.DeleteObject(pBodyProf);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_HPP

