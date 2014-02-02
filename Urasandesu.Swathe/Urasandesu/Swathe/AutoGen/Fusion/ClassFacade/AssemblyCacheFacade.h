/* 
 * File: AssemblyCacheFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYCACHEFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYCACHEFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSAPIAT_ASSEMBLYCACHEAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassApiAt/AssemblyCacheApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyCachePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_FUSIONINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/FusionInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYINFOFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyInfoFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

    namespace AssemblyCacheFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassApiAt::AssemblyCacheApiAt;
        using Urasandesu::Swathe::Fusion::AssemblyCachePimpl;
        using Urasandesu::Swathe::Fusion::AssemblyCache;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::FusionInfoPimplLabel;
        using Urasandesu::Swathe::Fusion::AssemblyInfo;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct AssemblyCacheFacadeImpl
        {
            typedef AssemblyCache class_type;
            typedef AssemblyCachePimpl class_pimpl_type;
            typedef AssemblyCachePimpl assembly_cache_pimpl_label_type;
            typedef typename AssemblyCacheApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename AssemblyCacheApiAt<ApiHolder, FusionInfoPimplLabel>::type fusion_info_pimpl_label_type;

            typedef AssemblyCachePimpl assembly_cache_pimpl_label_type;
            typedef AssemblyCache assembly_cache_label_type;
            typedef AssemblyInfo assembly_info_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_ASSEMBLY_CACHE_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace AssemblyCacheFacadeDetail {

    template<
        class ApiHolder
    >    
    struct AssemblyCacheFacade : 
        AssemblyCacheFacadeDetail::AssemblyCacheFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_ASSEMBLY_CACHE_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::AssemblyCacheFacade<ApiHolder> facade;

#define SWATHE_DECLARE_ASSEMBLY_CACHE_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_CACHE_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::assembly_cache_pimpl_label_type assembly_cache_pimpl_label_type; \
    friend typename assembly_cache_pimpl_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::fusion_info_pimpl_label_type fusion_info_pimpl_label_type; \
    friend typename fusion_info_label_type; \
    friend typename fusion_info_pimpl_label_type; \
    typedef typename facade::assembly_cache_pimpl_label_type assembly_cache_pimpl_label_type; \
    typedef typename facade::assembly_cache_label_type assembly_cache_label_type; \
    typedef typename facade::assembly_info_label_type assembly_info_label_type; \
    friend typename assembly_cache_pimpl_label_type; \
    friend typename assembly_cache_label_type; \
    friend typename assembly_info_label_type; \

#define SWATHE_END_ASSEMBLY_CACHE_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYCACHEFACADE_H

