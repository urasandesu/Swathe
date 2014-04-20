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

namespace Urasandesu { namespace Swathe { namespace Profiling {

    template<
        class Base
    >
    class ATL_NO_VTABLE ICorProfilerCallbackImpl : public Base
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

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACKIMPL_H
