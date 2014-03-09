/* 
 * File: BaseModuleGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_MODULEGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/ModuleGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseModuleGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEHASH_H
#include <Urasandesu/Swathe/Metadata/ITypeHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ITypeEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using std::pair;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseModuleGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_MODULE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_MODULE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_MODULE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseModuleGeneratorPimpl(module_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdModule GetToken() const;
        wstring const &GetName() const;
        IType const *GetType(wstring const &fullName) const;
        ITypePtrRange GetTypes() const;
        IAssembly const *GetAssembly() const;
        IModule const *GetSourceModule() const;
        bool Equals(IModule const *pMod) const;
        ULONG GetHashCode() const;
        type_generator_label_type *DefineType(wstring const &fullName, TypeAttributes const &attr);
    
    private:
        void SetName(wstring const &name);
        void SetSourceModule(IModule const *pSrcMod);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable module_generator_label_type *m_pClass;
        assembly_generator_label_type *m_pAsmGen;
        mutable mdToken m_mdt;
        mutable wstring m_name;
        IModule const *m_pSrcMod;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPL_H

