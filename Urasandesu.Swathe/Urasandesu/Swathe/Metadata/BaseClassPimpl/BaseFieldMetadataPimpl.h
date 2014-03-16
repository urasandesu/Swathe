/* 
 * File: BaseFieldMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_FIELDMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/FieldMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseFieldMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using std::wstring;
    
    template<
        class ApiHolder
    >    
    class BaseFieldMetadataPimpl
    {
    public:
        SWATHE_BEGIN_FIELD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FIELD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FIELD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseFieldMetadataPimpl(field_metadata_label_type *pClass);

        void Initialize(assembly_metadata_label_type *pAsm);
        mdToken GetToken() const;
        wstring const &GetName() const;
        CallingConventions GetCallingConvention() const;
        IType const *GetFieldType() const;
        Signature const &GetSignature() const;
        IType const *GetDeclaringType() const;
        FieldProvider const &GetMember() const;
        IAssembly const *GetAssembly() const;
        IField const *GetSourceField() const;
        bool Equals(IField const *pField) const;
        size_t GetHashCode() const;
        
    private:
        void SetToken(mdToken mdt);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetFieldType(IType const *pFieldType);
        void SetMember(FieldProvider const &member);
        static void FillFieldDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, FieldAttributes &attr, Signature &sig);
        static void FillFieldMember(IField const *pField, mdToken mdtOwner, FieldProvider &member);

        mutable field_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        mutable FieldProvider m_member;
        mutable mdToken m_mdt;
        mutable mdToken m_mdtOwner;
        mutable wstring m_name;
        mutable CallingConventions m_callingConvention;
        mutable FieldAttributes m_attr;
        mutable IType const *m_pFieldType;
        mutable Signature m_sig;
        mutable IField const *m_pSrcField;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_H

