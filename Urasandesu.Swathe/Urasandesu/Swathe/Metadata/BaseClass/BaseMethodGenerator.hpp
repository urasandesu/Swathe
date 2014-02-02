/* 
 * File: BaseMethodGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseMethodGenerator<ApiHolder>::BaseMethodGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(method_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(method_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())method_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseMethodGenerator<ApiHolder>::~BaseMethodGenerator()
    {
        Pimpl()->~method_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseMethodGenerator<ApiHolder>::method_generator_pimpl_label_type *BaseMethodGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<method_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMethodGenerator<ApiHolder>::method_generator_pimpl_label_type const *BaseMethodGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_METHOD_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdToken BaseMethodGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BaseMethodGenerator<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    CallingConventions BaseMethodGenerator<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }

    template<class ApiHolder>    
    MethodAttributes BaseMethodGenerator<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    IType const *BaseMethodGenerator<ApiHolder>::GetReturnType() const
    {
        return Pimpl()->GetReturnType();
    }

    template<class ApiHolder>    
    vector<IParameter const *> const &BaseMethodGenerator<ApiHolder>::GetParameters() const
    {
        return Pimpl()->GetParameters();
    }

    template<class ApiHolder>    
    IMethodBody const *BaseMethodGenerator<ApiHolder>::GetMethodBody() const
    {
        return Pimpl()->GetMethodBody();
    }

    template<class ApiHolder>    
    ULONG BaseMethodGenerator<ApiHolder>::GetCodeRVA() const
    {
        return Pimpl()->GetCodeRVA();
    }

    template<class ApiHolder>    
    bool BaseMethodGenerator<ApiHolder>::IsStatic() const
    {
        return Pimpl()->IsStatic();
    }

    template<class ApiHolder>    
    bool BaseMethodGenerator<ApiHolder>::IsGenericMethod() const
    {
        return Pimpl()->IsGenericMethod();
    }

    template<class ApiHolder>    
    bool BaseMethodGenerator<ApiHolder>::IsGenericMethodDefinition() const
    {
        return Pimpl()->IsGenericMethodDefinition();
    }

    template<class ApiHolder>    
    vector<IType const *> const &BaseMethodGenerator<ApiHolder>::GetGenericArguments() const
    {
        return Pimpl()->GetGenericArguments();
    }

    template<class ApiHolder>    
    Signature const &BaseMethodGenerator<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodGenerator<ApiHolder>::MakeGenericMethod(vector<IType const *> const &genericArgs) const
    {
        return Pimpl()->MakeGenericMethod(genericArgs);
    }

    template<class ApiHolder>    
    IAssembly const *BaseMethodGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IType const *BaseMethodGenerator<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodGenerator<ApiHolder>::GetDeclaringMethod() const
    {
        return Pimpl()->GetDeclaringMethod();
    }

    template<class ApiHolder>    
    MethodProvider const &BaseMethodGenerator<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodGenerator<ApiHolder>::GetSourceMethod() const
    {
        return Pimpl()->GetSourceMethod();
    }

    template<class ApiHolder>    
    IDispenser const *BaseMethodGenerator<ApiHolder>::GetDispenser() const
    {
        return Pimpl()->GetDispenser();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodGenerator<ApiHolder>::ResolveMethod(IMethod const *pMethod) const
    {
        return Pimpl()->ResolveMethod(pMethod);
    }

    template<class ApiHolder>    
    IType const *BaseMethodGenerator<ApiHolder>::ResolveType(IType const *pType) const
    {
        return Pimpl()->ResolveType(pType);
    }

    template<class ApiHolder>    
    IMethodBody const *BaseMethodGenerator<ApiHolder>::ResolveMethodBody(IMethodBody const *pBody) const
    {
        return Pimpl()->ResolveMethodBody(pBody);
    }

    template<class ApiHolder>    
    IParameter const *BaseMethodGenerator<ApiHolder>::ResolveParameter(IParameter const *pParam) const
    {
        return Pimpl()->ResolveParameter(pParam);
    }

    template<class ApiHolder>    
    IParameter const *BaseMethodGenerator<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        return Pimpl()->GetParameter(position, pParamType);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::OutDebugInfo(ULONG indent) const
    {
        return Pimpl()->OutDebugInfo(indent);
    }

    template<class ApiHolder>    
    typename BaseMethodGenerator<ApiHolder>::method_body_generator_label_type *BaseMethodGenerator<ApiHolder>::DefineMethodBody()
    {
        return Pimpl()->DefineMethodBody();
    }

    template<class ApiHolder>    
    typename BaseMethodGenerator<ApiHolder>::parameter_generator_label_type *BaseMethodGenerator<ApiHolder>::DefineParameter(ULONG position, IType const *pParamType)
    {
        return Pimpl()->DefineParameter(position, pParamType);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetToken(mdToken mdt)
    {
        Pimpl()->SetToken(mdt);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        Pimpl()->SetCallingConvention(callingConvention);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetReturnType(IType const *pRetType)
    {
        Pimpl()->SetReturnType(pRetType);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetParameters(vector<IParameter const *> const &params)
    {
        Pimpl()->SetParameters(params);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetAttributes(MethodAttributes const &attr)
    {
        Pimpl()->SetAttributes(attr);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetMember(MethodProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::SetSourceMethod(IMethod const *pSrcMethod)
    {
        Pimpl()->SetSourceMethod(pSrcMethod);
    }

    template<class ApiHolder>    
    void BaseMethodGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_HPP

