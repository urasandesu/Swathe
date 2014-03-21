/* 
 * File: BaseProfilingInfoPimpl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_H
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_PROFILINGINFOPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplFacade/ProfilingInfoPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseProfilingInfoPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseProfilingInfoPimpl
    {
    public:
        SWATHE_BEGIN_PROFILING_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROFILING_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROFILING_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseProfilingInfoPimpl(profiling_info_label_type *pClass);
        ~BaseProfilingInfoPimpl();
        
        void Initialize(runtime_host_label_type *pRuntime);
        TempPtr<process_profiler_label_type> AttachToCurrentProcess(IUnknown *pComProfInfoUnk);
        process_profiler_label_type *GetCurrentProcessProfiler();
        void DetachFromCurrentProcess();
        runtime_host_label_type const *GetRuntime() const;
                
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        TempPtr<process_profiler_label_type> NewProcessProfiler(IUnknown *pComProfInfoUnk);
        TempPtr<process_profiler_label_type> NewProcessProfilerCore();
        void RegisterProcessProfiler(TempPtr<process_profiler_label_type> &pProcProf);

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
#ifdef _M_IX86
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 32;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 64;
#endif
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable profiling_info_label_type *m_pClass;
        runtime_host_label_type const *m_pRuntime;
        SIZE_T m_procProfIndex;
        TempPtr<process_profiler_label_type> m_pCurrentProcProf;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_H

