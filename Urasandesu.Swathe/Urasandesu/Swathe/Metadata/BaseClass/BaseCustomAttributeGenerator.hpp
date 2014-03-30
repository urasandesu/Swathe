/* 
 * File: BaseCustomAttributeGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseCustomAttributeGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseCustomAttributeGenerator<ApiHolder>::BaseCustomAttributeGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(custom_attribute_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(custom_attribute_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())custom_attribute_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseCustomAttributeGenerator<ApiHolder>::~BaseCustomAttributeGenerator()
    {
        Pimpl()->~custom_attribute_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseCustomAttributeGenerator<ApiHolder>::custom_attribute_generator_pimpl_label_type *BaseCustomAttributeGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<custom_attribute_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseCustomAttributeGenerator<ApiHolder>::custom_attribute_generator_pimpl_label_type const *BaseCustomAttributeGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_CUSTOM_ATTRIBUTE_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    

    template<class ApiHolder>    
    void BaseCustomAttributeGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdToken BaseCustomAttributeGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    Signature const &BaseCustomAttributeGenerator<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseCustomAttributeGenerator<ApiHolder>::GetConstructor() const
    {
        return Pimpl()->GetConstructor();
    }

    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeGenerator<ApiHolder>::GetConstructorArguments() const
    {
        return Pimpl()->GetConstructorArguments();
    }

    template<class ApiHolder>    
    vector<IProperty const *> const &BaseCustomAttributeGenerator<ApiHolder>::GetNamedProperties() const
    {
        return Pimpl()->GetNamedProperties();
    }

    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeGenerator<ApiHolder>::GetPropertyValues() const
    {
        return Pimpl()->GetPropertyValues();
    }

    template<class ApiHolder>    
    vector<IField const *> const &BaseCustomAttributeGenerator<ApiHolder>::GetNamedFields() const
    {
        return Pimpl()->GetNamedFields();
    }

    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeGenerator<ApiHolder>::GetFieldValues() const
    {
        return Pimpl()->GetFieldValues();
    }

    template<class ApiHolder>    
    CustomAttributeProvider const &BaseCustomAttributeGenerator<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IAssembly const *BaseCustomAttributeGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IType const *BaseCustomAttributeGenerator<ApiHolder>::GetAttributeType() const
    {
        return Pimpl()->GetAttributeType();
    }

    template<class ApiHolder>    
    ICustomAttribute const *BaseCustomAttributeGenerator<ApiHolder>::GetSourceCustomAttribute() const
    {
        return Pimpl()->GetSourceCustomAttribute();
    }

    template<class ApiHolder>    
    bool BaseCustomAttributeGenerator<ApiHolder>::Equals(IType const *pAttributeType) const
    {
        return Pimpl()->Equals(pAttributeType);
    }

    template<class ApiHolder>    
    void BaseCustomAttributeGenerator<ApiHolder>::SetConstructor(IMethod const *pCtor)
    {
        Pimpl()->SetConstructor(pCtor);
    }

    template<class ApiHolder>    
    void BaseCustomAttributeGenerator<ApiHolder>::SetConstructorArguments(vector<CustomAttributeArgument> const &constructorArgs)
    {
        Pimpl()->SetConstructorArguments(constructorArgs);
    }

    template<class ApiHolder>    
    void BaseCustomAttributeGenerator<ApiHolder>::SetNamedProperties(vector<IProperty const *> const &namedProperties)
    {
        Pimpl()->SetNamedProperties(namedProperties);
    }

    template<class ApiHolder>    
    void BaseCustomAttributeGenerator<ApiHolder>::SetPropertyValues(vector<CustomAttributeArgument> const &propertyValues)
    {
        Pimpl()->SetPropertyValues(propertyValues);
    }

    template<class ApiHolder>    
    void BaseCustomAttributeGenerator<ApiHolder>::SetMember(CustomAttributeProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseCustomAttributeGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEGENERATOR_HPP

