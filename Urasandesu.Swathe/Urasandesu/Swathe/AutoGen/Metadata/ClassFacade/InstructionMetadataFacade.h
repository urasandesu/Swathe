/* 
 * File: InstructionMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_INSTRUCTIONMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_INSTRUCTIONMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_INSTRUCTIONMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/InstructionMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace InstructionMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::InstructionMetadataApiAt;
        using Urasandesu::Swathe::Metadata::InstructionMetadataPimpl;
        using Urasandesu::Swathe::Metadata::InstructionMetadata;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadata;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct InstructionMetadataFacadeImpl
        {
            typedef InstructionMetadata class_type;
            typedef InstructionMetadataPimpl class_pimpl_type;
            typedef InstructionMetadataPimpl instruction_metadata_pimpl_label_type;
            typedef typename InstructionMetadataApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_type;
            typedef typename InstructionMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;

            typedef InstructionMetadataPimpl instruction_metadata_pimpl_label_type;
            typedef InstructionMetadata instruction_metadata_label_type;
            typedef MethodBodyMetadata method_body_metadata_label_type;
            typedef MethodBodyMetadataPimpl method_body_metadata_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_INSTRUCTION_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace InstructionMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct InstructionMetadataFacade : 
        InstructionMetadataFacadeDetail::InstructionMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_INSTRUCTION_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::InstructionMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_INSTRUCTION_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_INSTRUCTION_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::instruction_metadata_pimpl_label_type instruction_metadata_pimpl_label_type; \
    friend typename instruction_metadata_pimpl_label_type; \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    friend typename metadata_dispenser_label_type; \
    friend typename assembly_metadata_label_type; \
    typedef typename facade::instruction_metadata_pimpl_label_type instruction_metadata_pimpl_label_type; \
    typedef typename facade::instruction_metadata_label_type instruction_metadata_label_type; \
    typedef typename facade::method_body_metadata_label_type method_body_metadata_label_type; \
    typedef typename facade::method_body_metadata_pimpl_label_type method_body_metadata_pimpl_label_type; \
    friend typename instruction_metadata_pimpl_label_type; \
    friend typename instruction_metadata_label_type; \
    friend typename method_body_metadata_label_type; \
    friend typename method_body_metadata_pimpl_label_type; \

#define SWATHE_END_INSTRUCTION_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_INSTRUCTIONMETADATAFACADE_H

