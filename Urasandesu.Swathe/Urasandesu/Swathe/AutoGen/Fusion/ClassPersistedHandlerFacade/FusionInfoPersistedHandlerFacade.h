/* 
 * File: FusionInfoPersistedHandlerFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPERSISTEDHANDLERFACADE_FUSIONINFOPERSISTEDHANDLERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPERSISTEDHANDLERFACADE_FUSIONINFOPERSISTEDHANDLERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSAPIAT_FUSIONINFOAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassApiAt/FusionInfoApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_FUSIONINFOFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassFacade/FusionInfoFacade.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassPersistedHandlerFacade { 

    namespace FusionInfoPersistedHandlerFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassApiAt::FusionInfoApiAt;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::FusionInfoFacade;

        template<
            class ApiHolder
        >    
        struct FusionInfoPersistedHandlerFacadeImpl : 
            FusionInfoFacade<ApiHolder>
        {

        };
    
    }   // namespace FusionInfoPersistedHandlerFacadeDetail {

    template<
        class ApiHolder
    >    
    struct FusionInfoPersistedHandlerFacade : 
        FusionInfoPersistedHandlerFacadeDetail::FusionInfoPersistedHandlerFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_FUSION_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Fusion::ClassPersistedHandlerFacade::FusionInfoPersistedHandlerFacade<ApiHolder> facade;

#define SWATHE_DECLARE_FUSION_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_FUSION_INFO_FACADE_TYPEDEF_ALIAS \


#define SWATHE_END_FUSION_INFO_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassPersistedHandlerFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPERSISTEDHANDLERFACADE_FUSIONINFOPERSISTEDHANDLERFACADE_H

