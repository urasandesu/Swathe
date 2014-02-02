/* 
 * File: BaseAppDomainProfilerPimpl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPL_H
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_APPDOMAINPROFILERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplFacade/AppDomainProfilerPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseAppDomainProfilerPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using boost::unordered_map;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::AnyPtr;
    
    template<
        class ApiHolder
    >    
    class BaseAppDomainProfilerPimpl
    {
    public:
        SWATHE_BEGIN_APP_DOMAIN_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_APP_DOMAIN_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_APP_DOMAIN_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseAppDomainProfilerPimpl(app_domain_profiler_label_type *pClass);
        ~BaseAppDomainProfilerPimpl();
        
        UINT_PTR GetID() const;
        metadata_dispenser_label_type *GetMetadataDispenser();
        AnyPtr GetData(wstring const &name);
        void SetData(wstring const &name, AnyPtr const &pData);

    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        void Initialize(process_profiler_label_type *pProcProf, metadata_info_label_type *pMetaInfo);
        void SetID(UINT_PTR id);
#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 40;
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable app_domain_profiler_label_type *m_pClass;
        process_profiler_label_type *m_pProcProf;
        metadata_info_label_type *m_pMetaInfo;
        UINT_PTR m_id;
        metadata_dispenser_label_type *m_pDisp;
        unordered_map<wstring, AnyPtr> m_dataEntries;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEAPPDOMAINPROFILERPIMPL_H

