/* 
 * File: FunctionBodyProfilerFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONBODYPROFILERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONBODYPROFILERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSAPIAT_FUNCTIONBODYPROFILERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassApiAt/FunctionBodyProfilerApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONBODYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionBodyProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROCESSPROFILERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProcessProfilerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROCESSPROFILERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProcessProfilerPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

    namespace FunctionBodyProfilerFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::FunctionBodyProfilerApiAt;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfilerPimpl;
        using Urasandesu::Swathe::Profiling::FunctionBodyProfiler;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProcessProfilerLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProcessProfilerPimplLabel;
        using Urasandesu::Swathe::Profiling::FunctionProfiler;
        using Urasandesu::Swathe::Metadata::MethodGenerator;
        using Urasandesu::Swathe::Metadata::MethodBodyGenerator;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct FunctionBodyProfilerFacadeImpl
        {
            typedef FunctionBodyProfiler class_type;
            typedef FunctionBodyProfilerPimpl class_pimpl_type;
            typedef FunctionBodyProfilerPimpl function_body_profiler_pimpl_label_type;
            typedef typename FunctionBodyProfilerApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_type;
            typedef typename FunctionBodyProfilerApiAt<ApiHolder, ProcessProfilerPimplLabel>::type process_profiler_pimpl_label_type;

            typedef FunctionBodyProfilerPimpl function_body_profiler_pimpl_label_type;
            typedef FunctionBodyProfiler function_body_profiler_label_type;
            typedef FunctionProfiler function_profiler_label_type;
            typedef MethodGenerator method_generator_label_type;
            typedef MethodBodyGenerator method_body_generator_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_FUNCTION_BODY_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace FunctionBodyProfilerFacadeDetail {

    template<
        class ApiHolder
    >    
    struct FunctionBodyProfilerFacade : 
        FunctionBodyProfilerFacadeDetail::FunctionBodyProfilerFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_FUNCTION_BODY_PROFILER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Profiling::ClassFacade::FunctionBodyProfilerFacade<ApiHolder> facade;

#define SWATHE_DECLARE_FUNCTION_BODY_PROFILER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_FUNCTION_BODY_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::function_body_profiler_pimpl_label_type function_body_profiler_pimpl_label_type; \
    friend typename function_body_profiler_pimpl_label_type; \
    typedef typename facade::process_profiler_label_type process_profiler_label_type; \
    typedef typename facade::process_profiler_pimpl_label_type process_profiler_pimpl_label_type; \
    friend typename process_profiler_label_type; \
    friend typename process_profiler_pimpl_label_type; \
    typedef typename facade::function_body_profiler_pimpl_label_type function_body_profiler_pimpl_label_type; \
    typedef typename facade::function_body_profiler_label_type function_body_profiler_label_type; \
    typedef typename facade::function_profiler_label_type function_profiler_label_type; \
    typedef typename facade::method_generator_label_type method_generator_label_type; \
    typedef typename facade::method_body_generator_label_type method_body_generator_label_type; \
    friend typename function_body_profiler_pimpl_label_type; \
    friend typename function_body_profiler_label_type; \
    friend typename function_profiler_label_type; \
    friend typename method_generator_label_type; \
    friend typename method_body_generator_label_type; \

#define SWATHE_END_FUNCTION_BODY_PROFILER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONBODYPROFILERFACADE_H

