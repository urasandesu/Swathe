/* 
 * File: DefaultRuntimeHostApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROFILINGINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProfilingInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROFILINGINFOFWD_H
#include <Urasandesu/Swathe/Profiling/ProfilingInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPERSISTEDHANDLERLABEL_PROFILINGINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPersistedHandlerLabel/ProfilingInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROFILINGINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/ProfilingInfoPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATAINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_METADATAINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/MetadataInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataInfoPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFOFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPERSISTEDHANDLERLABEL_PORTABLEEXECUTABLEINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPersistedHandlerLabel/PortableExecutableInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfoPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFOFWD_H
#include <Urasandesu/Swathe/Fusion/FusionInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPERSISTEDHANDLERLABEL_FUSIONINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPersistedHandlerLabel/FusionInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Fusion/FusionInfoPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPERSISTEDHANDLERLABEL_STRONGNAMEINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPersistedHandlerLabel/StrongNameInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace DefaultClassApiHolder { 

    namespace DefaultRuntimeHostApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProfilingInfoLabel;
        using Urasandesu::Swathe::Profiling::ProfilingInfo;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPersistedHandlerLabel::ProfilingInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::Profiling::ProfilingInfoPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataInfoLabel;
        using Urasandesu::Swathe::Metadata::MetadataInfo;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::MetadataInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::MetadataInfoPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPersistedHandlerLabel::PortableExecutableInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableInfoPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::Fusion::FusionInfo;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPersistedHandlerLabel::FusionInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::Fusion::FusionInfoPersistedHandler;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfo;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassPersistedHandlerLabel::StrongNameInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfoPersistedHandler;
        using mpl::map;
        using mpl::pair;

        struct DefaultRuntimeHostApiHolderImpl
        {
            typedef map<
                pair<ProfilingInfoLabel, ProfilingInfo>,
                pair<ProfilingInfoPersistedHandlerLabel, ProfilingInfoPersistedHandler>,
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<MetadataInfoPersistedHandlerLabel, MetadataInfoPersistedHandler>,
                pair<PortableExecutableInfoLabel, PortableExecutableInfo>,
                pair<PortableExecutableInfoPersistedHandlerLabel, PortableExecutableInfoPersistedHandler>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<FusionInfoPersistedHandlerLabel, FusionInfoPersistedHandler>,
                pair<StrongNameInfoLabel, StrongNameInfo>,
                pair<StrongNameInfoPersistedHandlerLabel, StrongNameInfoPersistedHandler>
            > api_cartridges;
        };
    
    }   // namespace DefaultRuntimeHostApiHolderDetail {

    struct DefaultRuntimeHostApiHolder : 
        DefaultRuntimeHostApiHolderDetail::DefaultRuntimeHostApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H

