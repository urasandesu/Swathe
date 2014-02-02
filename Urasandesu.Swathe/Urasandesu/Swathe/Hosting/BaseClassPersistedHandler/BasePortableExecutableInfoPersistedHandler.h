/* 
 * File: BasePortableExecutableInfoPersistedHandler.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPERSISTEDHANDLER_BASEPORTABLEEXECUTABLEINFOPERSISTEDHANDLER_H
#define URASANDESU_SWATHE_HOSTING_BASECLASSPERSISTEDHANDLER_BASEPORTABLEEXECUTABLEINFOPERSISTEDHANDLER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPERSISTEDHANDLERFACADE_PORTABLEEXECUTABLEINFOPERSISTEDHANDLERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPersistedHandlerFacade/PortableExecutableInfoPersistedHandlerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPERSISTEDHANDLER_BASEPORTABLEEXECUTABLEINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClassPersistedHandler/BasePortableExecutableInfoPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPersistedHandler { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using Urasandesu::CppAnonym::Utilities::TypeInfo;
    
    template<
        class ApiHolder
    >    
    class BasePortableExecutableInfoPersistedHandler
    {
    public:
        SWATHE_BEGIN_PORTABLE_EXECUTABLE_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PORTABLE_EXECUTABLE_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PORTABLE_EXECUTABLE_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS

        typedef TempPtr<portable_executable_info_label_type> sender_type;

        BasePortableExecutableInfoPersistedHandler(runtime_host_label_type *pRuntime);
        void operator()(sender_type *pSender, void *pArg);

    private:
        mutable runtime_host_label_type *m_pRuntime;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPersistedHandler { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPERSISTEDHANDLER_BASEPORTABLEEXECUTABLEINFOPERSISTEDHANDLER_H

