/* 
 * File: PropertyGeneratorFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYGENERATORFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYGENERATORFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_PROPERTYGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/PropertyGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYGENERATORPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyGeneratorPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace PropertyGeneratorFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::PropertyGeneratorApiAt;
        using Urasandesu::Swathe::Metadata::PropertyGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::PropertyGenerator;
        using Urasandesu::Swathe::Metadata::PropertyGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::TypeGenerator;
        using Urasandesu::Swathe::Metadata::TypeGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::ParameterGenerator;
        using Urasandesu::Swathe::Metadata::ParameterGeneratorPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyGeneratorPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct PropertyGeneratorFacadeImpl
        {
            typedef PropertyGenerator class_type;
            typedef PropertyGeneratorPimpl class_pimpl_type;
            typedef PropertyGeneratorPimpl property_generator_pimpl_label_type;
            typedef typename PropertyGeneratorApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;
            typedef typename PropertyGeneratorApiAt<ApiHolder, AssemblyGeneratorPimplLabel>::type assembly_generator_pimpl_label_type;

            typedef PropertyGeneratorPimpl property_generator_pimpl_label_type;
            typedef PropertyGenerator property_generator_label_type;
            typedef PropertyGeneratorPersistedHandler property_generator_persisted_handler_label_type;
            typedef TypeGenerator type_generator_label_type;
            typedef TypeGeneratorPimpl type_generator_pimpl_label_type;
            typedef ParameterGenerator parameter_generator_label_type;
            typedef ParameterGeneratorPimpl parameter_generator_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_PROPERTY_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace PropertyGeneratorFacadeDetail {

    template<
        class ApiHolder
    >    
    struct PropertyGeneratorFacade : 
        PropertyGeneratorFacadeDetail::PropertyGeneratorFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PROPERTY_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::PropertyGeneratorFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PROPERTY_GENERATOR_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PROPERTY_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::property_generator_pimpl_label_type property_generator_pimpl_label_type; \
    friend typename property_generator_pimpl_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    typedef typename facade::property_generator_pimpl_label_type property_generator_pimpl_label_type; \
    typedef typename facade::property_generator_label_type property_generator_label_type; \
    typedef typename facade::property_generator_persisted_handler_label_type property_generator_persisted_handler_label_type; \
    typedef typename facade::type_generator_label_type type_generator_label_type; \
    typedef typename facade::type_generator_pimpl_label_type type_generator_pimpl_label_type; \
    typedef typename facade::parameter_generator_label_type parameter_generator_label_type; \
    typedef typename facade::parameter_generator_pimpl_label_type parameter_generator_pimpl_label_type; \
    friend typename property_generator_pimpl_label_type; \
    friend typename property_generator_label_type; \
    friend typename property_generator_persisted_handler_label_type; \
    friend typename type_generator_label_type; \
    friend typename type_generator_pimpl_label_type; \
    friend typename parameter_generator_label_type; \
    friend typename parameter_generator_pimpl_label_type; \

#define SWATHE_END_PROPERTY_GENERATOR_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYGENERATORFACADE_H

