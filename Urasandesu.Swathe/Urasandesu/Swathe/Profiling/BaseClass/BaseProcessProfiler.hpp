/* 
 * File: BaseProcessProfiler.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProcessProfiler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    template<class ApiHolder>    
    BaseProcessProfiler<ApiHolder>::BaseProcessProfiler()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(process_profiler_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(process_profiler_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())process_profiler_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseProcessProfiler<ApiHolder>::~BaseProcessProfiler()
    {
        Pimpl()->~process_profiler_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseProcessProfiler<ApiHolder>::process_profiler_pimpl_label_type *BaseProcessProfiler<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<process_profiler_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseProcessProfiler<ApiHolder>::process_profiler_pimpl_label_type const *BaseProcessProfiler<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PROCESS_PROFILER_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::SetEventMask(ProfilerEvents const &events)
    {
        Pimpl()->SetEventMask(events);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfiler<ApiHolder>::app_domain_profiler_label_type> BaseProcessProfiler<ApiHolder>::AttachToAppDomain(AppDomainID appDomainId)
    {
        return Pimpl()->AttachToAppDomain(appDomainId);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::DetachFromAppDomain(AppDomainID appDomainId)
    {
        Pimpl()->DetachFromAppDomain(appDomainId);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfiler<ApiHolder>::assembly_profiler_label_type> BaseProcessProfiler<ApiHolder>::AttachToAssembly(AssemblyID assemblyId)
    {
        return Pimpl()->AttachToAssembly(assemblyId);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfiler<ApiHolder>::module_profiler_label_type> BaseProcessProfiler<ApiHolder>::AttachToModule(ModuleID moduleId)
    {
        return Pimpl()->AttachToModule(moduleId);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::DetachFromModule(ModuleID moduleId)
    {
        Pimpl()->DetachFromModule(moduleId);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfiler<ApiHolder>::class_profiler_label_type> BaseProcessProfiler<ApiHolder>::AttachToClass(ClassID classId)
    {
        return Pimpl()->AttachToClass(classId);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfiler<ApiHolder>::function_profiler_label_type> BaseProcessProfiler<ApiHolder>::AttachToFunction(FunctionID functionId)
    {
        return Pimpl()->AttachToFunction(functionId);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::DetachFromFunction(FunctionID functionId)
    {
        Pimpl()->DetachFromFunction(functionId);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfiler<ApiHolder>::function_body_profiler_label_type> BaseProcessProfiler<ApiHolder>::AttachToFunctionBody(FunctionID functionId, FunctionBodyID functionBodyId)
    {
        return Pimpl()->AttachToFunctionBody(functionId, functionBodyId);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProcessProfiler<ApiHolder>::app_domain_profiler_label_type> BaseProcessProfiler<ApiHolder>::GetCurrentAppDomain()
    {
        return Pimpl()->GetCurrentAppDomain();
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::Initialize(profiling_info_label_type *pProfInfo)
    {
        Pimpl()->Initialize(pProfInfo);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::RegisterAppDomainProfiler(TempPtr<app_domain_profiler_label_type> &pDomainProf)
    {
        Pimpl()->RegisterAppDomainProfiler(pDomainProf);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::RegisterAssemblyProfiler(TempPtr<assembly_profiler_label_type> &pAsmProf)
    {
        Pimpl()->RegisterAssemblyProfiler(pAsmProf);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::RegisterModuleProfiler(TempPtr<module_profiler_label_type> &pModProf)
    {
        Pimpl()->RegisterModuleProfiler(pModProf);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::RegisterClassProfiler(TempPtr<class_profiler_label_type> &pClsProf)
    {
        Pimpl()->RegisterClassProfiler(pClsProf);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::RegisterFunctionProfiler(TempPtr<function_profiler_label_type> &pFuncProf)
    {
        Pimpl()->RegisterFunctionProfiler(pFuncProf);
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::RegisterFunctionBodyProfiler(TempPtr<function_body_profiler_label_type> &pBodyProf)
    {
        Pimpl()->RegisterFunctionBodyProfiler(pBodyProf);
    }

    template<class ApiHolder>    
    ICorProfilerInfo2 &BaseProcessProfiler<ApiHolder>::GetCOMProfilerInfo()
    {
        return Pimpl()->GetCOMProfilerInfo();
    }

    template<class ApiHolder>    
    IUnknown &BaseProcessProfiler<ApiHolder>::GetCOMProfilerInfoUnknown()
    {
        return Pimpl()->GetCOMProfilerInfoUnknown();
    }

    template<class ApiHolder>    
    void BaseProcessProfiler<ApiHolder>::SetCOMProfilerInfoUnknown(IUnknown *pComProfInfoUnk)
    {
        Pimpl()->SetCOMProfilerInfoUnknown(pComProfInfoUnk);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_HPP

