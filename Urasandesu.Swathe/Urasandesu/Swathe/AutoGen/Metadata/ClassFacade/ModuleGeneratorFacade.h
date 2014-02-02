/* 
 * File: ModuleGeneratorFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEGENERATORFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEGENERATORFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_MODULEGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/ModuleGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYGENERATORPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyGeneratorPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace ModuleGeneratorFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::ModuleGeneratorApiAt;
        using Urasandesu::Swathe::Metadata::ModuleGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::ModuleGenerator;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyGeneratorPimplLabel;
        using Urasandesu::Swathe::Metadata::TypeGenerator;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPimpl;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ModuleGeneratorFacadeImpl
        {
            typedef ModuleGenerator class_type;
            typedef ModuleGeneratorPimpl class_pimpl_type;
            typedef ModuleGeneratorPimpl module_generator_pimpl_label_type;
            typedef typename ModuleGeneratorApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;
            typedef typename ModuleGeneratorApiAt<ApiHolder, AssemblyGeneratorPimplLabel>::type assembly_generator_pimpl_label_type;

            typedef ModuleGeneratorPimpl module_generator_pimpl_label_type;
            typedef ModuleGenerator module_generator_label_type;
            typedef TypeGenerator type_generator_label_type;
            typedef TypeGeneratorPimpl type_generator_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_MODULE_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace ModuleGeneratorFacadeDetail {

    template<
        class ApiHolder
    >    
    struct ModuleGeneratorFacade : 
        ModuleGeneratorFacadeDetail::ModuleGeneratorFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_MODULE_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::ModuleGeneratorFacade<ApiHolder> facade;

#define SWATHE_DECLARE_MODULE_GENERATOR_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_MODULE_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::module_generator_pimpl_label_type module_generator_pimpl_label_type; \
    friend typename module_generator_pimpl_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    typedef typename facade::module_generator_pimpl_label_type module_generator_pimpl_label_type; \
    typedef typename facade::module_generator_label_type module_generator_label_type; \
    typedef typename facade::type_generator_label_type type_generator_label_type; \
    typedef typename facade::type_generator_pimpl_label_type type_generator_pimpl_label_type; \
    friend typename module_generator_pimpl_label_type; \
    friend typename module_generator_label_type; \
    friend typename type_generator_label_type; \
    friend typename type_generator_pimpl_label_type; \

#define SWATHE_END_MODULE_GENERATOR_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEGENERATORFACADE_H

