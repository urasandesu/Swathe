/* 
 * File: BaseAssemblyNameRange.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_H
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMERANGEFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassFacade/AssemblyNameRangeFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGEFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyNameRangeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFLAGS_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheFlags.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    using boost::iterator_difference;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;

    template<
        class ApiHolder
    >    
    class BaseAssemblyNameRange : 
        boost::noncopyable
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_NAME_RANGE_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_NAME_RANGE_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_NAME_RANGE_FACADE_TYPEDEF_ALIAS
        
        BaseAssemblyNameRange();
        ~BaseAssemblyNameRange();

        typedef class_type type;
        typedef assembly_name_iterator_label_type iterator;
        typedef assembly_name_iterator_label_type const_iterator;
        typedef typename iterator_difference<iterator>::type difference_type;

        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;
        iterator end();
        const_iterator end() const;
        const_iterator cend() const;
        AutoPtr<assembly_name_label_type const> &GetCurrent();
        void Reset();
        bool MoveNext();
    
    private:
        assembly_name_range_pimpl_label_type *Pimpl();
        assembly_name_range_pimpl_label_type const *Pimpl() const;
        void Initialize(fusion_info_label_type const *pFuInfo);
        void SetCondition(AutoPtr<assembly_name_label_type> const &pCondition);
        void SetFlags(AssemblyCacheFlags const &flags);
        IAssemblyEnum &GetCOMAssemblyEnum();

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 24;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMERANGE_H

