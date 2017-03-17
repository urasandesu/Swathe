/* 
 * File: BaseMetadataDispenserPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METADATADISPENSERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/MetadataDispenserPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMetadataDispenserPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALFWD_H
#include <Urasandesu/Swathe/Metadata/ILocalFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYFWD_H
#include <Urasandesu/Swathe/Metadata/IPropertyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSER_H
#include <Urasandesu/Swathe/Metadata/IDispenser.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYRESOLVER_H
#include <Urasandesu/Swathe/Metadata/AssemblyResolver.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::filesystem::path;
    using boost::unordered_set;
    using std::pair;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMetadataDispenserPimpl
    {
    public:
        SWATHE_BEGIN_METADATA_DISPENSER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METADATA_DISPENSER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METADATA_DISPENSER_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseMetadataDispenserPimpl(metadata_dispenser_label_type *pClass);
        ~BaseMetadataDispenserPimpl();

        void Initialize(metadata_info_label_type *pMetaInfo, fusion_info_label_type const *pFuInfo);
        IAssembly const *GetAssembly(wstring const &fullName) const;
        IAssembly const *GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const;
        IAssembly const *GetAssemblyFrom(path const &asmPath) const;
        TempPtr<IAssembly const> GetTempAssemblyFrom(path const &asmPath) const;
        bool TryGetAssemblyWithPartialName(wstring const &name, IAssembly const *&pAsm) const;
        IAssemblyPtrRange GetAssemblies() const;
        assembly_generator_label_type *DefineAssemblyWithPartialName(wstring const &name) const;
        IAssembly const *GetAssembly(IMetaDataImport2 *pComMetaImp) const;
        assembly_generator_label_type *GetModifiableAssembly(IMetaDataImport2 *pModifiableComMetaImp) const;
        AssemblyResolver<fusion_info_label_type> &GetAssemblyResolver();
        AssemblyResolver<fusion_info_label_type> const &GetAssemblyResolver() const;
        
    private:        
        void SetCOMMetaDataDispenser(IMetaDataDispenserEx *pComMetaDisp);

        assembly_metadata_label_type const *GetAssemblyCore(wstring const &fullName) const;
        assembly_metadata_label_type const *GetAssemblyCore(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const;
        assembly_metadata_label_type const *GetAssemblyCore(IMetaDataImport2 *pComMetaImp) const;
        assembly_metadata_label_type const *GetAssemblyRefCore(assembly_metadata_label_type const *pOpeningAsm, mdToken mdt) const;
        assembly_metadata_label_type const *GetAssemblyWithPartialNameCore(wstring const &name) const;
        TempPtr<assembly_metadata_label_type> NewAssembly(wstring const &fullName) const;
        TempPtr<assembly_metadata_label_type> NewAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const;
        TempPtr<assembly_metadata_label_type> NewAssemblyWithPartialName(wstring const &name) const;
        TempPtr<assembly_metadata_label_type> NewAssembly(IMetaDataImport2 *pComMetaImp) const;
        TempPtr<assembly_metadata_label_type> NewAssembly(path const &asmPath) const;
        TempPtr<assembly_metadata_label_type> NewAssembly(assembly_metadata_label_type const *pOpeningAsm, mdToken mdt) const;
        void RegisterAssembly(TempPtr<assembly_metadata_label_type> &pAsm);
        bool TryGetAssembly(assembly_metadata_label_type &asm_, assembly_metadata_label_type *&pExistingAsm) const;
        
        assembly_generator_label_type *DefineAssembly(IAssembly const *pSrcAsm) const;
        assembly_generator_label_type *ResolveAssemblyRef(assembly_generator_label_type *pSavingAsmGen, IAssembly const *pAsm) const;
        static assembly_generator_label_type *GetTargetAssembly(assembly_generator_label_type *pSavingAsmGen);
        assembly_generator_label_type *ResolveOrDefineAssemblyRef(assembly_generator_label_type *pSavingAsmGen, IAssembly const *pAsm) const;
        void UpdateReferencedAssemblyIfNecessary(assembly_generator_label_type *pSavingAsmGen, assembly_generator_label_type *pResolvedAsm) const;
        assembly_generator_label_type *GetModifiableAssembly(IMetaDataEmit2 *pComMetaEmt, IAssembly const *pSrcAsm) const;
        TempPtr<assembly_generator_label_type> NewAssemblyGenerator(wstring const &name) const;
        TempPtr<assembly_generator_label_type> NewAssemblyGenerator(IAssembly const *pSrcAsm) const;
        TempPtr<assembly_generator_label_type> NewAssemblyGenerator(IMetaDataEmit2 *pComMetaEmt, IAssembly const *pSrcAsm) const;
        void RegisterAssemblyGenerator(TempPtr<assembly_generator_label_type> &pAsmGen);

        IMetaDataDispenserEx &GetCOMMetaDataDispenser() const;

        mutable metadata_dispenser_label_type *m_pClass;
        metadata_info_label_type *m_pMetaInfo;
        AssemblyResolver<fusion_info_label_type> m_asmResolver;
        mutable unordered_set<assembly_metadata_label_type *, IAssemblyHash, IAssemblyEqualTo> m_asms;
        mutable vector<assembly_generator_label_type *> m_asmGens;
        mutable ATL::CComPtr<IMetaDataDispenserEx> m_pComMetaDisp;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_H

