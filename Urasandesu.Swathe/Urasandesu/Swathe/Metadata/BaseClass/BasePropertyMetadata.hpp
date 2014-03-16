/* 
 * File: BasePropertyMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BasePropertyMetadata<ApiHolder>::BasePropertyMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(property_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(property_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())property_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BasePropertyMetadata<ApiHolder>::~BasePropertyMetadata()
    {
        Pimpl()->~property_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BasePropertyMetadata<ApiHolder>::property_metadata_pimpl_label_type *BasePropertyMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<property_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BasePropertyMetadata<ApiHolder>::property_metadata_pimpl_label_type const *BasePropertyMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PROPERTY_METADATA_ADDITIONAL_INSTANTIATION \

    
    

    template<class ApiHolder>    
    void BasePropertyMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdProperty BasePropertyMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BasePropertyMetadata<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    CallingConventions BasePropertyMetadata<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }

    template<class ApiHolder>    
    IType const *BasePropertyMetadata<ApiHolder>::GetPropertyType() const
    {
        return Pimpl()->GetPropertyType();
    }

    template<class ApiHolder>    
    vector<IParameter const *> const &BasePropertyMetadata<ApiHolder>::GetParameters() const
    {
        return Pimpl()->GetParameters();
    }

    template<class ApiHolder>    
    PropertyAttributes BasePropertyMetadata<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    IMethod const *BasePropertyMetadata<ApiHolder>::GetGetMethod() const
    {
        return Pimpl()->GetGetMethod();
    }

    template<class ApiHolder>    
    IMethod const *BasePropertyMetadata<ApiHolder>::GetSetMethod() const
    {
        return Pimpl()->GetSetMethod();
    }

    template<class ApiHolder>    
    Signature const &BasePropertyMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IType const *BasePropertyMetadata<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }

    template<class ApiHolder>    
    PropertyProvider const &BasePropertyMetadata<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IProperty const *BasePropertyMetadata<ApiHolder>::GetSourceProperty() const
    {
        return Pimpl()->GetSourceProperty();
    }

    template<class ApiHolder>    
    bool BasePropertyMetadata<ApiHolder>::Equals(IProperty const *pProp) const
    {
        return Pimpl()->Equals(pProp);
    }

    template<class ApiHolder>    
    size_t BasePropertyMetadata<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    template<class ApiHolder>    
    IAssembly const *BasePropertyMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IParameter const *BasePropertyMetadata<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        return Pimpl()->GetParameter(position, pParamType);
    }

    template<class ApiHolder>    
    void BasePropertyMetadata<ApiHolder>::SetToken(mdProperty mdp)
    {
        Pimpl()->SetToken(mdp);
    }
    
    template<class ApiHolder>    
    void BasePropertyMetadata<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BasePropertyMetadata<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        Pimpl()->SetCallingConvention(callingConvention);
    }

    template<class ApiHolder>    
    void BasePropertyMetadata<ApiHolder>::SetPropertyType(IType const *pPropType)
    {
        Pimpl()->SetPropertyType(pPropType);
    }

    template<class ApiHolder>    
    void BasePropertyMetadata<ApiHolder>::SetMember(PropertyProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_HPP

