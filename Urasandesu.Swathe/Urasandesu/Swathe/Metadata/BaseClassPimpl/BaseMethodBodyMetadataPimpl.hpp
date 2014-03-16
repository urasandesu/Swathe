/* 
 * File: BaseMethodBodyMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodBodyMetadataPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseMethodBodyMetadataPimpl<ApiHolder>::BaseMethodBodyMetadataPimpl(method_body_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr), 
        m_pMethod(nullptr), 
        m_mdt(mdTokenNil), 
        m_headerSize(static_cast<ULONG>(-1)), 
        m_pCode(nullptr), 
        m_codeSize(static_cast<ULONG>(-1)), 
        m_totalSize(static_cast<ULONG>(-1)), 
        m_callingConvention(CallingConventions::CC_UNREACHED), 
        m_localsInit(false), 
        m_instsInit(false), 
        m_exClausesInit(false), 
        m_pILBody(nullptr), 
        m_pSrcBody(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(8, <=, sizeof(base_heap_provider_type));
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseMethodBodyMetadataPimpl<ApiHolder>::~BaseMethodBodyMetadataPimpl()
    {
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseMethodBodyMetadataPimpl<ApiHolder>::base_heap_provider_type *BaseMethodBodyMetadataPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMethodBodyMetadataPimpl<ApiHolder>::base_heap_provider_type const *BaseMethodBodyMetadataPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_METHOD_BODY_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseMethodBodyMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdToken BaseMethodBodyMetadataPimpl<ApiHolder>::GetToken() const
    {
        if (IsNilToken(m_mdt))
            FillMethodBodyProperties(m_pAsm, m_pMethod, m_pILBody, m_mdt, m_headerSize, m_pCode, m_codeSize, m_totalSize, m_pSect);
        return m_mdt;
    }



    template<class ApiHolder>    
    CallingConventions BaseMethodBodyMetadataPimpl<ApiHolder>::GetCallingConvention() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<ILocal const *> const &BaseMethodBodyMetadataPimpl<ApiHolder>::GetLocals() const
    {
        if (!m_localsInit)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtSignature)
            {
                if (m_sig.GetBlob().empty())
                    FillLocalsProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_sig);
                FillLocalsSigProperties(m_pClass, m_sig, m_callingConvention, m_locals);
            }
            else
            {
                // nop
            }

            m_localsInit = true;
        }
        return m_locals;
    }



    template<class ApiHolder>    
    IInstructionPtrRange BaseMethodBodyMetadataPimpl<ApiHolder>::GetInstructions() const
    {
        using boost::adaptors::transformed;
        using std::function;

        if (!m_instsInit)
        {
            auto mdtTarget = GetToken();
            for (auto i = m_pCode, i_end = m_pCode + m_codeSize; i < i_end; )
            {
                auto *pInst = NewInstructionCore();
                i += pInst->TakeRawData(i, i_end);
            }

            m_instsInit = true;
        }

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<instruction_metadata_label_type>();
        auto &heap = provider.Heap();

        auto toUpper = function<IInstruction const *(instruction_metadata_label_type const &)>();
        toUpper = [](instruction_metadata_label_type const &inst) { return static_cast<IInstruction const *>(&inst); };
        return heap | transformed(toUpper);
    }



    template<class ApiHolder>    
    vector<ExceptionClause> const &BaseMethodBodyMetadataPimpl<ApiHolder>::GetExceptionClauses() const
    {
        if (!m_exClausesInit)
        {
            auto mdtTarget = GetToken();
            auto const *pSect = m_pSect;
            while (pSect)
            {
                if (pSect->Kind() == CorILMethod_Sect_EHTable)
                {
                    auto const *pEHSect = reinterpret_cast<COR_ILMETHOD_SECT_EH const *>(pSect);
                    auto ehCount = pEHSect->EHCount();
                    for (auto idx = 0ul; idx < ehCount; ++idx)
                    {
                        auto buff = IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_FAT();
                        auto const *pEHClause = pEHSect->EHClause(idx, &buff);
                        
                        auto tryStart = GetInstructionIterator(pEHClause->TryOffset);
                        auto tryEnd = GetInstructionIterator(pEHClause->TryOffset + pEHClause->TryLength);
                        auto clauseStart = GetInstructionIterator(pEHClause->HandlerOffset);
                        auto clauseEnd = GetInstructionIterator(pEHClause->HandlerOffset + pEHClause->HandlerLength);
                        
                        auto exClause = ExceptionClause(GetInstructions().begin());
                        exClause.SetClauseKind(ClauseKinds::ToClauseKinds(pEHClause->Flags, pEHClause->ClassToken));
                        exClause.SetTryStart(tryStart);
                        exClause.SetTryEnd(tryEnd);
                        exClause.SetClauseStart(clauseStart);
                        exClause.SetClauseEnd(clauseEnd);
                        if (pEHClause->Flags == COR_ILEXCEPTION_CLAUSE_FILTER)
                            exClause.SetFilterStart(GetInstructionIterator(pEHClause->FilterOffset));
                        else if (pEHClause->Flags == COR_ILEXCEPTION_CLAUSE_NONE && !IsNilToken(pEHClause->ClassToken))
                            exClause.SetExceptionType(m_pAsm->GetType(pEHClause->ClassToken));

                        m_exClauses.push_back(exClause);
                    }
                }
                else if (pSect->Kind() == CorILMethod_Sect_OptILTable)
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                
                pSect = pSect->Next();
            }

            m_exClausesInit = true;
        }

        return m_exClauses;
    }



    template<class ApiHolder>    
    Signature const &BaseMethodBodyMetadataPimpl<ApiHolder>::GetSignature() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodBodyMetadataPimpl<ApiHolder>::GetMethod() const
    {
        return m_pMethod;
    }



    template<class ApiHolder>    
    COR_ILMETHOD_FAT const &BaseMethodBodyMetadataPimpl<ApiHolder>::GetRawHeader() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<BYTE> const &BaseMethodBodyMetadataPimpl<ApiHolder>::GetRawBody() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    UINT BaseMethodBodyMetadataPimpl<ApiHolder>::GetRawBodyMaxStack() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<COR_ILMETHOD_SECT_EH_CLAUSE_FAT> const &BaseMethodBodyMetadataPimpl<ApiHolder>::GetRawEHClauses() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IAssembly const *BaseMethodBodyMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IMethodBody const *BaseMethodBodyMetadataPimpl<ApiHolder>::GetSourceMethodBody() const
    {
        return !m_pSrcBody ? m_pClass : m_pSrcBody;
    }



    template<class ApiHolder>    
    bool BaseMethodBodyMetadataPimpl<ApiHolder>::Equals(IMethodBody const *pBody) const
    {
        if (m_pClass == pBody)
            return true;

        if (!pBody)
            return false;

        auto const *pOtherBody = dynamic_cast<class_type const *>(pBody);
        if (!pOtherBody)
            return m_pClass == pBody->GetSourceMethodBody();

        return GetToken() == pOtherBody->GetToken() && 
               GetMethod() == pOtherBody->GetMethod() &&
               GetAssembly() == pOtherBody->GetAssembly();
    }



    template<class ApiHolder>    
    size_t BaseMethodBodyMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Utilities::HashValue;

        auto mdtTarget = GetToken();
        auto methodHash = HashValue(GetMethod());
        auto asmHash = HashValue(GetAssembly());
        return mdtTarget ^ methodHash ^ asmHash;
    }



    template<class ApiHolder>    
    ILocal const *BaseMethodBodyMetadataPimpl<ApiHolder>::GetLocal(ULONG index, IType const *pLocalType) const
    {
        return m_pAsm->GetLocal(index, pLocalType, m_pClass);
    }



    template<class ApiHolder>    
    typename BaseMethodBodyMetadataPimpl<ApiHolder>::instruction_metadata_label_type *BaseMethodBodyMetadataPimpl<ApiHolder>::NewInstructionCore() const
    {
        m_instsInit = false;
        //m_rawHeaderInit = false;
        //m_rawBodyMaxStackInit = false;
        //m_rawBodyInit = false;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<instruction_metadata_label_type>();
        auto &heap = provider.Heap();
        auto size = heap.size();
        auto *pInst = heap.New();
        pInst->Initialize(m_pAsm);
        pInst->SetMethodBody(m_pClass);
        pInst->SetIndex(size);
        return pInst;
    }



    template<class ApiHolder>    
    IInstructionPtrRange::iterator BaseMethodBodyMetadataPimpl<ApiHolder>::GetInstructionIterator(ULONG offset) const
    {
        using boost::adaptors::transformed;
        using boost::range::lower_bound;
        using std::function;
        
        auto insts = GetInstructions();
        auto toOffset = function<ULONG (IInstruction const *)>();
        toOffset = [](IInstruction const *pInst) { return pInst->GetToken(); };
        auto offsets = insts | transformed(toOffset);
        auto result = lower_bound(offsets, offset);
        if (result == offsets.end())
            return insts.end();
        else
            return insts.begin() + (result - offsets.begin());
    }



    template<class ApiHolder>    
    void BaseMethodBodyMetadataPimpl<ApiHolder>::SetMethod(IMethod const *pMethod)
    {
        _ASSERTE(!m_pMethod);
        m_pMethod = pMethod;
    }



    template<class ApiHolder>    
    void BaseMethodBodyMetadataPimpl<ApiHolder>::SetILBody(COR_ILMETHOD *pILBody)
    {
        _ASSERTE(!m_pILBody);
        m_pILBody = pILBody;
    }



    template<class ApiHolder>    
    void BaseMethodBodyMetadataPimpl<ApiHolder>::FillMethodBodyProperties(IAssembly const *pAsm, IMethod const *pMethod, COR_ILMETHOD const *pILBody, mdToken &mdt, ULONG &headerSize, BYTE const *&pCode, ULONG &codeSize, ULONG &totalSize, COR_ILMETHOD_SECT const *&pSect)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using boost::array;
        
        if (!pILBody)
        {
            auto asmStorage = pAsm->GetAssemblyStorage();

            auto i = asmStorage.begin();
            auto i_end = asmStorage.end();
            _ASSERTE(i != i_end);
                
            auto dosHeader = IMAGE_DOS_HEADER();
            i = PEGetDOSHeader(i, i_end, dosHeader);
            _ASSERTE(dosHeader.e_magic == 0x5A4D);
            _ASSERTE(i != i_end);
                
            auto dosStubBody = array<BYTE, 0x40>();
            i = PEGetData(i, i_end, dosStubBody.size(), dosStubBody.begin());
            _ASSERTE(i != i_end);
                
            {
                auto signature = DWORD();
                auto fileHeader = IMAGE_FILE_HEADER();
                PEGetNTHeadersPrerequisites(i, i_end, signature, fileHeader);
                _ASSERTE(signature == 0x00004550);
                if (fileHeader.Machine == IMAGE_FILE_MACHINE_I386)
                {
                    auto ntHeaders32 = IMAGE_NT_HEADERS32();
                    i = PEGetNTHeaders(i, i_end, ntHeaders32);
                }
                else
                {
                    auto ntHeaders64 = IMAGE_NT_HEADERS64();
                    i = PEGetNTHeaders(i, i_end, ntHeaders64);
                }
                _ASSERTE(i != i_end);
            }
                
            auto textSecHeader = IMAGE_SECTION_HEADER();
            i = PEGetSectionHeader(i, i_end, textSecHeader);
            _ASSERTE(std::string(reinterpret_cast<CHAR *>(&textSecHeader.Name[0])) == std::string(".text"));
            _ASSERTE(i != i_end);
                
            i = asmStorage.begin();
            i_end = asmStorage.end();
                
            auto codeRVA = pMethod->GetCodeRVA();
            auto offset = codeRVA - textSecHeader.VirtualAddress + textSecHeader.PointerToRawData;
            i += offset;
            _ASSERTE(i != i_end);
                
            pILBody = reinterpret_cast<COR_ILMETHOD const *>(i);
        }
        
        
        if (pILBody->Fat.IsFat())
        {
            headerSize = sizeof(COR_ILMETHOD_FAT);
            pCode = pILBody->Fat.GetCode();
            codeSize = pILBody->Fat.GetCodeSize();
            mdt = pILBody->Fat.GetLocalVarSigTok();
            pSect = pILBody->Fat.GetSect();
        }
        else
        {
            headerSize = sizeof(COR_ILMETHOD_TINY);
            pCode = pILBody->Tiny.GetCode();
            codeSize = pILBody->Tiny.GetCodeSize();
            mdt = pMethod->GetToken();
            pSect = pILBody->Tiny.GetSect();
        }
        totalSize = headerSize + codeSize;
    }



    template<class ApiHolder>    
    void BaseMethodBodyMetadataPimpl<ApiHolder>::FillLocalsProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, Signature &sig)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget) && TypeFromToken(mdtTarget) == mdtSignature);

        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto hr = pComMetaImp->GetSigFromToken(mdtTarget, &pSig, &sigLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        sig.SetBlob(pSig, sigLength);
    }

    
    
    template<class ApiHolder>    
    void BaseMethodBodyMetadataPimpl<ApiHolder>::FillLocalsSigProperties(IMethodBody const *pBody, Signature const &sig, CallingConventions &callingConvention, vector<ILocal const *> &locals)
    {
        _ASSERTE(pBody);
        _ASSERTE(!sig.GetBlob().empty());
        
        if (callingConvention != CallingConventions::CC_UNREACHED)
            return;
        
        sig.Decode(pBody, callingConvention, locals);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPL_HPP

