#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_IMODULEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/IModuleMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseIModuleMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct IModuleMetadataApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::IModuleMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadata
    {
    public:
        typedef BaseIModuleMetadata<IModuleMetadataApiHolder> this_type;

        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type i_assembly_metadata_type;

        virtual mdModule GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual i_assembly_metadata_type const *GetResolutionScope() const = 0;
    };




    
    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataHash : 
        CppAnonym::Traits::HashComputable<typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type const *>
    {
    public:
        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataHashLabel>::type i_assembly_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_assembly_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataEqualTo : 
        CppAnonym::Traits::EqualityComparable<typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type const *>
    {
    public:
        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   i_assembly_metadata_equal_to_type()(x->GetResolutionScope(), y->GetResolutionScope());
        }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEIMODULEMETADATA_HPP