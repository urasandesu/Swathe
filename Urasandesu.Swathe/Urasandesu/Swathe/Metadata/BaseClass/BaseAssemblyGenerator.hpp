/* 
 * File: BaseAssemblyGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAssemblyGenerator<ApiHolder>::BaseAssemblyGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())assembly_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseAssemblyGenerator<ApiHolder>::~BaseAssemblyGenerator()
    {
        Pimpl()->~assembly_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::assembly_generator_pimpl_label_type *BaseAssemblyGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<assembly_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::assembly_generator_pimpl_label_type const *BaseAssemblyGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::Initialize(metadata_info_label_type *pMetaInfo, metadata_dispenser_label_type *pDisp, portable_executable_info_label_type const *pPEInfo)
    {
        Pimpl()->Initialize(pMetaInfo, pDisp, pPEInfo);
    }

    template<class ApiHolder>    
    mdAssembly BaseAssemblyGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BaseAssemblyGenerator<ApiHolder>::GetFullName() const
    {
        return Pimpl()->GetFullName();
    }

    template<class ApiHolder>    
    path const &BaseAssemblyGenerator<ApiHolder>::GetLocation() const
    {
        return Pimpl()->GetLocation();
    }

    template<class ApiHolder>    
    IModule const *BaseAssemblyGenerator<ApiHolder>::GetMainModule() const
    {
        return Pimpl()->GetMainModule();
    }

    template<class ApiHolder>    
    IModule const *BaseAssemblyGenerator<ApiHolder>::GetModule(wstring const &name) const
    {
        return Pimpl()->GetModule(name);
    }

    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> const &BaseAssemblyGenerator<ApiHolder>::GetStrongNameKey() const
    {
        return Pimpl()->GetStrongNameKey();
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::SetStrongNameKey(AutoPtr<IStrongNameKey const> const &pSnKey)
    {
        Pimpl()->SetStrongNameKey(pSnKey);
    }

    template<class ApiHolder>    
    wstring const &BaseAssemblyGenerator<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    ASSEMBLYMETADATA const &BaseAssemblyGenerator<ApiHolder>::GetAssemblyMetadata() const
    {
        return Pimpl()->GetAssemblyMetadata();
    }

    template<class ApiHolder>    
    Version const &BaseAssemblyGenerator<ApiHolder>::GetVersion() const
    {
        return Pimpl()->GetVersion();
    }

    template<class ApiHolder>    
    wstring const &BaseAssemblyGenerator<ApiHolder>::GetCultureName() const
    {
        return Pimpl()->GetCultureName();
    }

    template<class ApiHolder>    
    wstring const &BaseAssemblyGenerator<ApiHolder>::GetImageRuntimeVersion() const
    {
        return Pimpl()->GetImageRuntimeVersion();
    }

    template<class ApiHolder>    
    AssemblyFlags BaseAssemblyGenerator<ApiHolder>::GetFlags() const
    {
        return Pimpl()->GetFlags();
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGenerator<ApiHolder>::GetSourceAssembly() const
    {
        return Pimpl()->GetSourceAssembly();
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGenerator<ApiHolder>::GetTargetAssembly() const
    {
        return Pimpl()->GetTargetAssembly();
    }

    template<class ApiHolder>    
    IDispenser const *BaseAssemblyGenerator<ApiHolder>::GetDispenser() const
    {
        return Pimpl()->GetDispenser();
    }

    template<class ApiHolder>    
    IField const *BaseAssemblyGenerator<ApiHolder>::GetField(mdToken mdt) const
    {
        return Pimpl()->GetField(mdt);
    }

    template<class ApiHolder>    
    IMethod const *BaseAssemblyGenerator<ApiHolder>::GetMethod(mdToken mdt) const
    {
        return Pimpl()->GetMethod(mdt);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::method_generator_label_type *BaseAssemblyGenerator<ApiHolder>::GetMethodGenerator(mdToken mdt)
    {
        return Pimpl()->GetMethodGenerator(mdt);
    }

    template<class ApiHolder>    
    IMethod const *BaseAssemblyGenerator<ApiHolder>::GetMethod(mdToken mdt, COR_ILMETHOD *pILBody) const
    {
        return Pimpl()->GetMethod(mdt, pILBody);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyGenerator<ApiHolder>::GetType(mdToken mdt) const
    {
        return Pimpl()->GetType(mdt);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyGenerator<ApiHolder>::GetType(wstring const &fullName) const
    {
        return Pimpl()->GetType(fullName);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyGenerator<ApiHolder>::GetGenericTypeParameter(ULONG genericParamPos) const
    {
        return Pimpl()->GetGenericTypeParameter(genericParamPos);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyGenerator<ApiHolder>::GetGenericMethodParameter(ULONG genericParamPos) const
    {
        return Pimpl()->GetGenericMethodParameter(genericParamPos);
    }

    template<class ApiHolder>    
    vector<ProcessorArchitecture> const &BaseAssemblyGenerator<ApiHolder>::GetProcessorArchitectures() const
    {
        return Pimpl()->GetProcessorArchitectures();
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGenerator<ApiHolder>::GetAssembly(wstring const &fullName) const
    {
        return Pimpl()->GetAssembly(fullName);
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGenerator<ApiHolder>::GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        return Pimpl()->GetAssembly(fullName, procArchs);
    }

    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGenerator<ApiHolder>::GetAssemblyReference(mdAssemblyRef mdt) const
    {
        return Pimpl()->GetAssemblyReference(mdt);
    }

    template<class ApiHolder>    
    ITypePtrRange BaseAssemblyGenerator<ApiHolder>::GetTypes() const
    {
        return Pimpl()->GetTypes();
    }

    template<class ApiHolder>    
    bool BaseAssemblyGenerator<ApiHolder>::Equals(IAssembly const *pAsm) const
    {
        return Pimpl()->Equals(pAsm);
    }

    template<class ApiHolder>    
    size_t BaseAssemblyGenerator<ApiHolder>::GetHashCode() const
    {
        return Pimpl()->GetHashCode();
    }

    template<class ApiHolder>    
    AutoPtr<IPortableExecutableReader const> const &BaseAssemblyGenerator<ApiHolder>::GetPortableExecutableReader() const
    {
        return Pimpl()->GetPortableExecutableReader();
    }

    template<class ApiHolder>    
    vector<IAssembly const *> const &BaseAssemblyGenerator<ApiHolder>::GetReferencedAssemblies() const
    {
        return Pimpl()->GetReferencedAssemblies();
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::module_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineModule(wstring const &name)
    {
        return Pimpl()->DefineModule(name);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::Save(PortableExecutableKinds const &portableExecutableKind, ImageFileMachine const &imageFileMachine)
    {
        Pimpl()->Save(portableExecutableKind, imageFileMachine);
    }

    template<class ApiHolder>    
    ICustomAttribute const *BaseAssemblyGenerator<ApiHolder>::GetCustomAttribute(mdToken mdt) const
    {
        return Pimpl()->GetCustomAttribute(mdt);
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseAssemblyGenerator<ApiHolder>::GetCustomAttributes() const
    {
        return Pimpl()->GetCustomAttributes();
    }

    template<class ApiHolder>    
    ICustomAttributePtrRange BaseAssemblyGenerator<ApiHolder>::GetCustomAttributes(IType const *pAttributeType) const
    {
        return Pimpl()->GetCustomAttributes(pAttributeType);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::custom_attribute_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineCustomAttribute(IMethod const *pCtor, vector<CustomAttributeArgument> const &constructorArgs)
    {
        return Pimpl()->DefineCustomAttribute(pCtor, constructorArgs);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::custom_attribute_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineCustomAttribute(IMethod const *pCtor, vector<CustomAttributeArgument> const &constructorArgs, vector<IProperty const *> const &namedProperties, vector<CustomAttributeArgument> const &propertyValues)
    {
        return Pimpl()->DefineCustomAttribute(pCtor, constructorArgs, namedProperties, propertyValues);
    }
    
    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::method_generator_label_type *BaseAssemblyGenerator<ApiHolder>::GetModifiableMethod(mdToken mdt, COR_ILMETHOD *pILBody) const
    {
        return Pimpl()->GetModifiableMethod(mdt, pILBody);
    }

    template<class ApiHolder>    
    IModule const *BaseAssemblyGenerator<ApiHolder>::Resolve(IModule const *pMod) const
    {
        return Pimpl()->Resolve(pMod);
    }

    template<class ApiHolder>    
    IType const *BaseAssemblyGenerator<ApiHolder>::Resolve(IType const *pType) const
    {
        return Pimpl()->Resolve(pType);
    }

    template<class ApiHolder>    
    IField const *BaseAssemblyGenerator<ApiHolder>::Resolve(IField const *pField) const
    {
        return Pimpl()->Resolve(pField);
    }

    template<class ApiHolder>    
    IProperty const *BaseAssemblyGenerator<ApiHolder>::Resolve(IProperty const *pProp) const
    {
        return Pimpl()->Resolve(pProp);
    }

    template<class ApiHolder>    
    IMethod const *BaseAssemblyGenerator<ApiHolder>::Resolve(IMethod const *pMethod) const
    {
        return Pimpl()->Resolve(pMethod);
    }

    template<class ApiHolder>    
    IMethodBody const *BaseAssemblyGenerator<ApiHolder>::Resolve(IMethodBody const *pBody) const
    {
        return Pimpl()->Resolve(pBody);
    }

    template<class ApiHolder>    
    IParameter const *BaseAssemblyGenerator<ApiHolder>::Resolve(IParameter const *pParam) const
    {
        return Pimpl()->Resolve(pParam);
    }

    template<class ApiHolder>    
    ILocal const *BaseAssemblyGenerator<ApiHolder>::Resolve(ILocal const *pLocal) const
    {
        return Pimpl()->Resolve(pLocal);
    }

    template<class ApiHolder>    
    ICustomAttribute const *BaseAssemblyGenerator<ApiHolder>::Resolve(ICustomAttribute const *pCa) const
    {
        return Pimpl()->Resolve(pCa);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::SetFullName(wstring const &fullName)
    {
        Pimpl()->SetFullName(fullName);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::SetCOMMetaDataEmit(IMetaDataEmit2 *pComMetaEmt)
    {
        Pimpl()->SetCOMMetaDataEmit(pComMetaEmt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::SetSourceAssembly(IAssembly const *pSrcAsm)
    {
        Pimpl()->SetSourceAssembly(pSrcAsm);
    }

    template<class ApiHolder>    
    bool BaseAssemblyGenerator<ApiHolder>::IsModifiable() const
    {
        return Pimpl()->IsModifiable();
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::module_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineModule(IModule const *pSrcMod)
    {
        return Pimpl()->DefineModule(pSrcMod);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterModuleGenerator(TempPtr<module_generator_label_type> &pModGen)
    {
        Pimpl()->RegisterModuleGenerator(pModGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::type_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineType(wstring const &fullName, TypeAttributes const &attr, GenericParamAttributes const &gpAttr, ULONG genericParamPos, TypeProvider const &member)
    {
        return Pimpl()->DefineType(fullName, attr, gpAttr, genericParamPos, member);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::type_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineType(IType const *pSrcType, TypeProvider const &member)
    {
        return Pimpl()->DefineType(pSrcType, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterTypeGenerator(TempPtr<type_generator_label_type> &pTypeGen)
    {
        return Pimpl()->RegisterTypeGenerator(pTypeGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::method_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineMethod(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member)
    {
        return Pimpl()->DefineMethod(name, attr, callingConvention, pRetType, paramsSpecified, params, member);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::method_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineMethod(mdToken mdt, CallingConventions const &callingConvention, bool genericArgsSpecified, vector<IType const *> const &genericArgs, COR_ILMETHOD *pILBody, IMethod const *pSrcMethod, MethodProvider const &member)
    {
        return Pimpl()->DefineMethod(mdt, callingConvention, genericArgsSpecified, genericArgs, pILBody, pSrcMethod, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterMethodGenerator(TempPtr<method_generator_label_type> &pMethodGen)
    {
        return Pimpl()->RegisterMethodGenerator(pMethodGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::property_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineProperty(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, bool paramsSpecified, vector<IParameter const *> const &params, PropertyProvider const &member)
    {
        return Pimpl()->DefineProperty(name, attr, pPropType, paramsSpecified, params, member);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::property_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineProperty(IProperty const *pSrcProp, PropertyProvider const &member)
    {
        return Pimpl()->DefineProperty(pSrcProp, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterPropertyGenerator(TempPtr<property_generator_label_type> &pPropGen)
    {
        Pimpl()->RegisterPropertyGenerator(pPropGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::field_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineField(wstring const &name, IType const *pFieldType, FieldAttributes const &attr, FieldProvider const &member)
    {
        return Pimpl()->DefineField(name, pFieldType, attr, member);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::field_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineField(IField const *pSrcField, FieldProvider const &member)
    {
        return Pimpl()->DefineField(pSrcField, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterFieldGenerator(TempPtr<field_generator_label_type> &pFieldGen)
    {
        Pimpl()->RegisterFieldGenerator(pFieldGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::method_body_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineMethodBody(IMethodBody const *pSrcBody, IMethod const *pMethod)
    {
        return Pimpl()->DefineMethodBody(pSrcBody, pMethod);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterMethodBodyGenerator(TempPtr<method_body_generator_label_type> &pBodyGen)
    {
        Pimpl()->RegisterMethodBodyGenerator(pBodyGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::parameter_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineParameter(ULONG position, IType const *pParamType, ParameterProvider const &member)
    {
        return Pimpl()->DefineParameter(position, pParamType, member);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::parameter_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineParameter(IParameter const *pSrcParam, ParameterProvider const &member)
    {
        return Pimpl()->DefineParameter(pSrcParam, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterParameterGenerator(TempPtr<parameter_generator_label_type> &pParamGen)
    {
        Pimpl()->RegisterParameterGenerator(pParamGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::local_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineLocal(SIZE_T index, IType const *pLocalType, IMethodBody const *pBody)
    {
        return Pimpl()->DefineLocal(index, pLocalType, pBody);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterLocalGenerator(TempPtr<local_generator_label_type> &pLocalGen)
    {
        Pimpl()->RegisterLocalGenerator(pLocalGen);
    }

    template<class ApiHolder>    
    typename BaseAssemblyGenerator<ApiHolder>::custom_attribute_generator_label_type *BaseAssemblyGenerator<ApiHolder>::DefineCustomAttribute(IMethod const *pCtor, bool constructorArgsSpecified, vector<CustomAttributeArgument> const &constructorArgs, bool namedPropertiesSpecified, vector<IProperty const *> const &namedProperties, bool propertyValuesSpecified, vector<CustomAttributeArgument> const &propertyValues, CustomAttributeProvider const &member)
    {
        return Pimpl()->DefineCustomAttribute(pCtor, constructorArgsSpecified, constructorArgs, namedPropertiesSpecified, namedProperties, propertyValuesSpecified, propertyValues, member);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::RegisterCustomAttributeGenerator(TempPtr<custom_attribute_generator_label_type> &pCaGen)
    {
        return Pimpl()->RegisterCustomAttributeGenerator(pCaGen);
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::module_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetModuleGeneratorToIndex() const
    {
        return Pimpl()->GetModuleGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::type_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetTypeGeneratorToIndex() const
    {
        return Pimpl()->GetTypeGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::field_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetFieldGeneratorToIndex() const
    {
        return Pimpl()->GetFieldGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::method_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetMethodGeneratorToIndex() const
    {
        return Pimpl()->GetMethodGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::method_body_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetMethodBodyGeneratorToIndex() const
    {
        return Pimpl()->GetMethodBodyGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::local_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetLocalGeneratorToIndex() const
    {
        return Pimpl()->GetLocalGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::parameter_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetParameterGeneratorToIndex() const
    {
        return Pimpl()->GetParameterGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::property_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetPropertyGeneratorToIndex() const
    {
        return Pimpl()->GetPropertyGeneratorToIndex();
    }

    template<class ApiHolder>    
    vector<typename BaseAssemblyGenerator<ApiHolder>::custom_attribute_generator_label_type *> const &BaseAssemblyGenerator<ApiHolder>::GetCustomAttributeGeneratorToIndex() const
    {
        return Pimpl()->GetCustomAttributeGeneratorToIndex();
    }
    
    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateTypeDef(wstring const &fullName, TypeAttributes const &attr, IType const *pBaseType, vector<IType const *> const &interfaces, mdTypeDef &mdt)
    {
        Pimpl()->UpdateTypeDef(fullName, attr, pBaseType, interfaces, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateTypeDef(wstring const &fullName, TypeAttributes const &attr, mdToken mdExtends, mdToken mdNilTerminatedImplements[], mdTypeDef &mdt)
    {
        Pimpl()->UpdateTypeDef(fullName, attr, mdExtends, mdNilTerminatedImplements, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateNestedType(wstring const &fullName, TypeAttributes const &attr, IType const *pBaseType, vector<IType const *> const &interfaces, IType const *pDeclaringType, mdTypeDef &mdt)
    {
        Pimpl()->UpdateNestedType(fullName, attr, pBaseType, interfaces, pDeclaringType, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateNestedType(wstring const &fullName, TypeAttributes const &attr, mdToken mdExtends, mdToken mdNilTerminatedImplements[], mdTypeDef mdEncloser, mdTypeDef &mdt)
    {
        Pimpl()->UpdateNestedType(fullName, attr, mdExtends, mdNilTerminatedImplements, mdEncloser, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateTypeSpec(Signature const &sig, mdTypeSpec &mdt)
    {
        Pimpl()->UpdateTypeSpec(sig, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateTypeRef(mdToken mdResolutionScope, wstring const &fullName, mdTypeRef &mdt)
    {
        Pimpl()->UpdateTypeRef(mdResolutionScope, fullName, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateGenericParam(IType const *pDeclaringType, IMethod const *pDeclaringMethod, ULONG genericParamPos, GenericParamAttributes const &gpAttr, wstring const &name, vector<IType const *> const &genericParamConstraints, mdGenericParam &mdt)
    {
        Pimpl()->UpdateGenericParam(pDeclaringType, pDeclaringMethod, genericParamPos, gpAttr, name, genericParamConstraints, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateGenericParam(mdToken mdtOwner, ULONG genericParamPos, GenericParamAttributes const &gpAttr, wstring const &name, mdToken mdNilTerminatedConstraints[], mdGenericParam &mdt)
    {
        Pimpl()->UpdateGenericParam(mdtOwner, genericParamPos, gpAttr, name, mdNilTerminatedConstraints, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateMethodDef(mdTypeDef mdtOwner, wstring const &name, MethodAttributes const &attr, Signature const &sig, ULONG codeRva, MethodImplAttributes const &implFlags, mdMethodDef &mdt)
    {
        Pimpl()->UpdateMethodDef(mdtOwner, name, attr, sig, codeRva, implFlags, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateMethodSpec(mdToken mdtOwner, Signature const &sig, mdMethodSpec &mdt)
    {
        Pimpl()->UpdateMethodSpec(mdtOwner, sig, mdt);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::UpdateMemberRef(mdTypeDef mdtOwner, wstring const &name, Signature const &sig, mdMemberRef &mdt)
    {
        Pimpl()->UpdateMemberRef(mdtOwner, name, sig, mdt);
    }

    template<class ApiHolder>    
    ULONG BaseAssemblyGenerator<ApiHolder>::GetValidRVA() const
    {
        return Pimpl()->GetValidRVA();
    }

    template<class ApiHolder>    
    IMetaDataAssemblyEmit &BaseAssemblyGenerator<ApiHolder>::GetCOMMetaDataAssemblyEmit()
    {
        return Pimpl()->GetCOMMetaDataAssemblyEmit();
    }

    template<class ApiHolder>    
    IMetaDataEmit2 &BaseAssemblyGenerator<ApiHolder>::GetCOMMetaDataEmit()
    {
        return Pimpl()->GetCOMMetaDataEmit();
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::AddReferencedAssembly(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->AddReferencedAssembly(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseAssemblyGenerator<ApiHolder>::SetSavingAssembly(assembly_generator_label_type *pSavingAsmGen)
    {
        Pimpl()->SetSavingAssembly(pSavingAsmGen);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_HPP

