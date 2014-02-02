/* 
 * File: BaseAssemblyNameRange.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyNameRange.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAssemblyNameRange<ApiHolder>::BaseAssemblyNameRange()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_name_range_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(assembly_name_range_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())assembly_name_range_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseAssemblyNameRange<ApiHolder>::~BaseAssemblyNameRange()
    {
        Pimpl()->~assembly_name_range_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::assembly_name_range_pimpl_label_type *BaseAssemblyNameRange<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<assembly_name_range_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::assembly_name_range_pimpl_label_type const *BaseAssemblyNameRange<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_NAME_RANGE_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::iterator BaseAssemblyNameRange<ApiHolder>::begin()
    {
        return Pimpl()->begin();
    }

    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::const_iterator BaseAssemblyNameRange<ApiHolder>::begin() const
    {
        return Pimpl()->begin();
    }

    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::const_iterator BaseAssemblyNameRange<ApiHolder>::cbegin() const
    {
        return Pimpl()->cbegin();
    }

    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::iterator BaseAssemblyNameRange<ApiHolder>::end()
    {
        return Pimpl()->end();
    }

    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::const_iterator BaseAssemblyNameRange<ApiHolder>::end() const
    {
        return Pimpl()->end();
    }

    template<class ApiHolder>    
    typename BaseAssemblyNameRange<ApiHolder>::const_iterator BaseAssemblyNameRange<ApiHolder>::cend() const
    {
        return Pimpl()->cend();
    }

    template<class ApiHolder>    
    AutoPtr<typename BaseAssemblyNameRange<ApiHolder>::assembly_name_label_type const> &BaseAssemblyNameRange<ApiHolder>::GetCurrent()
    {
        return Pimpl()->GetCurrent();
    }

    template<class ApiHolder>    
    void BaseAssemblyNameRange<ApiHolder>::Reset()
    {
        Pimpl()->Reset();
    }

    template<class ApiHolder>    
    bool BaseAssemblyNameRange<ApiHolder>::MoveNext()
    {
        return Pimpl()->MoveNext();
    }

    template<class ApiHolder>    
    void BaseAssemblyNameRange<ApiHolder>::Initialize(fusion_info_label_type const *pFuInfo)
    {
        Pimpl()->Initialize(pFuInfo);
    }

    template<class ApiHolder>    
    void BaseAssemblyNameRange<ApiHolder>::SetCondition(AutoPtr<assembly_name_label_type> const &pCondition)
    {
        Pimpl()->SetCondition(pCondition);
    }

    template<class ApiHolder>    
    void BaseAssemblyNameRange<ApiHolder>::SetFlags(AssemblyCacheFlags const &flags)
    {
        Pimpl()->SetFlags(flags);
    }

    template<class ApiHolder>    
    IAssemblyEnum &BaseAssemblyNameRange<ApiHolder>::GetCOMAssemblyEnum()
    {
        return Pimpl()->GetCOMAssemblyEnum();
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_HPP

