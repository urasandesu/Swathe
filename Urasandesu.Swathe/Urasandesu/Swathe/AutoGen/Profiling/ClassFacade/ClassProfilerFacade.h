/* 
 * File: ClassProfilerFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_CLASSPROFILERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_CLASSPROFILERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSAPIAT_CLASSPROFILERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassApiAt/ClassProfilerApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_CLASSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ClassProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROCESSPROFILERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProcessProfilerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROCESSPROFILERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProcessProfilerPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_MODULEPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ModuleProfilerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

    namespace ClassProfilerFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::ClassProfilerApiAt;
        using Urasandesu::Swathe::Profiling::ClassProfilerPimpl;
        using Urasandesu::Swathe::Profiling::ClassProfiler;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProcessProfilerLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProcessProfilerPimplLabel;
        using Urasandesu::Swathe::Profiling::ModuleProfiler;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ClassProfilerFacadeImpl
        {
            typedef ClassProfiler class_type;
            typedef ClassProfilerPimpl class_pimpl_type;
            typedef ClassProfilerPimpl class_profiler_pimpl_label_type;
            typedef typename ClassProfilerApiAt<ApiHolder, ProcessProfilerLabel>::type process_profiler_label_type;
            typedef typename ClassProfilerApiAt<ApiHolder, ProcessProfilerPimplLabel>::type process_profiler_pimpl_label_type;

            typedef ClassProfilerPimpl class_profiler_pimpl_label_type;
            typedef ClassProfiler class_profiler_label_type;
            typedef ModuleProfiler module_profiler_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_CLASS_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace ClassProfilerFacadeDetail {

    template<
        class ApiHolder
    >    
    struct ClassProfilerFacade : 
        ClassProfilerFacadeDetail::ClassProfilerFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_CLASS_PROFILER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Profiling::ClassFacade::ClassProfilerFacade<ApiHolder> facade;

#define SWATHE_DECLARE_CLASS_PROFILER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_CLASS_PROFILER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::class_profiler_pimpl_label_type class_profiler_pimpl_label_type; \
    friend typename class_profiler_pimpl_label_type; \
    typedef typename facade::process_profiler_label_type process_profiler_label_type; \
    typedef typename facade::process_profiler_pimpl_label_type process_profiler_pimpl_label_type; \
    friend typename process_profiler_label_type; \
    friend typename process_profiler_pimpl_label_type; \
    typedef typename facade::class_profiler_pimpl_label_type class_profiler_pimpl_label_type; \
    typedef typename facade::class_profiler_label_type class_profiler_label_type; \
    typedef typename facade::module_profiler_label_type module_profiler_label_type; \
    friend typename class_profiler_pimpl_label_type; \
    friend typename class_profiler_label_type; \
    friend typename module_profiler_label_type; \

#define SWATHE_END_CLASS_PROFILER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_CLASSPROFILERFACADE_H

