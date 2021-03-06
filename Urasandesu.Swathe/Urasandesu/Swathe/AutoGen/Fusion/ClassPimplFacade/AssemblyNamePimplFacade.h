﻿/* 
 * File: AssemblyNamePimplFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_ASSEMBLYNAMEPIMPLFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_ASSEMBLYNAMEPIMPLFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSAPIAT_ASSEMBLYNAMEAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassApiAt/AssemblyNameApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassFacade/AssemblyNameFacade.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassPimplFacade { 

    namespace AssemblyNamePimplFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassApiAt::AssemblyNameApiAt;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassFacade::AssemblyNameFacade;

        template<
            class ApiHolder
        >    
        struct AssemblyNamePimplFacadeImpl : 
            AssemblyNameFacade<ApiHolder>
        {

        };
    
    }   // namespace AssemblyNamePimplFacadeDetail {

    template<
        class ApiHolder
    >    
    struct AssemblyNamePimplFacade : 
        AssemblyNamePimplFacadeDetail::AssemblyNamePimplFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_ASSEMBLY_NAME_PIMPL_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Fusion::ClassPimplFacade::AssemblyNamePimplFacade<ApiHolder> facade;

#define SWATHE_DECLARE_ASSEMBLY_NAME_PIMPL_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_ASSEMBLY_NAME_FACADE_TYPEDEF_ALIAS \



#define SWATHE_END_ASSEMBLY_NAME_PIMPL_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Fusion { namespace ClassPimplFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_ASSEMBLYNAMEPIMPLFACADE_H

