/* 
 * File: BaseFieldGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_FIELDGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/FieldGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseFieldGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELD_H
#include <Urasandesu/Swathe/Metadata/IField.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseFieldGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_FIELD_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FIELD_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FIELD_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseFieldGeneratorPimpl(field_generator_label_type *pClass);

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
        void SetName(wstring const &name);
        void SetFieldType(IType const *pFieldType);
        void SetAttributes(FieldAttributes const &attr);
        void SetSourceField(IField const *pSrcField);
        void SetMember(FieldProvider const &member);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable field_generator_label_type *m_pClass;
        assembly_generator_label_type *m_pAsmGen;
        mutable bool m_declaringTypeInit;
        mutable FieldProvider m_member;
        mutable mdToken m_mdt;
        wstring m_name;
        mutable IType const *m_pFieldType;
        mutable bool m_fieldTypeInit;
        FieldAttributes m_attr;
        mutable Signature m_sig;
        IField const *m_pSrcField;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPL_H

