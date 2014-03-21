/* 
 * File: BaseFusionInfo.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEFUSIONINFO_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEFUSIONINFO_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEFUSIONINFO_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseFusionInfo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    template<class ApiHolder>    
    BaseFusionInfo<ApiHolder>::BaseFusionInfo()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(fusion_info_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(fusion_info_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())fusion_info_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseFusionInfo<ApiHolder>::~BaseFusionInfo()
    {
        Pimpl()->~fusion_info_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseFusionInfo<ApiHolder>::fusion_info_pimpl_label_type *BaseFusionInfo<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<fusion_info_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseFusionInfo<ApiHolder>::fusion_info_pimpl_label_type const *BaseFusionInfo<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_FUSION_INFO_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseFusionInfo<ApiHolder>::Initialize(runtime_host_label_type *pRuntime)
    {
        Pimpl()->Initialize(pRuntime);
    }

    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfo<ApiHolder>::assembly_cache_label_type> BaseFusionInfo<ApiHolder>::NewAssemblyCache() const
    {
        return Pimpl()->NewAssemblyCache();
    }

    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfo<ApiHolder>::assembly_name_label_type> BaseFusionInfo<ApiHolder>::NewAssemblyName(wstring const &displayName, NewAssemblyNameFlags const &flags) const
    {
        return Pimpl()->NewAssemblyName(displayName, flags);
    }

    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfo<ApiHolder>::assembly_name_range_label_type> BaseFusionInfo<ApiHolder>::EnumerateAssemblyName(AutoPtr<assembly_name_label_type> const &pCondition, AssemblyCacheFlags const &flags) const
    {
        return Pimpl()->EnumerateAssemblyName(pCondition, flags);
    }

    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfo<ApiHolder>::assembly_info_label_type> BaseFusionInfo<ApiHolder>::NewAssemblyInfo(ULONGLONG assemblySizeInKB, path const &assemblyPath) const
    {
        return Pimpl()->NewAssemblyInfo(assemblySizeInKB, assemblyPath);
    }

    template<class ApiHolder>    
    AutoPtr<typename BaseFusionInfo<ApiHolder>::assembly_name_label_type> BaseFusionInfo<ApiHolder>::NewAssemblyName(IAssemblyName *pComAsmName) const
    {
        return Pimpl()->NewAssemblyName(pComAsmName);
    }

    template<class ApiHolder>    
    HMODULE BaseFusionInfo<ApiHolder>::GetFusionHandle() const
    {
        return Pimpl()->GetFusionHandle();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEFUSIONINFO_HPP

