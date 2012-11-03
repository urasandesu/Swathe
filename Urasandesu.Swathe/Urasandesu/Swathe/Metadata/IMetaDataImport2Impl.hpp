#pragma once
#ifndef URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP
#define URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP

#ifndef URASANDESU_SWATHE_DEFAULTSTDMETHODWRAPPER_H
#include <Urasandesu/Swathe/DefaultSTDMETHODWrapper.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class Base
    >
    class ATL_NO_VTABLE IMetaDataImport2Impl : public Base
    {
        SWATHE_DECLARE_DEFAULT_STDMETHOD_VOID_WRAPPER(CloseEnum, ((HCORENUM, hEnum)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(CountEnum, ((HCORENUM, hEnum))((ULONG *, pulCount)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ResetEnum, ((HCORENUM, hEnum))((ULONG, ulPos)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeDefs, ((HCORENUM *, phEnum))((mdTypeDef *, rTypeDefs))((ULONG, cMax))((ULONG *, pcTypeDefs)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumInterfaceImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdInterfaceImpl *, rImpls))((ULONG, cMax))((ULONG*, pcImpls)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeRefs, ((HCORENUM *, phEnum))((mdTypeRef *, rTypeRefs))((ULONG, cMax))((ULONG*, pcTypeRefs)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindTypeDefByName, ((LPCWSTR, szTypeDef))((mdToken, tkEnclosingClass))((mdTypeDef *, ptd)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetScopeProps, ((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((GUID *, pmvid)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetModuleFromScope, ((mdModule *, pmd)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeDefProps, ((mdTypeDef, td))((LPWSTR, szTypeDef))((ULONG, cchTypeDef))((ULONG *, pchTypeDef))((DWORD *, pdwTypeDefFlags))((mdToken *, ptkExtends)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetInterfaceImplProps, ((mdInterfaceImpl, iiImpl))((mdTypeDef *, pClass))((mdToken *, ptkIface)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeRefProps, ((mdTypeRef, tr))((mdToken *, ptkResolutionScope))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ResolveTypeRef, ((mdTypeRef, tr))((REFIID, riid))((IUnknown **, ppIScope))((mdTypeDef *, ptd)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMembers, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMembersWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethods, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumFields, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumFieldsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumParams, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdParamDef *, rParams))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMemberRefs, ((HCORENUM *, phEnum))((mdToken, tkParent))((mdMemberRef *, rMemberRefs))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdToken *, rMethodBody))((mdToken *, rMethodDecl))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumPermissionSets, ((HCORENUM *, phEnum))((mdToken, tk))((DWORD, dwActions))((mdPermission *, rPermission))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMember, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdToken *, pmb)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMethod, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMethodDef *, pmb)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindField, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdFieldDef *, pmb)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMemberRef, ((mdTypeRef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMemberRef *, pmr)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodProps, ((mdMethodDef, mb))((mdTypeDef *, pClass))((LPWSTR, szMethod))((ULONG, cchMethod))((ULONG *, pchMethod))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMemberRefProps, ((mdMemberRef, mr))((mdToken *, ptk))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pbSig)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumProperties, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdProperty *, rProperties))((ULONG, cMax))((ULONG *, pcProperties)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumEvents, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdEvent *, rEvents))((ULONG, cMax))((ULONG *, pcEvents)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetEventProps, ((mdEvent, ev))((mdTypeDef *, pClass))((LPCWSTR, szEvent))((ULONG, cchEvent))((ULONG *, pchEvent))((DWORD *, pdwEventFlags))((mdToken *, ptkEventType))((mdMethodDef *, pmdAddOn))((mdMethodDef *, pmdRemoveOn))((mdMethodDef *, pmdFire))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodSemantics, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdToken *, rEventProp))((ULONG, cMax))((ULONG *, pcEventProp)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodSemantics, ((mdMethodDef, mb))((mdToken, tkEventProp))((DWORD *, pdwSemanticsFlags)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetClassLayout, ((mdTypeDef, td))((DWORD *, pdwPackSize))((COR_FIELD_OFFSET *, rFieldOffset))((ULONG, cMax))((ULONG *, pcFieldOffset))((ULONG *, pulClassSize)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetFieldMarshal, ((mdToken, tk))((PCCOR_SIGNATURE *, ppvNativeType))((ULONG *, pcbNativeType)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetRVA, ((mdToken, tk))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPermissionSetProps, ((mdPermission, pm))((DWORD *, pdwAction))((void const **, ppvPermission))((ULONG *, pcbPermission)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetSigFromToken, ((mdSignature, mdSig))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetModuleRefProps, ((mdModuleRef, mur))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumModuleRefs, ((HCORENUM *, phEnum))((mdModuleRef *, rModuleRefs))((ULONG, cmax))((ULONG *, pcModuleRefs)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeSpecFromToken, ((mdTypeSpec, typespec))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNameFromToken, ((mdToken, tk))((MDUTF8CSTR *, pszUtf8NamePtr)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumUnresolvedMethods, ((HCORENUM *, phEnum))((mdToken *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetUserString, ((mdString, stk))((LPWSTR, szString))((ULONG, cchString))((ULONG *, pchString)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPinvokeMap, ((mdToken, tk))((DWORD *, pdwMappingFlags))((LPWSTR, szImportName))((ULONG, cchImportName))((ULONG *, pchImportName))((mdModuleRef *, pmrImportDLL)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumSignatures, ((HCORENUM *, phEnum))((mdSignature *, rSignatures))((ULONG, cmax))((ULONG *, pcSignatures)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeSpecs, ((HCORENUM *, phEnum))((mdTypeSpec *, rTypeSpecs))((ULONG, cmax))((ULONG *, pcTypeSpecs)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumUserStrings, ((HCORENUM *, phEnum))((mdString *, rStrings))((ULONG, cmax))((ULONG *, pcStrings)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetParamForMethodIndex, ((mdMethodDef, md))((ULONG, ulParamSeq))((mdParamDef *, ppd)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumCustomAttributes, ((HCORENUM *, phEnum))((mdToken, tk))((mdToken, tkType))((mdCustomAttribute *, rCustomAttributes))((ULONG, cMax))((ULONG *, pcCustomAttributes)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetCustomAttributeProps, ((mdCustomAttribute, cv))((mdToken *, ptkObj))((mdToken *, ptkType))((void const **, ppBlob))((ULONG *, pcbSize)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindTypeRef, ((mdToken, tkResolutionScope))((LPCWSTR, szName))((mdTypeRef *, ptr)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMemberProps, ((mdToken, mb))((mdTypeDef *, pClass))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetFieldProps, ((mdFieldDef, mb))((mdTypeDef *, pClass))((LPWSTR, szField))((ULONG, cchField))((ULONG *, pchField))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPropertyProps, ((mdProperty, prop))((mdTypeDef *, pClass))((LPCWSTR, szProperty))((ULONG, cchProperty))((ULONG *, pchProperty))((DWORD *, pdwPropFlags))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pbSig))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppDefaultValue))((ULONG *, pcchDefaultValue))((mdMethodDef *, pmdSetter))((mdMethodDef *, pmdGetter))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetParamProps, ((mdParamDef, tk))((mdMethodDef *, pmd))((ULONG *, pulSequence))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((DWORD *, pdwAttr))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetCustomAttributeByName, ((mdToken, tkObj))((LPCWSTR, szName))((const void **, ppData))((ULONG *, pcbData)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD__WRAPPER(BOOL, IsValidToken, ((mdToken, tk)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNestedClassProps, ((mdTypeDef, tdNestedClass))((mdTypeDef *, ptdEnclosingClass)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNativeCallConvFromSig, ((void const *, pvSig))((ULONG, cbSig))((ULONG *, pCallConv)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(IsGlobal, ((mdToken, pd))((int *, pbGlobal)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumGenericParams, ((HCORENUM *, phEnum))((mdToken, tk))((mdGenericParam *, rGenericParams))((ULONG, cMax))((ULONG *, pcGenericParams)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetGenericParamProps, ((mdGenericParam, gp))((ULONG *, pulParamSeq))((DWORD *, pdwParamFlags))((mdToken *, ptOwner))((DWORD *, reserved))((LPWSTR, wzname))((ULONG, cchName))((ULONG *, pchName)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodSpecProps, ((mdMethodSpec, mi))((mdToken *, tkParent))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumGenericParamConstraints, ((HCORENUM *, phEnum))((mdGenericParam, tk))((mdGenericParamConstraint *, rGenericParamConstraints))((ULONG, cMax))((ULONG *, pcGenericParamConstraints)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetGenericParamConstraintProps, ((mdGenericParamConstraint, gpc))((mdGenericParam *, ptGenericParam))((mdToken *, ptkConstraintType)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPEKind, ((DWORD*, pdwPEKind))((DWORD*, pdwMAchine)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetVersionString, ((LPWSTR, pwzBuf))((DWORD, ccBufSize))((DWORD *, pccBufSize)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodSpecs, ((HCORENUM *, phEnum))((mdToken, tk))((mdMethodSpec *, rMethodSpecs))((ULONG, cMax))((ULONG *, pcMethodSpecs)))
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_IMETADATAIMPORT2IMPL_HPP