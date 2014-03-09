/* 
 * File: BaseMethodBodyGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODBODYGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/MethodBodyGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODY_H
#include <Urasandesu/Swathe/Metadata/IMethodBody.h>
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

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LABEL_H
#include <Urasandesu/Swathe/Metadata/Label.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using boost::any_range;
    using boost::random_access_traversal_tag;
    using std::ptrdiff_t;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMethodBodyGenerator : 
        public IMethodBody
    {
    public:
        SWATHE_BEGIN_METHOD_BODY_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_BODY_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_BODY_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseMethodBodyGenerator();
        ~BaseMethodBodyGenerator();

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
        ULONG GetHashCode() const;
        ILocal const *GetLocal(ULONG index, IType const *pLocalType) const;
        IInstructionPtrRange::iterator GetInstructionIterator(ULONG offset) const;
        void Emit(OpCode const &opCode, ILocal const *pLocal);        
        void Emit(OpCode const &opCode, wstring const &s);
        void Emit(OpCode const &opCode, IType const *pType);
        void Emit(OpCode const &opCode, Label const &label);
        void Emit(OpCode const &opCode, IMethod const *pMethod);
        void Emit(OpCode const &opCode, IField const *pField);
        void Emit(OpCode const &opCode, BYTE arg);
        void Emit(OpCode const &opCode, SHORT arg);
        void Emit(OpCode const &opCode, INT arg);
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
        method_body_generator_pimpl_label_type *Pimpl();
        method_body_generator_pimpl_label_type const *Pimpl() const;
        void SetSourceMethodBody(IMethodBody const *pSrcBody);
        void SetMethod(IMethod const *pMethod);
        instruction_generator_label_type const *GetInstruction(Label const &label) const;
        void Accept(IMetadataVisitor *pVisitor) const;

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 176;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_H

