#pragma once
#ifndef URASANDESU_SWATHE_FUSION_BASEFUSIONINFO_HPP
#define URASANDESU_SWATHE_FUSION_BASEFUSIONINFO_HPP

#ifndef URASANDESU_SWATHE_FUSION_INTERFACES_FUSIONINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Fusion/Interfaces/FusionInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/Swathe/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASEFUSIONINFOFWD_HPP
#include <Urasandesu/Swathe/Fusion/BaseFusionInfoFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct FusionInfoApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::FusionInfoApiHolderLabel, ApiLabel>
    {
    };

    namespace FusionInfoDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Fusion::Interfaces;

        template<
            class FusionInfoApiHolder
        >    
        struct FusionInfoFacade
        {
            typedef typename FusionInfoApiAt<FusionInfoApiHolder, IAssemblyCache>::type com_assembly_cache_type;
            typedef typename FusionInfoApiAt<FusionInfoApiHolder, RuntimeHostLabel>::type runtime_host_type;
            typedef typename FusionInfoApiAt<FusionInfoApiHolder, FusionInfoLabel>::type fusion_info_type;
            typedef typename FusionInfoApiAt<FusionInfoApiHolder, AssemblyInfoLabel>::type assembly_info_type;


            typedef mpl::vector<
                assembly_info_type
            > providing_types;
            typedef SmartHeapProvider<providing_types> base_heap_provider_type;


            typedef typename base_heap_provider_type::provider_of<assembly_info_type>::type assembly_info_provider_type;


            typedef runtime_host_type fusion_info_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<fusion_info_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<fusion_info_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<fusion_info_previous_type>::type fusion_info_chain_type;
        };

    }   // namespace FusionInfoDetail {

    template<
        class FusionInfoApiHolder
    >    
    class BaseFusionInfo : 
        public FusionInfoDetail::FusionInfoFacade<FusionInfoApiHolder>::base_ptr_chain_type,
        public FusionInfoDetail::FusionInfoFacade<FusionInfoApiHolder>::base_heap_provider_type,
        public SimpleDisposable
    {
    public:
        typedef BaseFusionInfo<FusionInfoApiHolder> this_type;

        typedef FusionInfoDetail::FusionInfoFacade<FusionInfoApiHolder> facade;
        typedef typename facade::com_assembly_cache_type com_assembly_cache_type;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::assembly_info_type assembly_info_type;
        typedef typename facade::assembly_info_provider_type assembly_info_provider_type;


        BaseFusionInfo()
        { }

        Utilities::AutoPtr<assembly_info_type> QueryAssemblyInfo(
                  AssemblyQueryTypes const &type, std::wstring const &assemblyName) const
        {
            using namespace boost::filesystem;

            this_type *pMutableThis = const_cast<this_type *>(this);

            WCHAR buffer[MAX_PATH] = { 0 };
            ASSEMBLY_INFO asmInfo;
            ::ZeroMemory(&asmInfo, sizeof(ASSEMBLY_INFO));
            asmInfo.cbAssemblyInfo = sizeof(ASSEMBLY_INFO);
            asmInfo.pszCurrentAssemblyPathBuf = buffer;
            asmInfo.cchBuf = MAX_PATH;
            HRESULT hr = pMutableThis->GetCOMAssemblyCache().QueryAssemblyInfo(type.Value(), assemblyName.c_str(), &asmInfo);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(SwatheCOMException(hr));

            ULONGLONG assemblySizeInKB = 0;
            ::memcpy_s(&assemblySizeInKB, sizeof(ULONGLONG), 
                       &asmInfo.uliAssemblySizeInKB, sizeof(ULARGE_INTEGER));

            assembly_info_provider_type &provider = ProviderOf<assembly_info_type>();
            AutoPtr<assembly_info_type> pAsmInfo = provider.NewObject();
            pAsmInfo->SetAssemblySizeInKB(assemblySizeInKB);
            pAsmInfo->SetAssemblyPath(asmInfo.pszCurrentAssemblyPathBuf);
            return pAsmInfo;
        }

    private:
        friend typename runtime_host_type;

        com_assembly_cache_type &GetCOMAssemblyCache()
        {
            using namespace boost::filesystem;
            
            if (m_pComAsmCache.p == NULL)
            {
                runtime_host_type *pRuntimeHost = MapFirst<runtime_host_type>();

                path const &corSysDirPath = pRuntimeHost->GetCORSystemDirectoryPath();
                path fusionPath = corSysDirPath;
                fusionPath /= L"fusion.dll";

                HMODULE hmodCorEE = ::LoadLibraryW(fusionPath.c_str());
                if (hmodCorEE == NULL)
                    BOOST_THROW_EXCEPTION(SwatheSystemException(::GetLastError()));
                BOOST_SCOPE_EXIT((hmodCorEE))
                {
                    ::FreeLibrary(hmodCorEE);
                }
                BOOST_SCOPE_EXIT_END

                typedef HRESULT (__stdcall *CreateAsmCachePtr)(IAssemblyCache **ppAsmCache, DWORD dwReserved);

                CreateAsmCachePtr pfnCreateAsmCache = NULL;
                pfnCreateAsmCache = reinterpret_cast<CreateAsmCachePtr>(
                                                ::GetProcAddress(hmodCorEE, "CreateAssemblyCache"));
                if (!pfnCreateAsmCache)
                    BOOST_THROW_EXCEPTION(SwatheSystemException(::GetLastError()));
        
                HRESULT hr = pfnCreateAsmCache(&m_pComAsmCache, 0);
                if (FAILED(hr)) 
                    BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            }
            return *m_pComAsmCache;
        }

        mutable ATL::CComPtr<com_assembly_cache_type> m_pComAsmCache;
    };





    namespace FusionInfoDetail {

        template<
            class FusionInfoApiHolder
        >    
        struct FusionInfoPersistedHandlerFacade : 
            FusionInfoFacade<FusionInfoApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(FusionInfoProvider, fusion_info_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(FusionInfoProvider, fusion_info_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(FusionInfoProvider, runtime_host_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(FusionInfoProvider, runtime_host_type), 
                mpl::void_
            >::type fusion_info_provider_type;
        };

    }   // namespace FusionInfoDetail {

    template<
        class FusionInfoApiHolder
    >    
    class BaseFusionInfoPersistedHandler
    {
    public:
        typedef FusionInfoDetail::FusionInfoPersistedHandlerFacade<FusionInfoApiHolder> facade;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::fusion_info_type fusion_info_type;
        typedef typename facade::fusion_info_provider_type fusion_info_provider_type;

        typedef Utilities::TempPtr<fusion_info_type> sender_type;

        BaseFusionInfoPersistedHandler(runtime_host_type *pRuntimeHost) : 
            m_pRuntimeHost(pRuntimeHost)
        { 
            _ASSERTE(pRuntimeHost != NULL);
        }
                
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pFuInfo = *pSender;
            fusion_info_provider_type &provider = m_pRuntimeHost->ProviderOf<fusion_info_type>();
            TypeInfo key = mpl::identity<fusion_info_type>();
            m_pRuntimeHost->m_infoToIndex[key] = provider.RegisterObject(pFuInfo);
        }
                
    private:                
        runtime_host_type *m_pRuntimeHost;
    };
        
}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_BASEFUSIONINFO_HPP