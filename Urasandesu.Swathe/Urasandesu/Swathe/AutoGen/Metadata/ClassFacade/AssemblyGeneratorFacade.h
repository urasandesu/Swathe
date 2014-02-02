/* 
 * File: AssemblyGeneratorFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYGENERATORFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYGENERATORFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_ASSEMBLYGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/AssemblyGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyGeneratorFwd.h>
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

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEKEYLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameKeyLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEWRITERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableWriterLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_FUNCTIONPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/FunctionProfilerPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace AssemblyGeneratorFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::AssemblyGeneratorApiAt;
        using Urasandesu::Swathe::Metadata::AssemblyGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::AssemblyGenerator;
        using Urasandesu::Swathe::Metadata::MetadataInfo;
        using Urasandesu::Swathe::Metadata::MetadataInfoPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::MetadataDispenserPimplLabel;
        using Urasandesu::Swathe::Metadata::ModuleGenerator;
        using Urasandesu::Swathe::Metadata::ModuleGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::ModuleGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::TypeGenerator;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodGenerator;
        using Urasandesu::Swathe::Metadata::MethodGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::MethodGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::FieldGenerator;
        using Urasandesu::Swathe::Metadata::FieldGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::FieldGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::PropertyGenerator;
        using Urasandesu::Swathe::Metadata::PropertyGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::PropertyGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodBodyGenerator;
        using Urasandesu::Swathe::Metadata::MethodBodyGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::MethodBodyGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::InstructionGenerator;
        using Urasandesu::Swathe::Metadata::InstructionGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::ParameterGenerator;
        using Urasandesu::Swathe::Metadata::ParameterGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::ParameterGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::LocalGenerator;
        using Urasandesu::Swathe::Metadata::LocalGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::LocalGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::CustomAttributeGenerator;
        using Urasandesu::Swathe::Metadata::CustomAttributeGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::CustomAttributeGeneratorPersistedHandler;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameKeyLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableWriterLabel;
        using Urasandesu::Swathe::Profiling::FunctionProfiler;
        using Urasandesu::Swathe::Profiling::FunctionProfilerPimpl;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct AssemblyGeneratorFacadeImpl
        {
            typedef AssemblyGenerator class_type;
            typedef AssemblyGeneratorPimpl class_pimpl_type;
            typedef AssemblyGeneratorPimpl assembly_generator_pimpl_label_type;
            typedef typename AssemblyGeneratorApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_type;
            typedef typename AssemblyGeneratorApiAt<ApiHolder, MetadataDispenserPimplLabel>::type metadata_dispenser_pimpl_label_type;
            typedef typename AssemblyGeneratorApiAt<ApiHolder, StrongNameKeyLabel>::type strong_name_key_label_type;
            typedef typename AssemblyGeneratorApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_type;
            typedef typename AssemblyGeneratorApiAt<ApiHolder, PortableExecutableWriterLabel>::type portable_executable_writer_label_type;

            typedef AssemblyGeneratorPimpl assembly_generator_pimpl_label_type;
            typedef AssemblyGenerator assembly_generator_label_type;
            typedef MetadataInfo metadata_info_label_type;
            typedef MetadataInfoPimpl metadata_info_pimpl_label_type;
            typedef ModuleGenerator module_generator_label_type;
            typedef ModuleGeneratorPimpl module_generator_pimpl_label_type;
            typedef ModuleGeneratorPersistedHandler module_generator_persisted_handler_label_type;
            typedef TypeGenerator type_generator_label_type;
            typedef TypeGeneratorPimpl type_generator_pimpl_label_type;
            typedef TypeGeneratorPersistedHandler type_generator_persisted_handler_label_type;
            typedef MethodGenerator method_generator_label_type;
            typedef MethodGeneratorPimpl method_generator_pimpl_label_type;
            typedef MethodGeneratorPersistedHandler method_generator_persisted_handler_label_type;
            typedef FieldGenerator field_generator_label_type;
            typedef FieldGeneratorPimpl field_generator_pimpl_label_type;
            typedef FieldGeneratorPersistedHandler field_generator_persisted_handler_label_type;
            typedef PropertyGenerator property_generator_label_type;
            typedef PropertyGeneratorPimpl property_generator_pimpl_label_type;
            typedef PropertyGeneratorPersistedHandler property_generator_persisted_handler_label_type;
            typedef MethodBodyGenerator method_body_generator_label_type;
            typedef MethodBodyGeneratorPimpl method_body_generator_pimpl_label_type;
            typedef MethodBodyGeneratorPersistedHandler method_body_generator_persisted_handler_label_type;
            typedef InstructionGenerator instruction_generator_label_type;
            typedef InstructionGeneratorPimpl instruction_generator_pimpl_label_type;
            typedef ParameterGenerator parameter_generator_label_type;
            typedef ParameterGeneratorPimpl parameter_generator_pimpl_label_type;
            typedef ParameterGeneratorPersistedHandler parameter_generator_persisted_handler_label_type;
            typedef LocalGenerator local_generator_label_type;
            typedef LocalGeneratorPimpl local_generator_pimpl_label_type;
            typedef LocalGeneratorPersistedHandler local_generator_persisted_handler_label_type;
            typedef CustomAttributeGenerator custom_attribute_generator_label_type;
            typedef CustomAttributeGeneratorPimpl custom_attribute_generator_pimpl_label_type;
            typedef CustomAttributeGeneratorPersistedHandler custom_attribute_generator_persisted_handler_label_type;
            typedef FunctionProfiler function_profiler_label_type;
            typedef FunctionProfilerPimpl function_profiler_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_ASSEMBLY_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace AssemblyGeneratorFacadeDetail {

    template<
        class ApiHolder
    >    
    struct AssemblyGeneratorFacade : 
        AssemblyGeneratorFacadeDetail::AssemblyGeneratorFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_ASSEMBLY_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::AssemblyGeneratorFacade<ApiHolder> facade;

#define SWATHE_DECLARE_ASSEMBLY_GENERATOR_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    typedef typename facade::metadata_dispenser_pimpl_label_type metadata_dispenser_pimpl_label_type; \
    typedef typename facade::strong_name_key_label_type strong_name_key_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    typedef typename facade::portable_executable_writer_label_type portable_executable_writer_label_type; \
    friend typename metadata_dispenser_label_type; \
    friend typename metadata_dispenser_pimpl_label_type; \
    friend typename strong_name_key_label_type; \
    friend typename portable_executable_info_label_type; \
    friend typename portable_executable_writer_label_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::metadata_info_label_type metadata_info_label_type; \
    typedef typename facade::metadata_info_pimpl_label_type metadata_info_pimpl_label_type; \
    typedef typename facade::module_generator_label_type module_generator_label_type; \
    typedef typename facade::module_generator_pimpl_label_type module_generator_pimpl_label_type; \
    typedef typename facade::module_generator_persisted_handler_label_type module_generator_persisted_handler_label_type; \
    typedef typename facade::type_generator_label_type type_generator_label_type; \
    typedef typename facade::type_generator_pimpl_label_type type_generator_pimpl_label_type; \
    typedef typename facade::type_generator_persisted_handler_label_type type_generator_persisted_handler_label_type; \
    typedef typename facade::method_generator_label_type method_generator_label_type; \
    typedef typename facade::method_generator_pimpl_label_type method_generator_pimpl_label_type; \
    typedef typename facade::method_generator_persisted_handler_label_type method_generator_persisted_handler_label_type; \
    typedef typename facade::field_generator_label_type field_generator_label_type; \
    typedef typename facade::field_generator_pimpl_label_type field_generator_pimpl_label_type; \
    typedef typename facade::field_generator_persisted_handler_label_type field_generator_persisted_handler_label_type; \
    typedef typename facade::property_generator_label_type property_generator_label_type; \
    typedef typename facade::property_generator_pimpl_label_type property_generator_pimpl_label_type; \
    typedef typename facade::property_generator_persisted_handler_label_type property_generator_persisted_handler_label_type; \
    typedef typename facade::method_body_generator_label_type method_body_generator_label_type; \
    typedef typename facade::method_body_generator_pimpl_label_type method_body_generator_pimpl_label_type; \
    typedef typename facade::method_body_generator_persisted_handler_label_type method_body_generator_persisted_handler_label_type; \
    typedef typename facade::instruction_generator_label_type instruction_generator_label_type; \
    typedef typename facade::instruction_generator_pimpl_label_type instruction_generator_pimpl_label_type; \
    typedef typename facade::parameter_generator_label_type parameter_generator_label_type; \
    typedef typename facade::parameter_generator_pimpl_label_type parameter_generator_pimpl_label_type; \
    typedef typename facade::parameter_generator_persisted_handler_label_type parameter_generator_persisted_handler_label_type; \
    typedef typename facade::local_generator_label_type local_generator_label_type; \
    typedef typename facade::local_generator_pimpl_label_type local_generator_pimpl_label_type; \
    typedef typename facade::local_generator_persisted_handler_label_type local_generator_persisted_handler_label_type; \
    typedef typename facade::custom_attribute_generator_label_type custom_attribute_generator_label_type; \
    typedef typename facade::custom_attribute_generator_pimpl_label_type custom_attribute_generator_pimpl_label_type; \
    typedef typename facade::custom_attribute_generator_persisted_handler_label_type custom_attribute_generator_persisted_handler_label_type; \
    typedef typename facade::function_profiler_label_type function_profiler_label_type; \
    typedef typename facade::function_profiler_pimpl_label_type function_profiler_pimpl_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename metadata_info_label_type; \
    friend typename metadata_info_pimpl_label_type; \
    friend typename module_generator_label_type; \
    friend typename module_generator_pimpl_label_type; \
    friend typename module_generator_persisted_handler_label_type; \
    friend typename type_generator_label_type; \
    friend typename type_generator_pimpl_label_type; \
    friend typename type_generator_persisted_handler_label_type; \
    friend typename method_generator_label_type; \
    friend typename method_generator_pimpl_label_type; \
    friend typename method_generator_persisted_handler_label_type; \
    friend typename field_generator_label_type; \
    friend typename field_generator_pimpl_label_type; \
    friend typename field_generator_persisted_handler_label_type; \
    friend typename property_generator_label_type; \
    friend typename property_generator_pimpl_label_type; \
    friend typename property_generator_persisted_handler_label_type; \
    friend typename method_body_generator_label_type; \
    friend typename method_body_generator_pimpl_label_type; \
    friend typename method_body_generator_persisted_handler_label_type; \
    friend typename instruction_generator_label_type; \
    friend typename instruction_generator_pimpl_label_type; \
    friend typename parameter_generator_label_type; \
    friend typename parameter_generator_pimpl_label_type; \
    friend typename parameter_generator_persisted_handler_label_type; \
    friend typename local_generator_label_type; \
    friend typename local_generator_pimpl_label_type; \
    friend typename local_generator_persisted_handler_label_type; \
    friend typename custom_attribute_generator_label_type; \
    friend typename custom_attribute_generator_pimpl_label_type; \
    friend typename custom_attribute_generator_persisted_handler_label_type; \
    friend typename function_profiler_label_type; \
    friend typename function_profiler_pimpl_label_type; \

#define SWATHE_END_ASSEMBLY_GENERATOR_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYGENERATORFACADE_H

