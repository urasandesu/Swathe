#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
//#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/Swathe/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_OBJECTTAG_H
//#include <Urasandesu/Swathe/ObjectTag.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataApiHolderLabel.hpp>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseModuleNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleNameMetadataGeneratorApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleNameMetadataGeneratorApiHolder
    >    
    class BaseModuleNameMetadataGenerator : 
        public ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::IModuleNameMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseModuleNameMetadataGenerator<ModuleNameMetadataGeneratorApiHolder> this_type;
        typedef typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::IModuleNameMetadataLabel>::type base_type;

        typedef typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::AssemblyMetadataGeneratorLabel>::type assembly_metadata_generator_type;
        typedef typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::AssemblyNameMetadataGeneratorLabel>::type assembly_name_metadata_generator_type;
        typedef typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
        typedef typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::ModuleMetadataGeneratorLabel>::type module_metadata_generator_type;

        typedef ObjectTag<type_name_metadata_generator_type, QuickHeap> type_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<type_name_metadata_generator_obj_tag_type>::type type_name_metadata_generator_heap_type;

        BaseModuleNameMetadataGenerator() : 
            m_pAsmNameGenAsScope(NULL), 
            m_pAsmGenAsScope(NULL),
            m_nameInitialized(false),
            m_pResolvedModGen(NULL)
        { }

        void Init(assembly_name_metadata_generator_type &asmNameGenAsScope) const
        {
            _ASSERTE(m_pAsmNameGenAsScope == NULL && m_pAsmGenAsScope == NULL);
            m_pAsmNameGenAsScope = &asmNameGenAsScope;
        }

        void Init(assembly_metadata_generator_type &asmGenAsScope) const
        {
            _ASSERTE(m_pAsmNameGenAsScope == NULL && m_pAsmGenAsScope == NULL);
            m_pAsmGenAsScope = &asmGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            _ASSERTE(m_pAsmNameGenAsScope != NULL || m_pAsmGenAsScope != NULL);
            if (m_pAsmNameGenAsScope != NULL)
                return m_pAsmNameGenAsScope->Map<T>();
            else
                return m_pAsmGenAsScope->GetAssemblyNameCore()->Map<T>();
        }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                m_nameInitialized = true;
            }
            return m_name;
        }

        typename base_type::i_assembly_name_metadata_type const &GetResolutionScope() const
        {
            return Map<assembly_name_metadata_generator_type>();
        }

        typename base_type::i_module_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        type_name_metadata_generator_type *NewTypeNameGenerator(std::wstring const &name, TypeAttributes const &attr)
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            type_name_metadata_generator_type *pTypeNameMetaGen = NULL;
            pTypeNameMetaGen = pMutableThis->TypeNameMetadataGeneratorHeap().New();
            pTypeNameMetaGen->Init(*pMutableThis);
            pTypeNameMetaGen->SetName(name);
            pTypeNameMetaGen->SetAttribute(attr);
            return pTypeNameMetaGen;
        }

    private:
        friend typename assembly_name_metadata_generator_type;
        friend typename module_metadata_generator_type;
        friend typename type_name_metadata_generator_type;

        type_name_metadata_generator_heap_type &TypeNameMetadataGeneratorHeap()
        {
            return Of<type_name_metadata_generator_obj_tag_type>();
        }
        
        type_name_metadata_generator_heap_type const &TypeNameMetadataGeneratorHeap() const
        {
            return Of<type_name_metadata_generator_obj_tag_type>();
        }

        module_metadata_generator_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        module_metadata_generator_type &ResolveCore()
        {
            if (m_pAsmGenAsScope == NULL)
                m_pAsmGenAsScope = &Map<assembly_name_metadata_generator_type>().ResolveCore();

            if (m_pResolvedModGen == NULL)
            {
                m_pResolvedModGen = m_pAsmGenAsScope->DefineModule(*this);
            }
            return *m_pResolvedModGen;
        }


        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        mutable assembly_name_metadata_generator_type *m_pAsmNameGenAsScope;
        mutable assembly_metadata_generator_type *m_pAsmGenAsScope;
        mutable bool m_nameInitialized;
        mutable std::wstring m_name;
        module_metadata_generator_type *m_pResolvedModGen;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP