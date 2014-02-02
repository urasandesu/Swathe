/* 
 * File: BaseMethodBodyMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseMethodBodyMetadata<ApiHolder>::BaseMethodBodyMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(method_body_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(method_body_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())method_body_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseMethodBodyMetadata<ApiHolder>::~BaseMethodBodyMetadata()
    {
        Pimpl()->~method_body_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseMethodBodyMetadata<ApiHolder>::method_body_metadata_pimpl_label_type *BaseMethodBodyMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<method_body_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMethodBodyMetadata<ApiHolder>::method_body_metadata_pimpl_label_type const *BaseMethodBodyMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_METHOD_BODY_METADATA_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseMethodBodyMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdToken BaseMethodBodyMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    CallingConventions BaseMethodBodyMetadata<ApiHolder>::GetCallingConvention() const
    {
        return Pimpl()->GetCallingConvention();
    }

    template<class ApiHolder>    
    vector<ILocal const *> const &BaseMethodBodyMetadata<ApiHolder>::GetLocals() const
    {
        return Pimpl()->GetLocals();
    }

    template<class ApiHolder>    
    IInstructionPtrRange BaseMethodBodyMetadata<ApiHolder>::GetInstructions() const
    {
        return Pimpl()->GetInstructions();
    }

    template<class ApiHolder>    
    vector<ExceptionClause> const &BaseMethodBodyMetadata<ApiHolder>::GetExceptionClauses() const
    {
        return Pimpl()->GetExceptionClauses();
    }

    template<class ApiHolder>    
    Signature const &BaseMethodBodyMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseMethodBodyMetadata<ApiHolder>::GetMethod() const
    {
        return Pimpl()->GetMethod();
    }

    template<class ApiHolder>    
    COR_ILMETHOD_FAT const &BaseMethodBodyMetadata<ApiHolder>::GetRawHeader() const
    {
        return Pimpl()->GetRawHeader();
    }

    template<class ApiHolder>    
    vector<BYTE> const &BaseMethodBodyMetadata<ApiHolder>::GetRawBody() const
    {
        return Pimpl()->GetRawBody();
    }

    template<class ApiHolder>    
    UINT BaseMethodBodyMetadata<ApiHolder>::GetRawBodyMaxStack() const
    {
        return Pimpl()->GetRawBodyMaxStack();
    }

    template<class ApiHolder>    
    vector<COR_ILMETHOD_SECT_EH_CLAUSE_FAT> const &BaseMethodBodyMetadata<ApiHolder>::GetRawEHClauses() const
    {
        return Pimpl()->GetRawEHClauses();
    }

    template<class ApiHolder>    
    IAssembly const *BaseMethodBodyMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IDispenser const *BaseMethodBodyMetadata<ApiHolder>::GetDispenser() const
    {
        return Pimpl()->GetDispenser();
    }

    template<class ApiHolder>    
    IMethodBody const *BaseMethodBodyMetadata<ApiHolder>::GetSourceMethodBody() const
    {
        return Pimpl()->GetSourceMethodBody();
    }

    template<class ApiHolder>    
    ILocal const *BaseMethodBodyMetadata<ApiHolder>::GetLocal(ULONG index, IType const *pLocalType) const
    {
        return Pimpl()->GetLocal(index, pLocalType);
    }

    template<class ApiHolder>    
    IInstructionPtrRange::iterator BaseMethodBodyMetadata<ApiHolder>::GetInstructionIterator(ULONG offset) const
    {
        return Pimpl()->GetInstructionIterator(offset);
    }

    template<class ApiHolder>    
    void BaseMethodBodyMetadata<ApiHolder>::SetMethod(IMethod const *pMethod)
    {
        Pimpl()->SetMethod(pMethod);
    }

    template<class ApiHolder>    
    void BaseMethodBodyMetadata<ApiHolder>::SetILBody(COR_ILMETHOD *pILBody)
    {
        Pimpl()->SetILBody(pILBody);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYMETADATA_HPP

