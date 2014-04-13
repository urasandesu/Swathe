/* 
 * File: BaseRuntimeHostPimpl.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BaseRuntimeHostPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseRuntimeHostPimpl<ApiHolder>::BaseRuntimeHostPimpl(runtime_host_label_type *pClass) : 
        m_pClass(pClass), 
        m_pHost(nullptr), 
        m_corVersionInit(false), 
        m_corSysDirPathInit(false)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    struct BaseRuntimeHostPimpl<ApiHolder>::info_destructor
    {
        info_destructor(base_heap_provider_type *pBaseProvider, unordered_map<TypeInfo, void *, TypeInfoHash, TypeInfoEqualTo> &infoToObjs) : 
            m_pBaseProvider(pBaseProvider), 
            m_infoToObjs(infoToObjs)
        { }

        template<class T>
        void operator()(T)
        {
            using boost::mpl::identity;

            typedef typename T::object_type Info;

            auto info = TypeInfo(identity<Info>());
            auto result = m_infoToObjs.find(info);
            if (result != m_infoToObjs.end())
            {
                auto &provider = m_pBaseProvider->FirstProviderOf<Info>();
                provider.DeleteObject(static_cast<Info *>((*result).second));
            }
        }

        base_heap_provider_type *m_pBaseProvider;
        unordered_map<TypeInfo, void *, TypeInfoHash, TypeInfoEqualTo> &m_infoToObjs;
    };

    template<class ApiHolder>    
    BaseRuntimeHostPimpl<ApiHolder>::~BaseRuntimeHostPimpl()
    {
        namespace mpl = boost::mpl;
        using mpl::for_each;

        if (!m_infoToObjs.empty())
        {
            typedef typename base_heap_provider_type::disposing_info<>::type DisposingInfos;
            for_each<DisposingInfos>(info_destructor(BaseHeapProvider(), m_infoToObjs));
        }

        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseRuntimeHostPimpl<ApiHolder>::base_heap_provider_type *BaseRuntimeHostPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseRuntimeHostPimpl<ApiHolder>::base_heap_provider_type const *BaseRuntimeHostPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_RUNTIME_HOST_PIMPL_ADDITIONAL_INSTANTIATION \
    template Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> *Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::GetInfo<Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::RegisterInfo<Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> > &); \
    template Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> *Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::GetInfo<Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::RegisterInfo<Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> > &); \
    template Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> *Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::GetInfo<Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::RegisterInfo<Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> > &); \
    template Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> *Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::GetInfo<Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::RegisterInfo<Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> > &); \
    template Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> *Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::GetInfo<Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>::RegisterInfo<Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> > &); \


    
    template<class ApiHolder>
    void BaseRuntimeHostPimpl<ApiHolder>::Initialize(host_info_label_type *pHost)
    {
        _ASSERTE(!m_pHost);
        _ASSERTE(pHost);
        m_pHost = pHost;
    }


    
    template<class ApiHolder>
    wstring const &BaseRuntimeHostPimpl<ApiHolder>::GetRequestedVersion() const
    {
        return m_reqVersion;
    }



    template<class ApiHolder>
    wstring const &BaseRuntimeHostPimpl<ApiHolder>::GetCORVersion() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        m_pClass->CheckDisposed();

        if (!m_corVersionInit)
        {
            auto &comRuntimeInfo = m_pClass->GetCOMRuntimeInfo();

            auto buffer = array<WCHAR, MAX_PATH>();
            auto length = static_cast<DWORD>(buffer.size());

            auto hr = comRuntimeInfo.GetRuntimeDirectory(buffer.c_array(), &length);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
            m_corVersion = buffer.data();

            m_corVersionInit = true;
        }
        return m_corVersion;
    }


    template<class ApiHolder>
    path const &BaseRuntimeHostPimpl<ApiHolder>::GetCORSystemDirectoryPath() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        m_pClass->CheckDisposed();

        if (!m_corSysDirPathInit)
        {
            auto &comRuntimeInfo = m_pClass->GetCOMRuntimeInfo();

            auto buffer = array<WCHAR, MAX_PATH>();
            auto length = static_cast<DWORD>(buffer.size());

            auto hr = comRuntimeInfo.GetRuntimeDirectory(buffer.c_array(), &length);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_corSysDirPath = buffer.data();
                
            m_corSysDirPathInit = true;
        }
        return m_corSysDirPath;
    }

    
    
    template<class ApiHolder>
    template<class Info>
    Info *BaseRuntimeHostPimpl<ApiHolder>::GetInfo() const
    {
        BOOST_MPL_ASSERT((typename base_heap_provider_type::is_provided_object<Info>));

        auto *pExistingInfo = static_cast<Info *>(nullptr);
        if (!TryGetInfo<Info>(pExistingInfo))
        {
            auto pNewInfo = NewInfo<Info>();
            pNewInfo.Persist();
            return pNewInfo.Get();
        }
        else
        {
            return pExistingInfo;
        }
    }

    
    
    template<class ApiHolder>
    template<class Info>
    TempPtr<Info> BaseRuntimeHostPimpl<ApiHolder>::NewInfo() const
    {
        BOOST_MPL_ASSERT((typename base_heap_provider_type::is_provided_object<Info>));
        typedef typename base_heap_provider_type::first_providing_persisted_handler<Info>::type InfoPersistedHandler;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<Info>();
        auto pInfo = provider.NewObject();
        pInfo->Initialize(m_pClass);
        auto handler = InfoPersistedHandler(m_pClass);
        provider.AddPersistedHandler(pInfo, handler);
        return pInfo;
    }



    template<class ApiHolder>
    void BaseRuntimeHostPimpl<ApiHolder>::SetRequestedVersion(wstring const &reqVersion)
    {
        _ASSERTE(m_reqVersion.empty());
        _ASSERTE(!reqVersion.empty());
        m_reqVersion = reqVersion;
    }



    template<class ApiHolder>
    template<class Info>
    void BaseRuntimeHostPimpl<ApiHolder>::RegisterInfo(TempPtr<Info> &pInfo)
    {
        using boost::mpl::identity;

        auto info = TypeInfo(identity<Info>());
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<Info>();
        provider.RegisterObject(pInfo);
        m_infoToObjs[info] = pInfo.Get();
    }

    
    
    template<class ApiHolder>
    template<class Info>
    bool BaseRuntimeHostPimpl<ApiHolder>::TryGetInfo(Info *&pExistingInfo) const
    {
        using boost::mpl::identity;

        BOOST_MPL_ASSERT((typename base_heap_provider_type::is_provided_object<Info>));

        auto info = TypeInfo(identity<Info>());
        auto result = m_infoToObjs.find(info);
        if (result == m_infoToObjs.end())
        {
            return false;
        }
        else
        {
            pExistingInfo = static_cast<Info *>((*result).second);
            return true;
        }
    }
    
    
    
    template<class ApiHolder>
    ICLRRuntimeInfo &BaseRuntimeHostPimpl<ApiHolder>::GetCOMRuntimeInfo() const
    {
        using boost::filesystem::path;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_pComRuntimeInfo.p)
        {
            auto &comMetaHost = m_pHost->GetCOMMetaHost();

            auto const &reqVersion = m_pClass->GetRequestedVersion();
            auto hr = comMetaHost.GetRuntime(reqVersion.c_str(), IID_ICLRRuntimeInfo, reinterpret_cast<LPVOID *>(&m_pComRuntimeInfo));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComRuntimeInfo.p;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_HPP

