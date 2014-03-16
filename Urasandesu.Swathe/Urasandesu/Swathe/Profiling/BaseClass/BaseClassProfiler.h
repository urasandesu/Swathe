/* 
 * File: BaseClassProfiler.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASECLASSPROFILER_H
#define URASANDESU_SWATHE_PROFILING_BASECLASS_BASECLASSPROFILER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSFACADE_CLASSPROFILERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassFacade/ClassProfilerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASECLASSPROFILERFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseClassProfilerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseClassProfiler
    {
    public:
        SWATHE_BEGIN_CLASS_PROFILER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_CLASS_PROFILER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_CLASS_PROFILER_FACADE_TYPEDEF_ALIAS
        
        BaseClassProfiler();
        ~BaseClassProfiler();

        UINT_PTR GetID() const;
        TempPtr<module_profiler_label_type> AttachToModule();
    
    private:
        class_profiler_pimpl_label_type *Pimpl();
        class_profiler_pimpl_label_type const *Pimpl() const;
        void Initialize(process_profiler_label_type *pProcProf);
        void SetID(UINT_PTR id);
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 20;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASS_BASECLASSPROFILER_H

