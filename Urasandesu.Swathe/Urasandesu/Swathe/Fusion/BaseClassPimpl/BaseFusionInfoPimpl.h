/* 
 * File: BaseFusionInfoPimpl.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPL_H
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_FUSIONINFOPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplFacade/FusionInfoPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseFusionInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_NEWASSEMBLYNAMEFLAGS_H
#include <Urasandesu/Swathe/Fusion/NewAssemblyNameFlags.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFLAGS_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheFlags.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using boost::filesystem::path;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;

    template<
        class ApiHolder
    >    
    class BaseFusionInfoPimpl
    {
    public:
        SWATHE_BEGIN_FUSION_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_FUSION_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_FUSION_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseFusionInfoPimpl(fusion_info_label_type *pClass);
        ~BaseFusionInfoPimpl();

        AutoPtr<assembly_cache_label_type> NewAssemblyCache() const;
        AutoPtr<assembly_name_label_type> NewAssemblyName(wstring const &displayName, NewAssemblyNameFlags const &flags) const;
        AutoPtr<assembly_name_range_label_type> EnumerateAssemblyName(AutoPtr<assembly_name_label_type> const &pCondition, AssemblyCacheFlags const &flags) const;
        
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        void Initialize(runtime_host_label_type const *pRuntime);
        void Finalize();
        AutoPtr<assembly_cache_label_type> NewAssemblyCacheCore() const;
        AutoPtr<assembly_info_label_type> NewAssemblyInfo(ULONGLONG assemblySizeInKB, path const &assemblyPath) const;
        AutoPtr<assembly_name_label_type> NewAssemblyName(IAssemblyName *pComAsmName) const;
        AutoPtr<assembly_name_label_type> NewAssemblyNameCore() const;
        AutoPtr<assembly_name_range_label_type> NewAssemblyNameRangeCore() const;
        HMODULE GetFusionHandle() const;

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
#ifdef _M_IX86
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 80;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 160;
#endif
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable fusion_info_label_type *m_pClass;
        runtime_host_label_type const *m_pRuntime;
        mutable HMODULE m_hmodFusion;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEFUSIONINFOPIMPL_H

