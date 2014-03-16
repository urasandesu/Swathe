/* 
 * File: BaseMetadataDispenser.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METADATADISPENSERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/MetadataDispenserFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
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

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using boost::filesystem::path;
    using std::pair;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMetadataDispenser : 
        public IDispenser
    {
    public:
        SWATHE_BEGIN_METADATA_DISPENSER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METADATA_DISPENSER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METADATA_DISPENSER_FACADE_TYPEDEF_ALIAS
        
        BaseMetadataDispenser();
        ~BaseMetadataDispenser();

        void Initialize(metadata_info_label_type *pMetaInfo);
        IAssembly const *GetAssembly(wstring const &fullName) const;
        IAssembly const *GetAssemblyFrom(path const &asmPath) const;
        bool TryGetAssemblyWithPartialName(wstring const &name, IAssembly const *&pAsm) const;
        assembly_generator_label_type *DefineAssemblyWithPartialName(wstring const &name) const;        
        IAssembly const *GetAssembly(IMetaDataImport2 *pComMetaImp) const;
        assembly_generator_label_type *GetModifiableAssembly(IMetaDataImport2 *pModifiableComMetaImp) const;
        bool IsCOMMetaDataDispenserPrepared() const;
    
    private:
        metadata_dispenser_pimpl_label_type *Pimpl();
        metadata_dispenser_pimpl_label_type const *Pimpl() const;

        assembly_metadata_label_type const *GetAssemblyCore(wstring const &fullName) const;
        assembly_metadata_label_type const *GetAssemblyCore(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const;
        assembly_metadata_label_type const *GetAssemblyCore(IMetaDataImport2 *pComMetaImp) const;
        assembly_metadata_label_type const *GetAssemblyRefCore(assembly_metadata_label_type const *pTargetAsm, mdToken mdt) const;
        assembly_metadata_label_type const *GetAssemblyWithPartialNameCore(wstring const &name) const;
        void RegisterAssembly(TempPtr<assembly_metadata_label_type> &pAsm);

        assembly_generator_label_type *DefineAssembly(IAssembly const *pSrcAsm) const;
        assembly_generator_label_type *ResolveAssembly(IAssembly const *pAsm) const;
        assembly_generator_label_type *ResolveOrDefineAssembly(IAssembly const *pAsm) const;
        void UpdateReferencedAssemblyIfNecessary(assembly_generator_label_type *pResolvedAsm) const;
        assembly_generator_label_type *GetModifiableAssembly(IMetaDataEmit2 *pComMetaEmt, IAssembly const *pSrcAsm) const;
        void RegisterAssemblyGenerator(TempPtr<assembly_generator_label_type> &pAsmGen);

        IMetaDataDispenserEx &GetCOMMetaDataDispenser() const;

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 48;
#else
        static INT const PIMPL_TYPE_SIZE = 96;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_H

