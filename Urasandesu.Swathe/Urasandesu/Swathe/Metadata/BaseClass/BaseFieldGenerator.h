/* 
 * File: BaseFieldGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_FIELDGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/FieldGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseFieldGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELD_H
#include <Urasandesu/Swathe/Metadata/IField.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseFieldGenerator : 
        public IField
    {
    public:
        SWATHE_BEGIN_FIELD_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FIELD_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FIELD_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseFieldGenerator();
        ~BaseFieldGenerator();
        
        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        wstring const &GetName() const;
        CallingConventions GetCallingConvention() const;
        IType const *GetFieldType() const;
        Signature const &GetSignature() const;
        IType const *GetDeclaringType() const;
        IAssembly const *GetAssembly() const;
        IField const *GetSourceField() const;
        FieldAttributes GetAttribute() const;
    
    private:
        field_generator_pimpl_label_type *Pimpl();
        field_generator_pimpl_label_type const *Pimpl() const;
        void SetName(wstring const &name);
        void SetFieldType(IType const *pFieldType);
        void SetAttributes(FieldAttributes const &attr);
        void SetSourceField(IField const *pSrcField);
        void SetMember(FieldProvider const &member);
        void Accept(IMetadataVisitor *pVisitor) const;
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 88;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_H

