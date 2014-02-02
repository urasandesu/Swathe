/* 
 * File: FunctionBodyProfilerPimplFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_FUNCTIONBODYPROFILERPIMPLFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_FUNCTIONBODYPROFILERPIMPLFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSAPIAT_FUNCTIONBODYPROFILERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassApiAt/FunctionBodyProfilerApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONBODYPROFILERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassFacade/FunctionBodyProfilerFacade.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassPimplFacade { 

    namespace FunctionBodyProfilerPimplFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassApiAt::FunctionBodyProfilerApiAt;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassFacade::FunctionBodyProfilerFacade;

        template<
            class ApiHolder
        >    
        struct FunctionBodyProfilerPimplFacadeImpl : 
            FunctionBodyProfilerFacade<ApiHolder>
        {

        };
    
    }   // namespace FunctionBodyProfilerPimplFacadeDetail {

    template<
        class ApiHolder
    >    
    struct FunctionBodyProfilerPimplFacade : 
        FunctionBodyProfilerPimplFacadeDetail::FunctionBodyProfilerPimplFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_FUNCTION_BODY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Profiling::ClassPimplFacade::FunctionBodyProfilerPimplFacade<ApiHolder> facade;

#define SWATHE_DECLARE_FUNCTION_BODY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_FUNCTION_BODY_PROFILER_FACADE_TYPEDEF_ALIAS \



#define SWATHE_END_FUNCTION_BODY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace ClassPimplFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_FUNCTIONBODYPROFILERPIMPLFACADE_H

