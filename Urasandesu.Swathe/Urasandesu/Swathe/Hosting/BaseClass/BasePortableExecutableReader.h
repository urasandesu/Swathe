/* 
 * File: BasePortableExecutableReader.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_H
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEREADERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassFacade/PortableExecutableReaderFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADERFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableReaderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    using boost::filesystem::path;
    using boost::iterator_range;

    template<
        class ApiHolder
    >    
    class BasePortableExecutableReader
    {
    public:
        SWATHE_BEGIN_PORTABLE_EXECUTABLE_READER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PORTABLE_EXECUTABLE_READER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PORTABLE_EXECUTABLE_READER_FACADE_TYPEDEF_ALIAS
        
        BasePortableExecutableReader();
        ~BasePortableExecutableReader();

        void Initialize(portable_executable_info_label_type *pPEInfo, strong_name_info_label_type const *pSnInfo);
        iterator_range<BYTE const *> GetMappedFileSource() const;
    
    private:
        portable_executable_reader_pimpl_label_type *Pimpl();
        portable_executable_reader_pimpl_label_type const *Pimpl() const;
        void SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp);
        void SetAssemblyPath(path const &asmPath);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 44;
#else
        static INT const PIMPL_TYPE_SIZE = 80;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_H

