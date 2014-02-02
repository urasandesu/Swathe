/* 
 * File: ICorProfilerCallback2Impl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK2IMPL_H
#define URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK2IMPL_H

namespace Urasandesu { namespace Swathe { namespace Profiling {

    template<
        class Base
    >
    class ATL_NO_VTABLE ICorProfilerCallback2Impl : public Base
    {
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(Initialize, ((IUnknown*,pICorProfilerInfoUnk)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(Shutdown, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainCreationStarted, ((AppDomainID,appDomainId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainCreationFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainShutdownStarted, ((AppDomainID,appDomainId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainShutdownFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyLoadStarted, ((AssemblyID,assemblyId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyLoadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyUnloadStarted, ((AssemblyID,assemblyId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyUnloadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleLoadStarted, ((ModuleID,moduleId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleLoadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleUnloadStarted, ((ModuleID,moduleId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleUnloadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleAttachedToAssembly, ((ModuleID,moduleId))((AssemblyID,AssemblyId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassLoadStarted, ((ClassID,classId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassLoadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassUnloadStarted, ((ClassID,classId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassUnloadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FunctionUnloadStarted, ((FunctionID,functionId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCompilationStarted, ((FunctionID,functionId))((BOOL,fIsSafeToBlock)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCompilationFinished, ((FunctionID,functionId))((HRESULT,hrStatus))((BOOL,fIsSafeToBlock)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCachedFunctionSearchStarted, ((FunctionID,functionId))((BOOL*,pbUseCachedFunction)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCachedFunctionSearchFinished, ((FunctionID,functionId))((COR_PRF_JIT_CACHE,result)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITFunctionPitched, ((FunctionID,functionId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITInlining, ((FunctionID,callerId))((FunctionID,calleeId))((BOOL*,pfShouldInline)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadCreated, ((ThreadID,threadId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadDestroyed, ((ThreadID,threadId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadAssignedToOSThread, ((ThreadID,managedThreadId))((DWORD,osThreadId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientInvocationStarted, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientSendingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientReceivingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientInvocationFinished, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerReceivingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerInvocationStarted, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerInvocationReturned, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerSendingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(UnmanagedToManagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ManagedToUnmanagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeSuspendStarted, ((COR_PRF_SUSPEND_REASON,suspendReason)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeSuspendFinished, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeSuspendAborted, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeResumeStarted, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeResumeFinished, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeThreadSuspended, ((ThreadID,threadId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeThreadResumed, ((ThreadID,threadId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(MovedReferences, ((ULONG,cMovedObjectIDRanges))((ObjectID*,oldObjectIDRangeStart))((ObjectID*,newObjectIDRangeStart))((ULONG*,cObjectIDRangeLength)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ObjectAllocated, ((ObjectID,objectId))((ClassID,classId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ObjectsAllocatedByClass, ((ULONG,cClassCount))((ClassID*,classIds))((ULONG*,cObjects)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ObjectReferences, ((ObjectID,objectId))((ClassID,classId))((ULONG,cObjectRefs))((ObjectID*,objectRefIds)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RootReferences, ((ULONG,cRootRefs))((ObjectID*,rootRefIds)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionThrown, ((ObjectID,thrownObjectId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFunctionEnter, ((FunctionID,functionId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFunctionLeave, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFilterEnter, ((FunctionID,functionId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFilterLeave, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchCatcherFound, ((FunctionID,functionId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionOSHandlerEnter, ((UINT_PTR,__unused)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionOSHandlerLeave, ((UINT_PTR,__unused)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFunctionEnter, ((FunctionID,functionId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFunctionLeave, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFinallyEnter, ((FunctionID,functionId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFinallyLeave, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCatcherEnter, ((FunctionID,functionId))((ObjectID,objectId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCatcherLeave, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(COMClassicVTableCreated, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable))((ULONG,cSlots)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(COMClassicVTableDestroyed, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCLRCatcherFound, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCLRCatcherExecute, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadNameChanged, ((ThreadID,threadId))((ULONG,cchName))((WCHAR*,name)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GarbageCollectionStarted, ((int,cGenerations))((BOOL*,generationCollected))((COR_PRF_GC_REASON,reason)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(SurvivingReferences, ((ULONG,cSurvivingObjectIDRanges))((ObjectID*,objectIDRangeStart))((ULONG*,cObjectIDRangeLength)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GarbageCollectionFinished, BOOST_PP_EMPTY())
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FinalizeableObjectQueued, ((DWORD,finalizerFlags))((ObjectID,objectID)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RootReferences2, ((ULONG,cRootRefs))((ObjectID*,rootRefIds))((COR_PRF_GC_ROOT_KIND*,rootKinds))((COR_PRF_GC_ROOT_FLAGS*,rootFlags))((UINT_PTR*,rootIds)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(HandleCreated, ((GCHandleID,handleId))((ObjectID,initialObjectId)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(HandleDestroyed, ((GCHandleID,handleId)))
    };

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK2IMPL_H
