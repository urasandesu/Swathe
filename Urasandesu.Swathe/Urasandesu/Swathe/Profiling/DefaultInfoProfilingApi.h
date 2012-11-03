#pragma once
#ifndef URASANDESU_SWATHE_PROFILING_DEFAULTINFOPROFILINGAPI_H
#define URASANDESU_SWATHE_PROFILING_DEFAULTINFOPROFILINGAPI_H

namespace Urasandesu { namespace Swathe { namespace Profiling {

    struct DefaultInfoProfilingApi
    {
        typedef ICorProfilerInfo2 IProfilerInfo;
        static IID const IID_IProfilerInfo;
        ATL::CComPtr<IProfilerInfo> ProfilerInfo;
    };
        
}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_DEFAULTINFOPROFILINGAPI_H