/* 
 * File: BaseRuntimeHost.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_RUNTIMEHOSTFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassFacade/RuntimeHostFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOSTFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseRuntimeHostFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    using boost::aligned_storage;
    using boost::filesystem::path;
    using std::wstring;
    using Urasandesu::CppAnonym::SimpleDisposable;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using Urasandesu::CppAnonym::Utilities::TypeInfo;

    template<
        class ApiHolder
    >    
    class BaseRuntimeHost : 
        public SimpleDisposable
    {
    public:
        SWATHE_BEGIN_RUNTIME_HOST_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_RUNTIME_HOST_FACADE_TYPEDEF_ALIAS
        SWATHE_END_RUNTIME_HOST_FACADE_TYPEDEF_ALIAS
        
        BaseRuntimeHost();
        ~BaseRuntimeHost();

        wstring const &GetCORVersion() const;
        path const &GetCORSystemDirectoryPath() const;
        template<class Info> Info *GetInfo() const;
    
    private:
        runtime_host_pimpl_label_type *Pimpl();
        runtime_host_pimpl_label_type const *Pimpl() const;
        void Initialize(host_info_label_type const *pHost);
        template<class Info> void RegisterInfo(TempPtr<Info> &pInfo);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 248;
#endif
        typedef typename aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H

