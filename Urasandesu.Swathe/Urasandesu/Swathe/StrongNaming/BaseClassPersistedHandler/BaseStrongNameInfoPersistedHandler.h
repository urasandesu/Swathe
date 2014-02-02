/* 
 * File: BaseStrongNameInfoPersistedHandler.h
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
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPERSISTEDHANDLER_BASESTRONGNAMEINFOPERSISTEDHANDLER_H
#define URASANDESU_SWATHE_STRONGNAMING_BASECLASSPERSISTEDHANDLER_BASESTRONGNAMEINFOPERSISTEDHANDLER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPERSISTEDHANDLERFACADE_STRONGNAMEINFOPERSISTEDHANDLERFACADE_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPersistedHandlerFacade/StrongNameInfoPersistedHandlerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASECLASSPERSISTEDHANDLER_BASESTRONGNAMEINFOPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/StrongNaming/BaseClassPersistedHandler/BaseStrongNameInfoPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPersistedHandler { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using Urasandesu::CppAnonym::Utilities::TypeInfo;
    
    template<
        class ApiHolder
    >    
    class BaseStrongNameInfoPersistedHandler
    {
    public:
        SWATHE_BEGIN_STRONG_NAME_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_STRONG_NAME_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_STRONG_NAME_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS

        typedef TempPtr<strong_name_info_label_type> sender_type;

        BaseStrongNameInfoPersistedHandler(runtime_host_label_type *pRuntime);
        void operator()(sender_type *pSender, void *pArg);
        
    private:
        mutable runtime_host_label_type *m_pRuntime;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace BaseClassPersistedHandler { 

#endif  // URASANDESU_SWATHE_STRONGNAMING_BASECLASSPERSISTEDHANDLER_BASESTRONGNAMEINFOPERSISTEDHANDLER_H

