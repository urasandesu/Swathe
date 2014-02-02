/* 
 * File: BaseAssemblyMetadataPimpl.cpp
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

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_HPP
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseAssemblyMetadataPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTASSEMBLYMETADATAPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPimplApiHolder/DefaultAssemblyMetadataPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyMetadata.h>
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

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEFUSIONINFO_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseFusionInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYINFO_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYCACHEAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyCacheApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyCache.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYNAMERANGEAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyNameRangeApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyNameRange.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYNAMEITERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyNameIteratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyNameIterator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYNAMEAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyNameApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAME_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyName.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/DefaultClassApiHolder/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEINFO_H
#include <Urasandesu/Swathe/StrongNaming/BaseClass/BaseStrongNameInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultPortableExecutableInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEREADERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultPortableExecutableReaderApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableReader.h>
#endif

extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseAssemblyMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataDispenser<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseModuleMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseModuleMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseTypeMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseTypeMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMethodMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BasePropertyMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BasePropertyMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodBodyMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMethodBodyMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseParameterMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseParameterMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseLocalMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseLocalMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseCustomAttributeMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseCustomAttributeMetadataPersistedHandler<>;
extern template class Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<>;
extern template class Urasandesu::Swathe::Fusion::BaseClass::BaseAssemblyInfo<>;
extern template class Urasandesu::Swathe::Fusion::BaseClass::BaseAssemblyCache<>;
extern template class Urasandesu::Swathe::Fusion::BaseClass::BaseAssemblyNameRange<>;
extern template class Urasandesu::Swathe::Fusion::BaseClass::BaseAssemblyNameIterator<>;
extern template class Urasandesu::Swathe::Fusion::BaseClass::BaseAssemblyName<>;
extern template class Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableReader<>;
template class Urasandesu::Swathe::Metadata::BaseClassPimpl::BaseAssemblyMetadataPimpl<>;
SWATHE_DECLARE_BASE_ASSEMBLY_METADATA_PIMPL_ADDITIONAL_INSTANTIATION

