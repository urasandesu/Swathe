/* 
 * File: BaseAssemblyGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_ASSEMBLYGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/AssemblyGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_ISTRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/IStrongNameKey.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_IPORTABLEEXECUTABLEREADER_H
#include <Urasandesu/Swathe/Hosting/IPortableExecutableReader.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PORTABLEEXECUTABLEKINDS_HPP
#include <Urasandesu/Swathe/Metadata/PortableExecutableKinds.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMAGEFILEMACHINE_HPP
#include <Urasandesu/Swathe/Metadata/ImageFileMachine.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALFWD_H
#include <Urasandesu/Swathe/Metadata/ILocalFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using boost::any_range;
    using boost::noncopyable;
    using boost::forward_traversal_tag;
    using boost::iterator_range;
    using std::pair;
    using std::ptrdiff_t;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using Urasandesu::CppAnonym::Version;
    using Urasandesu::Swathe::StrongNaming::IStrongNameKey;
    using Urasandesu::Swathe::Hosting::IPortableExecutableReader;

    template<
        class ApiHolder
    >    
    class BaseAssemblyGenerator : 
        public IAssembly
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseAssemblyGenerator();
        ~BaseAssemblyGenerator();

        void Initialize(metadata_info_label_type *pMetaInfo, metadata_dispenser_label_type *pDisp, portable_executable_info_label_type const *pPEInfo);
        mdAssembly GetToken() const;
        wstring const &GetFullName() const;
        IModule const *GetMainModule() const;
        IModule const *GetModule(wstring const &name) const;
        AutoPtr<IStrongNameKey const> const &GetStrongNameKey() const;
        void SetStrongNameKey(AutoPtr<IStrongNameKey const> const &pSnKey);
        wstring const &GetName() const;
        ASSEMBLYMETADATA const &GetAssemblyMetadata() const;
        Version const &GetVersion() const;
        wstring const &GetCultureName() const;
        wstring const &GetImageRuntimeVersion() const;
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
        bool Equals(IAssembly const *pAsm) const;
        size_t GetHashCode() const;
        AutoPtr<IPortableExecutableReader const> const &GetPortableExecutableReader() const;
        vector<IAssembly const *> const &GetReferencedAssemblies() const;
        module_generator_label_type *DefineModule(wstring const &name);
        void Save(PortableExecutableKinds const &portableExecutableKind, ImageFileMachine const &imageFileMachine);        
        custom_attribute_generator_label_type *DefineCustomAttribute(IMethod const *pCtor, vector<CustomAttributeArgument> const &constructorArgs);
        custom_attribute_generator_label_type *DefineCustomAttribute(IMethod const *pCtor, vector<CustomAttributeArgument> const &constructorArgs, vector<IProperty const *> const &namedProperties, vector<CustomAttributeArgument> const &propertyValues);
        method_generator_label_type *GetModifiableMethod(mdToken mdt, COR_ILMETHOD *pILBody) const;
    
    private:
        assembly_generator_pimpl_label_type *Pimpl();
        assembly_generator_pimpl_label_type const *Pimpl() const;

        class assembly_saving_prepared : 
            noncopyable
        {
        public: 
            assembly_saving_prepared(assembly_generator_label_type *_this);
            ~assembly_saving_prepared();
            
        private:
            assembly_generator_pimpl_label_type *m_pimpl;
        };

        void SetFullName(wstring const &fullName);
        void SetName(wstring const &name);
        void SetSourceAssembly(IAssembly const *pSrcAsm);
        void SetCOMMetaDataEmit(IMetaDataEmit2 *pComMetaEmt);
        bool IsModifiable() const;
        void Accept(IMetadataVisitor *pVisitor) const;

        
        module_generator_label_type *DefineModule(IModule const *pSrcMod);
        void RegisterModuleGenerator(TempPtr<module_generator_label_type> &pModGen);
        
        type_generator_label_type *DefineType(wstring const &fullName, TypeAttributes const &attr, TypeProvider const &member);
        type_generator_label_type *DefineType(IType const *pSrcType, TypeProvider const &member);
        void RegisterTypeGenerator(TempPtr<type_generator_label_type> &pTypeGen);
        
        method_generator_label_type *DefineMethod(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member);
        method_generator_label_type *DefineMethod(IMethod const *pSrcMethod, MethodProvider const &member);
        void RegisterMethodGenerator(TempPtr<method_generator_label_type> &pMethodGen);
        
        property_generator_label_type *DefineProperty(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, bool paramsSpecified, vector<IParameter const *> const &params, PropertyProvider const &member);
        property_generator_label_type *DefineProperty(IProperty const *pSrcProp, PropertyProvider const &member);
        void RegisterPropertyGenerator(TempPtr<property_generator_label_type> &pPropGen);
        
        field_generator_label_type *DefineField(wstring const &name, IType const *pFieldType, FieldAttributes const &attr, FieldProvider const &member);
        field_generator_label_type *DefineField(IField const *pSrcField, FieldProvider const &member);
        void RegisterFieldGenerator(TempPtr<field_generator_label_type> &pFieldGen);
        
        method_body_generator_label_type *DefineMethodBody(IMethodBody const *pSrcBody, IMethod const *pMethod);
        void RegisterMethodBodyGenerator(TempPtr<method_body_generator_label_type> &pBodyGen);
        
        parameter_generator_label_type *DefineParameter(ULONG position, IType const *pParamType, ParameterProvider const &member);
        parameter_generator_label_type *DefineParameter(IParameter const *pSrcParam, ParameterProvider const &member);
        void RegisterParameterGenerator(TempPtr<parameter_generator_label_type> &pParamGen);
        
        local_generator_label_type *DefineLocal(SIZE_T index, IType const *pLocalType, IMethodBody const *pBody);
        void RegisterLocalGenerator(TempPtr<local_generator_label_type> &pLocalGen);
        
        custom_attribute_generator_label_type *DefineCustomAttribute(IMethod const *pCtor, bool constructorArgsSpecified, vector<CustomAttributeArgument> const &constructorArgs, bool namedPropertiesSpecified, vector<IProperty const *> const &namedProperties, bool propertyValuesSpecified, vector<CustomAttributeArgument> const &propertyValues, CustomAttributeProvider const &member);
        void RegisterCustomAttributeGenerator(TempPtr<custom_attribute_generator_label_type> &pCaGen);
        
        vector<module_generator_label_type *> const &GetModuleGeneratorToIndex() const;
        vector<type_generator_label_type *> const &GetTypeGeneratorToIndex() const;
        vector<field_generator_label_type *> const &GetFieldGeneratorToIndex() const;
        vector<method_generator_label_type *> const &GetMethodGeneratorToIndex() const;
        vector<method_body_generator_label_type *> const &GetMethodBodyGeneratorToIndex() const;
        vector<local_generator_label_type *> const &GetLocalGeneratorToIndex() const;
        vector<parameter_generator_label_type *> const &GetParameterGeneratorToIndex() const;
        vector<property_generator_label_type *> const &GetPropertyGeneratorToIndex() const;
        vector<custom_attribute_generator_label_type *> const &GetCustomAttributeGeneratorToIndex() const;

        IModule const *Resolve(IModule const *pMod) const;
        IType const *Resolve(IType const *pType) const;
        IField const *Resolve(IField const *pField) const;
        IProperty const *Resolve(IProperty const *pProp) const;
        IMethod const *Resolve(IMethod const *pMethod) const;
        IMethodBody const *Resolve(IMethodBody const *pBody) const;
        IParameter const *Resolve(IParameter const *pParam) const;
        ILocal const *Resolve(ILocal const *pLocal) const;
        ICustomAttribute const *Resolve(ICustomAttribute const *pCa) const;

        IMetaDataAssemblyEmit &GetCOMMetaDataAssemblyEmit();
        IMetaDataEmit2 &GetCOMMetaDataEmit();
        
        void AddReferencedAssembly(assembly_generator_label_type *pAsmGen);
        bool IsSaving() const;
        void SetSavingAssembly(assembly_generator_label_type *pSavingAsmGen);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 288;
#else
        static INT const PIMPL_TYPE_SIZE = 528;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H

