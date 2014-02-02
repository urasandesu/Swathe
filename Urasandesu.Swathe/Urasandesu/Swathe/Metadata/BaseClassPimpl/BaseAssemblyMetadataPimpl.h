﻿/* 
 * File: BaseAssemblyMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_ASSEMBLYMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/AssemblyMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseAssemblyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_ISTRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/IStrongNameKey.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_PLATFORM_H
#include <Urasandesu/Swathe/Fusion/Platform.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULEHASH_H
#include <Urasandesu/Swathe/Metadata/IModuleHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IModuleEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEHASH_H
#include <Urasandesu/Swathe/Metadata/ITypeHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ITypeEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODHASH_H
#include <Urasandesu/Swathe/Metadata/IMethodHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IMethodEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYHASH_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERHASH_H
#include <Urasandesu/Swathe/Metadata/IParameterHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETEREQUALTO_H
#include <Urasandesu/Swathe/Metadata/IParameterEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALFWD_H
#include <Urasandesu/Swathe/Metadata/ILocalFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALHASH_H
#include <Urasandesu/Swathe/Metadata/ILocalHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ILocalEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYHASH_H
#include <Urasandesu/Swathe/Metadata/IPropertyHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IPropertyEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTEHASH_H
#include <Urasandesu/Swathe/Metadata/ICustomAttributeHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ICustomAttributeEqualTo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::any_range;
    using boost::filesystem::path;
    using boost::forward_traversal_tag;
    using boost::iterator_range;
    using boost::unordered_map;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
    using Urasandesu::CppAnonym::Utilities::Hash;
    using Urasandesu::CppAnonym::Utilities::EqualTo;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using Urasandesu::Swathe::StrongNaming::IStrongNameKey;
    using Urasandesu::Swathe::Fusion::Platform;
    using std::ptrdiff_t;
    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseAssemblyMetadataPimpl
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseAssemblyMetadataPimpl(assembly_metadata_label_type *pClass);

        void Initialize(metadata_info_label_type *pMetaInfo, metadata_dispenser_label_type *pDisp, portable_executable_info_label_type const *pPEInfo, fusion_info_label_type const *pFuInfo, strong_name_info_label_type const *pSnInfo);
        mdAssembly GetToken() const;
        wstring const &GetFullName() const;
        IModule const *GetMainModule() const;
        IModule const *GetModule(wstring const &name) const;
        AutoPtr<IStrongNameKey const> const &GetStrongNameKey() const;
        wstring const &GetName() const;
        ASSEMBLYMETADATA const &GetAssemblyMetadata() const;
        AssemblyFlags GetFlags() const;
        IAssembly const *GetSourceAssembly() const;
        IAssembly const *GetTargetAssembly() const;
        IDispenser const *GetDispenser() const;
        IMethod const *GetMethod(mdToken mdt) const;
        IMethod const *GetMethod(mdToken mdt, COR_ILMETHOD *pILBody) const;
        IType const *GetType(mdToken mdt) const;
        IType const *GetType(wstring const &fullName) const;
        vector<ProcessorArchitecture> const &GetProcessorArchitectures() const;
        IAssembly const *GetAssembly(wstring const &fullName) const;
        IAssembly const *GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const;
        IAssembly const *GetAssemblyReference(mdAssemblyRef mdt) const;
        IModule const *ResolveModule(IModule const *pMod) const;
        ICustomAttribute const *GetCustomAttribute(mdToken mdt) const;
        ICustomAttributePtrRange GetCustomAttributes(bool inherit) const;
        ICustomAttributePtrRange GetCustomAttributes(IType const *pAttributeType, bool inherit) const;
        iterator_range<BYTE const *> GetAssemblyStorage() const;
        bool Exists() const;
        
    private:
        void SetFullName(wstring const &fullName);
        void SetName(wstring const &name);
        void SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp);
        void SetAssemblyFilePath(path const &asmPath);
        void SetToken(mdToken mdt);

        module_metadata_label_type const *GetModuleCore(wstring const &name) const;
        TempPtr<module_metadata_label_type> NewModule(wstring const &name) const;
        bool TryGetModule(module_metadata_label_type const &mod, module_metadata_label_type *&pExistingMod) const;
        void RegisterModule(TempPtr<module_metadata_label_type> &pMod);
        
        type_metadata_label_type const *GetType(wstring const &fullName, TypeProvider const &member) const;
        type_metadata_label_type const *GetType(mdToken mdt, TypeKinds const &kind, bool genericArgsSpecified, vector<IType const *> const &genericArgs, TypeProvider const &member) const;
        TempPtr<type_metadata_label_type> NewType(wstring const &fullName, TypeProvider const &member) const;
        TempPtr<type_metadata_label_type> NewType(mdToken mdt, TypeKinds const &kind, bool genericArgsSpecified, vector<IType const *> const &genericArgs, TypeProvider const &member) const;
        bool TryGetType(type_metadata_label_type const &type, type_metadata_label_type *&pExistingType) const;
        void RegisterType(TempPtr<type_metadata_label_type> &pType);
        
        method_metadata_label_type const *GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member) const;
        method_metadata_label_type const *GetMethod(mdToken mdt, CallingConventions const &callingConvention, bool genericArgsSpecified, vector<IType const *> const &genericArgs, COR_ILMETHOD *pILBody, MethodProvider const &member) const;
        TempPtr<method_metadata_label_type> NewMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member) const;
        TempPtr<method_metadata_label_type> NewMethod(mdToken mdt, CallingConventions const &callingConvention, bool genericArgsSpecified, vector<IType const *> const &genericArgs, COR_ILMETHOD *pILBody, MethodProvider const &member) const;
        bool TryGetMethod(method_metadata_label_type const &method, method_metadata_label_type *&pExistingMethod) const;
        void RegisterMethod(TempPtr<method_metadata_label_type> &pMethod);
        
        method_body_metadata_label_type *GetMethodBody(COR_ILMETHOD *pILBody, IMethod const *pMethod) const;
        TempPtr<method_body_metadata_label_type> NewMethodBody(COR_ILMETHOD *pILBody, IMethod const *pMethod) const;
        bool TryGetMethodBody(method_body_metadata_label_type const &body, method_body_metadata_label_type *&pExistingBody) const;
        void RegisterMethodBody(TempPtr<method_body_metadata_label_type> &pBody);

        parameter_metadata_label_type const *GetParameter(ULONG position, IType const *pParamType, ParameterProvider const &member) const;
        TempPtr<parameter_metadata_label_type> NewParameter(ULONG position, IType const *pParamType, ParameterProvider const &member) const;
        bool TryGetParameter(parameter_metadata_label_type const &param, parameter_metadata_label_type *&pExistingParam) const;
        void RegisterParameter(TempPtr<parameter_metadata_label_type> &pParam);

        local_metadata_label_type const *GetLocal(ULONG index, IType const *pLocalType, IMethodBody const *pBody) const;
        TempPtr<local_metadata_label_type> NewLocal(ULONG index, IType const *pLocalType, IMethodBody const *pBody) const;
        bool TryGetLocal(local_metadata_label_type const &local, local_metadata_label_type *&pExistingLocal) const;
        void RegisterLocal(TempPtr<local_metadata_label_type> &pLocal);
        
        property_metadata_label_type const *GetProperty(mdToken mdt, PropertyProvider const &member) const;
        TempPtr<property_metadata_label_type> NewProperty(mdToken mdt, PropertyProvider const &member) const;
        bool TryGetProperty(property_metadata_label_type const &prop, property_metadata_label_type *&pExistingProp) const;
        void RegisterProperty(TempPtr<property_metadata_label_type> &pProp);
        
        custom_attribute_metadata_label_type const *GetCustomAttribute(mdToken mdt, CustomAttributeProvider const &member) const;
        TempPtr<custom_attribute_metadata_label_type> NewCustomAttribute(mdToken mdt, CustomAttributeProvider const &member) const;
        bool TryGetCustomAttribute(custom_attribute_metadata_label_type const &cas, custom_attribute_metadata_label_type *&pExistingCas) const;
        void RegisterCustomAttribute(TempPtr<custom_attribute_metadata_label_type> &pCas);

        IMetaDataAssemblyImport &GetCOMMetaDataAssemblyImport() const;
        IMetaDataImport2 &GetCOMMetaDataImport() const;
        path const &GetAssemblyFilePath() const;
        DWORD GetOpenFlags() const;
        void SetOpenFlags(DWORD openFlags);
        void SetOpeningAssembly(assembly_metadata_label_type const *pOpeningAsm);
        void SetProcessorArchitectures(vector<ProcessorArchitecture> const &procArchs);
        static void FillAssemblyProperties(assembly_metadata_pimpl_label_type const *_this, mdToken mdtTarget, wstring &name, AutoPtr<IStrongNameKey const> &pSnKey, ASSEMBLYMETADATA &amd,  vector<WCHAR> &locale, vector<OSINFO> &os, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags);
        static void FillAssemblyRefProperties(assembly_metadata_pimpl_label_type const *_this, mdToken mdtTarget, wstring &name, AutoPtr<IStrongNameKey const> &pSnKey, ASSEMBLYMETADATA &amd,  vector<WCHAR> &locale, vector<OSINFO> &os, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags);
        //static void FillAttributes(assembly_metadata_pimpl_label_type const *_this, vector<ICustomAttribute const *> &cas);
        static void FillPlatform(assembly_metadata_pimpl_label_type const *_this, ASSEMBLYMETADATA &amd, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags);
        static void ResolveAssemblyPathByCurrentDirectory(assembly_metadata_pimpl_label_type const *_this, wstring const &name, path &asmPath);
        static void ResolveAssemblyPathByGAC(assembly_metadata_pimpl_label_type const *_this, unordered_map<Platform, AutoPtr<assembly_name_label_type const>, Hash<Platform>, EqualTo<Platform> > const &candidates, path &asmPath);

        mutable assembly_metadata_label_type *m_pClass;
        metadata_info_label_type *m_pMetaInfo;
        metadata_dispenser_label_type *m_pDisp;
        portable_executable_info_label_type const *m_pPEInfo;
        fusion_info_label_type const *m_pFuInfo;
        strong_name_info_label_type const *m_pSnInfo;
        mutable unordered_map<IModule const *, SIZE_T, IModuleHash, IModuleEqualTo> m_modToIndex;
        mutable unordered_map<IType const *, SIZE_T, ITypeHash, ITypeEqualTo> m_typeToIndex;
        mutable unordered_map<IMethod const *, SIZE_T, IMethodHash, IMethodEqualTo> m_methodToIndex;
        mutable unordered_map<IParameter const *, SIZE_T, IParameterHash, IParameterEqualTo> m_paramToIndex;
        mutable unordered_map<ILocal const *, SIZE_T, ILocalHash, ILocalEqualTo> m_localToIndex;
        mutable unordered_map<IMethodBody const *, SIZE_T, IMethodBodyHash, IMethodBodyEqualTo> m_bodyToIndex;
        mutable unordered_map<IProperty const *, SIZE_T, IPropertyHash, IPropertyEqualTo> m_propToIndex;
        mutable unordered_map<ICustomAttribute const *, SIZE_T, ICustomAttributeHash, ICustomAttributeEqualTo> m_casToIndex;        
        mutable mdToken m_mdt;
        mutable wstring m_fullName;
        mutable AutoPtr<IStrongNameKey const> m_pSnKey;
        mutable bool m_casInit;
        mutable vector<ICustomAttribute const *> m_cas;
        mutable wstring m_name;
        mutable ASSEMBLYMETADATA m_amd;
        mutable vector<WCHAR> m_locale;
        mutable vector<OSINFO> m_os;
        mutable vector<ProcessorArchitecture> m_procArchs;
        mutable AssemblyFlags m_asmFlags;
        mutable path m_asmPath;
        mutable bool m_asmStorageInit;
        mutable iterator_range<BYTE const *> m_asmStorage;
        DWORD m_openFlags;
        assembly_metadata_label_type const *m_pOpeningAsm;
        IAssembly const *m_pSrcAsm;
        mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pComMetaAsmImp;
        mutable ATL::CComPtr<IMetaDataImport2> m_pComMetaImp;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_H
