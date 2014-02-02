/* 
 * File: DefaultStrongNameKeyApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEKEYAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSPIMPLLABEL_STRONGNAMEINFOPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassPimplLabel/StrongNameInfoPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOPIMPLFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace DefaultClassApiHolder { 

    namespace DefaultStrongNameKeyApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfo;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassPimplLabel::StrongNameInfoPimplLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfoPimpl;
        using mpl::map;
        using mpl::pair;

        struct DefaultStrongNameKeyApiHolderImpl
        {
            typedef map<
                pair<StrongNameInfoLabel, StrongNameInfo>,
                pair<StrongNameInfoLabel, StrongNameInfo>,
                pair<StrongNameInfoPimplLabel, StrongNameInfoPimpl>
            > api_cartridges;
        };
    
    }   // namespace DefaultStrongNameKeyApiHolderDetail {

    struct DefaultStrongNameKeyApiHolder : 
        DefaultStrongNameKeyApiHolderDetail::DefaultStrongNameKeyApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace StrongNaming { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEKEYAPIHOLDER_H

