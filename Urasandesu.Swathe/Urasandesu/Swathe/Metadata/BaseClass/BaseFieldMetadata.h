/* 
 * File: BaseFieldMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_FIELDMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/FieldMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseFieldMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELD_H
#include <Urasandesu/Swathe/Metadata/IField.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseFieldMetadata : 
        public IField
    {
    public:
        SWATHE_BEGIN_FIELD_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FIELD_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FIELD_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseFieldMetadata();
        ~BaseFieldMetadata();
    
        void Initialize(assembly_metadata_label_type *pAsm);
        mdToken GetToken() const;
        wstring const &GetName() const;
        CallingConventions GetCallingConvention() const;
        IType const *GetFieldType() const;
        Signature const &GetSignature() const;
        IType const *GetDeclaringType() const;
        IAssembly const *GetAssembly() const;
        IField const *GetSourceField() const;

    private:
        field_metadata_pimpl_label_type *Pimpl();
        field_metadata_pimpl_label_type const *Pimpl() const;
        void SetToken(mdToken mdt);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetFieldType(IType const *pFieldType);
        void SetMember(FieldProvider const &member);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 28;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_H

