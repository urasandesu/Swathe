/* 
 * File: StrongNameInfoFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSFACADE_STRONGNAMEINFOFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSFACADE_STRONGNAMEINFOFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSAPIAT_STRONGNAMEINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassApiAt/StrongNameInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOPIMPLFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEKEYPIMPLFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameKeyPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEKEYLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameKeyLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPERSISTEDHANDLERLABEL_RUNTIMEHOSTPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPersistedHandlerLabel/RuntimeHostPersistedHandlerLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace ClassFacade { 

    namespace StrongNameInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassApiAt::StrongNameInfoApiAt;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfoPimpl;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameKeyPimpl;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameKeyLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPersistedHandlerLabel::RuntimeHostPersistedHandlerLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct StrongNameInfoFacadeImpl
        {
            typedef StrongNameInfo class_type;
            typedef StrongNameInfoPimpl class_pimpl_type;
            typedef StrongNameInfoPimpl strong_name_info_pimpl_label_type;
            typedef typename StrongNameInfoApiAt<ApiHolder, RuntimeHostPimplLabel>::type runtime_host_pimpl_label_type;
            typedef typename StrongNameInfoApiAt<ApiHolder, StrongNameKeyLabel>::type strong_name_key_label_type;
            typedef typename StrongNameInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
            typedef typename StrongNameInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;

            typedef StrongNameInfoPimpl strong_name_info_pimpl_label_type;
            typedef StrongNameInfo strong_name_info_label_type;
            typedef StrongNameKeyPimpl strong_name_key_pimpl_label_type;

            
            typedef typename StrongNameInfoApiAt<ApiHolder, StrongNameKeyLabel>::type strong_name_key_label_2029a1f3_type;
            
            typedef StrongNameInfo strong_name_info_label_2029a1f3_type;
            
            typedef typename StrongNameInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_2029a1f3_type;
            
            typedef typename StrongNameInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;
            
            typedef DisposingInfo<runtime_host_label_2029a1f3_type, runtime_host_persisted_handler_label_type> runtime_host_label_disposing_info_type;
            
            typedef SmartHeapProvider<
                strong_name_key_label_2029a1f3_type,
                strong_name_info_label_2029a1f3_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_STRONG_NAME_INFO_SMART_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
                friend typename runtime_host_persisted_handler_label_type; \
                typedef typename facade::runtime_host_label_disposing_info_type runtime_host_label_disposing_info_type; \
                friend typename runtime_host_label_disposing_info_type; \
            
        };
    
    }   // namespace StrongNameInfoFacadeDetail {

    template<
        class ApiHolder
    >    
    struct StrongNameInfoFacade : 
        StrongNameInfoFacadeDetail::StrongNameInfoFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_STRONG_NAME_INFO_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::StrongNaming::ClassFacade::StrongNameInfoFacade<ApiHolder> facade;

#define SWATHE_DECLARE_STRONG_NAME_INFO_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_STRONG_NAME_INFO_SMART_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::strong_name_info_pimpl_label_type strong_name_info_pimpl_label_type; \
    friend typename strong_name_info_pimpl_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::strong_name_key_label_type strong_name_key_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename strong_name_key_label_type; \
    friend typename runtime_host_label_type; \
    friend typename runtime_host_persisted_handler_label_type; \
    typedef typename facade::strong_name_info_pimpl_label_type strong_name_info_pimpl_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    typedef typename facade::strong_name_key_pimpl_label_type strong_name_key_pimpl_label_type; \
    friend typename strong_name_info_pimpl_label_type; \
    friend typename strong_name_info_label_type; \
    friend typename strong_name_key_pimpl_label_type; \

#define SWATHE_END_STRONG_NAME_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSFACADE_STRONGNAMEINFOFACADE_H

