/* 
 * File: IMetaDataImport2Impl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP
#define URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class Base
    >
    class ATL_NO_VTABLE IMetaDataImport2Impl : 
        public Base
    {
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_VOID_WRAPPER(CloseEnum, ((HCORENUM, hEnum)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(CountEnum, ((HCORENUM, hEnum))((ULONG *, pulCount)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ResetEnum, ((HCORENUM, hEnum))((ULONG, ulPos)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeDefs, ((HCORENUM *, phEnum))((mdTypeDef *, rTypeDefs))((ULONG, cMax))((ULONG *, pcTypeDefs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumInterfaceImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdInterfaceImpl *, rImpls))((ULONG, cMax))((ULONG*, pcImpls)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeRefs, ((HCORENUM *, phEnum))((mdTypeRef *, rTypeRefs))((ULONG, cMax))((ULONG*, pcTypeRefs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindTypeDefByName, ((LPCWSTR, szTypeDef))((mdToken, tkEnclosingClass))((mdTypeDef *, ptd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetScopeProps, ((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((GUID *, pmvid)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetModuleFromScope, ((mdModule *, pmd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeDefProps, ((mdTypeDef, td))((LPWSTR, szTypeDef))((ULONG, cchTypeDef))((ULONG *, pchTypeDef))((DWORD *, pdwTypeDefFlags))((mdToken *, ptkExtends)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetInterfaceImplProps, ((mdInterfaceImpl, iiImpl))((mdTypeDef *, pClass))((mdToken *, ptkIface)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeRefProps, ((mdTypeRef, tr))((mdToken *, ptkResolutionScope))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ResolveTypeRef, ((mdTypeRef, tr))((REFIID, riid))((IUnknown **, ppIScope))((mdTypeDef *, ptd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMembers, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMembersWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethods, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumFields, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumFieldsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumParams, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdParamDef *, rParams))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMemberRefs, ((HCORENUM *, phEnum))((mdToken, tkParent))((mdMemberRef *, rMemberRefs))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdToken *, rMethodBody))((mdToken *, rMethodDecl))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumPermissionSets, ((HCORENUM *, phEnum))((mdToken, tk))((DWORD, dwActions))((mdPermission *, rPermission))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMember, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdToken *, pmb)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMethod, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMethodDef *, pmb)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindField, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdFieldDef *, pmb)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMemberRef, ((mdTypeRef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMemberRef *, pmr)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodProps, ((mdMethodDef, mb))((mdTypeDef *, pClass))((LPWSTR, szMethod))((ULONG, cchMethod))((ULONG *, pchMethod))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMemberRefProps, ((mdMemberRef, mr))((mdToken *, ptk))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pbSig)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumProperties, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdProperty *, rProperties))((ULONG, cMax))((ULONG *, pcProperties)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumEvents, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdEvent *, rEvents))((ULONG, cMax))((ULONG *, pcEvents)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetEventProps, ((mdEvent, ev))((mdTypeDef *, pClass))((LPCWSTR, szEvent))((ULONG, cchEvent))((ULONG *, pchEvent))((DWORD *, pdwEventFlags))((mdToken *, ptkEventType))((mdMethodDef *, pmdAddOn))((mdMethodDef *, pmdRemoveOn))((mdMethodDef *, pmdFire))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodSemantics, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdToken *, rEventProp))((ULONG, cMax))((ULONG *, pcEventProp)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodSemantics, ((mdMethodDef, mb))((mdToken, tkEventProp))((DWORD *, pdwSemanticsFlags)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetClassLayout, ((mdTypeDef, td))((DWORD *, pdwPackSize))((COR_FIELD_OFFSET *, rFieldOffset))((ULONG, cMax))((ULONG *, pcFieldOffset))((ULONG *, pulClassSize)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetFieldMarshal, ((mdToken, tk))((PCCOR_SIGNATURE *, ppvNativeType))((ULONG *, pcbNativeType)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetRVA, ((mdToken, tk))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPermissionSetProps, ((mdPermission, pm))((DWORD *, pdwAction))((void const **, ppvPermission))((ULONG *, pcbPermission)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetSigFromToken, ((mdSignature, mdSig))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetModuleRefProps, ((mdModuleRef, mur))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumModuleRefs, ((HCORENUM *, phEnum))((mdModuleRef *, rModuleRefs))((ULONG, cmax))((ULONG *, pcModuleRefs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeSpecFromToken, ((mdTypeSpec, typespec))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNameFromToken, ((mdToken, tk))((MDUTF8CSTR *, pszUtf8NamePtr)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumUnresolvedMethods, ((HCORENUM *, phEnum))((mdToken *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetUserString, ((mdString, stk))((LPWSTR, szString))((ULONG, cchString))((ULONG *, pchString)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPinvokeMap, ((mdToken, tk))((DWORD *, pdwMappingFlags))((LPWSTR, szImportName))((ULONG, cchImportName))((ULONG *, pchImportName))((mdModuleRef *, pmrImportDLL)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumSignatures, ((HCORENUM *, phEnum))((mdSignature *, rSignatures))((ULONG, cmax))((ULONG *, pcSignatures)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeSpecs, ((HCORENUM *, phEnum))((mdTypeSpec *, rTypeSpecs))((ULONG, cmax))((ULONG *, pcTypeSpecs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumUserStrings, ((HCORENUM *, phEnum))((mdString *, rStrings))((ULONG, cmax))((ULONG *, pcStrings)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetParamForMethodIndex, ((mdMethodDef, md))((ULONG, ulParamSeq))((mdParamDef *, ppd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumCustomAttributes, ((HCORENUM *, phEnum))((mdToken, tk))((mdToken, tkType))((mdCustomAttribute *, rCustomAttributes))((ULONG, cMax))((ULONG *, pcCustomAttributes)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetCustomAttributeProps, ((mdCustomAttribute, cv))((mdToken *, ptkObj))((mdToken *, ptkType))((void const **, ppBlob))((ULONG *, pcbSize)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindTypeRef, ((mdToken, tkResolutionScope))((LPCWSTR, szName))((mdTypeRef *, ptr)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMemberProps, ((mdToken, mb))((mdTypeDef *, pClass))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetFieldProps, ((mdFieldDef, mb))((mdTypeDef *, pClass))((LPWSTR, szField))((ULONG, cchField))((ULONG *, pchField))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPropertyProps, ((mdProperty, prop))((mdTypeDef *, pClass))((LPCWSTR, szProperty))((ULONG, cchProperty))((ULONG *, pchProperty))((DWORD *, pdwPropFlags))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pbSig))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppDefaultValue))((ULONG *, pcchDefaultValue))((mdMethodDef *, pmdSetter))((mdMethodDef *, pmdGetter))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetParamProps, ((mdParamDef, tk))((mdMethodDef *, pmd))((ULONG *, pulSequence))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((DWORD *, pdwAttr))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetCustomAttributeByName, ((mdToken, tkObj))((LPCWSTR, szName))((const void **, ppData))((ULONG *, pcbData)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD__WRAPPER(BOOL, IsValidToken, ((mdToken, tk)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNestedClassProps, ((mdTypeDef, tdNestedClass))((mdTypeDef *, ptdEnclosingClass)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNativeCallConvFromSig, ((void const *, pvSig))((ULONG, cbSig))((ULONG *, pCallConv)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(IsGlobal, ((mdToken, pd))((int *, pbGlobal)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumGenericParams, ((HCORENUM *, phEnum))((mdToken, tk))((mdGenericParam *, rGenericParams))((ULONG, cMax))((ULONG *, pcGenericParams)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetGenericParamProps, ((mdGenericParam, gp))((ULONG *, pulParamSeq))((DWORD *, pdwParamFlags))((mdToken *, ptOwner))((DWORD *, reserved))((LPWSTR, wzname))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodSpecProps, ((mdMethodSpec, mi))((mdToken *, tkParent))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumGenericParamConstraints, ((HCORENUM *, phEnum))((mdGenericParam, tk))((mdGenericParamConstraint *, rGenericParamConstraints))((ULONG, cMax))((ULONG *, pcGenericParamConstraints)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetGenericParamConstraintProps, ((mdGenericParamConstraint, gpc))((mdGenericParam *, ptGenericParam))((mdToken *, ptkConstraintType)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPEKind, ((DWORD*, pdwPEKind))((DWORD*, pdwMAchine)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetVersionString, ((LPWSTR, pwzBuf))((DWORD, ccBufSize))((DWORD *, pccBufSize)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodSpecs, ((HCORENUM *, phEnum))((mdToken, tk))((mdMethodSpec *, rMethodSpecs))((ULONG, cMax))((ULONG *, pcMethodSpecs)))
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP
