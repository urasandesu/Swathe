/* 
 * File: BaseRuntimeHostPimpl.cpp
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

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASERUNTIMEHOSTPIMPL_HPP
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BaseRuntimeHostPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTRUNTIMEHOSTPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassPimplApiHolder/DefaultRuntimeHostPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseRuntimeHost.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEFUSIONINFO_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseFusionInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTFUSIONINFOPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassPersistedHandlerApiHolder/DefaultFusionInfoPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPERSISTEDHANDLER_BASEFUSIONINFOPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Fusion/BaseClassPersistedHandler/BaseFusionInfoPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMETADATAINFOPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultMetadataInfoPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETADATAINFOPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMetadataInfoPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/DefaultClassApiHolder/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEINFO_H
#include <Urasandesu/Swathe/StrongNaming/BaseClass/BaseStrongNameInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTSTRONGNAMEINFOPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/DefaultClassPersistedHandlerApiHolder/DefaultStrongNameInfoPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPERSISTEDHANDLER_BASESTRONGNAMEINFOPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/StrongNaming/BaseClassPersistedHandler/BaseStrongNameInfoPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultPortableExecutableInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassPersistedHandlerApiHolder/DefaultPortableExecutableInfoPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPERSISTEDHANDLER_BASEPORTABLEEXECUTABLEINFOPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Hosting/BaseClassPersistedHandler/BasePortableExecutableInfoPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROFILINGINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultProfilingInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProfilingInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPROFILINGINFOPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultProfilingInfoPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEPROFILINGINFOPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseProfilingInfoPersistedHandler.h>
#endif

extern template class Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>;
extern template class Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<>;
extern template class Urasandesu::Swathe::Fusion::BaseClassPersistedHandler::BaseFusionInfoPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMetadataInfoPersistedHandler<>;
extern template class Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<>;
extern template class Urasandesu::Swathe::StrongNaming::BaseClassPersistedHandler::BaseStrongNameInfoPersistedHandler<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<>;
extern template class Urasandesu::Swathe::Hosting::BaseClassPersistedHandler::BasePortableExecutableInfoPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseProfilingInfoPersistedHandler<>;
template class Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseRuntimeHostPimpl<>;
SWATHE_DECLARE_BASE_RUNTIME_HOST_PIMPL_ADDITIONAL_INSTANTIATION

