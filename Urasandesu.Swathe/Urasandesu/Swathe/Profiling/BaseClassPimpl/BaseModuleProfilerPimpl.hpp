/* 
 * File: BaseModuleProfilerPimpl.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEMODULEPROFILERPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEMODULEPROFILERPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEMODULEPROFILERPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseModuleProfilerPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseModuleProfilerPimpl<ApiHolder>::BaseModuleProfilerPimpl(module_profiler_label_type *pClass) : 
        m_pClass(pClass), 
        m_pProcProf(nullptr), 
        m_id(static_cast<UINT_PTR>(-1)), 
        m_assemblyId(static_cast<UINT_PTR>(-1))
    { }

#define SWATHE_DECLARE_BASE_MODULE_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    UINT_PTR BaseModuleProfilerPimpl<ApiHolder>::GetID() const
    {
        _ASSERTE(m_id != static_cast<UINT_PTR>(-1));
        return m_id;
    }



    template<class ApiHolder>    
    wstring const &BaseModuleProfilerPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
            FillProperties(this, m_name, m_assemblyId);
        return m_name;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseModuleProfilerPimpl<ApiHolder>::assembly_profiler_label_type> BaseModuleProfilerPimpl<ApiHolder>::AttachToAssembly()
    {
        if (m_assemblyId == static_cast<UINT_PTR>(-1))
            FillProperties(this, m_name, m_assemblyId);
        return m_pProcProf->AttachToAssembly(m_assemblyId);
    }



    template<class ApiHolder>    
    void BaseModuleProfilerPimpl<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        _ASSERTE(pProcProf != nullptr);
        _ASSERTE(m_pProcProf == nullptr);
        m_pProcProf = pProcProf;
    }



    template<class ApiHolder>    
    void BaseModuleProfilerPimpl<ApiHolder>::SetID(UINT_PTR id)
    {
        _ASSERTE(id != static_cast<UINT_PTR>(-1));
        _ASSERTE(m_id == static_cast<UINT_PTR>(-1));
        m_id = id;
    }



    template<class ApiHolder>    
    void BaseModuleProfilerPimpl<ApiHolder>::FillProperties(module_profiler_pimpl_label_type const *_this, wstring &name, UINT_PTR &assemblyId)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comProfInfo = _this->m_pProcProf->GetCOMProfilerInfo();

        auto moduleId = _this->GetID();
        auto pBaseLoadAddress = LPCBYTE();
        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto length = 0ul;
        auto _assemblyId = AssemblyID();
        auto hr = comProfInfo.GetModuleInfo(moduleId, &pBaseLoadAddress, wzname.size(), &length, wzname.c_array(), &_assemblyId);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        assemblyId = _assemblyId;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEMODULEPROFILERPIMPL_HPP

