/* 
 * File: BasePortableExecutableInfo.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_H
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEINFOFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassFacade/PortableExecutableInfoFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFOFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableInfoFwd.h>
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

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    using boost::filesystem::path;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
    using Urasandesu::Swathe::Metadata::IMetadataVisitor; 

    template<
        class ApiHolder
    >    
    class BasePortableExecutableInfo
    {
    public:
        SWATHE_BEGIN_PORTABLE_EXECUTABLE_INFO_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PORTABLE_EXECUTABLE_INFO_FACADE_TYPEDEF_ALIAS
        
        BasePortableExecutableInfo();
        ~BasePortableExecutableInfo();

        void Initialize(runtime_host_label_type *pRuntime);
        AutoPtr<portable_executable_writer_label_type> CreateWriter(IMetaDataEmit2 *pComMetaEmt, ComImageFlags const &imageFlags, CeeCreateFlags const &createFlags) const;
        AutoPtr<portable_executable_reader_label_type> CreateReader(IMetaDataImport2 *pComMetaImp, path const &asmPath) const;
    
    private:
        portable_executable_info_pimpl_label_type *Pimpl();
        portable_executable_info_pimpl_label_type const *Pimpl() const;
        ICeeFileGen &GetCOMCeeFileGen();

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 72;
#else
        static INT const PIMPL_TYPE_SIZE = 144;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_H

