/* 
 * File: BaseAssemblyNameRangePimpl.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPL_H
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_ASSEMBLYNAMERANGEPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplFacade/AssemblyNameRangePimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyNameRangePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFLAGS_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheFlags.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    using boost::iterator_difference;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
    
    template<
        class ApiHolder
    >    
    class BaseAssemblyNameRangePimpl
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_NAME_RANGE_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_NAME_RANGE_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_NAME_RANGE_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseAssemblyNameRangePimpl(assembly_name_range_label_type *pClass);

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
        void Initialize(fusion_info_label_type const *pFuInfo);
        void SetCondition(AutoPtr<assembly_name_label_type> const &pCondition);
        void SetFlags(AssemblyCacheFlags const &flags);
        IAssemblyEnum &GetCOMAssemblyEnum();

        mutable assembly_name_range_label_type *m_pClass;
        fusion_info_label_type const *m_pFuInfo;
        AutoPtr<assembly_name_label_type> m_pCondition;
        AssemblyCacheFlags m_flags;
        AutoPtr<assembly_name_label_type const> m_pCurrent;
        mutable ATL::CComPtr<IAssemblyEnum> m_pComAsmEnum;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMERANGEPIMPL_H

