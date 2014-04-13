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
    { }

    template<class ApiHolder>    
    BaseProcessProfilerPimpl<ApiHolder>::~BaseProcessProfilerPimpl()
    {
        BOOST_FOREACH (auto const &pair, m_appDomainIdToObjs)
            m_pProfInfo->DetachFromAppDomainCore(pair.second);

        BOOST_FOREACH (auto const &pair, m_assemblyIdToObjs)
            m_pProfInfo->DetachFromAssemblyCore(pair.second);

        BOOST_FOREACH (auto const &pair, m_moduleIdToObjs)
            m_pProfInfo->DetachFromModuleCore(pair.second);

        BOOST_FOREACH (auto const &pair, m_classIdToObjs)
            m_pProfInfo->DetachFromClassCore(pair.second);

        BOOST_FOREACH (auto const &pair, m_functionIdToObjs)
            m_pProfInfo->DetachFromFunctionCore(pair.second);

        BOOST_FOREACH (auto const &pair, m_functionBodyIdToObjs)
            m_pProfInfo->DetachFromFunctionBodyCore(pair.second);
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
        auto result = m_appDomainIdToObjs.find(appDomainId);
        if (result == m_appDomainIdToObjs.end())
        {
            return NewAppDomainProfiler(appDomainId);
        }
        else
        {
            auto *pExistingDomainProf = (*result).second;
            return TempPtr<app_domain_profiler_label_type>(pExistingDomainProf, true);
        }
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::DetachFromAppDomain(AppDomainID appDomainId)
    {
        auto result = m_appDomainIdToObjs.find(appDomainId);
        if (result == m_appDomainIdToObjs.end())
            return;

        m_pProfInfo->DetachFromAppDomainCore((*result).second);
        m_appDomainIdToObjs.erase(result);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::assembly_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToAssembly(AssemblyID assemblyId)
    {
        auto result = m_assemblyIdToObjs.find(assemblyId);
        if (result == m_assemblyIdToObjs.end())
        {
            return NewAssemblyProfiler(assemblyId);
        }
        else
        {
            auto *pExistingAsmProf = (*result).second;
            return TempPtr<assembly_profiler_label_type>(pExistingAsmProf, true);
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::module_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToModule(ModuleID moduleId)
    {
        auto result = m_moduleIdToObjs.find(moduleId);
        if (result == m_moduleIdToObjs.end())
        {
            return NewModuleProfiler(moduleId);
        }
        else
        {
            auto *pExistingModProf = (*result).second;
            return TempPtr<module_profiler_label_type>(pExistingModProf, true);
        }
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::DetachFromModule(ModuleID moduleId)
    {
        auto result = m_moduleIdToObjs.find(moduleId);
        if (result == m_moduleIdToObjs.end())
            return;

        m_pProfInfo->DetachFromModuleCore((*result).second);
        m_moduleIdToObjs.erase(result);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::class_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToClass(ClassID classId)
    {
        auto result = m_classIdToObjs.find(classId);
        if (result == m_classIdToObjs.end())
        {
            return NewClassProfiler(classId);
        }
        else
        {
            auto *pExistingClsProf = (*result).second;
            return TempPtr<class_profiler_label_type>(pExistingClsProf, true);
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToFunction(FunctionID functionId)
    {
        auto result = m_functionIdToObjs.find(functionId);
        if (result == m_functionIdToObjs.end())
        {
            return NewFunctionProfiler(functionId);
        }
        else
        {
            auto *pExistingFuncProf = (*result).second;
            return TempPtr<function_profiler_label_type>(pExistingFuncProf, true);
        }
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::DetachFromFunction(FunctionID functionId)
    {
        auto result = m_functionIdToObjs.find(functionId);
        if (result == m_functionIdToObjs.end())
            return;

        m_pProfInfo->DetachFromFunctionCore((*result).second);
        m_functionIdToObjs.erase(result);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_body_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::AttachToFunctionBody(FunctionID functionId, FunctionBodyID functionBodyId)
    {
        auto result = m_functionBodyIdToObjs.find(functionBodyId);
        if (result == m_functionBodyIdToObjs.end())
        {
            return NewFunctionBodyProfiler(functionId, functionBodyId);
        }
        else
        {
            auto *pExistingBodyProf = (*result).second;
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
        auto pDomainProf = m_pProfInfo->NewAppDomainProfilerCore(m_pClass);
        pDomainProf->SetID(appDomainId);
        return pDomainProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterAppDomainProfiler(TempPtr<app_domain_profiler_label_type> &pDomainProf)
    {
        auto appDomainId = pDomainProf->GetID();
        m_pProfInfo->RegisterAppDomainProfilerCore(pDomainProf);
        m_appDomainIdToObjs[appDomainId] = pDomainProf.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::assembly_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewAssemblyProfiler(AssemblyID assemblyId)
    {
        auto pAsmProf = m_pProfInfo->NewAssemblyProfilerCore(m_pClass);
        pAsmProf->SetID(assemblyId);
        return pAsmProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterAssemblyProfiler(TempPtr<assembly_profiler_label_type> &pAsmProf)
    {
        auto assemblyId = pAsmProf->GetID();
        m_pProfInfo->RegisterAssemblyProfilerCore(pAsmProf);
        m_assemblyIdToObjs[assemblyId] = pAsmProf.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::module_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewModuleProfiler(ModuleID moduleId)
    {
        auto pModProf = m_pProfInfo->NewModuleProfilerCore(m_pClass);
        pModProf->SetID(moduleId);
        return pModProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterModuleProfiler(TempPtr<module_profiler_label_type> &pModProf)
    {
        auto moduleId = pModProf->GetID();
        m_pProfInfo->RegisterModuleProfilerCore(pModProf);
        m_moduleIdToObjs[moduleId] = pModProf.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::class_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewClassProfiler(ClassID classId)
    {
        auto pClsProf = m_pProfInfo->NewClassProfilerCore(m_pClass);
        pClsProf->SetID(classId);
        return pClsProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterClassProfiler(TempPtr<class_profiler_label_type> &pClsProf)
    {
        auto classId = pClsProf->GetID();
        m_pProfInfo->RegisterClassProfilerCore(pClsProf);
        m_classIdToObjs[classId] = pClsProf.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewFunctionProfiler(FunctionID functionId)
    {
        auto pFuncProf = m_pProfInfo->NewFunctionProfilerCore(m_pClass);
        pFuncProf->SetID(functionId);
        return pFuncProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterFunctionProfiler(TempPtr<function_profiler_label_type> &pFuncProf)
    {
        auto functionId = pFuncProf->GetID();
        m_pProfInfo->RegisterFunctionProfilerCore(pFuncProf);
        m_functionIdToObjs[functionId] = pFuncProf.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfilerPimpl<ApiHolder>::function_body_profiler_label_type> BaseProcessProfilerPimpl<ApiHolder>::NewFunctionBodyProfiler(FunctionID functionId, FunctionBodyID functionBodyId)
    {
        auto pBodyProf = m_pProfInfo->NewFunctionBodyProfilerCore(m_pClass);
        pBodyProf->SetID(functionBodyId);
        pBodyProf->SetFunctionID(functionId);
        return pBodyProf;
    }



    template<class ApiHolder>    
    void BaseProcessProfilerPimpl<ApiHolder>::RegisterFunctionBodyProfiler(TempPtr<function_body_profiler_label_type> &pBodyProf)
    {
        using Urasandesu::CppAnonym::CppAnonymInvalidOperationException;

        auto functionBodyId = pBodyProf->GetID();
        if (functionBodyId == -1)
            BOOST_THROW_EXCEPTION(CppAnonymInvalidOperationException(L"This FunctionBodyProfiler does not have the identifier(FunctionBodyID == -1)."));
        
        m_pProfInfo->RegisterFunctionBodyProfilerCore(pBodyProf);
        m_functionBodyIdToObjs[functionBodyId] = pBodyProf.Get();
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

