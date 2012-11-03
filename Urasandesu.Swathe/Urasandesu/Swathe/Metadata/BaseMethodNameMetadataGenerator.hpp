#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP

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

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMethodNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodNameMetadataGeneratorApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodNameMetadataGeneratorApiHolder
    >
    class BaseMethodNameMetadataGenerator : 
        public MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::IMethodNameMetadataLabel>::type
    {
    public:
        typedef BaseMethodNameMetadataGenerator<MethodNameMetadataGeneratorApiHolder> this_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::IMethodNameMetadataLabel>::type base_type;

        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::MethodBodyWriterLabel>::type method_body_writer_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::MethodMetadataGeneratorLabel>::type method_metadata_generator_type;

        BaseMethodNameMetadataGenerator() : 
            m_pTypeNameGenAsScope(NULL), 
            m_pTypeGenAsScope(NULL),
            m_nameInitialized(false), 
            m_callingConventionInitialized(false), 
            m_pRetTypeName(NULL),
            m_paramTypeNamesInitialized(false),
            m_attrInitialized(false),
            m_attr(MethodAttributes::MA_PRIVATE_SCOPE), 
            m_pResolvedMethodGen(NULL)
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

        CallingConventions const &GetCallingConvention() const
        {
            if (!m_callingConventionInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_callingConvention;
        }

        typename base_type::i_type_name_metadata_type const &GetReturnTypeName() const
        {
            if (m_pRetTypeName == NULL)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return *m_pRetTypeName;
        }

        std::vector<typename base_type::i_type_name_metadata_type const *> const &GetParameterTypeNames() const
        {
            if (!m_paramTypeNamesInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_paramTypeNames;
        }

        typename base_type::i_type_name_metadata_type const &GetResolutionScope() const
        {
            return Map<type_name_metadata_generator_type>();
        }

        typename base_type::i_method_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        MethodAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_attr;
        }

        method_body_writer_type const &GetMethodBody() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetMethodBody();
        }

        method_body_writer_type &GetMethodBody()
        {
            if (!m_pBody.get())
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                m_pBody = boost::make_shared<method_body_writer_type>();
                m_pBody->Init(*pMutableThis);
            }
            return *m_pBody.get();
        }

    private:
        friend typename type_name_metadata_generator_type;
        friend typename method_metadata_generator_type;

        method_metadata_generator_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        method_metadata_generator_type &ResolveCore()
        {
            if (m_pTypeGenAsScope == NULL)
                m_pTypeGenAsScope = &Map<type_name_metadata_generator_type>().ResolveCore();

            if (m_pResolvedMethodGen == NULL)
            {
                m_pResolvedMethodGen = m_pTypeGenAsScope->DefineMethod(*this);
            }

            return *m_pResolvedMethodGen;
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            _ASSERTE(!m_callingConventionInitialized);
            m_callingConvention = callingConvention;
            m_callingConventionInitialized = true;
        }

        void SetReturnType(i_type_metadata_type const &retType)
        {
            SetReturnType(retType.GetTypeName());
        }

        void SetReturnType(typename base_type::i_type_name_metadata_type const &retTypeName)
        {
            _ASSERTE(m_pRetTypeName == NULL);
            m_pRetTypeName = &retTypeName;
        }

        void SetParameterTypes(std::vector<i_type_metadata_type const *> const &paramTypes)
        {
            std::vector<typename base_type::i_type_name_metadata_type const *> paramTypeNames;
            paramTypeNames.reserve(paramTypes.size());
            typedef std::vector<i_type_metadata_type const *>::const_iterator ConstIterator;
            for (ConstIterator ci = paramTypes.cbegin(), ci_end = paramTypes.cend(); ci != ci_end; ++ci)
                paramTypeNames.push_back(&(*ci)->GetTypeName());

            SetParameterTypes(paramTypeNames);
        }

        void SetParameterTypes(std::vector<typename base_type::i_type_name_metadata_type const *> const &paramTypeNames)
        {
            _ASSERTE(!m_paramTypeNamesInitialized);
            m_paramTypeNames = paramTypeNames;
            m_paramTypeNamesInitialized = true;
        }

        void SetAttribute(MethodAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        void SetResolvedMethod(method_metadata_generator_type &resolvedMethodGen)
        {
            _ASSERTE(m_pResolvedMethodGen == NULL);
            m_pResolvedMethodGen = &resolvedMethodGen;
        }

        mutable type_name_metadata_generator_type *m_pTypeNameGenAsScope;
        mutable type_metadata_generator_type *m_pTypeGenAsScope;
        bool m_nameInitialized;
        std::wstring m_name;
        bool m_callingConventionInitialized;
        CallingConventions m_callingConvention;
        typename base_type::i_type_name_metadata_type const *m_pRetTypeName;
        bool m_paramTypeNamesInitialized;
        std::vector<typename base_type::i_type_name_metadata_type const *> m_paramTypeNames;
        bool m_attrInitialized;
        MethodAttributes m_attr;
        boost::shared_ptr<method_body_writer_type> m_pBody;
        method_metadata_generator_type *m_pResolvedMethodGen;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP