/* 
 * File: BaseFunctionProfilerPimpl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_H
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_FUNCTIONPROFILERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplFacade/FunctionProfilerPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseFunctionProfilerPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    
    template<
        class ApiHolder
    >    
    class BaseFunctionProfilerPimpl
    {
    public:
        SWATHE_BEGIN_FUNCTION_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FUNCTION_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FUNCTION_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseFunctionProfilerPimpl(function_profiler_label_type *pClass);

        void Initialize(process_profiler_label_type *pProcProf);
        UINT_PTR GetID() const;
        TempPtr<class_profiler_label_type> AttachToClass();
        TempPtr<module_profiler_label_type> AttachToModule();
        method_generator_label_type *GetMethodGenerator();
        TempPtr<function_body_profiler_label_type> AttachToFunctionBody();
        TempPtr<function_body_profiler_label_type> NewFunctionBody();
        void SetFunctionBody(TempPtr<function_body_profiler_label_type const> const &pBodyProf);
        
    private:
        void SetID(UINT_PTR id);
        mdToken GetToken() const;
        static void FillProperties(function_profiler_pimpl_label_type const *_this, ClassID &classId, ModuleID &moduleId, mdToken &mdt);
        static void FillFunctionBodyProperties(function_profiler_pimpl_label_type const *_this, FunctionBodyID &functionBodyId);

        mutable function_profiler_label_type *m_pClass;
        process_profiler_label_type *m_pProcProf;
        UINT_PTR m_id;
        mutable ClassID m_classId;
        mutable ModuleID m_moduleId;
        mutable FunctionBodyID m_functionBodyId;
        mutable mdToken m_mdt;
        mutable method_generator_label_type *m_pMethodGen;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_H

