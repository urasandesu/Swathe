/* 
 * File: BaseHostInfo.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_H
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_HOSTINFOFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassFacade/HostInfoFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFOFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseHostInfoFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    using boost::aligned_storage;
    using Urasandesu::CppAnonym::SimpleDisposable;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseHostInfo : 
        public SimpleDisposable
    {
    public:
        SWATHE_BEGIN_HOST_INFO_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_HOST_INFO_FACADE_TYPEDEF_ALIAS
        SWATHE_END_HOST_INFO_FACADE_TYPEDEF_ALIAS
        
        BaseHostInfo();
        ~BaseHostInfo();

        void Initialize(host_info_label_type *pHost);
        static host_info_label_type *CreateHost();
        runtime_host_label_type const *GetRuntime(std::wstring const &version) const;
    
    private:
        host_info_pimpl_label_type *Pimpl();
        host_info_pimpl_label_type const *Pimpl() const;
        void RegisterHost(TempPtr<host_info_label_type> &pHost);
        void RegisterRuntime(TempPtr<runtime_host_label_type> &pRuntime);

        ICLRMetaHost &GetCOMMetaHost() const;

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 112;
#else
        static INT const PIMPL_TYPE_SIZE = 224;
#endif
#endif
        typedef typename aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_H

