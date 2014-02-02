/* 
 * File: FusionInfoFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_FUSIONINFOFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_FUSIONINFOFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSAPIAT_FUSIONINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassApiAt/FusionInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/FusionInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFOFWD_H
#include <Urasandesu/Swathe/Fusion/FusionInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYCACHEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyCachePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYNAMEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyNamePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYNAMERANGEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyNameRangePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYCACHELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyCacheLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYINFOFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMERANGELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameRangeLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPERSISTEDHANDLERLABEL_RUNTIMEHOSTPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPersistedHandlerLabel/RuntimeHostPersistedHandlerLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

    namespace FusionInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassApiAt::FusionInfoApiAt;
        using Urasandesu::Swathe::Fusion::FusionInfoPimpl;
        using Urasandesu::Swathe::Fusion::FusionInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyCachePimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyNamePimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyNameRangePimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyCacheLabel;
        using Urasandesu::Swathe::Fusion::AssemblyInfo;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameRangeLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPersistedHandlerLabel::RuntimeHostPersistedHandlerLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct FusionInfoFacadeImpl
        {
            typedef FusionInfo class_type;
            typedef FusionInfoPimpl class_pimpl_type;
            typedef FusionInfoPimpl fusion_info_pimpl_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, RuntimeHostPimplLabel>::type runtime_host_pimpl_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyCachePimplLabel>::type assembly_cache_pimpl_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyNamePimplLabel>::type assembly_name_pimpl_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyNameRangePimplLabel>::type assembly_name_range_pimpl_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyCacheLabel>::type assembly_cache_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyNameLabel>::type assembly_name_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyNameRangeLabel>::type assembly_name_range_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
            typedef typename FusionInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;

            typedef FusionInfoPimpl fusion_info_pimpl_label_type;
            typedef FusionInfo fusion_info_label_type;
            typedef AssemblyInfo assembly_info_label_type;

            
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyCacheLabel>::type assembly_cache_label_0efe50f7_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyNameLabel>::type assembly_name_label_0efe50f7_type;
            typedef typename FusionInfoApiAt<ApiHolder, AssemblyNameRangeLabel>::type assembly_name_range_label_0efe50f7_type;
            
            typedef FusionInfo fusion_info_label_0efe50f7_type;
            typedef AssemblyInfo assembly_info_label_0efe50f7_type;
            
            typedef typename FusionInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_0efe50f7_type;
            
            typedef typename FusionInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;
            
            typedef DisposingInfo<runtime_host_label_0efe50f7_type, runtime_host_persisted_handler_label_type> runtime_host_label_disposing_info_type;
            
            typedef SmartHeapProvider<
                assembly_cache_label_0efe50f7_type,
                assembly_name_label_0efe50f7_type,
                assembly_name_range_label_0efe50f7_type,
                fusion_info_label_0efe50f7_type,
                assembly_info_label_0efe50f7_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_FUSION_INFO_SMART_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
                friend typename runtime_host_persisted_handler_label_type; \
                typedef typename facade::runtime_host_label_disposing_info_type runtime_host_label_disposing_info_type; \
                friend typename runtime_host_label_disposing_info_type; \
            
        };
    
    }   // namespace FusionInfoFacadeDetail {

    template<
        class ApiHolder
    >    
    struct FusionInfoFacade : 
        FusionInfoFacadeDetail::FusionInfoFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_FUSION_INFO_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::FusionInfoFacade<ApiHolder> facade;

#define SWATHE_DECLARE_FUSION_INFO_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_FUSION_INFO_SMART_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::fusion_info_pimpl_label_type fusion_info_pimpl_label_type; \
    friend typename fusion_info_pimpl_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::assembly_cache_pimpl_label_type assembly_cache_pimpl_label_type; \
    typedef typename facade::assembly_name_pimpl_label_type assembly_name_pimpl_label_type; \
    typedef typename facade::assembly_name_range_pimpl_label_type assembly_name_range_pimpl_label_type; \
    typedef typename facade::assembly_cache_label_type assembly_cache_label_type; \
    typedef typename facade::assembly_name_label_type assembly_name_label_type; \
    typedef typename facade::assembly_name_range_label_type assembly_name_range_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename assembly_cache_pimpl_label_type; \
    friend typename assembly_name_pimpl_label_type; \
    friend typename assembly_name_range_pimpl_label_type; \
    friend typename assembly_cache_label_type; \
    friend typename assembly_name_label_type; \
    friend typename assembly_name_range_label_type; \
    friend typename runtime_host_label_type; \
    friend typename runtime_host_persisted_handler_label_type; \
    typedef typename facade::fusion_info_pimpl_label_type fusion_info_pimpl_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::assembly_info_label_type assembly_info_label_type; \
    friend typename fusion_info_pimpl_label_type; \
    friend typename fusion_info_label_type; \
    friend typename assembly_info_label_type; \

#define SWATHE_END_FUSION_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_FUSIONINFOFACADE_H

