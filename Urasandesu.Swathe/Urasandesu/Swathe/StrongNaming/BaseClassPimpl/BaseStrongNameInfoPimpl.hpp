/* 
 * File: BaseStrongNameInfoPimpl.hpp
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPL_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPL_HPP

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPL_H
#include <Urasandesu/Swathe/StrongNaming/BaseClassPimpl/BaseStrongNameInfoPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseStrongNameInfoPimpl<ApiHolder>::BaseStrongNameInfoPimpl(strong_name_info_label_type *pClass) : 
        m_pClass(pClass), 
        m_pRuntime(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseStrongNameInfoPimpl<ApiHolder>::~BaseStrongNameInfoPimpl()
    {
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseStrongNameInfoPimpl<ApiHolder>::base_heap_provider_type *BaseStrongNameInfoPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseStrongNameInfoPimpl<ApiHolder>::base_heap_provider_type const *BaseStrongNameInfoPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_STRONG_NAME_INFO_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> BaseStrongNameInfoPimpl<ApiHolder>::NewStrongNameKey(wstring const &path) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<strong_name_key_label_type>();
        auto pSnKey = provider.NewObject();
        pSnKey->SetPath(path);
        return pSnKey;
    }



    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> BaseStrongNameInfoPimpl<ApiHolder>::NewStrongNameKey(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<strong_name_key_label_type>();
        auto pSnKey = provider.NewObject();
        pSnKey->SetPublicKeyBlob(pubKeyBlob, pubKeyBlobSize);
        return pSnKey;
    }



    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> BaseStrongNameInfoPimpl<ApiHolder>::NewStrongNameKeyWithToken(void const *pToken, DWORD tokenSize) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<strong_name_key_label_type>();
        auto pSnKey = provider.NewObject();
        pSnKey->SetPublicKeyToken(pToken, tokenSize);
        return pSnKey;
    }



    template<class ApiHolder>    
    void BaseStrongNameInfoPimpl<ApiHolder>::SetSignature(wstring const &path, IStrongNameKey const *pSnKey) const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto const &keyPair = pSnKey->GetKeyPair();
        if (!::StrongNameSignatureGenerationEx(path.c_str(), NULL, const_cast<BYTE *>(&keyPair[0]), keyPair.size(), NULL, NULL, 0))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(::StrongNameErrorInfo()));
    }



    template<class ApiHolder>    
    void BaseStrongNameInfoPimpl<ApiHolder>::Initialize(runtime_host_label_type const *pRuntime)
    {
        _ASSERTE(m_pRuntime == nullptr);
        _ASSERTE(pRuntime != nullptr);
        m_pRuntime = pRuntime;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPL_HPP

