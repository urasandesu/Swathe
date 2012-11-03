#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODBODYWRITERAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODBODYWRITERAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_LOCALNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/LocalNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseLocalNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_INSTRUCTIONLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/InstructionLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTIONFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseInstructionFwd.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODBODYWRITERAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMethodBodyWriterApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultMethodBodyWriterApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Hosting::Interfaces;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        //typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        //typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        //typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        //typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        struct DefaultMethodBodyWriterApiHolderImpl
        {
            typedef map<
                pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>,
                pair<MethodMetadataGeneratorLabel, MethodMetadataGenerator>,
                pair<IFieldNameMetadataLabel, IFieldNameMetadata>,
                pair<IMethodNameMetadataLabel, IMethodNameMetadata>,
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<LocalsNameMetadataGeneratorLabel, LocalsNameMetadataGenerator>,
                pair<InstructionLabel, Instruction>,
                pair<PEWriterHostLabel, PEWriterHost>
            > api_cartridges;
        };

    }   // namespace DefaultMethodBodyWriterApiHolderDetail {

    struct DefaultMethodBodyWriterApiHolder : 
        DefaultMethodBodyWriterApiHolderDetail::DefaultMethodBodyWriterApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODBODYWRITERAPIHOLDER_H