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
        using boost::adaptors::reversed;
        using boost::algorithm::boyer_moore_horspool_search;
        using boost::filesystem::file_size;
        using boost::make_iterator_range;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto &comMetaTbl = GetCOMMetaDataTables();
        
        auto const *pvMd = static_cast<BYTE *>(nullptr);
        auto cbMd = 0ul;
        auto hr = comMetaTbl.GetMetaDataStorage(reinterpret_cast<void const **>(&pvMd), &cbMd);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        BYTE const DOS_HEADER_PATTERN[] = {
            0x4D, 0x5A, 0x90, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 
            0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00
        };
        ULONG const DOS_HEADER_PATTERN_SIZE = sizeof(DOS_HEADER_PATTERN) / sizeof(BYTE);
        
        auto asmSize = file_size(m_asmPath);
        auto i = pvMd - asmSize;
        auto i_end = pvMd;
        auto source = make_iterator_range(i, i_end) | reversed;
        auto pattern = make_iterator_range(DOS_HEADER_PATTERN, DOS_HEADER_PATTERN + DOS_HEADER_PATTERN_SIZE) | reversed;
        auto result = boyer_moore_horspool_search(source, pattern);
        if (result == source.end())
            return iterator_range<BYTE const *>();
        
        i = &result.base()[0] - DOS_HEADER_PATTERN_SIZE;
        i_end = i + asmSize;
        return make_iterator_range(i, i_end);
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
    IMetaDataTables2 &BasePortableExecutableReaderPimpl<ApiHolder>::GetCOMMetaDataTables() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pComMetaTbl.p == nullptr)
        {
            _ASSERT(m_pComMetaImp.p);

            auto hr = m_pComMetaImp->QueryInterface(IID_IMetaDataTables2, 
                                                    reinterpret_cast<void **>(&m_pComMetaTbl));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return *m_pComMetaTbl;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEREADERPIMPL_HPP

