/* 
 * File: TypeGeneratorFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_TYPEGENERATORFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_TYPEGENERATORFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_TYPEGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/TypeGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/FieldGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYGENERATORPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyGeneratorPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleGeneratorPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace TypeGeneratorFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::TypeGeneratorApiAt;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::TypeGenerator;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodGenerator;
        using Urasandesu::Swathe::Metadata::MethodGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::MethodBodyGenerator;
        using Urasandesu::Swathe::Metadata::FieldGenerator;
        using Urasandesu::Swathe::Metadata::FieldGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::PropertyGenerator;
        using Urasandesu::Swathe::Metadata::PropertyGeneratorPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyGeneratorPimplLabel;
        using Urasandesu::Swathe::Metadata::ModuleGenerator;
        using Urasandesu::Swathe::Metadata::ModuleGeneratorPimpl;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct TypeGeneratorFacadeImpl
        {
            typedef TypeGenerator class_type;
            typedef TypeGeneratorPimpl class_pimpl_type;
            typedef TypeGeneratorPimpl type_generator_pimpl_label_type;
            typedef typename TypeGeneratorApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;
            typedef typename TypeGeneratorApiAt<ApiHolder, AssemblyGeneratorPimplLabel>::type assembly_generator_pimpl_label_type;

            typedef TypeGeneratorPimpl type_generator_pimpl_label_type;
            typedef TypeGenerator type_generator_label_type;
            typedef TypeGeneratorPersistedHandler type_generator_persisted_handler_label_type;
            typedef MethodGenerator method_generator_label_type;
            typedef MethodGeneratorPimpl method_generator_pimpl_label_type;
            typedef MethodBodyGenerator method_body_generator_label_type;
            typedef FieldGenerator field_generator_label_type;
            typedef FieldGeneratorPimpl field_generator_pimpl_label_type;
            typedef PropertyGenerator property_generator_label_type;
            typedef PropertyGeneratorPimpl property_generator_pimpl_label_type;
            typedef ModuleGenerator module_generator_label_type;
            typedef ModuleGeneratorPimpl module_generator_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_TYPE_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace TypeGeneratorFacadeDetail {

    template<
        class ApiHolder
    >    
    struct TypeGeneratorFacade : 
        TypeGeneratorFacadeDetail::TypeGeneratorFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_TYPE_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::TypeGeneratorFacade<ApiHolder> facade;

#define SWATHE_DECLARE_TYPE_GENERATOR_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_TYPE_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::type_generator_pimpl_label_type type_generator_pimpl_label_type; \
    friend typename type_generator_pimpl_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    typedef typename facade::type_generator_pimpl_label_type type_generator_pimpl_label_type; \
    typedef typename facade::type_generator_label_type type_generator_label_type; \
    typedef typename facade::type_generator_persisted_handler_label_type type_generator_persisted_handler_label_type; \
    typedef typename facade::method_generator_label_type method_generator_label_type; \
    typedef typename facade::method_generator_pimpl_label_type method_generator_pimpl_label_type; \
    typedef typename facade::method_body_generator_label_type method_body_generator_label_type; \
    typedef typename facade::field_generator_label_type field_generator_label_type; \
    typedef typename facade::field_generator_pimpl_label_type field_generator_pimpl_label_type; \
    typedef typename facade::property_generator_label_type property_generator_label_type; \
    typedef typename facade::property_generator_pimpl_label_type property_generator_pimpl_label_type; \
    typedef typename facade::module_generator_label_type module_generator_label_type; \
    typedef typename facade::module_generator_pimpl_label_type module_generator_pimpl_label_type; \
    friend typename type_generator_pimpl_label_type; \
    friend typename type_generator_label_type; \
    friend typename type_generator_persisted_handler_label_type; \
    friend typename method_generator_label_type; \
    friend typename method_generator_pimpl_label_type; \
    friend typename method_body_generator_label_type; \
    friend typename field_generator_label_type; \
    friend typename field_generator_pimpl_label_type; \
    friend typename property_generator_label_type; \
    friend typename property_generator_pimpl_label_type; \
    friend typename module_generator_label_type; \
    friend typename module_generator_pimpl_label_type; \

#define SWATHE_END_TYPE_GENERATOR_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_TYPEGENERATORFACADE_H

