/* 
 * File: BaseModuleMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_MODULEMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/ModuleMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseModuleMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEHASH_H
#include <Urasandesu/Swathe/Metadata/ITypeHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ITypeEqualTo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::unordered_map;
    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseModuleMetadataPimpl
    {
    public:
        SWATHE_BEGIN_MODULE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_MODULE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_MODULE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseModuleMetadataPimpl(module_metadata_label_type *pClass);

        void Initialize(assembly_metadata_label_type *pAsm);
        mdModule GetToken() const;
        wstring const &GetName() const;
        IType const *GetType(wstring const &fullName) const;
        vector<IType const *> const &GetTypes() const;
        IAssembly const *GetAssembly() const;
        IModule const *GetSourceModule() const;
    
    private:
        void SetName(wstring const &name);

        mutable module_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        mutable mdModule m_mdm;
        mutable wstring m_name;
        mutable bool m_typesInit;
        mutable vector<IType const *> m_types;
        IModule const *m_pSrcMod;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPL_H

