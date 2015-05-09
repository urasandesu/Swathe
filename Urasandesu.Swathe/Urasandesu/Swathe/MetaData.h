/* 
 * File: MetaData.h
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
#ifndef URASANDESU_SWATHE_METADATA_H
#define URASANDESU_SWATHE_METADATA_H

#ifndef URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H
#include <Urasandesu/Swathe/Metadata/MetadataDependsOn.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultModuleMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultModuleGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTFIELDGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultFieldGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPARAMETERMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultParameterMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPARAMETERGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultParameterGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTLOCALMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultLocalMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTLOCALGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultLocalGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTINSTRUCTIONMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultInstructionMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTINSTRUCTIONGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultInstructionGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTCUSTOMATTRIBUTEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultCustomAttributeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTCUSTOMATTRIBUTEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultCustomAttributeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFO_H
#include <Urasandesu/Swathe/Metadata/MetadataInfo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADISPENSER_H
#include <Urasandesu/Swathe/Metadata/MetadataDispenser.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATA_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/AssemblyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATA_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/ModuleGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATA_H
#include <Urasandesu/Swathe/Metadata/TypeMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/TypeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATA_H
#include <Urasandesu/Swathe/Metadata/MethodMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATOR_H
#include <Urasandesu/Swathe/Metadata/MethodGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATOR_H
#include <Urasandesu/Swathe/Metadata/FieldGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATA_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/PropertyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATA_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATOR_H
#include <Urasandesu/Swathe/Metadata/ParameterGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATA_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATA_H
#include <Urasandesu/Swathe/Metadata/LocalMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATOR_H
#include <Urasandesu/Swathe/Metadata/LocalGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONMETADATA_H
#include <Urasandesu/Swathe/Metadata/InstructionMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONGENERATOR_H
#include <Urasandesu/Swathe/Metadata/InstructionGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEMETADATA_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP
#include <Urasandesu/Swathe/Metadata/IMetaDataImport2Impl.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODETYPES_H
#include <Urasandesu/Swathe/Metadata/OpCodeTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURTYPES_H
#include <Urasandesu/Swathe/Metadata/StackBehaviourTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMTYPES_H
#include <Urasandesu/Swathe/Metadata/OperandParamTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDTYPES_H
#include <Urasandesu/Swathe/Metadata/OpCodeKindTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWTYPES_H
#include <Urasandesu/Swathe/Metadata/ControlFlowTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOUR_H
#include <Urasandesu/Swathe/Metadata/StackBehaviour.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP
#include <Urasandesu/Swathe/Metadata/StackBehaviours.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAM_H
#include <Urasandesu/Swathe/Metadata/OperandParam.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMS_HPP
#include <Urasandesu/Swathe/Metadata/OperandParams.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKIND_H
#include <Urasandesu/Swathe/Metadata/OpCodeKind.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDS_HPP
#include <Urasandesu/Swathe/Metadata/OpCodeKinds.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOW_H
#include <Urasandesu/Swathe/Metadata/ControlFlow.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP
#include <Urasandesu/Swathe/Metadata/ControlFlows.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODE_H
#include <Urasandesu/Swathe/Metadata/OpCode.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODES_H
#include <Urasandesu/Swathe/Metadata/OpCodes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYRESOLVER_H
#include <Urasandesu/Swathe/Metadata/AssemblyResolver.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/PropertyAttributes.hpp>
#endif

#endif  // #ifndef URASANDESU_SWATHE_METADATA_H
