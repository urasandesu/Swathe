/* 
 * File: BaseInstructionMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseInstructionMetadataPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseInstructionMetadataPimpl<ApiHolder>::BaseInstructionMetadataPimpl(instruction_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr), 
        m_pBody(nullptr), 
        m_mdt(mdTokenNil), 
        m_pOpCode(nullptr),
        m_index(static_cast<SIZE_T>(-1)), 
        m_popingCountInit(false),
        m_popingCount(0u), 
        m_pushingCountInit(false), 
        m_pushingCount(0u)
    { }

#define SWATHE_DECLARE_BASE_INSTRUCTION_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseInstructionMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }

    
    
    template<class ApiHolder>    
    mdToken BaseInstructionMetadataPimpl<ApiHolder>::GetToken() const
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
                auto const &insts = m_pBody->GetInstructions();
                auto const *pPrevInst = insts[m_index - 1ul];
                m_mdt = static_cast<mdToken>(pPrevInst->GetToken() + pPrevInst->GetSize());
            }
        }
        return m_mdt;
    }

    
    
    template<class ApiHolder>    
    OpCode const &BaseInstructionMetadataPimpl<ApiHolder>::GetOpCode() const
    {
        _ASSERTE(m_pOpCode);
        return *m_pOpCode;
    }

    
    
    template<class ApiHolder>    
    Operand const &BaseInstructionMetadataPimpl<ApiHolder>::GetOperand() const
    {
        return m_operand;
    }

    
    
    template<class ApiHolder>    
    SIZE_T BaseInstructionMetadataPimpl<ApiHolder>::GetSize() const
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
    UINT BaseInstructionMetadataPimpl<ApiHolder>::GetPopingCount() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }

    
    
    template<class ApiHolder>    
    UINT BaseInstructionMetadataPimpl<ApiHolder>::GetPushingCount() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }

    
    
    template<class ApiHolder>    
    vector<BYTE> const &BaseInstructionMetadataPimpl<ApiHolder>::GetRawData() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }

    
    
    template<class ApiHolder>    
    void BaseInstructionMetadataPimpl<ApiHolder>::SetMethodBody(method_body_metadata_label_type *pBody)
    {
        _ASSERTE(!m_pBody);
        m_pBody = pBody;
    }



    template<class ApiHolder>    
    void BaseInstructionMetadataPimpl<ApiHolder>::SetIndex(SIZE_T index)
    {
        _ASSERTE(m_index == static_cast<SIZE_T>(-1));
        m_index = index;
        Reset();
    }



    template<class ApiHolder>    
    void BaseInstructionMetadataPimpl<ApiHolder>::Reset()
    {
        m_mdt = mdTokenNil;
        m_popingCountInit = false;
        m_pushingCountInit = false;
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeRawData(BYTE const *i, BYTE const *i_end)
    {
        auto _i = i;
        auto const &opCode = OpCodes::GetOpCode(i, i_end);
        m_pOpCode = &opCode;
        i += opCode.GetLength();
        
        auto const &operandParam = opCode.GetOperandParam();
        switch (operandParam.GetType().Value())
        {
            case OperandParamTypes::OPT_INLINE_NONE: 
                // no effect
                break;
            case OperandParamTypes::OPT_INLINE_BR_TARGET: 
                i += TakeInlineBrTarget(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_FIELD:
                i += TakeInlineField(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_I:
                i += TakeInlineI(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_I8:
                i += TakeInlineI8(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_METHOD:
                i += TakeInlineMethod(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_R:
                i += TakeInlineR(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_SIG:
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                break;
            case OperandParamTypes::OPT_INLINE_STRING:
                i += TakeInlineString(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_SWITCH:
                i += TakeInlineSwitch(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_TOK:
                i += TakeInlineToken(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_TYPE:
                i += TakeInlineType(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_INLINE_VAR:
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                break;
            case OperandParamTypes::OPT_SHORT_INLINE_BR_TARGET:
                i += TakeShortInlineBrTarget(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_SHORT_INLINE_I:
                i += TakeShortInlineI(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_SHORT_INLINE_R:
                i += TakeShortInlineR(this, i, i_end, m_operand);
                break;
            case OperandParamTypes::OPT_SHORT_INLINE_VAR:
                i += TakeShortInlineVar(this, i, i_end, m_operand);
                break;
            default:
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        
        return static_cast<ULONG>(i - _i);
    }
    
    
    
    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineBrTarget(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto const *pBody = _this->m_pBody;
        
        auto offset = *reinterpret_cast<INT const *>(i);
        _ASSERTE(i + sizeof(INT) <= i_end);

        operand = offset;
        
        return sizeof(INT);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineField(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto const *pAsm = _this->m_pAsm;

        auto mdt = *reinterpret_cast<mdToken const *>(i);
        _ASSERTE(i + sizeof(mdToken) <= i_end);

        operand = pAsm->GetField(mdt);

        return sizeof(mdToken);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineI(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto *pBody = _this->m_pBody;

        auto value = *reinterpret_cast<INT const *>(i);
        _ASSERTE(i + sizeof(INT) <= i_end);

        operand = value;

        return sizeof(INT);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineI8(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto *pBody = _this->m_pBody;

        auto value = *reinterpret_cast<LONGLONG const *>(i);
        _ASSERTE(i + sizeof(LONGLONG) <= i_end);

        operand = value;

        return sizeof(LONGLONG);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineMethod(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto const *pAsm = _this->m_pAsm;

        auto mdt = *reinterpret_cast<mdToken const *>(i);
        _ASSERTE(i + sizeof(mdToken) <= i_end);

        operand = pAsm->GetMethod(mdt);

        return sizeof(mdToken);
    }
    
    
    
    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineR(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto *pBody = _this->m_pBody;

        auto value = *reinterpret_cast<DOUBLE const *>(i);
        _ASSERTE(i + sizeof(DOUBLE) <= i_end);

        operand = value;

        return sizeof(DOUBLE);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineString(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto const *pAsm = _this->m_pAsm;

        auto mds = *reinterpret_cast<mdString const *>(i);
        _ASSERTE(i + sizeof(mdString) <= i_end);

        auto wzs = array<WCHAR, MAX_SYM_NAME>();
        auto wzsLength = 0ul;
        auto &comMetaImp = pAsm->GetCOMMetaDataImport();
        auto hr = comMetaImp.GetUserString(mds, wzs.c_array(), static_cast<ULONG>(wzs.size()), &wzsLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        operand = wstring(wzs.data());
        
        return sizeof(mdString);
    }
    
    
    
    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineSwitch(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto *pBody = _this->m_pBody;

        auto length = *reinterpret_cast<INT const *>(i);
        _ASSERTE(i + sizeof(INT) + length * sizeof(INT) <= i_end);
        
        i += sizeof(INT);
        
        auto offsets = vector<INT>(length);
        for (auto n = 0; n < length; ++n, i += sizeof(INT))
            offsets[n] = *reinterpret_cast<INT const *>(i);
        
        operand = offsets;
        
        return sizeof(INT) + length * sizeof(INT);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineToken(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto const *pAsm = _this->m_pAsm;

        auto mdtTarget = *reinterpret_cast<mdToken const *>(i);
        _ASSERTE(i + sizeof(mdToken) <= i_end);

        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
            case mdtTypeRef:
            case mdtGenericParam:
            case mdtTypeSpec:
                operand = pAsm->GetType(mdtTarget);
                break;

            case mdtFieldDef:
                operand = pAsm->GetField(mdtTarget);
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }

        return sizeof(mdToken);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeInlineType(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto const *pAsm = _this->m_pAsm;

        auto mdt = *reinterpret_cast<mdToken const *>(i);
        _ASSERTE(i + sizeof(mdToken) <= i_end);

        operand = pAsm->GetType(mdt);

        return sizeof(mdToken);
    }
    
    
    
    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeShortInlineBrTarget(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto const *pBody = _this->m_pBody;
        
        auto offset = static_cast<BYTE>(*i);
        _ASSERTE(i + sizeof(BYTE) <= i_end);

        operand = offset;
        
        return sizeof(BYTE);
    }
    
    
    
    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeShortInlineI(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto *pBody = _this->m_pBody;

        auto value = static_cast<BYTE>(*i);
        _ASSERTE(i + sizeof(BYTE) <= i_end);

        operand = value;

        return sizeof(BYTE);
    }
    
    
    
    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeShortInlineR(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto *pBody = _this->m_pBody;

        auto value = *reinterpret_cast<FLOAT const *>(i);
        _ASSERTE(i + sizeof(FLOAT) <= i_end);

        operand = value;

        return sizeof(FLOAT);
    }



    template<class ApiHolder>    
    ULONG BaseInstructionMetadataPimpl<ApiHolder>::TakeShortInlineVar(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand)
    {
        auto *pBody = _this->m_pBody;

        auto index = static_cast<BYTE>(*i);
        _ASSERTE(i + sizeof(BYTE) <= i_end);

        operand = index;

        return sizeof(BYTE);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPL_HPP

