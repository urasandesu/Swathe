/* 
 * File: BaseMetadataDispenserPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMetadataDispenserPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseMetadataDispenserPimpl<ApiHolder>::BaseMetadataDispenserPimpl(metadata_dispenser_label_type *pClass) : 
        m_pClass(pClass), 
        m_pMetaInfo(nullptr)
    { }

#define SWATHE_DECLARE_BASE_METADATA_DISPENSER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::Initialize(metadata_info_label_type *pMetaInfo)
    {
        _ASSERTE(m_pMetaInfo == nullptr);
        _ASSERTE(pMetaInfo != nullptr);
        m_pMetaInfo = pMetaInfo;
    }


    
    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssembly(wstring const &fullName) const
    {
        return GetAssemblyCore(fullName);
    }


    
    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyFrom(path const &asmPath) const
    {
        auto pNewAsm = NewAssembly(asmPath);

        auto *pExistingAsm = static_cast<assembly_metadata_label_type *>(nullptr);
        if (!TryGetAssembly(*pNewAsm, pExistingAsm))
        {
            pNewAsm.Persist();
            return pNewAsm.Get();
        }
        else
        {
            return pExistingAsm;
        }
    }



    template<class ApiHolder>    
    bool BaseMetadataDispenserPimpl<ApiHolder>::TryGetAssemblyWithPartialName(wstring const &name, IAssembly const *&pAsm) const
    {
        pAsm = nullptr;

        auto pNewAsm = NewAssemblyWithPartialName(name);
        if (!pNewAsm->Exists())
            return false;

        auto *pExistingAsm = static_cast<assembly_metadata_label_type *>(nullptr);
        if (!TryGetAssembly(*pNewAsm, pExistingAsm))
        {
            pNewAsm.Persist();
            pAsm = pNewAsm.Get();
        }
        else
        {
            pAsm = pExistingAsm;
        }
        return true;
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::DefineAssemblyWithPartialName(wstring const &name) const
    {
        auto pNewAsmGen = NewAssemblyGenerator(name);
        pNewAsmGen.Persist();
        return pNewAsmGen.Get();
    }


    
    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenserPimpl<ApiHolder>::ResolveAssembly(IAssembly const *pAsm) const
    {
        return ResolveAssemblyCore(pAsm);
    }



    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssembly(IMetaDataImport2 *pComMetaImp) const
    {
        return GetAssemblyCore(pComMetaImp);
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::GetModifiableAssembly(IMetaDataImport2 *pModifiableComMetaImp) const
    {
        using ATL::CComPtr;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pModifiableComMetaImp != nullptr);
        
        auto pComMetaEmt = CComPtr<IMetaDataEmit2>();
        auto hr = pModifiableComMetaImp->QueryInterface(IID_IMetaDataEmit2, reinterpret_cast<void **>(&pComMetaEmt));
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        auto const *pSrcAsm = m_pClass->GetAssembly(pModifiableComMetaImp);
        
        auto pNewAsmGen = NewAssemblyGenerator(&*pComMetaEmt, pSrcAsm);
        pNewAsmGen.Persist();
        return pNewAsmGen.Get();
    }



    template<class ApiHolder>    
    bool BaseMetadataDispenserPimpl<ApiHolder>::IsCOMMetaDataDispenserPrepared() const
    {
        if (!m_pComMetaDisp.p)
        {
            auto hr = ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, 
                                         IID_IMetaDataDispenserEx, 
                                         reinterpret_cast<void **>(&m_pComMetaDisp));
            if (FAILED(hr) || !m_pComMetaDisp.p)
                return false;
        }
        return true;
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyCore(wstring const &fullName) const
    {
        auto pNewAsm = NewAssembly(fullName);

        auto *pExistingAsm = static_cast<assembly_metadata_label_type *>(nullptr);
        if (!TryGetAssembly(*pNewAsm, pExistingAsm))
        {
            pNewAsm.Persist();
            return pNewAsm.Get();
        }
        else
        {
            return pExistingAsm;
        }
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyCore(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        auto pNewAsm = NewAssembly(fullName, procArchs);

        auto *pExistingAsm = static_cast<assembly_metadata_label_type *>(nullptr);
        if (!TryGetAssembly(*pNewAsm, pExistingAsm))
        {
            pNewAsm.Persist();
            return pNewAsm.Get();
        }
        else
        {
            return pExistingAsm;
        }
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyCore(IMetaDataImport2 *pComMetaImp) const
    {
        auto pNewAsm = NewAssembly(pComMetaImp);

        auto *pExistingAsm = static_cast<assembly_metadata_label_type *>(nullptr);
        if (!TryGetAssembly(*pNewAsm, pExistingAsm))
        {
            pNewAsm.Persist();
            return pNewAsm.Get();
        }
        else
        {
            return pExistingAsm;
        }
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyRefCore(assembly_metadata_label_type const *pTargetAsm, mdToken mdt) const
    {
        auto pNewAsm = NewAssembly(pTargetAsm, mdt);

        auto *pExistingAsm = static_cast<assembly_metadata_label_type *>(nullptr);
        if (!TryGetAssembly(*pNewAsm, pExistingAsm))
        {
            pNewAsm.Persist();
            return pNewAsm.Get();
        }
        else
        {
            return pExistingAsm;
        }
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyWithPartialNameCore(wstring const &name) const
    {
        auto pNewAsm = NewAssemblyWithPartialName(name);

        auto *pExistingAsm = static_cast<assembly_metadata_label_type *>(nullptr);
        if (!TryGetAssembly(*pNewAsm, pExistingAsm))
        {
            pNewAsm.Persist();
            return pNewAsm.Get();
        }
        else
        {
            return pExistingAsm;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssembly(wstring const &fullName) const
    {
        auto pAsm = m_pMetaInfo->NewAssemblyCore(m_pClass);
        pAsm->SetFullName(fullName);
        return pAsm;
    }


    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        auto pAsm = m_pMetaInfo->NewAssemblyCore(m_pClass);
        pAsm->SetFullName(fullName);
        pAsm->SetProcessorArchitectures(procArchs);
        return pAsm;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssemblyWithPartialName(wstring const &name) const
    {
        auto pAsm = m_pMetaInfo->NewAssemblyCore(m_pClass);
        pAsm->SetName(name);
        return pAsm;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssembly(IMetaDataImport2 *pComMetaImp) const
    {
        auto pAsm = m_pMetaInfo->NewAssemblyCore(m_pClass);
        pAsm->SetCOMMetaDataImport(pComMetaImp);
        return pAsm;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssembly(path const &asmPath) const
    {
        auto pAsm = m_pMetaInfo->NewAssemblyCore(m_pClass);
        pAsm->SetAssemblyFilePath(asmPath);
        return pAsm;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssembly(assembly_metadata_label_type const *pTargetAsm, mdToken mdt) const
    {
        auto pAsm = m_pMetaInfo->NewAssemblyCore(m_pClass);
        pAsm->SetOpeningAssembly(pTargetAsm);
        pAsm->SetToken(mdt);
        return pAsm;
    }



    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::RegisterAssembly(TempPtr<assembly_metadata_label_type> &pAsm)
    {
        auto &asm_ = *pAsm;
        m_asmToIndex[&asm_] = m_pMetaInfo->RegisterAssemblyCore(pAsm);
    }


    
    template<class ApiHolder>    
    bool BaseMetadataDispenserPimpl<ApiHolder>::TryGetAssembly(assembly_metadata_label_type const &asm_, assembly_metadata_label_type *&pExistingAsm) const
    {
        if (m_asmToIndex.find(&asm_) == m_asmToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_asmToIndex[&asm_];
            pExistingAsm = m_pMetaInfo->GetAssemblyCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::DefineAssembly(IAssembly const *pSrcAsm) const
    {
        auto pNewAsmGen = NewAssemblyGenerator(pSrcAsm);
        pNewAsmGen.Persist();
        return pNewAsmGen.Get();
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::ResolveAssemblyCore(IAssembly const *pAsm) const
    {
        _ASSERTE(static_cast<IDispenser const *>(m_pClass) == pAsm->GetDispenser());

        auto *pResolvedAsm = ResolveOrDefineAssembly(pAsm);
        UpdateReferencedAssemblyIfNecessary(pResolvedAsm);
        return pResolvedAsm;
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::ResolveOrDefineAssembly(IAssembly const *pAsm) const
    {
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef decltype(m_asmGenToIndex) AsmGenToIndex;
        typedef AsmGenToIndex::value_type Value;

        auto result = FindIf(m_asmGenToIndex, [&](Value const &v) { return v.first->GetSourceAssembly() == pAsm->GetSourceAssembly(); });
        if (result)
            return (*result).first;

        return m_pClass->DefineAssembly(pAsm);
    }



    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::UpdateReferencedAssemblyIfNecessary(assembly_generator_label_type *pResolvedAsm) const
    {
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef decltype(m_asmGenToIndex) AsmGenToIndex;
        typedef AsmGenToIndex::value_type Value;

        auto result = FindIf(m_asmGenToIndex, [&](Value const &v) { return v.first->IsSaving(); });
        if (result && !pResolvedAsm->GetTargetAssembly())
            (*result).first->AddReferencedAssembly(pResolvedAsm);
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::GetModifiableAssembly(IMetaDataEmit2 *pComMetaEmt, IAssembly const *pSrcAsm) const
    {
        auto pNewAsmGen = NewAssemblyGenerator(pComMetaEmt, pSrcAsm);
        pNewAsmGen.Persist();
        return pNewAsmGen.Get();
    }


    
    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssemblyGenerator(wstring const &name) const
    {
        auto pAsmGen = m_pMetaInfo->NewAssemblyGeneratorCore(m_pClass);
        pAsmGen->SetName(name);
        return pAsmGen;
    }


    
    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssemblyGenerator(IAssembly const *pSrcAsm) const
    {
        auto pAsmGen = m_pMetaInfo->NewAssemblyGeneratorCore(m_pClass);
        pAsmGen->SetSourceAssembly(pSrcAsm);
        return pAsmGen;
    }


    
    template<class ApiHolder>    
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssemblyGenerator(IMetaDataEmit2 *pComMetaEmt, IAssembly const *pSrcAsm) const
    {
        auto pAsmGen = m_pMetaInfo->NewAssemblyGeneratorCore(m_pClass);
        pAsmGen->SetCOMMetaDataEmit(pComMetaEmt);
        pAsmGen->SetSourceAssembly(pSrcAsm);
        return pAsmGen;
    }



    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::RegisterAssemblyGenerator(TempPtr<assembly_generator_label_type> &pAsmGen)
    {
        using std::make_pair;

        auto &asmGen = *pAsmGen;
        m_asmGenToIndex.push_back(make_pair(&asmGen, m_pMetaInfo->RegisterAssemblyGeneratorCore(pAsmGen)));
    }
    


    template<class ApiHolder>    
    IMetaDataDispenserEx &BaseMetadataDispenserPimpl<ApiHolder>::GetCOMMetaDataDispenser() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pComMetaDisp.p == nullptr)
        {
            auto hr = ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, 
                                         IID_IMetaDataDispenserEx, 
                                         reinterpret_cast<void **>(&m_pComMetaDisp));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComMetaDisp;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_HPP

