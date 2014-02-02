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
        m_corVersionInitialized(false), 
        m_corSysDirPathInitialized(false)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseRuntimeHostPimpl<ApiHolder>::~BaseRuntimeHostPimpl()
    {
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
    wstring const &BaseRuntimeHostPimpl<ApiHolder>::GetCORVersion() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        m_pClass->CheckDisposed();

        if (!m_corVersionInitialized)
        {
            auto buffer = array<WCHAR, MAX_PATH>();
            auto length = static_cast<DWORD>(0);

#pragma warning(push)
#pragma warning(disable: 4996)
            auto hr = ::GetCORVersion(buffer.c_array(), buffer.size(), &length);
#pragma warning(pop)
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
            m_corVersion = buffer.data();

            m_corVersionInitialized = true;
        }
        return m_corVersion;
    }


    template<class ApiHolder>
    path const &BaseRuntimeHostPimpl<ApiHolder>::GetCORSystemDirectoryPath() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        m_pClass->CheckDisposed();

        if (!m_corSysDirPathInitialized)
        {
            auto buffer = array<WCHAR, MAX_PATH>();
            auto length = static_cast<DWORD>(0);

#pragma warning(push)
#pragma warning(disable: 4996)
            auto hr = ::GetCORSystemDirectory(buffer.c_array(), buffer.size(), &length);
#pragma warning(pop)
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_corSysDirPath = buffer.data();
                
            m_corSysDirPathInitialized = true;
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
    void BaseRuntimeHostPimpl<ApiHolder>::Initialize(host_info_label_type const *pHost)
    {
        _ASSERTE(m_pHost == nullptr);
        _ASSERTE(pHost != nullptr);
        m_pHost = pHost;
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
    template<class Info>
    void BaseRuntimeHostPimpl<ApiHolder>::RegisterInfo(TempPtr<Info> &pInfo)
    {
        using boost::mpl::identity;

        auto info = TypeInfo(identity<Info>());
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<Info>();
        m_infoToIndex[info] = provider.RegisterObject(pInfo);
    }

    
    template<class ApiHolder>
    template<class Info>
    bool BaseRuntimeHostPimpl<ApiHolder>::TryGetInfo(Info *&pExistingInfo) const
    {
        using boost::mpl::identity;

        BOOST_MPL_ASSERT((typename base_heap_provider_type::is_provided_object<Info>));

        auto info = TypeInfo(identity<Info>());
        if (m_infoToIndex.find(info) == m_infoToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_infoToIndex[info];
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<Info>();
            pExistingInfo = provider.GetObject(index);
            return true;
        }
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_HPP

