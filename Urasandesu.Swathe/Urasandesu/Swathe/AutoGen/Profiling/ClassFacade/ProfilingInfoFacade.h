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

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

    namespace ProfilingInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::ProfilingInfoApiAt;
        using Urasandesu::Swathe::Profiling::ProfilingInfoPimpl;
        using Urasandesu::Swathe::Profiling::ProfilingInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProcessProfilerLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPersistedHandlerLabel::ProcessProfilerPersistedHandlerLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ProfilingInfoFacadeImpl
        {
            typedef ProfilingInfo class_type;
            typedef ProfilingInfoPimpl class_pimpl_type;
            typedef ProfilingInfoPimpl profiling_info_pimpl_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, RuntimeHostPimplLabel>::type runtime_host_pimpl_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_type;
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerPersistedHandlerLabel>::type process_profiler_persisted_handler_label_type;

            typedef ProfilingInfoPimpl profiling_info_pimpl_label_type;
            typedef ProfilingInfo profiling_info_label_type;

            
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_dedadf85_type;
            
            typedef typename ProfilingInfoApiAt<ApiHolder, ProcessProfilerPersistedHandlerLabel>::type process_profiler_persisted_handler_label_type;
            
            typedef DisposingInfo<process_profiler_label_dedadf85_type, process_profiler_persisted_handler_label_type> process_profiler_label_disposing_info_type;
            
            
            
            
            
            
            
            typedef DisposableHeapProvider<
                process_profiler_label_disposing_info_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_PROFILING_INFO_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::process_profiler_persisted_handler_label_type process_profiler_persisted_handler_label_type; \
                friend typename process_profiler_persisted_handler_label_type; \
                typedef typename facade::process_profiler_label_disposing_info_type process_profiler_label_disposing_info_type; \
                friend typename process_profiler_label_disposing_info_type; \
            
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
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::process_profiler_label_type process_profiler_label_type; \
    typedef typename facade::process_profiler_persisted_handler_label_type process_profiler_persisted_handler_label_type; \
    friend typename runtime_host_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename process_profiler_label_type; \
    friend typename process_profiler_persisted_handler_label_type; \
    typedef typename facade::profiling_info_pimpl_label_type profiling_info_pimpl_label_type; \
    typedef typename facade::profiling_info_label_type profiling_info_label_type; \
    friend typename profiling_info_pimpl_label_type; \
    friend typename profiling_info_label_type; \

#define SWATHE_END_PROFILING_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_PROFILINGINFOFACADE_H

