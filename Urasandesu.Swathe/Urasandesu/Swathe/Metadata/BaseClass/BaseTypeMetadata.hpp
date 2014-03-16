/* 
 * File: BaseTypeMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseTypeMetadata<ApiHolder>::BaseTypeMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(type_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(type_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())type_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseTypeMetadata<ApiHolder>::~BaseTypeMetadata()
    {
        Pimpl()->~type_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseTypeMetadata<ApiHolder>::type_metadata_pimpl_label_type *BaseTypeMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<type_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseTypeMetadata<ApiHolder>::type_metadata_pimpl_label_type const *BaseTypeMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_TYPE_METADATA_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdToken BaseTypeMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BaseTypeMetadata<ApiHolder>::GetFullName() const
    {
        return Pimpl()->GetFullName();
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::IsValueType() const
    {
        return Pimpl()->IsValueType();
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::IsGenericParameter() const
    {
        return Pimpl()->IsGenericParameter();
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::IsGenericType() const
    {
        return Pimpl()->IsGenericType();
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::IsGenericTypeDefinition() const
    {
        return Pimpl()->IsGenericTypeDefinition();
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::IsByRef() const
    {
        return Pimpl()->IsByRef();
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::IsArray() const
    {
        return Pimpl()->IsArray();
    }

    template<class ApiHolder>    
    ULONG BaseTypeMetadata<ApiHolder>::GetGenericParameterPosition() const
    {
        return Pimpl()->GetGenericParameterPosition();
    }

    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeMetadata<ApiHolder>::GetGenericArguments() const
    {
        return Pimpl()->GetGenericArguments();
    }

    template<class ApiHolder>    
    Signature const &BaseTypeMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IModule const *BaseTypeMetadata<ApiHolder>::GetModule() const
    {
        return Pimpl()->GetModule();
    }

    template<class ApiHolder>    
    IAssembly const *BaseTypeMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadata<ApiHolder>::GetDeclaringMethod() const
    {
        return Pimpl()->GetDeclaringMethod();
    }

    template<class ApiHolder>    
    TypeProvider const &BaseTypeMetadata<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::GetNestedType(mdToken mdt) const
    {
        return Pimpl()->GetNestedType(mdt);
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::GetGenericParameter(mdToken mdt) const
    {
        return Pimpl()->GetGenericParameter(mdt);
    }

    template<class ApiHolder>    
    ICustomAttribute const *BaseTypeMetadata<ApiHolder>::GetCustomAttribute(mdToken mdt) const
    {
        return Pimpl()->GetCustomAttribute(mdt);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadata<ApiHolder>::GetMethod(mdToken mdt) const
    {
        return Pimpl()->GetMethod(mdt);
    }

    template<class ApiHolder>    
    IProperty const *BaseTypeMetadata<ApiHolder>::GetProperty(mdToken mdt) const
    {
        return Pimpl()->GetProperty(mdt);
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::IsDefined(IType const *pAttrType) const
    {
        return Pimpl()->IsDefined(pAttrType);
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeMetadata<ApiHolder>::GetCustomAttributes() const
    {
        return Pimpl()->GetCustomAttributes();
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeMetadata<ApiHolder>::GetCustomAttributes(IType const *pAttributeType) const
    {
        return Pimpl()->GetCustomAttributes(pAttributeType);
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::GetSourceType() const
    {
        return Pimpl()->GetSourceType();
    }

    template<class ApiHolder>    
    TypeAttributes BaseTypeMetadata<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::GetBaseType() const
    {
        return Pimpl()->GetBaseType();
    }

    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeMetadata<ApiHolder>::GetInterfaces() const
    {
        return Pimpl()->GetInterfaces();
    }

    template<class ApiHolder>    
    bool BaseTypeMetadata<ApiHolder>::Equals(IType const *pType) const
    {
        return Pimpl()->Equals(pType);
    }

    template<class ApiHolder>    
    size_t BaseTypeMetadata<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::OutDebugInfo() const
    {
        Pimpl()->OutDebugInfo();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::MakeArrayType() const
    {
        return Pimpl()->MakeArrayType();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::MakeGenericType(vector<IType const *> const &genericArgs) const
    {
        return Pimpl()->MakeGenericType(genericArgs);
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::MakePointerType() const
    {
        return Pimpl()->MakePointerType();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::MakeByRefType() const
    {
        return Pimpl()->MakeByRefType();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::MakePinnedType() const
    {
        return Pimpl()->MakePinnedType();
    }

    template<class ApiHolder>    
    IType const *BaseTypeMetadata<ApiHolder>::GetNestedType(wstring const &name) const
    {
        return Pimpl()->GetNestedType(name);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadata<ApiHolder>::GetMethod(wstring const &name) const
    {
        return Pimpl()->GetMethod(name);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadata<ApiHolder>::GetMethod(wstring const &name, vector<IType const *> const &paramTypes) const
    {
        return Pimpl()->GetMethod(name, paramTypes);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadata<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes) const
    {
        return Pimpl()->GetMethod(name, callingConvention, pRetType, paramTypes);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadata<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IParameter const *> const &params) const
    {
        return Pimpl()->GetMethod(name, callingConvention, pRetType, params);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadata<ApiHolder>::GetConstructor(vector<IType const *> const &paramTypes) const
    {
        return Pimpl()->GetConstructor(paramTypes);
    }

    template<class ApiHolder>    
    IProperty const *BaseTypeMetadata<ApiHolder>::GetProperty(wstring const &name) const
    {
        return Pimpl()->GetProperty(name);
    }

    template<class ApiHolder>    
    ITypePtrRange BaseTypeMetadata<ApiHolder>::GetNestedTypes() const
    {
        return Pimpl()->GetNestedTypes();
    }

    template<class ApiHolder>    
    IMethodPtrRange BaseTypeMetadata<ApiHolder>::GetMethods() const
    {
        return Pimpl()->GetMethods();
    }

    template<class ApiHolder>    
    IMethodPtrRange BaseTypeMetadata<ApiHolder>::GetConstructors() const
    {
        return Pimpl()->GetConstructors();
    }

    template<class ApiHolder>    
    IPropertyPtrRange BaseTypeMetadata<ApiHolder>::GetProperties() const
    {
        return Pimpl()->GetProperties();
    }

    template<class ApiHolder>    
    TypeKinds BaseTypeMetadata<ApiHolder>::GetKind() const
    {
        return Pimpl()->GetKind();
    }

    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::SetToken(mdToken mdt)
    {
        Pimpl()->SetToken(mdt);
    }

    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::SetFullName(wstring const &fullName)
    {
        Pimpl()->SetFullName(fullName);
    }

    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::SetMember(TypeProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::SetGenericArguments(vector<IType const *> const &genericArgs)
    {
        Pimpl()->SetGenericArguments(genericArgs);
    }

    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::SetGenericParameterPosition(ULONG genericParamPos)
    {
        Pimpl()->SetGenericParameterPosition(genericParamPos);
    }

    template<class ApiHolder>    
    void BaseTypeMetadata<ApiHolder>::SetKind(TypeKinds const &kind)
    {
        Pimpl()->SetKind(kind);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_HPP

