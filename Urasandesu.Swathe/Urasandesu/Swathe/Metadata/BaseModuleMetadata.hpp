#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMODULEMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASEMODULEMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMODULEMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseModuleMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleMetadataApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleMetadataApiHolderLabel, ApiLabel>
    {
    };

    namespace ModuleMetadataDetail {

        namespace mpl = boost::mpl;
        //using namespace Urasandesu::Swathe::Fusion::Interfaces;
        //using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        template<
            class ModuleMetadataApiHolder
        >    
        struct ModuleMetadataFacade
        {
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, MetadataDispenserLabel>::type metadata_dispenser_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, AssemblyMetadataLabel>::type assembly_metadata_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, ModuleMetadataLabel>::type module_metadata_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, TypeMetadataLabel>::type type_metadata_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, TypeMetadataPersistedHandlerLabel>::type type_metadata_persisted_handler_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, ITypeMetadataLabel>::type i_type_metadata_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, ITypeMetadataHashLabel>::type i_type_metadata_hash_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, ITypeMetadataEqualToLabel>::type i_type_metadata_equal_to_type;
            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;


            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeMetadataProvider, type_metadata_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeMetadataProvider, type_metadata_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(TypeMetadataProvider, metadata_dispenser_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(TypeMetadataProvider, metadata_dispenser_type), 
                mpl::void_
            >::type type_metadata_provider_type;


            typedef assembly_metadata_type module_metadata_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<module_metadata_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<module_metadata_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<module_metadata_previous_type>::type module_metadata_chain_type;


            typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type base_type;
        };

    }   // namespace ModuleMetadataDetail {

    template<
        class ModuleMetadataApiHolder
    >    
    class BaseModuleMetadata : 
        public ModuleMetadataDetail::ModuleMetadataFacade<ModuleMetadataApiHolder>::base_ptr_chain_type, 
        public ModuleMetadataDetail::ModuleMetadataFacade<ModuleMetadataApiHolder>::base_type, 
        //public SmartPtrChain<
        //    BaseModuleMetadata<ModuleMetadataApiHolder>,
        //    boost::mpl::vector<
        //        SmartPtrChainInfo<typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type>
        //    >
        //>,
        //public ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseModuleMetadata<ModuleMetadataApiHolder> this_type;

        typedef ModuleMetadataDetail::ModuleMetadataFacade<ModuleMetadataApiHolder> facade;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::assembly_metadata_type assembly_metadata_type;
        typedef typename facade::module_metadata_type module_metadata_type;
        typedef typename facade::type_metadata_type type_metadata_type;
        typedef typename facade::type_metadata_persisted_handler_type type_metadata_persisted_handler_type;
        typedef typename facade::i_type_metadata_type i_type_metadata_type;
        typedef typename facade::i_type_metadata_hash_type i_type_metadata_hash_type;
        typedef typename facade::i_type_metadata_equal_to_type i_type_metadata_equal_to_type;
        typedef typename facade::com_meta_data_import_type com_meta_data_import_type;
        typedef typename facade::type_metadata_provider_type type_metadata_provider_type;
        typedef typename facade::module_metadata_previous_type module_metadata_previous_type;
        typedef typename facade::module_metadata_chain_type module_metadata_chain_type;
        typedef typename facade::base_type base_type;

        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type base_type;
        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;
        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::ITypeMetadataEqualToLabel>::type i_type_metadata_equal_to_type;
        //typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        //CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Mod, type_metadata_provider_type);
        //CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Mod, type_metadata_provider_type);
        //typedef typename boost::mpl::eval_if<
        //    CPP_ANONYM_HAS_MEMBER_TYPE(Mod, type_metadata_provider_type, metadata_dispenser_type), 
        //    CPP_ANONYM_GET_MEMBER_TYPE(Mod, type_metadata_provider_type, metadata_dispenser_type), 
        //    boost::mpl::void_
        //>::type type_metadata_provider_type;
        //typedef int type_metadata_provider_type;

        //typedef typename chain_from<assembly_metadata_type>::type module_metadata_chain_type; 

        BaseModuleMetadata() : 
            m_mdm(mdModuleNil)
        { }

        mdModule GetToken() const
        {
            if (m_mdm == mdModuleNil)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                assembly_metadata_type *pAsm = pMutableThis->MapFirst<assembly_metadata_type>();

                com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.GetModuleFromScope(&m_mdm);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            }
            return m_mdm;
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_name;
        }

        typename base_type::i_assembly_metadata_type const *GetResolutionScope() const
        {
            return MapFirst<assembly_metadata_type>();
        }

        type_metadata_type const *GetType(std::wstring const &name) const
        {
            Utilities::TempPtr<type_metadata_type> pType = NewType(name);

            type_metadata_type *pExistingType = NULL;
            if (!TryGetType(*pType, pExistingType))
            {
                pType.Persist();
                return pType.Get();
            }
            else
            {
                return pExistingType;
            }
        }

    private:
        friend typename assembly_metadata_type;
        friend typename type_metadata_type;
        friend typename type_metadata_persisted_handler_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        Utilities::TempPtr<type_metadata_type> NewType(std::wstring const &name) const
        {
            Utilities::TempPtr<type_metadata_type> pType = NewTypeCore();
            pType->SetName(name);
            return pType;
        }

        Utilities::TempPtr<type_metadata_type> NewType(mdToken mdt) const
        {
            Utilities::TempPtr<type_metadata_type> pType = NewTypeCore();
            pType->SetToken(mdt);
            return pType;
        }

        Utilities::TempPtr<type_metadata_type> NewTypeCore() const
        {
            using namespace Urasandesu::Swathe::Utilities;

            metadata_dispenser_type const *pDisp = MapFirst<metadata_dispenser_type>();
            type_metadata_provider_type &provider = pDisp->ProviderOf<type_metadata_type>();
            module_metadata_chain_type &chain = ChainFrom<module_metadata_previous_type>();
            TempPtr<type_metadata_type> pType = chain.NewObject<type_metadata_type>(provider);
            type_metadata_persisted_handler_type handler(const_cast<this_type *>(this));
            provider.AddPersistedHandler(pType, handler);
            return pType;
        }

        bool TryGetType(type_metadata_type const &keyType, type_metadata_type *&pExistingType) const
        {
            if (m_typeToIndex.find(&keyType) == m_typeToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_typeToIndex[&keyType];
                metadata_dispenser_type const *pDisp = MapFirst<metadata_dispenser_type>();
                type_metadata_provider_type &provider = pDisp->ProviderOf<type_metadata_type>();
                pExistingType = provider.GetObject(index);
                return true;
            }
        }

        mutable mdModule m_mdm;
        std::wstring m_name;
        mutable boost::unordered_map<type_metadata_type const *, 
                                     SIZE_T, 
                                     i_type_metadata_hash_type, 
                                     i_type_metadata_equal_to_type> m_typeToIndex;
    };





    namespace ModuleMetadataDetail {

        template<
            class ModuleMetadataApiHolder
        >    
        struct ModuleMetadataPersistedHandlerFacade : 
            ModuleMetadataFacade<ModuleMetadataApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ModuleMetadataProvider, module_metadata_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ModuleMetadataProvider, module_metadata_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(ModuleMetadataProvider, metadata_dispenser_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(ModuleMetadataProvider, metadata_dispenser_type), 
                mpl::void_
            >::type module_metadata_provider_type;
        };

    }   // namespace ModuleMetadataDetail {

    template<
        class ModuleMetadataApiHolder
    >    
    class BaseModuleMetadataPersistedHandler
    {
    public:
        typedef ModuleMetadataDetail::ModuleMetadataPersistedHandlerFacade<ModuleMetadataApiHolder> facade;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::assembly_metadata_type assembly_metadata_type;
        typedef typename facade::module_metadata_type module_metadata_type;
        typedef typename facade::module_metadata_provider_type module_metadata_provider_type;

        typedef Utilities::TempPtr<module_metadata_type> sender_type;

        BaseModuleMetadataPersistedHandler(assembly_metadata_type *pAsm) : 
            m_pAsm(pAsm)
        { }
        
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pMod = *pSender;
            metadata_dispenser_type const *pDisp = m_pAsm->MapFirst<metadata_dispenser_type>();
            module_metadata_provider_type &provider = pDisp->ProviderOf<module_metadata_type>();
            m_pAsm->m_modToIndex[pMod.Get()] = provider.RegisterObject(pMod);
        }
    
    private:
        assembly_metadata_type *m_pAsm;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMODULEMETADATA_HPP