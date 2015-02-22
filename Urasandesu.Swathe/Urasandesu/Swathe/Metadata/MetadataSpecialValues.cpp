/* 
 * File: MetadataSpecialValues.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_VOID = L"System.Void";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_BOOLEAN = L"System.Boolean";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_CHAR = L"System.Char";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_SBYTE = L"System.SByte";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_BYTE = L"System.Byte";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT16 = L"System.Int16";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT16 = L"System.UInt16";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT32 = L"System.Int32";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT32 = L"System.UInt32";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT64 = L"System.Int64";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT64 = L"System.UInt64";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_SINGLE = L"System.Single";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_DOUBLE = L"System.Double";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_STRING = L"System.String";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_TYPEDBYREF = L"System.TypedReference";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INTPTR = L"System.IntPtr";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_OBJECT = L"System.Object";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_VALUETYPE = L"System.ValueType";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_ENUM = L"System.Enum";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UNREACHED = L"-";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_COMPILATION_RELAXATIONS_ATTRIBUTE = L"System.Runtime.CompilerServices.CompilationRelaxationsAttribute";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_RUNTIME_COMPATIBILITY_ATTRIBUTE = L"System.Runtime.CompilerServices.RuntimeCompatibilityAttribute";
    std::wstring const MetadataSpecialValues::GENERIC_TYPE_IDENTIFIER = L"`";
    std::wstring const MetadataSpecialValues::ASSEMBLY_FULL_NAME_OF_MSCORLIB = L"mscorlib, Culture=neutral, PublicKeyToken=b77a5c561934e089";
    std::wstring const MetadataSpecialValues::MODULE_NAME_OF_MAIN = L"*";
    std::wstring const MetadataSpecialValues::METHOD_NAME_OF_CTOR = L".ctor";
    std::wstring const MetadataSpecialValues::METHOD_NAME_OF_CCTOR = L".cctor";
    std::wstring const MetadataSpecialValues::EMPTY_NAME = L"";
    std::vector<IType const *> const MetadataSpecialValues::EMPTY_TYPES = std::vector<IType const *>();
    std::vector<IProperty const *> const MetadataSpecialValues::EMPTY_PROPERTIES = std::vector<IProperty const *>();
    std::vector<IParameter const *> const MetadataSpecialValues::EMPTY_PARAMETERS = std::vector<IParameter const *>();
    std::vector<CustomAttributeArgument> const MetadataSpecialValues::EMPTY_CUSTOM_ATTRIBUTE_ARGUMENTS = std::vector<CustomAttributeArgument>();
    std::vector<ArrayDimension> const MetadataSpecialValues::EMPTY_DIMENSIONS = std::vector<ArrayDimension>();
    std::vector<ArrayDimension> const MetadataSpecialValues::SZ_DIMENSIONS = MetadataSpecialValues::MakeSZArrayDimensions();
    Signature const MetadataSpecialValues::EMPTY_SIGNATURE = Signature();



    bool MetadataSpecialValues::IsArraysSpecialMethod(IMethod const *pMethod, IType const *pOwnerType)
    {
        _ASSERTE(pMethod);
        _ASSERTE(pOwnerType);
        return pOwnerType->IsArray() && 
                1 < pOwnerType->GetDimensions().size() && 
                (pMethod->GetName() == METHOD_NAME_OF_CTOR || 
                pMethod->GetName() == L"Get" || 
                pMethod->GetName() == L"Set" || 
                pMethod->GetName() == L"Address");
    }

    
    
    namespace EmptyMethodDetail {
        
        using std::wstring;
        using std::vector;
        using Urasandesu::CppAnonym::Utilities::HashValue;

        class EmptyMethod : 
            public IMethod
        {
        public:
            mdToken GetToken() const { return mdTokenNil; }
            wstring const &GetName() const { return MetadataSpecialValues::EMPTY_NAME; }
            CallingConventions GetCallingConvention() const { return CallingConventions::CC_UNREACHED; }
            MethodAttributes GetAttribute() const { return MethodAttributes::MA_UNREACHED; }
            IType const *GetReturnType() const { return nullptr; }
            vector<IParameter const *> const &GetParameters() const { return MetadataSpecialValues::EMPTY_PARAMETERS; }
            IMethodBody const *GetMethodBody() const { return nullptr; }
            ULONG GetCodeRVA() const { return -1; }
            bool IsStatic() const { return false; }
            bool IsGenericMethod() const { return false; }
            bool IsGenericMethodDefinition() const { return false; }
            vector<IType const *> const &GetGenericArguments() const { return MetadataSpecialValues::EMPTY_TYPES; }
            Signature const &GetSignature() const { return MetadataSpecialValues::EMPTY_SIGNATURE; }
            IMethod const *MakeGenericMethod(vector<IType const *> const &genericArgs) const { return nullptr; }
            IAssembly const *GetAssembly() const { return nullptr; }
            IType const *GetDeclaringType() const { return nullptr; }
            IMethod const *GetDeclaringMethod() const { return nullptr; }
            MethodProvider const &GetMember() const { return m_member; }
            IMethod const *GetSourceMethod() const { return nullptr; }
            bool Equals(IMethod const *pMethod) const { return this == pMethod; }
            size_t GetHashCode() const { return HashValue(this); }
            IParameter const *GetParameter(ULONG position, IType const *pParamType) const { return nullptr; }
            void OutDebugInfo() const { }
    
        private:
            MethodProvider m_member;
        };

    }   // namespace EmptyMethodDetail {

    IMethod *MetadataSpecialValues::MakeEmptyMethod()
    {
        using EmptyMethodDetail::EmptyMethod;

        static EmptyMethod method;
        return &method;
    }

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {
