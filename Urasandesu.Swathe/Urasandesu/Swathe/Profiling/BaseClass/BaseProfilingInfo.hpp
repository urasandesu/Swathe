/* 
 * File: BaseProfilingInfo.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProfilingInfo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    template<class ApiHolder>    
    BaseProfilingInfo<ApiHolder>::BaseProfilingInfo()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(profiling_info_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(profiling_info_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())profiling_info_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseProfilingInfo<ApiHolder>::~BaseProfilingInfo()
    {
        Pimpl()->~profiling_info_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseProfilingInfo<ApiHolder>::profiling_info_pimpl_label_type *BaseProfilingInfo<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<profiling_info_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseProfilingInfo<ApiHolder>::profiling_info_pimpl_label_type const *BaseProfilingInfo<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PROFILING_INFO_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseProfilingInfo<ApiHolder>::Initialize(runtime_host_label_type *pRuntime)
    {
        Pimpl()->Initialize(pRuntime);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseProfilingInfo<ApiHolder>::process_profiler_label_type> BaseProfilingInfo<ApiHolder>::AttachToCurrentProcess(IUnknown *pComProfInfoUnk)
    {
        return Pimpl()->AttachToCurrentProcess(pComProfInfoUnk);
    }

    template<class ApiHolder>    
    typename BaseProfilingInfo<ApiHolder>::process_profiler_label_type *BaseProfilingInfo<ApiHolder>::GetCurrentProcessProfiler()
    {
        return Pimpl()->GetCurrentProcessProfiler();
    }

    template<class ApiHolder>    
    void BaseProfilingInfo<ApiHolder>::DetachFromCurrentProcess()
    {
        Pimpl()->DetachFromCurrentProcess();
    }

    template<class ApiHolder>    
    typename BaseProfilingInfo<ApiHolder>::runtime_host_label_type const *BaseProfilingInfo<ApiHolder>::GetRuntime() const
    {
        return Pimpl()->GetRuntime();
    }

    template<class ApiHolder>    
    void BaseProfilingInfo<ApiHolder>::RegisterProcessProfiler(TempPtr<process_profiler_label_type> &pProcProf)
    {
        Pimpl()->RegisterProcessProfiler(pProcProf);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_HPP

