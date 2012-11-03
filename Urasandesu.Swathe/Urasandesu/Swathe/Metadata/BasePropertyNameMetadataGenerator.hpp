#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATOR_HPP

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

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_PROPERTYNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/PropertyNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BasePropertyNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct PropertyNameMetadataGeneratorApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::PropertyNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class PropertyNameMetadataGeneratorApiHolder
    >
    class BasePropertyNameMetadataGenerator : 
        public PropertyNameMetadataGeneratorApiAt<PropertyNameMetadataGeneratorApiHolder, Interfaces::IPropertyNameMetadataLabel>::type
    {
    public:
        typedef BasePropertyNameMetadataGenerator<PropertyNameMetadataGeneratorApiHolder> this_type;
        typedef typename PropertyNameMetadataGeneratorApiAt<PropertyNameMetadataGeneratorApiHolder, Interfaces::IPropertyNameMetadataLabel>::type base_type;

        typedef typename PropertyNameMetadataGeneratorApiAt<PropertyNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
        typedef typename PropertyNameMetadataGeneratorApiAt<PropertyNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;
        typedef typename PropertyNameMetadataGeneratorApiAt<PropertyNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename PropertyNameMetadataGeneratorApiAt<PropertyNameMetadataGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename PropertyNameMetadataGeneratorApiAt<PropertyNameMetadataGeneratorApiHolder, Interfaces::PropertyMetadataGeneratorLabel>::type property_metadata_generator_type;

        BasePropertyNameMetadataGenerator() : 
            m_pTypeNameGenAsScope(NULL), 
            m_pTypeGenAsScope(NULL),
            m_pResolvedPropGen(NULL),
            m_nameInitialized(false), 
            m_pPropType(NULL), 
            m_paramTypesInitialized(false), 
            m_attrInitialized(false), 
            m_pGetMethod(NULL),
            m_pSetMethod(NULL)
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

        typename base_type::i_type_name_metadata_type const &GetResolutionScope() const
        {
            return Map<type_name_metadata_generator_type>();
        }

        typename base_type::i_property_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        type_metadata_type const &GetPropertyType() const
        {
            if (m_pPropType == NULL)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return *m_pPropType;
        }

        std::vector<type_metadata_type const *> const &GetParameterTypes() const
        {
            if (!m_paramTypesInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_paramTypes;
        }

        PropertyAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_attr;
        }

        method_name_metadata_generator_type const *GetGetMethod() const
        {
            return m_pGetMethod;
        }

        method_name_metadata_generator_type const *GetSetMethod() const
        {
            return m_pSetMethod;
        }

        void SetGetMethod(method_name_metadata_generator_type const &getMethod)
        {
            m_pGetMethod = &getMethod;
        }

        void SetSetMethod(method_name_metadata_generator_type const &setMethod)
        {
            m_pSetMethod = &setMethod;
        }

    private:
        friend typename type_name_metadata_generator_type;

        property_metadata_generator_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        property_metadata_generator_type &ResolveCore()
        {
            if (m_pTypeGenAsScope == NULL)
                m_pTypeGenAsScope = &Map<type_name_metadata_generator_type>().ResolveCore();

            if (m_pResolvedPropGen == NULL)
                m_pResolvedPropGen = m_pTypeGenAsScope->DefineProperty(*this);

            return *m_pResolvedPropGen;
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        void SetPropertyType(type_metadata_type const &propType)
        {
            _ASSERTE(m_pPropType == NULL);
            m_pPropType = &propType;
        }

        void SetParameterTypes(std::vector<type_metadata_type const *> const &paramTypes)
        {
            _ASSERTE(!m_paramTypesInitialized);
            m_paramTypes = paramTypes;
            m_paramTypesInitialized = true;
        }

        void SetAttribute(PropertyAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        mutable type_name_metadata_generator_type *m_pTypeNameGenAsScope;
        mutable type_metadata_generator_type *m_pTypeGenAsScope;
        property_metadata_generator_type *m_pResolvedPropGen;
        bool m_nameInitialized;
        std::wstring m_name;
        type_metadata_type const *m_pPropType;
        bool m_paramTypesInitialized;
        std::vector<type_metadata_type const *> m_paramTypes;
        bool m_attrInitialized;
        PropertyAttributes m_attr;
        method_name_metadata_generator_type const *m_pGetMethod;
        method_name_metadata_generator_type const *m_pSetMethod;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEPROPERTYNAMEMETADATAGENERATOR_HPP