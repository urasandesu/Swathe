/* 
 * File: ProcessProfilerFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROCESSPROFILERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROCESSPROFILERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSAPIAT_PROCESSPROFILERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassApiAt/ProcessProfilerApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROCESSPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/ProcessProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROCESSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ProcessProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_APPDOMAINPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/AppDomainProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_APPDOMAINPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/AppDomainProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_APPDOMAINPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/AppDomainProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_ASSEMBLYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/AssemblyProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_ASSEMBLYPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/AssemblyProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_ASSEMBLYPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/AssemblyProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROFILINGINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProfilingInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROFILINGINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProfilingInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

    namespace ProcessProfilerFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::ProcessProfilerApiAt;
        using Urasandesu::Swathe::Profiling::ProcessProfilerPimpl;
        using Urasandesu::Swathe::Profiling::ProcessProfiler;
        using Urasandesu::Swathe::Profiling::AppDomainProfiler;
        using Urasandesu::Swathe::Profiling::AppDomainProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::AppDomainProfilerPimpl;
        using Urasandesu::Swathe::Profiling::AssemblyProfiler;
        using Urasandesu::Swathe::Profiling::AssemblyProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::AssemblyProfilerPimpl;
        using Urasandesu::Swathe::Profiling::ModuleProfiler;
        using Urasandesu::Swathe::Profiling::ModuleProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::ModuleProfilerPimpl;
        using Urasandesu::Swathe::Profiling::ClassProfiler;
        using Urasandesu::Swathe::Profiling::ClassProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::ClassProfilerPimpl;
        using Urasandesu::Swathe::Profiling::FunctionProfiler;
        using Urasandesu::Swathe::Profiling::FunctionProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::FunctionProfilerPimpl;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfiler;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfilerPimpl;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProfilingInfoLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProfilingInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ProcessProfilerFacadeImpl
        {
            typedef ProcessProfiler class_type;
            typedef ProcessProfilerPimpl class_pimpl_type;
            typedef ProcessProfilerPimpl process_profiler_pimpl_label_type;
            typedef typename ProcessProfilerApiAt<ApiHolder, ProfilingInfoLabel>::type profiling_info_label_type;
            typedef typename ProcessProfilerApiAt<ApiHolder, ProfilingInfoPimplLabel>::type profiling_info_pimpl_label_type;
            typedef typename ProcessProfilerApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;

            typedef ProcessProfilerPimpl process_profiler_pimpl_label_type;
            typedef ProcessProfiler process_profiler_label_type;
            typedef AppDomainProfiler app_domain_profiler_label_type;
            typedef AppDomainProfilerPersistedHandler app_domain_profiler_persisted_handler_label_type;
            typedef AppDomainProfilerPimpl app_domain_profiler_pimpl_label_type;
            typedef AssemblyProfiler assembly_profiler_label_type;
            typedef AssemblyProfilerPersistedHandler assembly_profiler_persisted_handler_label_type;
            typedef AssemblyProfilerPimpl assembly_profiler_pimpl_label_type;
            typedef ModuleProfiler module_profiler_label_type;
            typedef ModuleProfilerPersistedHandler module_profiler_persisted_handler_label_type;
            typedef ModuleProfilerPimpl module_profiler_pimpl_label_type;
            typedef ClassProfiler class_profiler_label_type;
            typedef ClassProfilerPersistedHandler class_profiler_persisted_handler_label_type;
            typedef ClassProfilerPimpl class_profiler_pimpl_label_type;
            typedef FunctionProfiler function_profiler_label_type;
            typedef FunctionProfilerPersistedHandler function_profiler_persisted_handler_label_type;
            typedef FunctionProfilerPimpl function_profiler_pimpl_label_type;
            typedef FunctionBodyProfiler function_body_profiler_label_type;
            typedef FunctionBodyProfilerPersistedHandler function_body_profiler_persisted_handler_label_type;
            typedef FunctionBodyProfilerPimpl function_body_profiler_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_PROCESS_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace ProcessProfilerFacadeDetail {

    template<
        class ApiHolder
    >    
    struct ProcessProfilerFacade : 
        ProcessProfilerFacadeDetail::ProcessProfilerFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PROCESS_PROFILER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Profiling::ClassFacade::ProcessProfilerFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PROCESS_PROFILER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PROCESS_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::process_profiler_pimpl_label_type process_profiler_pimpl_label_type; \
    friend typename process_profiler_pimpl_label_type; \
    typedef typename facade::profiling_info_label_type profiling_info_label_type; \
    typedef typename facade::profiling_info_pimpl_label_type profiling_info_pimpl_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    friend typename profiling_info_label_type; \
    friend typename profiling_info_pimpl_label_type; \
    friend typename runtime_host_label_type; \
    typedef typename facade::process_profiler_pimpl_label_type process_profiler_pimpl_label_type; \
    typedef typename facade::process_profiler_label_type process_profiler_label_type; \
    typedef typename facade::app_domain_profiler_label_type app_domain_profiler_label_type; \
    typedef typename facade::app_domain_profiler_persisted_handler_label_type app_domain_profiler_persisted_handler_label_type; \
    typedef typename facade::app_domain_profiler_pimpl_label_type app_domain_profiler_pimpl_label_type; \
    typedef typename facade::assembly_profiler_label_type assembly_profiler_label_type; \
    typedef typename facade::assembly_profiler_persisted_handler_label_type assembly_profiler_persisted_handler_label_type; \
    typedef typename facade::assembly_profiler_pimpl_label_type assembly_profiler_pimpl_label_type; \
    typedef typename facade::module_profiler_label_type module_profiler_label_type; \
    typedef typename facade::module_profiler_persisted_handler_label_type module_profiler_persisted_handler_label_type; \
    typedef typename facade::module_profiler_pimpl_label_type module_profiler_pimpl_label_type; \
    typedef typename facade::class_profiler_label_type class_profiler_label_type; \
    typedef typename facade::class_profiler_persisted_handler_label_type class_profiler_persisted_handler_label_type; \
    typedef typename facade::class_profiler_pimpl_label_type class_profiler_pimpl_label_type; \
    typedef typename facade::function_profiler_label_type function_profiler_label_type; \
    typedef typename facade::function_profiler_persisted_handler_label_type function_profiler_persisted_handler_label_type; \
    typedef typename facade::function_profiler_pimpl_label_type function_profiler_pimpl_label_type; \
    typedef typename facade::function_body_profiler_label_type function_body_profiler_label_type; \
    typedef typename facade::function_body_profiler_persisted_handler_label_type function_body_profiler_persisted_handler_label_type; \
    typedef typename facade::function_body_profiler_pimpl_label_type function_body_profiler_pimpl_label_type; \
    friend typename process_profiler_pimpl_label_type; \
    friend typename process_profiler_label_type; \
    friend typename app_domain_profiler_label_type; \
    friend typename app_domain_profiler_persisted_handler_label_type; \
    friend typename app_domain_profiler_pimpl_label_type; \
    friend typename assembly_profiler_label_type; \
    friend typename assembly_profiler_persisted_handler_label_type; \
    friend typename assembly_profiler_pimpl_label_type; \
    friend typename module_profiler_label_type; \
    friend typename module_profiler_persisted_handler_label_type; \
    friend typename module_profiler_pimpl_label_type; \
    friend typename class_profiler_label_type; \
    friend typename class_profiler_persisted_handler_label_type; \
    friend typename class_profiler_pimpl_label_type; \
    friend typename function_profiler_label_type; \
    friend typename function_profiler_persisted_handler_label_type; \
    friend typename function_profiler_pimpl_label_type; \
    friend typename function_body_profiler_label_type; \
    friend typename function_body_profiler_persisted_handler_label_type; \
    friend typename function_body_profiler_pimpl_label_type; \

#define SWATHE_END_PROCESS_PROFILER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROCESSPROFILERFACADE_H

