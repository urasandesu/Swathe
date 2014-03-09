/* 
 * File: BaseTypeGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_TYPEGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/TypeGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseTypeGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYFWD_H
#include <Urasandesu/Swathe/Metadata/IPropertyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEHASH_H
#include <Urasandesu/Swathe/Metadata/ITypeHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ITypeEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using std::pair;
    using std::wstring;
    using std::vector;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseTypeGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_TYPE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_TYPE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_TYPE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseTypeGeneratorPimpl(type_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        wstring const &GetFullName() const;
        bool IsValueType() const;
        bool IsGenericParameter() const;
        bool IsGenericType() const;
        bool IsGenericTypeDefinition() const;
        bool IsByRef() const;
        bool IsArray() const;
        ULONG GetGenericParameterPosition() const;
        vector<IType const *> const &GetGenericArguments() const;
        Signature const &GetSignature() const;
        IType const *MakeArrayType() const;
        IType const *MakeGenericType(vector<IType const *> const &genericArgs) const;
        IType const *MakePointerType() const;
        IType const *MakeByRefType() const;
        IType const *MakePinnedType() const;
        IType const *GetNestedType(wstring const &name) const;
        IMethod const *GetMethod(wstring const &name) const;
        IMethod const *GetMethod(wstring const &name, vector<IType const *> const &paramTypes) const;
        IMethod const *GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes) const;
        IMethod const *GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IParameter const *> const &params) const;
        IMethod const *GetConstructor(vector<IType const *> const &paramTypes) const;
        IProperty const *GetProperty(wstring const &name) const;
        ITypePtrRange GetNestedTypes() const;
        IMethodPtrRange GetMethods() const;
        IMethodPtrRange GetConstructors() const;
        IPropertyPtrRange GetProperties() const;
        TypeKinds GetKind() const;
        TypeAttributes GetAttribute() const;
        IType const *GetBaseType() const;
        vector<IType const *> const &GetInterfaces() const;
        IModule const *GetModule() const;
        IAssembly const *GetAssembly() const;
        IType const *GetDeclaringType() const;
        IMethod const *GetDeclaringMethod() const;
        TypeProvider const &GetMember() const;
        IType const *GetNestedType(mdToken mdt) const;
        IType const *GetGenericParameter(mdToken mdt) const;
        ICustomAttribute const *GetCustomAttribute(mdToken mdt) const;
        IMethod const *GetMethod(mdToken mdt) const;
        IProperty const *GetProperty(mdToken mdt) const;
        bool IsDefined(IType const *pAttrType) const;
        ICustomAttributePtrRange GetCustomAttributes() const;
        ICustomAttributePtrRange GetCustomAttributes(IType const *pAttributeType) const;
        IType const *GetSourceType() const;
        bool Equals(IType const *pType) const;
        ULONG GetHashCode() const;
        void OutDebugInfo() const;
        type_generator_label_type *DefineNestedType(wstring const &fullName, TypeAttributes const &attr);
        field_generator_label_type *DefineField(wstring const &name, IType const *pFieldType, FieldAttributes const &attr);
        method_generator_label_type *DefineMethod(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes);
        method_generator_label_type *DefineDefaultConstructor(MethodAttributes const &attr);
        property_generator_label_type *DefineProperty(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, vector<IType const *> const &paramTypes);
    
    private:
        void SetFullName(wstring const &fullName);
        void SetAttributes(TypeAttributes const &attr);
        void SetMember(TypeProvider const &member);
        void SetSourceType(IType const *pSrcType);
        void Accept(IMetadataVisitor *pVisitor) const;
        
        

        mutable type_generator_label_type *m_pClass;
        assembly_generator_label_type *m_pAsmGen;
        mutable bool m_moduleInit;
        mutable bool m_declaringTypeInit;
        mutable bool m_declaringMethodInit;
        mutable TypeProvider m_member;
        mutable mdToken m_mdt;
        mutable wstring m_fullName;
        mutable TypeAttributes m_attr;
        mutable ULONG m_genericParamPos;
        mutable bool m_genericArgsInit;
        mutable vector<IType const *> m_genericArgs;
        mutable bool m_interfacesInit;
        mutable vector<IType const *> m_interfaces;
        mutable TypeKinds m_kind;
        mutable bool m_baseTypeInit;
        mutable IType const *m_pBaseType;
        IType const *m_pSrcType;
        mutable Signature m_sig;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPL_H

