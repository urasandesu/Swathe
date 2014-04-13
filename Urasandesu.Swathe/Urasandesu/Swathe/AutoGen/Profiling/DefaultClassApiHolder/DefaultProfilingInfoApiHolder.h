/* 
 * File: DefaultProfilingInfoApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROFILINGINFOAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROFILINGINFOAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROCESSPROFILERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProcessProfilerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROCESSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/ProcessProfilerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROCESSPROFILERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProcessProfilerPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROCESSPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/ProcessProfilerPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPERSISTEDHANDLERLABEL_PROCESSPROFILERPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPersistedHandlerLabel/ProcessProfilerPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROCESSPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/ProcessProfilerPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATAINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_RUNTIMEHOSTFWD_H
#include <Urasandesu/Swathe/Hosting/RuntimeHostFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_RUNTIMEHOSTPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/RuntimeHostPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace DefaultClassApiHolder { 

    namespace DefaultProfilingInfoApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProcessProfilerLabel;
        using Urasandesu::Swathe::Profiling::ProcessProfiler;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProcessProfilerPimplLabel;
        using Urasandesu::Swathe::Profiling::ProcessProfilerPimpl;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPersistedHandlerLabel::ProcessProfilerPersistedHandlerLabel;
        using Urasandesu::Swathe::Profiling::ProcessProfilerPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataInfoLabel;
        using Urasandesu::Swathe::Metadata::MetadataInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHost;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHostPimpl;
        using mpl::map;
        using mpl::pair;

        struct DefaultProfilingInfoApiHolderImpl
        {
            typedef map<
                pair<ProcessProfilerLabel, ProcessProfiler>,
                pair<ProcessProfilerPimplLabel, ProcessProfilerPimpl>,
                pair<ProcessProfilerPersistedHandlerLabel, ProcessProfilerPersistedHandler>,
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<RuntimeHostPimplLabel, RuntimeHostPimpl>
            > api_cartridges;
        };
    
    }   // namespace DefaultProfilingInfoApiHolderDetail {

    struct DefaultProfilingInfoApiHolder : 
        DefaultProfilingInfoApiHolderDetail::DefaultProfilingInfoApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROFILINGINFOAPIHOLDER_H

