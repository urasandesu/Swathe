/* 
 * File: DefaultAssemblyMetadataApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H

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

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYCACHELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyCacheLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyCacheFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMERANGELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameRangeLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMERANGEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameRangeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_ASSEMBLYNAMELABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/AssemblyNameLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEFWD_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFOFWD_H
#include <Urasandesu/Swathe/Fusion/FusionInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFOFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEREADERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableReaderLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEREADERFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableReaderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassApiHolder { 

    namespace DefaultAssemblyMetadataApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::Metadata::MetadataDispenser;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::MetadataDispenserPimplLabel;
        using Urasandesu::Swathe::Metadata::MetadataDispenserPimpl;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyCacheLabel;
        using Urasandesu::Swathe::Fusion::AssemblyCache;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameRangeLabel;
        using Urasandesu::Swathe::Fusion::AssemblyNameRange;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::AssemblyNameLabel;
        using Urasandesu::Swathe::Fusion::AssemblyName;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::Fusion::FusionInfo;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableReaderLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableReader;
        using mpl::map;
        using mpl::pair;

        struct DefaultAssemblyMetadataApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<MetadataDispenserPimplLabel, MetadataDispenserPimpl>,
                pair<AssemblyCacheLabel, AssemblyCache>,
                pair<AssemblyNameRangeLabel, AssemblyNameRange>,
                pair<AssemblyNameLabel, AssemblyName>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<StrongNameInfoLabel, StrongNameInfo>,
                pair<PortableExecutableInfoLabel, PortableExecutableInfo>,
                pair<PortableExecutableReaderLabel, PortableExecutableReader>
            > api_cartridges;
        };
    
    }   // namespace DefaultAssemblyMetadataApiHolderDetail {

    struct DefaultAssemblyMetadataApiHolder : 
        DefaultAssemblyMetadataApiHolderDetail::DefaultAssemblyMetadataApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H

