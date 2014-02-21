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
        CPPANONYM_STDMETHOD_VOID_NOEXCEPT(CloseEnum, ((HCORENUM, hEnum)))
        CPPANONYM_STDMETHOD_NOEXCEPT(CountEnum, ((HCORENUM, hEnum))((ULONG *, pulCount)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ResetEnum, ((HCORENUM, hEnum))((ULONG, ulPos)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumTypeDefs, ((HCORENUM *, phEnum))((mdTypeDef *, rTypeDefs))((ULONG, cMax))((ULONG *, pcTypeDefs)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumInterfaceImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdInterfaceImpl *, rImpls))((ULONG, cMax))((ULONG*, pcImpls)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumTypeRefs, ((HCORENUM *, phEnum))((mdTypeRef *, rTypeRefs))((ULONG, cMax))((ULONG*, pcTypeRefs)))
        CPPANONYM_STDMETHOD_NOEXCEPT(FindTypeDefByName, ((LPCWSTR, szTypeDef))((mdToken, tkEnclosingClass))((mdTypeDef *, ptd)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetScopeProps, ((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((GUID *, pmvid)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetModuleFromScope, ((mdModule *, pmd)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetTypeDefProps, ((mdTypeDef, td))((LPWSTR, szTypeDef))((ULONG, cchTypeDef))((ULONG *, pchTypeDef))((DWORD *, pdwTypeDefFlags))((mdToken *, ptkExtends)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetInterfaceImplProps, ((mdInterfaceImpl, iiImpl))((mdTypeDef *, pClass))((mdToken *, ptkIface)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetTypeRefProps, ((mdTypeRef, tr))((mdToken *, ptkResolutionScope))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ResolveTypeRef, ((mdTypeRef, tr))((REFIID, riid))((IUnknown **, ppIScope))((mdTypeDef *, ptd)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMembers, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMembersWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMethods, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMethodsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumFields, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumFieldsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumParams, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdParamDef *, rParams))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMemberRefs, ((HCORENUM *, phEnum))((mdToken, tkParent))((mdMemberRef *, rMemberRefs))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMethodImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdToken *, rMethodBody))((mdToken *, rMethodDecl))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumPermissionSets, ((HCORENUM *, phEnum))((mdToken, tk))((DWORD, dwActions))((mdPermission *, rPermission))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(FindMember, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdToken *, pmb)))
        CPPANONYM_STDMETHOD_NOEXCEPT(FindMethod, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMethodDef *, pmb)))
        CPPANONYM_STDMETHOD_NOEXCEPT(FindField, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdFieldDef *, pmb)))
        CPPANONYM_STDMETHOD_NOEXCEPT(FindMemberRef, ((mdTypeRef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMemberRef *, pmr)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetMethodProps, ((mdMethodDef, mb))((mdTypeDef *, pClass))((LPWSTR, szMethod))((ULONG, cchMethod))((ULONG *, pchMethod))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetMemberRefProps, ((mdMemberRef, mr))((mdToken *, ptk))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pbSig)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumProperties, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdProperty *, rProperties))((ULONG, cMax))((ULONG *, pcProperties)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumEvents, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdEvent *, rEvents))((ULONG, cMax))((ULONG *, pcEvents)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetEventProps, ((mdEvent, ev))((mdTypeDef *, pClass))((LPCWSTR, szEvent))((ULONG, cchEvent))((ULONG *, pchEvent))((DWORD *, pdwEventFlags))((mdToken *, ptkEventType))((mdMethodDef *, pmdAddOn))((mdMethodDef *, pmdRemoveOn))((mdMethodDef *, pmdFire))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMethodSemantics, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdToken *, rEventProp))((ULONG, cMax))((ULONG *, pcEventProp)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetMethodSemantics, ((mdMethodDef, mb))((mdToken, tkEventProp))((DWORD *, pdwSemanticsFlags)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetClassLayout, ((mdTypeDef, td))((DWORD *, pdwPackSize))((COR_FIELD_OFFSET *, rFieldOffset))((ULONG, cMax))((ULONG *, pcFieldOffset))((ULONG *, pulClassSize)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetFieldMarshal, ((mdToken, tk))((PCCOR_SIGNATURE *, ppvNativeType))((ULONG *, pcbNativeType)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetRVA, ((mdToken, tk))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetPermissionSetProps, ((mdPermission, pm))((DWORD *, pdwAction))((void const **, ppvPermission))((ULONG *, pcbPermission)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetSigFromToken, ((mdSignature, mdSig))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetModuleRefProps, ((mdModuleRef, mur))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumModuleRefs, ((HCORENUM *, phEnum))((mdModuleRef *, rModuleRefs))((ULONG, cmax))((ULONG *, pcModuleRefs)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetTypeSpecFromToken, ((mdTypeSpec, typespec))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetNameFromToken, ((mdToken, tk))((MDUTF8CSTR *, pszUtf8NamePtr)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumUnresolvedMethods, ((HCORENUM *, phEnum))((mdToken *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetUserString, ((mdString, stk))((LPWSTR, szString))((ULONG, cchString))((ULONG *, pchString)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetPinvokeMap, ((mdToken, tk))((DWORD *, pdwMappingFlags))((LPWSTR, szImportName))((ULONG, cchImportName))((ULONG *, pchImportName))((mdModuleRef *, pmrImportDLL)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumSignatures, ((HCORENUM *, phEnum))((mdSignature *, rSignatures))((ULONG, cmax))((ULONG *, pcSignatures)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumTypeSpecs, ((HCORENUM *, phEnum))((mdTypeSpec *, rTypeSpecs))((ULONG, cmax))((ULONG *, pcTypeSpecs)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumUserStrings, ((HCORENUM *, phEnum))((mdString *, rStrings))((ULONG, cmax))((ULONG *, pcStrings)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetParamForMethodIndex, ((mdMethodDef, md))((ULONG, ulParamSeq))((mdParamDef *, ppd)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumCustomAttributes, ((HCORENUM *, phEnum))((mdToken, tk))((mdToken, tkType))((mdCustomAttribute *, rCustomAttributes))((ULONG, cMax))((ULONG *, pcCustomAttributes)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetCustomAttributeProps, ((mdCustomAttribute, cv))((mdToken *, ptkObj))((mdToken *, ptkType))((void const **, ppBlob))((ULONG *, pcbSize)))
        CPPANONYM_STDMETHOD_NOEXCEPT(FindTypeRef, ((mdToken, tkResolutionScope))((LPCWSTR, szName))((mdTypeRef *, ptr)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetMemberProps, ((mdToken, mb))((mdTypeDef *, pClass))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetFieldProps, ((mdFieldDef, mb))((mdTypeDef *, pClass))((LPWSTR, szField))((ULONG, cchField))((ULONG *, pchField))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetPropertyProps, ((mdProperty, prop))((mdTypeDef *, pClass))((LPCWSTR, szProperty))((ULONG, cchProperty))((ULONG *, pchProperty))((DWORD *, pdwPropFlags))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pbSig))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppDefaultValue))((ULONG *, pcchDefaultValue))((mdMethodDef *, pmdSetter))((mdMethodDef *, pmdGetter))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetParamProps, ((mdParamDef, tk))((mdMethodDef *, pmd))((ULONG *, pulSequence))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((DWORD *, pdwAttr))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetCustomAttributeByName, ((mdToken, tkObj))((LPCWSTR, szName))((const void **, ppData))((ULONG *, pcbData)))
        CPPANONYM_STDMETHOD__NOEXCEPT(BOOL, IsValidToken, ((mdToken, tk)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetNestedClassProps, ((mdTypeDef, tdNestedClass))((mdTypeDef *, ptdEnclosingClass)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetNativeCallConvFromSig, ((void const *, pvSig))((ULONG, cbSig))((ULONG *, pCallConv)))
        CPPANONYM_STDMETHOD_NOEXCEPT(IsGlobal, ((mdToken, pd))((int *, pbGlobal)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumGenericParams, ((HCORENUM *, phEnum))((mdToken, tk))((mdGenericParam *, rGenericParams))((ULONG, cMax))((ULONG *, pcGenericParams)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetGenericParamProps, ((mdGenericParam, gp))((ULONG *, pulParamSeq))((DWORD *, pdwParamFlags))((mdToken *, ptOwner))((DWORD *, reserved))((LPWSTR, wzname))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetMethodSpecProps, ((mdMethodSpec, mi))((mdToken *, tkParent))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumGenericParamConstraints, ((HCORENUM *, phEnum))((mdGenericParam, tk))((mdGenericParamConstraint *, rGenericParamConstraints))((ULONG, cMax))((ULONG *, pcGenericParamConstraints)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetGenericParamConstraintProps, ((mdGenericParamConstraint, gpc))((mdGenericParam *, ptGenericParam))((mdToken *, ptkConstraintType)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetPEKind, ((DWORD*, pdwPEKind))((DWORD*, pdwMAchine)))
        CPPANONYM_STDMETHOD_NOEXCEPT(GetVersionString, ((LPWSTR, pwzBuf))((DWORD, ccBufSize))((DWORD *, pccBufSize)))
        CPPANONYM_STDMETHOD_NOEXCEPT(EnumMethodSpecs, ((HCORENUM *, phEnum))((mdToken, tk))((mdMethodSpec *, rMethodSpecs))((ULONG, cMax))((ULONG *, pcMethodSpecs)))
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP
