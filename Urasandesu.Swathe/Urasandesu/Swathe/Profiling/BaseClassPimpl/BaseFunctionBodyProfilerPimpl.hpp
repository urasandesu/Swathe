/* 
 * File: BaseFunctionBodyProfilerPimpl.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseFunctionBodyProfilerPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseFunctionBodyProfilerPimpl<ApiHolder>::BaseFunctionBodyProfilerPimpl(function_body_profiler_label_type *pClass) : 
        m_pClass(pClass), 
        m_pProcProf(nullptr), 
        m_id(-1), 
        m_functionId(-1), 
        m_pBodyGen(nullptr)
    { }

#define SWATHE_DECLARE_BASE_FUNCTION_BODY_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseFunctionBodyProfilerPimpl<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        _ASSERTE(pProcProf);
        _ASSERTE(!m_pProcProf);
        m_pProcProf = pProcProf;
    }



    template<class ApiHolder>    
    UINT_PTR BaseFunctionBodyProfilerPimpl<ApiHolder>::GetID() const
    {
        return m_id;
    }



    template<class ApiHolder>    
    typename BaseFunctionBodyProfilerPimpl<ApiHolder>::method_body_generator_label_type *BaseFunctionBodyProfilerPimpl<ApiHolder>::GetMethodBodyGenerator(method_generator_label_type *pMethodGen)
    {
        using boost::polymorphic_cast;
        using Urasandesu::Swathe::Metadata::IMethodBody;

        if (!m_pBodyGen)
        {
            _ASSERTE(pMethodGen);
            auto functionBodyId = GetID();
            m_pBodyGen = functionBodyId == -1 ? 
                            pMethodGen->DefineMethodBody() : 
                            polymorphic_cast<method_body_generator_label_type *>(const_cast<IMethodBody *>(pMethodGen->GetMethodBody()));
        }
        return m_pBodyGen;
    }



    template<class ApiHolder>    
    typename BaseFunctionBodyProfilerPimpl<ApiHolder>::method_body_generator_label_type const *BaseFunctionBodyProfilerPimpl<ApiHolder>::GetMethodBodyGenerator(method_generator_label_type const *pMethodGen) const
    {
        return const_cast<class_pimpl_type *>(this)->GetMethodBodyGenerator(const_cast<method_generator_label_type *>(pMethodGen));
    }



    template<class ApiHolder>    
    TempPtr<typename BaseFunctionBodyProfilerPimpl<ApiHolder>::function_profiler_label_type> BaseFunctionBodyProfilerPimpl<ApiHolder>::AttachToFunction()
    {
        _ASSERTE(m_functionId != -1);
        return m_pProcProf->AttachToFunction(m_functionId);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseFunctionBodyProfilerPimpl<ApiHolder>::function_profiler_label_type const> BaseFunctionBodyProfilerPimpl<ApiHolder>::AttachToFunction() const
    {
        return const_cast<class_pimpl_type *>(this)->AttachToFunction();
    }



    template<class ApiHolder>    
    void BaseFunctionBodyProfilerPimpl<ApiHolder>::SetID(UINT_PTR id)
    {
        _ASSERTE(m_id == -1);
        m_id = id;
    }



    template<class ApiHolder>    
    void BaseFunctionBodyProfilerPimpl<ApiHolder>::SetFunctionID(FunctionID functionId)
    {
        _ASSERTE(functionId != -1);
        _ASSERTE(m_functionId == -1);
        m_functionId = functionId;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONBODYPROFILERPIMPL_HPP

