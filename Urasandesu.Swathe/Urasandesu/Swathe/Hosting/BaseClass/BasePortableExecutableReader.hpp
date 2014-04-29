/* 
 * File: BasePortableExecutableReader.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableReader.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    template<class ApiHolder>    
    BasePortableExecutableReader<ApiHolder>::BasePortableExecutableReader()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(portable_executable_reader_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(portable_executable_reader_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())portable_executable_reader_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BasePortableExecutableReader<ApiHolder>::~BasePortableExecutableReader()
    {
        Pimpl()->~portable_executable_reader_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BasePortableExecutableReader<ApiHolder>::portable_executable_reader_pimpl_label_type *BasePortableExecutableReader<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<portable_executable_reader_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BasePortableExecutableReader<ApiHolder>::portable_executable_reader_pimpl_label_type const *BasePortableExecutableReader<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PORTABLE_EXECUTABLE_READER_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BasePortableExecutableReader<ApiHolder>::Initialize(portable_executable_info_label_type *pPEInfo, strong_name_info_label_type const *pSnInfo)
    {
        Pimpl()->Initialize(pPEInfo, pSnInfo);
    }

    template<class ApiHolder>    
    iterator_range<BYTE const *> BasePortableExecutableReader<ApiHolder>::GetMappedFileSource() const
    {
        return Pimpl()->GetMappedFileSource();
    }

    template<class ApiHolder>    
    BYTE const *BasePortableExecutableReader<ApiHolder>::AdvanceToSectionHeader(BYTE const *i, BYTE const *i_end) const
    {
        return Pimpl()->AdvanceToSectionHeader(i, i_end);
    }

    template<class ApiHolder>    
    BYTE const *BasePortableExecutableReader<ApiHolder>::GetPEHeaders(BYTE const *i, BYTE const *i_end, IMAGE_DOS_HEADER &dosHeader, array<BYTE, 0x40> &dosStubBody, IMAGE_FILE_HEADER &fileHeader, IMAGE_NT_HEADERS32 &ntHeaders32, IMAGE_NT_HEADERS64 &ntHeaders64) const
    {
        return Pimpl()->GetPEHeaders(i, i_end, dosHeader, dosStubBody, fileHeader, ntHeaders32, ntHeaders64);
    }

    template<class ApiHolder>    
    void BasePortableExecutableReader<ApiHolder>::GetPEKind(DWORD &dwPEKind, DWORD &dwMachine) const
    {
        Pimpl()->GetPEKind(dwPEKind, dwMachine);
    }

    template<class ApiHolder>    
    COR_ILMETHOD const *BasePortableExecutableReader<ApiHolder>::GetILMethodBody(ULONG codeRVA) const
    {
        return Pimpl()->GetILMethodBody(codeRVA);
    }

    template<class ApiHolder>    
    void BasePortableExecutableReader<ApiHolder>::SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp)
    {
        Pimpl()->SetCOMMetaDataImport(pComMetaImp);
    }

    template<class ApiHolder>    
    void BasePortableExecutableReader<ApiHolder>::SetAssemblyPath(path const &asmPath)
    {
        Pimpl()->SetAssemblyPath(asmPath);
    }
    
}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEREADER_HPP

