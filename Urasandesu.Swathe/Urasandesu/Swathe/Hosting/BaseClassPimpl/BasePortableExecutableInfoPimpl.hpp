/* 
 * File: BasePortableExecutableInfoPimpl.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPL_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPL_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPL_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BasePortableExecutableInfoPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BasePortableExecutableInfoPimpl<ApiHolder>::BasePortableExecutableInfoPimpl(portable_executable_info_label_type *pClass) : 
        m_pClass(pClass), 
        m_pRuntime(nullptr), 
        m_hmodCorPE(nullptr), 
        m_pfnCreateCeeFileGen(nullptr), 
        m_pfnDestroyCeeFileGen(nullptr), 
        m_pCeeFileGen(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BasePortableExecutableInfoPimpl<ApiHolder>::~BasePortableExecutableInfoPimpl()
    {
        Finalize();
        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BasePortableExecutableInfoPimpl<ApiHolder>::base_heap_provider_type *BasePortableExecutableInfoPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BasePortableExecutableInfoPimpl<ApiHolder>::base_heap_provider_type const *BasePortableExecutableInfoPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_PORTABLE_EXECUTABLE_INFO_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    AutoPtr<typename BasePortableExecutableInfoPimpl<ApiHolder>::portable_executable_writer_label_type> BasePortableExecutableInfoPimpl<ApiHolder>::CreateWriter(IMetaDataEmit2 *pComMetaEmt, ComImageFlags const &imageFlags, CeeCreateFlags const &createFlags) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<portable_executable_writer_label_type>();
        auto pPEWriter = provider.NewObject();
        auto const *pSnInfo = m_pRuntime->GetInfo<strong_name_info_label_type>();
        pPEWriter->Initialize(m_pClass, pSnInfo);
        pPEWriter->SetCOMMetaDataEmit(pComMetaEmt);
        pPEWriter->SetImageFlags(imageFlags);
        pPEWriter->SetCreateFlags(createFlags);
        return pPEWriter;
    }



    template<class ApiHolder>    
    AutoPtr<typename BasePortableExecutableInfoPimpl<ApiHolder>::portable_executable_reader_label_type> BasePortableExecutableInfoPimpl<ApiHolder>::CreateReader(IMetaDataImport2 *pComMetaImp, path const &asmPath) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->ProviderOf<portable_executable_reader_label_type>();
        auto pPEReader = provider.NewObject();
        auto const *pSnInfo = m_pRuntime->GetInfo<strong_name_info_label_type>();
        pPEReader->Initialize(m_pClass, pSnInfo);
        pPEReader->SetCOMMetaDataImport(pComMetaImp);
        pPEReader->SetAssemblyPath(asmPath);
        return pPEReader;
    }



    template<class ApiHolder>    
    void BasePortableExecutableInfoPimpl<ApiHolder>::Initialize(runtime_host_label_type const *pRuntime)
    {
        using boost::filesystem::path;
        _ASSERTE(pRuntime != nullptr);
        _ASSERTE(m_pRuntime == nullptr);
        m_pRuntime = pRuntime;
    }



    template<class ApiHolder>    
    void BasePortableExecutableInfoPimpl<ApiHolder>::Finalize()
    {
        if (m_pCeeFileGen != nullptr && m_pfnDestroyCeeFileGen != nullptr)
        {
            m_pfnDestroyCeeFileGen(&m_pCeeFileGen);
            m_pCeeFileGen = nullptr;
            m_pfnDestroyCeeFileGen = nullptr;
            m_pfnCreateCeeFileGen = nullptr;
        }

        if (m_hmodCorPE != nullptr)
        {
            ::FreeLibrary(m_hmodCorPE);
            m_hmodCorPE = nullptr;
        }
    }



    template<class ApiHolder>    
    ICeeFileGen &BasePortableExecutableInfoPimpl<ApiHolder>::GetCOMCeeFileGen()
    {
        using boost::filesystem::path;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::CppAnonymSystemException;

        if (!m_pCeeFileGen)
        {
            auto const &corSystemDirectoryPath = m_pRuntime->GetCORSystemDirectoryPath();
            path msCorPEPath(corSystemDirectoryPath);
            msCorPEPath /= L"mscorpe.dll";
            m_hmodCorPE = ::LoadLibraryW(msCorPEPath.c_str());
            if (!m_hmodCorPE)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            m_pfnCreateCeeFileGen = reinterpret_cast<create_cee_file_gen_ptr_type>(::GetProcAddress(m_hmodCorPE, "CreateICeeFileGen"));
            if (!m_pfnCreateCeeFileGen)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            m_pfnDestroyCeeFileGen = reinterpret_cast<destroy_cee_file_gen_ptr_type>(::GetProcAddress(m_hmodCorPE, "DestroyICeeFileGen"));
            if (!m_pfnDestroyCeeFileGen)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            auto hr = m_pfnCreateCeeFileGen(&m_pCeeFileGen);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pCeeFileGen;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPL_HPP

