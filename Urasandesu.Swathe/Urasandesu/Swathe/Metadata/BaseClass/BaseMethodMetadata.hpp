/* 
 * File: BaseMethodMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseMethodMetadata<ApiHolder>::BaseMethodMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(method_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(method_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())method_metadata_pimpl_label_type(this);
#ifdef _DEBUG
        m_pPimpl = Pimpl();
#endif
    }

    template<class ApiHolder>    
    BaseMethodMetadata<ApiHolder>::~BaseMethodMetadata()
    {
        Pimpl()->~method_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseMethodMetadata<ApiHolder>::method_metadata_pimpl_label_type *BaseMethodMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<method_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMethodMetadata<ApiHolder>::method_metadata_pimpl_label_type const *BaseMethodMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_METHOD_METADATA_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdToken BaseMethodMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BaseMethodMetadata<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    CallingConventions BaseMethodMetadata<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }

    template<class ApiHolder>    
    MethodAttributes BaseMethodMetadata<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    MethodImplAttributes BaseMethodMetadata<ApiHolder>::GetMethodImplementationFlags() const
    {
        return Pimpl()->GetMethodImplementationFlags();
    }

    template<class ApiHolder>    
    IType const *BaseMethodMetadata<ApiHolder>::GetReturnType() const
    {
        return Pimpl()->GetReturnType();
    }

    template<class ApiHolder>    
    vector<IParameter const *> const &BaseMethodMetadata<ApiHolder>::GetParameters() const
    {
        return Pimpl()->GetParameters();
    }

    template<class ApiHolder>    
    IMethodBody const *BaseMethodMetadata<ApiHolder>::GetMethodBody() const
    {
        return Pimpl()->GetMethodBody();
    }

    template<class ApiHolder>    
    ULONG BaseMethodMetadata<ApiHolder>::GetCodeRVA() const
    {
        return Pimpl()->GetCodeRVA();
    }

    template<class ApiHolder>    
    bool BaseMethodMetadata<ApiHolder>::IsStatic() const
    {
        return Pimpl()->IsStatic();
    }

    template<class ApiHolder>    
    bool BaseMethodMetadata<ApiHolder>::IsGenericMethod() const
    {
        return Pimpl()->IsGenericMethod();
    }

    template<class ApiHolder>    
    bool BaseMethodMetadata<ApiHolder>::IsGenericMethodDefinition() const
    {
        return Pimpl()->IsGenericMethodDefinition();
    }

    template<class ApiHolder>    
    vector<IType const *> const &BaseMethodMetadata<ApiHolder>::GetGenericArguments() const
    {
        return Pimpl()->GetGenericArguments();
    }

    template<class ApiHolder>    
    Signature const &BaseMethodMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodMetadata<ApiHolder>::MakeGenericMethod(vector<IType const *> const &genericArgs) const
    {
        return Pimpl()->MakeGenericMethod(genericArgs);
    }

    template<class ApiHolder>    
    IAssembly const *BaseMethodMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IType const *BaseMethodMetadata<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodMetadata<ApiHolder>::GetDeclaringMethod() const
    {
        return Pimpl()->GetDeclaringMethod();
    }

    template<class ApiHolder>    
    MethodProvider const &BaseMethodMetadata<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodMetadata<ApiHolder>::GetSourceMethod() const
    {
        return Pimpl()->GetSourceMethod();
    }

    template<class ApiHolder>    
    bool BaseMethodMetadata<ApiHolder>::Equals(IMethod const *pMethod) const
    {
        return Pimpl()->Equals(pMethod);
    }

    template<class ApiHolder>    
    size_t BaseMethodMetadata<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    //template<class ApiHolder>    
    //IDispenser const *BaseMethodMetadata<ApiHolder>::GetDispenser() const
    //{
    //    return Pimpl()->GetDispenser();
    //}

    template<class ApiHolder>    
    IParameter const *BaseMethodMetadata<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        return Pimpl()->GetParameter(position, pParamType);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::OutDebugInfo() const
    {
        Pimpl()->OutDebugInfo();
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetILMethodBody(COR_ILMETHOD *pILBody)
    {
        Pimpl()->SetILMethodBody(pILBody);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetToken(mdMethodDef mdmd)
    {
        Pimpl()->SetToken(mdmd);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        Pimpl()->SetCallingConvention(callingConvention);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetReturnType(IType const *pRetType)
    {
        Pimpl()->SetReturnType(pRetType);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetParameters(vector<IParameter const *> const &params)
    {
        Pimpl()->SetParameters(params);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetMember(MethodProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseMethodMetadata<ApiHolder>::SetGenericArguments(vector<IType const *> const &genericArgs)
    {
        Pimpl()->SetGenericArguments(genericArgs);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_HPP

