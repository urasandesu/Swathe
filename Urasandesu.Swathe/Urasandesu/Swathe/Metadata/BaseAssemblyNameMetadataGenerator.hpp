#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_SWATHE_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/Swathe/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_OBJECTTAG_H
//#include <Urasandesu/Swathe/ObjectTag.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
//#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_UTILITIES_STACKALLOCATOR_H
//#include <Urasandesu/Swathe/Utilities/StackAllocator.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
//#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
//#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYNAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyNameMetadataApiHolderLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYINFO_H
//#include <Urasandesu/Swathe/Fusion/AssemblyInfo.h>
//#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEKINDS_HPP
#include <Urasandesu/Swathe/Hosting/PortableExecutableKinds.hpp>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_IMAGEFILEMACHINE_HPP
#include <Urasandesu/Swathe/Hosting/ImageFileMachine.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseAssemblyNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyNameMetadataGeneratorApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyNameMetadataGeneratorApiHolder
    >    
    class BaseAssemblyNameMetadataGenerator : 
        public AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::IAssemblyNameMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyNameMetadataGenerator<AssemblyNameMetadataGeneratorApiHolder> this_type;
        typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::IAssemblyNameMetadataLabel>::type base_type;

        //typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::AssemblyMetadataGeneratorLabel>::type assembly_metadata_generator_type;
        typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;
        //typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        typedef ObjectTag<module_name_metadata_generator_type, QuickHeap> module_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<module_name_metadata_generator_obj_tag_type>::type module_name_metadata_generator_heap_type;

        BaseAssemblyNameMetadataGenerator() : 
            m_pDispAsScope(NULL), 
            m_nameInitialized(false), 
            m_pResolvedAsmGen(NULL), 
            m_pSnKey(NULL)
        { }

        void Init(typename base_type::metadata_dispenser_type &dispAsScope) const
        {
            _ASSERTE(m_pDispAsScope == NULL);
            m_pDispAsScope = &dispAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pDispAsScope != NULL); return m_pDispAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_name;
        }

        typename base_type::strong_name_key_type const *GetStrongNameKey() const
        {
            return m_pSnKey;
        }

        typename base_type::metadata_dispenser_type const &GetResolutionScope() const
        {
            return Map<typename base_type::metadata_dispenser_type>();
        }

        typename base_type::i_assembly_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        void SetStrongNameKey(typename base_type::strong_name_key_type const &snKey)
        {
            m_pSnKey = &snKey;
        }

        module_name_metadata_generator_type *NewModuleNameGenerator(std::wstring const &name) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            module_name_metadata_generator_type *pModNameMetaGen = NULL;
            pModNameMetaGen = pMutableThis->ModuleNameMetadataGeneratorHeap().New();
            pModNameMetaGen->Init(*pMutableThis);
            pModNameMetaGen->SetName(name);
            return pModNameMetaGen;
        }

        void Save(std::wstring const &name, 
                  Hosting::PortableExecutableKinds const &portableExecutableKind, 
                  Hosting::ImageFileMachine const &imageFileMachine) const
        {
            ResolveCore().Save(name, portableExecutableKind, imageFileMachine);
        }

    private:
        friend typename base_type::metadata_dispenser_type;
        friend typename assembly_metadata_generator_type;
        friend typename module_name_metadata_generator_type;

        module_name_metadata_generator_heap_type &ModuleNameMetadataGeneratorHeap()
        {
            return Of<module_name_metadata_generator_obj_tag_type>();
        }
        
        module_name_metadata_generator_heap_type const &ModuleNameMetadataGeneratorHeap() const
        {
            return Of<module_name_metadata_generator_obj_tag_type>();
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        assembly_metadata_generator_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        assembly_metadata_generator_type &ResolveCore()
        {
            if (m_pResolvedAsmGen == NULL)
            {
                metadata_dispenser_type &metaDisp = Map<metadata_dispenser_type>();
                m_pResolvedAsmGen = metaDisp.DefineAssembly(*this);
            }
            return *m_pResolvedAsmGen;
        }

        mutable typename base_type::metadata_dispenser_type *m_pDispAsScope;
        mutable bool m_nameInitialized;
        mutable std::wstring m_name;
        mutable assembly_metadata_generator_type *m_pResolvedAsmGen;
        mutable typename base_type::strong_name_key_type const *m_pSnKey;
    };

    
    
    
    
    //template<
    //    class AssemblyNameMetadataGeneratorApiHolder
    //>    
    //class BaseAssemblyNameMetadataGeneratorHash : 
    //    CppAnonym::Traits::HashComputable<BaseAssemblyNameMetadataGenerator<AssemblyNameMetadataGeneratorApiHolder> const *>
    //{
    //public:
    //    typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

    //    result_type operator()(param_type v) const
    //    {
    //        using namespace boost;
    //        using namespace Urasandesu::Swathe::Utilities;

    //        _ASSERTE(v != NULL);

    //        std::size_t seed = 0;
    //        hash_combine(seed, hash_value(v->GetName()));
    //        hash_combine(seed, HashValue(&v->Map<metadata_dispenser_type>()));
    //        return seed;
    //    }
    //};

    //
    //
    //
    //
    //template<
    //    class AssemblyNameMetadataGeneratorApiHolder
    //>    
    //class BaseAssemblyNameMetadataGeneratorEqualTo : 
    //    CppAnonym::Traits::EqualityComparable<BaseAssemblyNameMetadataGenerator<AssemblyNameMetadataGeneratorApiHolder> const *>
    //{
    //public:
    //    typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
    //    
    //    result_type operator()(param_type x, param_type y) const
    //    {
    //        _ASSERTE(x != NULL && y != NULL);

    //        return x->GetName() == y->GetName() &&
    //               &x->Map<metadata_dispenser_type>() == &y->Map<metadata_dispenser_type>();
    //    }
    //};

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP