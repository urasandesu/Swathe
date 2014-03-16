/* 
 * File: BaseFieldGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseFieldGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseFieldGenerator<ApiHolder>::BaseFieldGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(field_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(field_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())field_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseFieldGenerator<ApiHolder>::~BaseFieldGenerator()
    {
        Pimpl()->~field_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseFieldGenerator<ApiHolder>::field_generator_pimpl_label_type *BaseFieldGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<field_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseFieldGenerator<ApiHolder>::field_generator_pimpl_label_type const *BaseFieldGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_FIELD_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseFieldGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdToken BaseFieldGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BaseFieldGenerator<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    CallingConventions BaseFieldGenerator<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }

    template<class ApiHolder>    
    IType const *BaseFieldGenerator<ApiHolder>::GetFieldType() const
    {
        return Pimpl()->GetFieldType();
    }

    template<class ApiHolder>    
    Signature const &BaseFieldGenerator<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IType const *BaseFieldGenerator<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }

    template<class ApiHolder>    
    FieldProvider const &BaseFieldGenerator<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IAssembly const *BaseFieldGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IField const *BaseFieldGenerator<ApiHolder>::GetSourceField() const
    {
        return Pimpl()->GetSourceField();
    }

    template<class ApiHolder>    
    bool BaseFieldGenerator<ApiHolder>::Equals(IField const *pField) const
    {
        return Pimpl()->Equals(pField);
    }

    template<class ApiHolder>    
    size_t BaseFieldGenerator<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    template<class ApiHolder>    
    FieldAttributes BaseFieldGenerator<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    void BaseFieldGenerator<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BaseFieldGenerator<ApiHolder>::SetFieldType(IType const *pFieldType)
    {
        Pimpl()->SetFieldType(pFieldType);
    }

    template<class ApiHolder>    
    void BaseFieldGenerator<ApiHolder>::SetAttributes(FieldAttributes const &attr)
    {
        Pimpl()->SetAttributes(attr);
    }

    template<class ApiHolder>    
    void BaseFieldGenerator<ApiHolder>::SetSourceField(IField const *pSrcField)
    {
        Pimpl()->SetSourceField(pSrcField);
    }

    template<class ApiHolder>    
    void BaseFieldGenerator<ApiHolder>::SetMember(FieldProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseFieldGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_HPP

