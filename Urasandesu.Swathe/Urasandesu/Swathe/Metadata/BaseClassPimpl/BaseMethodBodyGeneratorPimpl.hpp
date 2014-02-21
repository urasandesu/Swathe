/* 
 * File: BaseMethodBodyGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodBodyGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseMethodBodyGeneratorPimpl<ApiHolder>::BaseMethodBodyGeneratorPimpl(method_body_generator_label_type *pClass) : 
        m_pClass(pClass),
        m_pAsmGen(nullptr), 
        m_pMethod(nullptr), 
        m_mdt(mdTokenNil), 
        m_rawHeaderInit(false), 
        m_rawBodyMaxStackInit(false), 
        m_rawBodyMaxStack(0u), 
        m_rawBodyInit(false), 
        m_rawEHClausesInit(false), 
        m_pSrcBody(nullptr), 
        m_exClausesInit(false)
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
    BaseMethodBodyGeneratorPimpl<ApiHolder>::~BaseMethodBodyGeneratorPimpl()
    {
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseMethodBodyGeneratorPimpl<ApiHolder>::base_heap_provider_type *BaseMethodBodyGeneratorPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMethodBodyGeneratorPimpl<ApiHolder>::base_heap_provider_type const *BaseMethodBodyGeneratorPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }    
    
#define SWATHE_DECLARE_BASE_METHOD_BODY_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }
    
    
    
    template<class ApiHolder>    
    mdToken BaseMethodBodyGeneratorPimpl<ApiHolder>::GetToken() const
    {
        BOOST_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            BOOST_LOG_NAMED_SCOPE("if (IsNilToken(m_mdt))");

            if (!m_pSrcBody)
            {
                BOOST_LOG_NAMED_SCOPE("if (!m_pSrcBody)");

                auto const &locals = m_pClass->GetLocals();
                if (locals.empty())
                {
                    BOOST_LOG_NAMED_SCOPE("if (locals.empty())");
                    CPPANONYM_D_LOGW(L"Getting Method Body Generator Token... 1: There are no locals.");
                    m_mdt = mdSignatureNil;
                }
                else
                {
                    BOOST_LOG_NAMED_SCOPE("if (!locals.empty())");

                    auto const &sig = m_pClass->GetSignature();
                    auto const &blob = sig.GetBlob();
                    CPPANONYM_D_LOGW(L"Getting Method Body Generator Token... 2: There are some locals.");
                    if (CPPANONYM_D_LOG_ENABLED())
                    {
                        auto oss = std::wostringstream();
                        oss << L"Signature:";
                        for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
                            oss << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
                        CPPANONYM_D_LOGW(oss.str());
                    }
                    auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                    auto hr = comMetaEmt.GetTokenFromSig(&blob[0], blob.size(), &m_mdt);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
        }
        return m_mdt;
    }
    
    
    
    template<class ApiHolder>    
    CallingConventions BaseMethodBodyGeneratorPimpl<ApiHolder>::GetCallingConvention() const
    {
        return CallingConventions::CC_LOCAL_SIG;
    }
    
    
    
    template<class ApiHolder>    
    vector<ILocal const *> const &BaseMethodBodyGeneratorPimpl<ApiHolder>::GetLocals() const
    {
        return !m_pSrcBody ? m_locals : m_pSrcBody->GetLocals();
    }
    
    
    
    template<class ApiHolder>    
    IInstructionPtrRange BaseMethodBodyGeneratorPimpl<ApiHolder>::GetInstructions() const
    {
        if (!m_pSrcBody)
        {
            using boost::adaptors::transformed;
            using std::function;

            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->ProviderOf<instruction_generator_label_type>();
            auto &heap = provider.Heap();

            auto toUpper = function<IInstruction const *(instruction_generator_label_type const &)>();
            toUpper = [](instruction_generator_label_type const &inst) { return static_cast<IInstruction const *>(&inst); };
            return heap | transformed(toUpper);
        }
        else
        {
            return m_pSrcBody->GetInstructions();
        }
    }
    
    
    
    template<class ApiHolder>    
    vector<ExceptionClause> const &BaseMethodBodyGeneratorPimpl<ApiHolder>::GetExceptionClauses() const
    {
        if (!m_pSrcBody)
        {
            if (!m_exClausesInit)
            {
                auto const &insts = GetInstructions();
                BOOST_FOREACH (auto const &exClauseMarker, m_endedExClauseMarkers)
                {
                    auto tryStart = insts.begin() + exClauseMarker.GetTryStartIndex();
                    
                    auto const &catchStartEndIndexExTypes = exClauseMarker.GetCatchStartEndIndexExceptionTypes();
                    BOOST_FOREACH (auto const &tuple, catchStartEndIndexExTypes)
                    {
                        auto tryEnd = insts.begin() + tuple.get<0>();
                        auto clauseStart = insts.begin() + tuple.get<0>();
                        auto clauseEnd = insts.begin() + tuple.get<1>();
                            
                        auto exClause = ExceptionClause(insts.begin());
                        exClause.SetClauseKind(!tuple.get<2>() ? ClauseKinds::CK_NONE : ClauseKinds::CK_CATCH);
                        exClause.SetTryStart(tryStart);
                        exClause.SetTryEnd(tryEnd);
                        exClause.SetClauseStart(clauseStart);
                        exClause.SetClauseEnd(clauseEnd);
                        if (tuple.get<2>())
                            exClause.SetExceptionType(tuple.get<2>());
                            
                        m_exClauses.push_back(exClause);
                    }
                    
                    if (exClauseMarker.GetFinallyEndLabel().GetIndex() != -1)
                    {
                        auto tryEnd = insts.begin() + exClauseMarker.GetFinallyStartIndex();
                        auto clauseStart = insts.begin() + exClauseMarker.GetFinallyStartIndex();
                        auto clauseEnd = insts.begin() + exClauseMarker.GetFinallyEndIndex();
                        
                        auto exClause = ExceptionClause(insts.begin());
                        exClause.SetClauseKind(ClauseKinds::CK_FINALLY);
                        exClause.SetTryStart(tryStart);
                        exClause.SetTryEnd(tryEnd);
                        exClause.SetClauseStart(clauseStart);
                        exClause.SetClauseEnd(clauseEnd);
                        
                        m_exClauses.push_back(exClause);
                    }
                }
            
                m_exClausesInit = true;
            }
            return m_exClauses;
        }
        else
        {
            return m_pSrcBody->GetExceptionClauses();
        }
    }



    template<class ApiHolder>    
    Signature const &BaseMethodBodyGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }
    
    
    
    template<class ApiHolder>    
    IMethod const *BaseMethodBodyGeneratorPimpl<ApiHolder>::GetMethod() const
    {
        return m_pMethod;
    }



    template<class ApiHolder>    
    COR_ILMETHOD_FAT const &BaseMethodBodyGeneratorPimpl<ApiHolder>::GetRawHeader() const
    {
        if (!m_rawHeaderInit)
        {
            ::ZeroMemory(&m_rawHeader, sizeof(COR_ILMETHOD_FAT));
            m_rawHeader.SetMaxStack(GetRawBodyMaxStack());
            m_rawHeader.SetCodeSize(GetRawBody().size());
            m_rawHeader.SetLocalVarSigTok(IsNilToken(GetToken()) ? mdTokenNil : GetToken());
            m_rawHeader.SetFlags(IsNilToken(GetToken()) ? 0 : CorILMethod_InitLocals);
            m_rawHeaderInit = true;
        }
        return m_rawHeader;
    }



    template<class ApiHolder>    
    vector<BYTE> const &BaseMethodBodyGeneratorPimpl<ApiHolder>::GetRawBody() const
    {
        BOOST_LOG_FUNCTION();

        using std::back_inserter;
        using std::copy;

        if (!m_rawBodyInit)
        {
            BOOST_LOG_NAMED_SCOPE("if (!m_rawBodyInit)");

            auto rawBody = vector<BYTE>();
            auto const &insts = GetInstructions();
            rawBody.reserve(insts.size());
            for (auto i = insts.begin(), i_end = insts.end(); i != i_end; ++i)
                copy((*i)->GetRawData().begin(), (*i)->GetRawData().end(), back_inserter(rawBody));
            rawBody.swap(m_rawBody);
            
            if (CPPANONYM_D_LOG_ENABLED())
            {
                auto oss = std::wostringstream();
                oss << L"Method Body IL Stream:";
                for (auto i = m_rawBody.begin(), i_end = m_rawBody.end(); i != i_end; ++i)
                    oss << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
                CPPANONYM_D_LOGW(oss.str());
            }

            m_rawBodyInit = true;
        }
        return m_rawBody;
    }



    struct IInstructionRangeIteratorHash : 
        Urasandesu::CppAnonym::Traits::HashComputable<IInstructionPtrRange::iterator>
    {
        result_type operator()(param_type v) const
        {
            using Urasandesu::CppAnonym::Utilities::HashValue;
            return HashValue(*v);
        }
    };

    struct IInstructionRangeIteratorEqualTo : 
        Urasandesu::CppAnonym::Traits::EqualityComparable<IInstructionPtrRange::iterator>
    {
        result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };

    template<class ApiHolder>    
    UINT BaseMethodBodyGeneratorPimpl<ApiHolder>::GetRawBodyMaxStack() const
    {
        BOOST_LOG_FUNCTION();

        using boost::adaptors::filtered;
        using boost::unordered_set;
        
        if (!m_rawBodyMaxStackInit)
        {
            BOOST_LOG_NAMED_SCOPE("if (!m_rawBodyMaxStackInit)");

            auto const &exClauses = GetExceptionClauses();
            auto catchClauseStartSet = unordered_set<IInstructionPtrRange::iterator, IInstructionRangeIteratorHash, IInstructionRangeIteratorEqualTo>();
            auto catchClauses = exClauses | filtered([](ExceptionClause const &exClause) { return exClause.GetClauseKind() == ClauseKinds::CK_CATCH; });
            BOOST_FOREACH (auto const &catchClause, catchClauses)
                catchClauseStartSet.insert(catchClause.GetClauseStart());
            
            auto const &insts = GetInstructions();
            auto current = 0u;
            m_rawBodyMaxStack = 0ul;
            for (auto i = insts.begin(), i_end = insts.end(); i != i_end; ++i)
            {
                if (catchClauseStartSet.find(i) != catchClauseStartSet.end())
                    current += 1;
                current += (*i)->GetPushingCount();
                current -= (*i)->GetPopingCount();
                if (m_rawBodyMaxStack < current)
                    m_rawBodyMaxStack = current;
            }

            CPPANONYM_D_LOGW1(L"Method Body Max Stack: %|1$d|", m_rawBodyMaxStack);
            
            m_rawBodyMaxStackInit = true;
        }
        return m_rawBodyMaxStack;
    }



    template<class ApiHolder>    
    vector<COR_ILMETHOD_SECT_EH_CLAUSE_FAT> const &BaseMethodBodyGeneratorPimpl<ApiHolder>::GetRawEHClauses() const
    {
        if (!m_rawEHClausesInit)
        {
            auto const &exClauses = GetExceptionClauses();
            BOOST_FOREACH (auto const &exClause, exClauses)
            {
                auto clauseKind = exClause.GetClauseKind();
                auto tryStart = exClause.GetTryStart();
                auto tryEnd = exClause.GetTryEnd();
                auto clauseStart = exClause.GetClauseStart();
                auto clauseEnd = exClause.GetClauseEnd();
                    
                auto rawEHClause = COR_ILMETHOD_SECT_EH_CLAUSE_FAT();
                rawEHClause.SetFlags(ClauseKinds::ToCorExceptionFlag(clauseKind));
                rawEHClause.SetTryOffset((*tryStart)->GetToken());
                rawEHClause.SetTryLength((*tryEnd)->GetToken() - (*tryStart)->GetToken());
                rawEHClause.SetHandlerOffset((*clauseStart)->GetToken());
                rawEHClause.SetHandlerLength((*clauseEnd)->GetToken() - (*clauseStart)->GetToken());
                if (clauseKind == ClauseKinds::CK_FILTER)
                    rawEHClause.SetFilterOffset((*exClause.GetFilterStart())->GetToken());
                else if (clauseKind == ClauseKinds::CK_CATCH)
                    rawEHClause.SetClassToken(m_pAsmGen->Resolve(exClause.GetExceptionType())->GetToken());
                    
                m_rawEHClauses.push_back(rawEHClause);
            }
            
            m_rawEHClausesInit = true;
        }
        return m_rawEHClauses;
    }



    template<class ApiHolder>    
    IAssembly const *BaseMethodBodyGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IDispenser const *BaseMethodBodyGeneratorPimpl<ApiHolder>::GetDispenser() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethodBody const *BaseMethodBodyGeneratorPimpl<ApiHolder>::GetSourceMethodBody() const
    {
        return !m_pSrcBody ? m_pClass : m_pSrcBody->GetSourceMethodBody();
    }



    template<class ApiHolder>    
    ILocal const *BaseMethodBodyGeneratorPimpl<ApiHolder>::GetLocal(ULONG index, IType const *pLocalType) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IInstructionPtrRange::iterator BaseMethodBodyGeneratorPimpl<ApiHolder>::GetInstructionIterator(ULONG offset) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, ILocal const *pLocal)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldloca_S &&
            &opCode != &OpCodes::Stloc_S && 
            &opCode != &OpCodes::Ldloc_S)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, ILocal const *)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(pLocal);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, wstring const &s)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldstr)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, wstring const &)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(s);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, IType const *pType)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldtoken &&
            &opCode != &OpCodes::Initobj &&
            &opCode != &OpCodes::Newarr && 
            &opCode != &OpCodes::Castclass && 
            &opCode != &OpCodes::Isinst && 
            &opCode != &OpCodes::Box && 
            &opCode != &OpCodes::Ldelema)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, IType const *)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(pType);
    }
    
    
    
    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, Label const &label)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Brtrue_S &&
            &opCode != &OpCodes::Brfalse_S &&
            &opCode != &OpCodes::Leave)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, Label const &)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(label);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, IMethod const *pMethod)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldftn &&
            &opCode != &OpCodes::Newobj &&
            &opCode != &OpCodes::Call && 
            &opCode != &OpCodes::Callvirt)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, IMethod const *)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(pMethod);
    }
    
    
    
    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, IField const *pField)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldsfld && 
            &opCode != &OpCodes::Stsfld)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, IField const *)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(pField);
    }
    
    
    
    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, BYTE arg)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldc_I4_S && 
            &opCode != &OpCodes::Leave_S && 
            &opCode != &OpCodes::Blt_S && 
            &opCode != &OpCodes::Ble_S && 
            &opCode != &OpCodes::Bge_S && 
            &opCode != &OpCodes::Brfalse_S && 
            &opCode != &OpCodes::Brtrue_S && 
            &opCode != &OpCodes::Br_S && 
            &opCode != &OpCodes::Beq_S && 
            &opCode != &OpCodes::Blt_Un_S && 
            &opCode != &OpCodes::Bge_Un_S && 
            &opCode != &OpCodes::Bgt_S && 
            &opCode != &OpCodes::Bne_Un_S)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, BYTE)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(arg);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, DOUBLE arg)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldc_R8)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, DOUBLE)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(arg);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, SHORT arg)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldloca)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, SHORT)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(arg);
    }
    
    
    
    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, INT arg)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldc_I4 && 
            &opCode != &OpCodes::Beq)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, INT)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(arg);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode, LONGLONG arg)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        if (&opCode != &OpCodes::Ldc_I8)
        {
            auto oss = std::wostringstream();
            oss << L"OpCodes(" << opCode.CStr() << L") is not supported in the overloaded method \"MethodBodyGenerator::Emit(OpCode const &, LONGLONG)\".";
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
        }

        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
        pInstGen->SetOperand(arg);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(OpCode const &opCode)
    {
        auto *pInstGen = NewInstructionGeneratorCore();
        pInstGen->SetOpCode(opCode);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Emit(IInstruction const *pInst)
    {
        apply_visitor(emit_instruction_visitor(this, pInst->GetOpCode()), pInst->GetOperand());
    }



    template<class ApiHolder>    
    typename BaseMethodBodyGeneratorPimpl<ApiHolder>::local_generator_label_type *BaseMethodBodyGeneratorPimpl<ApiHolder>::DefineLocal(IType const *pLocalType)
    {
        auto *pLocalGen = m_pAsmGen->DefineLocal(m_locals.size(), pLocalType, m_pClass);
        m_locals.push_back(pLocalGen);
        return pLocalGen; 
    }
    
    
    
    template<class ApiHolder>    
    Label BaseMethodBodyGeneratorPimpl<ApiHolder>::DefineLabel()
    {
        m_labeledInstIndexes.push_back(-1);
        return Label(m_labeledInstIndexes.size() - 1);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::MarkLabel(Label const &label)
    {
        auto index = label.GetIndex();
        _ASSERTE(index < m_labeledInstIndexes.size());
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<instruction_generator_label_type>();
        auto &heap = provider.Heap();
        m_labeledInstIndexes[index] = heap.size();
    }



    template<class ApiHolder>    
    Label BaseMethodBodyGeneratorPimpl<ApiHolder>::BeginExceptionBlock()
    {
        auto endLabel = DefineLabel();
        auto exClauseMarker = exception_clause_marker(GetSize(), endLabel);
        m_exClauseMarkerStack.push_back(exClauseMarker);
        return endLabel;
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::BeginCatchBlock(IType const *pExType)
    {
        _ASSERTE(!m_exClauseMarkerStack.empty());
        
        auto &exClauseMarker = m_exClauseMarkerStack.back();
        if (exClauseMarker.GetCurrentClauseKind() == ClauseKinds::CK_FILTER)
        {
            _ASSERTE(!pExType);
            Emit(OpCodes::Endfilter);
        }
        else
        {
            _ASSERTE(pExType);
            auto endLabel = exClauseMarker.GetEndLabel();
            Emit(OpCodes::Leave, endLabel);
        }
        
        exClauseMarker.MarkCatchClause(GetSize(), pExType);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::BeginFinallyBlock()
    {
        _ASSERTE(!m_exClauseMarkerStack.empty());
        
        auto &exClauseMarker = m_exClauseMarkerStack.back();
        auto endLabel = exClauseMarker.GetEndLabel();
        auto endIndex = 0ul;
        if (exClauseMarker.GetCurrentClauseKind() != ClauseKinds::CK_UNREACHED)
        {
            Emit(OpCodes::Leave, endLabel);
            endIndex = GetSize();
        }
        MarkLabel(endLabel);
        
        auto finallyEndLabel = DefineLabel();
        exClauseMarker.SetFinallyEndLabel(finallyEndLabel);
        Emit(OpCodes::Leave, finallyEndLabel);
        if (endIndex == 0ul)
            endIndex = GetSize();
        
        exClauseMarker.MarkFinallyClause(GetSize(), endIndex);
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::EndExceptionBlock()
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;
        
        _ASSERTE(!m_exClauseMarkerStack.empty());
        
        auto exClauseMarker = m_exClauseMarkerStack.back();
        m_exClauseMarkerStack.pop_back();
        
        auto endLabel = exClauseMarker.GetEndLabel();
        switch (exClauseMarker.GetCurrentClauseKind().Value())
        {
            case ClauseKinds::CK_NONE:
            case ClauseKinds::CK_CATCH:
                Emit(OpCodes::Leave, endLabel);
                break;
            
            case ClauseKinds::CK_FINALLY:
            case ClauseKinds::CK_FAULT:
                Emit(OpCodes::Endfinally);
                break;
            
            default:    // CK_UNREACHED, CK_FILTER
                BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
        }
        
        if (m_labeledInstIndexes[endLabel.GetIndex()] == -1)
            MarkLabel(endLabel);
        else
            MarkLabel(exClauseMarker.GetFinallyEndLabel());
        
        exClauseMarker.MarkEnd(GetSize());
        m_endedExClauseMarkers.push_back(exClauseMarker);
    }


    
    template<class ApiHolder>    
    ExceptionClause BaseMethodBodyGeneratorPimpl<ApiHolder>::DefineExceptionClause(ExceptionClause const &exClause, SIZE_T offset)
    {
        auto const &insts = GetInstructions();
        
        auto newExClause = ExceptionClause(insts.begin());
        newExClause.SetClauseKind(exClause.GetClauseKind());
        newExClause.SetTryStart(insts.begin() + exClause.GetTryStartIndex() + offset);
        newExClause.SetTryEnd(insts.begin() + exClause.GetTryEndIndex() + offset);
        newExClause.SetClauseStart(insts.begin() + exClause.GetClauseStartIndex() + offset);
        newExClause.SetClauseEnd(insts.begin() + exClause.GetClauseEndIndex() + offset);
        if (exClause.GetClauseKind() == ClauseKinds::CK_FILTER)
            newExClause.SetFilterStart(insts.begin() + exClause.GetFilterStartIndex() + offset);
        else if (exClause.GetClauseKind() == ClauseKinds::CK_CATCH)
            newExClause.SetExceptionType(exClause.GetExceptionType());
        
        m_exClauses.push_back(newExClause);
        
        return newExClause;
    }



    template<class ApiHolder>    
    SIZE_T BaseMethodBodyGeneratorPimpl<ApiHolder>::GetSize() const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<instruction_generator_label_type>();
        auto &heap = provider.Heap();
        return heap.size();
    }



    template<class ApiHolder>    
    typename BaseMethodBodyGeneratorPimpl<ApiHolder>::instruction_generator_label_type *BaseMethodBodyGeneratorPimpl<ApiHolder>::NewInstructionGeneratorCore() const
    {
        m_rawHeaderInit = false;
        m_rawBodyMaxStackInit = false;
        m_rawBodyInit = false;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<instruction_generator_label_type>();
        auto &heap = provider.Heap();
        auto size = heap.size();
        auto *pInstGen = heap.New();
        pInstGen->Initialize(m_pAsmGen);
        pInstGen->SetMethodBody(m_pClass);
        pInstGen->SetIndex(size);
        return pInstGen;
    }
    
    
    
    template<class ApiHolder>    
    struct BaseMethodBodyGeneratorPimpl<ApiHolder>::emit_instruction_visitor : 
        static_visitor<>
    {
        emit_instruction_visitor(method_body_generator_pimpl_label_type *_this, OpCode const &opCode) : 
            m__this(_this), 
            m_opCode(opCode)
        { }

        template<class T>
        void operator ()(T const &v) const
        {
            auto oss = std::wostringstream();
            oss << L"Type: ";
            oss << typeid(v).name();
            oss << std::endl;
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }

        template<>
        void operator ()<boost::blank>(boost::blank const &) const
        {
            m__this->Emit(m_opCode);
        }

        template<>
        void operator ()<BYTE>(BYTE const &arg) const
        {
            m__this->Emit(m_opCode, arg);
        }

        template<>
        void operator ()<DOUBLE>(DOUBLE const &arg) const
        {
            m__this->Emit(m_opCode, arg);
        }

        template<>
        void operator ()<INT>(INT const &arg) const
        {
            m__this->Emit(m_opCode, arg);
        }

        template<>
        void operator ()<LONGLONG>(LONGLONG const &arg) const
        {
            m__this->Emit(m_opCode, arg);
        }

        template<>
        void operator ()<ILocal const *>(ILocal const *const &pLocal) const
        {
            m__this->Emit(m_opCode, pLocal);
        }

        template<>
        void operator ()<wstring>(wstring const &s) const
        {
            m__this->Emit(m_opCode, s);
        }

        template<>
        void operator ()<IField const *>(IField const *const &pField) const
        {
            m__this->Emit(m_opCode, pField);
        }

        template<>
        void operator ()<IMethod const *>(IMethod const *const &pMethod) const
        {
            m__this->Emit(m_opCode, pMethod);
        }

        template<>
        void operator ()<IType const *>(IType const *const &pType) const
        {
            m__this->Emit(m_opCode, pType);
        }

        mutable method_body_generator_pimpl_label_type *m__this;
        OpCode const &m_opCode;
    };



    template<class ApiHolder>    
    class BaseMethodBodyGeneratorPimpl<ApiHolder>::exception_clause_marker
    {
    public:
        exception_clause_marker(SIZE_T tryStartIndex, Label const &endLabel) : 
            m_tryStartIndex(tryStartIndex), 
            m_tryEndIndex(-1), 
            m_endLabel(endLabel), 
            m_curClauseKind(ClauseKinds::CK_UNREACHED), 
            m_endIndex(-1), 
            m_finallyStartIndex(-1), 
            m_finallyEndIndex(-1)
        { }

        SIZE_T GetTryStartIndex() const
        {
            return m_tryStartIndex;
        }

        SIZE_T GetTryEndIndex() const
        {
            return m_tryEndIndex;
        }
        
        Label GetEndLabel() const
        {
            return m_endLabel;
        }

        ClauseKinds GetCurrentClauseKind() const
        {
            return m_curClauseKind;
        }

        std::vector<boost::tuple<SIZE_T, SIZE_T, IType const *> > const &GetCatchStartEndIndexExceptionTypes() const
        {
            return m_catchStartEndIndexExTypes;
        }

        SIZE_T GetFinallyStartIndex() const
        {
            return m_finallyStartIndex;
        }

        SIZE_T GetFinallyEndIndex() const
        {
            return m_finallyEndIndex;
        }

        Label GetFinallyEndLabel() const
        {
            return m_finallyEndLabel;
        }

        void SetFinallyEndLabel(Label const &finallyEndLabel)
        {
            _ASSERTE(m_finallyEndLabel.GetIndex() == -1);
            m_finallyEndLabel = finallyEndLabel;
        }

        void MarkCatchClause(SIZE_T catchStartIndex, IType const *pExType)
        {
            m_curClauseKind = !pExType ? ClauseKinds::CK_NONE : ClauseKinds::CK_CATCH;
            if (!m_catchStartEndIndexExTypes.empty())
            {
                auto &last = m_catchStartEndIndexExTypes.back();
                last.get<1>() = catchStartIndex;
            }
            m_catchStartEndIndexExTypes.push_back(boost::make_tuple(catchStartIndex, static_cast<SIZE_T>(-1), pExType));
            if (m_tryEndIndex == -1)
                m_tryEndIndex = catchStartIndex;
        }

        void MarkFinallyClause(SIZE_T finallyStartIndex, SIZE_T endIndex)
        {
            _ASSERTE(m_finallyStartIndex == -1);
            _ASSERTE(m_endIndex == -1);
            m_curClauseKind = ClauseKinds::CK_FINALLY;
            m_finallyStartIndex = finallyStartIndex;
            if (m_tryEndIndex == -1)
                m_tryEndIndex = endIndex;
            if (!m_catchStartEndIndexExTypes.empty())
            {
                auto &last = m_catchStartEndIndexExTypes.back();
                last.get<1>() = endIndex;
            }
            m_endIndex = endIndex;
        }

        void MarkEnd(SIZE_T endIndexOrFinallyEndIndex)
        {
            if (m_finallyEndLabel.GetIndex() == -1)
                m_endIndex = endIndexOrFinallyEndIndex;
            else
                m_finallyEndIndex = endIndexOrFinallyEndIndex;
        }

    private:
        SIZE_T m_tryStartIndex;
        SIZE_T m_tryEndIndex;
        Label m_endLabel;
        ClauseKinds m_curClauseKind;
        std::vector<boost::tuple<SIZE_T, SIZE_T, IType const *> > m_catchStartEndIndexExTypes;
        SIZE_T m_endIndex;
        SIZE_T m_finallyStartIndex;
        SIZE_T m_finallyEndIndex;
        Label m_finallyEndLabel;
    };



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::SetSourceMethodBody(IMethodBody const *pSrcBody)
    {
        _ASSERTE(!m_pSrcBody);
        m_pSrcBody = pSrcBody;
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::SetMethod(IMethod const *pMethod)
    {
        _ASSERTE(!m_pMethod);
        m_pMethod = pMethod;
    }



    template<class ApiHolder>    
    typename BaseMethodBodyGeneratorPimpl<ApiHolder>::instruction_generator_label_type const *BaseMethodBodyGeneratorPimpl<ApiHolder>::GetInstruction(Label const &label) const
    {
        auto index = label.GetIndex();
        _ASSERTE(index < m_labeledInstIndexes.size());
        auto labeledInstIndex = m_labeledInstIndexes[index];
        _ASSERTE(labeledInstIndex != -1);

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<instruction_generator_label_type>();
        auto &heap = provider.Heap();
        return &heap[labeledInstIndex];
    }



    template<class ApiHolder>    
    void BaseMethodBodyGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);

        // TODO: Method Body 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i).first->Accept(pVisitor);

        auto const &localGenToIndex = m_pAsmGen->GetLocalGeneratorToIndex();
        for (auto i = 0ul; i < localGenToIndex.size(); ++i)
            if (localGenToIndex[i].first->GetMethodBody() == m_pClass)
                localGenToIndex[i].first->Accept(pVisitor);

        GetInstructions();   // resolves default instructions of this Method.
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<instruction_generator_label_type>();
        auto &heap = provider.Heap();
        auto size = heap.size();
        for (auto i = 0ul; i < size; ++i)
            heap[i].Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPL_HPP

