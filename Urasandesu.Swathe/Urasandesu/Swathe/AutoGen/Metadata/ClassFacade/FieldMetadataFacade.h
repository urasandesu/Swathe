/* 
 * File: FieldMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_FIELDMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_FIELDMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_FIELDMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/FieldMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/FieldMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/FieldMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/FieldMetadataPersistedHandlerFwd.h>
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

    namespace FieldMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::FieldMetadataApiAt;
        using Urasandesu::Swathe::Metadata::FieldMetadataPimpl;
        using Urasandesu::Swathe::Metadata::FieldMetadata;
        using Urasandesu::Swathe::Metadata::FieldMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::TypeMetadata;
        using Urasandesu::Swathe::Metadata::TypeMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct FieldMetadataFacadeImpl
        {
            typedef FieldMetadata class_type;
            typedef FieldMetadataPimpl class_pimpl_type;
            typedef FieldMetadataPimpl field_metadata_pimpl_label_type;
            typedef typename FieldMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename FieldMetadataApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;

            typedef FieldMetadataPimpl field_metadata_pimpl_label_type;
            typedef FieldMetadata field_metadata_label_type;
            typedef FieldMetadataPersistedHandler field_metadata_persisted_handler_label_type;
            typedef TypeMetadata type_metadata_label_type;
            typedef TypeMetadataPimpl type_metadata_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_FIELD_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace FieldMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct FieldMetadataFacade : 
        FieldMetadataFacadeDetail::FieldMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_FIELD_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::FieldMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_FIELD_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_FIELD_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::field_metadata_pimpl_label_type field_metadata_pimpl_label_type; \
    friend typename field_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    typedef typename facade::field_metadata_pimpl_label_type field_metadata_pimpl_label_type; \
    typedef typename facade::field_metadata_label_type field_metadata_label_type; \
    typedef typename facade::field_metadata_persisted_handler_label_type field_metadata_persisted_handler_label_type; \
    typedef typename facade::type_metadata_label_type type_metadata_label_type; \
    typedef typename facade::type_metadata_pimpl_label_type type_metadata_pimpl_label_type; \
    friend typename field_metadata_pimpl_label_type; \
    friend typename field_metadata_label_type; \
    friend typename field_metadata_persisted_handler_label_type; \
    friend typename type_metadata_label_type; \
    friend typename type_metadata_pimpl_label_type; \

#define SWATHE_END_FIELD_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_FIELDMETADATAFACADE_H

