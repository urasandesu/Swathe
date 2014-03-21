/* 
 * File: BasePortableExecutableInfo.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableInfo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    template<class ApiHolder>    
    BasePortableExecutableInfo<ApiHolder>::BasePortableExecutableInfo()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(portable_executable_info_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(portable_executable_info_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())portable_executable_info_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BasePortableExecutableInfo<ApiHolder>::~BasePortableExecutableInfo()
    {
        Pimpl()->~portable_executable_info_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BasePortableExecutableInfo<ApiHolder>::portable_executable_info_pimpl_label_type *BasePortableExecutableInfo<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<portable_executable_info_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BasePortableExecutableInfo<ApiHolder>::portable_executable_info_pimpl_label_type const *BasePortableExecutableInfo<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PORTABLE_EXECUTABLE_INFO_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BasePortableExecutableInfo<ApiHolder>::Initialize(runtime_host_label_type *pRuntime)
    {
        Pimpl()->Initialize(pRuntime);
    }
    
    template<class ApiHolder>    
    AutoPtr<typename BasePortableExecutableInfo<ApiHolder>::portable_executable_writer_label_type> BasePortableExecutableInfo<ApiHolder>::CreateWriter(IMetaDataEmit2 *pComMetaEmt, ComImageFlags const &imageFlags, CeeCreateFlags const &createFlags) const
    {
        return Pimpl()->CreateWriter(pComMetaEmt, imageFlags, createFlags);
    }

    template<class ApiHolder>    
    AutoPtr<typename BasePortableExecutableInfo<ApiHolder>::portable_executable_reader_label_type> BasePortableExecutableInfo<ApiHolder>::CreateReader(IMetaDataImport2 *pComMetaImp, path const &asmPath) const
    {
        return Pimpl()->CreateReader(pComMetaImp, asmPath);
    }

    template<class ApiHolder>    
    ICeeFileGen &BasePortableExecutableInfo<ApiHolder>::GetCOMCeeFileGen()
    {
        return Pimpl()->GetCOMCeeFileGen();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_HPP

