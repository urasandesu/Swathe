/* 
 * File: BaseInstructionGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_INSTRUCTIONGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/InstructionGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseInstructionGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTION_H
#include <Urasandesu/Swathe/Metadata/IInstruction.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODES_H
#include <Urasandesu/Swathe/Metadata/OpCodes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::SimpleBlob;

    template<
        class ApiHolder
    >    
    class BaseInstructionGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_INSTRUCTION_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_INSTRUCTION_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_INSTRUCTION_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseInstructionGeneratorPimpl(instruction_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        OpCode const &GetOpCode() const;
        Operand const &GetOperand() const;
        SIZE_T GetSize() const;
        UINT GetPopingCount() const;
        UINT GetPushingCount() const;
        vector<BYTE> const &GetRawData() const;
        
    private:
        void SetMethodBody(method_body_generator_label_type *pBodyGen);
        void SetOpCode(OpCode const &opCode);
        void SetOperand(Operand const &operand);
        void SetIndex(SIZE_T index);
        void Reset();
        static void PutInlineBrTarget(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineField(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineI(Operand const &operand, SimpleBlob &blob);
        static void PutInlineI8(Operand const &operand, SimpleBlob &blob);
        static void PutInlineMethod(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineR(Operand const &operand, SimpleBlob &blob);
        static void PutInlineSignature(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineString(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineSwitch(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineToken(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineType(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutInlineVar(Operand const &operand, SimpleBlob &blob);
        static void PutShortInlineBrTarget(instruction_generator_pimpl_label_type const *_this, Operand const &operand, SimpleBlob &blob);
        static void PutShortInlineI(Operand const &operand, SimpleBlob &blob);
        static void PutShortInlineR(Operand const &operand, SimpleBlob &blob);
        static void PutShortInlineVar(Operand const &operand, SimpleBlob &blob);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable instruction_generator_label_type *m_pClass;
        assembly_generator_label_type *m_pAsmGen;
        method_body_generator_label_type *m_pBodyGen;
        mutable mdToken m_mdt;
        OpCode const *m_pOpCode;
        Operand m_operand;
        SIZE_T m_index;
        mutable bool m_popingCountInit;
        mutable UINT m_popingCount;
        mutable bool m_pushingCountInit;
        mutable UINT m_pushingCount;
        mutable bool m_rawDataInit;
        mutable vector<BYTE> m_rawData;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEINSTRUCTIONGENERATORPIMPL_H

