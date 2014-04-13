/* 
 * File: BaseProcessProfilerPimpl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_H
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_PROCESSPROFILERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplFacade/ProcessProfilerPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseProcessProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROFILEREVENTS_H
#include <Urasandesu/Swathe/Profiling/ProfilerEvents.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    using boost::unordered_map;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    
    template<
        class ApiHolder
    >    
    class BaseProcessProfilerPimpl
    {
    public:
        SWATHE_BEGIN_PROCESS_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROCESS_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROCESS_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseProcessProfilerPimpl(process_profiler_label_type *pClass);
        ~BaseProcessProfilerPimpl();

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
        void Initialize(profiling_info_label_type *pProfInfo);
        TempPtr<app_domain_profiler_label_type> NewAppDomainProfiler(AppDomainID appDomainId);
        void RegisterAppDomainProfiler(TempPtr<app_domain_profiler_label_type> &pDomainProf);
        TempPtr<assembly_profiler_label_type> NewAssemblyProfiler(AssemblyID assemblyId);
        void RegisterAssemblyProfiler(TempPtr<assembly_profiler_label_type> &pAsmProf);
        TempPtr<module_profiler_label_type> NewModuleProfiler(ModuleID moduleId);
        void RegisterModuleProfiler(TempPtr<module_profiler_label_type> &pModProf);
        TempPtr<class_profiler_label_type> NewClassProfiler(ClassID classId);
        void RegisterClassProfiler(TempPtr<class_profiler_label_type> &pClsProf);
        TempPtr<function_profiler_label_type> NewFunctionProfiler(FunctionID functionId);
        void RegisterFunctionProfiler(TempPtr<function_profiler_label_type> &pFuncProf);
        TempPtr<function_body_profiler_label_type> NewFunctionBodyProfiler(FunctionID functionId, FunctionBodyID functionBodyId);
        void RegisterFunctionBodyProfiler(TempPtr<function_body_profiler_label_type> &pBodyProf);
        ICorProfilerInfo2 &GetCOMProfilerInfo();
        IUnknown &GetCOMProfilerInfoUnknown();
        void SetCOMProfilerInfoUnknown(IUnknown *pComProfInfoUnk);

        mutable process_profiler_label_type *m_pClass;
        profiling_info_label_type *m_pProfInfo;
        unordered_map<AppDomainID, app_domain_profiler_label_type *> m_appDomainIdToObjs;
        unordered_map<AssemblyID, assembly_profiler_label_type *> m_assemblyIdToObjs;
        unordered_map<ModuleID, module_profiler_label_type *> m_moduleIdToObjs;
        unordered_map<ClassID, class_profiler_label_type *> m_classIdToObjs;
        unordered_map<FunctionID, function_profiler_label_type *> m_functionIdToObjs;
        unordered_map<FunctionBodyID, function_body_profiler_label_type *> m_functionBodyIdToObjs;
        ATL::CComPtr<ICorProfilerInfo2> m_pComProfInfo;
        ATL::CComPtr<IUnknown> m_pComProfInfoUnk;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_H

