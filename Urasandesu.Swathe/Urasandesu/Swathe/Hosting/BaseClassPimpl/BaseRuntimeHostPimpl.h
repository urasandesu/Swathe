/* 
 * File: BaseRuntimeHostPimpl.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_H
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_RUNTIMEHOSTPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplFacade/RuntimeHostPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BaseRuntimeHostPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using boost::filesystem::path;
    using boost::unordered_map;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using Urasandesu::CppAnonym::Utilities::TypeInfo;
    using Urasandesu::CppAnonym::Utilities::TypeInfoHash;
    using Urasandesu::CppAnonym::Utilities::TypeInfoEqualTo;

    template<
        class ApiHolder
    >    
    class BaseRuntimeHostPimpl
    {
    public:
        SWATHE_BEGIN_RUNTIME_HOST_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_RUNTIME_HOST_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_RUNTIME_HOST_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseRuntimeHostPimpl(runtime_host_label_type *pClass);
        ~BaseRuntimeHostPimpl();

        void Initialize(host_info_label_type *pHost);
        wstring const &GetRequestedVersion() const;
        wstring const &GetCORVersion() const;
        path const &GetCORSystemDirectoryPath() const;
        template<class Info> Info *GetInfo() const;
        
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        void SetRequestedVersion(wstring const &reqVersion);
        template<class Info> TempPtr<Info> NewInfo() const;
        template<class Info> void RegisterInfo(TempPtr<Info> &pInfo);
        template<class Info> bool TryGetInfo(Info *&pExistingInfo) const;

        ICLRRuntimeInfo &GetCOMRuntimeInfo() const;

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
#ifdef _M_IX86
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 160;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 320;
#endif
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable runtime_host_label_type *m_pClass;
        host_info_label_type *m_pHost;
        wstring m_reqVersion;
        mutable bool m_corVersionInit;
        mutable wstring m_corVersion;
        mutable bool m_corSysDirPathInit;
        mutable path m_corSysDirPath;
        mutable unordered_map<TypeInfo, SIZE_T, TypeInfoHash, TypeInfoEqualTo> m_infoToIndex;
        mutable ATL::CComPtr<ICLRRuntimeInfo> m_pComRuntimeInfo;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_H

