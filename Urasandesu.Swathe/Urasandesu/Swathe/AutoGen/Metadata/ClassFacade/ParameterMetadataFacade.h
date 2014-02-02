/* 
 * File: ParameterMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PARAMETERMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PARAMETERMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_PARAMETERMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/ParameterMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PARAMETERMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ParameterMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace ParameterMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::ParameterMetadataApiAt;
        using Urasandesu::Swathe::Metadata::ParameterMetadataPimpl;
        using Urasandesu::Swathe::Metadata::ParameterMetadata;
        using Urasandesu::Swathe::Metadata::ParameterMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodMetadata;
        using Urasandesu::Swathe::Metadata::MethodMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ParameterMetadataFacadeImpl
        {
            typedef ParameterMetadata class_type;
            typedef ParameterMetadataPimpl class_pimpl_type;
            typedef ParameterMetadataPimpl parameter_metadata_pimpl_label_type;
            typedef typename ParameterMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename ParameterMetadataApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;

            typedef ParameterMetadataPimpl parameter_metadata_pimpl_label_type;
            typedef ParameterMetadata parameter_metadata_label_type;
            typedef ParameterMetadataPersistedHandler parameter_metadata_persisted_handler_label_type;
            typedef MethodMetadata method_metadata_label_type;
            typedef MethodMetadataPimpl method_metadata_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_PARAMETER_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace ParameterMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct ParameterMetadataFacade : 
        ParameterMetadataFacadeDetail::ParameterMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_PARAMETER_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::ParameterMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_PARAMETER_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_PARAMETER_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::parameter_metadata_pimpl_label_type parameter_metadata_pimpl_label_type; \
    friend typename parameter_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    typedef typename facade::parameter_metadata_pimpl_label_type parameter_metadata_pimpl_label_type; \
    typedef typename facade::parameter_metadata_label_type parameter_metadata_label_type; \
    typedef typename facade::parameter_metadata_persisted_handler_label_type parameter_metadata_persisted_handler_label_type; \
    typedef typename facade::method_metadata_label_type method_metadata_label_type; \
    typedef typename facade::method_metadata_pimpl_label_type method_metadata_pimpl_label_type; \
    friend typename parameter_metadata_pimpl_label_type; \
    friend typename parameter_metadata_label_type; \
    friend typename parameter_metadata_persisted_handler_label_type; \
    friend typename method_metadata_label_type; \
    friend typename method_metadata_pimpl_label_type; \

#define SWATHE_END_PARAMETER_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PARAMETERMETADATAFACADE_H

