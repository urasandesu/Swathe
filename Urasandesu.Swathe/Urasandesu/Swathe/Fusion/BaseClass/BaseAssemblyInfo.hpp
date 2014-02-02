/* 
 * File: BaseAssemblyInfo.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYINFO_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYINFO_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYINFO_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyInfo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAssemblyInfo<ApiHolder>::BaseAssemblyInfo()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_info_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_info_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())assembly_info_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseAssemblyInfo<ApiHolder>::~BaseAssemblyInfo()
    {
        Pimpl()->~assembly_info_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseAssemblyInfo<ApiHolder>::assembly_info_pimpl_label_type *BaseAssemblyInfo<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<assembly_info_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAssemblyInfo<ApiHolder>::assembly_info_pimpl_label_type const *BaseAssemblyInfo<ApiHolder>::Pimpl() const
    {
        return const_cast<this_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_INFO_ADDITIONAL_INSTANTIATION \

    
    

    template<class ApiHolder>    
    ULONGLONG BaseAssemblyInfo<ApiHolder>::GetAssemblySizeInKB() const
    {
        return Pimpl()->GetAssemblySizeInKB();
    }

    template<class ApiHolder>    
    path const &BaseAssemblyInfo<ApiHolder>::GetAssemblyPath() const
    {
        return Pimpl()->GetAssemblyPath();
    }

    template<class ApiHolder>    
    void BaseAssemblyInfo<ApiHolder>::SetAssemblySizeInKB(ULONGLONG assemblySizeInKB)
    {
        Pimpl()->SetAssemblySizeInKB(assemblySizeInKB);
    }

    template<class ApiHolder>    
    void BaseAssemblyInfo<ApiHolder>::SetAssemblyPath(path const &assemblyPath)
    {
        Pimpl()->SetAssemblyPath(assemblyPath);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYINFO_HPP

