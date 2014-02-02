/* 
 * File: InstructionGeneratorFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_INSTRUCTIONGENERATORFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_INSTRUCTIONGENERATORFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_INSTRUCTIONGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/InstructionGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INSTRUCTIONGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/InstructionGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace InstructionGeneratorFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::InstructionGeneratorApiAt;
        using Urasandesu::Swathe::Metadata::InstructionGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::InstructionGenerator;
        using Urasandesu::Swathe::Metadata::MethodBodyGenerator;
        using Urasandesu::Swathe::Metadata::MethodBodyGeneratorPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct InstructionGeneratorFacadeImpl
        {
            typedef InstructionGenerator class_type;
            typedef InstructionGeneratorPimpl class_pimpl_type;
            typedef InstructionGeneratorPimpl instruction_generator_pimpl_label_type;
            typedef typename InstructionGeneratorApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;

            typedef InstructionGeneratorPimpl instruction_generator_pimpl_label_type;
            typedef InstructionGenerator instruction_generator_label_type;
            typedef MethodBodyGenerator method_body_generator_label_type;
            typedef MethodBodyGeneratorPimpl method_body_generator_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_INSTRUCTION_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace InstructionGeneratorFacadeDetail {

    template<
        class ApiHolder
    >    
    struct InstructionGeneratorFacade : 
        InstructionGeneratorFacadeDetail::InstructionGeneratorFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_INSTRUCTION_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::InstructionGeneratorFacade<ApiHolder> facade;

#define SWATHE_DECLARE_INSTRUCTION_GENERATOR_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_INSTRUCTION_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::instruction_generator_pimpl_label_type instruction_generator_pimpl_label_type; \
    friend typename instruction_generator_pimpl_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    friend typename assembly_generator_label_type; \
    typedef typename facade::instruction_generator_pimpl_label_type instruction_generator_pimpl_label_type; \
    typedef typename facade::instruction_generator_label_type instruction_generator_label_type; \
    typedef typename facade::method_body_generator_label_type method_body_generator_label_type; \
    typedef typename facade::method_body_generator_pimpl_label_type method_body_generator_pimpl_label_type; \
    friend typename instruction_generator_pimpl_label_type; \
    friend typename instruction_generator_label_type; \
    friend typename method_body_generator_label_type; \
    friend typename method_body_generator_pimpl_label_type; \

#define SWATHE_END_INSTRUCTION_GENERATOR_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_INSTRUCTIONGENERATORFACADE_H

