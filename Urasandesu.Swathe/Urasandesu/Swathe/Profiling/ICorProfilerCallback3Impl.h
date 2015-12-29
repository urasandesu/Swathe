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

#include <boost/version.hpp> 
#if defined(_MSC_VER) && BOOST_VERSION == 106000 
#pragma warning(push)
#pragma warning(disable:4003)
#undef BOOST_PP_VARIADICS
#define BOOST_PP_VARIADICS 0 
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling {

    template<
        class Base
    >
    class ATL_NO_VTABLE ICorProfilerCallback3WithoutChainImpl : public ICorProfilerCallback2WithoutChainImpl<Base>
    {
        CPPANONYM_STDMETHOD_NOEXCEPT(InitializeForAttach, ((IUnknown *,pCorProfilerInfoUnk))((void *,pvClientData))((UINT,cbClientData)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ProfilerAttachComplete, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(ProfilerDetachSucceeded, BOOST_PP_EMPTY())
    };



    template<
        class Base
    >
    class ATL_NO_VTABLE ICorProfilerCallback3Impl : public ICorProfilerCallback2Impl<Base>
    {
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(InitializeForAttach, ((IUnknown *,pCorProfilerInfoUnk))((void *,pvClientData))((UINT,cbClientData)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ProfilerAttachComplete, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ProfilerDetachSucceeded, BOOST_PP_EMPTY())
        
        
        
    protected:
        ICorProfilerCallback3 &GetCOMExternalProfilerCallback()
        {
            using Urasandesu::CppAnonym::CppAnonymCOMException;
            
            if (!m_pComProfExtCallback3)
            {
                auto &comProfExtCallback = ICorProfilerCallback2Impl<Base>::GetCOMExternalProfilerCallback();
                auto hr = comProfExtCallback.QueryInterface(IID_ICorProfilerCallback3, reinterpret_cast<void **>(&m_pComProfExtCallback3));
                if (FAILED(hr)) 
                {
                    m_pComProfExtCallback3 = ATL::CComPtr<ICorProfilerCallback3>(&GetEmptyCOMExternalProfilerCallback());
                    return *m_pComProfExtCallback3;
                }
            }
            return *m_pComProfExtCallback3;
        }
        
        
        
    private:
        struct empty_profiler_callback : ICorProfilerCallback3WithoutChainImpl<ICorProfilerCallback3>
        {
            STDMETHOD(QueryInterface)(REFIID riid, _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject) { return E_NOINTERFACE; }
            STDMETHOD_(ULONG, AddRef)(void) { return 0; }
            STDMETHOD_(ULONG, Release)(void) { return 0; }
        };



        static ICorProfilerCallback3 &GetEmptyCOMExternalProfilerCallback()
        {
            static empty_profiler_callback emptyProfCallback;
            return emptyProfCallback;
        }



        ATL::CComPtr<ICorProfilerCallback3> m_pComProfExtCallback3;
    };

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK3IMPL_H

#if defined(_MSC_VER) && BOOST_VERSION == 106000 
#pragma warning(pop)
#undef BOOST_PP_VARIADICS
#define BOOST_PP_VARIADICS 1
#endif
