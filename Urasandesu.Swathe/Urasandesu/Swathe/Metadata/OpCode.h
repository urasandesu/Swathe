/* 
 * File: OpCode.h
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
#ifndef URASANDESU_SWATHE_METADATA_OPCODE_H
#define URASANDESU_SWATHE_METADATA_OPCODE_H

#ifndef URASANDESU_SWATHE_METADATA_OPCODETYPES_H
#include <Urasandesu/Swathe/Metadata/OpCodeTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURTYPES_H
#include <Urasandesu/Swathe/Metadata/StackBehaviourTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMTYPES_H
#include <Urasandesu/Swathe/Metadata/OperandParamTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDTYPES_H
#include <Urasandesu/Swathe/Metadata/OpCodeKindTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWTYPES_H
#include <Urasandesu/Swathe/Metadata/ControlFlowTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOUR_H
#include <Urasandesu/Swathe/Metadata/StackBehaviour.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP
#include <Urasandesu/Swathe/Metadata/StackBehaviours.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAM_H
#include <Urasandesu/Swathe/Metadata/OperandParam.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPERANDPARAMS_HPP
#include <Urasandesu/Swathe/Metadata/OperandParams.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKIND_H
#include <Urasandesu/Swathe/Metadata/OpCodeKind.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEKINDS_HPP
#include <Urasandesu/Swathe/Metadata/OpCodeKinds.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOW_H
#include <Urasandesu/Swathe/Metadata/ControlFlow.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP
#include <Urasandesu/Swathe/Metadata/ControlFlows.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODEFWD_H
#include <Urasandesu/Swathe/Metadata/OpCodeFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OpCode : 
        boost::noncopyable
    {
    public:
        inline OpCodeTypes const &GetType() const { return m_type; }
        inline std::wstring const &GetName() const  { return m_name; }
        inline StackBehaviour const &GetBehaviour0() const { return m_behaviour0; }
        inline StackBehaviour const &GetBehaviour1() const { return m_behaviour1; }
        inline OperandParam const &GetOperandParam() const { return m_operandParam; }
        inline OpCodeKind const &GetOpCodeKind() const { return m_opcodeKind; }
        inline BYTE GetLength() const { return m_length; }
        inline BYTE GetByte1() const { return m_byte1; }
        inline BYTE GetByte2() const { return m_byte2; }
        inline ControlFlow const &GetControlFlow() const { return m_controlFlow; }
        inline LPCWSTR CStr() const { return m_cstr.c_str(); }

    protected:
        inline OpCode(OpCodeTypes const &type, 
                            std::wstring const &name, 
                            StackBehaviour const &behaviour0, 
                            StackBehaviour const &behaviour1, 
                            OperandParam const &operandParam, 
                            OpCodeKind const &opcodeKind, 
                            BYTE length, 
                            BYTE byte1,
                            BYTE byte2, 
                            ControlFlow const &controlFlow, 
                            std::wstring const &cstr) : 
            m_type(type),
            m_name(name),
            m_behaviour0(behaviour0),
            m_behaviour1(behaviour1),
            m_operandParam(operandParam),
            m_opcodeKind(opcodeKind),
            m_length(length),
            m_byte1(byte1),
            m_byte2(byte2),
            m_controlFlow(controlFlow), 
            m_cstr(cstr)
        { }

    private:
        OpCodeTypes m_type;
        std::wstring m_name; 
        StackBehaviour m_behaviour0;
        StackBehaviour m_behaviour1;
        OperandParam m_operandParam;
        OpCodeKind m_opcodeKind;
        BYTE m_length;
        BYTE m_byte1;
        BYTE m_byte2;
        ControlFlow m_controlFlow;
        std::wstring m_cstr;
    };

    namespace OpCodeDetail {

        template<int type>
        class OpCode_;
#define Pop0 StackBehaviours::Pop0()
#define Pop1 StackBehaviours::Pop1()
#define PopI StackBehaviours::PopI()
#define PopI8 StackBehaviours::PopI8()
#define PopR4 StackBehaviours::PopR4()
#define PopR8 StackBehaviours::PopR8()
#define PopRef StackBehaviours::PopRef()
#define Push0 StackBehaviours::Push0()
#define Push1 StackBehaviours::Push1()
#define PushI StackBehaviours::PushI()
#define PushI8 StackBehaviours::PushI8()
#define PushR4 StackBehaviours::PushR4()
#define PushR8 StackBehaviours::PushR8()
#define PushRef StackBehaviours::PushRef()
#define VarPop StackBehaviours::VarPop()
#define VarPush StackBehaviours::VarPush()
#define InlineBrTarget OperandParams::InlineBrTarget()
#define InlineField OperandParams::InlineField()
#define InlineI OperandParams::InlineI()
#define InlineI8 OperandParams::InlineI8()
#define InlineMethod OperandParams::InlineMethod()
#define InlineNone OperandParams::InlineNone()
#define InlineR OperandParams::InlineR()
#define InlineSig OperandParams::InlineSig()
#define InlineString OperandParams::InlineString()
#define InlineSwitch OperandParams::InlineSwitch()
#define InlineTok OperandParams::InlineTok()
#define InlineType OperandParams::InlineType()
#define InlineVar OperandParams::InlineVar()
#define ShortInlineBrTarget OperandParams::ShortInlineBrTarget()
#define ShortInlineI OperandParams::ShortInlineI()
#define ShortInlineR OperandParams::ShortInlineR()
#define ShortInlineVar OperandParams::ShortInlineVar()
#define IInternal OpCodeKinds::IInternal()
#define IMacro OpCodeKinds::IMacro()
#define IObjModel OpCodeKinds::IObjModel()
#define IPrefix OpCodeKinds::IPrefix()
#define IPrimitive OpCodeKinds::IPrimitive()
#define BRANCH ControlFlows::Branch()
#define BREAK ControlFlows::Break()
#define CALL ControlFlows::Call()
#define COND_BRANCH ControlFlows::CondBranch()
#define META ControlFlows::Meta()
#define NEXT ControlFlows::Next()
#define RETURN ControlFlows::Return()
#define THROW ControlFlows::Throw()
#define OPDEF(canonicalName, stringName, stackBehaviour0, stackBehaviour1, \
                operandParam, opcodeKind, length, byte1, byte2, controlFlow) \
        template<> \
        class OpCode_<OpCodeTypes::canonicalName> : public OpCode \
        { \
        public: \
            OpCode_() : \
                OpCode(OpCodeTypes::canonicalName, L"" L##stringName L"", \
                                    stackBehaviour0, stackBehaviour1, \
                                    operandParam, opcodeKind, \
                                    length, byte1, byte2, controlFlow, \
                                    L"" L#canonicalName L"," L##stringName L"," \
                                    L#stackBehaviour0 L"," L#stackBehaviour1 L"," \
                                    L#operandParam L"," L#opcodeKind L"," \
                                    L#length L"," L#byte1 L"," L#byte2 L"," L#controlFlow L"") \
            { } \
        };
#include "opcode.def"
#undef THROW
#undef RETURN
#undef NEXT
#undef META
#undef COND_BRANCH
#undef CALL
#undef BREAK
#undef BRANCH
#undef OPDEF
#undef IPrimitive
#undef IPrefix
#undef IObjModel
#undef IMacro
#undef IInternal
#undef ShortInlineVar
#undef ShortInlineR
#undef ShortInlineI
#undef ShortInlineBrTarget
#undef InlineVar
#undef InlineType
#undef InlineTok
#undef InlineSwitch
#undef InlineString
#undef InlineSig
#undef InlineR
#undef InlineNone
#undef InlineMethod
#undef InlineI8
#undef InlineI
#undef InlineField
#undef InlineBrTarget
#undef VarPush
#undef VarPop
#undef PushRef
#undef PushR8
#undef PushR4
#undef PushI8
#undef PushI
#undef Push1
#undef Push0
#undef PopRef
#undef PopR8
#undef PopR4
#undef PopI8
#undef PopI
#undef Pop1
#undef Pop0
    }   // namespace OpCodeDetail {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPCODE_H
