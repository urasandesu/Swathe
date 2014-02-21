/* 
 * File: BaseStrongNameKey.h
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEY_H
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEY_H

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSFACADE_STRONGNAMEKEYFACADE_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassFacade/StrongNameKeyFacade.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEYFWD_H
#include <Urasandesu/Swathe/StrongNaming/BaseClass/BaseStrongNameKeyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_ISTRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/IStrongNameKey.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClass { 

    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseStrongNameKey : 
        public IStrongNameKey
    {
    public:
        SWATHE_BEGIN_STRONG_NAME_KEY_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_STRONG_NAME_KEY_FACADE_TYPEDEF_ALIAS
        SWATHE_END_STRONG_NAME_KEY_FACADE_TYPEDEF_ALIAS
        
        BaseStrongNameKey();
        virtual ~BaseStrongNameKey();

        vector<BYTE> const &GetKeyPair() const;
        vector<BYTE> const &GetPublicKey() const;
        vector<BYTE> const &GetPublicKeyToken() const;
        DWORD GetSignatureSize() const;
        PublicKeyBlob const &GetPublicKeyBlob() const;
        DWORD GetPublicKeyBlobSize() const;
    
    private:
        strong_name_key_pimpl_label_type *Pimpl();
        strong_name_key_pimpl_label_type const *Pimpl() const;
        void SetPath(wstring const &path);
        void SetPublicKeyBlob(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize);
        void SetPublicKeyToken(void const *pToken, DWORD tokenSize);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 88;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASS_BASESTRONGNAMEKEY_H

