/* 
 * File: BaseStrongNameInfo.hpp
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEINFO_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEINFO_HPP

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEINFO_H
#include <Urasandesu/Swathe/StrongNaming/BaseClass/BaseStrongNameInfo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClass { 

    template<class ApiHolder>    
    BaseStrongNameInfo<ApiHolder>::BaseStrongNameInfo()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(strong_name_info_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(strong_name_info_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())strong_name_info_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseStrongNameInfo<ApiHolder>::~BaseStrongNameInfo()
    {
        Pimpl()->~strong_name_info_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseStrongNameInfo<ApiHolder>::strong_name_info_pimpl_label_type *BaseStrongNameInfo<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<strong_name_info_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseStrongNameInfo<ApiHolder>::strong_name_info_pimpl_label_type const *BaseStrongNameInfo<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_STRONG_NAME_INFO_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseStrongNameInfo<ApiHolder>::Initialize(runtime_host_label_type *pRuntime)
    {
        Pimpl()->Initialize(pRuntime);
    }

    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> BaseStrongNameInfo<ApiHolder>::NewStrongNameKey(wstring const &path) const
    {
        return Pimpl()->NewStrongNameKey(path);
    }

    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> BaseStrongNameInfo<ApiHolder>::NewStrongNameKey(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize) const
    {
        return Pimpl()->NewStrongNameKey(pubKeyBlob, pubKeyBlobSize);
    }

    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> BaseStrongNameInfo<ApiHolder>::NewStrongNameKeyWithToken(void const *pToken, DWORD tokenSize) const
    {
        return Pimpl()->NewStrongNameKeyWithToken(pToken, tokenSize);
    }

    template<class ApiHolder>    
    void BaseStrongNameInfo<ApiHolder>::SetSignature(wstring const &path, IStrongNameKey const *pSnKey) const
    {
        Pimpl()->SetSignature(path, pSnKey);
    }

    template<class ApiHolder>    
    ICLRStrongName &BaseStrongNameInfo<ApiHolder>::GetCOMStrongName() const
    {
        return Pimpl()->GetCOMStrongName();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEINFO_HPP

