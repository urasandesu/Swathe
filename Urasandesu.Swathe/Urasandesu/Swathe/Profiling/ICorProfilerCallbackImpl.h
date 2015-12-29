/* 
 * File: ICorProfilerCallbackImpl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACKIMPL_H
#define URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACKIMPL_H

#ifndef URASANDESU_SWATHE_PROFILING_PROFILINGSPECIALVALUES_H
#include <Urasandesu/Swathe/Profiling/ProfilingSpecialValues.h>
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
    class ATL_NO_VTABLE ICorProfilerCallbackWithoutChainImpl : public Base
    {
        CPPANONYM_STDMETHOD_NOEXCEPT(Initialize, ((IUnknown*,pICorProfilerInfoUnk)))
        CPPANONYM_STDMETHOD_NOEXCEPT(Shutdown, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(AppDomainCreationStarted, ((AppDomainID,appDomainId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(AppDomainCreationFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(AppDomainShutdownStarted, ((AppDomainID,appDomainId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(AppDomainShutdownFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(AssemblyLoadStarted, ((AssemblyID,assemblyId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(AssemblyLoadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(AssemblyUnloadStarted, ((AssemblyID,assemblyId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(AssemblyUnloadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ModuleLoadStarted, ((ModuleID,moduleId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ModuleLoadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ModuleUnloadStarted, ((ModuleID,moduleId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ModuleUnloadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ModuleAttachedToAssembly, ((ModuleID,moduleId))((AssemblyID,AssemblyId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ClassLoadStarted, ((ClassID,classId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ClassLoadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ClassUnloadStarted, ((ClassID,classId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ClassUnloadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        CPPANONYM_STDMETHOD_NOEXCEPT(FunctionUnloadStarted, ((FunctionID,functionId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(JITCompilationStarted, ((FunctionID,functionId))((BOOL,fIsSafeToBlock)))
        CPPANONYM_STDMETHOD_NOEXCEPT(JITCompilationFinished, ((FunctionID,functionId))((HRESULT,hrStatus))((BOOL,fIsSafeToBlock)))
        CPPANONYM_STDMETHOD_NOEXCEPT(JITCachedFunctionSearchStarted, ((FunctionID,functionId))((BOOL*,pbUseCachedFunction)))
        CPPANONYM_STDMETHOD_NOEXCEPT(JITCachedFunctionSearchFinished, ((FunctionID,functionId))((COR_PRF_JIT_CACHE,result)))
        CPPANONYM_STDMETHOD_NOEXCEPT(JITFunctionPitched, ((FunctionID,functionId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(JITInlining, ((FunctionID,callerId))((FunctionID,calleeId))((BOOL*,pfShouldInline)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ThreadCreated, ((ThreadID,threadId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ThreadDestroyed, ((ThreadID,threadId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ThreadAssignedToOSThread, ((ThreadID,managedThreadId))((DWORD,osThreadId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingClientInvocationStarted, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingClientSendingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingClientReceivingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingClientInvocationFinished, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingServerReceivingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingServerInvocationStarted, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingServerInvocationReturned, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RemotingServerSendingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_STDMETHOD_NOEXCEPT(UnmanagedToManagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ManagedToUnmanagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RuntimeSuspendStarted, ((COR_PRF_SUSPEND_REASON,suspendReason)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RuntimeSuspendFinished, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RuntimeSuspendAborted, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RuntimeResumeStarted, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RuntimeResumeFinished, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(RuntimeThreadSuspended, ((ThreadID,threadId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RuntimeThreadResumed, ((ThreadID,threadId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(MovedReferences, ((ULONG,cMovedObjectIDRanges))((ObjectID*,oldObjectIDRangeStart))((ObjectID*,newObjectIDRangeStart))((ULONG*,cObjectIDRangeLength)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ObjectAllocated, ((ObjectID,objectId))((ClassID,classId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ObjectsAllocatedByClass, ((ULONG,cClassCount))((ClassID*,classIds))((ULONG*,cObjects)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ObjectReferences, ((ObjectID,objectId))((ClassID,classId))((ULONG,cObjectRefs))((ObjectID*,objectRefIds)))
        CPPANONYM_STDMETHOD_NOEXCEPT(RootReferences, ((ULONG,cRootRefs))((ObjectID*,rootRefIds)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionThrown, ((ObjectID,thrownObjectId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionSearchFunctionEnter, ((FunctionID,functionId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionSearchFunctionLeave, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionSearchFilterEnter, ((FunctionID,functionId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionSearchFilterLeave, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionSearchCatcherFound, ((FunctionID,functionId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionOSHandlerEnter, ((UINT_PTR,__unused)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionOSHandlerLeave, ((UINT_PTR,__unused)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionUnwindFunctionEnter, ((FunctionID,functionId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionUnwindFunctionLeave, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionUnwindFinallyEnter, ((FunctionID,functionId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionUnwindFinallyLeave, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionCatcherEnter, ((FunctionID,functionId))((ObjectID,objectId)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionCatcherLeave, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(COMClassicVTableCreated, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable))((ULONG,cSlots)))
        CPPANONYM_STDMETHOD_NOEXCEPT(COMClassicVTableDestroyed, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable)))
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionCLRCatcherFound, BOOST_PP_EMPTY())
        CPPANONYM_STDMETHOD_NOEXCEPT(ExceptionCLRCatcherExecute, BOOST_PP_EMPTY())
    };



#define SWATHE_PROFILING_STDMETHOD_ARG(r, data, i, elem) \
    BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(2, 0, elem) BOOST_PP_TUPLE_ELEM(2, 1, elem)

#define SWATHE_PROFILING_STDMETHOD_LOAD_ARG(r, data, i, elem) \
    BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(2, 1, elem)

#define SWATHE_PROFILING_STDMETHOD_NOEXCEPT(method, args_tuple_seq) \
    public: \
        STDMETHOD(method)(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_ARG, _, args_tuple_seq)) \
        { \
            using namespace std; \
            using namespace boost; \
            using namespace Urasandesu::CppAnonym; \
             \
            try \
            { \
                GetCOMExternalProfilerCallback().method(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_LOAD_ARG, _, args_tuple_seq)); \
                return method##Core(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_LOAD_ARG, _, args_tuple_seq)); \
            } \
            catch (CppAnonymException &e) \
            { \
                if (CPPANONYM_E_LOG_ENABLED()) \
                { \
                    auto oss = std::ostringstream(); \
                    oss << diagnostic_information(e); \
                    CPPANONYM_E_LOG(oss.str()); \
                } \
            } \
            catch (...) \
            { \
                if (CPPANONYM_E_LOG_ENABLED()) \
                { \
                    auto oss = std::ostringstream(); \
                    oss << diagnostic_information(boost::current_exception()); \
                    CPPANONYM_E_LOG(oss.str()); \
                } \
            } \
             \
            return S_OK; \
        } \
         \
    protected: \
        STDMETHOD(method##Core)(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_ARG, _, args_tuple_seq)) \
        { \
            return S_OK; \
        }


#define SWATHE_PROFILING_STDMETHOD_VOID_NOEXCEPT(method, args_tuple_seq) \
    public: \
        STDMETHOD_(void, method)(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_ARG, _, args_tuple_seq)) \
        { \
            using namespace std; \
            using namespace boost; \
            using namespace Urasandesu::CppAnonym; \
             \
            try \
            { \
                GetCOMExternalProfilerCallback().method(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_LOAD_ARG, _, args_tuple_seq)); \
                method##Core(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_LOAD_ARG, _, args_tuple_seq)); \
            } \
            catch (CppAnonymException &e) \
            { \
                if (CPPANONYM_E_LOG_ENABLED()) \
                { \
                    auto oss = std::ostringstream(); \
                    oss << diagnostic_information(e); \
                    CPPANONYM_E_LOG(oss.str()); \
                } \
            } \
            catch (...) \
            { \
                if (CPPANONYM_E_LOG_ENABLED()) \
                { \
                    auto oss = std::ostringstream(); \
                    oss << diagnostic_information(boost::current_exception()); \
                    CPPANONYM_E_LOG(oss.str()); \
                } \
            } \
        } \
         \
    protected: \
        STDMETHOD_(void, method##Core)(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_ARG, _, args_tuple_seq)) \
        { \
        }


#define SWATHE_PROFILING_STDMETHOD__NOEXCEPT(ret, method, args_tuple_seq) \
    public: \
        STDMETHOD_(ret, method)(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_ARG, _, args_tuple_seq)) \
        { \
            using namespace std; \
            using namespace boost; \
            using namespace Urasandesu::CppAnonym; \
             \
            try \
            { \
                GetCOMExternalProfilerCallback().method(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_LOAD_ARG, _, args_tuple_seq)); \
                return method##Core(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_LOAD_ARG, _, args_tuple_seq)); \
            } \
            catch (CppAnonymException &e) \
            { \
                if (CPPANONYM_E_LOG_ENABLED()) \
                { \
                    auto oss = std::ostringstream(); \
                    oss << diagnostic_information(e); \
                    CPPANONYM_E_LOG(oss.str()); \
                } \
            } \
            catch (...) \
            { \
                if (CPPANONYM_E_LOG_ENABLED()) \
                { \
                    auto oss = std::ostringstream(); \
                    oss << diagnostic_information(boost::current_exception()); \
                    CPPANONYM_E_LOG(oss.str()); \
                } \
            } \
             \
            return ret(); \
        } \
         \
    protected: \
        STDMETHOD_(ret, method##Core)(BOOST_PP_SEQ_FOR_EACH_I(SWATHE_PROFILING_STDMETHOD_ARG, _, args_tuple_seq)) \
        { \
            return ret(); \
        }



    template<
        class Base
    >
    class ATL_NO_VTABLE ICorProfilerCallbackImpl : public Base
    {
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(Initialize, ((IUnknown*,pICorProfilerInfoUnk)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(Shutdown, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AppDomainCreationStarted, ((AppDomainID,appDomainId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AppDomainCreationFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AppDomainShutdownStarted, ((AppDomainID,appDomainId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AppDomainShutdownFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AssemblyLoadStarted, ((AssemblyID,assemblyId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AssemblyLoadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AssemblyUnloadStarted, ((AssemblyID,assemblyId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(AssemblyUnloadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ModuleLoadStarted, ((ModuleID,moduleId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ModuleLoadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ModuleUnloadStarted, ((ModuleID,moduleId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ModuleUnloadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ModuleAttachedToAssembly, ((ModuleID,moduleId))((AssemblyID,AssemblyId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ClassLoadStarted, ((ClassID,classId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ClassLoadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ClassUnloadStarted, ((ClassID,classId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ClassUnloadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(FunctionUnloadStarted, ((FunctionID,functionId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(JITCompilationStarted, ((FunctionID,functionId))((BOOL,fIsSafeToBlock)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(JITCompilationFinished, ((FunctionID,functionId))((HRESULT,hrStatus))((BOOL,fIsSafeToBlock)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(JITCachedFunctionSearchStarted, ((FunctionID,functionId))((BOOL*,pbUseCachedFunction)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(JITCachedFunctionSearchFinished, ((FunctionID,functionId))((COR_PRF_JIT_CACHE,result)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(JITFunctionPitched, ((FunctionID,functionId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(JITInlining, ((FunctionID,callerId))((FunctionID,calleeId))((BOOL*,pfShouldInline)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ThreadCreated, ((ThreadID,threadId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ThreadDestroyed, ((ThreadID,threadId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ThreadAssignedToOSThread, ((ThreadID,managedThreadId))((DWORD,osThreadId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingClientInvocationStarted, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingClientSendingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingClientReceivingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingClientInvocationFinished, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingServerReceivingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingServerInvocationStarted, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingServerInvocationReturned, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RemotingServerSendingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(UnmanagedToManagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ManagedToUnmanagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RuntimeSuspendStarted, ((COR_PRF_SUSPEND_REASON,suspendReason)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RuntimeSuspendFinished, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RuntimeSuspendAborted, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RuntimeResumeStarted, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RuntimeResumeFinished, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RuntimeThreadSuspended, ((ThreadID,threadId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RuntimeThreadResumed, ((ThreadID,threadId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(MovedReferences, ((ULONG,cMovedObjectIDRanges))((ObjectID*,oldObjectIDRangeStart))((ObjectID*,newObjectIDRangeStart))((ULONG*,cObjectIDRangeLength)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ObjectAllocated, ((ObjectID,objectId))((ClassID,classId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ObjectsAllocatedByClass, ((ULONG,cClassCount))((ClassID*,classIds))((ULONG*,cObjects)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ObjectReferences, ((ObjectID,objectId))((ClassID,classId))((ULONG,cObjectRefs))((ObjectID*,objectRefIds)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(RootReferences, ((ULONG,cRootRefs))((ObjectID*,rootRefIds)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionThrown, ((ObjectID,thrownObjectId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionSearchFunctionEnter, ((FunctionID,functionId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionSearchFunctionLeave, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionSearchFilterEnter, ((FunctionID,functionId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionSearchFilterLeave, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionSearchCatcherFound, ((FunctionID,functionId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionOSHandlerEnter, ((UINT_PTR,__unused)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionOSHandlerLeave, ((UINT_PTR,__unused)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionUnwindFunctionEnter, ((FunctionID,functionId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionUnwindFunctionLeave, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionUnwindFinallyEnter, ((FunctionID,functionId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionUnwindFinallyLeave, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionCatcherEnter, ((FunctionID,functionId))((ObjectID,objectId)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionCatcherLeave, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(COMClassicVTableCreated, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable))((ULONG,cSlots)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(COMClassicVTableDestroyed, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable)))
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionCLRCatcherFound, BOOST_PP_EMPTY())
        SWATHE_PROFILING_STDMETHOD_NOEXCEPT(ExceptionCLRCatcherExecute, BOOST_PP_EMPTY())
        
        
        
    protected:
        ICorProfilerCallback &GetCOMExternalProfilerCallback()
        {
            using Urasandesu::CppAnonym::CppAnonymCOMException;
            
            if (!m_pComProfExtCallback)
            {
                auto &comExtProfFactory = GetCOMExternalProfilerClassFactory();
                auto hr = comExtProfFactory.CreateInstance(nullptr, IID_ICorProfilerCallback, reinterpret_cast<void **>(&m_pComProfExtCallback));
                if (FAILED(hr)) 
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComProfExtCallback;
        }
        
        
        
    private:
        struct empty_profiler_callback : ICorProfilerCallbackWithoutChainImpl<ICorProfilerCallback>
        {
            STDMETHOD(QueryInterface)(REFIID riid, _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject) { return E_NOINTERFACE; }
            STDMETHOD_(ULONG, AddRef)(void) { return 0; }
            STDMETHOD_(ULONG, Release)(void) { return 0; }
        };

        
        
        struct empty_class_factory : IClassFactory
        {
            STDMETHOD(QueryInterface)(REFIID riid, _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject) { return E_NOINTERFACE; }
            STDMETHOD_(ULONG, AddRef)(void) { return 0; }
            STDMETHOD_(ULONG, Release)(void) { return 0; }

            STDMETHOD(LockServer)(BOOL fLock) { return S_OK; }

            
            
            STDMETHOD(CreateInstance)(IUnknown *pUnkOuter, REFIID riid, void **ppvObject) 
            { 
                if (!ppvObject)
                    return E_POINTER;
                
                auto hr = E_NOINTERFACE;
                if (::IsEqualCLSID(riid, IID_ICorProfilerCallback))
                {
                    *ppvObject = &GetEmptyCOMExternalProfilerCallback();
                    hr = S_OK;
                }
                return hr; 
            }


        
            static ICorProfilerCallback &GetEmptyCOMExternalProfilerCallback()
            {
                static empty_profiler_callback emptyProfCallback;
                return emptyProfCallback;
            }
        };



        IClassFactory &GetCOMExternalProfilerClassFactory()
        {
            using Urasandesu::CppAnonym::CppAnonymCOMException;
            using Urasandesu::CppAnonym::Environment;
            using Urasandesu::CppAnonym::Utilities::CComClassFactorySlim;
            using Urasandesu::CppAnonym::Utilities::CComObjectSlim;
            
            if (!m_pComExtProfFactory)
            {
                auto strExtProf = Environment::GetEnvironmentVariable(ProfilingSpecialValues::EXTERNAL_PROFILER_KEY);
                if (strExtProf.empty())
                {
                    m_pComExtProfFactory = ATL::CComPtr<IClassFactory>(&GetEmptyCOMExternalProfilerClassFactory());
                    return *m_pComExtProfFactory;
                }
                
                auto extProf = IID();
                {
                    auto hr = ::IIDFromString(strExtProf.c_str(), &extProf);
                    if (FAILED(hr)) 
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
                
                {
                    typedef CComObjectSlim<CComClassFactorySlim> ExternalProfilerClassFactoryObject;
                    
                    auto *pComExtProfFactory = static_cast<ExternalProfilerClassFactoryObject *>(nullptr);
                    auto hr = ExternalProfilerClassFactoryObject::CreateInstance(&pComExtProfFactory);
                    if (FAILED(hr)) 
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                    
                    hr = pComExtProfFactory->Initialize(extProf);
                    if (FAILED(hr)) 
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                    
                    m_pComExtProfFactory = ATL::CComPtr<IClassFactory>(pComExtProfFactory);
                }
            }
            return *m_pComExtProfFactory;
        }


        
        static IClassFactory &GetEmptyCOMExternalProfilerClassFactory()
        {
            static empty_class_factory emptyClassFactory;
            return emptyClassFactory;
        }
        
        
        
        ATL::CComPtr<IClassFactory> m_pComExtProfFactory;
        ATL::CComPtr<ICorProfilerCallback> m_pComProfExtCallback;
    };

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACKIMPL_H

#if defined(_MSC_VER) && BOOST_VERSION == 106000 
#pragma warning(pop)
#undef BOOST_PP_VARIADICS
#define BOOST_PP_VARIADICS 1
#endif
