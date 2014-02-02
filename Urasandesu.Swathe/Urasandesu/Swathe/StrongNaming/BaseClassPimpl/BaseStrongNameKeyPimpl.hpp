/* 
 * File: BaseStrongNameKeyPimpl.hpp
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPL_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPL_HPP

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPL_H
#include <Urasandesu/Swathe/StrongNaming/BaseClassPimpl/BaseStrongNameKeyPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseStrongNameKeyPimpl<ApiHolder>::BaseStrongNameKeyPimpl(strong_name_key_label_type *pClass) : 
        m_pClass(pClass), 
        m_pubKeyBlobSize(static_cast<DWORD>(-1)), 
        m_keyPairInit(false), 
        m_publicKeyInit(false), 
        m_publicKeyTokenInit(false), 
        m_sigSize(0ul)
    { }
    
#define SWATHE_DECLARE_BASE_STRONG_NAME_KEY_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    vector<BYTE> const &BaseStrongNameKeyPimpl<ApiHolder>::GetKeyPair() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::CppAnonymSystemException;

        if (!m_keyPairInit)
        {
            _ASSERTE(!m_path.empty());

            auto *pPubKeyBlob = static_cast<PublicKeyBlob *>(nullptr);
            auto pubKeyBlobSize = 0ul;
            auto hSnk = ::CreateFileW(m_path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, 
                                      OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
            if (hSnk == INVALID_HANDLE_VALUE)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
            BOOST_SCOPE_EXIT((&hSnk))
            {
                ::CloseHandle(hSnk);
            }
            BOOST_SCOPE_EXIT_END
            
            auto keyPairSize = ::GetFileSize(hSnk, NULL);
            if (keyPairSize == -1)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            if (keyPairSize != 0)
            {
                m_keyPair.resize(keyPairSize);
                if (::ReadFile(hSnk, &m_keyPair[0], keyPairSize, &keyPairSize, NULL) == FALSE)
                    BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
            }
            
            m_keyPairInit = true;
        }
        return m_keyPair;
    }



    template<class ApiHolder>    
    vector<BYTE> const &BaseStrongNameKeyPimpl<ApiHolder>::GetPublicKey() const
    {
        if (!m_publicKeyInit)
        {
            auto const &pubKeyBlob = GetPublicKeyBlob();
            m_publicKey.reserve(pubKeyBlob.cbPublicKey);
            auto const *pPubKey = reinterpret_cast<BYTE const *>(pubKeyBlob.PublicKey);
            m_publicKey.assign(pPubKey, pPubKey + pubKeyBlob.cbPublicKey);
            
            m_publicKeyInit = true;
        }
        return m_publicKey;
    }



    template<class ApiHolder>    
    vector<BYTE> const &BaseStrongNameKeyPimpl<ApiHolder>::GetPublicKeyToken() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        if (!m_publicKeyTokenInit)
        {
            auto const &pubKeyBlob = GetPublicKeyBlob();
            auto pubKeyBlobSize = GetPublicKeyBlobSize();
            auto *pPubKeyToken = static_cast<BYTE *>(nullptr);
            auto pubKeyTokenSize = 0ul;
            if (!::StrongNameTokenFromPublicKey(reinterpret_cast<BYTE *>(const_cast<PublicKeyBlob *>(&pubKeyBlob)), 
                                                pubKeyBlobSize, 
                                                &pPubKeyToken, 
                                                &pubKeyTokenSize))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(::StrongNameErrorInfo()));
            BOOST_SCOPE_EXIT((pPubKeyToken))
            {
                ::StrongNameFreeBuffer(pPubKeyToken);
            }
            BOOST_SCOPE_EXIT_END
                    
            m_publicKeyToken.reserve(pubKeyTokenSize);
            m_publicKeyToken.assign(pPubKeyToken, pPubKeyToken + pubKeyTokenSize);
            
            m_publicKeyTokenInit = true;
        }
        return m_publicKeyToken;
    }

    
    
    template<class ApiHolder>    
    DWORD BaseStrongNameKeyPimpl<ApiHolder>::GetSignatureSize() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_sigSize == 0ul)
        {
            auto const &pubKeyBlob = GetPublicKeyBlob();
            auto pubKeyBlobSize = GetPublicKeyBlobSize();
            if (!::StrongNameSignatureSize(reinterpret_cast<BYTE *>(const_cast<PublicKeyBlob *>(&pubKeyBlob)), 
                                           pubKeyBlobSize, 
                                           &m_sigSize))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(::StrongNameErrorInfo()));
        }
        return m_sigSize;
    }



    template<class ApiHolder>    
    PublicKeyBlob const &BaseStrongNameKeyPimpl<ApiHolder>::GetPublicKeyBlob() const
    {
        if (m_pubKeyBlobSize == static_cast<DWORD>(-1))
            GetPublicKeyBlobSize();
        return *m_pPubKeyBlob.get();
    }



    template<class ApiHolder>    
    DWORD BaseStrongNameKeyPimpl<ApiHolder>::GetPublicKeyBlobSize() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pubKeyBlobSize == static_cast<DWORD>(-1))
        {
            auto const &keyPair = GetKeyPair();
            auto *pPubKeyBlob = static_cast<PublicKeyBlob *>(nullptr);
            auto pubKeyBlobSize = 0ul;
            if (!::StrongNameGetPublicKey(NULL, 
                                          const_cast<BYTE *>(&keyPair[0]), 
                                          keyPair.size(), 
                                          reinterpret_cast<BYTE **>(&pPubKeyBlob), 
                                          &pubKeyBlobSize))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(::StrongNameErrorInfo()));
            BOOST_SCOPE_EXIT((&pubKeyBlobSize)(&pPubKeyBlob))
            {
                if (pubKeyBlobSize)
                    ::StrongNameFreeBuffer(reinterpret_cast<BYTE *>(pPubKeyBlob));
            }
            BOOST_SCOPE_EXIT_END

            SetPublicKeyBlob(*pPubKeyBlob, pubKeyBlobSize);
        }
        return m_pubKeyBlobSize;
    }



    template<class ApiHolder>    
    void BaseStrongNameKeyPimpl<ApiHolder>::SetPath(wstring const &path)
    {
        _ASSERTE(!path.empty());
        _ASSERTE(m_path.empty());
        m_path = path;
    }



    template<class ApiHolder>    
    void BaseStrongNameKeyPimpl<ApiHolder>::SetPublicKeyBlob(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize) const
    {
        m_pPubKeyBlob = unique_ptr<PublicKeyBlob>(reinterpret_cast<PublicKeyBlob *>(new BYTE[pubKeyBlobSize]));
        ::memcpy_s(m_pPubKeyBlob.get(), pubKeyBlobSize, &pubKeyBlob, pubKeyBlobSize);

        _ASSERTE(pubKeyBlobSize != static_cast<DWORD>(-1));
        _ASSERTE(m_pubKeyBlobSize == static_cast<DWORD>(-1));
        m_pubKeyBlobSize = pubKeyBlobSize;
    }



    template<class ApiHolder>    
    void BaseStrongNameKeyPimpl<ApiHolder>::SetPublicKeyToken(void const *pToken, DWORD tokenSize)
    {
        m_publicKeyToken.resize(tokenSize);
        auto const *pBuf = reinterpret_cast<BYTE const *>(pToken);
        m_publicKeyToken.assign(pBuf, pBuf + tokenSize);
        m_publicKeyTokenInit = true;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPL_HPP

