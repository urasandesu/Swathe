/* 
 * File: BaseModuleProfiler.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEMODULEPROFILER_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEMODULEPROFILER_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEMODULEPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseModuleProfiler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    template<class ApiHolder>    
    BaseModuleProfiler<ApiHolder>::BaseModuleProfiler()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(module_profiler_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(module_profiler_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())module_profiler_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseModuleProfiler<ApiHolder>::~BaseModuleProfiler()
    {
        Pimpl()->~module_profiler_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseModuleProfiler<ApiHolder>::module_profiler_pimpl_label_type *BaseModuleProfiler<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<module_profiler_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseModuleProfiler<ApiHolder>::module_profiler_pimpl_label_type const *BaseModuleProfiler<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_MODULE_PROFILER_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    UINT_PTR BaseModuleProfiler<ApiHolder>::GetID() const
    {
        return Pimpl()->GetID();
    }

    template<class ApiHolder>    
    wstring const &BaseModuleProfiler<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }
    
    template<class ApiHolder>    
    TempPtr<typename BaseModuleProfiler<ApiHolder>::assembly_profiler_label_type> BaseModuleProfiler<ApiHolder>::AttachToAssembly()
    {
        return Pimpl()->AttachToAssembly();
    }

    template<class ApiHolder>    
    void BaseModuleProfiler<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        Pimpl()->Initialize(pProcProf);
    }

    template<class ApiHolder>    
    void BaseModuleProfiler<ApiHolder>::SetID(UINT_PTR id)
    {
        Pimpl()->SetID(id);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEMODULEPROFILER_HPP

