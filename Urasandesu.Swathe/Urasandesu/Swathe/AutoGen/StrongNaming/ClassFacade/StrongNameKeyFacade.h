/* 
 * File: StrongNameKeyFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSFACADE_STRONGNAMEKEYFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSFACADE_STRONGNAMEKEYFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSAPIAT_STRONGNAMEKEYAPIAT_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassApiAt/StrongNameKeyApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEKEYPIMPLFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameKeyPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEKEYFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameKeyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPIMPLLABEL_STRONGNAMEINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPimplLabel/StrongNameInfoPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace ClassFacade { 

    namespace StrongNameKeyFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassApiAt::StrongNameKeyApiAt;
        using Urasandesu::Swathe::StrongNaming::StrongNameKeyPimpl;
        using Urasandesu::Swathe::StrongNaming::StrongNameKey;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassPimplLabel::StrongNameInfoPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct StrongNameKeyFacadeImpl
        {
            typedef StrongNameKeyPimpl strong_name_key_pimpl_label_type;
            typedef typename StrongNameKeyApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;
            typedef typename StrongNameKeyApiAt<ApiHolder, StrongNameInfoPimplLabel>::type strong_name_info_pimpl_label_type;

            typedef StrongNameKeyPimpl strong_name_key_pimpl_label_type;
            typedef StrongNameKey strong_name_key_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_STRONG_NAME_KEY_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
            
            typedef typename StrongNameKeyApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_previous_type;
            typedef StrongNameKey this_type;
            
            typedef vector<
                SmartPtrChainInfo<strong_name_info_label_previous_type, SmartPtrChainMapper, SmartPtrChainConstructor>
            > chain_info_types;
            typedef SmartPtrChain<this_type, chain_info_types> base_ptr_chain_type;
            
            typedef typename base_ptr_chain_type::template chain_from<strong_name_info_label_previous_type>::type strong_name_info_label_chain_type;
            
            #define SWATHE_DECLARE_STRONG_NAME_KEY_SMART_PTR_CHAIN_TYPEDEF_ALIAS \
                typedef typename facade::this_type this_type; \
                typedef typename facade::base_ptr_chain_type base_ptr_chain_type; \
                friend typename base_ptr_chain_type; \
                typedef typename facade::strong_name_info_label_previous_type strong_name_info_label_previous_type; \
                friend typename strong_name_info_label_previous_type; \
                typedef typename facade::strong_name_info_label_chain_type strong_name_info_label_chain_type; \
                friend typename strong_name_info_label_chain_type; \
            
        };
    
    }   // namespace StrongNameKeyFacadeDetail {

    template<
        class ApiHolder
    >    
    struct StrongNameKeyFacade : 
        StrongNameKeyFacadeDetail::StrongNameKeyFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_STRONG_NAME_KEY_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::StrongNaming::ClassFacade::StrongNameKeyFacade<ApiHolder> facade;

#define SWATHE_DECLARE_STRONG_NAME_KEY_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_STRONG_NAME_KEY_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    SWATHE_DECLARE_STRONG_NAME_KEY_SMART_PTR_CHAIN_TYPEDEF_ALIAS \
    typedef typename facade::strong_name_key_pimpl_label_type strong_name_key_pimpl_label_type; \
    friend typename strong_name_key_pimpl_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    typedef typename facade::strong_name_info_pimpl_label_type strong_name_info_pimpl_label_type; \
    friend typename strong_name_info_label_type; \
    friend typename strong_name_info_pimpl_label_type; \
    typedef typename facade::strong_name_key_pimpl_label_type strong_name_key_pimpl_label_type; \
    typedef typename facade::strong_name_key_label_type strong_name_key_label_type; \
    friend typename strong_name_key_pimpl_label_type; \
    friend typename strong_name_key_label_type; \

#define SWATHE_END_STRONG_NAME_KEY_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSFACADE_STRONGNAMEKEYFACADE_H

