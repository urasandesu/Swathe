/* 
 * File: BaseFunctionBodyProfilerPimpl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPL_H
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_FUNCTIONBODYPROFILERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplFacade/FunctionBodyProfilerPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseFunctionBodyProfilerPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseFunctionBodyProfilerPimpl
    {
    public:
        SWATHE_BEGIN_FUNCTION_BODY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FUNCTION_BODY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FUNCTION_BODY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseFunctionBodyProfilerPimpl(function_body_profiler_label_type *pClass);

        UINT_PTR GetID() const;
        method_body_generator_label_type *GetMethodBodyGenerator();
        method_body_generator_label_type const *GetMethodBodyGenerator() const;
        TempPtr<function_profiler_label_type> AttachToFunction();
        
    private:
        void Initialize(process_profiler_label_type *pProcProf);
        void SetID(UINT_PTR id);
        void SetFunctionID(FunctionID functionId);

        mutable function_body_profiler_label_type *m_pClass;
        process_profiler_label_type *m_pProcProf;
        UINT_PTR m_id;
        FunctionID m_functionId;
        method_body_generator_label_type *m_pBodyGen;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPL_H

