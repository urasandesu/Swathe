/* 
 * File: BasePortableExecutableReaderPimpl.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_H
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_PORTABLEEXECUTABLEREADERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplFacade/PortableExecutableReaderPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BasePortableExecutableReaderPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    using boost::array;
    using boost::filesystem::path;
    using boost::iterator_range;
    using std::unique_ptr;
    using std::vector;
    
    template<
        class ApiHolder
    >    
    class BasePortableExecutableReaderPimpl
    {
    public:
        SWATHE_BEGIN_PORTABLE_EXECUTABLE_READER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PORTABLE_EXECUTABLE_READER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PORTABLE_EXECUTABLE_READER_PIMPL_FACADE_TYPEDEF_ALIAS

        BasePortableExecutableReaderPimpl(portable_executable_reader_label_type *pClass);
        ~BasePortableExecutableReaderPimpl();

        void Initialize(portable_executable_info_label_type *pPEInfo, strong_name_info_label_type const *pSnInfo);
        iterator_range<BYTE const *> GetMappedFileSource() const;
        BYTE const *AdvanceToSectionHeader(BYTE const *i, BYTE const *i_end) const;
        BYTE const *GetPEHeaders(BYTE const *i, BYTE const *i_end, IMAGE_DOS_HEADER &dosHeader, array<BYTE, 0x40> &dosStubBody, IMAGE_FILE_HEADER &fileHeader, IMAGE_NT_HEADERS32 &ntHeaders32, IMAGE_NT_HEADERS64 &ntHeaders64) const;
        void GetPEKind(DWORD &dwPEKind, DWORD &dwMachine) const;
        COR_ILMETHOD const *GetILMethodBody(ULONG codeRVA) const;
        
    private:
        void SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp);
        void SetAssemblyPath(path const &asmPath);
        vector<BYTE> const &GetMemoryMappedFile() const;

        mutable portable_executable_reader_label_type *m_pClass;
        portable_executable_info_label_type *m_pPEInfo;
        strong_name_info_label_type const *m_pSnInfo;
        ATL::CComPtr<IMetaDataImport2> m_pComMetaImp;
        path m_asmPath;
        mutable vector<BYTE> m_file;
        int reserved;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_H

