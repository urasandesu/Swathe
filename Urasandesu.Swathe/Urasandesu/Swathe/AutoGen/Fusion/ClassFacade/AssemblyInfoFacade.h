/* 
 * File: AssemblyInfoFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYINFOFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYINFOFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSAPIAT_ASSEMBLYINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassApiAt/AssemblyInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYINFOFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_FUSIONINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/FusionInfoPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

    namespace AssemblyInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassApiAt::AssemblyInfoApiAt;
        using Urasandesu::Swathe::Fusion::AssemblyInfoPimpl;
        using Urasandesu::Swathe::Fusion::AssemblyInfo;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::FusionInfoPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct AssemblyInfoFacadeImpl
        {
            typedef AssemblyInfoPimpl assembly_info_pimpl_label_type;
            typedef typename AssemblyInfoApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename AssemblyInfoApiAt<ApiHolder, FusionInfoPimplLabel>::type fusion_info_pimpl_label_type;

            typedef AssemblyInfoPimpl assembly_info_pimpl_label_type;
            typedef AssemblyInfo assembly_info_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_ASSEMBLY_INFO_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
            
            typedef typename AssemblyInfoApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_previous_type;
            typedef AssemblyInfo this_type;
            
            typedef vector<
                SmartPtrChainInfo<fusion_info_label_previous_type, SmartPtrChainMapper, SmartPtrChainConstructor>
            > chain_info_types;
            typedef SmartPtrChain<this_type, chain_info_types> base_ptr_chain_type;
            
            typedef typename base_ptr_chain_type::template chain_from<fusion_info_label_previous_type>::type fusion_info_label_chain_type;
            
            #define SWATHE_DECLARE_ASSEMBLY_INFO_SMART_PTR_CHAIN_TYPEDEF_ALIAS \
                typedef typename facade::this_type this_type; \
                typedef typename facade::base_ptr_chain_type base_ptr_chain_type; \
                friend typename base_ptr_chain_type; \
                typedef typename facade::fusion_info_label_previous_type fusion_info_label_previous_type; \
                friend typename fusion_info_label_previous_type; \
                typedef typename facade::fusion_info_label_chain_type fusion_info_label_chain_type; \
                friend typename fusion_info_label_chain_type; \
            
        };
    
    }   // namespace AssemblyInfoFacadeDetail {

    template<
        class ApiHolder
    >    
    struct AssemblyInfoFacade : 
        AssemblyInfoFacadeDetail::AssemblyInfoFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_ASSEMBLY_INFO_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::AssemblyInfoFacade<ApiHolder> facade;

#define SWATHE_DECLARE_ASSEMBLY_INFO_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_INFO_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_INFO_SMART_PTR_CHAIN_TYPEDEF_ALIAS \
    typedef typename facade::assembly_info_pimpl_label_type assembly_info_pimpl_label_type; \
    friend typename assembly_info_pimpl_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::fusion_info_pimpl_label_type fusion_info_pimpl_label_type; \
    friend typename fusion_info_label_type; \
    friend typename fusion_info_pimpl_label_type; \
    typedef typename facade::assembly_info_pimpl_label_type assembly_info_pimpl_label_type; \
    typedef typename facade::assembly_info_label_type assembly_info_label_type; \
    friend typename assembly_info_pimpl_label_type; \
    friend typename assembly_info_label_type; \

#define SWATHE_END_ASSEMBLY_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYINFOFACADE_H

