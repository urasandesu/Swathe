#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_IASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/IAssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseIAssemblyMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct IAssemblyMetadataApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::IAssemblyMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadata
    {
    public:
        typedef BaseIAssemblyMetadata<IAssemblyMetadataApiHolder> this_type;

        typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;
        typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type i_assembly_metadata_type;

        virtual mdAssembly GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual Utilities::AutoPtr<strong_name_key_type const> GetStrongNameKey() const = 0;
        virtual metadata_dispenser_type const *GetResolutionScope() const = 0;
    };




    
    template<
        class IAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataHash : 
        CppAnonym::Traits::HashComputable<typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type const *>
    {
    public:
        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::Swathe::Utilities;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, HashValue(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataEqualTo : 
        CppAnonym::Traits::EqualityComparable<typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type const *>
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   x->GetResolutionScope() == y->GetResolutionScope();
        }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEIASSEMBLYMETADATA_HPP