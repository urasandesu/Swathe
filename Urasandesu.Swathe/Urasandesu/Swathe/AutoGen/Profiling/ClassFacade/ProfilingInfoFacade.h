/* 
 * File: ProfilingInfoFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROFILINGINFOFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROFILINGINFOFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSAPIAT_PROFILINGINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassApiAt/ProfilingInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROFILINGINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/ProfilingInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROFILINGINFOFWD_H
#include <Urasandesu/Swathe/Profiling/ProfilingInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROCESSPROFILERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProcessProfilerPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATAINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROCESSPROFILERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProcessProfilerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPERSISTEDHANDLERLABEL_PROCESSPROFILERPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPersistedHandlerLabel/ProcessProfilerPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_ASSEMBLYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/AssemblyProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_ASSEMBLYPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/AssemblyProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_APPDOMAINPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/AppDomainProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_APPDOMAINPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/AppDomainProfilerPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

    namespace ProfilingInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::ProfilingInfoApiAt;
        using Urasandesu::Swathe::Profiling::ProfilingInfoPimpl;
        using Urasandesu::Swathe::Profiling::ProfilingInfo;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProcessProfilerPimplLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProcessProfilerLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPersistedHandlerLabel::ProcessProfilerPersistedHandlerLabel;
        using Urasandesu::Swathe::Profiling::FunctionProfiler;
        using Urasandesu::Swathe::Profiling::FunctionProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfiler;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::ClassProfiler;
        using Urasandesu::Swathe::Profiling::ClassProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::ModuleProfiler;
        using Urasandesu::Swathe::Profiling::ModuleProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::AssemblyProfiler;
        using Urasandesu::Swathe::Profiling::AssemblyProfilerPersistedHandler;
        using Urasandesu::Swathe::Profiling::AppDomainProfiler;
        using Urasandesu::Swathe::Profiling::AppDomainProfilerPersistedHandler;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ProfilingInfoFacadeImpl
        {
            typedef ProfilingInfo class_type;
            typedef ProfilingInfoPimpl class_pimpl_type;
            typedef ProfilingInfoPimpl profiling_info_pimpl_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerPimplLabel>::type process_profiler_pimpl_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, MetadataInfoLabel>::type metadata_info_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, RuntimeHostPimplLabel>::type runtime_host_pimpl_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerPersistedHandlerLabel>::type process_profiler_persisted_handler_label_type;

            typedef ProfilingInfoPimpl profiling_info_pimpl_label_type;
            typedef ProfilingInfo profiling_info_label_type;
            typedef FunctionProfiler function_profiler_label_type;
            typedef FunctionProfilerPersistedHandler function_profiler_persisted_handler_label_type;
            typedef FunctionBodyProfiler function_body_profiler_label_type;
            typedef FunctionBodyProfilerPersistedHandler function_body_profiler_persisted_handler_label_type;
            typedef ClassProfiler class_profiler_label_type;
            typedef ClassProfilerPersistedHandler class_profiler_persisted_handler_label_type;
            typedef ModuleProfiler module_profiler_label_type;
            typedef ModuleProfilerPersistedHandler module_profiler_persisted_handler_label_type;
            typedef AssemblyProfiler assembly_profiler_label_type;
            typedef AssemblyProfilerPersistedHandler assembly_profiler_persisted_handler_label_type;
            typedef AppDomainProfiler app_domain_profiler_label_type;
            typedef AppDomainProfilerPersistedHandler app_domain_profiler_persisted_handler_label_type;

            
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_dedadf85_type;
            
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerPersistedHandlerLabel>::type process_profiler_persisted_handler_label_type;
            
            typedef DisposingInfo<process_profiler_label_dedadf85_type, process_profiler_persisted_handler_label_type> process_profiler_label_disposing_info_type;
            
            typedef FunctionProfiler function_profiler_label_dedadf85_type;
            typedef FunctionBodyProfiler function_body_profiler_label_dedadf85_type;
            typedef ClassProfiler class_profiler_label_dedadf85_type;
            typedef ModuleProfiler module_profiler_label_dedadf85_type;
            typedef AssemblyProfiler assembly_profiler_label_dedadf85_type;
            typedef AppDomainProfiler app_domain_profiler_label_dedadf85_type;
            
            typedef FunctionProfilerPersistedHandler function_profiler_persisted_handler_label_type;
            typedef FunctionBodyProfilerPersistedHandler function_body_profiler_persisted_handler_label_type;
            typedef ClassProfilerPersistedHandler class_profiler_persisted_handler_label_type;
            typedef ModuleProfilerPersistedHandler module_profiler_persisted_handler_label_type;
            typedef AssemblyProfilerPersistedHandler assembly_profiler_persisted_handler_label_type;
            typedef AppDomainProfilerPersistedHandler app_domain_profiler_persisted_handler_label_type;
            
            typedef DisposingInfo<function_profiler_label_dedadf85_type, function_profiler_persisted_handler_label_type> function_profiler_label_disposing_info_type;
            typedef DisposingInfo<function_body_profiler_label_dedadf85_type, function_body_profiler_persisted_handler_label_type> function_body_profiler_label_disposing_info_type;
            typedef DisposingInfo<class_profiler_label_dedadf85_type, class_profiler_persisted_handler_label_type> class_profiler_label_disposing_info_type;
            typedef DisposingInfo<module_profiler_label_dedadf85_type, module_profiler_persisted_handler_label_type> module_profiler_label_disposing_info_type;
            typedef DisposingInfo<assembly_profiler_label_dedadf85_type, assembly_profiler_persisted_handler_label_type> assembly_profiler_label_disposing_info_type;
            typedef DisposingInfo<app_domain_profiler_label_dedadf85_type, app_domain_profiler_persisted_handler_label_type> app_domain_profiler_label_disposing_info_type;
            
            typedef DisposableHeapProvider<
                function_profiler_label_disposing_info_type,
                function_body_profiler_label_disposing_info_type,
                class_profiler_label_disposing_info_type,
                module_profiler_label_disposing_info_type,
                assembly_profiler_label_disposing_info_type,
                app_domain_profiler_label_disposing_info_type,
                process_profiler_label_disposing_info_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_PROFILING_INFO_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::process_profiler_persisted_handler_label_type process_profiler_persisted_handler_label_type; \
                friend typename process_profiler_persisted_handler_label_type; \
                typedef typename facade::process_profiler_label_disposing_info_type process_profiler_label_disposing_info_type; \
                friend typename process_profiler_label_disposing_info_type; \
                typedef typename facade::function_profiler_persisted_handler_label_type function_profiler_persisted_handler_label_type; \
                typedef typename facade::function_body_profiler_persisted_handler_label_type function_body_profiler_persisted_handler_label_type; \
                typedef typename facade::class_profiler_persisted_handler_label_type class_profiler_persisted_handler_label_type; \
                typedef typename facade::module_profiler_persisted_handler_label_type module_profiler_persisted_handler_label_type; \
                typedef typename facade::assembly_profiler_persisted_handler_label_type assembly_profiler_persisted_handler_label_type; \
                typedef typename facade::app_domain_profiler_persisted_handler_label_type app_domain_profiler_persisted_handler_label_type; \
                friend typename function_profiler_persisted_handler_label_type; \
                friend typename function_body_profiler_persisted_handler_label_type; \
                friend typename class_profiler_persisted_handler_label_type; \
                friend typename module_profiler_persisted_handler_label_type; \
                friend typename assembly_profiler_persisted_handler_label_type; \
                friend typename app_domain_profiler_persisted_handler_label_type; \
                typedef typename facade::function_profiler_label_disposing_info_type function_profiler_label_disposing_info_type; \
                typedef typename facade::function_body_profiler_label_disposing_info_type function_body_profiler_label_disposing_info_type; \
                typedef typename facade::class_profiler_label_disposing_info_type class_profiler_label_disposing_info_type; \
                typedef typename facade::module_profiler_label_disposing_info_type module_profiler_label_disposing_info_type; \
                typedef typename facade::assembly_profiler_label_disposing_info_type assembly_profiler_label_disposing_info_type; \
                typedef typename facade::app_domain_profiler_label_disposing_info_type app_domain_profiler_label_disposing_info_type; \
                friend typename function_profiler_label_disposing_info_type; \
                friend typename function_body_profiler_label_disposing_info_type; \
                friend typename class_profiler_label_disposing_info_type; \
                friend typename module_profiler_label_disposing_info_type; \
                friend typename assembly_profiler_label_disposing_info_type; \
                friend typename app_domain_profiler_label_disposing_info_type; \
            
        };
    
    }   // namespace ProfilingInfoFacadeDetail {

    template<
        class ApiHolder
    >    
    struct ProfilingInfoFacade : 
        ProfilingInfoFacadeDetail::ProfilingInfoFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PROFILING_INFO_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Profiling::ClassFacade::ProfilingInfoFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PROFILING_INFO_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PROFILING_INFO_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::profiling_info_pimpl_label_type profiling_info_pimpl_label_type; \
    friend typename profiling_info_pimpl_label_type; \
    typedef typename facade::process_profiler_pimpl_label_type process_profiler_pimpl_label_type; \
    typedef typename facade::metadata_info_label_type metadata_info_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::process_profiler_label_type process_profiler_label_type; \
    typedef typename facade::process_profiler_persisted_handler_label_type process_profiler_persisted_handler_label_type; \
    friend typename process_profiler_pimpl_label_type; \
    friend typename metadata_info_label_type; \
    friend typename runtime_host_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename process_profiler_label_type; \
    friend typename process_profiler_persisted_handler_label_type; \
    typedef typename facade::profiling_info_pimpl_label_type profiling_info_pimpl_label_type; \
    typedef typename facade::profiling_info_label_type profiling_info_label_type; \
    typedef typename facade::function_profiler_label_type function_profiler_label_type; \
    typedef typename facade::function_profiler_persisted_handler_label_type function_profiler_persisted_handler_label_type; \
    typedef typename facade::function_body_profiler_label_type function_body_profiler_label_type; \
    typedef typename facade::function_body_profiler_persisted_handler_label_type function_body_profiler_persisted_handler_label_type; \
    typedef typename facade::class_profiler_label_type class_profiler_label_type; \
    typedef typename facade::class_profiler_persisted_handler_label_type class_profiler_persisted_handler_label_type; \
    typedef typename facade::module_profiler_label_type module_profiler_label_type; \
    typedef typename facade::module_profiler_persisted_handler_label_type module_profiler_persisted_handler_label_type; \
    typedef typename facade::assembly_profiler_label_type assembly_profiler_label_type; \
    typedef typename facade::assembly_profiler_persisted_handler_label_type assembly_profiler_persisted_handler_label_type; \
    typedef typename facade::app_domain_profiler_label_type app_domain_profiler_label_type; \
    typedef typename facade::app_domain_profiler_persisted_handler_label_type app_domain_profiler_persisted_handler_label_type; \
    friend typename profiling_info_pimpl_label_type; \
    friend typename profiling_info_label_type; \
    friend typename function_profiler_label_type; \
    friend typename function_profiler_persisted_handler_label_type; \
    friend typename function_body_profiler_label_type; \
    friend typename function_body_profiler_persisted_handler_label_type; \
    friend typename class_profiler_label_type; \
    friend typename class_profiler_persisted_handler_label_type; \
    friend typename module_profiler_label_type; \
    friend typename module_profiler_persisted_handler_label_type; \
    friend typename assembly_profiler_label_type; \
    friend typename assembly_profiler_persisted_handler_label_type; \
    friend typename app_domain_profiler_label_type; \
    friend typename app_domain_profiler_persisted_handler_label_type; \

#define SWATHE_END_PROFILING_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROFILINGINFOFACADE_H

