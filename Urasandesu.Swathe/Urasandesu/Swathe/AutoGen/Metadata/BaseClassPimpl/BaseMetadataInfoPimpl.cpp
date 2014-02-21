/* 
 * File: BaseMetadataInfoPimpl.cpp
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


#include "stdafx.h"

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_HPP
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMetadataInfoPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTMETADATAINFOPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPimplApiHolder/DefaultMetadataInfoPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataDispenser.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMETADATADISPENSERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultMetadataDispenserPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETADATADISPENSERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMetadataDispenserPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTASSEMBLYMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultAssemblyMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEASSEMBLYMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseAssemblyMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultModuleMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseModuleMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMODULEMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultModuleMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMODULEMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseModuleMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTTYPEMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultTypeMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASETYPEMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseTypeMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMETHODMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultMethodMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETHODMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMethodMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPROPERTYMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultPropertyMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEPROPERTYMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BasePropertyMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTFIELDMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultFieldMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseFieldMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTFIELDMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultFieldMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEFIELDMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseFieldMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMETHODBODYMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultMethodBodyMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETHODBODYMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMethodBodyMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPARAMETERMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultParameterMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseParameterMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPARAMETERMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultParameterMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEPARAMETERMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseParameterMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTLOCALMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultLocalMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseLocalMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTLOCALMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultLocalMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASELOCALMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseLocalMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTCUSTOMATTRIBUTEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultCustomAttributeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseCustomAttributeMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTCUSTOMATTRIBUTEMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultCustomAttributeMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASECUSTOMATTRIBUTEMETADATAPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseCustomAttributeMetadataPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTASSEMBLYGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultAssemblyGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEASSEMBLYGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseAssemblyGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultModuleGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseModuleGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMODULEGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultModuleGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMODULEGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseModuleGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTTYPEGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultTypeGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASETYPEGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseTypeGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMETHODGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultMethodGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETHODGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMethodGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPROPERTYGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultPropertyGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEPROPERTYGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BasePropertyGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTFIELDGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultFieldGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseFieldGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTFIELDGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultFieldGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEFIELDGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseFieldGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPARAMETERGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultParameterGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseParameterGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPARAMETERGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultParameterGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEPARAMETERGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseParameterGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMETHODBODYGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultMethodBodyGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETHODBODYGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMethodBodyGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTLOCALGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultLocalGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseLocalGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTLOCALGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultLocalGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASELOCALGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseLocalGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTCUSTOMATTRIBUTEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultCustomAttributeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseCustomAttributeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTCUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultCustomAttributeGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASECUSTOMATTRIBUTEGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseCustomAttributeGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseRuntimeHost.h>
#endif

extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataDispenser<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMetadataDispenserPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseAssemblyMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseAssemblyMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseModuleMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseModuleMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseTypeMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseTypeMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMethodMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BasePropertyMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BasePropertyMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseFieldMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseFieldMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodBodyMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMethodBodyMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseParameterMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseParameterMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseLocalMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseLocalMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseCustomAttributeMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseCustomAttributeMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseAssemblyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseAssemblyGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseModuleGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseModuleGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseTypeGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseTypeGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMethodGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BasePropertyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BasePropertyGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseFieldGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseFieldGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseParameterGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseParameterGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodBodyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMethodBodyGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseLocalGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseLocalGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseCustomAttributeGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseCustomAttributeGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>;
template class Urasandesu::Swathe::Metadata::BaseClassPimpl::BaseMetadataInfoPimpl<>;
SWATHE_DECLARE_BASE_METADATA_INFO_PIMPL_ADDITIONAL_INSTANTIATION

