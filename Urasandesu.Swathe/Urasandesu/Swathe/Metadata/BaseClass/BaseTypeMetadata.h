/* 
 * File: BaseTypeMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_TYPEMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/TypeMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeMetadataFwd.h>
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

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using boost::aligned_storage;
    using std::wstring;
    using std::vector;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseTypeMetadata : 
        public IType
    {
    public:
        SWATHE_BEGIN_TYPE_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_TYPE_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_TYPE_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseTypeMetadata();
        ~BaseTypeMetadata();

        void Initialize(assembly_metadata_label_type *pAsm);
        mdToken GetToken() const;
        wstring const &GetFullName() const;
        bool IsGenericParameter() const;
        bool IsGenericType() const;
        bool IsGenericTypeDefinition() const;
        bool IsByRef() const;
        bool IsArray() const;
        ULONG GetGenericParameterPosition() const;
        vector<IType const *> const &GetGenericArguments() const;
        Signature const &GetSignature() const;
        IType const *GetGenericTypeDefinition() const;
        TypeAttributes GetAttribute() const;
        IType const *GetBaseType() const;
        vector<IType const *> const &GetInterfaces() const;
        IModule const *GetModule() const;
        IAssembly const *GetAssembly() const;
        IType const *GetDeclaringType() const;
        IMethod const *GetDeclaringMethod() const;
        TypeProvider const &GetMember() const;
        IMethod const *GetMethod(mdToken mdt) const;
        IProperty const *GetProperty(mdToken mdt) const;
        IMethod const *ResolveMethod(IMethod const *pMethod) const;
        IProperty const *ResolveProperty(IProperty const *pProp) const;
        IField const *ResolveField(IField const *pField) const;
        IType const *ResolveType(IType const *pType) const;
        bool IsDefined(IType const *pAttrType, bool inherit) const;
        ICustomAttributePtrRange GetCustomAttributes(bool inherit) const;
        ICustomAttributePtrRange GetCustomAttributes(IType const *pAttributeType, bool inherit) const;
        IType const *GetSourceType() const;
        void OutDebugInfo(ULONG indent) const;
        IType const *MakeArrayType() const;
        IType const *MakeGenericType(vector<IType const *> const &genericArgs) const;
        IType const *MakeByRefType() const;
        IMethod const *GetMethod(wstring const &name) const;
        IMethod const *GetMethod(wstring const &name, vector<IType const *> const &paramTypes) const;
        IMethod const *GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes) const;
        IMethod const *GetConstructor(vector<IType const *> const &paramTypes) const;
        IProperty const *GetProperty(wstring const &name) const;
        IMethodPtrRange GetMethods() const;
        IMethodPtrRange GetConstructors() const;
        vector<IProperty const *> const &GetProperties() const;
        TypeKinds GetKind() const;
    
    private:
        type_metadata_pimpl_label_type *Pimpl();
        type_metadata_pimpl_label_type const *Pimpl() const;
        void SetToken(mdToken mdt);
        void SetFullName(wstring const &fullName);
        void SetMember(TypeProvider const &member);
        void SetGenericArguments(vector<IType const *> const &genericArgs);
        void SetKind(TypeKinds const &kind);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
        typedef typename aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEMETADATA_H

