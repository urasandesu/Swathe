/* 
 * File: BaseInstructionGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseInstructionGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELD_H
#include <Urasandesu/Swathe/Metadata/IField.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCAL_H
#include <Urasandesu/Swathe/Metadata/ILocal.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseInstructionGeneratorPimpl<ApiHolder>::BaseInstructionGeneratorPimpl(instruction_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsmGen(nullptr), 
        m_pBodyGen(nullptr), 
        m_mdt(mdTokenNil), 
        m_pOpCode(nullptr),
        m_index(static_cast<SIZE_T>(-1)), 
        m_popingCountInit(false),
        m_popingCount(0u), 
        m_pushingCountInit(false), 
        m_pushingCount(0u), 
        m_rawDataInit(false)
    { }
    
#define SWATHE_DECLARE_BASE_INSTRUCTION_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdToken BaseInstructionGeneratorPimpl<ApiHolder>::GetToken() const
    {
        // Instruction does not have its metadata token, but the rule that GetToken surely returns the identity of the scope is convenient.
        // In this case, GetToken returns the offset of IL stream.
        if (IsNilToken(m_mdt))
        {
            if (m_index == 0ul)
            {
                m_mdt = 0ul;
            }
            else
            {
                auto const &insts = m_pBodyGen->GetInstructions();
                auto const *pPrevInst = insts[m_index - 1ul];
                m_mdt = static_cast<mdToken>(pPrevInst->GetToken() + pPrevInst->GetSize());
            }
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    OpCode const &BaseInstructionGeneratorPimpl<ApiHolder>::GetOpCode() const
    {
        _ASSERTE(m_pOpCode);
        return *m_pOpCode;
    }



    template<class ApiHolder>    
    Operand const &BaseInstructionGeneratorPimpl<ApiHolder>::GetOperand() const
    {
        return m_operand;
    }



    template<class ApiHolder>    
    SIZE_T BaseInstructionGeneratorPimpl<ApiHolder>::GetSize() const
    {
        // TODO: IInstruction に移動。
        auto const &opCode = GetOpCode();
        auto opCodeLength = opCode.GetLength();
        auto const &operandParam = opCode.GetOperandParam();
        auto operandParamType = operandParam.GetType();
        switch (operandParamType.Value())
        {
            case OperandParamTypes::OPT_INLINE_SWITCH: 
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            case OperandParamTypes::OPT_INLINE_I8: 
            case OperandParamTypes::OPT_INLINE_R: 
                return opCodeLength + 8;
            case OperandParamTypes::OPT_INLINE_BR_TARGET: 
            case OperandParamTypes::OPT_INLINE_FIELD: 
            case OperandParamTypes::OPT_INLINE_I: 
            case OperandParamTypes::OPT_INLINE_METHOD: 
            case OperandParamTypes::OPT_INLINE_STRING: 
            case OperandParamTypes::OPT_INLINE_TOK: 
            case OperandParamTypes::OPT_INLINE_TYPE: 
            case OperandParamTypes::OPT_SHORT_INLINE_R: 
            case OperandParamTypes::OPT_INLINE_SIG: 
                return opCodeLength + 4;
            case OperandParamTypes::OPT_INLINE_VAR: 
                return opCodeLength + 2;
            case OperandParamTypes::OPT_SHORT_INLINE_BR_TARGET: 
            case OperandParamTypes::OPT_SHORT_INLINE_I: 
            case OperandParamTypes::OPT_SHORT_INLINE_VAR: 
                return opCodeLength + 1;
            default: 
                return opCodeLength;
        }
    }



    template<class ApiHolder>    
    UINT BaseInstructionGeneratorPimpl<ApiHolder>::GetPopingCount() const
    {
        using boost::get;

        if (!m_popingCountInit)
        {
            auto const &behaviour0 = GetOpCode().GetBehaviour0();
            auto const &typeList = behaviour0.GetTypeList();
            m_popingCount = 0u;
            for (auto i = typeList.begin(), i_end = typeList.end(); i != i_end; ++i)
            {
                switch ((*i).Value())
                {
                    case StackBehaviourTypes::SBT_POP0:
                        // no effect
                        break;
                    case StackBehaviourTypes::SBT_POP1:
                    case StackBehaviourTypes::SBT_POP_I:
                    case StackBehaviourTypes::SBT_POP_I8:
                    case StackBehaviourTypes::SBT_POP_R4:
                    case StackBehaviourTypes::SBT_POP_R8:
                    case StackBehaviourTypes::SBT_POP_REF:
                        ++m_popingCount;
                        break;
                    case StackBehaviourTypes::SBT_VAR_POP: 
                        if (&GetOpCode() == &OpCodes::Call ||
                            &GetOpCode() == &OpCodes::Calli ||
                            &GetOpCode() == &OpCodes::Callvirt)
                        {
                            auto const &operand = GetOperand();
                            auto const *pMethod = get<IMethod const *>(operand);
                            m_popingCount += pMethod->IsStatic() ? 0 : 1;
                            m_popingCount += static_cast<UINT>(pMethod->GetParameters().size());
                        }
                        else if (&GetOpCode() == &OpCodes::Newobj)
                        {
                            auto const &operand = GetOperand();
                            auto const *pMethod = get<IMethod const *>(operand);
                            m_popingCount += static_cast<UINT>(pMethod->GetParameters().size());
                        }
                        else if (&GetOpCode() == &OpCodes::Ret)
                        {
                            auto const *pMethod = m_pBodyGen->GetMethod();
                            m_popingCount = pMethod->GetReturnType()->GetKind() == TypeKinds::TK_VOID ? 0 : 1;
                        }
                        else
                        {
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                        }
                        break;
                    default:
                        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
            }
            m_popingCountInit = true;
        }
        return m_popingCount;
    }



    template<class ApiHolder>    
    UINT BaseInstructionGeneratorPimpl<ApiHolder>::GetPushingCount() const
    {
        using boost::get;

        if (!m_pushingCountInit)
        {
            auto const &behaviour1 = GetOpCode().GetBehaviour1();
            auto const &typeList = behaviour1.GetTypeList();
            m_pushingCount = 0u;
            for (auto i = typeList.begin(), i_end = typeList.end(); i != i_end; ++i)
            {
                switch ((*i).Value())
                {
                    case StackBehaviourTypes::SBT_PUSH0:
                        // no effect
                        break;
                    case StackBehaviourTypes::SBT_PUSH1:
                    case StackBehaviourTypes::SBT_PUSH_I:
                    case StackBehaviourTypes::SBT_PUSH_I8:
                    case StackBehaviourTypes::SBT_PUSH_R4:
                    case StackBehaviourTypes::SBT_PUSH_R8:
                    case StackBehaviourTypes::SBT_PUSH_REF:
                        ++m_pushingCount;
                        break;
                    case StackBehaviourTypes::SBT_VAR_PUSH: 
                        if (&GetOpCode() == &OpCodes::Call ||
                            &GetOpCode() == &OpCodes::Calli ||
                            &GetOpCode() == &OpCodes::Callvirt)
                        {
                            auto const &operand = GetOperand();
                            auto const *pMethod = get<IMethod const *>(operand);
                            m_pushingCount = pMethod->GetReturnType()->GetKind() == TypeKinds::TK_VOID ? 0 : 1;
                        }
                        else
                        {
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                        }
                        break;
                    default:
                        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
            }
            m_pushingCountInit = true;
        }
        return m_pushingCount;
    }



    template<class ApiHolder>    
    vector<BYTE> const &BaseInstructionGeneratorPimpl<ApiHolder>::GetRawData() const
    {
        if (!m_rawDataInit)
        {
            auto blob = SimpleBlob();
            auto const &opCode = GetOpCode();
            if (opCode.GetByte1() == 0xff)
            {
                blob.Put<BYTE>(opCode.GetByte2());
            }
            else
            {
                blob.Put<BYTE>(opCode.GetByte1());
                blob.Put<BYTE>(opCode.GetByte2());
            }

            auto const &operandParam = opCode.GetOperandParam();
            switch (operandParam.GetType().Value())
            {
                case OperandParamTypes::OPT_INLINE_NONE: 
                    // no effect
                    break;
                case OperandParamTypes::OPT_INLINE_BR_TARGET: 
                    PutInlineBrTarget(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_FIELD:
                    PutInlineField(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_I:
                    PutInlineI(GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_I8:
                    PutInlineI8(GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_METHOD:
                    PutInlineMethod(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_R:
                    PutInlineR(GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_SIG:
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                    break;
                case OperandParamTypes::OPT_INLINE_STRING:
                    PutInlineString(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_SWITCH:
                    PutInlineSwitch(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_TOK:
                    PutInlineToken(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_TYPE:
                    PutInlineType(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_INLINE_VAR:
                    PutInlineVar(GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_SHORT_INLINE_BR_TARGET:
                    PutShortInlineBrTarget(this, GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_SHORT_INLINE_I:
                    PutShortInlineI(GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_SHORT_INLINE_R:
                    PutShortInlineR(GetOperand(), blob);
                    break;
                case OperandParamTypes::OPT_SHORT_INLINE_VAR:
                    PutShortInlineVar(GetOperand(), blob);
                    break;
                default:
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            
            auto size = blob.Size();
            auto rawData = vector<BYTE>(size);
            for (auto i = 0ul; i < size; ++i)
                rawData[i] = blob[i];
            rawData.swap(m_rawData);
            
            m_rawDataInit = true;
        }
        return m_rawData;
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::SetMethodBody(method_body_generator_label_type *pBodyGen)
    {
        _ASSERTE(!m_pBodyGen);
        m_pBodyGen = pBodyGen;
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::SetOpCode(OpCode const &opCode)
    {
        m_pOpCode = &opCode;
        Reset();
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::SetOperand(Operand const &operand)
    {
        m_operand = operand;
        Reset();
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::SetIndex(SIZE_T index)
    {
        _ASSERTE(m_index == static_cast<SIZE_T>(-1));
        m_index = index;
        Reset();
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::Reset()
    {
        m_mdt = mdTokenNil;
        m_popingCountInit = false;
        m_pushingCountInit = false;
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineBrTarget(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        auto *pBodyGen = _this->m_pBodyGen;

        if (auto *pArg = get<INT>(&operand))
        {
            blob.Put<INT>(*pArg);
        }
        else if (auto *const &pLabel = get<Label>(&operand))
        {
            auto const *pTargetInst = pBodyGen->GetInstruction(*pLabel);
            auto currentOffset = _this->GetToken();
            auto currentSize = _this->GetSize();
            auto targetOffset = pTargetInst->GetToken();
            blob.Put<INT>(static_cast<INT>(targetOffset - currentOffset - currentSize));
        }
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineField(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        auto *pAsmGen = _this->m_pAsmGen;

        auto const *pField = get<IField const *>(operand);
        blob.Put<mdToken>(pAsmGen->Resolve(pField)->GetToken());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineI(Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        if (auto *pArg = get<INT>(&operand))
            blob.Put<INT>(*pArg);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineI8(Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        if (auto *pArg = get<LONGLONG>(&operand))
            blob.Put<LONGLONG>(*pArg);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineMethod(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        auto *pAsmGen = _this->m_pAsmGen;

        auto const *pMethod = get<IMethod const *>(operand);
        blob.Put<mdToken>(pAsmGen->Resolve(pMethod)->GetToken());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineR(Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        if (auto *pArg = get<DOUBLE>(&operand))
            blob.Put<DOUBLE>(*pArg);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineString(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        BOOST_LOG_FUNCTION();

        using boost::get;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto *pAsmGen = _this->m_pAsmGen;

        auto const &s = get<wstring>(operand);
        CPPANONYM_D_LOGW1(L"Getting User String Token... 1: %|1$s|", s);
        auto mds = mdStringNil;
        auto &comMetaEmt = pAsmGen->GetCOMMetaDataEmit();
        auto hr = comMetaEmt.DefineUserString(s.c_str(), static_cast<ULONG>(s.size()), &mds);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", mds);

        blob.Put<mdToken>(mds);
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineSwitch(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        auto *pBodyGen = _this->m_pBodyGen;

        if (auto *pOffsets = get<vector<INT> >(&operand))
        {
            blob.Put<INT>(static_cast<INT>(pOffsets->size()));
            BOOST_FOREACH (auto const &offset, *pOffsets)
                blob.Put<INT>(offset);
        }
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineToken(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        auto *pAsmGen = _this->m_pAsmGen;

        auto const *pType = get<IType const *>(operand);
        blob.Put<mdToken>(pAsmGen->Resolve(pType)->GetToken());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineType(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        auto *pAsmGen = _this->m_pAsmGen;

        if (auto *const *ppType = get<IType const *>(&operand))
            blob.Put<mdToken>(pAsmGen->Resolve(*ppType)->GetToken());
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutInlineVar(Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        if (auto *pArg = get<SHORT>(&operand))
            blob.Put<SHORT>(*pArg);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutShortInlineBrTarget(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        auto *pBodyGen = _this->m_pBodyGen;

        if (auto *pArg = get<BYTE>(&operand))
        {
            blob.Put<BYTE>(*pArg);
        }
        else if (auto *const &pLabel = get<Label>(&operand))
        {
            auto const *pTargetInst = pBodyGen->GetInstruction(*pLabel);
            auto currentOffset = _this->GetToken();
            auto currentSize = _this->GetSize();
            auto targetOffset = pTargetInst->GetToken();
            blob.Put<BYTE>(static_cast<BYTE>(targetOffset - currentOffset - currentSize));
        }
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutShortInlineI(Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        if (auto *pArg = get<BYTE>(&operand))
            blob.Put<BYTE>(*pArg);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutShortInlineR(Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        if (auto *pArg = get<FLOAT>(&operand))
            blob.Put<FLOAT>(*pArg);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::PutShortInlineVar(Operand const &operand, SimpleBlob &blob)
    {
        using boost::get;

        if (auto *pArg = get<BYTE>(&operand))
            blob.Put<BYTE>(*pArg);
        else if (auto *const *ppLocal = get<ILocal const *>(&operand))
            blob.Put<BYTE>(static_cast<BYTE>((*ppLocal)->GetLocalIndex()));
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseInstructionGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPL_HPP

