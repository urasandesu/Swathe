/* 
 * File: BaseAssemblyNameIterator.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_H
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEITERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassFacade/AssemblyNameIteratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATORFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyNameIteratorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    using boost::iterator_core_access;
    using boost::iterator_facade;
    using boost::forward_traversal_tag;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;

    template<
        class ApiHolder
    >    
    class BaseAssemblyNameIterator : 
        public iterator_facade<
            BaseAssemblyNameIterator<ApiHolder>, 
            AutoPtr<typename Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::AssemblyNameIteratorFacade<ApiHolder>::assembly_name_label_type const>, 
            forward_traversal_tag>
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_NAME_ITERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_NAME_ITERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_NAME_ITERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseAssemblyNameIterator(assembly_name_range_label_type *pAsmNameRng, bool hasNext = true);
    
    private:
        friend class iterator_core_access;

        reference dereference() const;
        bool equal(class_type const& other) const;
        void increment();

        assembly_name_range_label_type *m_pAsmNameRng;
        bool m_hasNext;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEITERATOR_H

