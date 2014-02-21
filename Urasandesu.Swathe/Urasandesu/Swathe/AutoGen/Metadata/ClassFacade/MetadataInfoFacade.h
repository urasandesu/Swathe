/* 
 * File: MetadataInfoFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METADATAINFOFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METADATAINFOFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_METADATAINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/MetadataInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/FieldMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYGENERATORPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyGeneratorPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGeneratorPimplFwd.h>
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

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_METADATADISPENSERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/MetadataDispenserPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_METADATADISPENSERPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/MetadataDispenserPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_ASSEMBLYMETADATAPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/AssemblyMetadataPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/FieldMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/FieldMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_ASSEMBLYGENERATORPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/AssemblyGeneratorPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGeneratorPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace MetadataInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::MetadataInfoApiAt;
        using Urasandesu::Swathe::Metadata::MetadataInfoPimpl;
        using Urasandesu::Swathe::Metadata::MetadataInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using Urasandesu::Swathe::Metadata::ModuleMetadataPimpl;
        using Urasandesu::Swathe::Metadata::TypeMetadataPimpl;
        using Urasandesu::Swathe::Metadata::MethodMetadataPimpl;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPimpl;
        using Urasandesu::Swathe::Metadata::ParameterMetadataPimpl;
        using Urasandesu::Swathe::Metadata::PropertyMetadataPimpl;
        using Urasandesu::Swathe::Metadata::FieldMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyGeneratorPimplLabel;
        using Urasandesu::Swathe::Metadata::ModuleGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::MethodGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::PropertyGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::FieldGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::MethodBodyGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::ParameterGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::LocalGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::CustomAttributeMetadataPimpl;
        using Urasandesu::Swathe::Metadata::CustomAttributeGeneratorPimpl;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::MetadataDispenserPimplLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::MetadataDispenserPersistedHandlerLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::AssemblyMetadataPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::ModuleMetadata;
        using Urasandesu::Swathe::Metadata::ModuleMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::TypeMetadata;
        using Urasandesu::Swathe::Metadata::TypeMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodMetadata;
        using Urasandesu::Swathe::Metadata::MethodMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadata;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::ParameterMetadata;
        using Urasandesu::Swathe::Metadata::ParameterMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::LocalMetadata;
        using Urasandesu::Swathe::Metadata::LocalMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::PropertyMetadata;
        using Urasandesu::Swathe::Metadata::PropertyMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::FieldMetadata;
        using Urasandesu::Swathe::Metadata::FieldMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::CustomAttributeMetadata;
        using Urasandesu::Swathe::Metadata::CustomAttributeMetadataPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::AssemblyGeneratorPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::ModuleGenerator;
        using Urasandesu::Swathe::Metadata::ModuleGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::TypeGenerator;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodGenerator;
        using Urasandesu::Swathe::Metadata::MethodGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::PropertyGenerator;
        using Urasandesu::Swathe::Metadata::PropertyGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::FieldGenerator;
        using Urasandesu::Swathe::Metadata::FieldGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodBodyGenerator;
        using Urasandesu::Swathe::Metadata::MethodBodyGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::ParameterGenerator;
        using Urasandesu::Swathe::Metadata::ParameterGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::LocalGenerator;
        using Urasandesu::Swathe::Metadata::LocalGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::CustomAttributeGenerator;
        using Urasandesu::Swathe::Metadata::CustomAttributeGeneratorPersistedHandler;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct MetadataInfoFacadeImpl
        {
            typedef MetadataInfo class_type;
            typedef MetadataInfoPimpl class_pimpl_type;
            typedef MetadataInfoPimpl metadata_info_pimpl_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, RuntimeHostPimplLabel>::type runtime_host_pimpl_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyGeneratorPimplLabel>::type assembly_generator_pimpl_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, MetadataDispenserPimplLabel>::type metadata_dispenser_pimpl_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, MetadataDispenserPersistedHandlerLabel>::type metadata_dispenser_persisted_handler_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyMetadataPersistedHandlerLabel>::type assembly_metadata_persisted_handler_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyGeneratorPersistedHandlerLabel>::type assembly_generator_persisted_handler_label_type;

            typedef MetadataInfoPimpl metadata_info_pimpl_label_type;
            typedef MetadataInfo metadata_info_label_type;
            typedef ModuleMetadataPimpl module_metadata_pimpl_label_type;
            typedef TypeMetadataPimpl type_metadata_pimpl_label_type;
            typedef MethodMetadataPimpl method_metadata_pimpl_label_type;
            typedef MethodBodyMetadataPimpl method_body_metadata_pimpl_label_type;
            typedef ParameterMetadataPimpl parameter_metadata_pimpl_label_type;
            typedef PropertyMetadataPimpl property_metadata_pimpl_label_type;
            typedef FieldMetadataPimpl field_metadata_pimpl_label_type;
            typedef ModuleGeneratorPimpl module_generator_pimpl_label_type;
            typedef TypeGeneratorPimpl type_generator_pimpl_label_type;
            typedef MethodGeneratorPimpl method_generator_pimpl_label_type;
            typedef PropertyGeneratorPimpl property_generator_pimpl_label_type;
            typedef FieldGeneratorPimpl field_generator_pimpl_label_type;
            typedef MethodBodyGeneratorPimpl method_body_generator_pimpl_label_type;
            typedef ParameterGeneratorPimpl parameter_generator_pimpl_label_type;
            typedef LocalGeneratorPimpl local_generator_pimpl_label_type;
            typedef CustomAttributeMetadataPimpl custom_attribute_metadata_pimpl_label_type;
            typedef CustomAttributeGeneratorPimpl custom_attribute_generator_pimpl_label_type;
            typedef ModuleMetadata module_metadata_label_type;
            typedef ModuleMetadataPersistedHandler module_metadata_persisted_handler_label_type;
            typedef TypeMetadata type_metadata_label_type;
            typedef TypeMetadataPersistedHandler type_metadata_persisted_handler_label_type;
            typedef MethodMetadata method_metadata_label_type;
            typedef MethodMetadataPersistedHandler method_metadata_persisted_handler_label_type;
            typedef MethodBodyMetadata method_body_metadata_label_type;
            typedef MethodBodyMetadataPersistedHandler method_body_metadata_persisted_handler_label_type;
            typedef ParameterMetadata parameter_metadata_label_type;
            typedef ParameterMetadataPersistedHandler parameter_metadata_persisted_handler_label_type;
            typedef LocalMetadata local_metadata_label_type;
            typedef LocalMetadataPersistedHandler local_metadata_persisted_handler_label_type;
            typedef PropertyMetadata property_metadata_label_type;
            typedef PropertyMetadataPersistedHandler property_metadata_persisted_handler_label_type;
            typedef FieldMetadata field_metadata_label_type;
            typedef FieldMetadataPersistedHandler field_metadata_persisted_handler_label_type;
            typedef CustomAttributeMetadata custom_attribute_metadata_label_type;
            typedef CustomAttributeMetadataPersistedHandler custom_attribute_metadata_persisted_handler_label_type;
            typedef ModuleGenerator module_generator_label_type;
            typedef ModuleGeneratorPersistedHandler module_generator_persisted_handler_label_type;
            typedef TypeGenerator type_generator_label_type;
            typedef TypeGeneratorPersistedHandler type_generator_persisted_handler_label_type;
            typedef MethodGenerator method_generator_label_type;
            typedef MethodGeneratorPersistedHandler method_generator_persisted_handler_label_type;
            typedef PropertyGenerator property_generator_label_type;
            typedef PropertyGeneratorPersistedHandler property_generator_persisted_handler_label_type;
            typedef FieldGenerator field_generator_label_type;
            typedef FieldGeneratorPersistedHandler field_generator_persisted_handler_label_type;
            typedef MethodBodyGenerator method_body_generator_label_type;
            typedef MethodBodyGeneratorPersistedHandler method_body_generator_persisted_handler_label_type;
            typedef ParameterGenerator parameter_generator_label_type;
            typedef ParameterGeneratorPersistedHandler parameter_generator_persisted_handler_label_type;
            typedef LocalGenerator local_generator_label_type;
            typedef LocalGeneratorPersistedHandler local_generator_persisted_handler_label_type;
            typedef CustomAttributeGenerator custom_attribute_generator_label_type;
            typedef CustomAttributeGeneratorPersistedHandler custom_attribute_generator_persisted_handler_label_type;

            
            typedef typename MetadataInfoApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_6307effc_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_6307effc_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_6307effc_type;
            
            typedef typename MetadataInfoApiAt<ApiHolder, MetadataDispenserPersistedHandlerLabel>::type metadata_dispenser_persisted_handler_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyMetadataPersistedHandlerLabel>::type assembly_metadata_persisted_handler_label_type;
            typedef typename MetadataInfoApiAt<ApiHolder, AssemblyGeneratorPersistedHandlerLabel>::type assembly_generator_persisted_handler_label_type;
            
            typedef DisposingInfo<metadata_dispenser_label_6307effc_type, metadata_dispenser_persisted_handler_label_type> metadata_dispenser_label_disposing_info_type;
            typedef DisposingInfo<assembly_metadata_label_6307effc_type, assembly_metadata_persisted_handler_label_type> assembly_metadata_label_disposing_info_type;
            typedef DisposingInfo<assembly_generator_label_6307effc_type, assembly_generator_persisted_handler_label_type> assembly_generator_label_disposing_info_type;
            
            typedef ModuleMetadata module_metadata_label_6307effc_type;
            typedef TypeMetadata type_metadata_label_6307effc_type;
            typedef MethodMetadata method_metadata_label_6307effc_type;
            typedef MethodBodyMetadata method_body_metadata_label_6307effc_type;
            typedef ParameterMetadata parameter_metadata_label_6307effc_type;
            typedef LocalMetadata local_metadata_label_6307effc_type;
            typedef PropertyMetadata property_metadata_label_6307effc_type;
            typedef FieldMetadata field_metadata_label_6307effc_type;
            typedef CustomAttributeMetadata custom_attribute_metadata_label_6307effc_type;
            typedef ModuleGenerator module_generator_label_6307effc_type;
            typedef TypeGenerator type_generator_label_6307effc_type;
            typedef MethodGenerator method_generator_label_6307effc_type;
            typedef PropertyGenerator property_generator_label_6307effc_type;
            typedef FieldGenerator field_generator_label_6307effc_type;
            typedef MethodBodyGenerator method_body_generator_label_6307effc_type;
            typedef ParameterGenerator parameter_generator_label_6307effc_type;
            typedef LocalGenerator local_generator_label_6307effc_type;
            typedef CustomAttributeGenerator custom_attribute_generator_label_6307effc_type;
            
            typedef ModuleMetadataPersistedHandler module_metadata_persisted_handler_label_type;
            typedef TypeMetadataPersistedHandler type_metadata_persisted_handler_label_type;
            typedef MethodMetadataPersistedHandler method_metadata_persisted_handler_label_type;
            typedef MethodBodyMetadataPersistedHandler method_body_metadata_persisted_handler_label_type;
            typedef ParameterMetadataPersistedHandler parameter_metadata_persisted_handler_label_type;
            typedef LocalMetadataPersistedHandler local_metadata_persisted_handler_label_type;
            typedef PropertyMetadataPersistedHandler property_metadata_persisted_handler_label_type;
            typedef FieldMetadataPersistedHandler field_metadata_persisted_handler_label_type;
            typedef CustomAttributeMetadataPersistedHandler custom_attribute_metadata_persisted_handler_label_type;
            typedef ModuleGeneratorPersistedHandler module_generator_persisted_handler_label_type;
            typedef TypeGeneratorPersistedHandler type_generator_persisted_handler_label_type;
            typedef MethodGeneratorPersistedHandler method_generator_persisted_handler_label_type;
            typedef PropertyGeneratorPersistedHandler property_generator_persisted_handler_label_type;
            typedef FieldGeneratorPersistedHandler field_generator_persisted_handler_label_type;
            typedef MethodBodyGeneratorPersistedHandler method_body_generator_persisted_handler_label_type;
            typedef ParameterGeneratorPersistedHandler parameter_generator_persisted_handler_label_type;
            typedef LocalGeneratorPersistedHandler local_generator_persisted_handler_label_type;
            typedef CustomAttributeGeneratorPersistedHandler custom_attribute_generator_persisted_handler_label_type;
            
            typedef DisposingInfo<module_metadata_label_6307effc_type, module_metadata_persisted_handler_label_type> module_metadata_label_disposing_info_type;
            typedef DisposingInfo<type_metadata_label_6307effc_type, type_metadata_persisted_handler_label_type> type_metadata_label_disposing_info_type;
            typedef DisposingInfo<method_metadata_label_6307effc_type, method_metadata_persisted_handler_label_type> method_metadata_label_disposing_info_type;
            typedef DisposingInfo<method_body_metadata_label_6307effc_type, method_body_metadata_persisted_handler_label_type> method_body_metadata_label_disposing_info_type;
            typedef DisposingInfo<parameter_metadata_label_6307effc_type, parameter_metadata_persisted_handler_label_type> parameter_metadata_label_disposing_info_type;
            typedef DisposingInfo<local_metadata_label_6307effc_type, local_metadata_persisted_handler_label_type> local_metadata_label_disposing_info_type;
            typedef DisposingInfo<property_metadata_label_6307effc_type, property_metadata_persisted_handler_label_type> property_metadata_label_disposing_info_type;
            typedef DisposingInfo<field_metadata_label_6307effc_type, field_metadata_persisted_handler_label_type> field_metadata_label_disposing_info_type;
            typedef DisposingInfo<custom_attribute_metadata_label_6307effc_type, custom_attribute_metadata_persisted_handler_label_type> custom_attribute_metadata_label_disposing_info_type;
            typedef DisposingInfo<module_generator_label_6307effc_type, module_generator_persisted_handler_label_type> module_generator_label_disposing_info_type;
            typedef DisposingInfo<type_generator_label_6307effc_type, type_generator_persisted_handler_label_type> type_generator_label_disposing_info_type;
            typedef DisposingInfo<method_generator_label_6307effc_type, method_generator_persisted_handler_label_type> method_generator_label_disposing_info_type;
            typedef DisposingInfo<property_generator_label_6307effc_type, property_generator_persisted_handler_label_type> property_generator_label_disposing_info_type;
            typedef DisposingInfo<field_generator_label_6307effc_type, field_generator_persisted_handler_label_type> field_generator_label_disposing_info_type;
            typedef DisposingInfo<method_body_generator_label_6307effc_type, method_body_generator_persisted_handler_label_type> method_body_generator_label_disposing_info_type;
            typedef DisposingInfo<parameter_generator_label_6307effc_type, parameter_generator_persisted_handler_label_type> parameter_generator_label_disposing_info_type;
            typedef DisposingInfo<local_generator_label_6307effc_type, local_generator_persisted_handler_label_type> local_generator_label_disposing_info_type;
            typedef DisposingInfo<custom_attribute_generator_label_6307effc_type, custom_attribute_generator_persisted_handler_label_type> custom_attribute_generator_label_disposing_info_type;
            
            typedef DisposableHeapProvider<
                module_metadata_label_disposing_info_type,
                type_metadata_label_disposing_info_type,
                method_metadata_label_disposing_info_type,
                method_body_metadata_label_disposing_info_type,
                parameter_metadata_label_disposing_info_type,
                local_metadata_label_disposing_info_type,
                property_metadata_label_disposing_info_type,
                field_metadata_label_disposing_info_type,
                custom_attribute_metadata_label_disposing_info_type,
                module_generator_label_disposing_info_type,
                type_generator_label_disposing_info_type,
                method_generator_label_disposing_info_type,
                property_generator_label_disposing_info_type,
                field_generator_label_disposing_info_type,
                method_body_generator_label_disposing_info_type,
                parameter_generator_label_disposing_info_type,
                local_generator_label_disposing_info_type,
                custom_attribute_generator_label_disposing_info_type,
                metadata_dispenser_label_disposing_info_type,
                assembly_metadata_label_disposing_info_type,
                assembly_generator_label_disposing_info_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_METADATA_INFO_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::metadata_dispenser_persisted_handler_label_type metadata_dispenser_persisted_handler_label_type; \
                typedef typename facade::assembly_metadata_persisted_handler_label_type assembly_metadata_persisted_handler_label_type; \
                typedef typename facade::assembly_generator_persisted_handler_label_type assembly_generator_persisted_handler_label_type; \
                friend typename metadata_dispenser_persisted_handler_label_type; \
                friend typename assembly_metadata_persisted_handler_label_type; \
                friend typename assembly_generator_persisted_handler_label_type; \
                typedef typename facade::metadata_dispenser_label_disposing_info_type metadata_dispenser_label_disposing_info_type; \
                typedef typename facade::assembly_metadata_label_disposing_info_type assembly_metadata_label_disposing_info_type; \
                typedef typename facade::assembly_generator_label_disposing_info_type assembly_generator_label_disposing_info_type; \
                friend typename metadata_dispenser_label_disposing_info_type; \
                friend typename assembly_metadata_label_disposing_info_type; \
                friend typename assembly_generator_label_disposing_info_type; \
                typedef typename facade::module_metadata_persisted_handler_label_type module_metadata_persisted_handler_label_type; \
                typedef typename facade::type_metadata_persisted_handler_label_type type_metadata_persisted_handler_label_type; \
                typedef typename facade::method_metadata_persisted_handler_label_type method_metadata_persisted_handler_label_type; \
                typedef typename facade::method_body_metadata_persisted_handler_label_type method_body_metadata_persisted_handler_label_type; \
                typedef typename facade::parameter_metadata_persisted_handler_label_type parameter_metadata_persisted_handler_label_type; \
                typedef typename facade::local_metadata_persisted_handler_label_type local_metadata_persisted_handler_label_type; \
                typedef typename facade::property_metadata_persisted_handler_label_type property_metadata_persisted_handler_label_type; \
                typedef typename facade::field_metadata_persisted_handler_label_type field_metadata_persisted_handler_label_type; \
                typedef typename facade::custom_attribute_metadata_persisted_handler_label_type custom_attribute_metadata_persisted_handler_label_type; \
                typedef typename facade::module_generator_persisted_handler_label_type module_generator_persisted_handler_label_type; \
                typedef typename facade::type_generator_persisted_handler_label_type type_generator_persisted_handler_label_type; \
                typedef typename facade::method_generator_persisted_handler_label_type method_generator_persisted_handler_label_type; \
                typedef typename facade::property_generator_persisted_handler_label_type property_generator_persisted_handler_label_type; \
                typedef typename facade::field_generator_persisted_handler_label_type field_generator_persisted_handler_label_type; \
                typedef typename facade::method_body_generator_persisted_handler_label_type method_body_generator_persisted_handler_label_type; \
                typedef typename facade::parameter_generator_persisted_handler_label_type parameter_generator_persisted_handler_label_type; \
                typedef typename facade::local_generator_persisted_handler_label_type local_generator_persisted_handler_label_type; \
                typedef typename facade::custom_attribute_generator_persisted_handler_label_type custom_attribute_generator_persisted_handler_label_type; \
                friend typename module_metadata_persisted_handler_label_type; \
                friend typename type_metadata_persisted_handler_label_type; \
                friend typename method_metadata_persisted_handler_label_type; \
                friend typename method_body_metadata_persisted_handler_label_type; \
                friend typename parameter_metadata_persisted_handler_label_type; \
                friend typename local_metadata_persisted_handler_label_type; \
                friend typename property_metadata_persisted_handler_label_type; \
                friend typename field_metadata_persisted_handler_label_type; \
                friend typename custom_attribute_metadata_persisted_handler_label_type; \
                friend typename module_generator_persisted_handler_label_type; \
                friend typename type_generator_persisted_handler_label_type; \
                friend typename method_generator_persisted_handler_label_type; \
                friend typename property_generator_persisted_handler_label_type; \
                friend typename field_generator_persisted_handler_label_type; \
                friend typename method_body_generator_persisted_handler_label_type; \
                friend typename parameter_generator_persisted_handler_label_type; \
                friend typename local_generator_persisted_handler_label_type; \
                friend typename custom_attribute_generator_persisted_handler_label_type; \
                typedef typename facade::module_metadata_label_disposing_info_type module_metadata_label_disposing_info_type; \
                typedef typename facade::type_metadata_label_disposing_info_type type_metadata_label_disposing_info_type; \
                typedef typename facade::method_metadata_label_disposing_info_type method_metadata_label_disposing_info_type; \
                typedef typename facade::method_body_metadata_label_disposing_info_type method_body_metadata_label_disposing_info_type; \
                typedef typename facade::parameter_metadata_label_disposing_info_type parameter_metadata_label_disposing_info_type; \
                typedef typename facade::local_metadata_label_disposing_info_type local_metadata_label_disposing_info_type; \
                typedef typename facade::property_metadata_label_disposing_info_type property_metadata_label_disposing_info_type; \
                typedef typename facade::field_metadata_label_disposing_info_type field_metadata_label_disposing_info_type; \
                typedef typename facade::custom_attribute_metadata_label_disposing_info_type custom_attribute_metadata_label_disposing_info_type; \
                typedef typename facade::module_generator_label_disposing_info_type module_generator_label_disposing_info_type; \
                typedef typename facade::type_generator_label_disposing_info_type type_generator_label_disposing_info_type; \
                typedef typename facade::method_generator_label_disposing_info_type method_generator_label_disposing_info_type; \
                typedef typename facade::property_generator_label_disposing_info_type property_generator_label_disposing_info_type; \
                typedef typename facade::field_generator_label_disposing_info_type field_generator_label_disposing_info_type; \
                typedef typename facade::method_body_generator_label_disposing_info_type method_body_generator_label_disposing_info_type; \
                typedef typename facade::parameter_generator_label_disposing_info_type parameter_generator_label_disposing_info_type; \
                typedef typename facade::local_generator_label_disposing_info_type local_generator_label_disposing_info_type; \
                typedef typename facade::custom_attribute_generator_label_disposing_info_type custom_attribute_generator_label_disposing_info_type; \
                friend typename module_metadata_label_disposing_info_type; \
                friend typename type_metadata_label_disposing_info_type; \
                friend typename method_metadata_label_disposing_info_type; \
                friend typename method_body_metadata_label_disposing_info_type; \
                friend typename parameter_metadata_label_disposing_info_type; \
                friend typename local_metadata_label_disposing_info_type; \
                friend typename property_metadata_label_disposing_info_type; \
                friend typename field_metadata_label_disposing_info_type; \
                friend typename custom_attribute_metadata_label_disposing_info_type; \
                friend typename module_generator_label_disposing_info_type; \
                friend typename type_generator_label_disposing_info_type; \
                friend typename method_generator_label_disposing_info_type; \
                friend typename property_generator_label_disposing_info_type; \
                friend typename field_generator_label_disposing_info_type; \
                friend typename method_body_generator_label_disposing_info_type; \
                friend typename parameter_generator_label_disposing_info_type; \
                friend typename local_generator_label_disposing_info_type; \
                friend typename custom_attribute_generator_label_disposing_info_type; \
            
        };
    
    }   // namespace MetadataInfoFacadeDetail {

    template<
        class ApiHolder
    >    
    struct MetadataInfoFacade : 
        MetadataInfoFacadeDetail::MetadataInfoFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_METADATA_INFO_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::MetadataInfoFacade<ApiHolder> facade;

#define SWATHE_DECLARE_METADATA_INFO_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_METADATA_INFO_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::metadata_info_pimpl_label_type metadata_info_pimpl_label_type; \
    friend typename metadata_info_pimpl_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    typedef typename facade::metadata_dispenser_pimpl_label_type metadata_dispenser_pimpl_label_type; \
    typedef typename facade::metadata_dispenser_persisted_handler_label_type metadata_dispenser_persisted_handler_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_persisted_handler_label_type assembly_metadata_persisted_handler_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::assembly_generator_persisted_handler_label_type assembly_generator_persisted_handler_label_type; \
    friend typename runtime_host_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    friend typename fusion_info_label_type; \
    friend typename portable_executable_info_label_type; \
    friend typename strong_name_info_label_type; \
    friend typename metadata_dispenser_label_type; \
    friend typename metadata_dispenser_pimpl_label_type; \
    friend typename metadata_dispenser_persisted_handler_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_persisted_handler_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename assembly_generator_persisted_handler_label_type; \
    typedef typename facade::metadata_info_pimpl_label_type metadata_info_pimpl_label_type; \
    typedef typename facade::metadata_info_label_type metadata_info_label_type; \
    typedef typename facade::module_metadata_pimpl_label_type module_metadata_pimpl_label_type; \
    typedef typename facade::type_metadata_pimpl_label_type type_metadata_pimpl_label_type; \
    typedef typename facade::method_metadata_pimpl_label_type method_metadata_pimpl_label_type; \
    typedef typename facade::method_body_metadata_pimpl_label_type method_body_metadata_pimpl_label_type; \
    typedef typename facade::parameter_metadata_pimpl_label_type parameter_metadata_pimpl_label_type; \
    typedef typename facade::property_metadata_pimpl_label_type property_metadata_pimpl_label_type; \
    typedef typename facade::field_metadata_pimpl_label_type field_metadata_pimpl_label_type; \
    typedef typename facade::module_generator_pimpl_label_type module_generator_pimpl_label_type; \
    typedef typename facade::type_generator_pimpl_label_type type_generator_pimpl_label_type; \
    typedef typename facade::method_generator_pimpl_label_type method_generator_pimpl_label_type; \
    typedef typename facade::property_generator_pimpl_label_type property_generator_pimpl_label_type; \
    typedef typename facade::field_generator_pimpl_label_type field_generator_pimpl_label_type; \
    typedef typename facade::method_body_generator_pimpl_label_type method_body_generator_pimpl_label_type; \
    typedef typename facade::parameter_generator_pimpl_label_type parameter_generator_pimpl_label_type; \
    typedef typename facade::local_generator_pimpl_label_type local_generator_pimpl_label_type; \
    typedef typename facade::custom_attribute_metadata_pimpl_label_type custom_attribute_metadata_pimpl_label_type; \
    typedef typename facade::custom_attribute_generator_pimpl_label_type custom_attribute_generator_pimpl_label_type; \
    typedef typename facade::module_metadata_label_type module_metadata_label_type; \
    typedef typename facade::module_metadata_persisted_handler_label_type module_metadata_persisted_handler_label_type; \
    typedef typename facade::type_metadata_label_type type_metadata_label_type; \
    typedef typename facade::type_metadata_persisted_handler_label_type type_metadata_persisted_handler_label_type; \
    typedef typename facade::method_metadata_label_type method_metadata_label_type; \
    typedef typename facade::method_metadata_persisted_handler_label_type method_metadata_persisted_handler_label_type; \
    typedef typename facade::method_body_metadata_label_type method_body_metadata_label_type; \
    typedef typename facade::method_body_metadata_persisted_handler_label_type method_body_metadata_persisted_handler_label_type; \
    typedef typename facade::parameter_metadata_label_type parameter_metadata_label_type; \
    typedef typename facade::parameter_metadata_persisted_handler_label_type parameter_metadata_persisted_handler_label_type; \
    typedef typename facade::local_metadata_label_type local_metadata_label_type; \
    typedef typename facade::local_metadata_persisted_handler_label_type local_metadata_persisted_handler_label_type; \
    typedef typename facade::property_metadata_label_type property_metadata_label_type; \
    typedef typename facade::property_metadata_persisted_handler_label_type property_metadata_persisted_handler_label_type; \
    typedef typename facade::field_metadata_label_type field_metadata_label_type; \
    typedef typename facade::field_metadata_persisted_handler_label_type field_metadata_persisted_handler_label_type; \
    typedef typename facade::custom_attribute_metadata_label_type custom_attribute_metadata_label_type; \
    typedef typename facade::custom_attribute_metadata_persisted_handler_label_type custom_attribute_metadata_persisted_handler_label_type; \
    typedef typename facade::module_generator_label_type module_generator_label_type; \
    typedef typename facade::module_generator_persisted_handler_label_type module_generator_persisted_handler_label_type; \
    typedef typename facade::type_generator_label_type type_generator_label_type; \
    typedef typename facade::type_generator_persisted_handler_label_type type_generator_persisted_handler_label_type; \
    typedef typename facade::method_generator_label_type method_generator_label_type; \
    typedef typename facade::method_generator_persisted_handler_label_type method_generator_persisted_handler_label_type; \
    typedef typename facade::property_generator_label_type property_generator_label_type; \
    typedef typename facade::property_generator_persisted_handler_label_type property_generator_persisted_handler_label_type; \
    typedef typename facade::field_generator_label_type field_generator_label_type; \
    typedef typename facade::field_generator_persisted_handler_label_type field_generator_persisted_handler_label_type; \
    typedef typename facade::method_body_generator_label_type method_body_generator_label_type; \
    typedef typename facade::method_body_generator_persisted_handler_label_type method_body_generator_persisted_handler_label_type; \
    typedef typename facade::parameter_generator_label_type parameter_generator_label_type; \
    typedef typename facade::parameter_generator_persisted_handler_label_type parameter_generator_persisted_handler_label_type; \
    typedef typename facade::local_generator_label_type local_generator_label_type; \
    typedef typename facade::local_generator_persisted_handler_label_type local_generator_persisted_handler_label_type; \
    typedef typename facade::custom_attribute_generator_label_type custom_attribute_generator_label_type; \
    typedef typename facade::custom_attribute_generator_persisted_handler_label_type custom_attribute_generator_persisted_handler_label_type; \
    friend typename metadata_info_pimpl_label_type; \
    friend typename metadata_info_label_type; \
    friend typename module_metadata_pimpl_label_type; \
    friend typename type_metadata_pimpl_label_type; \
    friend typename method_metadata_pimpl_label_type; \
    friend typename method_body_metadata_pimpl_label_type; \
    friend typename parameter_metadata_pimpl_label_type; \
    friend typename property_metadata_pimpl_label_type; \
    friend typename field_metadata_pimpl_label_type; \
    friend typename module_generator_pimpl_label_type; \
    friend typename type_generator_pimpl_label_type; \
    friend typename method_generator_pimpl_label_type; \
    friend typename property_generator_pimpl_label_type; \
    friend typename field_generator_pimpl_label_type; \
    friend typename method_body_generator_pimpl_label_type; \
    friend typename parameter_generator_pimpl_label_type; \
    friend typename local_generator_pimpl_label_type; \
    friend typename custom_attribute_metadata_pimpl_label_type; \
    friend typename custom_attribute_generator_pimpl_label_type; \
    friend typename module_metadata_label_type; \
    friend typename module_metadata_persisted_handler_label_type; \
    friend typename type_metadata_label_type; \
    friend typename type_metadata_persisted_handler_label_type; \
    friend typename method_metadata_label_type; \
    friend typename method_metadata_persisted_handler_label_type; \
    friend typename method_body_metadata_label_type; \
    friend typename method_body_metadata_persisted_handler_label_type; \
    friend typename parameter_metadata_label_type; \
    friend typename parameter_metadata_persisted_handler_label_type; \
    friend typename local_metadata_label_type; \
    friend typename local_metadata_persisted_handler_label_type; \
    friend typename property_metadata_label_type; \
    friend typename property_metadata_persisted_handler_label_type; \
    friend typename field_metadata_label_type; \
    friend typename field_metadata_persisted_handler_label_type; \
    friend typename custom_attribute_metadata_label_type; \
    friend typename custom_attribute_metadata_persisted_handler_label_type; \
    friend typename module_generator_label_type; \
    friend typename module_generator_persisted_handler_label_type; \
    friend typename type_generator_label_type; \
    friend typename type_generator_persisted_handler_label_type; \
    friend typename method_generator_label_type; \
    friend typename method_generator_persisted_handler_label_type; \
    friend typename property_generator_label_type; \
    friend typename property_generator_persisted_handler_label_type; \
    friend typename field_generator_label_type; \
    friend typename field_generator_persisted_handler_label_type; \
    friend typename method_body_generator_label_type; \
    friend typename method_body_generator_persisted_handler_label_type; \
    friend typename parameter_generator_label_type; \
    friend typename parameter_generator_persisted_handler_label_type; \
    friend typename local_generator_label_type; \
    friend typename local_generator_persisted_handler_label_type; \
    friend typename custom_attribute_generator_label_type; \
    friend typename custom_attribute_generator_persisted_handler_label_type; \

#define SWATHE_END_METADATA_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METADATAINFOFACADE_H

