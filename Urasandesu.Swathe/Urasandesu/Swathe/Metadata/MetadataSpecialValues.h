/* 
 * File: MetadataSpecialValues.h
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
#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#define URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    struct MetadataSpecialValues
    {
        static std::wstring const TYPE_NAME_OF_VOID;
        static std::wstring const TYPE_NAME_OF_BOOLEAN;
        static std::wstring const TYPE_NAME_OF_CHAR;
        static std::wstring const TYPE_NAME_OF_SBYTE;
        static std::wstring const TYPE_NAME_OF_BYTE;
        static std::wstring const TYPE_NAME_OF_INT16;
        static std::wstring const TYPE_NAME_OF_UINT16;
        static std::wstring const TYPE_NAME_OF_INT32;
        static std::wstring const TYPE_NAME_OF_UINT32;
        static std::wstring const TYPE_NAME_OF_INT64;
        static std::wstring const TYPE_NAME_OF_UINT64;
        static std::wstring const TYPE_NAME_OF_SINGLE;
        static std::wstring const TYPE_NAME_OF_DOUBLE;
        static std::wstring const TYPE_NAME_OF_STRING;
        static std::wstring const TYPE_NAME_OF_TYPEDBYREF;
        static std::wstring const TYPE_NAME_OF_INTPTR;
        static std::wstring const TYPE_NAME_OF_OBJECT;
        static std::wstring const TYPE_NAME_OF_VALUETYPE;
        static std::wstring const TYPE_NAME_OF_ENUM;
        static std::wstring const TYPE_NAME_OF_UNREACHED;
        static std::wstring const TYPE_NAME_OF_COMPILATION_RELAXATIONS_ATTRIBUTE;
        static std::wstring const TYPE_NAME_OF_RUNTIME_COMPATIBILITY_ATTRIBUTE;
        static std::wstring const GENERIC_TYPE_IDENTIFIER;
        static std::wstring const ASSEMBLY_FULL_NAME_OF_MSCORLIB;
        static std::wstring const MODULE_NAME_OF_MAIN;
        static std::wstring const METHOD_NAME_OF_CTOR;
        static std::wstring const METHOD_NAME_OF_CCTOR;
        static std::wstring const EMPTY_NAME;
        static std::vector<IType const *> const EMPTY_TYPES;
        static std::vector<IProperty const *> const EMPTY_PROPERTIES;
        static std::vector<IParameter const *> const EMPTY_PARAMETERS;
        static std::vector<CustomAttributeArgument> const EMPTY_CUSTOM_ATTRIBUTE_ARGUMENTS;
        static std::vector<ArrayDimension> const EMPTY_DIMENSIONS;
        static std::vector<ArrayDimension> const SZ_DIMENSIONS;
        static Signature const EMPTY_SIGNATURE;

        static TypeKinds ToTypeKind(std::wstring const &typeName)
        {
            if (typeName == TYPE_NAME_OF_VOID) return TypeKinds::TK_VOID;
            else if (typeName == TYPE_NAME_OF_BOOLEAN) return TypeKinds::TK_BOOLEAN;
            else if (typeName == TYPE_NAME_OF_CHAR) return TypeKinds::TK_CHAR;
            else if (typeName == TYPE_NAME_OF_SBYTE) return TypeKinds::TK_I1;
            else if (typeName == TYPE_NAME_OF_BYTE) return TypeKinds::TK_U1;
            else if (typeName == TYPE_NAME_OF_INT16) return TypeKinds::TK_I2;
            else if (typeName == TYPE_NAME_OF_UINT16) return TypeKinds::TK_U2;
            else if (typeName == TYPE_NAME_OF_INT32) return TypeKinds::TK_I4;
            else if (typeName == TYPE_NAME_OF_UINT32) return TypeKinds::TK_U4;
            else if (typeName == TYPE_NAME_OF_INT64) return TypeKinds::TK_I8;
            else if (typeName == TYPE_NAME_OF_UINT64) return TypeKinds::TK_U8;
            else if (typeName == TYPE_NAME_OF_SINGLE) return TypeKinds::TK_R4;
            else if (typeName == TYPE_NAME_OF_DOUBLE) return TypeKinds::TK_R8;
            else if (typeName == TYPE_NAME_OF_STRING) return TypeKinds::TK_STRING;
            else if (typeName == TYPE_NAME_OF_TYPEDBYREF) return TypeKinds::TK_TYPEDBYREF;
            else if (typeName == TYPE_NAME_OF_INTPTR) return TypeKinds::TK_I;
            else if (typeName == TYPE_NAME_OF_OBJECT) return TypeKinds::TK_OBJECT;
            else return TypeKinds::TK_UNREACHED;
        }

        static TypeKinds ToTypeKind(std::wstring const &typeName, std::wstring const &baseTypeName)
        {
            _ASSERTE(ToTypeKind(typeName) == TypeKinds::TK_UNREACHED);
            return baseTypeName == TYPE_NAME_OF_VALUETYPE || baseTypeName == TYPE_NAME_OF_ENUM ? TypeKinds::TK_VALUETYPE : TypeKinds::TK_CLASS;
        }

        static std::wstring const &ToTypeName(TypeKinds const &kind)
        {
            switch (kind.Value())
            {
                case TypeKinds::TK_VOID: return TYPE_NAME_OF_VOID;
                case TypeKinds::TK_BOOLEAN: return TYPE_NAME_OF_BOOLEAN;
                case TypeKinds::TK_CHAR: return TYPE_NAME_OF_CHAR;
                case TypeKinds::TK_I1: return TYPE_NAME_OF_SBYTE;
                case TypeKinds::TK_U1: return TYPE_NAME_OF_BYTE;
                case TypeKinds::TK_I2: return TYPE_NAME_OF_INT16;
                case TypeKinds::TK_U2: return TYPE_NAME_OF_UINT16;
                case TypeKinds::TK_I4: return TYPE_NAME_OF_INT32;
                case TypeKinds::TK_U4: return TYPE_NAME_OF_UINT32;
                case TypeKinds::TK_I8: return TYPE_NAME_OF_INT64;
                case TypeKinds::TK_U8: return TYPE_NAME_OF_UINT64;
                case TypeKinds::TK_R4: return TYPE_NAME_OF_SINGLE;
                case TypeKinds::TK_R8: return TYPE_NAME_OF_DOUBLE;
                case TypeKinds::TK_STRING: return TYPE_NAME_OF_STRING;
                case TypeKinds::TK_TYPEDBYREF: return TYPE_NAME_OF_TYPEDBYREF;
                case TypeKinds::TK_I: return TYPE_NAME_OF_INTPTR;
                case TypeKinds::TK_OBJECT: return TYPE_NAME_OF_OBJECT;
                default: return TYPE_NAME_OF_UNREACHED;
            }
        }
        
        static bool IsPrimitiveKind(TypeKinds const &kind)
        {
            switch (kind.Value())
            {
                case TypeKinds::TK_VOID: 
                case TypeKinds::TK_BOOLEAN: 
                case TypeKinds::TK_CHAR: 
                case TypeKinds::TK_I1: 
                case TypeKinds::TK_U1: 
                case TypeKinds::TK_I2: 
                case TypeKinds::TK_U2: 
                case TypeKinds::TK_I4: 
                case TypeKinds::TK_U4: 
                case TypeKinds::TK_I8: 
                case TypeKinds::TK_U8: 
                case TypeKinds::TK_R4: 
                case TypeKinds::TK_R8: 
                case TypeKinds::TK_STRING: 
                case TypeKinds::TK_TYPEDBYREF: 
                case TypeKinds::TK_I: 
                case TypeKinds::TK_OBJECT: 
                    return true;
                default: 
                    return false;
            }
        }

        static std::vector<ArrayDimension> MakeSZArrayDimensions()
        {
            auto arrDims = std::vector<ArrayDimension>();
            arrDims.push_back(ArrayDimension(-1, 0));
            return arrDims;
        }

        static bool IsArraysSpecialMethod(IMethod const *pMethod, IType const *pOwnerType);
        static IMethod *MakeEmptyMethod();
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
