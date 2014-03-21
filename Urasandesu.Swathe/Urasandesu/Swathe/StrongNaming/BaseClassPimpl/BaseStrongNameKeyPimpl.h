/* 
 * File: BaseStrongNameKeyPimpl.h
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPL_H
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPIMPLFACADE_STRONGNAMEKEYPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPimplFacade/StrongNameKeyPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPLFWD_H
#include <Urasandesu/Swathe/StrongNaming/BaseClassPimpl/BaseStrongNameKeyPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

    using std::unique_ptr;
    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseStrongNameKeyPimpl
    {
    public:
        SWATHE_BEGIN_STRONG_NAME_KEY_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_STRONG_NAME_KEY_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_STRONG_NAME_KEY_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseStrongNameKeyPimpl(strong_name_key_label_type *pClass);

        void Initialize(strong_name_info_label_type *pSnInfo);
        vector<BYTE> const &GetKeyPair() const;
        vector<BYTE> const &GetPublicKey() const;
        vector<BYTE> const &GetPublicKeyToken() const;
        DWORD GetSignatureSize() const;
        PublicKeyBlob const &GetPublicKeyBlob() const;
        DWORD GetPublicKeyBlobSize() const;
        
    private:
        void SetPath(wstring const &path);
        void SetPublicKeyBlob(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize) const;
        void SetPublicKeyToken(void const *pToken, DWORD tokenSize);

        mutable strong_name_key_label_type *m_pClass;
        strong_name_info_label_type *m_pSnInfo;
        wstring m_path;
        mutable unique_ptr<PublicKeyBlob> m_pPubKeyBlob;
        mutable DWORD m_pubKeyBlobSize;
        mutable bool m_keyPairInit;
        mutable vector<BYTE> m_keyPair;
        mutable bool m_publicKeyInit;
        mutable vector<BYTE> m_publicKey;
        mutable bool m_publicKeyTokenInit;
        mutable vector<BYTE> m_publicKeyToken;
        mutable DWORD m_sigSize;
        int m_reserved;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEKEYPIMPL_H

