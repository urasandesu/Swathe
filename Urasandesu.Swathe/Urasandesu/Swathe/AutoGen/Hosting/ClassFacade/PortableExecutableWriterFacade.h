/* 
 * File: PortableExecutableWriterFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEWRITERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEWRITERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSAPIAT_PORTABLEEXECUTABLEWRITERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassApiAt/PortableExecutableWriterApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEWRITERPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableWriterPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEWRITERFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableWriterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_PORTABLEEXECUTABLEINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/PortableExecutableInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

    namespace PortableExecutableWriterFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassApiAt::PortableExecutableWriterApiAt;
        using Urasandesu::Swathe::Hosting::PortableExecutableWriterPimpl;
        using Urasandesu::Swathe::Hosting::PortableExecutableWriter;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::PortableExecutableInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct PortableExecutableWriterFacadeImpl
        {
            typedef PortableExecutableWriter class_type;
            typedef PortableExecutableWriterPimpl class_pimpl_type;
            typedef PortableExecutableWriterPimpl portable_executable_writer_pimpl_label_type;
            typedef typename PortableExecutableWriterApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_type;
            typedef typename PortableExecutableWriterApiAt<ApiHolder, PortableExecutableInfoPimplLabel>::type portable_executable_info_pimpl_label_type;
            typedef typename PortableExecutableWriterApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;

            typedef PortableExecutableWriterPimpl portable_executable_writer_pimpl_label_type;
            typedef PortableExecutableWriter portable_executable_writer_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_PORTABLE_EXECUTABLE_WRITER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace PortableExecutableWriterFacadeDetail {

    template<
        class ApiHolder
    >    
    struct PortableExecutableWriterFacade : 
        PortableExecutableWriterFacadeDetail::PortableExecutableWriterFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PORTABLE_EXECUTABLE_WRITER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Hosting::ClassFacade::PortableExecutableWriterFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PORTABLE_EXECUTABLE_WRITER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PORTABLE_EXECUTABLE_WRITER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::portable_executable_writer_pimpl_label_type portable_executable_writer_pimpl_label_type; \
    friend typename portable_executable_writer_pimpl_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    typedef typename facade::portable_executable_info_pimpl_label_type portable_executable_info_pimpl_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    friend typename portable_executable_info_label_type; \
    friend typename portable_executable_info_pimpl_label_type; \
    friend typename strong_name_info_label_type; \
    typedef typename facade::portable_executable_writer_pimpl_label_type portable_executable_writer_pimpl_label_type; \
    typedef typename facade::portable_executable_writer_label_type portable_executable_writer_label_type; \
    friend typename portable_executable_writer_pimpl_label_type; \
    friend typename portable_executable_writer_label_type; \

#define SWATHE_END_PORTABLE_EXECUTABLE_WRITER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEWRITERFACADE_H

