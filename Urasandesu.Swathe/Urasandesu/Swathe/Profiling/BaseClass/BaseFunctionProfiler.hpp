/* 
 * File: BaseFunctionProfiler.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONPROFILER_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONPROFILER_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseFunctionProfiler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    template<class ApiHolder>    
    BaseFunctionProfiler<ApiHolder>::BaseFunctionProfiler()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(function_profiler_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(function_profiler_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())function_profiler_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseFunctionProfiler<ApiHolder>::~BaseFunctionProfiler()
    {
        Pimpl()->~function_profiler_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseFunctionProfiler<ApiHolder>::function_profiler_pimpl_label_type *BaseFunctionProfiler<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<function_profiler_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseFunctionProfiler<ApiHolder>::function_profiler_pimpl_label_type const *BaseFunctionProfiler<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_FUNCTION_PROFILER_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    UINT_PTR BaseFunctionProfiler<ApiHolder>::GetID() const
    {
        return Pimpl()->GetID();
    }

    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfiler<ApiHolder>::class_profiler_label_type> BaseFunctionProfiler<ApiHolder>::AttachToClass()
    {
        return Pimpl()->AttachToClass();
    }

    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfiler<ApiHolder>::module_profiler_label_type> BaseFunctionProfiler<ApiHolder>::AttachToModule()
    {
        return Pimpl()->AttachToModule();
    }

    template<class ApiHolder>    
    typename BaseFunctionProfiler<ApiHolder>::method_generator_label_type *BaseFunctionProfiler<ApiHolder>::GetMethodGenerator()
    {
        return Pimpl()->GetMethodGenerator();
    }

    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfiler<ApiHolder>::function_body_profiler_label_type> BaseFunctionProfiler<ApiHolder>::AttachToFunctionBody()
    {
        return Pimpl()->AttachToFunctionBody();
    }

    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfiler<ApiHolder>::function_body_profiler_label_type> BaseFunctionProfiler<ApiHolder>::NewFunctionBody()
    {
        return Pimpl()->NewFunctionBody();
    }

    template<class ApiHolder>    
    void BaseFunctionProfiler<ApiHolder>::SetFunctionBody(TempPtr<function_body_profiler_label_type const> const &pBodyProf)
    {
        Pimpl()->SetFunctionBody(pBodyProf);
    }

    template<class ApiHolder>    
    void BaseFunctionProfiler<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        Pimpl()->Initialize(pProcProf);
    }

    template<class ApiHolder>    
    void BaseFunctionProfiler<ApiHolder>::SetID(UINT_PTR id)
    {
        Pimpl()->SetID(id);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONPROFILER_HPP

