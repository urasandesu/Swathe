/* 
 * File: BaseAssemblyName.h
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
#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAME_H
#define URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAME_H

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSFACADE_ASSEMBLYNAMEFACADE_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassFacade/AssemblyNameFacade.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAMEFWD_H
#include <Urasandesu/Swathe/Fusion/BaseClass/BaseAssemblyNameFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_NEWASSEMBLYNAMEFLAGS_H
#include <Urasandesu/Swathe/Fusion/NewAssemblyNameFlags.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_PLATFORM_H
#include <Urasandesu/Swathe/Fusion/Platform.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseAssemblyName
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_NAME_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_NAME_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_NAME_FACADE_TYPEDEF_ALIAS
        
        BaseAssemblyName();
        ~BaseAssemblyName();

        wstring const &GetFullName() const;
        wstring const &GetName() const;
        Platform GetPlatform() const;
    
    private:
        assembly_name_pimpl_label_type *Pimpl();
        assembly_name_pimpl_label_type const *Pimpl() const;
        void Initialize(fusion_info_label_type const *pFuInfo);
        void SetDisplayName(wstring const &displayName);
        void SetFlags(NewAssemblyNameFlags const &flags);
        void SetCOMAssemblyName(IAssemblyName *pComAsmName);
        IAssemblyName &GetCOMAssemblyName();

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 92;
#else
        static INT const PIMPL_TYPE_SIZE = 144;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_FUSION_BASECLASS_BASEASSEMBLYNAME_H

