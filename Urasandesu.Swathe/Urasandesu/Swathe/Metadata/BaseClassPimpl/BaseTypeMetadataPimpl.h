/* 
 * File: BaseTypeMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_TYPEMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/TypeMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseTypeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODHASH_H
#include <Urasandesu/Swathe/Metadata/IMethodHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IMethodEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYFWD_H
#include <Urasandesu/Swathe/Metadata/IPropertyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYHASH_H
#include <Urasandesu/Swathe/Metadata/IPropertyHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IPropertyEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEHASH_H
#include <Urasandesu/Swathe/Metadata/ITypeHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ITypeEqualTo.h>
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

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::unordered_map;
    using std::wstring;
    using std::vector;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseTypeMetadataPimpl
    {
    public:
        SWATHE_BEGIN_TYPE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_TYPE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_TYPE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseTypeMetadataPimpl(type_metadata_label_type *pClass);

        void Initialize(assembly_metadata_label_type *pAsm);
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
        TypeAttributes GetAttribute() const;
        IType const *GetBaseType() const;
        vector<IType const *> const &GetInterfaces() const;
        IModule const *GetModule() const;
        IAssembly const *GetAssembly() const;
        IType const *GetDeclaringType() const;
        IMethod const *GetDeclaringMethod() const;
        TypeProvider const &GetMember() const;
        IType const *GetNestedType(mdToken mdt) const;
        ICustomAttribute const *GetCustomAttribute(mdToken mdt) const;
        IMethod const *GetMethod(mdToken mdt) const;
        IType const *GetGenericParameter(mdToken mdt) const;
        IProperty const *GetProperty(mdToken mdt) const;
        bool IsDefined(IType const *pAttrType) const;
        ICustomAttributePtrRange GetCustomAttributes() const;
        ICustomAttributePtrRange GetCustomAttributes(IType const *pAttributeType) const;
        IType const *GetSourceType() const;
        bool Equals(IType const *pType) const;
        ULONG GetHashCode() const;
        void OutDebugInfo() const;
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
    
    private:
        void SetToken(mdToken mdt);
        void SetFullName(wstring const &fullName);
        void SetMember(TypeProvider const &member);
        void SetGenericArguments(vector<IType const *> const &genericArgs);
        void SetGenericParameterPosition(ULONG genericParamPos);
        void SetKind(TypeKinds const &kind);
        static void FillTypeDefToken(IMetaDataImport2 *pComMetaImp, wstring const &fullName, mdToken &mdt);
        static void FillTypeDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, wstring &fullName, TypeAttributes &attr, mdToken &mdtExt);
        static void FillTypeDefBaseType(IType const *pType, mdToken mdtExt, bool &baseTypeInit, IType const *&pBaseType);
        static void FillTypeDefGenericParams(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &genericArgsInit, vector<IType const *> &genericArgs);
        static void FillTypeDefCustomAttributes(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &casInit, vector<ICustomAttribute const *> &cas);
        static void FillTypeDefMethods(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &methodsInit, vector<IMethod const *> &methods);
        static void FillTypeDefProperties(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &propsInit, vector<IProperty const *> &props);
        static void FillNestedTypeOwner(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner);
        static void FillTypeRefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, wstring &fullName, mdToken &mdtResolutionScope);
        static void FillTypeRefSourceType(IType const *pType, mdToken mdtResolutionScope, wstring const &fullName, IType const *&pSrcType);
        static void FillGenericParamProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, ULONG &genericParamPos, mdToken &mdtOwner, wstring &fullName);
        static void FillTypeMember(IType const *pType, mdToken mdtOwner, TypeProvider &member);
        static void FillTypeSpecSignature(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, Signature &sig);
        static void FillTypeSpecProperties(IType const *pType, Signature const &sig, TypeKinds &kind, TypeProvider &member, bool &genericArgsInit, vector<IType const *> &genericArgs);
        //static void FillAttributes(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, IType const *pOwner, bool &casInit, vector<ICustomAttribute const *> &cas);

        

        mutable type_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        mutable TypeProvider m_member;
        mutable mdToken m_mdt;
        mutable mdToken m_mdtResolutionScope;
        mutable mdToken m_mdtExt;
        mutable mdToken m_mdtOwner;
        mutable wstring m_fullName;
        mutable ULONG m_genericParamPos;
        mutable bool m_genericArgsInit;
        mutable vector<IType const *> m_genericArgs;
        mutable bool m_interfacesInit;
        mutable vector<IType const *> m_interfaces;
        mutable bool m_methodsInit;
        mutable vector<IMethod const *> m_methods;
        mutable bool m_propsInit;
        mutable vector<IProperty const *> m_props;
        mutable bool m_casInit;
        mutable vector<ICustomAttribute const *> m_cas;
        mutable Signature m_sig;
        mutable TypeKinds m_kind;
        mutable TypeAttributes m_attr;
        mutable bool m_baseTypeInit;
        mutable IType const *m_pBaseType;
        mutable IType const *m_pSrcType;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_H

