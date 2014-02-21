/* 
 * File: BaseAssemblyNamePimpl.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPL_H
#define URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSPIMPLFACADE_ASSEMBLYNAMEPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassPimplFacade/AssemblyNamePimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPLFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClassPimpl/BaseAssemblyNamePimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_NEWASSEMBLYNAMEFLAGS_H
#include <Urasandesu/Swathe/Fusion/NewAssemblyNameFlags.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_PLATFORM_H
#include <Urasandesu/Swathe/Fusion/Platform.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

    using std::wstring;
    using boost::aligned_storage;
    
    template<
        class ApiHolder
    >    
    class BaseAssemblyNamePimpl
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_NAME_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_NAME_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_NAME_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseAssemblyNamePimpl(assembly_name_label_type *pClass);

        wstring const &GetFullName() const;
        wstring const &GetName() const;
        Platform GetPlatform() const;
        
    private:
        void Initialize(fusion_info_label_type const *pFuInfo);
        void SetDisplayName(wstring const &displayName);
        void SetFlags(NewAssemblyNameFlags const &flags);
        void SetCOMAssemblyName(IAssemblyName *pComAsmName);
        IAssemblyName &GetCOMAssemblyName();

        mutable assembly_name_label_type *m_pClass;
        fusion_info_label_type const *m_pFuInfo;
        wstring m_displayName;
        NewAssemblyNameFlags m_flags;
        mutable wstring m_fullName;
        mutable wstring m_name;
        mutable Platform m_platform;
        mutable ATL::CComPtr<IAssemblyName> m_pComAsmName;
        int reserved;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASSPIMPL_BASEASSEMBLYNAMEPIMPL_H

