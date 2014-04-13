/* 
 * File: BaseClassProfilerPimpl.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASECLASSPROFILERPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASECLASSPROFILERPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASECLASSPROFILERPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseClassProfilerPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseClassProfilerPimpl<ApiHolder>::BaseClassProfilerPimpl(class_profiler_label_type *pClass) : 
        m_pClass(pClass), 
        m_pProcProf(nullptr), 
        m_id(static_cast<UINT_PTR>(-1)), 
        m_moduleId(static_cast<UINT_PTR>(-1)), 
        m_mdt(mdTokenNil)
    { }

#define SWATHE_DECLARE_BASE_CLASS_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseClassProfilerPimpl<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        _ASSERTE(pProcProf != nullptr);
        _ASSERTE(m_pProcProf == nullptr);
        m_pProcProf = pProcProf;
    }



    template<class ApiHolder>    
    UINT_PTR BaseClassProfilerPimpl<ApiHolder>::GetID() const
    {
        _ASSERTE(m_id != static_cast<UINT_PTR>(-1));
        return m_id;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseClassProfilerPimpl<ApiHolder>::module_profiler_label_type> BaseClassProfilerPimpl<ApiHolder>::AttachToModule()
    {
        if (m_moduleId == static_cast<UINT_PTR>(-1))
            FillProperties(this, m_moduleId, m_mdt);
        return m_pProcProf->AttachToModule(m_moduleId);
    }



    template<class ApiHolder>    
    void BaseClassProfilerPimpl<ApiHolder>::SetID(UINT_PTR id)
    {
        _ASSERTE(id != static_cast<UINT_PTR>(-1));
        _ASSERTE(m_id == static_cast<UINT_PTR>(-1));
        m_id = id;
    }



    template<class ApiHolder>    
    void BaseClassProfilerPimpl<ApiHolder>::FillProperties(class_profiler_pimpl_label_type const *_this, ModuleID &moduleId, mdToken &mdt)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comProfInfo = _this->m_pProcProf->GetCOMProfilerInfo();

        auto classId = _this->GetID();
        auto _moduleId = ModuleID();
        auto mdtd = mdTypeDefNil;
        auto hr = comProfInfo.GetClassIDInfo(classId, &_moduleId, &mdtd);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));   // TODO: classId が 0 で来てる？？
                                                                // TODO: 考えてみれば、Type に属さず、Module に直接属す Method があっても良かったんだった。
                                                                // TODO: Metadata 側で破綻がないか見直す必要あるかも・・・。うへー。

        moduleId = _moduleId;
        mdt = mdtd;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASECLASSPROFILERPIMPL_HPP

