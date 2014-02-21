/* 
 * File: BaseMethodBodyMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METHODBODYMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/MethodBodyMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodBodyMetadataPimplFwd.h>
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

    using boost::aligned_storage;
    using boost::any_range;
    using boost::iterator_range;
    using boost::random_access_traversal_tag;
    using boost::shared_ptr;
    using std::pair;
    using std::ptrdiff_t;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    
    template<
        class ApiHolder
    >    
    class BaseMethodBodyMetadataPimpl
    {
    public:
        SWATHE_BEGIN_METHOD_BODY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_BODY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_BODY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseMethodBodyMetadataPimpl(method_body_metadata_label_type *pClass);
        ~BaseMethodBodyMetadataPimpl();

        void Initialize(assembly_metadata_label_type *pAsm);
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
        IDispenser const *GetDispenser() const;
        IMethodBody const *GetSourceMethodBody() const;
        ILocal const *GetLocal(ULONG index, IType const *pLocalType) const;
        IInstructionPtrRange::iterator GetInstructionIterator(ULONG offset) const;
        
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        instruction_metadata_label_type *NewInstructionCore() const;
        void SetMethod(IMethod const *pMethod);
        void SetILBody(COR_ILMETHOD *pILBody);
        static void FillMethodBodyProperties(IAssembly const *pAsm, IMethod const *pMethod, COR_ILMETHOD const *pILBody, mdToken &mdt, ULONG &headerSize, BYTE const *&pCode, ULONG &codeSize, ULONG &totalSize, COR_ILMETHOD_SECT const *&pSect);
        static void FillLocalsProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, Signature &sig);
        static void FillLocalsSigProperties(IMethodBody const *pBody, Signature const &sig, CallingConventions &callingConvention, vector<ILocal const *> &locals);

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 16;
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable method_body_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        IMethod const *m_pMethod;
        mutable mdToken m_mdt;
        mutable ULONG m_headerSize;
        mutable BYTE const *m_pCode;
        mutable ULONG m_codeSize;
        mutable ULONG m_totalSize;
        mutable COR_ILMETHOD_SECT const *m_pSect;
        mutable CallingConventions m_callingConvention;
        mutable bool m_localsInit;
        mutable vector<ILocal const *> m_locals;
        mutable Signature m_sig;
        mutable bool m_instsInit;
        mutable bool m_exClausesInit;
        mutable vector<ExceptionClause> m_exClauses;
        COR_ILMETHOD *m_pILBody;
        IMethodBody const *m_pSrcBody;

    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODBODYMETADATAPIMPL_H

