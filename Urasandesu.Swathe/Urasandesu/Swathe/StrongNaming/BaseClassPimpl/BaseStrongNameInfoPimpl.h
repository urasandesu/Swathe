/* 
 * File: BaseStrongNameInfoPimpl.h
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPL_H
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPIMPLFACADE_STRONGNAMEINFOPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPimplFacade/StrongNameInfoPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPLFWD_H
#include <Urasandesu/Swathe/StrongNaming/BaseClassPimpl/BaseStrongNameInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_ISTRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/IStrongNameKey.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;

    template<
        class ApiHolder
    >    
    class BaseStrongNameInfoPimpl
    {
    public:
        SWATHE_BEGIN_STRONG_NAME_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_STRONG_NAME_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_STRONG_NAME_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseStrongNameInfoPimpl(strong_name_info_label_type *pClass);
        ~BaseStrongNameInfoPimpl();

        AutoPtr<IStrongNameKey const> NewStrongNameKey(wstring const &path) const;
        AutoPtr<IStrongNameKey const> NewStrongNameKey(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize) const;
        AutoPtr<IStrongNameKey const> NewStrongNameKeyWithToken(void const *pToken, DWORD tokenSize) const;
        void SetSignature(wstring const &path, IStrongNameKey const *pSnKey) const;
        
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        void Initialize(runtime_host_label_type const *pRuntime);

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 40;
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable strong_name_info_label_type *m_pClass;
        runtime_host_label_type const *m_pRuntime;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASSPIMPL_BASESTRONGNAMEINFOPIMPL_H

