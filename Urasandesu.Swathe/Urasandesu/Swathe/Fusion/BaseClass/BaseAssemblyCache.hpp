/* 
 * File: BaseAssemblyCache.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyCache.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAssemblyCache<ApiHolder>::BaseAssemblyCache()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_cache_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_cache_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())assembly_cache_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseAssemblyCache<ApiHolder>::~BaseAssemblyCache()
    {
        Pimpl()->~assembly_cache_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseAssemblyCache<ApiHolder>::assembly_cache_pimpl_label_type *BaseAssemblyCache<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<assembly_cache_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAssemblyCache<ApiHolder>::assembly_cache_pimpl_label_type const *BaseAssemblyCache<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_CACHE_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    AutoPtr<typename BaseAssemblyCache<ApiHolder>::assembly_info_label_type> BaseAssemblyCache<ApiHolder>::QueryAssemblyInfo(AssemblyQueryTypes const &type, wstring const &assemblyFullName) const
    {
        return Pimpl()->QueryAssemblyInfo(type, assemblyFullName);
    }

    template<class ApiHolder>    
    void BaseAssemblyCache<ApiHolder>::InstallAssembly(AssemblyCacheInstallFlags const &flag, path const &asmPath)
    {
        Pimpl()->InstallAssembly(flag, asmPath);
    }

    template<class ApiHolder>    
    AssemblyCacheUninstallDispositions BaseAssemblyCache<ApiHolder>::UninstallAssembly(wstring const &fullName)
    {
        return Pimpl()->UninstallAssembly(fullName);
    }

    template<class ApiHolder>    
    void BaseAssemblyCache<ApiHolder>::Initialize(fusion_info_label_type const *pFuInfo)
    {
        Pimpl()->Initialize(pFuInfo);
    }

    template<class ApiHolder>    
    IAssemblyCache &BaseAssemblyCache<ApiHolder>::GetCOMAssemblyCache()
    {
        return Pimpl()->GetCOMAssemblyCache();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_HPP

