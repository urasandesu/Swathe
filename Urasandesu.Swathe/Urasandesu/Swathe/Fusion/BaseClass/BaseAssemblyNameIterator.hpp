/* 
 * File: BaseAssemblyNameIterator.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyNameIterator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    template<class ApiHolder>    
    BaseAssemblyNameIterator<ApiHolder>::BaseAssemblyNameIterator() : 
        m_pAsmNameRng(nullptr), 
        m_hasNext(false)
    { }

    template<class ApiHolder>    
    BaseAssemblyNameIterator<ApiHolder>::BaseAssemblyNameIterator(assembly_name_range_label_type *pAsmNameRng, bool hasNext) : 
        m_pAsmNameRng(pAsmNameRng), 
        m_hasNext(hasNext)
    { }

#define SWATHE_DECLARE_BASE_ASSEMBLY_NAME_ITERATOR_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    typename BaseAssemblyNameIterator<ApiHolder>::reference BaseAssemblyNameIterator<ApiHolder>::dereference() const
    {
        _ASSERTE(m_pAsmNameRng);
        return m_pAsmNameRng->GetCurrent();
    }

    template<class ApiHolder>    
    bool BaseAssemblyNameIterator<ApiHolder>::equal(class_type const& other) const
    {
        return m_hasNext == other.m_hasNext;
    }

    template<class ApiHolder>    
    void BaseAssemblyNameIterator<ApiHolder>::increment()
    {
        _ASSERTE(m_pAsmNameRng);
        m_hasNext = m_pAsmNameRng->MoveNext();
    }
    
}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_HPP

