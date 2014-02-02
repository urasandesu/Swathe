/* 
 * File: BaseAssemblyInfoPimpl.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPL_H
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_ASSEMBLYINFOPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplFacade/AssemblyInfoPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyInfoPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    using boost::filesystem::path;

    template<
        class ApiHolder
    >    
    class BaseAssemblyInfoPimpl
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseAssemblyInfoPimpl(assembly_info_label_type *pClass);
        ULONGLONG GetAssemblySizeInKB() const;
        path const &GetAssemblyPath() const;
        
    private:
        void SetAssemblySizeInKB(ULONGLONG assemblySizeInKB);
        void SetAssemblyPath(path const &assemblyPath);

        mutable assembly_info_label_type *m_pClass;
        ULONGLONG m_assemblySizeInKB;
        path m_assemblyPath;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYINFOPIMPL_H

