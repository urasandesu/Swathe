﻿/* 
 * File: FieldMetadataPimplFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_FIELDMETADATAPIMPLFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_FIELDMETADATAPIMPLFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_FIELDMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/FieldMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_FIELDMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/FieldMetadataFacade.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPimplFacade { 

    namespace FieldMetadataPimplFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::FieldMetadataApiAt;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::FieldMetadataFacade;

        template<
            class ApiHolder
        >    
        struct FieldMetadataPimplFacadeImpl : 
            FieldMetadataFacade<ApiHolder>
        {

        };
    
    }   // namespace FieldMetadataPimplFacadeDetail {

    template<
        class ApiHolder
    >    
    struct FieldMetadataPimplFacade : 
        FieldMetadataPimplFacadeDetail::FieldMetadataPimplFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_FIELD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassPimplFacade::FieldMetadataPimplFacade<ApiHolder> facade;

#define SWATHE_DECLARE_FIELD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_FIELD_METADATA_FACADE_TYPEDEF_ALIAS \



#define SWATHE_END_FIELD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPimplFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_FIELDMETADATAPIMPLFACADE_H

