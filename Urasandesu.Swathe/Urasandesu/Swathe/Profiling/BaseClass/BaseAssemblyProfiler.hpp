/* 
 * File: BaseAssemblyProfiler.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEASSEMBLYPROFILER_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEASSEMBLYPROFILER_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEASSEMBLYPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseAssemblyProfiler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAssemblyProfiler<ApiHolder>::BaseAssemblyProfiler()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_profiler_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_profiler_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())assembly_profiler_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseAssemblyProfiler<ApiHolder>::~BaseAssemblyProfiler()
    {
        Pimpl()->~assembly_profiler_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseAssemblyProfiler<ApiHolder>::assembly_profiler_pimpl_label_type *BaseAssemblyProfiler<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<assembly_profiler_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAssemblyProfiler<ApiHolder>::assembly_profiler_pimpl_label_type const *BaseAssemblyProfiler<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_PROFILER_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseAssemblyProfiler<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        Pimpl()->Initialize(pProcProf);
    }

    template<class ApiHolder>    
    UINT_PTR BaseAssemblyProfiler<ApiHolder>::GetID() const
    {
        return Pimpl()->GetID();
    }

    template<class ApiHolder>    
    wstring const &BaseAssemblyProfiler<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyProfiler<ApiHolder>::app_domain_profiler_label_type> BaseAssemblyProfiler<ApiHolder>::AttachToAppDomain()
    {
        return Pimpl()->AttachToAppDomain();
    }

    template<class ApiHolder>    
    typename BaseAssemblyProfiler<ApiHolder>::assembly_generator_label_type *BaseAssemblyProfiler<ApiHolder>::GetAssemblyGenerator(metadata_dispenser_label_type *pDisp)
    {
        return Pimpl()->GetAssemblyGenerator(pDisp);
    }

    template<class ApiHolder>    
    void BaseAssemblyProfiler<ApiHolder>::SetID(UINT_PTR id)
    {
        Pimpl()->SetID(id);
    }

    template<class ApiHolder>    
    IMethodMalloc &BaseAssemblyProfiler<ApiHolder>::GetCOMMethodMalloc()
    {
        return Pimpl()->GetCOMMethodMalloc();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEASSEMBLYPROFILER_HPP

