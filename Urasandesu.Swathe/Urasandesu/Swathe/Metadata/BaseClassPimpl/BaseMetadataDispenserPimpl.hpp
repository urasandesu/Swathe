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

    
    
    template<class ApiHolder>    
    BaseMetadataDispenserPimpl<ApiHolder>::~BaseMetadataDispenserPimpl()
    { 
        BOOST_FOREACH (auto const &pAsm, m_asms)
            m_pMetaInfo->UnloadAssemblyCore(pAsm);

        BOOST_FOREACH (auto const &pAsmGen, m_asmGens)
            m_pMetaInfo->UnloadAssemblyGeneratorCore(pAsmGen);
    }

#define SWATHE_DECLARE_BASE_METADATA_DISPENSER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::Initialize(metadata_info_label_type *pMetaInfo, fusion_info_label_type const *pFuInfo)
    {
        _ASSERTE(!m_pMetaInfo);
        _ASSERTE(pMetaInfo);
        m_pMetaInfo = pMetaInfo;
        
        m_asmResolver.Initialize(pFuInfo);
    }


    
    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssembly(wstring const &fullName) const
    {
        return GetAssemblyCore(fullName);
    }


    
    template<class ApiHolder>    
    IAssembly const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        return GetAssemblyCore(fullName, procArchs);
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
    TempPtr<IAssembly const> BaseMetadataDispenserPimpl<ApiHolder>::GetTempAssemblyFrom(path const &asmPath) const
    {
        return NewAssembly(asmPath);
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
    IAssemblyPtrRange BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblies() const
    {
        using boost::adaptors::filtered;
        using boost::adaptors::transformed;
        using std::function;

        auto ofAssembly = function<bool (assembly_metadata_label_type *)>();
        ofAssembly = [](assembly_metadata_label_type *pAsm) { return TypeFromToken(pAsm->GetToken()) == mdtAssembly; };
        auto toAssembly = function<IAssembly const *(assembly_metadata_label_type *)>();
        toAssembly = [](assembly_metadata_label_type *pAsm) { return static_cast<IAssembly const *>(pAsm); };
        return m_asms | filtered(ofAssembly) | transformed(toAssembly);
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::DefineAssemblyWithPartialName(wstring const &name) const
    {
        auto pNewAsmGen = NewAssemblyGenerator(name);
        pNewAsmGen.Persist();
        return pNewAsmGen.Get();
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
    AssemblyResolver<typename BaseMetadataDispenserPimpl<ApiHolder>::fusion_info_label_type> &BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyResolver()
    {
        return m_asmResolver;
    }



    template<class ApiHolder>    
    AssemblyResolver<typename BaseMetadataDispenserPimpl<ApiHolder>::fusion_info_label_type> const &BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyResolver() const
    {
        return const_cast<class_pimpl_type *>(this)->GetAssemblyResolver();
    }



    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::SetCOMMetaDataDispenser(IMetaDataDispenserEx *pComMetaDisp)
    {
        _ASSERTE(!m_pComMetaDisp.p);
        _ASSERTE(pComMetaDisp);
        m_pComMetaDisp = pComMetaDisp;
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
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type const *BaseMetadataDispenserPimpl<ApiHolder>::GetAssemblyRefCore(assembly_metadata_label_type const *pOpeningAsm, mdToken mdt) const
    {
        auto pNewAsm = NewAssembly(pOpeningAsm, mdt);

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
    TempPtr<typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataDispenserPimpl<ApiHolder>::NewAssembly(assembly_metadata_label_type const *pOpeningAsm, mdToken mdt) const
    {
        auto pAsm = m_pMetaInfo->NewAssemblyCore(m_pClass);
        pAsm->SetOpeningAssembly(pOpeningAsm);
        pAsm->SetToken(mdt);
        return pAsm;
    }



    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::RegisterAssembly(TempPtr<assembly_metadata_label_type> &pAsm)
    {
        m_pMetaInfo->RegisterAssemblyCore(pAsm);
        m_asms.insert(pAsm.Get());
    }


    
    template<class ApiHolder>    
    bool BaseMetadataDispenserPimpl<ApiHolder>::TryGetAssembly(assembly_metadata_label_type &asm_, assembly_metadata_label_type *&pExistingAsm) const
    {
        auto result = m_asms.find(&asm_);
        if (result == m_asms.end())
        {
            return false;
        }
        else
        {
            pExistingAsm = *result;
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
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::ResolveAssemblyRef(assembly_generator_label_type *pSavingAsmGen, IAssembly const *pAsm) const
    {
        CPPANONYM_LOG_FUNCTION();

        _ASSERTE(static_cast<IDispenser const *>(m_pClass) == pAsm->GetDispenser());

#ifdef _DEBUG
        CPPANONYM_D_LOGW2(L"pSavingAsmGen(0x%|1|): %|2|", reinterpret_cast<void *>(pSavingAsmGen), pSavingAsmGen->GetFullName());
        CPPANONYM_D_LOGW3(L"pAsm(0x%|1|)(0x%|2|): %|3|", reinterpret_cast<void const *>(pAsm), reinterpret_cast<void const *>(dynamic_cast<assembly_generator_label_type const *>(pAsm)), pAsm->GetFullName());
#endif

        auto *pResolvedAsm = ResolveOrDefineAssemblyRef(pSavingAsmGen, pAsm);
#ifdef _DEBUG
        CPPANONYM_D_LOGW2(L"pResolvedAsm(0x%|1|): %|2|", reinterpret_cast<void *>(pResolvedAsm), pResolvedAsm->GetFullName());
#endif
        UpdateReferencedAssemblyIfNecessary(pSavingAsmGen, pResolvedAsm);
        return pResolvedAsm;
    }



    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::GetTargetAssembly(assembly_generator_label_type *pSavingAsmGen)
    {
        _ASSERTE(pSavingAsmGen);
        
        auto const *pTargetAsm = pSavingAsmGen->GetTargetAssembly();
        auto const *pTargetAsmGen = dynamic_cast<assembly_generator_label_type const *>(pTargetAsm);
        if (!pTargetAsmGen)
            return pSavingAsmGen;
        
        return GetTargetAssembly(const_cast<assembly_generator_label_type *>(pTargetAsmGen));
    }

    
    
    template<class ApiHolder>    
    typename BaseMetadataDispenserPimpl<ApiHolder>::assembly_generator_label_type *BaseMetadataDispenserPimpl<ApiHolder>::ResolveOrDefineAssemblyRef(assembly_generator_label_type *pSavingAsmGen, IAssembly const *pAsm) const
    {
        using Urasandesu::CppAnonym::Collections::FindIf;
        
        if (pSavingAsmGen->Equals(pAsm))
            return pSavingAsmGen;
        
        typedef decltype(m_asmGens) AsmGens;
        typedef AsmGens::value_type Value;

        auto const *pAsmGen = dynamic_cast<assembly_generator_label_type const *>(pAsm);
        auto isAlreadyExist = [&](Value const &v) { return pAsmGen ? v->Equals(pAsmGen) : v->Equals(pAsm) && GetTargetAssembly(pSavingAsmGen)->Equals(GetTargetAssembly(v)); };
        auto result = FindIf(m_asmGens, isAlreadyExist);
        if (result)
            return *result;

        return m_pClass->DefineAssembly(pAsm);
    }



    template<class ApiHolder>    
    void BaseMetadataDispenserPimpl<ApiHolder>::UpdateReferencedAssemblyIfNecessary(assembly_generator_label_type *pSavingAsmGen, assembly_generator_label_type *pResolvedAsm) const
    {
        if (!pResolvedAsm->GetTargetAssembly())
            GetTargetAssembly(pSavingAsmGen)->AddReferencedAssembly(pResolvedAsm);
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
        m_asmGens.push_back(pAsmGen.Get());
    }
    


    template<class ApiHolder>    
    IMetaDataDispenserEx &BaseMetadataDispenserPimpl<ApiHolder>::GetCOMMetaDataDispenser() const
    {
        _ASSERTE(m_pComMetaDisp.p);
        return *m_pComMetaDisp;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATADISPENSERPIMPL_HPP

