/* 
 * File: FunctionProfilerFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONPROFILERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONPROFILERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSAPIAT_FUNCTIONPROFILERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassApiAt/FunctionProfilerApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROCESSPROFILERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProcessProfilerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROCESSPROFILERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProcessProfilerPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_APPDOMAINPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/AppDomainProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_ASSEMBLYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/AssemblyProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

    namespace FunctionProfilerFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::FunctionProfilerApiAt;
        using Urasandesu::Swathe::Profiling::FunctionProfilerPimpl;
        using Urasandesu::Swathe::Profiling::FunctionProfiler;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProcessProfilerLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProcessProfilerPimplLabel;
        using Urasandesu::Swathe::Profiling::AppDomainProfiler;
        using Urasandesu::Swathe::Profiling::AssemblyProfiler;
        using Urasandesu::Swathe::Profiling::ModuleProfiler;
        using Urasandesu::Swathe::Profiling::ClassProfiler;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::Metadata::MethodGenerator;
        using Urasandesu::Swathe::Metadata::MethodBodyGenerator;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfiler;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct FunctionProfilerFacadeImpl
        {
            typedef FunctionProfiler class_type;
            typedef FunctionProfilerPimpl class_pimpl_type;
            typedef FunctionProfilerPimpl function_profiler_pimpl_label_type;
            typedef typename FunctionProfilerApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_type;
            typedef typename FunctionProfilerApiAt<ApiHolder, ProcessProfilerPimplLabel>::type process_profiler_pimpl_label_type;
            typedef typename FunctionProfilerApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;

            typedef FunctionProfilerPimpl function_profiler_pimpl_label_type;
            typedef FunctionProfiler function_profiler_label_type;
            typedef AppDomainProfiler app_domain_profiler_label_type;
            typedef AssemblyProfiler assembly_profiler_label_type;
            typedef ModuleProfiler module_profiler_label_type;
            typedef ClassProfiler class_profiler_label_type;
            typedef MethodGenerator method_generator_label_type;
            typedef MethodBodyGenerator method_body_generator_label_type;
            typedef FunctionBodyProfiler function_body_profiler_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_FUNCTION_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace FunctionProfilerFacadeDetail {

    template<
        class ApiHolder
    >    
    struct FunctionProfilerFacade : 
        FunctionProfilerFacadeDetail::FunctionProfilerFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_FUNCTION_PROFILER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Profiling::ClassFacade::FunctionProfilerFacade<ApiHolder> facade;

#define SWATHE_DECLARE_FUNCTION_PROFILER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_FUNCTION_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::function_profiler_pimpl_label_type function_profiler_pimpl_label_type; \
    friend typename function_profiler_pimpl_label_type; \
    typedef typename facade::process_profiler_label_type process_profiler_label_type; \
    typedef typename facade::process_profiler_pimpl_label_type process_profiler_pimpl_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    friend typename process_profiler_label_type; \
    friend typename process_profiler_pimpl_label_type; \
    friend typename assembly_generator_label_type; \
    typedef typename facade::function_profiler_pimpl_label_type function_profiler_pimpl_label_type; \
    typedef typename facade::function_profiler_label_type function_profiler_label_type; \
    typedef typename facade::app_domain_profiler_label_type app_domain_profiler_label_type; \
    typedef typename facade::assembly_profiler_label_type assembly_profiler_label_type; \
    typedef typename facade::module_profiler_label_type module_profiler_label_type; \
    typedef typename facade::class_profiler_label_type class_profiler_label_type; \
    typedef typename facade::method_generator_label_type method_generator_label_type; \
    typedef typename facade::method_body_generator_label_type method_body_generator_label_type; \
    typedef typename facade::function_body_profiler_label_type function_body_profiler_label_type; \
    friend typename function_profiler_pimpl_label_type; \
    friend typename function_profiler_label_type; \
    friend typename app_domain_profiler_label_type; \
    friend typename assembly_profiler_label_type; \
    friend typename module_profiler_label_type; \
    friend typename class_profiler_label_type; \
    friend typename method_generator_label_type; \
    friend typename method_body_generator_label_type; \
    friend typename function_body_profiler_label_type; \

#define SWATHE_END_FUNCTION_PROFILER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONPROFILERFACADE_H

