/* 
 * File: MetadataDispenserFacade.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METADATADISPENSERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METADATADISPENSERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_METADATADISPENSERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/MetadataDispenserApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADISPENSERPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataDispenserPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_ASSEMBLYMETADATAPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/AssemblyMetadataPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYGENERATORPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyGeneratorPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_ASSEMBLYGENERATORPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/AssemblyGeneratorPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace MetadataDispenserFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::MetadataDispenserApiAt;
        using Urasandesu::Swathe::Metadata::MetadataDispenserPimpl;
        using Urasandesu::Swathe::Metadata::MetadataDispenser;
        using Urasandesu::Swathe::Metadata::MetadataInfo;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::AssemblyMetadataPersistedHandlerLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyGeneratorPimplLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::AssemblyGeneratorPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::MetadataInfoPimpl;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct MetadataDispenserFacadeImpl
        {
            typedef MetadataDispenser class_type;
            typedef MetadataDispenserPimpl class_pimpl_type;
            typedef MetadataDispenserPimpl metadata_dispenser_pimpl_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, AssemblyMetadataPersistedHandlerLabel>::type assembly_metadata_persisted_handler_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, AssemblyGeneratorPimplLabel>::type assembly_generator_pimpl_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, AssemblyGeneratorPersistedHandlerLabel>::type assembly_generator_persisted_handler_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_type;
            typedef typename MetadataDispenserApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;

            typedef MetadataDispenserPimpl metadata_dispenser_pimpl_label_type;
            typedef MetadataDispenser metadata_dispenser_label_type;
            typedef MetadataInfo metadata_info_label_type;
            typedef MetadataInfoPimpl metadata_info_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_METADATA_DISPENSER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace MetadataDispenserFacadeDetail {

    template<
        class ApiHolder
    >    
    struct MetadataDispenserFacade : 
        MetadataDispenserFacadeDetail::MetadataDispenserFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_METADATA_DISPENSER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::MetadataDispenserFacade<ApiHolder> facade;

#define SWATHE_DECLARE_METADATA_DISPENSER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_METADATA_DISPENSER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::metadata_dispenser_pimpl_label_type metadata_dispenser_pimpl_label_type; \
    friend typename metadata_dispenser_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_persisted_handler_label_type assembly_metadata_persisted_handler_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    typedef typename facade::assembly_generator_persisted_handler_label_type assembly_generator_persisted_handler_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_persisted_handler_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    friend typename assembly_generator_persisted_handler_label_type; \
    friend typename fusion_info_label_type; \
    friend typename portable_executable_info_label_type; \
    friend typename strong_name_info_label_type; \
    typedef typename facade::metadata_dispenser_pimpl_label_type metadata_dispenser_pimpl_label_type; \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    typedef typename facade::metadata_info_label_type metadata_info_label_type; \
    typedef typename facade::metadata_info_pimpl_label_type metadata_info_pimpl_label_type; \
    friend typename metadata_dispenser_pimpl_label_type; \
    friend typename metadata_dispenser_label_type; \
    friend typename metadata_info_label_type; \
    friend typename metadata_info_pimpl_label_type; \

#define SWATHE_END_METADATA_DISPENSER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METADATADISPENSERFACADE_H

