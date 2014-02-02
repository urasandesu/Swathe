/* 
 * File: BaseTypeGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_TYPEGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/TypeGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeGeneratorFwd.h>
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

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::wstring;
    using std::vector;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseTypeGenerator : 
        public IType
    {
    public:
        SWATHE_BEGIN_TYPE_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_TYPE_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_TYPE_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseTypeGenerator();
        ~BaseTypeGenerator();

        void Initialize(assembly_generator_label_type *pAsmGen);
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
        type_generator_label_type *DefineNestedType(wstring const &fullName, TypeAttributes const &attr);
        field_generator_label_type *DefineField(wstring const &name, IType const *pFieldType, FieldAttributes const &attr);
        method_generator_label_type *DefineMethod(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes);
        method_generator_label_type *DefineDefaultConstructor(MethodAttributes const &attr);
        property_generator_label_type *DefineProperty(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, vector<IType const *> const &paramTypes);
    
    private:
        type_generator_pimpl_label_type *Pimpl();
        type_generator_pimpl_label_type const *Pimpl() const;
        void SetFullName(wstring const &fullName);
        void SetAttributes(TypeAttributes const &attr);
        void SetMember(TypeProvider const &member);
        void SetSourceType(IType const *pSrcType);
        void Accept(IMetadataVisitor *pVisitor) const;
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_H

