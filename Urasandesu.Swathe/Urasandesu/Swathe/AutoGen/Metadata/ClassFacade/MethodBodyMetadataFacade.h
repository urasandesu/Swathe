/* 
 * File: MethodBodyMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODBODYMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODBODYMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_METHODBODYMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/MethodBodyMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionMetadataFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace MethodBodyMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::MethodBodyMetadataApiAt;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPimpl;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadata;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodMetadata;
        using Urasandesu::Swathe::Metadata::MethodMetadataPimpl;
        using Urasandesu::Swathe::Metadata::LocalMetadata;
        using Urasandesu::Swathe::Metadata::InstructionMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using Urasandesu::Swathe::Metadata::InstructionMetadata;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct MethodBodyMetadataFacadeImpl
        {
            typedef MethodBodyMetadata class_type;
            typedef MethodBodyMetadataPimpl class_pimpl_type;
            typedef MethodBodyMetadataPimpl method_body_metadata_pimpl_label_type;
            typedef typename MethodBodyMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename MethodBodyMetadataApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;

            typedef MethodBodyMetadataPimpl method_body_metadata_pimpl_label_type;
            typedef MethodBodyMetadata method_body_metadata_label_type;
            typedef MethodBodyMetadataPersistedHandler method_body_metadata_persisted_handler_label_type;
            typedef MethodMetadata method_metadata_label_type;
            typedef MethodMetadataPimpl method_metadata_pimpl_label_type;
            typedef LocalMetadata local_metadata_label_type;
            typedef InstructionMetadataPimpl instruction_metadata_pimpl_label_type;
            typedef InstructionMetadata instruction_metadata_label_type;

            
            
            
            typedef InstructionMetadata instruction_metadata_label_0b595903_type;
            
            typedef vector<
                ObjectTag<instruction_metadata_label_0b595903_type, VeryQuickHeapButMustAccessThroughEachMethod>
            > object_tag_types;
            typedef SimpleHeapProvider<object_tag_types> base_heap_provider_type;
            
            #define SWATHE_DECLARE_METHOD_BODY_METADATA_SIMPLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace MethodBodyMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct MethodBodyMetadataFacade : 
        MethodBodyMetadataFacadeDetail::MethodBodyMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_METHOD_BODY_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::MethodBodyMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_METHOD_BODY_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_METHOD_BODY_METADATA_SIMPLE_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::method_body_metadata_pimpl_label_type method_body_metadata_pimpl_label_type; \
    friend typename method_body_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    typedef typename facade::method_body_metadata_pimpl_label_type method_body_metadata_pimpl_label_type; \
    typedef typename facade::method_body_metadata_label_type method_body_metadata_label_type; \
    typedef typename facade::method_body_metadata_persisted_handler_label_type method_body_metadata_persisted_handler_label_type; \
    typedef typename facade::method_metadata_label_type method_metadata_label_type; \
    typedef typename facade::method_metadata_pimpl_label_type method_metadata_pimpl_label_type; \
    typedef typename facade::local_metadata_label_type local_metadata_label_type; \
    typedef typename facade::instruction_metadata_pimpl_label_type instruction_metadata_pimpl_label_type; \
    typedef typename facade::instruction_metadata_label_type instruction_metadata_label_type; \
    friend typename method_body_metadata_pimpl_label_type; \
    friend typename method_body_metadata_label_type; \
    friend typename method_body_metadata_persisted_handler_label_type; \
    friend typename method_metadata_label_type; \
    friend typename method_metadata_pimpl_label_type; \
    friend typename local_metadata_label_type; \
    friend typename instruction_metadata_pimpl_label_type; \
    friend typename instruction_metadata_label_type; \

#define SWATHE_END_METHOD_BODY_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODBODYMETADATAFACADE_H

