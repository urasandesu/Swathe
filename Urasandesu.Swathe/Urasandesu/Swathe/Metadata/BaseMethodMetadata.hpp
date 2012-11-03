#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASEMETHODMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMethodMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadataApiHolder
    >    
    class BaseMethodMetadata : 
        public SmartPtrChain<
            BaseMethodMetadata<MethodMetadataApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabel>::type>
            >
        >,
        public MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseMethodMetadata<MethodMetadataApiHolder> this_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type base_type;

        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;        
        
        BaseMethodMetadata() : 
            m_mdt(mdTokenNil),
            m_callingConvention(CallingConventions::CC_NO_VALUE),
            m_retTypeInitialized(false), 
            m_paramTypesInitialized(false)
        { }

        mdToken GetToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                _ASSERTE(!m_name.empty());

                SimpleBlob sig;

                _ASSERTE(m_callingConvention != CallingConventions::CC_NO_VALUE);
                SignatureUtil::PutSignatures(sig, m_callingConvention);

                _ASSERTE(m_paramTypesInitialized);
                sig.Put<COR_SIGNATURE>(m_paramTypes.size());

                _ASSERTE(m_retTypeInitialized);
                SignatureUtil::PutSignatures(sig, *m_pRetType);

                typedef std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> >::const_iterator ConstIterator;
                for (ConstIterator ci = m_paramTypes.cbegin(), ci_end = m_paramTypes.cend(); ci != ci_end; ++ci)
                    SignatureUtil::PutSignatures(sig, **ci);

                this_type *pMutableThis = const_cast<this_type *>(this);

                boost::shared_ptr<assembly_metadata_type> pAsm = MapFirst<assembly_metadata_type>();
                boost::shared_ptr<type_metadata_type> pType = MapFirst<type_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.FindMethod(pType->GetToken(), m_name.c_str(), 
                                                   sig.Ptr(), sig.Size(), &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            }
            return m_mdt;
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_name;
        }

        CallingConventions const &GetCallingConvention() const
        {
            if (m_callingConvention == CallingConventions::CC_NO_VALUE)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_callingConvention;
        }
        
        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetReturnType() const
        {
            if (!m_retTypeInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_pRetType;
        }

        std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > const &GetParameterTypes() const
        {
            if (!m_paramTypesInitialized)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            return m_paramTypes;
        }

        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<type_metadata_type>();
        }

    private:
        friend typename type_metadata_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            _ASSERTE(callingConvention != CallingConventions::CC_NO_VALUE);
            _ASSERTE(m_callingConvention == CallingConventions::CC_NO_VALUE);
            m_callingConvention = callingConvention;
        }

        void SetReturnType(boost::shared_ptr<i_type_metadata_type const> const &pRetType)
        {
            _ASSERTE(!m_retTypeInitialized);
            m_pRetType = pRetType;
            m_retTypeInitialized = true;
        }

        void SetParameterTypes(std::vector<boost::shared_ptr<i_type_metadata_type const> > const &paramTypes)
        {
            _ASSERTE(!m_paramTypesInitialized);
            m_paramTypes = paramTypes;
            m_paramTypesInitialized = true;
        }

        mutable mdToken m_mdt;
        std::wstring m_name;
        CallingConventions m_callingConvention;
        bool m_retTypeInitialized; 
        boost::shared_ptr<i_type_metadata_type const> m_pRetType;
        bool m_paramTypesInitialized; 
        std::vector<boost::shared_ptr<i_type_metadata_type const> > m_paramTypes;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETHODMETADATA_HPP