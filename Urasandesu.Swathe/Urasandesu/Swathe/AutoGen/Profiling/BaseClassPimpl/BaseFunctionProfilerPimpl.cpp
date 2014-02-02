/* 
 * File: BaseFunctionProfilerPimpl.cpp
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

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_HPP
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseFunctionProfilerPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTFUNCTIONPROFILERPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPimplApiHolder/DefaultFunctionProfilerPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTFUNCTIONPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultFunctionProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseFunctionProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTAPPDOMAINPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultAppDomainProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEAPPDOMAINPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseAppDomainProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultAssemblyProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEASSEMBLYPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseAssemblyProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultModuleProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEMODULEPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseModuleProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTFUNCTIONBODYPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultFunctionBodyProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEFUNCTIONBODYPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseFunctionBodyProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROCESSPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultProcessProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProcessProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyGenerator.h>
#endif

extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseFunctionProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseAppDomainProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseAssemblyProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseModuleProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseFunctionBodyProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseProcessProfiler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseAssemblyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodBodyGenerator<>;
template class Urasandesu::Swathe::Profiling::BaseClassPimpl::BaseFunctionProfilerPimpl<>;
SWATHE_DECLARE_BASE_FUNCTION_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION

