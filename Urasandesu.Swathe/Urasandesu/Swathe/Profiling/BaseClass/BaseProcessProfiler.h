/* 
 * File: BaseProcessProfiler.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROCESSPROFILERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassFacade/ProcessProfilerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProcessProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROFILEREVENTS_H
#include <Urasandesu/Swathe/Profiling/ProfilerEvents.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    using boost::aligned_storage;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseProcessProfiler
    {
    public:
        SWATHE_BEGIN_PROCESS_PROFILER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROCESS_PROFILER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROCESS_PROFILER_FACADE_TYPEDEF_ALIAS
        
        BaseProcessProfiler();
        ~BaseProcessProfiler();

        void SetEventMask(ProfilerEvents const &events);
        TempPtr<app_domain_profiler_label_type> AttachToAppDomain(AppDomainID appDomainId);
        void DetachFromAppDomain(AppDomainID appDomainId);
        TempPtr<assembly_profiler_label_type> AttachToAssembly(AssemblyID assemblyId);
        TempPtr<module_profiler_label_type> AttachToModule(ModuleID moduleId);
        void DetachFromModule(ModuleID moduleId);
        TempPtr<class_profiler_label_type> AttachToClass(ClassID classId);
        TempPtr<function_profiler_label_type> AttachToFunction(FunctionID functionId);
        void DetachFromFunction(FunctionID functionId);
        TempPtr<function_body_profiler_label_type> AttachToFunctionBody(FunctionID functionId, FunctionBodyID functionBodyId);
    
    private:
        process_profiler_pimpl_label_type *Pimpl();
        process_profiler_pimpl_label_type const *Pimpl() const;
        void Initialize(profiling_info_label_type *pProfInfo);
        void RegisterAppDomainProfiler(TempPtr<app_domain_profiler_label_type> &pDomainProf);
        void RegisterAssemblyProfiler(TempPtr<assembly_profiler_label_type> &pAsmProf);
        void RegisterModuleProfiler(TempPtr<module_profiler_label_type> &pModProf);
        void RegisterClassProfiler(TempPtr<class_profiler_label_type> &pClsProf);
        void RegisterFunctionProfiler(TempPtr<function_profiler_label_type> &pFuncProf);
        void RegisterFunctionBodyProfiler(TempPtr<function_body_profiler_label_type> &pBodyProf);
        ICorProfilerInfo2 &GetCOMProfilerInfo();
        IUnknown &GetCOMProfilerInfoUnknown();
        void SetCOMProfilerInfoUnknown(IUnknown *pComProfInfoUnk);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 352;
#endif
        typedef typename aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H

