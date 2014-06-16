/* 
 * File: IPortableExecutableReader.h
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
#ifndef URASANDESU_SWATHE_HOSTING_IPORTABLEEXECUTABLEREADER_H
#define URASANDESU_SWATHE_HOSTING_IPORTABLEEXECUTABLEREADER_H

#ifndef URASANDESU_SWATHE_HOSTING_IPORTABLEEXECUTABLEREADERFWD_H
#include <Urasandesu/Swathe/Hosting/IPortableExecutableReaderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { 
    
    struct IPortableExecutableReader
    {
        IPortableExecutableReader() { }
        virtual boost::iterator_range<BYTE const *> GetMappedFileSource() const = 0;
        virtual BYTE const *AdvanceToSectionHeader(BYTE const *i, BYTE const *i_end) const = 0;
        virtual BYTE const *GetPEHeaders(BYTE const *i, BYTE const *i_end, IMAGE_DOS_HEADER &dosHeader, boost::array<BYTE, 0x40> &dosStubBody, IMAGE_FILE_HEADER &fileHeader, IMAGE_NT_HEADERS32 &ntHeaders32, IMAGE_NT_HEADERS64 &ntHeaders64) const = 0;
        virtual void GetPEKind(DWORD &dwPEKind, DWORD &dwMachine) const = 0;
        //virtual void GetPEKindAndVersionString(DWORD &dwPEKind, DWORD &dwMachine, std::wstring &verStr) const = 0;
        virtual COR_ILMETHOD const *GetILMethodBody(ULONG codeRVA) const = 0;
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // URASANDESU_SWATHE_HOSTING_IPORTABLEEXECUTABLEREADER_H

