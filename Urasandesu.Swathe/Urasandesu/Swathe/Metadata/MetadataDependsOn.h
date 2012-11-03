#pragma once
#ifndef URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H
#define URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H

#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/any.hpp>
#include <boost/array.hpp>
#include <boost/make_shared.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/any_range.hpp>
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
            return (pTmpData - pData) / sizeof(COR_SIGNATURE);
        }
    }

}}} // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H