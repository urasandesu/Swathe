/* 
 * File: DefaultPortableExecutableInfoApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOAPIHOLDER_H

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

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEREADERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableReaderLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEREADERFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableReaderFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_PORTABLEEXECUTABLEREADERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/PortableExecutableReaderPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEREADERPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableReaderPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEWRITERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableWriterLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEWRITERFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableWriterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLLABEL_PORTABLEEXECUTABLEWRITERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplLabel/PortableExecutableWriterPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEWRITERPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableWriterPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace DefaultClassApiHolder { 

    namespace DefaultPortableExecutableInfoApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::RuntimeHostLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHost;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::RuntimeHostPimplLabel;
        using Urasandesu::Swathe::Hosting::RuntimeHostPimpl;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableReaderLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableReader;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::PortableExecutableReaderPimplLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableReaderPimpl;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableWriterLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableWriter;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassPimplLabel::PortableExecutableWriterPimplLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableWriterPimpl;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfo;
        using mpl::map;
        using mpl::pair;

        struct DefaultPortableExecutableInfoApiHolderImpl
        {
            typedef map<
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<RuntimeHostPimplLabel, RuntimeHostPimpl>,
                pair<PortableExecutableReaderLabel, PortableExecutableReader>,
                pair<PortableExecutableReaderPimplLabel, PortableExecutableReaderPimpl>,
                pair<PortableExecutableWriterLabel, PortableExecutableWriter>,
                pair<PortableExecutableWriterPimplLabel, PortableExecutableWriterPimpl>,
                pair<StrongNameInfoLabel, StrongNameInfo>
            > api_cartridges;
        };
    
    }   // namespace DefaultPortableExecutableInfoApiHolderDetail {

    struct DefaultPortableExecutableInfoApiHolder : 
        DefaultPortableExecutableInfoApiHolderDetail::DefaultPortableExecutableInfoApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Hosting { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOAPIHOLDER_H

