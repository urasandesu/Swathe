/* 
 * File: BaseMethodBodyGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METHODBODYGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/MethodBodyGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodBodyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODES_H
#include <Urasandesu/Swathe/Metadata/OpCodes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTION_H
#include <Urasandesu/Swathe/Metadata/IInstruction.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_EXCEPTIONCLAUSE_H
#include <Urasandesu/Swathe/Metadata/ExceptionClause.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALFWD_H
#include <Urasandesu/Swathe/Metadata/ILocalFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LABEL_H
#include <Urasandesu/Swathe/Metadata/Label.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::any_range;
    using boost::random_access_traversal_tag;
    using std::ptrdiff_t;
    using boost::aligned_storage;
    using boost::apply_visitor;
    using boost::shared_ptr;
    using boost::static_visitor;
    using std::pair;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMethodBodyGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_METHOD_BODY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_BODY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_BODY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseMethodBodyGeneratorPimpl(method_body_generator_label_type *pClass);
        ~BaseMethodBodyGeneratorPimpl();

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        CallingConventions GetCallingConvention() const;
        vector<ILocal const *> const &GetLocals() const;
        IInstructionPtrRange GetInstructions() const;
        vector<ExceptionClause> const &GetExceptionClauses() const;
        Signature const &GetSignature() const;
        IMethod const *GetMethod() const;
        COR_ILMETHOD_FAT const &GetRawHeader() const;
        vector<BYTE> const &GetRawBody() const;
        UINT GetRawBodyMaxStack() const;
        vector<COR_ILMETHOD_SECT_EH_CLAUSE_FAT> const &GetRawEHClauses() const;
        IAssembly const *GetAssembly() const;
        IMethodBody const *GetSourceMethodBody() const;
        bool Equals(IMethodBody const *pBody) const;
        size_t GetHashCode() const;
        ILocal const *GetLocal(ULONG index, IType const *pLocalType) const;
        IInstructionPtrRange::iterator GetInstructionIterator(ULONG offset) const;
        void Emit(OpCode const &opCode, ILocal const *pLocal);
        void Emit(OpCode const &opCode, wstring const &s);
        void Emit(OpCode const &opCode, IType const *pType);
        void Emit(OpCode const &opCode, Label const &label);
        void Emit(OpCode const &opCode, IMethod const *pMethod);
        void Emit(OpCode const &opCode, IField const *pField);
        void Emit(OpCode const &opCode, BYTE arg);
        void Emit(OpCode const &opCode, DOUBLE arg);
        void Emit(OpCode const &opCode, SHORT arg);
        void Emit(OpCode const &opCode, INT arg);
        void Emit(OpCode const &opCode, LONGLONG arg);
        void Emit(OpCode const &opCode, vector<INT> const &offsets);
        void Emit(OpCode const &opCode, vector<Label> const &labels);
        void Emit(OpCode const &opCode, FLOAT arg);
        void Emit(OpCode const &opCode);
        void Emit(IInstruction const *pInst);
        local_generator_label_type *DefineLocal(IType const *pLocalType);
        Label DefineLabel();
        void MarkLabel(Label const &label);
        Label BeginExceptionBlock();
        void BeginCatchBlock(IType const *pExType);
        void BeginFinallyBlock();
        void EndExceptionBlock();
        ExceptionClause DefineExceptionClause(ExceptionClause const &exClause, SIZE_T offset);
        
    private:
        struct emit_instruction_visitor;
        class exception_clause_marker;
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        SIZE_T GetSize() const;
        instruction_generator_label_type *NewInstructionGeneratorCore() const;
        void SetSourceMethodBody(IMethodBody const *pSrcBody);
        void SetMethod(IMethod const *pMethod);
        instruction_generator_label_type const *GetInstruction(Label const &label) const;
        void Accept(IMetadataVisitor *pVisitor) const;

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 16;
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable method_body_generator_label_type *m_pClass;
        mutable assembly_generator_label_type *m_pAsmGen;
        mutable IMethod const *m_pMethod;
        mutable mdToken m_mdt;
        mutable vector<ILocal const *> m_locals;
        mutable Signature m_sig;
        mutable bool m_rawHeaderInit;
        mutable COR_ILMETHOD_FAT m_rawHeader;
        mutable bool m_rawBodyMaxStackInit;
        mutable UINT m_rawBodyMaxStack;
        mutable bool m_rawBodyInit;
        mutable vector<BYTE> m_rawBody;
        mutable bool m_rawEHClausesInit;
        mutable vector<COR_ILMETHOD_SECT_EH_CLAUSE_FAT> m_rawEHClauses;
        IMethodBody const *m_pSrcBody;
        mutable vector<SIZE_T> m_labeledInstIndexes;
        mutable vector<exception_clause_marker> m_exClauseMarkerStack;
        mutable vector<exception_clause_marker> m_endedExClauseMarkers;
        mutable bool m_exClausesInit;
        mutable vector<ExceptionClause> m_exClauses;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYGENERATORPIMPL_H

