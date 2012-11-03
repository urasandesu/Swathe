#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_BASEHOSTINFO_HPP
#define URASANDESU_SWATHE_HOSTING_BASEHOSTINFO_HPP

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_HOSTINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/HostInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASEHOSTINFOFWD_HPP
#include <Urasandesu/Swathe/Hosting/BaseHostInfoFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct HostInfoApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::HostInfoApiHolderLabel, ApiLabel>
    {
    };

    namespace HostInfoDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        
        template<
            class HostInfoApiHolder
        >    
        struct HostInfoFacade
        {
            typedef typename HostInfoApiAt<HostInfoApiHolder, HostInfoLabel>::type host_info_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, HostInfoPersistedHandlerLabel>::type host_info_persisted_handler_type;
            typedef DisposingInfo<host_info_type, host_info_persisted_handler_type> host_info_disposing_info_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, RuntimeHostLabel>::type runtime_host_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_type;
            typedef DisposingInfo<runtime_host_type, runtime_host_persisted_handler_type> runtime_host_disposing_info_type;


            typedef DisposableHeapProvider<
                host_info_disposing_info_type, 
                runtime_host_disposing_info_type
            > base_heap_provider_type;


            typedef typename base_heap_provider_type::provider_of<host_info_disposing_info_type>::type host_info_provider_type;
            typedef typename base_heap_provider_type::provider_of<runtime_host_disposing_info_type>::type runtime_host_provider_type;


            typedef mpl::void_ host_info_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<host_info_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<host_info_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<host_info_previous_type>::type host_info_chain_type;
        };
    
    }   // namespace HostInfoDetail {

    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfo : 
        public HostInfoDetail::HostInfoFacade<HostInfoApiHolder>::base_ptr_chain_type,
        public HostInfoDetail::HostInfoFacade<HostInfoApiHolder>::base_heap_provider_type,
        public SimpleDisposable
    {
    public:
        typedef BaseHostInfo<HostInfoApiHolder> this_type;
        
        typedef HostInfoDetail::HostInfoFacade<HostInfoApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::host_info_persisted_handler_type host_info_persisted_handler_type;
        typedef typename facade::host_info_disposing_info_type host_info_disposing_info_type;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::runtime_host_persisted_handler_type runtime_host_persisted_handler_type;
        typedef typename facade::runtime_host_disposing_info_type runtime_host_disposing_info_type;
        typedef typename facade::base_heap_provider_type base_heap_provider_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        typedef typename facade::runtime_host_provider_type runtime_host_provider_type;
        typedef typename facade::host_info_previous_type host_info_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::host_info_chain_type host_info_chain_type;

        BaseHostInfo()
        { }

        static host_info_type *CreateHost()
        {
            using namespace Urasandesu::Swathe::Utilities;
            
            TempPtr<host_info_type> pHost = NewHost();
            pHost.Persist();
            return pHost.Get();
        }

        runtime_host_type const *GetRuntime(std::wstring const &version) const
        {
            using namespace Urasandesu::Swathe::Utilities;
            
            if (version.empty())
                BOOST_THROW_EXCEPTION(SwatheArgumentException(L"The parameter must be non-empty.", L"version"));

            runtime_host_type *pExistingRuntime = NULL;
            if (!TryGetRuntime(version, pExistingRuntime))
            {
                TempPtr<runtime_host_type> pNewRuntime = NewRuntime(version);

                std::wstring const &corVersion = pNewRuntime->GetCORVersion();
                if (corVersion != version)
                {
                    std::wstring what;
                    what += L"The version '";
                    what += version;
                    what += L"' is not supported. For your information, this process runs at version '";
                    what += corVersion;
                    what += L"'.";
                    BOOST_THROW_EXCEPTION(SwatheNotSupportedException(what));
                }

                pNewRuntime.Persist();
                return pNewRuntime.Get();
            }
            else
            {
                return pExistingRuntime;
            }
        }
    
    private:
        friend typename runtime_host_persisted_handler_type;

        static Utilities::TempPtr<host_info_type> NewHost()
        {
            using namespace Urasandesu::Swathe::Utilities;

            host_info_type &hostInfo = SwatheStorage::Object<host_info_type>();
            host_info_provider_type &provider = hostInfo.ProviderOf<host_info_disposing_info_type>();
            TempPtr<host_info_type> pHostInfo = host_info_chain_type::NewRootObject<host_info_type>(provider);
            host_info_persisted_handler_type handler(&hostInfo);
            provider.AddPersistedHandler(pHostInfo, handler);
            return pHostInfo;
        }

        Utilities::TempPtr<runtime_host_type> NewRuntime(std::wstring const &version) const
        {
            using namespace Urasandesu::Swathe::Utilities;

            runtime_host_provider_type &provider = ProviderOf<runtime_host_disposing_info_type>();
            host_info_chain_type &chain = ChainFrom<host_info_previous_type>();
            TempPtr<runtime_host_type> pRuntime = chain.NewObject<runtime_host_type>(provider);
            runtime_host_persisted_handler_type handler(const_cast<this_type *>(this), version);
            provider.AddPersistedHandler(pRuntime, handler);
            return pRuntime;
        }

        bool TryGetRuntime(std::wstring const &version, runtime_host_type *&pExistingRuntime) const
        {
            if (m_versionToIndex.find(version) == m_versionToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_versionToIndex[version];
                runtime_host_provider_type &provider = ProviderOf<runtime_host_disposing_info_type>();
                pExistingRuntime = provider.GetObject(index);
                return true;
            }
        }

        mutable boost::unordered_map<std::wstring, SIZE_T> m_versionToIndex;
    };
    
    template class BaseHostInfo<>;





    namespace HostInfoDetail {

        template<
            class HostInfoApiHolder
        >    
        struct HostInfoPersistedHandlerFacade : 
            HostInfoFacade<HostInfoApiHolder>
        {
        };

    }   // namespace HostInfoDetail {
    
    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfoPersistedHandler
    {
    public:
        typedef HostInfoDetail::HostInfoPersistedHandlerFacade<HostInfoApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::host_info_persisted_handler_type host_info_persisted_handler_type;
        typedef typename facade::host_info_disposing_info_type host_info_disposing_info_type;
        typedef typename facade::base_heap_provider_type base_heap_provider_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        typedef typename facade::host_info_previous_type host_info_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::host_info_chain_type host_info_chain_type;
        
        typedef Utilities::TempPtr<host_info_type> sender_type;

        BaseHostInfoPersistedHandler(host_info_type *pHostInfo) : 
            m_pHostInfo(pHostInfo)
        { }

        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pHostInfo = *pSender;

            host_info_provider_type &provider = m_pHostInfo->ProviderOf<host_info_disposing_info_type>();
            provider.RegisterObject(pHostInfo);
        }

    private:
        host_info_type *m_pHostInfo;
    };
    
    template class BaseHostInfoPersistedHandler<>;

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // URASANDESU_SWATHE_HOSTING_BASEHOSTINFO_HPP