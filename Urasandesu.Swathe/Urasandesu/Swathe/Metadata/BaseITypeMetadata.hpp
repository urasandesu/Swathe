#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASEITYPEMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ITYPEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/ITypeMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseITypeMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ITypeMetadataApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::ITypeMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadata
    {
    public:
        typedef BaseITypeMetadata<ITypeMetadataApiHolder> this_type;

        typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type i_module_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual this_type const *GetBaseType() const = 0;
        virtual i_module_metadata_type const *GetResolutionScope() const = 0;
        virtual std::vector<COR_SIGNATURE> const &GetSignatures() const = 0;
        virtual bool IsGenericParameter() const = 0;
    };




    
    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadataHash : 
        CppAnonym::Traits::HashComputable<typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type const *>
    {
    public:
        typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IModuleMetadataHashLabel>::type i_module_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_module_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadataEqualTo : 
        CppAnonym::Traits::EqualityComparable<typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type const *>
    {
    public:
        //typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            //_ASSERTE(x != NULL && y != NULL);

            //return x->GetName() == y->GetName() &&
            //       i_assembly_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEITYPEMETADATA_HPP