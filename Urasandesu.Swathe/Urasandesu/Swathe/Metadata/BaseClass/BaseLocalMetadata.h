/* 
 * File: BaseLocalMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/LocalMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseLocalMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCAL_H
#include <Urasandesu/Swathe/Metadata/ILocal.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<
        class ApiHolder
    >    
    class BaseLocalMetadata : 
        public ILocal
    {
    public:
        SWATHE_BEGIN_LOCAL_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_LOCAL_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_LOCAL_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseLocalMetadata();
        ~BaseLocalMetadata();

        void Initialize(assembly_metadata_label_type *pAsm);
        mdToken GetToken() const;
        SIZE_T GetLocalIndex() const;
        IType const *GetLocalType() const;
        Signature const &GetSignature() const;
        IMethodBody const *GetMethodBody() const;
        IAssembly const *GetAssembly() const;
    
    private:
        local_metadata_pimpl_label_type *Pimpl();
        local_metadata_pimpl_label_type const *Pimpl() const;
        void SetMethodBody(IMethodBody const *pBody);
        void SetLocalIndex(ULONG index);
        void SetLocalType(IType const *pLocalType);
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALMETADATA_H

