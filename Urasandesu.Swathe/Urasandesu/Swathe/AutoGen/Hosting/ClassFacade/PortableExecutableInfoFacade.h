/* 
 * File: PortableExecutableInfoFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEINFOFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEINFOFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSAPIAT_PORTABLEEXECUTABLEINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassApiAt/PortableExecutableInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFOFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_PORTABLEEXECUTABLEREADERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/PortableExecutableReaderPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_PORTABLEEXECUTABLEWRITERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/PortableExecutableWriterPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEREADERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableReaderLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEWRITERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableWriterLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPERSISTEDHANDLERLABEL_RUNTIMEHOSTPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPersistedHandlerLabel/RuntimeHostPersistedHandlerLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

    namespace PortableExecutableInfoFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassApiAt::PortableExecutableInfoApiAt;
        using Urasandesu::Swathe::Hosting::PortableExecutableInfoPimpl;
        using Urasandesu::Swathe::Hosting::PortableExecutableInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::PortableExecutableReaderPimplLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::PortableExecutableWriterPimplLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableReaderLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableWriterLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPersistedHandlerLabel::RuntimeHostPersistedHandlerLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct PortableExecutableInfoFacadeImpl
        {
            typedef PortableExecutableInfo class_type;
            typedef PortableExecutableInfoPimpl class_pimpl_type;
            typedef PortableExecutableInfoPimpl portable_executable_info_pimpl_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, PortableExecutableReaderPimplLabel>::type portable_executable_reader_pimpl_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, PortableExecutableWriterPimplLabel>::type portable_executable_writer_pimpl_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, RuntimeHostPimplLabel>::type runtime_host_pimpl_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, PortableExecutableReaderLabel>::type portable_executable_reader_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, PortableExecutableWriterLabel>::type portable_executable_writer_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;

            typedef PortableExecutableInfoPimpl portable_executable_info_pimpl_label_type;
            typedef PortableExecutableInfo portable_executable_info_label_type;

            
            typedef typename PortableExecutableInfoApiAt<ApiHolder, PortableExecutableReaderLabel>::type portable_executable_reader_label_f763e58e_type;
            typedef typename PortableExecutableInfoApiAt<ApiHolder, PortableExecutableWriterLabel>::type portable_executable_writer_label_f763e58e_type;
            
            typedef PortableExecutableInfo portable_executable_info_label_f763e58e_type;
            
            typedef typename PortableExecutableInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_f763e58e_type;
            
            typedef typename PortableExecutableInfoApiAt<ApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_label_type;
            
            typedef DisposingInfo<runtime_host_label_f763e58e_type, runtime_host_persisted_handler_label_type> runtime_host_label_disposing_info_type;
            
            typedef SmartHeapProvider<
                portable_executable_reader_label_f763e58e_type,
                portable_executable_writer_label_f763e58e_type,
                portable_executable_info_label_f763e58e_type
            > base_heap_provider_type;
            
            #define SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_SMART_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
                typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
                friend typename runtime_host_persisted_handler_label_type; \
                typedef typename facade::runtime_host_label_disposing_info_type runtime_host_label_disposing_info_type; \
                friend typename runtime_host_label_disposing_info_type; \
            
        };
    
    }   // namespace PortableExecutableInfoFacadeDetail {

    template<
        class ApiHolder
    >    
    struct PortableExecutableInfoFacade : 
        PortableExecutableInfoFacadeDetail::PortableExecutableInfoFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PORTABLE_EXECUTABLE_INFO_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Hosting::ClassFacade::PortableExecutableInfoFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_SMART_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::portable_executable_info_pimpl_label_type portable_executable_info_pimpl_label_type; \
    friend typename portable_executable_info_pimpl_label_type; \
    typedef typename facade::portable_executable_reader_pimpl_label_type portable_executable_reader_pimpl_label_type; \
    typedef typename facade::portable_executable_writer_pimpl_label_type portable_executable_writer_pimpl_label_type; \
    typedef typename facade::runtime_host_pimpl_label_type runtime_host_pimpl_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    typedef typename facade::portable_executable_reader_label_type portable_executable_reader_label_type; \
    typedef typename facade::portable_executable_writer_label_type portable_executable_writer_label_type; \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    typedef typename facade::runtime_host_persisted_handler_label_type runtime_host_persisted_handler_label_type; \
    friend typename portable_executable_reader_pimpl_label_type; \
    friend typename portable_executable_writer_pimpl_label_type; \
    friend typename runtime_host_pimpl_label_type; \
    friend typename strong_name_info_label_type; \
    friend typename portable_executable_reader_label_type; \
    friend typename portable_executable_writer_label_type; \
    friend typename runtime_host_label_type; \
    friend typename runtime_host_persisted_handler_label_type; \
    typedef typename facade::portable_executable_info_pimpl_label_type portable_executable_info_pimpl_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    friend typename portable_executable_info_pimpl_label_type; \
    friend typename portable_executable_info_label_type; \

#define SWATHE_END_PORTABLE_EXECUTABLE_INFO_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEINFOFACADE_H

