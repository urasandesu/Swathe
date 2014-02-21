/* 
 * File: BasePropertyGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BasePropertyGenerator<ApiHolder>::BasePropertyGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(property_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(property_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())property_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BasePropertyGenerator<ApiHolder>::~BasePropertyGenerator()
    {
        Pimpl()->~property_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BasePropertyGenerator<ApiHolder>::property_generator_pimpl_label_type *BasePropertyGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<property_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BasePropertyGenerator<ApiHolder>::property_generator_pimpl_label_type const *BasePropertyGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PROPERTY_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdProperty BasePropertyGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BasePropertyGenerator<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    CallingConventions BasePropertyGenerator<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }
    
    template<class ApiHolder>    
    IType const *BasePropertyGenerator<ApiHolder>::GetPropertyType() const
    {
        return Pimpl()->GetPropertyType();
    }

    template<class ApiHolder>    
    vector<IParameter const *> const &BasePropertyGenerator<ApiHolder>::GetParameters() const
    {
        return Pimpl()->GetParameters();
    }

    template<class ApiHolder>    
    PropertyAttributes BasePropertyGenerator<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }
    
    template<class ApiHolder>    
    IMethod const *BasePropertyGenerator<ApiHolder>::GetGetMethod() const
    {
        return Pimpl()->GetGetMethod();
    }
    
    template<class ApiHolder>    
    IMethod const *BasePropertyGenerator<ApiHolder>::GetSetMethod() const
    {
        return Pimpl()->GetSetMethod();
    }
    
    template<class ApiHolder>    
    Signature const &BasePropertyGenerator<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }
    
    template<class ApiHolder>    
    IType const *BasePropertyGenerator<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }
    
    template<class ApiHolder>    
    PropertyProvider const &BasePropertyGenerator<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IProperty const *BasePropertyGenerator<ApiHolder>::GetSourceProperty() const
    {
        return Pimpl()->GetSourceProperty();
    }

    template<class ApiHolder>    
    IAssembly const *BasePropertyGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IParameter const *BasePropertyGenerator<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        return Pimpl()->GetParameter(position, pParamType);
    }

    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetGetMethod(IMethod const *pGetMethod)
    {
        Pimpl()->SetGetMethod(pGetMethod);
    }
    
    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetSetMethod(IMethod const *pGetMethod)
    {
        Pimpl()->SetSetMethod(pGetMethod);
    }
    
    template<class ApiHolder>    
    typename BasePropertyGenerator<ApiHolder>::parameter_generator_label_type *BasePropertyGenerator<ApiHolder>::DefineParameter(ULONG position, IType const *pParamType)
    {
        return Pimpl()->DefineParameter(position, pParamType);
    }

    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }
    
    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetPropertyType(IType const *pPropType)
    {
        Pimpl()->SetPropertyType(pPropType);
    }

    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetParameters(vector<IParameter const *> const &params)
    {
        Pimpl()->SetParameters(params);
    }

    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetAttributes(PropertyAttributes const &attr)
    {
        Pimpl()->SetAttributes(attr);
    }
    
    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetSourceProperty(IProperty const *pSrcProp)
    {
        Pimpl()->SetSourceProperty(pSrcProp);
    }

    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::SetMember(PropertyProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BasePropertyGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_HPP

