/* 
 * File: BaseTypeGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseTypeGenerator<ApiHolder>::BaseTypeGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(type_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(type_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())type_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseTypeGenerator<ApiHolder>::~BaseTypeGenerator()
    {
        Pimpl()->~type_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseTypeGenerator<ApiHolder>::type_generator_pimpl_label_type *BaseTypeGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<type_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseTypeGenerator<ApiHolder>::type_generator_pimpl_label_type const *BaseTypeGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_TYPE_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseTypeGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }
    
    template<class ApiHolder>    
    mdToken BaseTypeGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }
    
    template<class ApiHolder>    
    wstring const &BaseTypeGenerator<ApiHolder>::GetFullName() const
    {
        return Pimpl()->GetFullName();
    }
    
    template<class ApiHolder>    
    bool BaseTypeGenerator<ApiHolder>::IsValueType() const
    {
        return Pimpl()->IsValueType();
    }

    template<class ApiHolder>    
    bool BaseTypeGenerator<ApiHolder>::IsGenericParameter() const
    {
        return Pimpl()->IsGenericParameter();
    }
    
    template<class ApiHolder>    
    bool BaseTypeGenerator<ApiHolder>::IsGenericType() const
    {
        return Pimpl()->IsGenericType();
    }
    
    template<class ApiHolder>    
    bool BaseTypeGenerator<ApiHolder>::IsGenericTypeDefinition() const
    {
        return Pimpl()->IsGenericTypeDefinition();
    }
    
    template<class ApiHolder>    
    bool BaseTypeGenerator<ApiHolder>::IsByRef() const
    {
        return Pimpl()->IsByRef();
    }

    template<class ApiHolder>    
    bool BaseTypeGenerator<ApiHolder>::IsArray() const
    {
        return Pimpl()->IsArray();
    }

    template<class ApiHolder>    
    ULONG BaseTypeGenerator<ApiHolder>::GetGenericParameterPosition() const
    {
        return Pimpl()->GetGenericParameterPosition();
    }

    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeGenerator<ApiHolder>::GetGenericArguments() const
    {
        return Pimpl()->GetGenericArguments();
    }
    
    template<class ApiHolder>    
    Signature const &BaseTypeGenerator<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }
    
    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::MakeArrayType() const
    {
        return Pimpl()->MakeArrayType();
    }

    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::MakeGenericType(vector<IType const *> const &genericArgs) const
    {
        return Pimpl()->MakeGenericType(genericArgs);
    }
    
    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::MakePointerType() const
    {
        return Pimpl()->MakePointerType();
    }

    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::MakeByRefType() const
    {
        return Pimpl()->MakeByRefType();
    }

    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::MakePinnedType() const
    {
        return Pimpl()->MakePinnedType();
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeGenerator<ApiHolder>::GetMethod(wstring const &name) const
    {
        return Pimpl()->GetMethod(name);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeGenerator<ApiHolder>::GetMethod(wstring const &name, vector<IType const *> const &paramTypes) const
    {
        return Pimpl()->GetMethod(name, paramTypes);
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeGenerator<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes) const
    {
        return Pimpl()->GetMethod(name, callingConvention, pRetType, paramTypes);
    }
    
    template<class ApiHolder>    
    IMethod const *BaseTypeGenerator<ApiHolder>::GetConstructor(vector<IType const *> const &paramTypes) const
    {
        return Pimpl()->GetConstructor(paramTypes);
    }
    
    template<class ApiHolder>    
    IProperty const *BaseTypeGenerator<ApiHolder>::GetProperty(wstring const &name) const
    {
        return Pimpl()->GetProperty(name);
    }
    
    template<class ApiHolder>    
    IMethodPtrRange BaseTypeGenerator<ApiHolder>::GetMethods() const
    {
        return Pimpl()->GetMethods();
    }

    template<class ApiHolder>    
    IMethodPtrRange BaseTypeGenerator<ApiHolder>::GetConstructors() const
    {
        return Pimpl()->GetConstructors();
    }

    template<class ApiHolder>    
    vector<IProperty const *> const &BaseTypeGenerator<ApiHolder>::GetProperties() const
    {
        return Pimpl()->GetProperties();
    }
    
    template<class ApiHolder>    
    TypeKinds BaseTypeGenerator<ApiHolder>::GetKind() const
    {
        return Pimpl()->GetKind();
    }

    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::GetGenericTypeDefinition() const
    {
        return Pimpl()->GetGenericTypeDefinition();
    }
    
    template<class ApiHolder>    
    TypeAttributes BaseTypeGenerator<ApiHolder>::GetAttribute() const
    {
        return Pimpl()->GetAttribute();
    }

    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::GetBaseType() const
    {
        return Pimpl()->GetBaseType();
    }
    
    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeGenerator<ApiHolder>::GetInterfaces() const
    {
        return Pimpl()->GetInterfaces();
    }
    
    template<class ApiHolder>    
    IModule const *BaseTypeGenerator<ApiHolder>::GetModule() const
    {
        return Pimpl()->GetModule();
    }
    
    template<class ApiHolder>    
    IAssembly const *BaseTypeGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::GetDeclaringType() const
    {
        return Pimpl()->GetDeclaringType();
    }
    
    template<class ApiHolder>    
    IMethod const *BaseTypeGenerator<ApiHolder>::GetDeclaringMethod() const
    {
        return Pimpl()->GetDeclaringMethod();
    }

    template<class ApiHolder>    
    TypeProvider const &BaseTypeGenerator<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IMethod const *BaseTypeGenerator<ApiHolder>::GetMethod(mdToken mdt) const
    {
        return Pimpl()->GetMethod(mdt);
    }
    
    template<class ApiHolder>    
    IProperty const *BaseTypeGenerator<ApiHolder>::GetProperty(mdToken mdt) const
    {
        return Pimpl()->GetProperty(mdt);
    }

    template<class ApiHolder>    
    bool BaseTypeGenerator<ApiHolder>::IsDefined(IType const *pAttrType, bool inherit) const
    {
        return Pimpl()->IsDefined(pAttrType, inherit);
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeGenerator<ApiHolder>::GetCustomAttributes(bool inherit) const
    {
        return Pimpl()->GetCustomAttributes(inherit);
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeGenerator<ApiHolder>::GetCustomAttributes(IType const *pAttributeType, bool inherit) const
    {
        return Pimpl()->GetCustomAttributes(pAttributeType, inherit);
    }

    template<class ApiHolder>    
    IType const *BaseTypeGenerator<ApiHolder>::GetSourceType() const
    {
        return Pimpl()->GetSourceType();
    }

    template<class ApiHolder>    
    void BaseTypeGenerator<ApiHolder>::OutDebugInfo() const
    {
        Pimpl()->OutDebugInfo();
    }

    template<class ApiHolder>    
    typename BaseTypeGenerator<ApiHolder>::type_generator_label_type *BaseTypeGenerator<ApiHolder>::DefineNestedType(wstring const &fullName, TypeAttributes const &attr)
    {
        return Pimpl()->DefineNestedType(fullName, attr);
    }
    
    template<class ApiHolder>    
    typename BaseTypeGenerator<ApiHolder>::field_generator_label_type *BaseTypeGenerator<ApiHolder>::DefineField(wstring const &name, IType const *pFieldType, FieldAttributes const &attr)
    {
        return Pimpl()->DefineField(name, pFieldType, attr);
    }
    
    template<class ApiHolder>    
    typename BaseTypeGenerator<ApiHolder>::method_generator_label_type *BaseTypeGenerator<ApiHolder>::DefineMethod(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes)
    {
        return Pimpl()->DefineMethod(name, attr, callingConvention, pRetType, paramTypes);
    }
    
    template<class ApiHolder>    
    typename BaseTypeGenerator<ApiHolder>::method_generator_label_type *BaseTypeGenerator<ApiHolder>::DefineDefaultConstructor(MethodAttributes const &attr)
    {
        return Pimpl()->DefineDefaultConstructor(attr);
    }

    template<class ApiHolder>    
    typename BaseTypeGenerator<ApiHolder>::property_generator_label_type *BaseTypeGenerator<ApiHolder>::DefineProperty(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, vector<IType const *> const &paramTypes)
    {
        return Pimpl()->DefineProperty(name, attr, pPropType, paramTypes);
    }
    
    template<class ApiHolder>    
    void BaseTypeGenerator<ApiHolder>::SetFullName(wstring const &fullName)
    {
        Pimpl()->SetFullName(fullName);
    }

    template<class ApiHolder>    
    void BaseTypeGenerator<ApiHolder>::SetAttributes(TypeAttributes const &attr)
    {
        Pimpl()->SetAttributes(attr);
    }

    template<class ApiHolder>    
    void BaseTypeGenerator<ApiHolder>::SetMember(TypeProvider const &member)
    {
        Pimpl()->SetMember(member);
    }

    template<class ApiHolder>    
    void BaseTypeGenerator<ApiHolder>::SetSourceType(IType const *pSrcType)
    {
        Pimpl()->SetSourceType(pSrcType);
    }
    
    template<class ApiHolder>    
    void BaseTypeGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_HPP

