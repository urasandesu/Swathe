/* 
 * File: AssemblyNameFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSAPIAT_ASSEMBLYNAMEAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassApiAt/AssemblyNameApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNamePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYNAMERANGEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyNameRangePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_FUSIONINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/FusionInfoPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

    namespace AssemblyNameFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassApiAt::AssemblyNameApiAt;
        using Urasandesu::Swathe::Fusion::AssemblyNamePimpl;
        using Urasandesu::Swathe::Fusion::AssemblyName;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyNameRangePimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::FusionInfoPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct AssemblyNameFacadeImpl
        {
            typedef AssemblyName class_type;
            typedef AssemblyNamePimpl class_pimpl_type;
            typedef AssemblyNamePimpl assembly_name_pimpl_label_type;
            typedef typename AssemblyNameApiAt<ApiHolder, AssemblyNameRangePimplLabel>::type assembly_name_range_pimpl_label_type;
            typedef typename AssemblyNameApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename AssemblyNameApiAt<ApiHolder, FusionInfoPimplLabel>::type fusion_info_pimpl_label_type;

            typedef AssemblyNamePimpl assembly_name_pimpl_label_type;
            typedef AssemblyName assembly_name_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_ASSEMBLY_NAME_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace AssemblyNameFacadeDetail {

    template<
        class ApiHolder
    >    
    struct AssemblyNameFacade : 
        AssemblyNameFacadeDetail::AssemblyNameFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_ASSEMBLY_NAME_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::AssemblyNameFacade<ApiHolder> facade;

#define SWATHE_DECLARE_ASSEMBLY_NAME_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_NAME_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::assembly_name_pimpl_label_type assembly_name_pimpl_label_type; \
    friend typename assembly_name_pimpl_label_type; \
    typedef typename facade::assembly_name_range_pimpl_label_type assembly_name_range_pimpl_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::fusion_info_pimpl_label_type fusion_info_pimpl_label_type; \
    friend typename assembly_name_range_pimpl_label_type; \
    friend typename fusion_info_label_type; \
    friend typename fusion_info_pimpl_label_type; \
    typedef typename facade::assembly_name_pimpl_label_type assembly_name_pimpl_label_type; \
    typedef typename facade::assembly_name_label_type assembly_name_label_type; \
    friend typename assembly_name_pimpl_label_type; \
    friend typename assembly_name_label_type; \

#define SWATHE_END_ASSEMBLY_NAME_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEFACADE_H

