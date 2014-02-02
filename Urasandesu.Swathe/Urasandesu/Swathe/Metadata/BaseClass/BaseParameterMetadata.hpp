/* 
 * File: BaseParameterMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseParameterMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseParameterMetadata<ApiHolder>::BaseParameterMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(parameter_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(parameter_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())parameter_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseParameterMetadata<ApiHolder>::~BaseParameterMetadata()
    {
        Pimpl()->~parameter_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseParameterMetadata<ApiHolder>::parameter_metadata_pimpl_label_type *BaseParameterMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<parameter_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseParameterMetadata<ApiHolder>::parameter_metadata_pimpl_label_type const *BaseParameterMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PARAMETER_METADATA_ADDITIONAL_INSTANTIATION \

    
    

    template<class ApiHolder>    
    void BaseParameterMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdToken BaseParameterMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    ULONG BaseParameterMetadata<ApiHolder>::GetPosition() const
    {
        return Pimpl()->GetPosition();
    }

    template<class ApiHolder>    
    wstring const &BaseParameterMetadata<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    ParameterAttributes BaseParameterMetadata<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    IType const *BaseParameterMetadata<ApiHolder>::GetParameterType() const
    {
        return Pimpl()->GetParameterType();
    }

    template<class ApiHolder>    
    Signature const &BaseParameterMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseParameterMetadata<ApiHolder>::GetMethod() const
    {
        return Pimpl()->GetMethod();
    }

    template<class ApiHolder>    
    IProperty const *BaseParameterMetadata<ApiHolder>::GetProperty() const
    {
        return Pimpl()->GetProperty();
    }

    template<class ApiHolder>    
    ParameterProvider const &BaseParameterMetadata<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IParameter const *BaseParameterMetadata<ApiHolder>::GetSourceParameter() const
    {
        return Pimpl()->GetSourceParameter();
    }

    template<class ApiHolder>    
    void BaseParameterMetadata<ApiHolder>::OutDebugInfo(ULONG indent) const
    {
        Pimpl()->OutDebugInfo(indent);
    }

    template<class ApiHolder>    
    void BaseParameterMetadata<ApiHolder>::SetMember(ParameterProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseParameterMetadata<ApiHolder>::SetPosition(ULONG position)
    {
        Pimpl()->SetPosition(position);
    }

    template<class ApiHolder>    
    void BaseParameterMetadata<ApiHolder>::SetParameterType(IType const *pParamType)
    {
        Pimpl()->SetParameterType(pParamType);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERMETADATA_HPP

