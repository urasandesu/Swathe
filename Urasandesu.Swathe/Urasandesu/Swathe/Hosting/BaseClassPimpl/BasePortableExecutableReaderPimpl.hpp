/* 
 * File: BasePortableExecutableReaderPimpl.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BasePortableExecutableReaderPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BasePortableExecutableReaderPimpl<ApiHolder>::BasePortableExecutableReaderPimpl(portable_executable_reader_label_type *pClass) : 
        m_pClass(pClass), 
        m_pPEInfo(nullptr), 
        m_pSnInfo(nullptr)
    { }

    template<class ApiHolder>    
    BasePortableExecutableReaderPimpl<ApiHolder>::~BasePortableExecutableReaderPimpl()
    { }

#define SWATHE_DECLARE_BASE_PORTABLE_EXECUTABLE_READER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BasePortableExecutableReaderPimpl<ApiHolder>::Initialize(portable_executable_info_label_type *pPEInfo, strong_name_info_label_type const *pSnInfo)
    {
        _ASSERTE(pPEInfo);
        _ASSERTE(!m_pPEInfo);
        m_pPEInfo = pPEInfo;

        _ASSERTE(pSnInfo);
        _ASSERTE(!m_pSnInfo);
        m_pSnInfo = pSnInfo;
    }



    template<class ApiHolder>    
    iterator_range<BYTE const *> BasePortableExecutableReaderPimpl<ApiHolder>::GetMappedFileSource() const
    {
        using boost::make_iterator_range;

        auto &file = GetMemoryMappedFile();
        auto i = reinterpret_cast<BYTE const *>(file.begin());
        auto i_end = reinterpret_cast<BYTE const *>(file.end());
        return make_iterator_range(i, i_end);
    }



    template<class ApiHolder>    
    BYTE const *BasePortableExecutableReaderPimpl<ApiHolder>::AdvanceToSectionHeader(BYTE const *i, BYTE const *i_end) const
    {
        auto dosHeader = IMAGE_DOS_HEADER();
        auto dosStubBody = array<BYTE, 0x40>();
        auto fileHeader = IMAGE_FILE_HEADER();
        auto ntHeaders32 = IMAGE_NT_HEADERS32();
        auto ntHeaders64 = IMAGE_NT_HEADERS64();
        return GetPEHeaders(i, i_end, dosHeader, dosStubBody, fileHeader, ntHeaders32, ntHeaders64);
    }



    template<class ApiHolder>    
    BYTE const *BasePortableExecutableReaderPimpl<ApiHolder>::GetPEHeaders(BYTE const *i, BYTE const *i_end, IMAGE_DOS_HEADER &dosHeader, array<BYTE, 0x40> &dosStubBody, IMAGE_FILE_HEADER &fileHeader, IMAGE_NT_HEADERS32 &ntHeaders32, IMAGE_NT_HEADERS64 &ntHeaders64) const
    {
        _ASSERTE(i != i_end);

        i = PEGetDOSHeader(i, i_end, dosHeader);
        _ASSERTE(dosHeader.e_magic == 0x5A4D);
        _ASSERTE(i != i_end);
        
        i = PEGetData(i, i_end, dosStubBody.size(), dosStubBody.begin());
        _ASSERTE(i != i_end);
        
        auto signature = DWORD();
        PEGetNTHeadersPrerequisites(i, i_end, signature, fileHeader);
        _ASSERTE(signature == 0x00004550);
        if (fileHeader.Machine == IMAGE_FILE_MACHINE_I386)
            i = PEGetNTHeaders(i, i_end, ntHeaders32);
        else
            i = PEGetNTHeaders(i, i_end, ntHeaders64);
        _ASSERTE(i != i_end);

        return i;
    }



    template<class ApiHolder>    
    void BasePortableExecutableReaderPimpl<ApiHolder>::GetPEKind(DWORD &dwPEKind, DWORD &dwMachine) const
    {
        auto mappedFileSource = GetMappedFileSource();
        
        auto i = mappedFileSource.begin();
        auto i_end = mappedFileSource.end();
        
        auto dosHeader = IMAGE_DOS_HEADER();
        auto dosStubBody = array<BYTE, 0x40>();
        auto fileHeader = IMAGE_FILE_HEADER();
        auto ntHeaders32 = IMAGE_NT_HEADERS32();
        auto ntHeaders64 = IMAGE_NT_HEADERS64();
        i = GetPEHeaders(i, i_end, dosHeader, dosStubBody, fileHeader, ntHeaders32, ntHeaders64);
        _ASSERTE(i != i_end);
        
        auto cliHeaderRVA = 0ul;
        if (fileHeader.Machine == IMAGE_FILE_MACHINE_I386)
            cliHeaderRVA = ntHeaders32.OptionalHeader.DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 2].VirtualAddress;
        else
            cliHeaderRVA = ntHeaders64.OptionalHeader.DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 2].VirtualAddress;
        
        auto textSecHeader = IMAGE_SECTION_HEADER();
        i = PEGetSectionHeader(i, i_end, textSecHeader);
        _ASSERTE(std::string(reinterpret_cast<CHAR *>(&textSecHeader.Name[0])) == std::string(".text"));
        _ASSERTE(i != i_end);
        
        i = mappedFileSource.begin();
        i_end = mappedFileSource.end();
        
        auto offset = cliHeaderRVA - textSecHeader.VirtualAddress + textSecHeader.PointerToRawData;
        i += offset;
        _ASSERTE(i != i_end);
        
        auto cliHeader = IMAGE_COR20_HEADER();
        i = PEGetCLIHeader(i, i_end, cliHeader);
        _ASSERTE(i != i_end);
        
        dwMachine = fileHeader.Machine;
        dwPEKind = 0ul;
        if (fileHeader.Machine != IMAGE_FILE_MACHINE_I386)
            dwPEKind |= static_cast<DWORD>(pe32Plus);
        
        if (cliHeader.Flags & COMIMAGE_FLAGS_ILONLY)
            dwPEKind |= static_cast<DWORD>(peILonly);
        else
            dwPEKind |= static_cast<DWORD>(pe32Unmanaged);
        
        if (COR_IS_32BIT_REQUIRED(cliHeader.Flags))
            dwPEKind |= static_cast<DWORD>(pe32BitRequired);
        
        if (COR_IS_32BIT_PREFERRED(cliHeader.Flags))
            dwPEKind |= static_cast<DWORD>(pe32BitPreferred);
    }



    template<class ApiHolder>    
    COR_ILMETHOD const *BasePortableExecutableReaderPimpl<ApiHolder>::GetILMethodBody(ULONG codeRVA) const
    {
        auto mappedFileSource = GetMappedFileSource();
        
        auto i = mappedFileSource.begin();
        auto i_end = mappedFileSource.end();
        
        i = AdvanceToSectionHeader(i, i_end);
        _ASSERTE(i != i_end);
        
        auto textSecHeader = IMAGE_SECTION_HEADER();
        i = PEGetSectionHeader(i, i_end, textSecHeader);
        _ASSERTE(std::string(reinterpret_cast<CHAR *>(&textSecHeader.Name[0])) == std::string(".text"));
        _ASSERTE(i != i_end);
        
        i = mappedFileSource.begin();
        i_end = mappedFileSource.end();
        
        auto offset = codeRVA - textSecHeader.VirtualAddress + textSecHeader.PointerToRawData;
        i += offset;
        _ASSERTE(i != i_end);
        
        return reinterpret_cast<COR_ILMETHOD const *>(i);
    }



    template<class ApiHolder>    
    void BasePortableExecutableReaderPimpl<ApiHolder>::SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp)
    {
        _ASSERTE(m_pComMetaImp.p == nullptr);
        m_pComMetaImp = pComMetaImp;
    }



    template<class ApiHolder>    
    void BasePortableExecutableReaderPimpl<ApiHolder>::SetAssemblyPath(path const &asmPath)
    {
        _ASSERTE(m_asmPath.empty());
        m_asmPath = asmPath;
    }



    template<class ApiHolder>    
    mapped_file_source &BasePortableExecutableReaderPimpl<ApiHolder>::GetMemoryMappedFile() const
    {
        using boost::iostreams::basic_mapped_file_params;
        using boost::iostreams::mapped_file_base;        
        using boost::filesystem::canonical;
        using boost::filesystem::path;
        using Urasandesu::CppAnonym::CppAnonymException;

        typedef basic_mapped_file_params<path> MappedFileParams;

        if (!m_file.is_open())
        {
            auto params = MappedFileParams(canonical(m_asmPath));
            params.flags = mapped_file_base::readonly;
            try
            {
                m_file.open(params);
            }
            catch (...)
            {
                auto oss = std::ostringstream();
                oss << diagnostic_information(boost::current_exception());
                BOOST_THROW_EXCEPTION(CppAnonymException(oss.str()));
            }
        }
        return m_file;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_HPP

