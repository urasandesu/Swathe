/* 
 * File: DefaultAssemblyGeneratorApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_METADATADISPENSERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/MetadataDispenserPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADISPENSERPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataDispenserPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEKEYLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameKeyLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEKEYFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameKeyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFOFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEWRITERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableWriterLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEWRITERFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableWriterFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassApiHolder { 

    namespace DefaultAssemblyGeneratorApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::Metadata::MetadataDispenser;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::MetadataDispenserPimplLabel;
        using Urasandesu::Swathe::Metadata::MetadataDispenserPimpl;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameKeyLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameKey;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableWriterLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableWriter;
        using mpl::map;
        using mpl::pair;

        struct DefaultAssemblyGeneratorApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<MetadataDispenserPimplLabel, MetadataDispenserPimpl>,
                pair<StrongNameKeyLabel, StrongNameKey>,
                pair<PortableExecutableInfoLabel, PortableExecutableInfo>,
                pair<PortableExecutableWriterLabel, PortableExecutableWriter>
            > api_cartridges;
        };
    
    }   // namespace DefaultAssemblyGeneratorApiHolderDetail {

    struct DefaultAssemblyGeneratorApiHolder : 
        DefaultAssemblyGeneratorApiHolderDetail::DefaultAssemblyGeneratorApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H

