/* 
 * File: BaseRuntimeHost.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseRuntimeHost.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    template<class ApiHolder>    
    BaseRuntimeHost<ApiHolder>::BaseRuntimeHost()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(runtime_host_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(runtime_host_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())runtime_host_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseRuntimeHost<ApiHolder>::~BaseRuntimeHost()
    {
        Pimpl()->~runtime_host_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseRuntimeHost<ApiHolder>::runtime_host_pimpl_label_type *BaseRuntimeHost<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<runtime_host_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>
    typename BaseRuntimeHost<ApiHolder>::runtime_host_pimpl_label_type const *BaseRuntimeHost<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_RUNTIME_HOST_ADDITIONAL_INSTANTIATION \
    template Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> *Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::GetInfo<Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::RegisterInfo<Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<> > &); \
    template Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> *Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::GetInfo<Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::RegisterInfo<Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Fusion::BaseClass::BaseFusionInfo<> > &); \
    template Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> *Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::GetInfo<Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::RegisterInfo<Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::StrongNaming::BaseClass::BaseStrongNameInfo<> > &); \
    template Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> *Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::GetInfo<Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::RegisterInfo<Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<> > &); \
    template Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> *Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::GetInfo<Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> >() const; \
    template void Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>::RegisterInfo<Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> >(Urasandesu::CppAnonym::Utilities::TempPtr<Urasandesu::Swathe::Profiling::BaseClass::BaseProfilingInfo<> > &); \
    
    
    
    template<class ApiHolder>
    void BaseRuntimeHost<ApiHolder>::Initialize(host_info_label_type *pHost)
    {
        Pimpl()->Initialize(pHost);
    }

    template<class ApiHolder>
    wstring const &BaseRuntimeHost<ApiHolder>::GetRequestedVersion() const
    {
        return Pimpl()->GetRequestedVersion();
    }

    template<class ApiHolder>
    wstring const &BaseRuntimeHost<ApiHolder>::GetCORVersion() const
    {
        return Pimpl()->GetCORVersion();
    }

    template<class ApiHolder>
    path const &BaseRuntimeHost<ApiHolder>::GetCORSystemDirectoryPath() const
    {
        return Pimpl()->GetCORSystemDirectoryPath();
    }

    template<class ApiHolder>
    template<class Info>
    Info *BaseRuntimeHost<ApiHolder>::GetInfo() const
    {
        return Pimpl()->GetInfo<Info>();
    }

    template<class ApiHolder>
    void BaseRuntimeHost<ApiHolder>::SetRequestedVersion(wstring const &reqVersion)
    {
        Pimpl()->SetRequestedVersion(reqVersion);
    }

    template<class ApiHolder>
    template<class Info>
    void BaseRuntimeHost<ApiHolder>::RegisterInfo(TempPtr<Info> &pInfo)
    {
        Pimpl()->RegisterInfo(pInfo);
    }

    template<class ApiHolder>
    ICLRRuntimeInfo &BaseRuntimeHost<ApiHolder>::GetCOMRuntimeInfo() const
    {
        return Pimpl()->GetCOMRuntimeInfo();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_HPP

