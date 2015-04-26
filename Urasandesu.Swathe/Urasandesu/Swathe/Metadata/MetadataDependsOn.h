/* 
 * File: MetadataDependsOn.h
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
#ifndef URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H
#define URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H

#include <vector>
#include <boost/array.hpp>
#include <boost/make_shared.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/shared_ptr.hpp>

namespace Urasandesu { namespace Swathe { namespace Metadata {

    inline ULONG CorSigUncompressSerString( // return number of bytes of that compressed string occupied in pData 
        PCCOR_SIGNATURE pData,              // [IN] compressed data 
        CHAR const **ppStr,                 // [OUT] string value of the expanded *pData    
        ULONG *pStrSize)                    // [OUT] string size of the expanded *pData    
    {
        PCCOR_SIGNATURE pTmpData = pData;
        if (*pTmpData == 0xFF)
        {
            // NULL pointer
            *pStrSize = 0;
            *ppStr = NULL;
            return 1;
        }
        else
        {
            pTmpData += ::CorSigUncompressData(pTmpData, pStrSize);
            *ppStr = reinterpret_cast<CHAR const*>(pTmpData);
            pTmpData += sizeof(CHAR) * *pStrSize;
            return static_cast<ULONG>((pTmpData - pData) / sizeof(COR_SIGNATURE));
        }
    }

    typedef mdToken mdTypeVar;              // ELEMENT_TYPE_VAR type token
    typedef mdToken mdTypeMVar;             // ELEMENT_TYPE_MVAR type token

    typedef enum CorTokenTypeEx
    {
        mdtTypeVar              = 0x1c000000,       // 
        mdtTypeMVar             = 0x1d000000,       // 
    } CorTokenTypeEx;

    #define mdTypeVarNil                ((mdTypeVar)mdtTypeVar)
    #define mdTypeMVarNil               ((mdTypeMVar)mdtTypeMVar)

}}} // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H
