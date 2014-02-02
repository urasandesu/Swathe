/* 
 * File: PortableExecutableReaderFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEREADERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEREADERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSAPIAT_PORTABLEEXECUTABLEREADERAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassApiAt/PortableExecutableReaderApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEREADERPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableReaderPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEREADERFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableReaderFwd.h>
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

    namespace PortableExecutableReaderFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassApiAt::PortableExecutableReaderApiAt;
        using Urasandesu::Swathe::Hosting::PortableExecutableReaderPimpl;
        using Urasandesu::Swathe::Hosting::PortableExecutableReader;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::PortableExecutableInfoPimplLabel;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct PortableExecutableReaderFacadeImpl
        {
            typedef PortableExecutableReader class_type;
            typedef PortableExecutableReaderPimpl class_pimpl_type;
            typedef PortableExecutableReaderPimpl portable_executable_reader_pimpl_label_type;
            typedef typename PortableExecutableReaderApiAt<ApiHolder, PortableExecutableInfoLabel>::type portable_executable_info_label_type;
            typedef typename PortableExecutableReaderApiAt<ApiHolder, PortableExecutableInfoPimplLabel>::type portable_executable_info_pimpl_label_type;
            typedef typename PortableExecutableReaderApiAt<ApiHolder, StrongNameInfoLabel>::type strong_name_info_label_type;

            typedef PortableExecutableReaderPimpl portable_executable_reader_pimpl_label_type;
            typedef PortableExecutableReader portable_executable_reader_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_PORTABLE_EXECUTABLE_READER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace PortableExecutableReaderFacadeDetail {

    template<
        class ApiHolder
    >    
    struct PortableExecutableReaderFacade : 
        PortableExecutableReaderFacadeDetail::PortableExecutableReaderFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PORTABLE_EXECUTABLE_READER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Hosting::ClassFacade::PortableExecutableReaderFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PORTABLE_EXECUTABLE_READER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PORTABLE_EXECUTABLE_READER_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::portable_executable_reader_pimpl_label_type portable_executable_reader_pimpl_label_type; \
    friend typename portable_executable_reader_pimpl_label_type; \
    typedef typename facade::portable_executable_info_label_type portable_executable_info_label_type; \
    typedef typename facade::portable_executable_info_pimpl_label_type portable_executable_info_pimpl_label_type; \
    typedef typename facade::strong_name_info_label_type strong_name_info_label_type; \
    friend typename portable_executable_info_label_type; \
    friend typename portable_executable_info_pimpl_label_type; \
    friend typename strong_name_info_label_type; \
    typedef typename facade::portable_executable_reader_pimpl_label_type portable_executable_reader_pimpl_label_type; \
    typedef typename facade::portable_executable_reader_label_type portable_executable_reader_label_type; \
    friend typename portable_executable_reader_pimpl_label_type; \
    friend typename portable_executable_reader_label_type; \

#define SWATHE_END_PORTABLE_EXECUTABLE_READER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEREADERFACADE_H

