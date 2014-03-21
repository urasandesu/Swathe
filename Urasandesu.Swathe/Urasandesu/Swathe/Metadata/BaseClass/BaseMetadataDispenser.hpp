/* 
 * File: BaseMetadataDispenser.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataDispenser.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseMetadataDispenser<ApiHolder>::BaseMetadataDispenser()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(metadata_dispenser_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(metadata_dispenser_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())metadata_dispenser_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseMetadataDispenser<ApiHolder>::~BaseMetadataDispenser()
    {
        Pimpl()->~metadata_dispenser_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::metadata_dispenser_pimpl_label_type *BaseMetadataDispenser<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<metadata_dispenser_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::metadata_dispenser_pimpl_label_type const *BaseMetadataDispenser<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_METADATA_DISPENSER_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMetadataDispenser<ApiHolder>::Initialize(metadata_info_label_type *pMetaInfo)
    {
        Pimpl()->Initialize(pMetaInfo);
    }

    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenser<ApiHolder>::GetAssembly(wstring const &fullName) const
    {
        return Pimpl()->GetAssembly(fullName);
    }

    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenser<ApiHolder>::GetAssemblyFrom(path const &asmPath) const
    {
        return Pimpl()->GetAssemblyFrom(asmPath);
    }

    template<class ApiHolder>    
    bool BaseMetadataDispenser<ApiHolder>::TryGetAssemblyWithPartialName(wstring const &name, IAssembly const *&pAsm) const
    {
        return Pimpl()->TryGetAssemblyWithPartialName(name, pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenser<ApiHolder>::DefineAssemblyWithPartialName(wstring const &name) const
    {
        return Pimpl()->DefineAssemblyWithPartialName(name);
    }

    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenser<ApiHolder>::GetAssembly(IMetaDataImport2 *pComMetaImp) const
    {
        return Pimpl()->GetAssembly(pComMetaImp);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenser<ApiHolder>::GetModifiableAssembly(IMetaDataImport2 *pModifiableComMetaImp) const
    {
        return Pimpl()->GetModifiableAssembly(pModifiableComMetaImp);
    }

    template<class ApiHolder>    
    void BaseMetadataDispenser<ApiHolder>::SetCOMMetaDataDispenser(IMetaDataDispenserEx *pComMetaDisp)
    {
        Pimpl()->SetCOMMetaDataDispenser(pComMetaDisp);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenser<ApiHolder>::GetAssemblyCore(wstring const &fullName) const
    {
        return Pimpl()->GetAssemblyCore(fullName);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenser<ApiHolder>::GetAssemblyCore(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        return Pimpl()->GetAssemblyCore(fullName, procArchs);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenser<ApiHolder>::GetAssemblyCore(IMetaDataImport2 *pComMetaImp) const
    {
        return Pimpl()->GetAssemblyCore(pComMetaImp);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenser<ApiHolder>::GetAssemblyRefCore(assembly_metadata_label_type const *pTargetAsm, mdToken mdt) const
    {
        return Pimpl()->GetAssemblyRefCore(pTargetAsm, mdt);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenser<ApiHolder>::GetAssemblyWithPartialNameCore(wstring const &name) const
    {
        return Pimpl()->GetAssemblyWithPartialNameCore(name);
    }

    template<class ApiHolder>    
    void BaseMetadataDispenser<ApiHolder>::RegisterAssembly(TempPtr<assembly_metadata_label_type> &pAsm)
    {
        Pimpl()->RegisterAssembly(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenser<ApiHolder>::DefineAssembly(IAssembly const *pSrcAsm) const
    {
        return Pimpl()->DefineAssembly(pSrcAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenser<ApiHolder>::ResolveAssembly(IAssembly const *pAsm) const
    {
        return Pimpl()->ResolveAssembly(pAsm);
    }

    
    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenser<ApiHolder>::ResolveOrDefineAssembly(IAssembly const *pAsm) const
    {
        return Pimpl()->ResolveOrDefineAssembly(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataDispenser<ApiHolder>::UpdateReferencedAssemblyIfNecessary(assembly_generator_label_type *pResolvedAsm) const
    {
        return Pimpl()->UpdateReferencedAssemblyIfNecessary(pResolvedAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataDispenser<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenser<ApiHolder>::GetModifiableAssembly(IMetaDataEmit2 *pComMetaEmt, IAssembly const *pSrcAsm) const
    {
        return Pimpl()->GetModifiableAssembly(pComMetaEmt, pSrcAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataDispenser<ApiHolder>::RegisterAssemblyGenerator(TempPtr<assembly_generator_label_type> &pAsmGen)
    {
        Pimpl()->RegisterAssemblyGenerator(pAsmGen);
    }

    template<class ApiHolder>    
    IMetaDataDispenserEx &BaseMetadataDispenser<ApiHolder>::GetCOMMetaDataDispenser() const
    {
        return Pimpl()->GetCOMMetaDataDispenser();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_HPP

