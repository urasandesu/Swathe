/* 
 * File: RuntimeHostFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_RUNTIMEHOSTFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_RUNTIMEHOSTFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSAPIAT_RUNTIMEHOSTAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassApiAt/RuntimeHostApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_RUNTIMEHOSTPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/RuntimeHostPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_RUNTIMEHOSTFWD_H
#include <Urasandesu/Swathe/Hosting/RuntimeHostFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/HostInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLLABEL_PROFILINGINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplLabel/ProfilingInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_METADATAINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/MetadataInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_PORTABLEEXECUTABLEINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/PortableExecutableInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_FUSIONINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/FusionInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPIMPLLABEL_STRONGNAMEINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPimplLabel/StrongNameInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSLABEL_PROFILINGINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassLabel/ProfilingInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPERSISTEDHANDLERLABEL_PROFILINGINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPersistedHandlerLabel/ProfilingInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATAINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_METADATAINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/MetadataInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPERSISTEDHANDLERLABEL_PORTABLEEXECUTABLEINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPersistedHandlerLabel/PortableExecutableInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPERSISTEDHANDLERLABEL_FUSIONINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPersistedHandlerLabel/FusionInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPERSISTEDHANDLERLABEL_STRONGNAMEINFOPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPersistedHandlerLabel/StrongNameInfoPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFOFWD_H
#include <Urasandesu/Swathe/Hosting/HostInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Hosting/HostInfoPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

    namespace RuntimeHostFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassApiAt::RuntimeHostApiAt;
        using Urasandesu::Swathe::Hosting::RuntimeHostPimpl;
        using Urasandesu::Swathe::Hosting::RuntimeHost;
        using Urasandesu::Swathe::Hosting::HostInfoPimpl;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPimplLabel::ProfilingInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::MetadataInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::PortableExecutableInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::FusionInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassPimplLabel::StrongNameInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassLabel::ProfilingInfoLabel;
        using Urasandesu::Swathe::AutoGen::Profiling::ClassPersistedHandlerLabel::ProfilingInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataInfoLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::MetadataInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPersistedHandlerLabel::PortableExecutableInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPersistedHandlerLabel::FusionInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassPersistedHandlerLabel::StrongNameInfoPersistedHandlerLabel;
        using Urasandesu::Swathe::Hosting::HostInfo;
        using Urasandesu::Swathe::Hosting::HostInfoPersistedHandler;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct RuntimeHostFacadeImpl
        {
            typedef RuntimeHost class_type;
            typedef RuntimeHostPimpl class_pimpl_type;
            typedef RuntimeHostPimpl runtime_host_pimpl_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, ProfilingInfoPimplLabel>::type profiling_info_pimpl_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, MetadataInfoPimplLabel>::type metadata_info_pimpl_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, PortableExecutableInfoPimplLabel>::type portable_executable_info_pimpl_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, FusionInfoPimplLabel>::type fusion_info_pimpl_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, StrongNameInfoPimplLabel>::type strong_name_info_pimpl_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, ProfilingInfoLabel>::type profiling_info_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, ProfilingInfoPersistedHandlerLabel>::type profiling_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, MetadataInfoLabel>::type metadata_info_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, MetadataInfoPersistedHandlerLabel>::type metadata_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, PortableExecutableInfoPersistedHandlerLabel>::type portable_executable_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, FusionInfoPersistedHandlerLabel>::type fusion_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, StrongNameInfoPersistedHandlerLabel>::type strong_name_info_persisted_handler_label_type;

            typedef RuntimeHostPimpl runtime_host_pimpl_label_type;
            typedef RuntimeHost runtime_host_label_type;
            typedef HostInfoPimpl host_info_pimpl_label_type;
            typedef HostInfo host_info_label_type;
            typedef HostInfoPersistedHandler host_info_persisted_handler_label_type;

            
            typedef typename RuntimeHostApiAt<ApiHolder, ProfilingInfoLabel>::type profiling_info_label_0178e57d_type;
            typedef typename RuntimeHostApiAt<ApiHolder, MetadataInfoLabel>::type metadata_info_label_0178e57d_type;
            typedef typename RuntimeHostApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_0178e57d_type;
            typedef typename RuntimeHostApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_0178e57d_type;
            typedef typename RuntimeHostApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_0178e57d_type;
            
            typedef typename RuntimeHostApiAt<ApiHolder, ProfilingInfoPersistedHandlerLabel>::type profiling_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, MetadataInfoPersistedHandlerLabel>::type metadata_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, PortableExecutableInfoPersistedHandlerLabel>::type portable_executable_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, FusionInfoPersistedHandlerLabel>::type fusion_info_persisted_handler_label_type;
            typedef typename RuntimeHostApiAt<ApiHolder, StrongNameInfoPersistedHandlerLabel>::type strong_name_info_persisted_handler_label_type;
            
            typedef DisposingInfo<profiling_info_label_0178e57d_type, profiling_info_persisted_handler_label_type> profiling_info_label_disposing_info_type;
            typedef DisposingInfo<metadata_info_label_0178e57d_type, metadata_info_persisted_handler_label_type> metadata_info_label_disposing_info_type;
            typedef DisposingInfo<portable_executable_info_label_0178e57d_type, portable_executable_info_persisted_handler_label_type> portable_executable_info_label_disposing_info_type;
            typedef DisposingInfo<fusion_info_label_0178e57d_type, fusion_info_persisted_handler_label_type> fusion_info_label_disposing_info_type;
            typedef DisposingInfo<strong_name_info_label_0178e57d_type, strong_name_info_persisted_handler_label_type> strong_name_info_label_disposing_info_type;
            
            
            
            
            
            
            
            typedef HostInfo host_info_label_0178e57d_type;
            
            typedef HostInfoPersistedHandler host_info_persisted_handler_label_type;
            
            typedef DisposingInfo<host_info_label_0178e57d_type, host_info_persisted_handler_label_type> host_info_label_disposing_info_type;
            
            typedef DisposableHeapProvider<
                profiling_info_label_disposing_info_type,
                metadata_info_label_disposing_info_type,
                portable_executable_info_label_disposing_info_type,
                fusion_info_label_disposing_info_type,
                strong_name_info_label_disposing_info_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_RUNTIME_HOST_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::host_info_persisted_handler_label_type host_info_persisted_handler_label_type; \
                friend typename host_info_persisted_handler_label_type; \
                typedef typename facade::host_info_label_disposing_info_type host_info_label_disposing_info_type; \
                friend typename host_info_label_disposing_info_type; \
                typedef typename facade::profiling_info_persisted_handler_label_type profiling_info_persisted_handler_label_type; \
                typedef typename facade::metadata_info_persisted_handler_label_type metadata_info_persisted_handler_label_type; \
                typedef typename facade::portable_executable_info_persisted_handler_label_type portable_executable_info_persisted_handler_label_type; \
                typedef typename facade::fusion_info_persisted_handler_label_type fusion_info_persisted_handler_label_type; \
                typedef typename facade::strong_name_info_persisted_handler_label_type strong_name_info_persisted_handler_label_type; \
                friend typename profiling_info_persisted_handler_label_type; \
                friend typename metadata_info_persisted_handler_label_type; \
                friend typename portable_executable_info_persisted_handler_label_type; \
                friend typename fusion_info_persisted_handler_label_type; \
                friend typename strong_name_info_persisted_handler_label_type; \
                typedef typename facade::profiling_info_label_disposing_info_type profiling_info_label_disposing_info_type; \
                typedef typename facade::metadata_info_label_disposing_info_type metadata_info_label_disposing_info_type; \
                typedef typename facade::portable_executable_info_label_disposing_info_type portable_executable_info_label_disposing_info_type; \
                typedef typename facade::fusion_info_label_disposing_info_type fusion_info_label_disposing_info_type; \
                typedef typename facade::strong_name_info_label_disposing_info_type strong_name_info_label_disposing_info_type; \
                friend typename profiling_info_label_disposing_info_type; \
                friend typename metadata_info_label_disposing_info_type; \
                friend typename portable_executable_info_label_disposing_info_type; \
                friend typename fusion_info_label_disposing_info_type; \
                friend typename strong_name_info_label_disposing_info_type; \
            
        };
    
    }   // namespace RuntimeHostFacadeDetail {

    template<
        class ApiHolder
    >    
    struct RuntimeHostFacade : 
        RuntimeHostFacadeDetail::RuntimeHostFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_RUNTIME_HOST_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Hosting::ClassFacade::RuntimeHostFacade<ApiHolder> facade;

#define SWATHE_DECLARE_RUNTIME_HOST_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_RUNTIME_HOST_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    typedef typename facade::profiling_info_pimpl_label_type profiling_info_pimpl_label_type; \
    typedef typename facade::metadata_info_pimpl_label_type metadata_info_pimpl_label_type; \
    typedef typename facade::portable_executable_info_pimpl_label_type portable_executable_info_pimpl_label_type; \
    typedef typename facade::fusion_info_pimpl_label_type fusion_info_pimpl_label_type; \
    typedef typename facade::strong_name_info_pimpl_label_type strong_name_info_pimpl_label_type; \
    typedef typename facade::profiling_info_label_type profiling_info_label_type; \
    typedef typename facade::profiling_info_persisted_handler_label_type profiling_info_persisted_handler_label_type; \
    typedef typename facade::metadata_info_label_type metadata_info_label_type; \
    typedef typename facade::metadata_info_persisted_handler_label_type metadata_info_persisted_handler_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    typedef typename facade::portable_executable_info_persisted_handler_label_type portable_executable_info_persisted_handler_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::fusion_info_persisted_handler_label_type fusion_info_persisted_handler_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    typedef typename facade::strong_name_info_persisted_handler_label_type strong_name_info_persisted_handler_label_type; \
    friend typename profiling_info_pimpl_label_type; \
    friend typename metadata_info_pimpl_label_type; \
    friend typename portable_executable_info_pimpl_label_type; \
    friend typename fusion_info_pimpl_label_type; \
    friend typename strong_name_info_pimpl_label_type; \
    friend typename profiling_info_label_type; \
    friend typename profiling_info_persisted_handler_label_type; \
    friend typename metadata_info_label_type; \
    friend typename metadata_info_persisted_handler_label_type; \
    friend typename portable_executable_info_label_type; \
    friend typename portable_executable_info_persisted_handler_label_type; \
    friend typename fusion_info_label_type; \
    friend typename fusion_info_persisted_handler_label_type; \
    friend typename strong_name_info_label_type; \
    friend typename strong_name_info_persisted_handler_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::host_info_pimpl_label_type host_info_pimpl_label_type; \
    typedef typename facade::host_info_label_type host_info_label_type; \
    typedef typename facade::host_info_persisted_handler_label_type host_info_persisted_handler_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename runtime_host_label_type; \
    friend typename host_info_pimpl_label_type; \
    friend typename host_info_label_type; \
    friend typename host_info_persisted_handler_label_type; \

#define SWATHE_END_RUNTIME_HOST_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_RUNTIMEHOSTFACADE_H

