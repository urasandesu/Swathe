/* 
 * File: BaseAssemblyMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAssemblyMetadata<ApiHolder>::BaseAssemblyMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())assembly_metadata_pimpl_label_type(this);
#ifdef _DEBUG
        m_pPimpl = Pimpl();
#endif
    }

    template<class ApiHolder>    
    BaseAssemblyMetadata<ApiHolder>::~BaseAssemblyMetadata()
    {
        Pimpl()->~assembly_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::assembly_metadata_pimpl_label_type *BaseAssemblyMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<assembly_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::assembly_metadata_pimpl_label_type const *BaseAssemblyMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_METADATA_ADDITIONAL_INSTANTIATION \
    
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::Initialize(metadata_info_label_type *pMetaInfo, metadata_dispenser_label_type *pDisp, portable_executable_info_label_type const *pPEInfo, strong_name_info_label_type const *pSnInfo)
    {
        Pimpl()->Initialize(pMetaInfo, pDisp, pPEInfo, pSnInfo);
    }

    template<class ApiHolder>    
    mdAssembly BaseAssemblyMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }
    
    template<class ApiHolder>    
    wstring const &BaseAssemblyMetadata<ApiHolder>::GetFullName() const
    {
        return Pimpl()->GetFullName();
    }
    
    template<class ApiHolder>    
    path const &BaseAssemblyMetadata<ApiHolder>::GetLocation() const
    {
        return Pimpl()->GetLocation();
    }

    template<class ApiHolder>    
    IModule const *BaseAssemblyMetadata<ApiHolder>::GetMainModule() const
    {
        return Pimpl()->GetMainModule();
    }

    template<class ApiHolder>    
    IModule const *BaseAssemblyMetadata<ApiHolder>::GetModule(wstring const &name) const
    {
        return Pimpl()->GetModule(name);
    }
    
    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> const &BaseAssemblyMetadata<ApiHolder>::GetStrongNameKey() const
    {
        return Pimpl()->GetStrongNameKey();
    }
    
    template<class ApiHolder>    
    wstring const &BaseAssemblyMetadata<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }
    
    template<class ApiHolder>    
    ASSEMBLYMETADATA const &BaseAssemblyMetadata<ApiHolder>::GetAssemblyMetadata() const
    {
        return Pimpl()->GetAssemblyMetadata();
    }
    
    template<class ApiHolder>    
    Version const &BaseAssemblyMetadata<ApiHolder>::GetVersion() const
    {
        return Pimpl()->GetVersion();
    }

    template<class ApiHolder>    
    wstring const &BaseAssemblyMetadata<ApiHolder>::GetCultureName() const
    {
        return Pimpl()->GetCultureName();
    }

    template<class ApiHolder>    
    wstring const &BaseAssemblyMetadata<ApiHolder>::GetImageRuntimeVersion() const
    {
        return Pimpl()->GetImageRuntimeVersion();
    }

    template<class ApiHolder>    
    AssemblyFlags BaseAssemblyMetadata<ApiHolder>::GetFlags() const
    {
        return Pimpl()->GetFlags();
    }
    
    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadata<ApiHolder>::GetSourceAssembly() const
    {
        return Pimpl()->GetSourceAssembly();
    }
    
    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadata<ApiHolder>::GetTargetAssembly() const
    {
        return Pimpl()->GetTargetAssembly();
    }

    template<class ApiHolder>    
    IDispenser const *BaseAssemblyMetadata<ApiHolder>::GetDispenser() const
    {
        return Pimpl()->GetDispenser();
    }
    
    template<class ApiHolder>    
    IField const *BaseAssemblyMetadata<ApiHolder>::GetField(mdToken mdt) const
    {
        return Pimpl()->GetField(mdt);
    }

    template<class ApiHolder>    
    IMethod const *BaseAssemblyMetadata<ApiHolder>::GetMethod(mdToken mdt) const
    {
        return Pimpl()->GetMethod(mdt);
    }

    template<class ApiHolder>    
    IMethod const *BaseAssemblyMetadata<ApiHolder>::GetMethod(mdToken mdt, COR_ILMETHOD *pILBody) const
    {
        return Pimpl()->GetMethod(mdt, pILBody);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyMetadata<ApiHolder>::GetType(mdToken mdt) const
    {
        return Pimpl()->GetType(mdt);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyMetadata<ApiHolder>::GetType(wstring const &fullName) const
    {
        return Pimpl()->GetType(fullName);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyMetadata<ApiHolder>::GetGenericTypeParameter(ULONG genericParamPos) const
    {
        return Pimpl()->GetGenericTypeParameter(genericParamPos);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyMetadata<ApiHolder>::GetGenericMethodParameter(ULONG genericParamPos) const
    {
        return Pimpl()->GetGenericMethodParameter(genericParamPos);
    }

    template<class ApiHolder>    
    vector<ProcessorArchitecture> const &BaseAssemblyMetadata<ApiHolder>::GetProcessorArchitectures() const
    {
        return Pimpl()->GetProcessorArchitectures();
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadata<ApiHolder>::GetAssembly(wstring const &fullName) const
    {
        return Pimpl()->GetAssembly(fullName);
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadata<ApiHolder>::GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        return Pimpl()->GetAssembly(fullName, procArchs);
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadata<ApiHolder>::GetAssemblyReference(mdAssemblyRef mdt) const
    {
        return Pimpl()->GetAssemblyReference(mdt);
    }

    template<class ApiHolder>    
    ICustomAttribute const *BaseAssemblyMetadata<ApiHolder>::GetCustomAttribute(mdToken mdt) const
    {
        return Pimpl()->GetCustomAttribute(mdt);
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseAssemblyMetadata<ApiHolder>::GetCustomAttributes() const
    {
        return Pimpl()->GetCustomAttributes();
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseAssemblyMetadata<ApiHolder>::GetCustomAttributes(IType const *pAttributeType) const
    {
        return Pimpl()->GetCustomAttributes(pAttributeType);
    }

    template<class ApiHolder>    
    ITypePtrRange BaseAssemblyMetadata<ApiHolder>::GetTypes() const
    {
        return Pimpl()->GetTypes();
    }

    template<class ApiHolder>    
    IMetaDataAssemblyImport &BaseAssemblyMetadata<ApiHolder>::GetCOMMetaDataAssemblyImport() const
    {
        return Pimpl()->GetCOMMetaDataAssemblyImport();
    }

    template<class ApiHolder>    
    IMetaDataImport2 &BaseAssemblyMetadata<ApiHolder>::GetCOMMetaDataImport() const
    {
        return Pimpl()->GetCOMMetaDataImport();
    }

    template<class ApiHolder>    
    IMetaDataAssemblyEmit &BaseAssemblyMetadata<ApiHolder>::GetCOMMetaDataAssemblyEmit()
    {
        return Pimpl()->GetCOMMetaDataAssemblyEmit();
    }

    template<class ApiHolder>    
    IMetaDataEmit2 &BaseAssemblyMetadata<ApiHolder>::GetCOMMetaDataEmit()
    {
        return Pimpl()->GetCOMMetaDataEmit();
    }

    template<class ApiHolder>    
    bool BaseAssemblyMetadata<ApiHolder>::Equals(IAssembly const *pAsm) const
    {
        return Pimpl()->Equals(pAsm);
    }

    template<class ApiHolder>    
    size_t BaseAssemblyMetadata<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    template<class ApiHolder>    
    AutoPtr<IPortableExecutableReader const> const &BaseAssemblyMetadata<ApiHolder>::GetPortableExecutableReader() const
    {
        return Pimpl()->GetPortableExecutableReader();
    }

    template<class ApiHolder>    
    bool BaseAssemblyMetadata<ApiHolder>::Exists() const
    {
        return Pimpl()->Exists();
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::SetFullName(wstring const &fullName)
    {
        Pimpl()->SetFullName(fullName);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp)
    {
        Pimpl()->SetCOMMetaDataImport(pComMetaImp);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::SetAssemblyFilePath(path const &asmPath)
    {
        Pimpl()->SetAssemblyFilePath(asmPath);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::SetToken(mdToken mdt)
    {
        Pimpl()->SetToken(mdt);
    }

    template<class ApiHolder>    
    bool BaseAssemblyMetadata<ApiHolder>::IsModifiable() const
    {
        return Pimpl()->IsModifiable();
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::module_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetModuleCore(wstring const &name) const
    {
        return Pimpl()->GetModuleCore(name);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterModule(TempPtr<module_metadata_label_type> &pMod)
    {
        Pimpl()->RegisterModule(pMod);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::type_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetType(wstring const &fullName, TypeProvider const &member) const
    {
        return Pimpl()->GetType(fullName, member);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::type_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetType(mdToken mdt, TypeKinds const &kind, bool arrDimsSpecified, vector<ArrayDimension> const &arrDims, ULONG genericParamPos, bool genericArgsSpecified, vector<IType const *> const &genericArgs, TypeProvider const &member) const
    {
        return Pimpl()->GetType(mdt, kind, arrDimsSpecified, arrDims, genericParamPos, genericArgsSpecified, genericArgs, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterType(TempPtr<type_metadata_label_type> &pType)
    {
        Pimpl()->RegisterType(pType);
    }
    
    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::method_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member) const
    {
        return Pimpl()->GetMethod(name, callingConvention, pRetType, paramsSpecified, params, member);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::method_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetMethod(mdToken mdt, CallingConventions const &callingConvention, bool genericArgsSpecified, vector<IType const *> const &genericArgs, COR_ILMETHOD *pILBody, MethodProvider const &member) const
    {
        return Pimpl()->GetMethod(mdt, callingConvention, genericArgsSpecified, genericArgs, pILBody, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterMethod(TempPtr<method_metadata_label_type> &pMethod)
    {
        Pimpl()->RegisterMethod(pMethod);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::method_body_metadata_label_type *BaseAssemblyMetadata<ApiHolder>::GetMethodBody(COR_ILMETHOD *pILBody, IMethod const *pMethod) const
    {
        return Pimpl()->GetMethodBody(pILBody, pMethod);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterMethodBody(TempPtr<method_body_metadata_label_type> &pBody)
    {
        Pimpl()->RegisterMethodBody(pBody);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::parameter_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetParameter(ULONG position, IType const *pParamType, ParameterProvider const &member) const
    {
        return Pimpl()->GetParameter(position, pParamType, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterParameter(TempPtr<parameter_metadata_label_type> &pParam)
    {
        Pimpl()->RegisterParameter(pParam);
    }
    
    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::local_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetLocal(ULONG index, IType const *pLocalType, IMethodBody const *pBody) const
    {
        return Pimpl()->GetLocal(index, pLocalType, pBody);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterLocal(TempPtr<local_metadata_label_type> &pLocal)
    {
        Pimpl()->RegisterLocal(pLocal);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::property_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetProperty(mdToken mdt, PropertyProvider const &member) const
    {
        return Pimpl()->GetProperty(mdt, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterProperty(TempPtr<property_metadata_label_type> &pProp)
    {
        Pimpl()->RegisterProperty(pProp);
    }
    
    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::field_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetField(mdToken mdt, FieldProvider const &member) const
    {
        return Pimpl()->GetField(mdt, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterField(TempPtr<field_metadata_label_type> &pField)
    {
        return Pimpl()->RegisterField(pField);
    }

    template<class ApiHolder>    
    typename BaseAssemblyMetadata<ApiHolder>::custom_attribute_metadata_label_type const *BaseAssemblyMetadata<ApiHolder>::GetCustomAttribute(mdToken mdt, CustomAttributeProvider const &member) const
    {
        return Pimpl()->GetCustomAttribute(mdt, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::RegisterCustomAttribute(TempPtr<custom_attribute_metadata_label_type> &pCas)
    {
        Pimpl()->RegisterCustomAttribute(pCas);
    }

    template<class ApiHolder>    
    IAssemblyPtrRange BaseAssemblyMetadata<ApiHolder>::GetAssemblyReferences() const
    {
        return Pimpl()->GetAssemblyReferences();
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadata<ApiHolder>::GetAssemblyReference(wstring const &fullName) const
    {
        return Pimpl()->GetAssemblyReference(fullName);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyMetadata<ApiHolder>::GetTypeReference(IType const *pType) const
    {
        return Pimpl()->GetTypeReference(pType);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillAssemblyRefs(vector<mdAssemblyRef> &asmRefs) const
    {
        Pimpl()->FillAssemblyRefs(asmRefs);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillTypeRefs(vector<mdTypeRef> &typeRefs) const
    {
        Pimpl()->FillTypeRefs(typeRefs);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillTypeRefs(wstring const &fullName, vector<mdTypeRef> &typeRefs) const
    {
        Pimpl()->FillTypeRefs(fullName, typeRefs);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillTypeDefMethodDefs(mdTypeDef mdtTarget, wstring const &name, vector<mdMethodDef> &methodDefs) const
    {
        Pimpl()->FillTypeDefMethodDefs(mdtTarget, name, methodDefs);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillTypeDefProperties(mdToken mdtTarget, wstring &fullName, TypeAttributes &attr, mdToken &mdtExt) const
    {
        Pimpl()->FillTypeDefProperties(mdtTarget, fullName, attr, mdtExt);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillTypeRefProperties(mdToken mdtTarget, wstring &fullName, mdToken &mdtResolutionScope) const
    {
        Pimpl()->FillTypeRefProperties(mdtTarget, fullName, mdtResolutionScope);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillMethodDefProperties(mdMethodDef mdtTarget, mdTypeDef &mdtOwner, wstring &name, MethodAttributes &attr, Signature &sig, ULONG &codeRva, MethodImplAttributes &implFlags) const
    {
        Pimpl()->FillMethodDefProperties(mdtTarget, mdtOwner, name, attr, sig, codeRva, implFlags);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillMethodSpecProperties(mdMethodSpec mdtTarget, mdToken &mdtOwner, Signature &sig) const
    {
        Pimpl()->FillMethodSpecProperties(mdtTarget, mdtOwner, sig);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillFieldDefProperties(mdFieldDef mdtTarget, mdToken &mdtOwner, wstring &name, FieldAttributes &attr, Signature &sig) const
    {
        Pimpl()->FillFieldDefProperties(mdtTarget, mdtOwner, name, attr, sig);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillScopeMemberRefs(mdToken mdtTarget, vector<mdMemberRef> &memberRefs) const
    {
        Pimpl()->FillScopeMemberRefs(mdtTarget, memberRefs);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillScopeMemberRefs(mdToken mdtTarget, wstring const &name, vector<mdMemberRef> &memberRefs) const
    {
        Pimpl()->FillScopeMemberRefs(mdtTarget, name, memberRefs);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillMemberRefProperties(mdMemberRef mdtTarget, mdToken &mdtOwner, wstring &name, Signature &sig) const
    {
        Pimpl()->FillMemberRefProperties(mdtTarget, mdtOwner, name, sig);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::FillCustomAttributeProperties(mdCustomAttribute mdtTarget, Signature &sig, mdToken &mdtOwner, mdToken &mdtCtor) const
    {
        Pimpl()->FillCustomAttributeProperties(mdtTarget, sig, mdtOwner, mdtCtor);
    }

    template<class ApiHolder>    
    DWORD BaseAssemblyMetadata<ApiHolder>::GetOpenFlags() const
    {
        return Pimpl()->GetOpenFlags();
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::SetOpeningAssembly(assembly_metadata_label_type const *pOpeningAsm)
    {
        Pimpl()->SetOpeningAssembly(pOpeningAsm);
    }

    template<class ApiHolder>    
    void BaseAssemblyMetadata<ApiHolder>::SetProcessorArchitectures(vector<ProcessorArchitecture> const &procArchs)
    {
        Pimpl()->SetProcessorArchitectures(procArchs);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_HPP

