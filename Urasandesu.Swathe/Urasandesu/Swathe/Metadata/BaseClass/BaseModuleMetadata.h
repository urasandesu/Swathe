/* 
 * File: BaseModuleMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/ModuleMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseModuleMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using boost::aligned_storage;
    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseModuleMetadata : 
        public IModule
    {
    public:
        SWATHE_BEGIN_MODULE_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_MODULE_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_MODULE_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseModuleMetadata();
        ~BaseModuleMetadata();

        void Initialize(assembly_metadata_label_type *pAsm);
        mdModule GetToken() const;
        wstring const &GetName() const;
        IType const *GetType(wstring const &fullName) const;
        ITypePtrRange GetTypes() const;
        IAssembly const *GetAssembly() const;
        IModule const *GetSourceModule() const;
        bool Equals(IModule const *pMod) const;
        size_t GetHashCode() const;
    
    private:
        module_metadata_pimpl_label_type *Pimpl();
        module_metadata_pimpl_label_type const *Pimpl() const;
        void SetName(wstring const &name);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 56;
#else
        static INT const PIMPL_TYPE_SIZE = 96;
#endif
#endif
        typedef typename aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_H

