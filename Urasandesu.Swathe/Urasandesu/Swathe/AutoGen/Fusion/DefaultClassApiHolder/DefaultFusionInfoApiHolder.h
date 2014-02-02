/* 
 * File: DefaultFusionInfoApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTFUSIONINFOAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTFUSIONINFOAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYCACHELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyCacheLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYCACHEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyCachePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyCachePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYNAMEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyNamePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNamePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMERANGELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameRangeLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMERANGEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameRangeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLLABEL_ASSEMBLYNAMERANGEPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplLabel/AssemblyNameRangePimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMERANGEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameRangePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_RUNTIMEHOSTLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/RuntimeHostLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_RUNTIMEHOSTFWD_H
#include <Urasandesu/Swathe/Hosting/RuntimeHostFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_RUNTIMEHOSTPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/RuntimeHostPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_RUNTIMEHOSTPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/RuntimeHostPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace DefaultClassApiHolder { 

    namespace DefaultFusionInfoApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyCacheLabel;
        using Urasandesu::Swathe::Fusion::AssemblyCache;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyCachePimplLabel;
        using Urasandesu::Swathe::Fusion::AssemblyCachePimpl;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameLabel;
        using Urasandesu::Swathe::Fusion::AssemblyName;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyNamePimplLabel;
        using Urasandesu::Swathe::Fusion::AssemblyNamePimpl;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameRangeLabel;
        using Urasandesu::Swathe::Fusion::AssemblyNameRange;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassPimplLabel::AssemblyNameRangePimplLabel;
        using Urasandesu::Swathe::Fusion::AssemblyNameRangePimpl;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHost;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHostPimpl;
        using mpl::map;
        using mpl::pair;

        struct DefaultFusionInfoApiHolderImpl
        {
            typedef map<
                pair<AssemblyCacheLabel, AssemblyCache>,
                pair<AssemblyCachePimplLabel, AssemblyCachePimpl>,
                pair<AssemblyNameLabel, AssemblyName>,
                pair<AssemblyNamePimplLabel, AssemblyNamePimpl>,
                pair<AssemblyNameRangeLabel, AssemblyNameRange>,
                pair<AssemblyNameRangePimplLabel, AssemblyNameRangePimpl>,
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<RuntimeHostPimplLabel, RuntimeHostPimpl>
            > api_cartridges;
        };
    
    }   // namespace DefaultFusionInfoApiHolderDetail {

    struct DefaultFusionInfoApiHolder : 
        DefaultFusionInfoApiHolderDetail::DefaultFusionInfoApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTFUSIONINFOAPIHOLDER_H

