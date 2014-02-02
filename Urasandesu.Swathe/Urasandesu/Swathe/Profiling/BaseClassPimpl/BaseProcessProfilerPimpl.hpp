/* 
 * File: BaseProcessProfilerPimpl.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseProcessProfilerPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROCESSPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultProcessProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProcessProfiler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseProcessProfilerPimpl<ApiHolder>::BaseProcessProfilerPimpl(process_profiler_label_type *pClass) : 
        m_pClass(pClass), 
        m_pProfInfo(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseProcessProfilerPimpl<ApiHolder>::~BaseProcessProfilerPimpl()
    {
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseProcessProfilerPimpl<ApiHolder>::base_heap_provider_type *BaseProcessProfilerPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseProcessProfilerPimpl<ApiHolder>::base_heap_provider_type const *BaseProcessProfilerPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_PROCESS_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::SetEventMask(ProfilerEvents const &events)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comProfInfo = GetCOMProfilerInfo();
        auto hr = comProfInfo.SetEventMask(events.Value());
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::app_domain_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToAppDomain(AppDomainID appDomainId)
    {
        auto result = m_appDomainIdToIndex.find(appDomainId);
        if (result == m_appDomainIdToIndex.end())
        {
            return NewAppDomainProfiler(appDomainId);
        }
        else
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<app_domain_profiler_label_type>();
            auto index = (*result).second;
            auto *pExistingDomainProf = provider.GetObject(index);
            return TempPtr<app_domain_profiler_label_type>(pExistingDomainProf, true);
        }
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::DetachFromAppDomain(AppDomainID appDomainId)
    {
        auto result = m_appDomainIdToIndex.find(appDomainId);
        if (result == m_appDomainIdToIndex.end())
            return;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<app_domain_profiler_label_type>();
        auto index = (*result).second;
        provider.DeleteObject(index);

        m_appDomainIdToIndex.erase(result);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::assembly_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToAssembly(AssemblyID assemblyId)
    {
        auto result = m_assemblyIdToIndex.find(assemblyId);
        if (result == m_assemblyIdToIndex.end())
        {
            return NewAssemblyProfiler(assemblyId);
        }
        else
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<assembly_profiler_label_type>();
            auto index = (*result).second;
            auto *pExistingAsmProf = provider.GetObject(index);
            return TempPtr<assembly_profiler_label_type>(pExistingAsmProf, true);
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::module_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToModule(ModuleID moduleId)
    {
        auto result = m_moduleIdToIndex.find(moduleId);
        if (result == m_moduleIdToIndex.end())
        {
            return NewModuleProfiler(moduleId);
        }
        else
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<module_profiler_label_type>();
            auto index = (*result).second;
            auto *pExistingModProf = provider.GetObject(index);
            return TempPtr<module_profiler_label_type>(pExistingModProf, true);
        }
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::DetachFromModule(ModuleID moduleId)
    {
        auto result = m_moduleIdToIndex.find(moduleId);
        if (result == m_moduleIdToIndex.end())
            return;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_profiler_label_type>();
        auto index = (*result).second;
        provider.DeleteObject(index);

        m_moduleIdToIndex.erase(result);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::class_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToClass(ClassID classId)
    {
        auto result = m_classIdToIndex.find(classId);
        if (result == m_classIdToIndex.end())
        {
            return NewClassProfiler(classId);
        }
        else
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<class_profiler_label_type>();
            auto index = (*result).second;
            auto *pExistingClsProf = provider.GetObject(index);
            return TempPtr<class_profiler_label_type>(pExistingClsProf, true);
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToFunction(FunctionID functionId)
    {
        auto result = m_functionIdToIndex.find(functionId);
        if (result == m_functionIdToIndex.end())
        {
            return NewFunctionProfiler(functionId);
        }
        else
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<function_profiler_label_type>();
            auto index = (*result).second;
            auto *pExistingFuncProf = provider.GetObject(index);
            return TempPtr<function_profiler_label_type>(pExistingFuncProf, true);
        }
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::DetachFromFunction(FunctionID functionId)
    {
        auto result = m_functionIdToIndex.find(functionId);
        if (result == m_functionIdToIndex.end())
            return;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_profiler_label_type>();
        auto index = (*result).second;
        provider.DeleteObject(index);

        m_functionIdToIndex.erase(result);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_body_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToFunctionBody(FunctionID functionId, FunctionBodyID functionBodyId)
    {
        auto result = m_functionBodyIdToIndex.find(functionBodyId);
        if (result == m_functionBodyIdToIndex.end())
        {
            return NewFunctionBodyProfiler(functionId, functionBodyId);
        }
        else
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<function_body_profiler_label_type>();
            auto index = (*result).second;
            auto *pExistingBodyProf = provider.GetObject(index);
            return TempPtr<function_body_profiler_label_type>(pExistingBodyProf, true);
        }
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::Initialize(profiling_info_label_type *pProfInfo)
    {
        _ASSERTE(pProfInfo != nullptr);
        _ASSERTE(m_pProfInfo == nullptr);
        m_pProfInfo = pProfInfo;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::app_domain_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewAppDomainProfiler(AppDomainID appDomainId)
    {
        auto pDomainProf = NewAppDomainProfilerCore();
        pDomainProf->SetID(appDomainId);
        return pDomainProf;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::app_domain_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewAppDomainProfilerCore()
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<app_domain_profiler_label_type>();
        auto pDomainProf = provider.NewObject();
        auto const *pRuntime = m_pProfInfo->GetRuntime();
        auto *pMetaInfo = pRuntime->GetInfo<metadata_info_label_type>();
        pDomainProf->Initialize(m_pClass, pMetaInfo);
        auto handler = app_domain_profiler_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pDomainProf, handler);
        return pDomainProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterAppDomainProfiler(TempPtr<app_domain_profiler_label_type> &pDomainProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<app_domain_profiler_label_type>();
        auto appDomainId = pDomainProf->GetID();
        auto index = provider.RegisterObject(pDomainProf);
        m_appDomainIdToIndex[appDomainId] = index;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::assembly_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewAssemblyProfiler(AssemblyID assemblyId)
    {
        auto pAsmProf = NewAssemblyProfilerCore();
        pAsmProf->SetID(assemblyId);
        return pAsmProf;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::assembly_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewAssemblyProfilerCore()
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_profiler_label_type>();
        auto pAsmProf = provider.NewObject();
        pAsmProf->Initialize(m_pClass);
        auto handler = assembly_profiler_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pAsmProf, handler);
        return pAsmProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterAssemblyProfiler(TempPtr<assembly_profiler_label_type> &pAsmProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_profiler_label_type>();
        auto assemblyId = pAsmProf->GetID();
        auto index = provider.RegisterObject(pAsmProf);
        m_assemblyIdToIndex[assemblyId] = index;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::module_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewModuleProfiler(ModuleID moduleId)
    {
        auto pModProf = NewModuleProfilerCore();
        pModProf->SetID(moduleId);
        return pModProf;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::module_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewModuleProfilerCore()
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_profiler_label_type>();
        auto pModProf = provider.NewObject();
        pModProf->Initialize(m_pClass);
        auto handler = module_profiler_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pModProf, handler);
        return pModProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterModuleProfiler(TempPtr<module_profiler_label_type> &pModProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_profiler_label_type>();
        auto moduleId = pModProf->GetID();
        auto index = provider.RegisterObject(pModProf);
        m_moduleIdToIndex[moduleId] = index;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::class_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewClassProfiler(ClassID classId)
    {
        auto pClsProf = NewClassProfilerCore();
        pClsProf->SetID(classId);
        return pClsProf;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::class_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewClassProfilerCore()
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<class_profiler_label_type>();
        auto pClsProf = provider.NewObject();
        pClsProf->Initialize(m_pClass);
        auto handler = class_profiler_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pClsProf, handler);
        return pClsProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterClassProfiler(TempPtr<class_profiler_label_type> &pClsProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<class_profiler_label_type>();
        auto classId = pClsProf->GetID();
        auto index = provider.RegisterObject(pClsProf);
        m_classIdToIndex[classId] = index;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewFunctionProfiler(FunctionID functionId)
    {
        auto pFuncProf = NewFunctionProfilerCore();
        pFuncProf->SetID(functionId);
        return pFuncProf;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewFunctionProfilerCore()
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_profiler_label_type>();
        auto pFuncProf = provider.NewObject();
        pFuncProf->Initialize(m_pClass);
        auto handler = function_profiler_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pFuncProf, handler);
        return pFuncProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterFunctionProfiler(TempPtr<function_profiler_label_type> &pFuncProf)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_profiler_label_type>();
        auto functionId = pFuncProf->GetID();
        auto index = provider.RegisterObject(pFuncProf);
        m_functionIdToIndex[functionId] = index;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_body_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewFunctionBodyProfiler(FunctionID functionId, FunctionBodyID functionBodyId)
    {
        auto pBodyProf = NewFunctionBodyProfilerCore();
        pBodyProf->SetID(functionBodyId);
        pBodyProf->SetFunctionID(functionId);
        return pBodyProf;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_body_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewFunctionBodyProfilerCore()
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_body_profiler_label_type>();
        auto pBodyProf = provider.NewObject();
        pBodyProf->Initialize(m_pClass);
        auto handler = function_body_profiler_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pBodyProf, handler);
        return pBodyProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterFunctionBodyProfiler(TempPtr<function_body_profiler_label_type> &pBodyProf)
    {
        using Urasandesu::CppAnonym::CppAnonymInvalidOperationException;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<function_body_profiler_label_type>();
        auto functionBodyId = pBodyProf->GetID();
        if (functionBodyId == static_cast<UINT_PTR>(-1))
            BOOST_THROW_EXCEPTION(CppAnonymInvalidOperationException(L"This FunctionBodyProfiler does not have the identifier(FunctionBodyID == -1)."));
        auto index = provider.RegisterObject(pBodyProf);
        m_functionBodyIdToIndex[functionBodyId] = index;
    }



    template<class ApiHolder>    
    ICorProfilerInfo2 &BaseProcessProfilerPimpl<ApiHolder>::GetCOMProfilerInfo()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pComProfInfo.p == nullptr)
        {
            auto &comProfInfoUnk = GetCOMProfilerInfoUnknown();
            auto hr = comProfInfoUnk.QueryInterface(IID_ICorProfilerInfo2, 
                                                    reinterpret_cast<void **>(&m_pComProfInfo));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComProfInfo;
    }



    template<class ApiHolder>    
    IUnknown &BaseProcessProfilerPimpl<ApiHolder>::GetCOMProfilerInfoUnknown()
    {
        return *m_pComProfInfoUnk;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::SetCOMProfilerInfoUnknown(IUnknown *pComProfInfoUnk)
    {
        _ASSERTE(pComProfInfoUnk != nullptr);
        _ASSERTE(m_pComProfInfoUnk.p == nullptr);
        m_pComProfInfoUnk = pComProfInfoUnk;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_HPP

