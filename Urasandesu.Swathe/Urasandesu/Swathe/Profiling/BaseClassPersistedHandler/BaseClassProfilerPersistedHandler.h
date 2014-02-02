/* 
 * File: BaseClassProfilerPersistedHandler.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASECLASSPROFILERPERSISTEDHANDLER_H
#define URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASECLASSPROFILERPERSISTEDHANDLER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPERSISTEDHANDLERFACADE_CLASSPROFILERPERSISTEDHANDLERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPersistedHandlerFacade/ClassProfilerPersistedHandlerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASECLASSPROFILERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseClassProfilerPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPersistedHandler { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;
    
    template<
        class ApiHolder
    >    
    class BaseClassProfilerPersistedHandler
    {
    public:
        SWATHE_BEGIN_CLASS_PROFILER_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_CLASS_PROFILER_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_CLASS_PROFILER_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS

        typedef TempPtr<class_profiler_label_type> sender_type;

        BaseClassProfilerPersistedHandler(process_profiler_label_type *pProcProf);
        void operator()(sender_type *pSender, void *pArg);

    private:
        process_profiler_label_type *m_pProcProf;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPersistedHandler { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASECLASSPROFILERPERSISTEDHANDLER_H

