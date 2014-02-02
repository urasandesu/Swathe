/* 
 * File: ProfilerEvents.h
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
#ifndef URASANDESU_SWATHE_PROFILING_PROFILEREVENTS_H
#define URASANDESU_SWATHE_PROFILING_PROFILEREVENTS_H

namespace Urasandesu { namespace Swathe { namespace Profiling {

    namespace ProfilerEventsDetail {

        using Urasandesu::CppAnonym::SafeFlagsEnum;

        struct ProfilerEventsDef
        {
            enum type
            {
                PE_MONITOR_NONE = COR_PRF_MONITOR_NONE, 
                PE_MONITOR_FUNCTION_UNLOADS = COR_PRF_MONITOR_FUNCTION_UNLOADS, 
                PE_MONITOR_CLASS_LOADS = COR_PRF_MONITOR_CLASS_LOADS, 
                PE_MONITOR_MODULE_LOADS = COR_PRF_MONITOR_MODULE_LOADS, 
                PE_MONITOR_ASSEMBLY_LOADS = COR_PRF_MONITOR_ASSEMBLY_LOADS, 
                PE_MONITOR_APPDOMAIN_LOADS = COR_PRF_MONITOR_APPDOMAIN_LOADS, 
                PE_MONITOR_JIT_COMPILATION = COR_PRF_MONITOR_JIT_COMPILATION, 
                PE_MONITOR_EXCEPTIONS = COR_PRF_MONITOR_EXCEPTIONS, 
                PE_MONITOR_GC = COR_PRF_MONITOR_GC, 
                PE_MONITOR_OBJECT_ALLOCATED = COR_PRF_MONITOR_OBJECT_ALLOCATED, 
                PE_MONITOR_THREADS = COR_PRF_MONITOR_THREADS, 
                PE_MONITOR_REMOTING = COR_PRF_MONITOR_REMOTING, 
                PE_MONITOR_CODE_TRANSITIONS = COR_PRF_MONITOR_CODE_TRANSITIONS, 
                PE_MONITOR_ENTERLEAVE = COR_PRF_MONITOR_ENTERLEAVE, 
                PE_MONITOR_CCW = COR_PRF_MONITOR_CCW, 
                PE_MONITOR_REMOTING_COOKIE = COR_PRF_MONITOR_REMOTING_COOKIE, 
                PE_MONITOR_REMOTING_ASYNC = COR_PRF_MONITOR_REMOTING_ASYNC, 
                PE_MONITOR_SUSPENDS = COR_PRF_MONITOR_SUSPENDS, 
                PE_MONITOR_CACHE_SEARCHES = COR_PRF_MONITOR_CACHE_SEARCHES, 
                PE_MONITOR_CLR_EXCEPTIONS = COR_PRF_MONITOR_CLR_EXCEPTIONS, 
                PE_MONITOR_ALL = COR_PRF_MONITOR_ALL, 
                PE_ENABLE_REJIT = COR_PRF_ENABLE_REJIT, 
                PE_ENABLE_INPROC_DEBUGGING = COR_PRF_ENABLE_INPROC_DEBUGGING, 
                PE_ENABLE_JIT_MAPS = COR_PRF_ENABLE_JIT_MAPS, 
                PE_DISABLE_INLINING = COR_PRF_DISABLE_INLINING, 
                PE_DISABLE_OPTIMIZATIONS = COR_PRF_DISABLE_OPTIMIZATIONS, 
                PE_ENABLE_OBJECT_ALLOCATED = COR_PRF_ENABLE_OBJECT_ALLOCATED, 
                PE_ENABLE_FUNCTION_ARGS = COR_PRF_ENABLE_FUNCTION_ARGS, 
                PE_ENABLE_FUNCTION_RETVAL = COR_PRF_ENABLE_FUNCTION_RETVAL, 
                PE_ENABLE_FRAME_INFO = COR_PRF_ENABLE_FRAME_INFO, 
                PE_ENABLE_STACK_SNAPSHOT = COR_PRF_ENABLE_STACK_SNAPSHOT, 
                PE_USE_PROFILE_IMAGES = COR_PRF_USE_PROFILE_IMAGES, 
                PE_DISABLE_TRANSPARENCY_CHECKS_UNDER_FULL_TRUST = COR_PRF_DISABLE_TRANSPARENCY_CHECKS_UNDER_FULL_TRUST, 
                PE_ALL = COR_PRF_ALL, 
                PE_REQUIRE_PROFILE_IMAGE = COR_PRF_REQUIRE_PROFILE_IMAGE, 
                PE_ALLOWABLE_AFTER_ATTACH = COR_PRF_ALLOWABLE_AFTER_ATTACH, 
                PE_MONITOR_IMMUTABLE = COR_PRF_MONITOR_IMMUTABLE, 
                PE_UNREACHED = 0xffffffff
            };

            CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)

        };

    }   // namespace ProfilerEventsDetail {

    typedef Urasandesu::CppAnonym::SafeFlagsEnum<ProfilerEventsDetail::ProfilerEventsDef> ProfilerEvents;

}}}  // namespace Urasandesu { namespace Swathe { namespace Profiling {

#endif  // URASANDESU_SWATHE_PROFILING_PROFILEREVENTS_H
