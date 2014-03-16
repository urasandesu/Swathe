/* 
 * File: BasePortableExecutableInfoPimpl.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPL_H
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_PORTABLEEXECUTABLEINFOPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplFacade/PortableExecutableInfoPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BasePortableExecutableInfoPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_COMIMAGEFLAGS_H
#include <Urasandesu/Swathe/Hosting/ComImageFlags.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_CEECREATEFLAGS_H
#include <Urasandesu/Swathe/Hosting/CeeCreateFlags.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using boost::filesystem::path;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
    using Urasandesu::Swathe::Metadata::IMetadataVisitor; 

    template<
        class ApiHolder
    >    
    class BasePortableExecutableInfoPimpl
    {
    public:
        SWATHE_BEGIN_PORTABLE_EXECUTABLE_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PORTABLE_EXECUTABLE_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

        BasePortableExecutableInfoPimpl(portable_executable_info_label_type *pClass);
        ~BasePortableExecutableInfoPimpl();

        AutoPtr<portable_executable_writer_label_type> CreateWriter(IMetaDataEmit2 *pComMetaEmt, ComImageFlags const &imageFlags, CeeCreateFlags const &createFlags) const;
        AutoPtr<portable_executable_reader_label_type> CreateReader(IMetaDataImport2 *pComMetaImp, path const &asmPath) const;
                
    private:
        typedef HRESULT (__stdcall *create_cee_file_gen_ptr_type)(ICeeFileGen **ceeFileGen);
        typedef HRESULT (__stdcall *destroy_cee_file_gen_ptr_type)(ICeeFileGen **ceeFileGen);
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        void Initialize(runtime_host_label_type const *pRuntime);
        void Finalize();
        ICeeFileGen &GetCOMCeeFileGen();

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
#ifdef _M_IX86
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 48;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 96;
#endif
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable portable_executable_info_label_type *m_pClass;
        runtime_host_label_type const *m_pRuntime;
        HMODULE m_hmodCorPE;
        create_cee_file_gen_ptr_type m_pfnCreateCeeFileGen;
        destroy_cee_file_gen_ptr_type m_pfnDestroyCeeFileGen;
        ICeeFileGen *m_pCeeFileGen;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEINFOPIMPL_H

