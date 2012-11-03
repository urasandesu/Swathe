#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataApiHolderLabel, ApiLabel>
    {
    };

    namespace AssemblyMetadataDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::Swathe::Fusion::Interfaces;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        template<
            class AssemblyMetadataApiHolder
        >    
        struct AssemblyMetadataFacade
        {
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, FusionInfoLabel>::type fusion_info_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, AssemblyInfoLabel>::type assembly_info_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, MetadataDispenserLabel>::type metadata_dispenser_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, AssemblyMetadataLabel>::type assembly_metadata_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, ModuleMetadataLabel>::type module_metadata_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, ModuleMetadataPersistedHandlerLabel>::type module_metadata_persisted_handler_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IModuleMetadataHashLabel>::type i_module_metadata_hash_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IModuleMetadataEqualToLabel>::type i_module_metadata_equal_to_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, TypeMetadataLabel>::type type_metadata_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;        
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;

            //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
            //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;        
            //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, RuntimeHostLabel>::type runtime_host_type;
            //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, AssemblyMetadataLabel>::type metadata_info_type;

            //typedef mpl::vector<
            //    /*DisposingInfo<metadata_dispenser_type, metadata_dispenser_persisted_handler_type>*/
            //> disposing_info_types;
            //typedef DisposableHeapProvider<disposing_info_types> base_heap_provider_type;


            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ModuleMetadataProvider, module_metadata_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ModuleMetadataProvider, module_metadata_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(ModuleMetadataProvider, metadata_dispenser_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(ModuleMetadataProvider, metadata_dispenser_type), 
                mpl::void_
            >::type module_metadata_provider_type;
            //typedef typename base_heap_provider_type::provider_of<metadata_dispenser_type>::type metadata_dispenser_provider_type;


            typedef metadata_dispenser_type assembly_metadata_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<assembly_metadata_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<assembly_metadata_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<assembly_metadata_previous_type>::type assembly_metadata_chain_type;


            typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type base_type;
        };

    }   // namespace AssemblyMetadataDetail {

    template<
        class AssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadata : 
        public AssemblyMetadataDetail::AssemblyMetadataFacade<AssemblyMetadataApiHolder>::base_ptr_chain_type, 
        public AssemblyMetadataDetail::AssemblyMetadataFacade<AssemblyMetadataApiHolder>::base_type, 
        //public SmartPtrChain<
        //    BaseAssemblyMetadata<AssemblyMetadataApiHolder>,
        //    boost::mpl::vector<
        //        SmartPtrChainInfo<typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type>
        //    >
        //>,
        //public AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseAssemblyMetadata<AssemblyMetadataApiHolder> this_type;

        typedef AssemblyMetadataDetail::AssemblyMetadataFacade<AssemblyMetadataApiHolder> facade;
        typedef typename facade::fusion_info_type fusion_info_type;
        typedef typename facade::assembly_info_type assembly_info_type;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::assembly_metadata_type assembly_metadata_type;
        typedef typename facade::module_metadata_type module_metadata_type;
        typedef typename facade::module_metadata_persisted_handler_type module_metadata_persisted_handler_type;
        typedef typename facade::i_module_metadata_hash_type i_module_metadata_hash_type;
        typedef typename facade::i_module_metadata_equal_to_type i_module_metadata_equal_to_type;
        typedef typename facade::type_metadata_type type_metadata_type;
        typedef typename facade::com_meta_data_assembly_import_type com_meta_data_assembly_import_type;
        typedef typename facade::com_meta_data_import_type com_meta_data_import_type;
        typedef typename facade::com_meta_data_dispenser_type com_meta_data_dispenser_type;
        typedef typename facade::module_metadata_provider_type module_metadata_provider_type;
        typedef typename facade::assembly_metadata_previous_type assembly_metadata_previous_type;
        typedef typename facade::assembly_metadata_chain_type assembly_metadata_chain_type;
        typedef typename facade::base_type base_type;

        //typedef int type_metadata_type;
        typedef int method_metadata_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;        
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Fusion::Interfaces::FusionInfoLabel>::type fusion_info_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Fusion::Interfaces::AssemblyInfoLabel>::type assembly_info_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IModuleMetadataHashLabel>::type i_module_metadata_hash_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IModuleMetadataEqualToLabel>::type i_module_metadata_equal_to_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        //typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;        
        
        //CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Asm, module_metadata_provider_type);
        //CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Asm, module_metadata_provider_type);
        //typedef typename boost::mpl::eval_if<
        //    CPP_ANONYM_HAS_MEMBER_TYPE(Asm, module_metadata_provider_type, typename base_type::metadata_dispenser_type), 
        //    CPP_ANONYM_GET_MEMBER_TYPE(Asm, module_metadata_provider_type, typename base_type::metadata_dispenser_type), 
        //    boost::mpl::void_
        //>::type module_metadata_provider_type;
        //typedef int module_metadata_provider_type;
        
        //typedef typename chain_from<typename base_type::metadata_dispenser_type>::type assembly_metadata_chain_type; 

        BaseAssemblyMetadata() : 
            m_mda(mdAssemblyNil),
            m_openFlags(ofRead)
        { }

        mdAssembly GetToken() const
        {
            if (m_mda == mdAssemblyNil)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                com_meta_data_assembly_import_type &comMetaAsmImp = pMutableThis->GetCOMMetaDataAssemblyImport();
                HRESULT hr = comMetaAsmImp.GetAssemblyFromScope(&m_mda);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            }

            return m_mda;
        }
        
        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_name;
        }
        
        Utilities::AutoPtr<typename base_type::strong_name_key_type const> GetStrongNameKey() const
        {
            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
        }
        
        typename base_type::metadata_dispenser_type const *GetResolutionScope() const
        {
            return MapFirst<typename base_type::metadata_dispenser_type>();
        }

        module_metadata_type const *GetModule(std::wstring const &name) const
        {
            Utilities::TempPtr<module_metadata_type> pMod = NewModule(name);

            module_metadata_type *pExistingMod = NULL;
            if (!TryGetModule(*pMod, pExistingMod))
            {
                pMod.Persist();
                return pMod.Get();
            }
            else
            {
                return pExistingMod;
            }
        }

    private:
        friend typename base_type::metadata_dispenser_type;
        friend typename module_metadata_type;
        friend typename module_metadata_persisted_handler_type;
        friend typename type_metadata_type;
        friend typename method_metadata_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        Utilities::TempPtr<module_metadata_type> NewModule(std::wstring const &name) const
        {
            using namespace Urasandesu::Swathe::Utilities;

            metadata_dispenser_type const *pDisp = MapFirst<metadata_dispenser_type>();
            module_metadata_provider_type &provider = pDisp->ProviderOf<module_metadata_type>();
            assembly_metadata_chain_type &chain = ChainFrom<typename base_type::metadata_dispenser_type>();
            TempPtr<module_metadata_type> pMod = chain.NewObject<module_metadata_type>(provider);
            pMod->SetName(name);
            module_metadata_persisted_handler_type handler(const_cast<this_type *>(this));
            provider.AddPersistedHandler(pMod, handler);
            //struct pMod_Persisted
            //{
            //    typedef TempPtr<module_metadata_type> sender_type;

            //    pMod_Persisted(this_type &this_) : 
            //        m_pThis(&this_)
            //    { }
            //    
            //    void operator()(sender_type *pSender, void *pArg)
            //    {
            //        sender_type &pMod = *pSender;
            //        metadata_dispenser_type const *pDisp = m_pThis->MapFirst<metadata_dispenser_type>();
            //        module_metadata_provider_type &provider = pDisp->ProviderOf<module_metadata_type>();
            //        m_pThis->m_modToIndex[pMod.Get()] = provider.RegisterObject(pMod);
            //    }
            //    
            //    this_type *m_pThis;
            //};
            //pMod.AddPersistedHandler(pMod_Persisted(const_cast<this_type &>(*this)));
            return pMod;
        }

        bool TryGetModule(module_metadata_type const &keyMod, module_metadata_type *&pExistingMod) const
        {
            if (m_modToIndex.find(&keyMod) == m_modToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_modToIndex[&keyMod];
                metadata_dispenser_type const *pDisp = MapFirst<metadata_dispenser_type>();
                module_metadata_provider_type &provider = pDisp->ProviderOf<module_metadata_type>();
                pExistingMod = provider.GetObject(index);
                return true;
            }
        }

        com_meta_data_assembly_import_type &GetCOMMetaDataAssemblyImport()
        {
            if (m_pComMetaAsmImp.p == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                
                com_meta_data_import_type &comMetaImp = pMutableThis->GetCOMMetaDataImport();
                HRESULT hr = comMetaImp.QueryInterface(IID_IMetaDataAssemblyImport, 
                                               reinterpret_cast<void **>(&m_pComMetaAsmImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            }
            return *m_pComMetaAsmImp;
        }

        com_meta_data_import_type &GetCOMMetaDataImport()
        {
            namespace fs = boost::filesystem;

            if (m_pComMetaImp.p == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                metadata_dispenser_type *pMetaDisp = NULL;
                pMetaDisp = pMutableThis->MapFirst<metadata_dispenser_type>();

                com_meta_data_dispenser_type &comMetaDisp = pMetaDisp->GetCOMMetaDataDispenser();

                fs::path const &asmPath = GetAssemblyFilePath();
                DWORD openFlags = GetOpenFlags();
                REFIID riid = GetCOMMetaDataImportIID();
                HRESULT hr = comMetaDisp.OpenScope(asmPath.c_str(), openFlags, 
                                                   riid, reinterpret_cast<IUnknown **>(&m_pComMetaImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            }
            return *m_pComMetaImp.p;
        }

        boost::filesystem::path const &GetAssemblyFilePath() const
        {
            using namespace Urasandesu::Swathe::Fusion;

            if (m_asmPath.empty())
            {
                _ASSERTE(!m_name.empty());

                fusion_info_type const *pFuInfo = Map<fusion_info_type>();
                AutoPtr<assembly_info_type> pAsmInfo;
                pAsmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, m_name);
                m_asmPath = pAsmInfo->GetAssemblyPath();
            }
            return m_asmPath;
        }

        void SetAssemblyFilePath(boost::filesystem::path const &asmPath)
        {
            _ASSERTE(!asmPath.empty());
            _ASSERTE(m_asmPath.empty());
            
            m_asmPath = asmPath;
        }

        DWORD GetOpenFlags() const
        {
            return m_openFlags;
        }

        void SetOpenFlags(DWORD openFlags)
        {
            _ASSERTE(openFlags != ofRead);
            _ASSERTE(m_openFlags == ofRead);

            m_openFlags = openFlags;
        }

        REFIID GetCOMMetaDataImportIID()
        {
            return IID_IMetaDataImport2;
        }

        mutable mdAssembly m_mda;
        std::wstring m_name;
        mutable boost::filesystem::path m_asmPath;
        DWORD m_openFlags;
        mutable ATL::CComPtr<com_meta_data_assembly_import_type> m_pComMetaAsmImp;
        mutable ATL::CComPtr<com_meta_data_import_type> m_pComMetaImp;
        mutable boost::unordered_map<module_metadata_type const *, 
                                     SIZE_T, 
                                     i_module_metadata_hash_type, 
                                     i_module_metadata_equal_to_type> m_modToIndex;
    };





    namespace AssemblyMetadataDetail {

        template<
            class AssemblyMetadataApiHolder
        >    
        struct AssemblyMetadataPersistedHandlerFacade : 
            AssemblyMetadataFacade<AssemblyMetadataApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(AssemblyMetadataProvider, assembly_metadata_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(AssemblyMetadataProvider, assembly_metadata_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(AssemblyMetadataProvider, metadata_dispenser_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(AssemblyMetadataProvider, metadata_dispenser_type), 
                mpl::void_
            >::type assembly_metadata_provider_type;
        };

    }   // namespace AssemblyMetadataDetail {

    template<
        class AssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadataPersistedHandler
    {
    public:
        typedef AssemblyMetadataDetail::AssemblyMetadataPersistedHandlerFacade<AssemblyMetadataApiHolder> facade;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::assembly_metadata_type assembly_metadata_type;
        typedef typename facade::assembly_metadata_provider_type assembly_metadata_provider_type;

        typedef Utilities::TempPtr<assembly_metadata_type> sender_type;

        BaseAssemblyMetadataPersistedHandler(metadata_dispenser_type *pDisp) : 
            m_pDisp(pDisp)
        {
            _ASSERTE(pDisp != NULL); 
        }
        
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pAsm = *pSender;            
            assembly_metadata_provider_type &provider = m_pDisp->ProviderOf<assembly_metadata_type>();
            m_pDisp->m_asmToIndex[pAsm.Get()] = provider.RegisterObject(pAsm);
        }

    private:        
        metadata_dispenser_type *m_pDisp;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYMETADATA_HPP