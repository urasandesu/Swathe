#pragma once
#ifndef URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK2IMPL_H
#define URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK2IMPL_H

#ifndef URASANDESU_SWATHE_DEFAULTSTDMETHODWRAPPER_H
#include <Urasandesu/Swathe/DefaultSTDMETHODWrapper.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling {

    template<
        class Base
    >
    class ATL_NO_VTABLE ICorProfilerCallback2Impl : public Base
    {
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(Initialize, ((IUnknown*,pICorProfilerInfoUnk)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(Shutdown, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainCreationStarted, ((AppDomainID,appDomainId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainCreationFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainShutdownStarted, ((AppDomainID,appDomainId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AppDomainShutdownFinished, ((AppDomainID,appDomainId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyLoadStarted, ((AssemblyID,assemblyId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyLoadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyUnloadStarted, ((AssemblyID,assemblyId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(AssemblyUnloadFinished, ((AssemblyID,assemblyId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleLoadStarted, ((ModuleID,moduleId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleLoadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleUnloadStarted, ((ModuleID,moduleId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleUnloadFinished, ((ModuleID,moduleId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ModuleAttachedToAssembly, ((ModuleID,moduleId))((AssemblyID,AssemblyId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassLoadStarted, ((ClassID,classId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassLoadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassUnloadStarted, ((ClassID,classId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ClassUnloadFinished, ((ClassID,classId))((HRESULT,hrStatus)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FunctionUnloadStarted, ((FunctionID,functionId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCompilationStarted, ((FunctionID,functionId))((BOOL,fIsSafeToBlock)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCompilationFinished, ((FunctionID,functionId))((HRESULT,hrStatus))((BOOL,fIsSafeToBlock)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCachedFunctionSearchStarted, ((FunctionID,functionId))((BOOL*,pbUseCachedFunction)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITCachedFunctionSearchFinished, ((FunctionID,functionId))((COR_PRF_JIT_CACHE,result)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITFunctionPitched, ((FunctionID,functionId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(JITInlining, ((FunctionID,callerId))((FunctionID,calleeId))((BOOL*,pfShouldInline)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadCreated, ((ThreadID,threadId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadDestroyed, ((ThreadID,threadId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadAssignedToOSThread, ((ThreadID,managedThreadId))((DWORD,osThreadId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientInvocationStarted, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientSendingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientReceivingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingClientInvocationFinished, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerReceivingMessage, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerInvocationStarted, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerInvocationReturned, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RemotingServerSendingReply, ((GUID*,pCookie))((BOOL,fIsAsync)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(UnmanagedToManagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ManagedToUnmanagedTransition, ((FunctionID,functionId))((COR_PRF_TRANSITION_REASON,reason)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeSuspendStarted, ((COR_PRF_SUSPEND_REASON,suspendReason)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeSuspendFinished, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeSuspendAborted, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeResumeStarted, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeResumeFinished, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeThreadSuspended, ((ThreadID,threadId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RuntimeThreadResumed, ((ThreadID,threadId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(MovedReferences, ((ULONG,cMovedObjectIDRanges))((ObjectID*,oldObjectIDRangeStart))((ObjectID*,newObjectIDRangeStart))((ULONG*,cObjectIDRangeLength)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ObjectAllocated, ((ObjectID,objectId))((ClassID,classId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ObjectsAllocatedByClass, ((ULONG,cClassCount))((ClassID*,classIds))((ULONG*,cObjects)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ObjectReferences, ((ObjectID,objectId))((ClassID,classId))((ULONG,cObjectRefs))((ObjectID*,objectRefIds)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RootReferences, ((ULONG,cRootRefs))((ObjectID*,rootRefIds)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionThrown, ((ObjectID,thrownObjectId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFunctionEnter, ((FunctionID,functionId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFunctionLeave, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFilterEnter, ((FunctionID,functionId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchFilterLeave, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionSearchCatcherFound, ((FunctionID,functionId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionOSHandlerEnter, ((UINT_PTR,__unused)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionOSHandlerLeave, ((UINT_PTR,__unused)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFunctionEnter, ((FunctionID,functionId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFunctionLeave, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFinallyEnter, ((FunctionID,functionId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionUnwindFinallyLeave, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCatcherEnter, ((FunctionID,functionId))((ObjectID,objectId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCatcherLeave, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(COMClassicVTableCreated, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable))((ULONG,cSlots)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(COMClassicVTableDestroyed, ((ClassID,wrappedClassId))((REFGUID,implementedIID))((void*,pVTable)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCLRCatcherFound, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ExceptionCLRCatcherExecute, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ThreadNameChanged, ((ThreadID,threadId))((ULONG,cchName))((WCHAR*,name)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GarbageCollectionStarted, ((int,cGenerations))((BOOL*,generationCollected))((COR_PRF_GC_REASON,reason)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(SurvivingReferences, ((ULONG,cSurvivingObjectIDRanges))((ObjectID*,objectIDRangeStart))((ULONG*,cObjectIDRangeLength)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GarbageCollectionFinished, BOOST_PP_EMPTY())
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FinalizeableObjectQueued, ((DWORD,finalizerFlags))((ObjectID,objectID)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(RootReferences2, ((ULONG,cRootRefs))((ObjectID*,rootRefIds))((COR_PRF_GC_ROOT_KIND*,rootKinds))((COR_PRF_GC_ROOT_FLAGS*,rootFlags))((UINT_PTR*,rootIds)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(HandleCreated, ((GCHandleID,handleId))((ObjectID,initialObjectId)))
        SWATHE_DECLARE_DEFAULT_STDMETHOD_WRAPPER(HandleDestroyed, ((GCHandleID,handleId)))
    };

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_ICORPROFILERCALLBACK2IMPL_H