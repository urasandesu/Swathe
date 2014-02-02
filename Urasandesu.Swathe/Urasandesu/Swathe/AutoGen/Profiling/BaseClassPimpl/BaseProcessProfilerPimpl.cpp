/* 
 * File: BaseProcessProfilerPimpl.cpp
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

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROCESSPROFILERPIMPL_HPP
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseProcessProfilerPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTPROCESSPROFILERPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPimplApiHolder/DefaultProcessProfilerPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROCESSPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultProcessProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProcessProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPROCESSPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultProcessProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEPROCESSPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseProcessProfilerPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTFUNCTIONPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultFunctionProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseFunctionProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTFUNCTIONPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultFunctionProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEFUNCTIONPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseFunctionProfilerPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTFUNCTIONBODYPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultFunctionBodyProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseFunctionBodyProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTFUNCTIONBODYPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultFunctionBodyProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEFUNCTIONBODYPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseFunctionBodyProfilerPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTCLASSPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultClassProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASECLASSPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseClassProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTCLASSPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultClassProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASECLASSPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseClassProfilerPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultModuleProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEMODULEPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseModuleProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMODULEPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultModuleProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEMODULEPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseModuleProfilerPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultAssemblyProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEASSEMBLYPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseAssemblyProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTASSEMBLYPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultAssemblyProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEASSEMBLYPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseAssemblyProfilerPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTAPPDOMAINPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultAppDomainProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEAPPDOMAINPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseAppDomainProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTAPPDOMAINPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultAppDomainProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEAPPDOMAINPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseAppDomainProfilerPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROFILINGINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultProfilingInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROFILINGINFO_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProfilingInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseRuntimeHost.h>
#endif

extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseProcessProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseProcessProfilerPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseFunctionProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseFunctionProfilerPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseFunctionBodyProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseFunctionBodyProfilerPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseClassProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseClassProfilerPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseModuleProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseModuleProfilerPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseAssemblyProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseAssemblyProfilerPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseAppDomainProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseAppDomainProfilerPersistedHandler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>;
template class Urasandesu::Swathe::Profiling::BaseClassPimpl::BaseProcessProfilerPimpl<>;
SWATHE_DECLARE_BASE_PROCESS_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION

