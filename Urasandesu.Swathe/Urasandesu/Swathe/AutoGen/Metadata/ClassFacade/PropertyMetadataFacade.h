/* 
 * File: PropertyMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_PROPERTYMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/PropertyMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace PropertyMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::PropertyMetadataApiAt;
        using Urasandesu::Swathe::Metadata::PropertyMetadataPimpl;
        using Urasandesu::Swathe::Metadata::PropertyMetadata;
        using Urasandesu::Swathe::Metadata::PropertyMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::TypeMetadata;
        using Urasandesu::Swathe::Metadata::TypeMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct PropertyMetadataFacadeImpl
        {
            typedef PropertyMetadata class_type;
            typedef PropertyMetadataPimpl class_pimpl_type;
            typedef PropertyMetadataPimpl property_metadata_pimpl_label_type;
            typedef typename PropertyMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename PropertyMetadataApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;

            typedef PropertyMetadataPimpl property_metadata_pimpl_label_type;
            typedef PropertyMetadata property_metadata_label_type;
            typedef PropertyMetadataPersistedHandler property_metadata_persisted_handler_label_type;
            typedef TypeMetadata type_metadata_label_type;
            typedef TypeMetadataPimpl type_metadata_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_PROPERTY_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace PropertyMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct PropertyMetadataFacade : 
        PropertyMetadataFacadeDetail::PropertyMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PROPERTY_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::PropertyMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PROPERTY_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PROPERTY_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::property_metadata_pimpl_label_type property_metadata_pimpl_label_type; \
    friend typename property_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    typedef typename facade::property_metadata_pimpl_label_type property_metadata_pimpl_label_type; \
    typedef typename facade::property_metadata_label_type property_metadata_label_type; \
    typedef typename facade::property_metadata_persisted_handler_label_type property_metadata_persisted_handler_label_type; \
    typedef typename facade::type_metadata_label_type type_metadata_label_type; \
    typedef typename facade::type_metadata_pimpl_label_type type_metadata_pimpl_label_type; \
    friend typename property_metadata_pimpl_label_type; \
    friend typename property_metadata_label_type; \
    friend typename property_metadata_persisted_handler_label_type; \
    friend typename type_metadata_label_type; \
    friend typename type_metadata_pimpl_label_type; \

#define SWATHE_END_PROPERTY_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYMETADATAFACADE_H

