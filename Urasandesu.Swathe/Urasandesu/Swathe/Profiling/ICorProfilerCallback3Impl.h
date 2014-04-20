/* 
 * File: ICorProfilerCallback3Impl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK3IMPL_H
#define URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK3IMPL_H

#ifndef URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK2IMPL_H
#include <Urasandesu/Swathe/Profiling/ICorProfilerCallback2Impl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling {

    template<
        class Base
    >
    class ATL_NO_VTABLE ICorProfilerCallback3Impl : public ICorProfilerCallback2Impl<Base>
    {
        CPPANONYM_STDMETHOD_NOEXCEPT(InitializeForAttach, ((IUnknown *,pCorProfilerInfoUnk))((void *,pvClientData))((UINT,cbClientData)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ProfilerAttachComplete, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(ProfilerDetachSucceeded, BOOST_PP_EMPTY())
    };

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK3IMPL_H
