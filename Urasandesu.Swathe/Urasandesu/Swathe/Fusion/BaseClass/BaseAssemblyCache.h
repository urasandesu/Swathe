/* 
 * File: BaseAssemblyCache.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_H
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYCACHEFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassFacade/AssemblyCacheFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHEFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyCacheFwd.h>
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

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    using boost::filesystem::path;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;

    template<
        class ApiHolder
    >    
    class BaseAssemblyCache
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_CACHE_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_CACHE_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_CACHE_FACADE_TYPEDEF_ALIAS
        
        BaseAssemblyCache();
        ~BaseAssemblyCache();

        AutoPtr<assembly_info_label_type> QueryAssemblyInfo(AssemblyQueryTypes const &type, wstring const &assemblyFullName) const;
        void InstallAssembly(AssemblyCacheInstallFlags const &flag, path const &asmPath);
        AssemblyCacheUninstallDispositions UninstallAssembly(wstring const &fullName);
    
    private:
        assembly_cache_pimpl_label_type *Pimpl();
        assembly_cache_pimpl_label_type const *Pimpl() const;
        void Initialize(fusion_info_label_type const *pFuInfo);
        IAssemblyCache &GetCOMAssemblyCache();

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 16;
#else
        static INT const PIMPL_TYPE_SIZE = 32;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYCACHE_H

