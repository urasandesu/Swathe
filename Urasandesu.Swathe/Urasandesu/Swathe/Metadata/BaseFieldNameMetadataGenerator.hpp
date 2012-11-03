#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_SWATHE_IHEAPCONTENT_H
//#include <Urasandesu/Swathe/IHeapContent.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
//#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
//#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_UTILITIES_HASH_H
//#include <Urasandesu/Swathe/Utilities/Hash.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_UTILITIES_EQUALTO_H
//#include <Urasandesu/Swathe/Utilities/EqualTo.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataApiHolderLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_TRAITS_EQUALITYCOMPARABLE_H
//#include <Urasandesu/Swathe/Traits/EqualityComparable.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_TRAITS_HASHCOMPUTABLE_H
//#include <Urasandesu/Swathe/Traits/HashComputable.h>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_FIELDNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/FieldNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseFieldNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct FieldNameMetadataGeneratorApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::FieldNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class FieldNameMetadataGeneratorApiHolder
    >
    class BaseFieldNameMetadataGenerator : 
        public FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::IFieldNameMetadataLabel>::type
    {
    public:
        typedef BaseFieldNameMetadataGenerator<FieldNameMetadataGeneratorApiHolder> this_type;
        typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::IFieldNameMetadataLabel>::type base_type;

        typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
        typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;
        typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::FieldMetadataGeneratorLabel>::type field_metadata_generator_type;

        BaseFieldNameMetadataGenerator() : 
            m_pTypeNameGenAsScope(NULL), 
            m_pTypeGenAsScope(NULL),
            m_nameInitialized(false), 
            m_pFieldTypeName(NULL), 
            m_attrInitialized(false),
            m_attr(FieldAttributes::FA_PRIVATE_SCOPE),
            m_pResolvedFieldGen(NULL)
        { }

        void Init(type_name_metadata_generator_type &typeNameGenAsScope) const
        {
            _ASSERTE(m_pTypeNameGenAsScope == NULL && m_pTypeGenAsScope == NULL);
            m_pTypeNameGenAsScope = &typeNameGenAsScope;
        }

        void Init(type_metadata_generator_type &typeGenAsScope) const
        {
            _ASSERTE(m_pTypeNameGenAsScope == NULL && m_pTypeGenAsScope == NULL);
            m_pTypeGenAsScope = &typeGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            _ASSERTE(m_pTypeNameGenAsScope != NULL || m_pTypeGenAsScope != NULL);
            if (m_pTypeNameGenAsScope != NULL)
                return m_pTypeNameGenAsScope->Map<T>();
            else
                return m_pTypeGenAsScope->GetTypeNameCore()->Map<T>();
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

        typename base_type::i_type_name_metadata_type const &GetFieldTypeName() const
        {
            if (m_pFieldTypeName == NULL)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return *m_pFieldTypeName;
        }

        typename base_type::i_type_name_metadata_type const &GetResolutionScope() const
        {
            return Map<type_name_metadata_generator_type>();
        }

        typename base_type::i_field_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        //type_metadata_type const &GetFieldType() const
        //{
        //    if (m_pFieldType == NULL)
        //    {
        //        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
        //    }
        //    return *m_pFieldType;
        //}

        FieldAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_attr;
        }

    private:
        friend typename type_name_metadata_generator_type;

        field_metadata_generator_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        field_metadata_generator_type &ResolveCore()
        {
            if (m_pTypeGenAsScope == NULL)
                m_pTypeGenAsScope = &Map<type_name_metadata_generator_type>().ResolveCore();

            if (m_pResolvedFieldGen == NULL)
            {
                m_pResolvedFieldGen = m_pTypeGenAsScope->DefineField(*this);
            }

            return *m_pResolvedFieldGen;
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        //void SetFieldType(type_metadata_type const &fieldType)
        //{
        //    _ASSERTE(m_pFieldType == NULL);
        //    m_pFieldType = &fieldType;
        //}
        void SetFieldType(i_type_metadata_type const &fieldType)
        {
            SetFieldType(fieldType.GetTypeName());
        }

        void SetFieldType(typename base_type::i_type_name_metadata_type const &fieldTypeName)
        {
            _ASSERTE(m_pFieldTypeName == NULL);
            m_pFieldTypeName = &fieldTypeName;
        }

        void SetAttribute(FieldAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        mutable type_name_metadata_generator_type *m_pTypeNameGenAsScope;
        mutable type_metadata_generator_type *m_pTypeGenAsScope;
        bool m_nameInitialized;
        std::wstring m_name;
        //type_metadata_type const *m_pFieldType;
        typename base_type::i_type_name_metadata_type const *m_pFieldTypeName;
        bool m_attrInitialized;
        FieldAttributes m_attr;
        field_metadata_generator_type *m_pResolvedFieldGen;
    };

    
    
    
    
    //template<
    //    class FieldNameMetadataGeneratorApiHolder
    //>    
    //class BaseFieldNameMetadataGeneratorHash : 
    //    CppAnonym::Traits::HashComputable<BaseFieldNameMetadataGenerator<FieldNameMetadataGeneratorApiHolder> const *>
    //{
    //public:
    //    typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
    //    typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorHashLabel>::type type_name_metadata_generator_hash_type;

    //    result_type operator()(param_type v) const
    //    {
    //        using namespace boost;

    //        _ASSERTE(v != NULL);

    //        std::size_t seed = 0;
    //        hash_combine(seed, hash_value(v->GetName()));
    //        hash_combine(seed, type_name_metadata_generator_hash_type()(&v->Map<type_name_metadata_generator_type>()));
    //        return seed;
    //    }
    //};

    
    
    
    
    //template<
    //    class FieldNameMetadataGeneratorApiHolder
    //>    
    //class BaseFieldNameMetadataGeneratorEqualTo : 
    //    CppAnonym::Traits::EqualityComparable<BaseFieldNameMetadataGenerator<FieldNameMetadataGeneratorApiHolder> const *>
    //{
    //public:
    //    typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
    //    typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorEqualToLabel>::type type_name_metadata_generator_equal_to_type;
    //    
    //    result_type operator()(param_type x, param_type y) const
    //    {
    //        _ASSERTE(x != NULL && y != NULL);

    //        return x->GetName() == y->GetName() &&
    //               type_name_metadata_generator_equal_to_type()(&x->Map<type_name_metadata_generator_type>(), &y->Map<type_name_metadata_generator_type>());
    //    }
    //};

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP