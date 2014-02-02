/* 
 * File: BaseLocalMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseLocalMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseLocalMetadata<ApiHolder>::BaseLocalMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(local_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(local_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())local_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseLocalMetadata<ApiHolder>::~BaseLocalMetadata()
    {
        Pimpl()->~local_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseLocalMetadata<ApiHolder>::local_metadata_pimpl_label_type *BaseLocalMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<local_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseLocalMetadata<ApiHolder>::local_metadata_pimpl_label_type const *BaseLocalMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_LOCAL_METADATA_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseLocalMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdToken BaseLocalMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    SIZE_T BaseLocalMetadata<ApiHolder>::GetLocalIndex() const
    {
        return Pimpl()->GetLocalIndex();
    }

    template<class ApiHolder>    
    IType const *BaseLocalMetadata<ApiHolder>::GetLocalType() const
    {
        return Pimpl()->GetLocalType();
    }

    template<class ApiHolder>    
    Signature const &BaseLocalMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }
    
    template<class ApiHolder>    
    IMethodBody const *BaseLocalMetadata<ApiHolder>::GetMethodBody() const
    {
        return Pimpl()->GetMethodBody();
    }

    template<class ApiHolder>    
    IAssembly const *BaseLocalMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    void BaseLocalMetadata<ApiHolder>::SetMethodBody(IMethodBody const *pBody)
    {
        Pimpl()->SetMethodBody(pBody);
    }

    template<class ApiHolder>    
    void BaseLocalMetadata<ApiHolder>::SetLocalIndex(ULONG index)
    {
        Pimpl()->SetLocalIndex(index);
    }

    template<class ApiHolder>    
    void BaseLocalMetadata<ApiHolder>::SetLocalType(IType const *pLocalType)
    {
        Pimpl()->SetLocalType(pLocalType);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_HPP

