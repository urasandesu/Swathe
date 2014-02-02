/* 
 * File: BaseCustomAttributeGeneratorPersistedHandler.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASECUSTOMATTRIBUTEGENERATORPERSISTEDHANDLER_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASECUSTOMATTRIBUTEGENERATORPERSISTEDHANDLER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERFACADE_CUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerFacade/CustomAttributeGeneratorPersistedHandlerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASECUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseCustomAttributeGeneratorPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPersistedHandler { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseCustomAttributeGeneratorPersistedHandler
    {
    public:
        SWATHE_BEGIN_CUSTOM_ATTRIBUTE_GENERATOR_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_CUSTOM_ATTRIBUTE_GENERATOR_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_CUSTOM_ATTRIBUTE_GENERATOR_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS

        typedef TempPtr<custom_attribute_generator_label_type> sender_type;

        BaseCustomAttributeGeneratorPersistedHandler(assembly_generator_label_type *pAsmGen);
        void operator()(sender_type *pSender, void *pArg);

    private:
        assembly_generator_label_type *m_pAsmGen;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPersistedHandler { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASECUSTOMATTRIBUTEGENERATORPERSISTEDHANDLER_H

