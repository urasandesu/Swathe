/* 
 * File: BaseMethodBodyMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODBODYMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/MethodBodyMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyMetadataFwd.h>
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
    class BaseMethodBodyMetadata : 
        public IMethodBody
    {
    public:
        SWATHE_BEGIN_METHOD_BODY_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_BODY_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_BODY_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseMethodBodyMetadata();
        ~BaseMethodBodyMetadata();
    
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
        method_body_metadata_pimpl_label_type *Pimpl();
        method_body_metadata_pimpl_label_type const *Pimpl() const;
        void SetMethod(IMethod const *pMethod);
        void SetILBody(COR_ILMETHOD *pILBody);
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_H

