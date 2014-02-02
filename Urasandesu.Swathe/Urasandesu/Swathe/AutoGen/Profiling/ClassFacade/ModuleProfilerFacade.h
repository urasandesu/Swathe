/* 
 * File: ModuleProfilerFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_MODULEPROFILERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_MODULEPROFILERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSAPIAT_MODULEPROFILERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassApiAt/ModuleProfilerApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROCESSPROFILERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProcessProfilerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROCESSPROFILERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProcessProfilerPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_ASSEMBLYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/AssemblyProfilerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

    namespace ModuleProfilerFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::ModuleProfilerApiAt;
        using Urasandesu::Swathe::Profiling::ModuleProfilerPimpl;
        using Urasandesu::Swathe::Profiling::ModuleProfiler;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProcessProfilerLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProcessProfilerPimplLabel;
        using Urasandesu::Swathe::Profiling::AssemblyProfiler;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ModuleProfilerFacadeImpl
        {
            typedef ModuleProfiler class_type;
            typedef ModuleProfilerPimpl class_pimpl_type;
            typedef ModuleProfilerPimpl module_profiler_pimpl_label_type;
            typedef typename ModuleProfilerApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_type;
            typedef typename ModuleProfilerApiAt<ApiHolder, ProcessProfilerPimplLabel>::type process_profiler_pimpl_label_type;

            typedef ModuleProfilerPimpl module_profiler_pimpl_label_type;
            typedef ModuleProfiler module_profiler_label_type;
            typedef AssemblyProfiler assembly_profiler_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_MODULE_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace ModuleProfilerFacadeDetail {

    template<
        class ApiHolder
    >    
    struct ModuleProfilerFacade : 
        ModuleProfilerFacadeDetail::ModuleProfilerFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_MODULE_PROFILER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Profiling::ClassFacade::ModuleProfilerFacade<ApiHolder> facade;

#define SWATHE_DECLARE_MODULE_PROFILER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_MODULE_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::module_profiler_pimpl_label_type module_profiler_pimpl_label_type; \
    friend typename module_profiler_pimpl_label_type; \
    typedef typename facade::process_profiler_label_type process_profiler_label_type; \
    typedef typename facade::process_profiler_pimpl_label_type process_profiler_pimpl_label_type; \
    friend typename process_profiler_label_type; \
    friend typename process_profiler_pimpl_label_type; \
    typedef typename facade::module_profiler_pimpl_label_type module_profiler_pimpl_label_type; \
    typedef typename facade::module_profiler_label_type module_profiler_label_type; \
    typedef typename facade::assembly_profiler_label_type assembly_profiler_label_type; \
    friend typename module_profiler_pimpl_label_type; \
    friend typename module_profiler_label_type; \
    friend typename assembly_profiler_label_type; \

#define SWATHE_END_MODULE_PROFILER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_MODULEPROFILERFACADE_H

