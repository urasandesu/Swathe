/* 
 * File: BaseAssemblyMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/AssemblyMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_ISTRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/IStrongNameKey.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_IPORTABLEEXECUTABLEREADER_H
#include <Urasandesu/Swathe/Hosting/IPortableExecutableReader.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYFWD_H
#include <Urasandesu/Swathe/Metadata/IPropertyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODIMPLATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodImplAttributes.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using boost::any_range;
    using boost::aligned_storage;
    using boost::filesystem::path;
    using boost::forward_traversal_tag;
    using boost::iterator_range;
    using std::ptrdiff_t;
    using std::wstring;
    using std::vector;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using Urasandesu::Swathe::StrongNaming::IStrongNameKey;
    using Urasandesu::Swathe::Hosting::IPortableExecutableReader;

    template<
        class ApiHolder
    >    
    class BaseAssemblyMetadata : 
        public IAssembly
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseAssemblyMetadata();
        ~BaseAssemblyMetadata();

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
        IField const *GetField(mdToken mdt) const;
        IMethod const *GetMethod(mdToken mdt) const;
        IMethod const *GetMethod(mdToken mdt, COR_ILMETHOD *pILBody) const;
        IType const *GetType(mdToken mdt) const;
        IType const *GetType(wstring const &fullName) const;
        IType const *GetGenericTypeParameter(ULONG genericParamPos) const;
        IType const *GetGenericMethodParameter(ULONG genericParamPos) const;
        vector<ProcessorArchitecture> const &GetProcessorArchitectures() const;
        IAssembly const *GetAssembly(wstring const &fullName) const;
        IAssembly const *GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const;
        IAssembly const *GetAssemblyReference(mdAssemblyRef mdt) const;
        ICustomAttribute const *GetCustomAttribute(mdToken mdt) const;
        ICustomAttributePtrRange GetCustomAttributes() const;
        ICustomAttributePtrRange GetCustomAttributes(IType const *pAttributeType) const;
        ITypePtrRange GetTypes() const;
        AutoPtr<IPortableExecutableReader const> const &GetPortableExecutableReader() const;
        bool Exists() const;
    
    private:
        assembly_metadata_pimpl_label_type *Pimpl();
        assembly_metadata_pimpl_label_type const *Pimpl() const;
        void SetFullName(wstring const &fullName);
        void SetName(wstring const &name);
        void SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp);
        void SetAssemblyFilePath(path const &asmPath);
        void SetToken(mdToken mdt);

        module_metadata_label_type const *GetModuleCore(wstring const &name) const;
        void RegisterModule(TempPtr<module_metadata_label_type> &pMod);
        
        type_metadata_label_type const *GetType(wstring const &fullName, TypeProvider const &member) const;
        type_metadata_label_type const *GetType(mdToken mdt, TypeKinds const &kind, ULONG genericParamPos, bool genericArgsSpecified, vector<IType const *> const &genericArgs, TypeProvider const &member) const;
        void RegisterType(TempPtr<type_metadata_label_type> &pType);
        
        method_metadata_label_type const *GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member) const;
        method_metadata_label_type const *GetMethod(mdToken mdt, CallingConventions const &callingConvention, bool genericArgsSpecified, vector<IType const *> const &genericArgs, COR_ILMETHOD *pILBody, MethodProvider const &member) const;
        void RegisterMethod(TempPtr<method_metadata_label_type> &pMethod);
        
        method_body_metadata_label_type *GetMethodBody(COR_ILMETHOD *pILBody, IMethod const *pMethod) const;
        void RegisterMethodBody(TempPtr<method_body_metadata_label_type> &pBody);

        parameter_metadata_label_type const *GetParameter(ULONG position, IType const *pParamType, ParameterProvider const &member) const;
        void RegisterParameter(TempPtr<parameter_metadata_label_type> &pParam);

        local_metadata_label_type const *GetLocal(ULONG index, IType const *pLocalType, IMethodBody const *pBody) const;
        void RegisterLocal(TempPtr<local_metadata_label_type> &pLocal);
        
        property_metadata_label_type const *GetProperty(mdToken mdt, PropertyProvider const &member) const;
        void RegisterProperty(TempPtr<property_metadata_label_type> &pProp);
        
        field_metadata_label_type const *GetField(mdToken mdt, FieldProvider const &member) const;
        void RegisterField(TempPtr<field_metadata_label_type> &pField);
        
        custom_attribute_metadata_label_type const *GetCustomAttribute(mdToken mdt, CustomAttributeProvider const &member) const;
        void RegisterCustomAttribute(TempPtr<custom_attribute_metadata_label_type> &pCas);

        IAssemblyPtrRange GetAssemblyReferences() const;
        IAssembly const *GetAssemblyReference(wstring const &fullName) const;
        IType const *GetTypeReference(IType const *pType) const;
        void FillAssemblyRefs(vector<mdAssemblyRef> &asmRefs) const;
        void FillTypeRefs(vector<mdTypeRef> &typeRefs) const;
        void FillTypeRefs(wstring const &fullName, vector<mdTypeRef> &typeRefs) const;
        void FillTypeDefMethodDefs(mdTypeDef mdtTarget, wstring const &name, vector<mdMethodDef> &methodDefs) const;
        void FillTypeDefProperties(mdToken mdtTarget, wstring &fullName, TypeAttributes &attr, mdToken &mdtExt) const;
        void FillTypeRefProperties(mdToken mdtTarget, wstring &fullName, mdToken &mdtResolutionScope) const;
        void FillMethodDefProperties(mdMethodDef mdtTarget, mdTypeDef &mdtOwner, wstring &name, MethodAttributes &attr, Signature &sig, ULONG &codeRva, MethodImplAttributes &implFlags) const;
        void FillMethodSpecProperties(mdMethodSpec mdtTarget, mdToken &mdtOwner, Signature &sig) const;
        void FillFieldDefProperties(mdFieldDef mdtTarget, mdToken &mdtOwner, wstring &name, FieldAttributes &attr, Signature &sig) const;
        void FillScopeMemberRefs(mdToken mdtTarget, vector<mdMemberRef> &memberRefs) const;
        void FillScopeMemberRefs(mdToken mdtTarget, wstring const &name, vector<mdMemberRef> &memberRefs) const;
        void FillMemberRefProperties(mdMemberRef mdtTarget, mdToken &mdtOwner, wstring &name, Signature &sig) const;
        void FillCustomAttributeProperties(mdCustomAttribute mdtTarget, Signature &sig, mdToken &mdtOwner, mdToken &mdtCtor) const;

        IMetaDataAssemblyImport &GetCOMMetaDataAssemblyImport() const;
        IMetaDataImport2 &GetCOMMetaDataImport() const;
        path const &GetAssemblyFilePath() const;
        DWORD GetOpenFlags() const;
        void SetOpeningAssembly(assembly_metadata_label_type const *pOpeningAsm);
        void SetProcessorArchitectures(vector<ProcessorArchitecture> const &procArchs);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 464;
#else
        static INT const PIMPL_TYPE_SIZE = 872;
#endif
#endif
        typedef typename aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_H

