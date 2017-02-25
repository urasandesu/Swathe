/* 
 * File: BaseAssemblyCachePimpl.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPL_H
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_ASSEMBLYCACHEPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplFacade/AssemblyCachePimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyCachePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYQUERYTYPES_H
#include <Urasandesu/Swathe/Fusion/AssemblyQueryTypes.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEINSTALLFLAGS_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheInstallFlags.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEUNINSTALLDISPOSITIONS_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheUninstallDispositions.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using boost::filesystem::path;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
    
    template<
        class ApiHolder
    >    
    class BaseAssemblyCachePimpl
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_CACHE_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_CACHE_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_CACHE_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseAssemblyCachePimpl(assembly_cache_label_type *pClass);

        AutoPtr<assembly_info_label_type> QueryAssemblyInfo(AssemblyQueryTypes const &type, wstring const &assemblyFullName) const;
        void InstallAssembly(AssemblyCacheInstallFlags const &flag, path const &asmPath);
        AssemblyCacheUninstallDispositions UninstallAssembly(wstring const &fullName);
        
    private:
        void Initialize(fusion_info_label_type const *pFuInfo);
        IAssemblyCache &GetCOMAssemblyCache();

        mutable assembly_cache_label_type *m_pClass;
        fusion_info_label_type const *m_pFuInfo;
        mutable ATL::CComPtr<IAssemblyCache> m_pComAsmCache;
        int reserved;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYCACHEPIMPL_H

