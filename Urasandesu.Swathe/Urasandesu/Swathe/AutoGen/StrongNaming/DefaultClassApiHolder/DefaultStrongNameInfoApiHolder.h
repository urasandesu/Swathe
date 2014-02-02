/* 
 * File: DefaultStrongNameInfoApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEINFOAPIHOLDER_H

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

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEKEYLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameKeyLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEKEYFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameKeyFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace DefaultClassApiHolder { 

    namespace DefaultStrongNameInfoApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHost;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHostPimpl;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameKeyLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameKey;
        using mpl::map;
        using mpl::pair;

        struct DefaultStrongNameInfoApiHolderImpl
        {
            typedef map<
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<RuntimeHostPimplLabel, RuntimeHostPimpl>,
                pair<StrongNameKeyLabel, StrongNameKey>
            > api_cartridges;
        };
    
    }   // namespace DefaultStrongNameInfoApiHolderDetail {

    struct DefaultStrongNameInfoApiHolder : 
        DefaultStrongNameInfoApiHolderDetail::DefaultStrongNameInfoApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEINFOAPIHOLDER_H

