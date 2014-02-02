/* 
 * File: HostingDependsOn.h
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
#ifndef URASANDESU_SWATHE_HOSTING_HOSTINGDEPENDSON_H
#define URASANDESU_SWATHE_HOSTING_HOSTINGDEPENDSON_H

#include <ICeeFileGen.h>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

namespace Urasandesu { namespace Swathe { namespace Hosting {

    template<class PEDataIterator, class Size, class OutIterator>
    PEDataIterator PEGetData(PEDataIterator i, PEDataIterator i_end, Size count, OutIterator dest)
    {
        using std::copy;
        
        auto i_sub_end = i + count;
        if (i_sub_end == i_end)
            return i_end;
        
        copy(i, i_sub_end, dest);
        
        return i_sub_end;
    }
    
    
    
    template<class PEDataIterator>
    PEDataIterator PEGetDOSHeader(PEDataIterator const &i, PEDataIterator const &i_end, IMAGE_DOS_HEADER &dosHeader)
    {
        return PEGetData(i, i_end, sizeof(IMAGE_DOS_HEADER), reinterpret_cast<BYTE *>(&dosHeader));
    }
    
    
    
    template<class PEDataIterator>
    PEDataIterator PEGetNTHeaders(PEDataIterator const &i, PEDataIterator const &i_end, IMAGE_NT_HEADERS &ntHeaders)
    {
        return PEGetData(i, i_end, sizeof(IMAGE_NT_HEADERS), reinterpret_cast<BYTE *>(&ntHeaders));
    }
    
    
    
    template<class PEDataIterator>
    PEDataIterator PEGetSectionHeader(PEDataIterator const &i, PEDataIterator const &i_end, IMAGE_SECTION_HEADER &secHeader)
    {
        return PEGetData(i, i_end, sizeof(IMAGE_SECTION_HEADER), reinterpret_cast<BYTE *>(&secHeader));
    }

}}}  // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // #ifndef URASANDESU_SWATHE_HOSTING_HOSTINGDEPENDSON_H
