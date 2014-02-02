/* 
 * File: PropertyGeneratorPimplFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_PROPERTYGENERATORPIMPLFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_PROPERTYGENERATORPIMPLFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_PROPERTYGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/PropertyGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/PropertyGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_PROPERTYGENERATORPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/PropertyGeneratorPersistedHandlerLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPimplFacade { 

    namespace PropertyGeneratorPimplFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::PropertyGeneratorApiAt;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::PropertyGeneratorFacade;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::PropertyGeneratorPersistedHandlerLabel;

        template<
            class ApiHolder
        >    
        struct PropertyGeneratorPimplFacadeImpl : 
            PropertyGeneratorFacade<ApiHolder>
        {
            typedef typename PropertyGeneratorApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;
            typedef typename PropertyGeneratorApiAt<ApiHolder, PropertyGeneratorPersistedHandlerLabel>::type property_generator_persisted_handler_label_type;
        };
    
    }   // namespace PropertyGeneratorPimplFacadeDetail {

    template<
        class ApiHolder
    >    
    struct PropertyGeneratorPimplFacade : 
        PropertyGeneratorPimplFacadeDetail::PropertyGeneratorPimplFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PROPERTY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassPimplFacade::PropertyGeneratorPimplFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PROPERTY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PROPERTY_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::property_generator_persisted_handler_label_type property_generator_persisted_handler_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename property_generator_persisted_handler_label_type; \

#define SWATHE_END_PROPERTY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPimplFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_PROPERTYGENERATORPIMPLFACADE_H

