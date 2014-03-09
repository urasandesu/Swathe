/* 
 * File: BaseModuleGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/ModuleGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseModuleGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseModuleGenerator : 
        public IModule
    {
    public:
        SWATHE_BEGIN_MODULE_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_MODULE_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_MODULE_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseModuleGenerator();
        ~BaseModuleGenerator();

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
        module_generator_pimpl_label_type *Pimpl();
        module_generator_pimpl_label_type const *Pimpl() const;
        void SetName(wstring const &name);
        void SetSourceModule(IModule const *pSrcMod);
        void Accept(IMetadataVisitor *pVisitor) const;
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_H

