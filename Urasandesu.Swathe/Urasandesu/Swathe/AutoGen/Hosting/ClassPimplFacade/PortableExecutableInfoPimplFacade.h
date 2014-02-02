/* 
 * File: PortableExecutableInfoPimplFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_PORTABLEEXECUTABLEINFOPIMPLFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_PORTABLEEXECUTABLEINFOPIMPLFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSAPIAT_PORTABLEEXECUTABLEINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassApiAt/PortableExecutableInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEINFOFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassFacade/PortableExecutableInfoFacade.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassPimplFacade { 

    namespace PortableExecutableInfoPimplFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassApiAt::PortableExecutableInfoApiAt;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassFacade::PortableExecutableInfoFacade;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;

        template<
            class ApiHolder
        >    
        struct PortableExecutableInfoPimplFacadeImpl : 
            PortableExecutableInfoFacade<ApiHolder>
        {
            typedef typename PortableExecutableInfoApiAt<ApiHolder, RuntimeHostLabel>::type runtime_host_label_type;
        };
    
    }   // namespace PortableExecutableInfoPimplFacadeDetail {

    template<
        class ApiHolder
    >    
    struct PortableExecutableInfoPimplFacade : 
        PortableExecutableInfoPimplFacadeDetail::PortableExecutableInfoPimplFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PORTABLE_EXECUTABLE_INFO_PIMPL_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Hosting::ClassPimplFacade::PortableExecutableInfoPimplFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_PIMPL_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_FACADE_TYPEDEF_ALIAS \
    typedef typename facade::runtime_host_label_type runtime_host_label_type; \
    friend typename runtime_host_label_type; \

#define SWATHE_END_PORTABLE_EXECUTABLE_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace ClassPimplFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_PORTABLEEXECUTABLEINFOPIMPLFACADE_H

