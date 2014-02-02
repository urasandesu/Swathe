/* 
 * File: AssemblyMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_ASSEMBLYMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/AssemblyMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_METADATADISPENSERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/MetadataDispenserPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYCACHELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyCacheLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMERANGELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameRangeLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEITERATORFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameIteratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEREADERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableReaderLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace AssemblyMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::AssemblyMetadataApiAt;
        using Urasandesu::Swathe::Metadata::AssemblyMetadataPimpl;
        using Urasandesu::Swathe::Metadata::AssemblyMetadata;
        using Urasandesu::Swathe::Metadata::MetadataInfo;
        using Urasandesu::Swathe::Metadata::MetadataInfoPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::MetadataDispenserPimplLabel;
        using Urasandesu::Swathe::Metadata::ModuleMetadata;
        using Urasandesu::Swathe::Metadata::ModuleMetadataPimpl;
        using Urasandesu::Swathe::Metadata::ModuleMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::TypeMetadata;
        using Urasandesu::Swathe::Metadata::TypeMetadataPimpl;
        using Urasandesu::Swathe::Metadata::TypeMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodMetadata;
        using Urasandesu::Swathe::Metadata::MethodMetadataPimpl;
        using Urasandesu::Swathe::Metadata::MethodMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::PropertyMetadata;
        using Urasandesu::Swathe::Metadata::PropertyMetadataPimpl;
        using Urasandesu::Swathe::Metadata::PropertyMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadata;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPimpl;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::InstructionMetadata;
        using Urasandesu::Swathe::Metadata::InstructionMetadataPimpl;
        using Urasandesu::Swathe::Metadata::ParameterMetadata;
        using Urasandesu::Swathe::Metadata::ParameterMetadataPimpl;
        using Urasandesu::Swathe::Metadata::ParameterMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::LocalMetadata;
        using Urasandesu::Swathe::Metadata::LocalMetadataPimpl;
        using Urasandesu::Swathe::Metadata::LocalMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::CustomAttributeMetadata;
        using Urasandesu::Swathe::Metadata::CustomAttributeMetadataPimpl;
        using Urasandesu::Swathe::Metadata::CustomAttributeMetadataPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyCacheLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameRangeLabel;
        using Urasandesu::Swathe::Fusion::AssemblyNameIterator;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableReaderLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct AssemblyMetadataFacadeImpl
        {
            typedef AssemblyMetadata class_type;
            typedef AssemblyMetadataPimpl class_pimpl_type;
            typedef AssemblyMetadataPimpl assembly_metadata_pimpl_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, MetadataDispenserPimplLabel>::type metadata_dispenser_pimpl_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, AssemblyCacheLabel>::type assembly_cache_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, AssemblyNameRangeLabel>::type assembly_name_range_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, AssemblyNameLabel>::type assembly_name_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_type;
            typedef typename AssemblyMetadataApiAt<ApiHolder, PortableExecutableReaderLabel>::type portable_executable_reader_label_type;

            typedef AssemblyMetadataPimpl assembly_metadata_pimpl_label_type;
            typedef AssemblyMetadata assembly_metadata_label_type;
            typedef MetadataInfo metadata_info_label_type;
            typedef MetadataInfoPimpl metadata_info_pimpl_label_type;
            typedef ModuleMetadata module_metadata_label_type;
            typedef ModuleMetadataPimpl module_metadata_pimpl_label_type;
            typedef ModuleMetadataPersistedHandler module_metadata_persisted_handler_label_type;
            typedef TypeMetadata type_metadata_label_type;
            typedef TypeMetadataPimpl type_metadata_pimpl_label_type;
            typedef TypeMetadataPersistedHandler type_metadata_persisted_handler_label_type;
            typedef MethodMetadata method_metadata_label_type;
            typedef MethodMetadataPimpl method_metadata_pimpl_label_type;
            typedef MethodMetadataPersistedHandler method_metadata_persisted_handler_label_type;
            typedef PropertyMetadata property_metadata_label_type;
            typedef PropertyMetadataPimpl property_metadata_pimpl_label_type;
            typedef PropertyMetadataPersistedHandler property_metadata_persisted_handler_label_type;
            typedef MethodBodyMetadata method_body_metadata_label_type;
            typedef MethodBodyMetadataPimpl method_body_metadata_pimpl_label_type;
            typedef MethodBodyMetadataPersistedHandler method_body_metadata_persisted_handler_label_type;
            typedef InstructionMetadata instruction_metadata_label_type;
            typedef InstructionMetadataPimpl instruction_metadata_pimpl_label_type;
            typedef ParameterMetadata parameter_metadata_label_type;
            typedef ParameterMetadataPimpl parameter_metadata_pimpl_label_type;
            typedef ParameterMetadataPersistedHandler parameter_metadata_persisted_handler_label_type;
            typedef LocalMetadata local_metadata_label_type;
            typedef LocalMetadataPimpl local_metadata_pimpl_label_type;
            typedef LocalMetadataPersistedHandler local_metadata_persisted_handler_label_type;
            typedef CustomAttributeMetadata custom_attribute_metadata_label_type;
            typedef CustomAttributeMetadataPimpl custom_attribute_metadata_pimpl_label_type;
            typedef CustomAttributeMetadataPersistedHandler custom_attribute_metadata_persisted_handler_label_type;
            typedef AssemblyNameIterator assembly_name_iterator_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_ASSEMBLY_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace AssemblyMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct AssemblyMetadataFacade : 
        AssemblyMetadataFacadeDetail::AssemblyMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_ASSEMBLY_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::AssemblyMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_ASSEMBLY_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    typedef typename facade::metadata_dispenser_pimpl_label_type metadata_dispenser_pimpl_label_type; \
    typedef typename facade::assembly_cache_label_type assembly_cache_label_type; \
    typedef typename facade::assembly_name_range_label_type assembly_name_range_label_type; \
    typedef typename facade::assembly_name_label_type assembly_name_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    typedef typename facade::portable_executable_reader_label_type portable_executable_reader_label_type; \
    friend typename metadata_dispenser_label_type; \
    friend typename metadata_dispenser_pimpl_label_type; \
    friend typename assembly_cache_label_type; \
    friend typename assembly_name_range_label_type; \
    friend typename assembly_name_label_type; \
    friend typename fusion_info_label_type; \
    friend typename strong_name_info_label_type; \
    friend typename portable_executable_info_label_type; \
    friend typename portable_executable_reader_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::metadata_info_label_type metadata_info_label_type; \
    typedef typename facade::metadata_info_pimpl_label_type metadata_info_pimpl_label_type; \
    typedef typename facade::module_metadata_label_type module_metadata_label_type; \
    typedef typename facade::module_metadata_pimpl_label_type module_metadata_pimpl_label_type; \
    typedef typename facade::module_metadata_persisted_handler_label_type module_metadata_persisted_handler_label_type; \
    typedef typename facade::type_metadata_label_type type_metadata_label_type; \
    typedef typename facade::type_metadata_pimpl_label_type type_metadata_pimpl_label_type; \
    typedef typename facade::type_metadata_persisted_handler_label_type type_metadata_persisted_handler_label_type; \
    typedef typename facade::method_metadata_label_type method_metadata_label_type; \
    typedef typename facade::method_metadata_pimpl_label_type method_metadata_pimpl_label_type; \
    typedef typename facade::method_metadata_persisted_handler_label_type method_metadata_persisted_handler_label_type; \
    typedef typename facade::property_metadata_label_type property_metadata_label_type; \
    typedef typename facade::property_metadata_pimpl_label_type property_metadata_pimpl_label_type; \
    typedef typename facade::property_metadata_persisted_handler_label_type property_metadata_persisted_handler_label_type; \
    typedef typename facade::method_body_metadata_label_type method_body_metadata_label_type; \
    typedef typename facade::method_body_metadata_pimpl_label_type method_body_metadata_pimpl_label_type; \
    typedef typename facade::method_body_metadata_persisted_handler_label_type method_body_metadata_persisted_handler_label_type; \
    typedef typename facade::instruction_metadata_label_type instruction_metadata_label_type; \
    typedef typename facade::instruction_metadata_pimpl_label_type instruction_metadata_pimpl_label_type; \
    typedef typename facade::parameter_metadata_label_type parameter_metadata_label_type; \
    typedef typename facade::parameter_metadata_pimpl_label_type parameter_metadata_pimpl_label_type; \
    typedef typename facade::parameter_metadata_persisted_handler_label_type parameter_metadata_persisted_handler_label_type; \
    typedef typename facade::local_metadata_label_type local_metadata_label_type; \
    typedef typename facade::local_metadata_pimpl_label_type local_metadata_pimpl_label_type; \
    typedef typename facade::local_metadata_persisted_handler_label_type local_metadata_persisted_handler_label_type; \
    typedef typename facade::custom_attribute_metadata_label_type custom_attribute_metadata_label_type; \
    typedef typename facade::custom_attribute_metadata_pimpl_label_type custom_attribute_metadata_pimpl_label_type; \
    typedef typename facade::custom_attribute_metadata_persisted_handler_label_type custom_attribute_metadata_persisted_handler_label_type; \
    typedef typename facade::assembly_name_iterator_label_type assembly_name_iterator_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename metadata_info_label_type; \
    friend typename metadata_info_pimpl_label_type; \
    friend typename module_metadata_label_type; \
    friend typename module_metadata_pimpl_label_type; \
    friend typename module_metadata_persisted_handler_label_type; \
    friend typename type_metadata_label_type; \
    friend typename type_metadata_pimpl_label_type; \
    friend typename type_metadata_persisted_handler_label_type; \
    friend typename method_metadata_label_type; \
    friend typename method_metadata_pimpl_label_type; \
    friend typename method_metadata_persisted_handler_label_type; \
    friend typename property_metadata_label_type; \
    friend typename property_metadata_pimpl_label_type; \
    friend typename property_metadata_persisted_handler_label_type; \
    friend typename method_body_metadata_label_type; \
    friend typename method_body_metadata_pimpl_label_type; \
    friend typename method_body_metadata_persisted_handler_label_type; \
    friend typename instruction_metadata_label_type; \
    friend typename instruction_metadata_pimpl_label_type; \
    friend typename parameter_metadata_label_type; \
    friend typename parameter_metadata_pimpl_label_type; \
    friend typename parameter_metadata_persisted_handler_label_type; \
    friend typename local_metadata_label_type; \
    friend typename local_metadata_pimpl_label_type; \
    friend typename local_metadata_persisted_handler_label_type; \
    friend typename custom_attribute_metadata_label_type; \
    friend typename custom_attribute_metadata_pimpl_label_type; \
    friend typename custom_attribute_metadata_persisted_handler_label_type; \
    friend typename assembly_name_iterator_label_type; \

#define SWATHE_END_ASSEMBLY_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYMETADATAFACADE_H

