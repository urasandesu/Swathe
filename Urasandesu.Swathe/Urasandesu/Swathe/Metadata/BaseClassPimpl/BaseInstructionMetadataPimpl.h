/* 
 * File: BaseInstructionMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_INSTRUCTIONMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/InstructionMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseInstructionMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTION_H
#include <Urasandesu/Swathe/Metadata/IInstruction.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODES_H
#include <Urasandesu/Swathe/Metadata/OpCodes.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using std::vector;
    using std::wstring;
    
    template<
        class ApiHolder
    >    
    class BaseInstructionMetadataPimpl
    {
    public:
        SWATHE_BEGIN_INSTRUCTION_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_INSTRUCTION_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_INSTRUCTION_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseInstructionMetadataPimpl(instruction_metadata_label_type *pClass);

        void Initialize(assembly_metadata_label_type *pAsm);
        mdToken GetToken() const;
        OpCode const &GetOpCode() const;
        Operand const &GetOperand() const;
        SIZE_T GetSize() const;
        UINT GetPopingCount() const;
        UINT GetPushingCount() const;
        vector<BYTE> const &GetRawData() const;
        
    private:
        void SetMethodBody(method_body_metadata_label_type *pBody);
        void SetIndex(SIZE_T index);
        void Reset();
        ULONG TakeRawData(BYTE const *i, BYTE const *i_end);
        static ULONG TakeInlineMethod(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand);
        static ULONG TakeInlineString(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand);
        static ULONG TakeInlineType(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand);
        static ULONG TakeShortInlineBrTarget(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand);
        static ULONG TakeShortInlineI(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand);
        static ULONG TakeShortInlineVar(instruction_metadata_pimpl_label_type const *_this, BYTE const *i, BYTE const *i_end, Operand &operand);

        mutable instruction_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        method_body_metadata_label_type *m_pBody;
        mutable mdToken m_mdt;
        OpCode const *m_pOpCode;
        Operand m_operand;
        mutable bool m_popingCountInit;
        mutable UINT m_popingCount;
        mutable bool m_pushingCountInit;
        mutable UINT m_pushingCount;
        SIZE_T m_index;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONMETADATAPIMPL_H

