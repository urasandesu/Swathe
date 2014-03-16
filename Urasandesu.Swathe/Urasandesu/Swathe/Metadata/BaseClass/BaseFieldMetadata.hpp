/* 
 * File: BaseFieldMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseFieldMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseFieldMetadata<ApiHolder>::BaseFieldMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(field_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(field_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())field_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseFieldMetadata<ApiHolder>::~BaseFieldMetadata()
    {
        Pimpl()->~field_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseFieldMetadata<ApiHolder>::field_metadata_pimpl_label_type *BaseFieldMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<field_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseFieldMetadata<ApiHolder>::field_metadata_pimpl_label_type const *BaseFieldMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_FIELD_METADATA_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseFieldMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdToken BaseFieldMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BaseFieldMetadata<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    CallingConventions BaseFieldMetadata<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }

    template<class ApiHolder>    
    IType const *BaseFieldMetadata<ApiHolder>::GetFieldType() const
    {
        return Pimpl()->GetFieldType();
    }

    template<class ApiHolder>    
    Signature const &BaseFieldMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IType const *BaseFieldMetadata<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }

    template<class ApiHolder>    
    FieldProvider const &BaseFieldMetadata<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IAssembly const *BaseFieldMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IField const *BaseFieldMetadata<ApiHolder>::GetSourceField() const
    {
        return Pimpl()->GetSourceField();
    }
    
    template<class ApiHolder>    
    bool BaseFieldMetadata<ApiHolder>::Equals(IField const *pField) const
    {
        return Pimpl()->Equals(pField);
    }

    template<class ApiHolder>    
    size_t BaseFieldMetadata<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    template<class ApiHolder>    
    void BaseFieldMetadata<ApiHolder>::SetToken(mdToken mdt)
    {
        Pimpl()->SetToken(mdt);
    }

    template<class ApiHolder>    
    void BaseFieldMetadata<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BaseFieldMetadata<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        Pimpl()->SetCallingConvention(callingConvention);
    }

    template<class ApiHolder>    
    void BaseFieldMetadata<ApiHolder>::SetFieldType(IType const *pFieldType)
    {
        Pimpl()->SetFieldType(pFieldType);
    }

    template<class ApiHolder>    
    void BaseFieldMetadata<ApiHolder>::SetMember(FieldProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDMETADATA_HPP

