/* 
 * File: BaseParameterGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseParameterGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseParameterGenerator<ApiHolder>::BaseParameterGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(parameter_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(parameter_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())parameter_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseParameterGenerator<ApiHolder>::~BaseParameterGenerator()
    {
        Pimpl()->~parameter_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseParameterGenerator<ApiHolder>::parameter_generator_pimpl_label_type *BaseParameterGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<parameter_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseParameterGenerator<ApiHolder>::parameter_generator_pimpl_label_type const *BaseParameterGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PARAMETER_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    

    template<class ApiHolder>    
    void BaseParameterGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdToken BaseParameterGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    ULONG BaseParameterGenerator<ApiHolder>::GetPosition() const
    {
        return Pimpl()->GetPosition();
    }

    template<class ApiHolder>    
    wstring const &BaseParameterGenerator<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    ParameterAttributes BaseParameterGenerator<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    IType const *BaseParameterGenerator<ApiHolder>::GetParameterType() const
    {
        return Pimpl()->GetParameterType();
    }

    template<class ApiHolder>    
    Signature const &BaseParameterGenerator<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseParameterGenerator<ApiHolder>::GetMethod() const
    {
        return Pimpl()->GetMethod();
    }

    template<class ApiHolder>    
    IProperty const *BaseParameterGenerator<ApiHolder>::GetProperty() const
    {
        return Pimpl()->GetProperty();
    }

    template<class ApiHolder>    
    ParameterProvider const &BaseParameterGenerator<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IAssembly const *BaseParameterGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IParameter const *BaseParameterGenerator<ApiHolder>::GetSourceParameter() const
    {
        return Pimpl()->GetSourceParameter();
    }

    template<class ApiHolder>    
    bool BaseParameterGenerator<ApiHolder>::Equals(IParameter const *pParam) const
    {
        return Pimpl()->Equals(pParam);
    }

    template<class ApiHolder>    
    size_t BaseParameterGenerator<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    template<class ApiHolder>    
    void BaseParameterGenerator<ApiHolder>::OutDebugInfo() const
    {
        Pimpl()->OutDebugInfo();
    }

    template<class ApiHolder>    
    void BaseParameterGenerator<ApiHolder>::SetPosition(ULONG position)
    {
        return Pimpl()->SetPosition(position);
    }

    template<class ApiHolder>    
    void BaseParameterGenerator<ApiHolder>::SetParameterType(IType const *pParamType)
    {
        return Pimpl()->SetParameterType(pParamType);
    }

    template<class ApiHolder>    
    void BaseParameterGenerator<ApiHolder>::SetSourceParameter(IParameter const *pSrcParam)
    {
        return Pimpl()->SetSourceParameter(pSrcParam);
    }

    template<class ApiHolder>    
    void BaseParameterGenerator<ApiHolder>::SetMember(ParameterProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseParameterGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_HPP

