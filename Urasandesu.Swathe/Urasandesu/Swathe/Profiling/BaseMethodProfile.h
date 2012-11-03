#pragma once
#ifndef URASANDESU_SWATHE_PROFILING_BASEMETHODPROFILE_H
#define URASANDESU_SWATHE_PROFILING_BASEMETHODPROFILE_H

#ifndef URASANDESU_SWATHE_TRAITS_REPLACE_H
#include <Urasandesu/Swathe/Traits/Replace.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling {

#ifdef UNT
#error This .h reserves the word "UNT" that means "Urasandesu::Swathe::Traits".
#endif
#define UNT Urasandesu::Swathe::Traits

    template<
        class HeapManagerType,
        class ApiType
    >        
    class ATL_NO_VTABLE IProfilingApiOperable;

    template<
        class InfoProfilingApiType
    >
    class BaseProcessProfile;

    struct DefaultInfoProfilingApi;

    template<
        class InfoProfilingApiType
    >
    class BaseMethodBodyProfile;

    template<
        class InfoProfilingApiType = boost::use_default
    >
    class BaseMethodProfile : 
        public IProfilingApiOperable<
            BaseProcessProfile<InfoProfilingApiType>, 
            typename UNT::Replace<InfoProfilingApiType, boost::use_default, DefaultInfoProfilingApi>::type
        >
    {
    public:
        BaseMethodBodyProfile<InfoProfilingApiType> *GetMethodBody()
        {
            HRESULT hr = E_FAIL;
            
            ClassID classId = 0;
            ModuleID modId = 0;
            mdToken mdt = mdTokenNil;
            hr = GetApi()->ProfilerInfo->GetFunctionInfo(GetID(), &classId, &modId, &mdt);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            
            LPCBYTE pMethodBodyAll = NULL;
            ULONG methodBodyAllSize = 0;
            hr = GetApi()->ProfilerInfo->GetILFunctionBody(modId, mdt, &pMethodBodyAll, &methodBodyAllSize);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            
            BaseMethodBodyProfile<InfoProfilingApiType> *pBodyProf = NULL;
            pBodyProf = CreateIfNecessary<BaseMethodBodyProfile<InfoProfilingApiType>>(reinterpret_cast<UINT_PTR>(pMethodBodyAll));
            return pBodyProf;
        }

        void SetMethodBody(BaseMethodBodyProfile<InfoProfilingApiType> *pBodyProf)
        {
            HRESULT hr = E_FAIL;
            
            COR_ILMETHOD *pILMethod = reinterpret_cast<COR_ILMETHOD *>(pBodyProf->GetID());

            ClassID classId = 0;
            ModuleID modId = 0;
            mdToken mdt = mdTokenNil;
            hr = GetApi()->ProfilerInfo->GetFunctionInfo(GetID(), &classId, &modId, &mdt);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            
            CComPtr<IMethodMalloc> pMethodMalloc;
            hr = GetApi()->ProfilerInfo->GetILFunctionBodyAllocator(modId, &pMethodMalloc);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
            
            
            unsigned headerSize = 0;
            BYTE *pCode = NULL;
            unsigned codeSize = 0;
            if (pILMethod->Fat.IsFat())
            {
                headerSize = sizeof(COR_ILMETHOD_FAT);
                pCode = pILMethod->Fat.GetCode();
                codeSize = pILMethod->Fat.GetCodeSize();
            }
            else
            {
                headerSize = sizeof(COR_ILMETHOD_TINY);
                pCode = pILMethod->Tiny.GetCode();
                codeSize = pILMethod->Tiny.GetCodeSize();
            }
            unsigned totalSize = headerSize + codeSize;
            
            
            BYTE *pNewILFunctionBody = reinterpret_cast<BYTE*>(pMethodMalloc->Alloc(totalSize));
            BYTE *pBuffer = pNewILFunctionBody;
            if (pILMethod->Fat.IsFat())
            {
                COR_ILMETHOD_FAT* pILMethodFat = reinterpret_cast<COR_ILMETHOD_FAT *>(pBuffer);
                pBuffer += sizeof(COR_ILMETHOD_FAT);
                *pILMethodFat = pILMethod->Fat;
                pILMethodFat->SetFlags(pILMethodFat->GetFlags() | CorILMethod_FatFormat);
                pILMethodFat->SetSize(sizeof(COR_ILMETHOD_FAT) / 4);
                // TODO: Add the process if there are more sections...
            }
            else
            {
                *pBuffer++ = static_cast<BYTE>(CorILMethod_TinyFormat | (pILMethod->Tiny.GetCodeSize() << 2));
            }
            ::memcpy_s(pBuffer, totalSize - headerSize, pCode, codeSize);
            
            hr = GetApi()->ProfilerInfo->SetILFunctionBody(modId, mdt, pNewILFunctionBody);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(SwatheCOMException(hr));
        }
    };

    typedef BaseMethodProfile<boost::use_default> MethodProfile;

#undef UNT

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_BASEMETHODPROFILE_H