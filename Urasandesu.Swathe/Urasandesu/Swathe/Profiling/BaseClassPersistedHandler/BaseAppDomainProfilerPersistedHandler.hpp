/* 
 * File: BaseAppDomainProfilerPersistedHandler.hpp
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEAPPDOMAINPROFILERPERSISTEDHANDLER_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEAPPDOMAINPROFILERPERSISTEDHANDLER_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEAPPDOMAINPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseAppDomainProfilerPersistedHandler.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPersistedHandler { 

    template<class ApiHolder>    
    BaseAppDomainProfilerPersistedHandler<ApiHolder>::BaseAppDomainProfilerPersistedHandler(process_profiler_label_type *pProcProf) : 
        m_pProcProf(pProcProf)
    { }
    
#define SWATHE_DECLARE_BASE_APP_DOMAIN_PROFILER_PERSISTED_HANDLER_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseAppDomainProfilerPersistedHandler<ApiHolder>::operator()(sender_type *pSender, void *pArg)
    {
        auto &pDomainProf = *pSender;
        m_pProcProf->RegisterAppDomainProfiler(pDomainProf);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPersistedHandler { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEAPPDOMAINPROFILERPERSISTEDHANDLER_HPP

