#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
//#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPENAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeNameMetadataApiHolderLabel.hpp>
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
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/ModuleMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
//#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
//#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPENAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/TypeNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseTypeNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeNameMetadataGeneratorApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeNameMetadataGeneratorApiHolder
    >
    class BaseTypeNameMetadataGenerator : 
        public TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ITypeNameMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::FieldNameMetadataGeneratorLabel>::type, QuickHeap>,
                ObjectTag<typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type, QuickHeap>,
                ObjectTag<typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::PropertyNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeNameMetadataGenerator<TypeNameMetadataGeneratorApiHolder> this_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ITypeNameMetadataLabel>::type base_type;

        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ModuleMetadataGeneratorLabel>::type module_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::FieldNameMetadataGeneratorLabel>::type field_name_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::PropertyNameMetadataGeneratorLabel>::type property_name_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;

        typedef ObjectTag<field_name_metadata_generator_type, QuickHeap> field_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<field_name_metadata_generator_obj_tag_type>::type field_name_metadata_generator_heap_type;

        typedef ObjectTag<method_name_metadata_generator_type, QuickHeap> method_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_generator_obj_tag_type>::type method_name_metadata_generator_heap_type;

        typedef ObjectTag<property_name_metadata_generator_type, QuickHeap> property_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<property_name_metadata_generator_obj_tag_type>::type property_name_metadata_generator_heap_type;

        BaseTypeNameMetadataGenerator() : 
            m_pModNameGenAsScope(NULL), 
            m_pModGenAsScope(NULL),
            m_nameInitialized(false), 
            m_attrInitialized(false),
            m_pResolvedTypeGen(NULL)
        { }

        void Init(module_name_metadata_generator_type &modNameGenAsScope) const
        {
            _ASSERTE(m_pModNameGenAsScope == NULL && m_pModGenAsScope == NULL);
            m_pModNameGenAsScope = &modNameGenAsScope;
        }

        void Init(module_metadata_generator_type &modGenAsScope) const
        {
            _ASSERTE(m_pModNameGenAsScope == NULL && m_pModGenAsScope == NULL);
            m_pModGenAsScope = &modGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            _ASSERTE(m_pModNameGenAsScope != NULL || m_pModGenAsScope != NULL);
            if (m_pModNameGenAsScope != NULL)
                return m_pModNameGenAsScope->Map<T>();
            else
                return m_pModGenAsScope->GetModuleNameCore()->Map<T>();
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
            }
            return m_name;
        }

        typename base_type::this_type const *GetBaseTypeName() const
        {
            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
        }

        typename base_type::i_module_name_metadata_type const &GetResolutionScope() const
        {
            return Map<module_name_metadata_generator_type>();
        }

        typename base_type::i_type_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
        }

        TypeAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_attr;
        }

        this_type *NewNestedTypeNameGenerator(std::wstring const &name, TypeAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            module_name_metadata_generator_type &modNameMetaGen = 
                                pMutableThis->Map<module_name_metadata_generator_type>();
            return modNameMetaGen.NewTypeNameGenerator(name, attr);
        }

        field_name_metadata_generator_type *NewFieldNameGenerator(std::wstring const &name, 
                                                                  type_metadata_type const &fieldType, 
                                                                  FieldAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            field_name_metadata_generator_type *pFieldNameMetaGen = NULL;
            pFieldNameMetaGen = pMutableThis->FieldNameMetadataGeneratorHeap().New();
            pFieldNameMetaGen->Init(*pMutableThis);
            pFieldNameMetaGen->SetName(name);
            pFieldNameMetaGen->SetFieldType(fieldType);
            pFieldNameMetaGen->SetAttribute(attr);
            return pFieldNameMetaGen;
        }

        method_name_metadata_generator_type *NewMethodNameGenerator(std::wstring const &name, 
                                                                    CallingConventions const &callingConvention, 
                                                                    typename base_type::i_type_metadata_type const &retType, 
                                                                    std::vector<typename base_type::i_type_metadata_type const *> const &paramTypes,
                                                                    MethodAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            method_name_metadata_generator_type *pMethodNameMetaGen = NULL;
            pMethodNameMetaGen = pMutableThis->MethodNameMetadataGeneratorHeap().New();
            pMethodNameMetaGen->Init(*pMutableThis);
            pMethodNameMetaGen->SetName(name);
            pMethodNameMetaGen->SetCallingConvention(callingConvention);
            pMethodNameMetaGen->SetReturnType(retType);
            pMethodNameMetaGen->SetParameterTypes(paramTypes);
            pMethodNameMetaGen->SetAttribute(attr);
            return pMethodNameMetaGen;
        }

        property_name_metadata_generator_type *NewPropertyNameGenerator(std::wstring const &name, 
                                                                        type_metadata_type const &propType,
                                                                        std::vector<type_metadata_type const *> const &paramTypes,
                                                                        PropertyAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            property_name_metadata_generator_type *pPropertyNameMetaGen = NULL;
            pPropertyNameMetaGen = pMutableThis->PropertyNameMetadataGeneratorHeap().New();
            pPropertyNameMetaGen->Init(*pMutableThis);
            pPropertyNameMetaGen->SetName(name);
            pPropertyNameMetaGen->SetPropertyType(propType);
            pPropertyNameMetaGen->SetParameterTypes(paramTypes);
            pPropertyNameMetaGen->SetAttribute(attr);
            return pPropertyNameMetaGen;
        }

    private:
        friend typename module_name_metadata_generator_type;
        friend typename type_metadata_generator_type;
        friend typename field_name_metadata_generator_type;
        friend typename method_name_metadata_generator_type;
        friend typename property_name_metadata_generator_type;

        field_name_metadata_generator_heap_type &FieldNameMetadataGeneratorHeap()
        {
            return Of<field_name_metadata_generator_obj_tag_type>();
        }
        
        field_name_metadata_generator_heap_type const &FieldNameMetadataGeneratorHeap() const
        {
            return Of<field_name_metadata_generator_obj_tag_type>();
        }

        method_name_metadata_generator_heap_type &MethodNameMetadataGeneratorHeap()
        {
            return Of<method_name_metadata_generator_obj_tag_type>();
        }
        
        method_name_metadata_generator_heap_type const &MethodNameMetadataGeneratorHeap() const
        {
            return Of<method_name_metadata_generator_obj_tag_type>();
        }

        property_name_metadata_generator_heap_type &PropertyNameMetadataGeneratorHeap()
        {
            return Of<property_name_metadata_generator_obj_tag_type>();
        }
        
        property_name_metadata_generator_heap_type const &PropertyNameMetadataGeneratorHeap() const
        {
            return Of<property_name_metadata_generator_obj_tag_type>();
        }

        type_metadata_generator_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        type_metadata_generator_type &ResolveCore()
        {
            if (m_pModGenAsScope == NULL)
                m_pModGenAsScope = &Map<module_name_metadata_generator_type>().ResolveCore();

            if (m_pResolvedTypeGen == NULL)
            {
                m_pResolvedTypeGen = m_pModGenAsScope->DefineType(*this);
            }

            return *m_pResolvedTypeGen;
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        void SetAttribute(TypeAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        mutable module_name_metadata_generator_type *m_pModNameGenAsScope;
        mutable module_metadata_generator_type *m_pModGenAsScope;
        bool m_nameInitialized;
        std::wstring m_name;
        bool m_attrInitialized;
        TypeAttributes m_attr;
        type_metadata_generator_type *m_pResolvedTypeGen;
    };

    
    
    
    
    //template<
    //    class TypeNameMetadataGeneratorApiHolder
    //>    
    //class BaseTypeNameMetadataGeneratorHash : 
    //    CppAnonym::Traits::HashComputable<BaseTypeNameMetadataGenerator<TypeNameMetadataGeneratorApiHolder> const *>
    //{
    //public:
    //    typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;
    //    typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorHashLabel>::type module_name_metadata_generator_hash_type;

    //    result_type operator()(param_type v) const
    //    {
    //        using namespace boost;

    //        _ASSERTE(v != NULL);

    //        std::size_t seed = 0;
    //        hash_combine(seed, hash_value(v->GetName()));
    //        hash_combine(seed, module_name_metadata_generator_hash_type()(&v->Map<module_name_metadata_generator_type>()));
    //        return seed;
    //    }
    //};

    //
    //
    //
    //
    //template<
    //    class TypeNameMetadataGeneratorApiHolder
    //>    
    //class BaseTypeNameMetadataGeneratorEqualTo : 
    //    CppAnonym::Traits::EqualityComparable<BaseTypeNameMetadataGenerator<TypeNameMetadataGeneratorApiHolder> const *>
    //{
    //public:
    //    typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;
    //    typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorEqualToLabel>::type module_name_metadata_generator_equal_to_type;
    //    
    //    result_type operator()(param_type x, param_type y) const
    //    {
    //        _ASSERTE(x != NULL && y != NULL);

    //        return x->GetName() == y->GetName() &&
    //               module_name_metadata_generator_equal_to_type()(&x->Map<module_name_metadata_generator_type>(), &y->Map<module_name_metadata_generator_type>());
    //    }
    //};

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP