/* 
 * File: BaseStrongNameKey.hpp
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEY_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEY_HPP

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/BaseClass/BaseStrongNameKey.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClass { 

    template<class ApiHolder>    
    BaseStrongNameKey<ApiHolder>::BaseStrongNameKey()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(strong_name_key_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(strong_name_key_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())strong_name_key_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseStrongNameKey<ApiHolder>::~BaseStrongNameKey()
    {
        Pimpl()->~strong_name_key_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseStrongNameKey<ApiHolder>::strong_name_key_pimpl_label_type *BaseStrongNameKey<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<strong_name_key_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseStrongNameKey<ApiHolder>::strong_name_key_pimpl_label_type const *BaseStrongNameKey<ApiHolder>::Pimpl() const
    {
        return const_cast<this_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_STRONG_NAME_KEY_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    vector<BYTE> const &BaseStrongNameKey<ApiHolder>::GetKeyPair() const
    {
        return Pimpl()->GetKeyPair();
    }

    template<class ApiHolder>    
    vector<BYTE> const &BaseStrongNameKey<ApiHolder>::GetPublicKey() const
    {
        return Pimpl()->GetPublicKey();
    }

    template<class ApiHolder>    
    vector<BYTE> const &BaseStrongNameKey<ApiHolder>::GetPublicKeyToken() const
    {
        return Pimpl()->GetPublicKeyToken();
    }

    template<class ApiHolder>    
    DWORD BaseStrongNameKey<ApiHolder>::GetSignatureSize() const
    {
        return Pimpl()->GetSignatureSize();
    }

    template<class ApiHolder>    
    PublicKeyBlob const &BaseStrongNameKey<ApiHolder>::GetPublicKeyBlob() const
    {
        return Pimpl()->GetPublicKeyBlob();
    }

    template<class ApiHolder>    
    DWORD BaseStrongNameKey<ApiHolder>::GetPublicKeyBlobSize() const
    {
        return Pimpl()->GetPublicKeyBlobSize();
    }

    template<class ApiHolder>    
    void BaseStrongNameKey<ApiHolder>::SetPath(wstring const &path)
    {
        Pimpl()->SetPath(path);
    }

    template<class ApiHolder>    
    void BaseStrongNameKey<ApiHolder>::SetPublicKeyBlob(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize)
    {
        Pimpl()->SetPublicKeyBlob(pubKeyBlob, pubKeyBlobSize);
    }

    template<class ApiHolder>    
    void BaseStrongNameKey<ApiHolder>::SetPublicKeyToken(void const *pToken, DWORD tokenSize)
    {
        Pimpl()->SetPublicKeyToken(pToken, tokenSize);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEY_HPP

