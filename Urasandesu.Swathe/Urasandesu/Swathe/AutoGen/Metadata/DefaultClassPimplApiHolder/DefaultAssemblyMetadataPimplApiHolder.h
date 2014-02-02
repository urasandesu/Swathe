/* 
 * File: DefaultAssemblyMetadataPimplApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTASSEMBLYMETADATAPIMPLAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTASSEMBLYMETADATAPIMPLAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFOFWD_H
#include <Urasandesu/Swathe/Fusion/FusionInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_MODULEMETADATAPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/ModuleMetadataPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassPimplApiHolder { 

    namespace DefaultAssemblyMetadataPimplApiHolderDetail {

        namespace mpl = boost::mpl;
        using Urasandesu::Swathe::AutoGen::Metadata::DefaultClassApiHolder::DefaultAssemblyMetadataApiHolder;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::Fusion::FusionInfo;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::ModuleMetadataPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::ModuleMetadataPersistedHandler;
        using mpl::_1;
        using mpl::_2;
        using mpl::fold;
        using mpl::insert;
        using mpl::map;
        using mpl::pair;

        struct DefaultAssemblyMetadataPimplApiHolderImpl : 
            DefaultAssemblyMetadataApiHolder
        {
            typedef map<
                pair<FusionInfoLabel, FusionInfo>,
                pair<ModuleMetadataPersistedHandlerLabel, ModuleMetadataPersistedHandler>
            > additional_api_cartridges;

            typedef fold<
                additional_api_cartridges,
                DefaultAssemblyMetadataApiHolder::api_cartridges,
                insert<_1, _2>
            >::type api_cartridges;
        };

    }   // namespace DefaultAssemblyMetadataPimplApiHolderDetail {

    struct DefaultAssemblyMetadataPimplApiHolder : 
        DefaultAssemblyMetadataPimplApiHolderDetail::DefaultAssemblyMetadataPimplApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassPimplApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTASSEMBLYMETADATAPIMPLAPIHOLDER_H

