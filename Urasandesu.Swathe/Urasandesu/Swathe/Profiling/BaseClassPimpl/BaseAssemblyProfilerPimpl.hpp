/* 
 * File: BaseAssemblyProfilerPimpl.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseAssemblyProfilerPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAssemblyProfilerPimpl<ApiHolder>::BaseAssemblyProfilerPimpl(assembly_profiler_label_type *pClass) : 
        m_pClass(pClass), 
        m_pProcProf(nullptr), 
        m_id(static_cast<UINT_PTR>(-1)), 
        m_appDomainId(static_cast<UINT_PTR>(-1)), 
        m_moduleId(static_cast<UINT_PTR>(-1)), 
        m_pAsmGen(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseAssemblyProfilerPimpl<ApiHolder>::~BaseAssemblyProfilerPimpl()
    {
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseAssemblyProfilerPimpl<ApiHolder>::base_heap_provider_type *BaseAssemblyProfilerPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAssemblyProfilerPimpl<ApiHolder>::base_heap_provider_type const *BaseAssemblyProfilerPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    UINT_PTR BaseAssemblyProfilerPimpl<ApiHolder>::GetID() const
    {
        _ASSERTE(m_id != static_cast<UINT_PTR>(-1));
        return m_id;
    }



    template<class ApiHolder>    
    wstring const &BaseAssemblyProfilerPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
            FillProperties(this, m_name, m_appDomainId, m_moduleId);
        return m_name;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyProfilerPimpl<ApiHolder>::app_domain_profiler_label_type> BaseAssemblyProfilerPimpl<ApiHolder>::AttachToAppDomain()
    {
        if (m_appDomainId == static_cast<UINT_PTR>(-1))
            FillProperties(this, m_name, m_appDomainId, m_moduleId);
        return m_pProcProf->AttachToAppDomain(m_appDomainId);
    }



    template<class ApiHolder>    
    typename BaseAssemblyProfilerPimpl<ApiHolder>::assembly_generator_label_type *BaseAssemblyProfilerPimpl<ApiHolder>::GetAssemblyGenerator()
    {
        using ATL::CComPtr;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_pAsmGen)
        {
            if (m_moduleId == static_cast<UINT_PTR>(-1))
                FillProperties(this, m_name, m_appDomainId, m_moduleId);

            auto &comProfInfo = m_pProcProf->GetCOMProfilerInfo();
            
            auto pComMetaImp = CComPtr<IMetaDataImport2>();
            auto hr = comProfInfo.GetModuleMetaData(m_moduleId, ofRead | ofWrite, IID_IMetaDataImport2, reinterpret_cast<IUnknown **>(&pComMetaImp));
            if (hr != CORPROF_E_DATAINCOMPLETE && FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            auto pDomainProf = m_pClass->AttachToAppDomain();
            auto *pDisp = pDomainProf->GetMetadataDispenser();
            m_pAsmGen = pDisp->GetModifiableAssembly(&*pComMetaImp);
        }
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyProfilerPimpl<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        _ASSERTE(pProcProf != nullptr);
        _ASSERTE(m_pProcProf == nullptr);
        m_pProcProf = pProcProf;
    }



    template<class ApiHolder>    
    void BaseAssemblyProfilerPimpl<ApiHolder>::SetID(UINT_PTR id)
    {
        _ASSERTE(id != static_cast<UINT_PTR>(-1));
        _ASSERTE(m_id == static_cast<UINT_PTR>(-1));
        m_id = id;
    }



    template<class ApiHolder>    
    void BaseAssemblyProfilerPimpl<ApiHolder>::FillProperties(assembly_profiler_pimpl_label_type const *_this, wstring &name, AppDomainID &appDomainId, ModuleID &moduleId)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comProfInfo = _this->m_pProcProf->GetCOMProfilerInfo();

        auto assemblyId = _this->GetID();
        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto length = 0ul;
        auto _appDomainId = AppDomainID();
        auto _moduleId = ModuleID();
        auto hr = comProfInfo.GetAssemblyInfo(assemblyId, wzname.size(), &length, wzname.c_array(), &_appDomainId, &_moduleId);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        appDomainId = _appDomainId;
        moduleId = _moduleId;
    }



    template<class ApiHolder>    
    IMethodMalloc &BaseAssemblyProfilerPimpl<ApiHolder>::GetCOMMethodMalloc()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pComMethodMalloc.p == nullptr)
        {
            if (m_moduleId == static_cast<UINT_PTR>(-1))
                FillProperties(this, m_name, m_appDomainId, m_moduleId);

            auto &comProfInfo = m_pProcProf->GetCOMProfilerInfo();

            auto hr = comProfInfo.GetILFunctionBodyAllocator(m_moduleId, &m_pComMethodMalloc);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComMethodMalloc;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPL_HPP

