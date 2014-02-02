/* 
 * File: SwatheStorageFacade.h
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
#ifndef URASANDESU_SWATHE_SWATHESTORAGEFACADE_H
#define URASANDESU_SWATHE_SWATHESTORAGEFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_HOSTINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/HostInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_SWATHESTORAGEAPIAT_H
#include <Urasandesu/Swathe/SwatheStorageApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_SWATHESTORAGEFACADEFWD_H
#include <Urasandesu/Swathe/SwatheStorageFacadeFwd.h>
#endif

namespace Urasandesu { namespace Swathe {

    namespace SwatheStorageFacadeDetail {

        using Urasandesu::CppAnonym::StaticDependentObjectsStorage;
#ifdef _DEBUG
        using Urasandesu::CppAnonym::StaticDependentObjectsStorageDetail::HostAccessor;
#endif
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::HostInfoLabel;

        template<
            class SwatheStorageApiHolder
        >    
        struct SwatheStorageFacadeImpl
        {
            typedef typename SwatheStorageApiAt<SwatheStorageApiHolder, HostInfoLabel>::type host_info_label_type;
            typedef StaticDependentObjectsStorage<host_info_label_type> base_type;
#ifdef _DEBUG
            typedef HostAccessor<host_info_label_type> accessor_type;
#endif
        };

    }   // namespace SwatheStorageFacadeDetail {

    template<
        class ApiHolder
    >    
    struct SwatheStorageFacade : 
        SwatheStorageFacadeDetail::SwatheStorageFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_SWATHE_STORAGE_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::SwatheStorageFacade<ApiHolder> facade;

#ifdef _DEBUG
#define SWATHE_DECLARE_SWATHE_STORAGE_FACADE_TYPEDEF_ALIAS \
    typedef typename facade::host_info_label_type host_info_label_type; \
    typedef typename facade::accessor_type accessor_type; \

#else
#define SWATHE_DECLARE_SWATHE_STORAGE_FACADE_TYPEDEF_ALIAS \
    typedef typename facade::host_info_label_type host_info_label_type; \

#endif

#define SWATHE_END_SWATHE_STORAGE_FACADE_TYPEDEF_ALIAS

}}   // namespace Urasandesu { namespace Swathe {

#endif  // URASANDESU_SWATHE_SWATHESTORAGEFACADE_H
