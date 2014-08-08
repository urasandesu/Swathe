/* 
 * File: BaseLocalGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/LocalGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseLocalGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCAL_H
#include <Urasandesu/Swathe/Metadata/ILocal.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<
        class ApiHolder
    >    
    class BaseLocalGenerator : 
        public ILocal
    {
    public:
        SWATHE_BEGIN_LOCAL_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_LOCAL_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_LOCAL_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseLocalGenerator();
        ~BaseLocalGenerator();

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        SIZE_T GetLocalIndex() const;
        IType const *GetLocalType() const;
        Signature const &GetSignature() const;
        IMethodBody const *GetMethodBody() const;
        IAssembly const *GetAssembly() const;
        ILocal const *GetSourceLocal() const;
        bool Equals(ILocal const *pLocal) const;
        size_t GetHashCode() const;
    
    private:
        local_generator_pimpl_label_type *Pimpl();
        local_generator_pimpl_label_type const *Pimpl() const;
        void SetLocalIndex(SIZE_T index);
        void SetLocalType(IType const *pLocalType);
        void SetMethodBody(IMethodBody const *pBody);
        void Accept(IMetadataVisitor *pVisitor) const;

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 32;
#else
        static INT const PIMPL_TYPE_SIZE = 64;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALGENERATOR_H

