/* 
 * File: HostInfoFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_HOSTINFOFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_HOSTINFOFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSAPIAT_HOSTINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassApiAt/HostInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/HostInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFOFWD_H
#include <Urasandesu/Swathe/Hosting/HostInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Hosting/HostInfoPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPERSISTEDHANDLERLABEL_RUNTIMEHOSTPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPersistedHandlerLabel/RuntimeHostPersistedHandlerLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

    namespace HostInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassApiAt::HostInfoApiAt;
        using Urasandesu::Swathe::Hosting::HostInfoPimpl;
        using Urasandesu::Swathe::Hosting::HostInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::Hosting::HostInfoPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPersistedHandlerLabel::RuntimeHostPersistedHandlerLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct HostInfoFacadeImpl
        {
            typedef HostInfo class_type;
            typedef HostInfoPimpl class_pimpl_type;
            typedef HostInfoPimpl host_info_pimpl_label_type;
            typedef typename HostInfoApiAt<ApiHolder, RuntimeHostPimplLabel>::type runtime_host_pimpl_label_type;
            typedef typename HostInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
            typedef typename HostInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;

            typedef HostInfoPimpl host_info_pimpl_label_type;
            typedef HostInfo host_info_label_type;
            typedef HostInfoPersistedHandler host_info_persisted_handler_label_type;

            
            typedef typename HostInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_6baab14b_type;
            
            typedef typename HostInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;
            
            typedef DisposingInfo<runtime_host_label_6baab14b_type, runtime_host_persisted_handler_label_type> runtime_host_label_disposing_info_type;
            
            typedef HostInfo host_info_label_6baab14b_type;
            
            typedef HostInfoPersistedHandler host_info_persisted_handler_label_type;
            
            typedef DisposingInfo<host_info_label_6baab14b_type, host_info_persisted_handler_label_type> host_info_label_disposing_info_type;
            
            typedef DisposableHeapProvider<
                host_info_label_disposing_info_type,
                runtime_host_label_disposing_info_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_HOST_INFO_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
                friend typename runtime_host_persisted_handler_label_type; \
                typedef typename facade::runtime_host_label_disposing_info_type runtime_host_label_disposing_info_type; \
                friend typename runtime_host_label_disposing_info_type; \
                typedef typename facade::host_info_persisted_handler_label_type host_info_persisted_handler_label_type; \
                friend typename host_info_persisted_handler_label_type; \
                typedef typename facade::host_info_label_disposing_info_type host_info_label_disposing_info_type; \
                friend typename host_info_label_disposing_info_type; \
            
        };
    
    }   // namespace HostInfoFacadeDetail {

    template<
        class ApiHolder
    >    
    struct HostInfoFacade : 
        HostInfoFacadeDetail::HostInfoFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_HOST_INFO_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Hosting::ClassFacade::HostInfoFacade<ApiHolder> facade;

#define SWATHE_DECLARE_HOST_INFO_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_HOST_INFO_DISPOSABLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::host_info_pimpl_label_type host_info_pimpl_label_type; \
    friend typename host_info_pimpl_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename runtime_host_label_type; \
    friend typename runtime_host_persisted_handler_label_type; \
    typedef typename facade::host_info_pimpl_label_type host_info_pimpl_label_type; \
    typedef typename facade::host_info_label_type host_info_label_type; \
    typedef typename facade::host_info_persisted_handler_label_type host_info_persisted_handler_label_type; \
    friend typename host_info_pimpl_label_type; \
    friend typename host_info_label_type; \
    friend typename host_info_persisted_handler_label_type; \

#define SWATHE_END_HOST_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_HOSTINFOFACADE_H

