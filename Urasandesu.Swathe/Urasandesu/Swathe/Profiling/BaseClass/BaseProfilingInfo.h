/* 
 * File: BaseProfilingInfo.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_H
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROFILINGINFOFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassFacade/ProfilingInfoFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFOFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProfilingInfoFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseProfilingInfo
    {
    public:
        SWATHE_BEGIN_PROFILING_INFO_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROFILING_INFO_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROFILING_INFO_FACADE_TYPEDEF_ALIAS
        
        BaseProfilingInfo();
        ~BaseProfilingInfo();

        void Initialize(runtime_host_label_type *pRuntime);
        TempPtr<process_profiler_label_type> AttachToCurrentProcess(IUnknown *pComProfInfoUnk);
        process_profiler_label_type *GetCurrentProcessProfiler();
        void DetachFromCurrentProcess();
        runtime_host_label_type const *GetRuntime() const;
    
    private:
        profiling_info_pimpl_label_type *Pimpl();
        profiling_info_pimpl_label_type const *Pimpl() const;
        void RegisterProcessProfiler(TempPtr<process_profiler_label_type> &pProcProf);

        TempPtr<app_domain_profiler_label_type> NewAppDomainProfilerCore(process_profiler_label_type *pProcProf);
        void RegisterAppDomainProfilerCore(TempPtr<app_domain_profiler_label_type> &pDomainProf);
        void DetachFromAppDomainCore(app_domain_profiler_label_type *pDomainProf);

        TempPtr<assembly_profiler_label_type> NewAssemblyProfilerCore(process_profiler_label_type *pProcProf);
        void RegisterAssemblyProfilerCore(TempPtr<assembly_profiler_label_type> &pAsmProf);
        void DetachFromAssemblyCore(assembly_profiler_label_type *pAsmProf);
        
        TempPtr<module_profiler_label_type> NewModuleProfilerCore(process_profiler_label_type *pProcProf);
        void RegisterModuleProfilerCore(TempPtr<module_profiler_label_type> &pModProf);
        void DetachFromModuleCore(module_profiler_label_type *pModProf);
        
        TempPtr<class_profiler_label_type> NewClassProfilerCore(process_profiler_label_type *pProcProf);
        void RegisterClassProfilerCore(TempPtr<class_profiler_label_type> &pClsProf);
        void DetachFromClassCore(class_profiler_label_type *pClsProf);
        
        TempPtr<function_profiler_label_type> NewFunctionProfilerCore(process_profiler_label_type *pProcProf);
        void RegisterFunctionProfilerCore(TempPtr<function_profiler_label_type> &pFuncProf);
        void DetachFromFunctionCore(function_profiler_label_type *pFuncProf);
        
        TempPtr<function_body_profiler_label_type> NewFunctionBodyProfilerCore(process_profiler_label_type *pProcProf);
        void RegisterFunctionBodyProfilerCore(TempPtr<function_body_profiler_label_type> &pBodyProf);
        void DetachFromFunctionBodyCore(function_body_profiler_label_type *pBodyProf);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 264;
#else
        static INT const PIMPL_TYPE_SIZE = 512;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_H

