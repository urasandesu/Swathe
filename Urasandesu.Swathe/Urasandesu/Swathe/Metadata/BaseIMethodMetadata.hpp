#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_IMETHODMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/IMethodMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseIMethodMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct IMethodMetadataApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::IMethodMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IMethodMetadataApiHolder
    >    
    class BaseIMethodMetadata
    {
    public:
        typedef BaseIMethodMetadata<IMethodMetadataApiHolder> this_type;

        typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type i_method_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual CallingConventions const &GetCallingConvention() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetReturnType() const = 0;
        virtual std::vector<boost::shared_ptr<i_type_metadata_type const> > const &GetParameterTypes() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetResolutionScope() const = 0;
    };




    
    template<
        class IMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataHash : 
        CppAnonym::Traits::HashComputable<boost::shared_ptr<typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type const> >
    {
    public:
        typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::Swathe::Collections;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, v->GetCallingConvention().Value());
            hash_combine(seed, i_type_metadata_hash_type()(v->GetReturnType()));
            hash_combine(seed, SequenceHashValue(v->GetParameterTypes().cbegin(), 
                                                 v->GetParameterTypes().cend(), 
                                                 i_type_metadata_hash_type()));
            hash_combine(seed, i_type_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataEqualTo : 
        CppAnonym::Traits::EqualityComparable<boost::shared_ptr<typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type const> >
    {
    public:
        //typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            //_ASSERTE(x && y);

            //return x->GetName() == y->GetName() &&
            //       i_assembly_metadata_equal_to_type()(x->GetResolutionScope(), y->GetResolutionScope());
        }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEIMETHODMETADATA_HPP