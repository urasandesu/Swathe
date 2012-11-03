#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOST_HPP
#define URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOST_HPP

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/RuntimeHostApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/Swathe/Hosting/BaseRuntimeHostFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting {

    struct RuntimeHostChainMapper : 
        SmartPtrChainMapper
    {
        template<
            class T,
            class Previous,
            class Current
        >
        static T *MapFirstAncestor(Current &current) 
        { 
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static T *MapAncestor(Current &current) 
        { 
            return current.GetInfo<T>();
        }
    };

    template<class ApiCartridgesHolder, class ApiLabel>
    struct RuntimeHostApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::RuntimeHostApiHolderLabel, ApiLabel>
    {
    };

    namespace RuntimeHostDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        template<
            class RuntimeHostApiHolder
        >    
        struct RuntimeHostFacade
        {
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, HostInfoLabel>::type host_info_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, RuntimeHostLabel>::type runtime_host_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_type;
            typedef DisposingInfo<runtime_host_type, runtime_host_persisted_handler_type> runtime_host_disposing_info_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, MetadataInfoLabel>::type metadata_info_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, MetadataInfoPersistedHandlerLabel>::type metadata_info_persisted_handler_type;
            typedef DisposingInfo<metadata_info_type, metadata_info_persisted_handler_type> metadata_info_disposing_info_type;
            
            
            typedef DisposableHeapProvider<
                metadata_info_disposing_info_type
            > base_heap_provider_type;
            
            
            typedef typename base_heap_provider_type::provider_of<metadata_info_disposing_info_type>::type metadata_info_provider_type;
            
            
            typedef host_info_type runtime_host_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<runtime_host_previous_type, RuntimeHostChainMapper>
            > chain_info_types;
            typedef SmartPtrChain<runtime_host_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<runtime_host_previous_type>::type runtime_host_chain_type;
        };
        
    }   // namespace RuntimeHostDetail {

    template<
        class RuntimeHostApiHolder
    >    
    class BaseRuntimeHost : 
        public RuntimeHostDetail::RuntimeHostFacade<RuntimeHostApiHolder>::base_ptr_chain_type,
        public RuntimeHostDetail::RuntimeHostFacade<RuntimeHostApiHolder>::base_heap_provider_type,
        public SimpleDisposable
    {
    public:
        typedef BaseRuntimeHost<RuntimeHostApiHolder> this_type;
        
        typedef RuntimeHostDetail::RuntimeHostFacade<RuntimeHostApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::runtime_host_persisted_handler_type runtime_host_persisted_handler_type;
        typedef typename facade::runtime_host_disposing_info_type runtime_host_disposing_info_type;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_info_persisted_handler_type metadata_info_persisted_handler_type;
        typedef typename facade::metadata_info_disposing_info_type metadata_info_disposing_info_type;
        typedef typename facade::metadata_info_provider_type metadata_info_provider_type;        
        typedef typename facade::runtime_host_previous_type runtime_host_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::runtime_host_chain_type runtime_host_chain_type;

        BaseRuntimeHost() : 
            m_corVersionInitialized(false)
        { }

        std::wstring const &GetCORVersion() const
        {
            CheckDisposed();

            if (!m_corVersionInitialized)
            {
                WCHAR buffer[MAX_PATH] = { 0 };
                DWORD bufferSize = MAX_PATH - 1;
                DWORD length = 0;

#pragma warning(push)
#pragma warning(disable: 4996)
                HRESULT hr = ::GetCORVersion(buffer, bufferSize, &length);
#pragma warning(pop)
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
                
                m_corVersion = buffer;

                m_corVersionInitialized = true;
            }
            return m_corVersion;
        }

        template<class Info>
        Info *GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            using namespace Urasandesu::Swathe::Utilities;

            BOOST_MPL_ASSERT((is_provided_object<Info>));
            typedef typename first_provider_of<Info>::type InfoProvider;

            Info *pExistingInfo = NULL;
            if (!TryGetInfo<Info>(pExistingInfo))
            {
                TempPtr<Info> pNewInfo = NewInfo<Info>();
                pNewInfo.Persist();
                return pNewInfo.Get();
            }
            else
            {
                return pExistingInfo;
            }
        }

    private:
        friend typename metadata_info_persisted_handler_type;

        template<class Info>
        Utilities::TempPtr<Info> NewInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            using namespace Urasandesu::Swathe::Utilities;

            BOOST_MPL_ASSERT((is_provided_object<Info>));
            typedef typename first_providing_persisted_handler<Info>::type InfoPersistedHandler;
            typedef typename first_provider_of<Info>::type InfoProvider;

            InfoProvider &provider = FirstProviderOf<Info>();
            runtime_host_chain_type &chain = ChainFrom<runtime_host_previous_type>();
            TempPtr<Info> pInfo = chain.NewObject<Info>(provider);
            InfoPersistedHandler handler(const_cast<this_type *>(this));
            provider.AddPersistedHandler(pInfo, handler);
            return pInfo;
        }

        template<class Info>
        bool TryGetInfo(Info *&pExistingInfo) const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            using namespace Urasandesu::Swathe::Utilities;

            BOOST_MPL_ASSERT((is_provided_object<Info>));
            typedef typename first_provider_of<Info>::type InfoProvider;

            TypeInfo key = mpl::identity<Info>();
            if (m_infoToIndex.find(key) == m_infoToIndex.end())
            {
                return false;
            }
            else
            {
                SIZE_T index = m_infoToIndex[key];
                InfoProvider &provider = FirstProviderOf<Info>();
                pExistingInfo = provider.GetObject(index);
                return true;
            }
        }

        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable boost::unordered_map<Utilities::TypeInfo, SIZE_T, Utilities::TypeInfoHash, Utilities::TypeInfoEqualTo> m_infoToIndex;
    };





    namespace RuntimeHostDetail {

        template<
            class RuntimeHostApiHolder
        >    
        struct RuntimeHostPersistedHandlerFacade : 
            RuntimeHostFacade<RuntimeHostApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(RuntimeHostProvider, runtime_host_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(RuntimeHostProvider, runtime_host_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(RuntimeHostProvider, host_info_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(RuntimeHostProvider, host_info_type), 
                mpl::void_
            >::type runtime_host_provider_type;
        };

    }   // namespace RuntimeHostDetail {

    template<
        class RuntimeHostApiHolder
    >    
    class BaseRuntimeHostPersistedHandler
    {
    public:
        typedef RuntimeHostDetail::RuntimeHostPersistedHandlerFacade<RuntimeHostApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::runtime_host_persisted_handler_type runtime_host_persisted_handler_type;
        typedef typename facade::runtime_host_disposing_info_type runtime_host_disposing_info_type;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_info_persisted_handler_type metadata_info_persisted_handler_type;
        typedef typename facade::metadata_info_disposing_info_type metadata_info_disposing_info_type;
        typedef typename facade::runtime_host_previous_type runtime_host_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::runtime_host_chain_type runtime_host_chain_type;
        typedef typename facade::runtime_host_provider_type runtime_host_provider_type;

        typedef Utilities::TempPtr<runtime_host_type> sender_type;

        BaseRuntimeHostPersistedHandler(host_info_type *pHostInfo, std::wstring const &version) : 
            m_pHostInfo(pHostInfo),
            m_version(version)
        { }
                
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pRuntime = *pSender;
            runtime_host_provider_type &provider = m_pHostInfo->ProviderOf<runtime_host_disposing_info_type>();
            m_pHostInfo->m_versionToIndex[m_version] = provider.RegisterObject(pRuntime);
        }

    private:                
        host_info_type *m_pHostInfo;
        std::wstring m_version;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // URASANDESU_SWATHE_HOSTING_BASERUNTIMEHOST_HPP