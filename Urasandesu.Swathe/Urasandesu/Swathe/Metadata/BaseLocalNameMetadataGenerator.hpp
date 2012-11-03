#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
//#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODBODYWRITERAPIHOLDERLABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MethodBodyWriterApiHolderLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/Swathe/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTION_HPP
//#include <Urasandesu/Swathe/Metadata/BaseInstruction.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MethodMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeMetadataLabel.hpp>
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
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
//#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataDispenserLabel.hpp>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
//#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
//#endif
//
//#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
//#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
//#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_LOCALNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/LocalNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseLocalNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct LocalNameMetadataGeneratorApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::LocalNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class LocalNameMetadataGeneratorApiHolder
    >
    class BaseLocalNameMetadataGenerator
    {
    public:
        typedef BaseLocalNameMetadataGenerator<LocalNameMetadataGeneratorApiHolder> this_type;

        //typedef typename LocalNameMetadataGeneratorApiAt<LocalNameMetadataGeneratorApiHolder, Interfaces::MethodBodyWriterLabel>::type method_body_writer_type;
        typedef typename LocalNameMetadataGeneratorApiAt<LocalNameMetadataGeneratorApiHolder, Interfaces::LocalsNameMetadataGeneratorLabel>::type locals_name_metadata_generator_type;
        typedef typename LocalNameMetadataGeneratorApiAt<LocalNameMetadataGeneratorApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;

        BaseLocalNameMetadataGenerator() : 
            m_pLocalsNameAsScope(NULL),
            m_pLocalType(NULL)
        { }

    private:
        friend typename locals_name_metadata_generator_type;

        void Init(locals_name_metadata_generator_type &localsNameAsScope) const
        {
            _ASSERTE(m_pLocalsNameAsScope == NULL);
            m_pLocalsNameAsScope = &localsNameAsScope;
        }

        void SetLocalType(i_type_name_metadata_type const &localType)
        {
            _ASSERTE(m_pLocalType == NULL);
            m_pLocalType = &localType;
        }

        mutable locals_name_metadata_generator_type *m_pLocalsNameAsScope;
        i_type_name_metadata_type const *m_pLocalType;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP