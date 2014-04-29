/* 
 * File: BaseHostInfoPimpl.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BaseHostInfoPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseHostInfoPimpl<ApiHolder>::BaseHostInfoPimpl(host_info_label_type *pClass) : 
        m_pClass(pClass), 
        m_pHost(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseHostInfoPimpl<ApiHolder>::~BaseHostInfoPimpl()
    {
        if (!m_versionToRuntimes.empty())
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<runtime_host_label_type>();
            BOOST_FOREACH (auto const &pair, m_versionToRuntimes)
                provider.DeleteObject(pair.second);
        }

        if (!m_hosts.empty())
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<host_info_label_type>();
            BOOST_FOREACH (auto const &pHost, m_hosts)
                provider.DeleteObject(pHost);

            // If we delegate releasing the resources to system, the result will become unintended consequences for Boost.Log.
            boost::log::core::get()->remove_all_sinks();
        }

        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseHostInfoPimpl<ApiHolder>::base_heap_provider_type *BaseHostInfoPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseHostInfoPimpl<ApiHolder>::base_heap_provider_type const *BaseHostInfoPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_HOST_INFO_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>
    void BaseHostInfoPimpl<ApiHolder>::Initialize(host_info_label_type *pHost)
    {
        _ASSERT(!m_pHost);
        _ASSERT(pHost);
        m_pHost = pHost;
    }
    
    
    
    template<class ApiHolder>    
    typename BaseHostInfoPimpl<ApiHolder>::host_info_label_type *BaseHostInfoPimpl<ApiHolder>::CreateHost()
    {
        typedef boost::lock_guard<boost::mutex> Guard;
        static auto lock = boost::mutex();
        auto _ = Guard(lock);

        auto pHost = NewHost(); 
        pHost.Persist();
        return pHost.Get();
    }


    
    template<class ApiHolder>
    typename BaseHostInfoPimpl<ApiHolder>::runtime_host_label_type const *BaseHostInfoPimpl<ApiHolder>::GetRuntime(wstring const &version) const
    {
        using namespace Urasandesu::CppAnonym;

        if (version.empty())
            BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

        auto pNewRuntime = NewRuntime(version);

        auto *pExistingRuntime = static_cast<runtime_host_label_type *>(nullptr);
        if (!TryGetRuntime(version, pExistingRuntime))
        {
            pNewRuntime.Persist();
            return pNewRuntime.Get();
        }
        else
        {
            return pExistingRuntime;
        }
    }


    
    template<class ApiHolder>    
    TempPtr<typename BaseHostInfoPimpl<ApiHolder>::host_info_label_type> typename BaseHostInfoPimpl<ApiHolder>::NewHost()
    {
        auto &host = swathe_storage_label_type::Object<host_info_label_type>();
        auto *pHostPimpl = host.Pimpl();
        auto *pBaseProvider = pHostPimpl->BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<host_info_label_type>();
        auto pHost = provider.NewObject();
        pHost->Initialize(&host);
        auto handler = host_info_persisted_handler_label_type(&host);
        provider.AddPersistedHandler(pHost, handler);
        return pHost;
    }


    
    template<class ApiHolder>
    void BaseHostInfoPimpl<ApiHolder>::RegisterHost(TempPtr<host_info_label_type> &pHost)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<host_info_label_type>();
        provider.RegisterObject(pHost);
        m_hosts.push_back(pHost.Get());
    }


    template<class ApiHolder>
    TempPtr<typename BaseHostInfoPimpl<ApiHolder>::runtime_host_label_type> BaseHostInfoPimpl<ApiHolder>::NewRuntime(wstring const &version) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<runtime_host_label_type>();
        auto pRuntime = provider.NewObject();
        pRuntime->Initialize(m_pClass);
        auto handler = runtime_host_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pRuntime, handler);
        pRuntime->SetRequestedVersion(version);
        return pRuntime;
    }
    
    
    
    template<class ApiHolder>    
    void BaseHostInfoPimpl<ApiHolder>::RegisterRuntime(TempPtr<runtime_host_label_type> &pRuntime)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<runtime_host_label_type>();
        provider.RegisterObject(pRuntime);
        m_versionToRuntimes[pRuntime->GetCORVersion()] = pRuntime.Get();
    }



    template<class ApiHolder>    
    bool BaseHostInfoPimpl<ApiHolder>::TryGetRuntime(wstring const &version, runtime_host_label_type *&pExistingRuntime) const
    {
        auto result = m_versionToRuntimes.find(version);
        if (result == m_versionToRuntimes.end())
        {
            return false;
        }
        else
        {
            pExistingRuntime = (*result).second;
            return true;
        }
    }



    template<class ApiHolder>    
    ICLRMetaHost &BaseHostInfoPimpl<ApiHolder>::GetCOMMetaHost() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_pComMetaHost.p)
        {
            auto hr = ::CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, reinterpret_cast<LPVOID *>(&m_pComMetaHost));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComMetaHost;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_HPP

