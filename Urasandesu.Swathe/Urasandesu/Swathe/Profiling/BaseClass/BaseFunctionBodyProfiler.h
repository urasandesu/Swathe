/* 
 * File: BaseFunctionBodyProfiler.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_H
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_FUNCTIONBODYPROFILERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassFacade/FunctionBodyProfilerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseFunctionBodyProfilerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseFunctionBodyProfiler
    {
    public:
        SWATHE_BEGIN_FUNCTION_BODY_PROFILER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FUNCTION_BODY_PROFILER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FUNCTION_BODY_PROFILER_FACADE_TYPEDEF_ALIAS
        
        BaseFunctionBodyProfiler();
        ~BaseFunctionBodyProfiler();

        void Initialize(process_profiler_label_type *pProcProf);
        UINT_PTR GetID() const;
        method_body_generator_label_type *GetMethodBodyGenerator();
        method_body_generator_label_type const *GetMethodBodyGenerator() const;
        TempPtr<function_profiler_label_type> AttachToFunction();
    
    private:
        function_body_profiler_pimpl_label_type *Pimpl();
        function_body_profiler_pimpl_label_type const *Pimpl() const;
        void SetID(UINT_PTR id);
        void SetFunctionID(FunctionID functionId);
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 20;
#else
        static INT const PIMPL_TYPE_SIZE = 48;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_H

