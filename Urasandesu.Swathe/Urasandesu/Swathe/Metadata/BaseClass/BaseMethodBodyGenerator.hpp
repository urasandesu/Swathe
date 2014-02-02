/* 
 * File: BaseMethodBodyGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseMethodBodyGenerator<ApiHolder>::BaseMethodBodyGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(method_body_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(method_body_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())method_body_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseMethodBodyGenerator<ApiHolder>::~BaseMethodBodyGenerator()
    {
        Pimpl()->~method_body_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseMethodBodyGenerator<ApiHolder>::method_body_generator_pimpl_label_type *BaseMethodBodyGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<class_pimpl_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMethodBodyGenerator<ApiHolder>::method_body_generator_pimpl_label_type const *BaseMethodBodyGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_METHOD_BODY_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdToken BaseMethodBodyGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }
    
    template<class ApiHolder>    
    CallingConventions BaseMethodBodyGenerator<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }
    
    template<class ApiHolder>    
    vector<ILocal const *> const &BaseMethodBodyGenerator<ApiHolder>::GetLocals() const
    {
        return Pimpl()->GetLocals();
    }
    
    template<class ApiHolder>    
    IInstructionPtrRange BaseMethodBodyGenerator<ApiHolder>::GetInstructions() const
    {
        return Pimpl()->GetInstructions();
    }

    template<class ApiHolder>    
    vector<ExceptionClause> const &BaseMethodBodyGenerator<ApiHolder>::GetExceptionClauses() const
    {
        return Pimpl()->GetExceptionClauses();
    }

    template<class ApiHolder>    
    Signature const &BaseMethodBodyGenerator<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodBodyGenerator<ApiHolder>::GetMethod() const
    {
        return Pimpl()->GetMethod();
    }

    template<class ApiHolder>    
    COR_ILMETHOD_FAT const &BaseMethodBodyGenerator<ApiHolder>::GetRawHeader() const
    {
        return Pimpl()->GetRawHeader();
    }

    template<class ApiHolder>    
    vector<BYTE> const &BaseMethodBodyGenerator<ApiHolder>::GetRawBody() const
    {
        return Pimpl()->GetRawBody();
    }

    template<class ApiHolder>    
    UINT BaseMethodBodyGenerator<ApiHolder>::GetRawBodyMaxStack() const
    {
        return Pimpl()->GetRawBodyMaxStack();
    }

    template<class ApiHolder>    
    vector<COR_ILMETHOD_SECT_EH_CLAUSE_FAT> const &BaseMethodBodyGenerator<ApiHolder>::GetRawEHClauses() const
    {
        return Pimpl()->GetRawEHClauses();
    }

    template<class ApiHolder>    
    IAssembly const *BaseMethodBodyGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IDispenser const *BaseMethodBodyGenerator<ApiHolder>::GetDispenser() const
    {
        return Pimpl()->GetDispenser();
    }

    template<class ApiHolder>    
    IMethodBody const *BaseMethodBodyGenerator<ApiHolder>::GetSourceMethodBody() const
    {
        return Pimpl()->GetSourceMethodBody();
    }

    template<class ApiHolder>    
    ILocal const *BaseMethodBodyGenerator<ApiHolder>::GetLocal(ULONG index, IType const *pLocalType) const
    {
        return Pimpl()->GetLocal(index, pLocalType);
    }

    template<class ApiHolder>    
    IInstructionPtrRange::iterator BaseMethodBodyGenerator<ApiHolder>::GetInstructionIterator(ULONG offset) const
    {
        return Pimpl()->GetInstructionIterator(offset);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, ILocal const *pLocal)
    {
        Pimpl()->Emit(opCode, pLocal);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, wstring const &s)
    {
        Pimpl()->Emit(opCode, s);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, IType const *pType)
    {
        Pimpl()->Emit(opCode, pType);
    }
    
    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, Label const &label)
    {
        Pimpl()->Emit(opCode, label);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, IMethod const *pMethod)
    {
        Pimpl()->Emit(opCode, pMethod);
    }
    
    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, IField const *pField)
    {
        Pimpl()->Emit(opCode, pField);
    }
    
    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, BYTE arg)
    {
        Pimpl()->Emit(opCode, arg);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, SHORT arg)
    {
        Pimpl()->Emit(opCode, arg);
    }
    
    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode, INT arg)
    {
        Pimpl()->Emit(opCode, arg);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(OpCode const &opCode)
    {
        Pimpl()->Emit(opCode);
    }
    
    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Emit(IInstruction const *pInst)
    {
        Pimpl()->Emit(pInst);
    }

    template<class ApiHolder>    
    typename BaseMethodBodyGenerator<ApiHolder>::local_generator_label_type *BaseMethodBodyGenerator<ApiHolder>::DefineLocal(IType const *pLocalType)
    {
        return Pimpl()->DefineLocal(pLocalType);
    }
    
    template<class ApiHolder>    
    Label BaseMethodBodyGenerator<ApiHolder>::DefineLabel()
    {
        return Pimpl()->DefineLabel();
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::MarkLabel(Label const &label)
    {
        Pimpl()->MarkLabel(label);
    }

    template<class ApiHolder>    
    Label BaseMethodBodyGenerator<ApiHolder>::BeginExceptionBlock()
    {
        return Pimpl()->BeginExceptionBlock();
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::BeginCatchBlock(IType const *pExType)
    {
        Pimpl()->BeginCatchBlock(pExType);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::BeginFinallyBlock()
    {
        Pimpl()->BeginFinallyBlock();
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::EndExceptionBlock()
    {
        Pimpl()->EndExceptionBlock();
    }

    template<class ApiHolder>    
    ExceptionClause BaseMethodBodyGenerator<ApiHolder>::DefineExceptionClause(ExceptionClause const &exClause, SIZE_T offset)
    {
        return Pimpl()->DefineExceptionClause(exClause, offset);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::SetSourceMethodBody(IMethodBody const *pSrcBody)
    {
        Pimpl()->SetSourceMethodBody(pSrcBody);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::SetMethod(IMethod const *pMethod)
    {
        Pimpl()->SetMethod(pMethod);
    }

    template<class ApiHolder>    
    typename BaseMethodBodyGenerator<ApiHolder>::instruction_generator_label_type const *BaseMethodBodyGenerator<ApiHolder>::GetInstruction(Label const &label) const
    {
        return Pimpl()->GetInstruction(label);
    }

    template<class ApiHolder>    
    void BaseMethodBodyGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_HPP

