/* 
 * File: BaseFunctionBodyProfiler.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseFunctionBodyProfiler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    template<class ApiHolder>    
    BaseFunctionBodyProfiler<ApiHolder>::BaseFunctionBodyProfiler()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(function_body_profiler_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(function_body_profiler_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())function_body_profiler_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseFunctionBodyProfiler<ApiHolder>::~BaseFunctionBodyProfiler()
    {
        Pimpl()->~function_body_profiler_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseFunctionBodyProfiler<ApiHolder>::function_body_profiler_pimpl_label_type *BaseFunctionBodyProfiler<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<function_body_profiler_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseFunctionBodyProfiler<ApiHolder>::function_body_profiler_pimpl_label_type const *BaseFunctionBodyProfiler<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_FUNCTION_BODY_PROFILER_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseFunctionBodyProfiler<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        Pimpl()->Initialize(pProcProf);
    }

    template<class ApiHolder>    
    UINT_PTR BaseFunctionBodyProfiler<ApiHolder>::GetID() const
    {
        return Pimpl()->GetID();
    }

    template<class ApiHolder>    
    typename BaseFunctionBodyProfiler<ApiHolder>::method_body_generator_label_type *BaseFunctionBodyProfiler<ApiHolder>::GetMethodBodyGenerator(method_generator_label_type *pMethodGen)
    {
        return Pimpl()->GetMethodBodyGenerator(pMethodGen);
    }

    template<class ApiHolder>    
    typename BaseFunctionBodyProfiler<ApiHolder>::method_body_generator_label_type const *BaseFunctionBodyProfiler<ApiHolder>::GetMethodBodyGenerator(method_generator_label_type const *pMethodGen) const
    {
        return Pimpl()->GetMethodBodyGenerator(pMethodGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseFunctionBodyProfiler<ApiHolder>::function_profiler_label_type> BaseFunctionBodyProfiler<ApiHolder>::AttachToFunction()
    {
        return Pimpl()->AttachToFunction();
    }

    template<class ApiHolder>    
    TempPtr<typename BaseFunctionBodyProfiler<ApiHolder>::function_profiler_label_type const> BaseFunctionBodyProfiler<ApiHolder>::AttachToFunction() const
    {
        return Pimpl()->AttachToFunction();
    }

    template<class ApiHolder>    
    void BaseFunctionBodyProfiler<ApiHolder>::SetID(UINT_PTR id)
    {
        Pimpl()->SetID(id);
    }

    template<class ApiHolder>    
    void BaseFunctionBodyProfiler<ApiHolder>::SetFunctionID(FunctionID functionId)
    {
        Pimpl()->SetFunctionID(functionId);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_HPP

