/* 
 * File: BaseHostInfo.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseHostInfo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    template<class ApiHolder>    
    BaseHostInfo<ApiHolder>::BaseHostInfo()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(host_info_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(host_info_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())host_info_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseHostInfo<ApiHolder>::~BaseHostInfo()
    {
        Pimpl()->~host_info_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseHostInfo<ApiHolder>::host_info_pimpl_label_type *BaseHostInfo<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<host_info_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseHostInfo<ApiHolder>::host_info_pimpl_label_type const *BaseHostInfo<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_HOST_INFO_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>
    void BaseHostInfo<ApiHolder>::Initialize(host_info_label_type *pHost)
    {
        Pimpl()->Initialize(pHost);
    }

    template<class ApiHolder>    
    typename BaseHostInfo<ApiHolder>::host_info_label_type *BaseHostInfo<ApiHolder>::CreateHost()
    {
        return host_info_pimpl_label_type::CreateHost();
    }

    template<class ApiHolder>
    unordered_map<wstring, typename BaseHostInfo<ApiHolder>::runtime_host_label_type const *> const &BaseHostInfo<ApiHolder>::GetRuntimes() const
    {
        return Pimpl()->GetRuntimes();
    }

    template<class ApiHolder>
    typename BaseHostInfo<ApiHolder>::runtime_host_label_type const *BaseHostInfo<ApiHolder>::GetRuntime(wstring const &version) const
    {
        return Pimpl()->GetRuntime(version);
    }

    template<class ApiHolder>
    void BaseHostInfo<ApiHolder>::RegisterHost(TempPtr<host_info_label_type> &pHost)
    {
        Pimpl()->RegisterHost(pHost);
    }

    template<class ApiHolder>
    void BaseHostInfo<ApiHolder>::RegisterRuntime(TempPtr<runtime_host_label_type> &pRuntime)
    {
        Pimpl()->RegisterRuntime(pRuntime);
    }

    template<class ApiHolder>
    ICLRMetaHost &BaseHostInfo<ApiHolder>::GetCOMMetaHost() const
    {
        return Pimpl()->GetCOMMetaHost();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_HPP

