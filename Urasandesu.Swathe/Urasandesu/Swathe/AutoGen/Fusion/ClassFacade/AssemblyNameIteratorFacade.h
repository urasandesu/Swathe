/* 
 * File: AssemblyNameIteratorFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEITERATORFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEITERATORFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSAPIAT_ASSEMBLYNAMEITERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassApiAt/AssemblyNameIteratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEITERATORFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameIteratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_FUSIONINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/FusionInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYNAMEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyNamePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMERANGELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameRangeLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYNAMERANGEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyNameRangePimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

    namespace AssemblyNameIteratorFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassApiAt::AssemblyNameIteratorApiAt;
        using Urasandesu::Swathe::Fusion::AssemblyNameIterator;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::FusionInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyNamePimplLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameRangeLabel;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyNameRangePimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct AssemblyNameIteratorFacadeImpl
        {
            typedef AssemblyNameIterator class_type;
            typedef Nil class_pimpl_type;
            typedef Nil nil_label_type;
            typedef typename AssemblyNameIteratorApiAt<ApiHolder, FusionInfoLabel>::type fusion_info_label_type;
            typedef typename AssemblyNameIteratorApiAt<ApiHolder, FusionInfoPimplLabel>::type fusion_info_pimpl_label_type;
            typedef typename AssemblyNameIteratorApiAt<ApiHolder, AssemblyNameLabel>::type assembly_name_label_type;
            typedef typename AssemblyNameIteratorApiAt<ApiHolder, AssemblyNamePimplLabel>::type assembly_name_pimpl_label_type;
            typedef typename AssemblyNameIteratorApiAt<ApiHolder, AssemblyNameRangeLabel>::type assembly_name_range_label_type;
            typedef typename AssemblyNameIteratorApiAt<ApiHolder, AssemblyNameRangePimplLabel>::type assembly_name_range_pimpl_label_type;

            typedef AssemblyNameIterator assembly_name_iterator_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_ASSEMBLY_NAME_ITERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace AssemblyNameIteratorFacadeDetail {

    template<
        class ApiHolder
    >    
    struct AssemblyNameIteratorFacade : 
        AssemblyNameIteratorFacadeDetail::AssemblyNameIteratorFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_ASSEMBLY_NAME_ITERATOR_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::AssemblyNameIteratorFacade<ApiHolder> facade;

#define SWATHE_DECLARE_ASSEMBLY_NAME_ITERATOR_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_NAME_ITERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::nil_label_type nil_label_type; \
    friend typename nil_label_type; \
    typedef typename facade::fusion_info_label_type fusion_info_label_type; \
    typedef typename facade::fusion_info_pimpl_label_type fusion_info_pimpl_label_type; \
    typedef typename facade::assembly_name_label_type assembly_name_label_type; \
    typedef typename facade::assembly_name_pimpl_label_type assembly_name_pimpl_label_type; \
    typedef typename facade::assembly_name_range_label_type assembly_name_range_label_type; \
    typedef typename facade::assembly_name_range_pimpl_label_type assembly_name_range_pimpl_label_type; \
    friend typename fusion_info_label_type; \
    friend typename fusion_info_pimpl_label_type; \
    friend typename assembly_name_label_type; \
    friend typename assembly_name_pimpl_label_type; \
    friend typename assembly_name_range_label_type; \
    friend typename assembly_name_range_pimpl_label_type; \
    typedef typename facade::assembly_name_iterator_label_type assembly_name_iterator_label_type; \
    friend typename assembly_name_iterator_label_type; \

#define SWATHE_END_ASSEMBLY_NAME_ITERATOR_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEITERATORFACADE_H

