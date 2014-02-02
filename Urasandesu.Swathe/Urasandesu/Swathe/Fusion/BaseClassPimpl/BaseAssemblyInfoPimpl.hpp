/* 
 * File: BaseAssemblyInfoPimpl.hpp
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPL_HPP
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPL_HPP

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPL_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyInfoPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAssemblyInfoPimpl<ApiHolder>::BaseAssemblyInfoPimpl(assembly_info_label_type *pClass) : 
        m_pClass(pClass), 
        m_assemblySizeInKB(0)
    { }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_INFO_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    ULONGLONG BaseAssemblyInfoPimpl<ApiHolder>::GetAssemblySizeInKB() const
    {
        return m_assemblySizeInKB;
    }


    template<class ApiHolder>    
    path const &BaseAssemblyInfoPimpl<ApiHolder>::GetAssemblyPath() const
    {
        return m_assemblyPath;
    }

    
    template<class ApiHolder>    
    void BaseAssemblyInfoPimpl<ApiHolder>::SetAssemblySizeInKB(ULONGLONG assemblySizeInKB)
    {
        m_assemblySizeInKB = assemblySizeInKB;
    }


    template<class ApiHolder>    
    void BaseAssemblyInfoPimpl<ApiHolder>::SetAssemblyPath(path const &assemblyPath)
    {
        m_assemblyPath = assemblyPath;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPL_HPP

