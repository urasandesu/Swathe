/* 
 * File: BasePortableExecutableWriter.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_H
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSFACADE_PORTABLEEXECUTABLEWRITERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassFacade/PortableExecutableWriterFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITERFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableWriterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_COMIMAGEFLAGS_H
#include <Urasandesu/Swathe/Hosting/ComImageFlags.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_CEECREATEFLAGS_H
#include <Urasandesu/Swathe/Hosting/CeeCreateFlags.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    using Urasandesu::Swathe::Metadata::IAssembly;
    using Urasandesu::Swathe::Metadata::IModule;
    using Urasandesu::Swathe::Metadata::IType;
    using Urasandesu::Swathe::Metadata::IField;
    using Urasandesu::Swathe::Metadata::IProperty;
    using Urasandesu::Swathe::Metadata::IMethod;
    using Urasandesu::Swathe::Metadata::IMethodBody;
    using Urasandesu::Swathe::Metadata::IParameter;
    using Urasandesu::Swathe::Metadata::ILocal;
    using Urasandesu::Swathe::Metadata::IInstruction;
    using Urasandesu::Swathe::Metadata::ICustomAttribute;
    using Urasandesu::Swathe::Metadata::IMetadataVisitor;

    template<
        class ApiHolder
    >    
    class BasePortableExecutableWriter : 
        public IMetadataVisitor
    {
    public:
        SWATHE_BEGIN_PORTABLE_EXECUTABLE_WRITER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PORTABLE_EXECUTABLE_WRITER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PORTABLE_EXECUTABLE_WRITER_FACADE_TYPEDEF_ALIAS
        
        BasePortableExecutableWriter();
        ~BasePortableExecutableWriter();

        void Initialize(portable_executable_info_label_type *pPEInfo, strong_name_info_label_type const *pSnInfo);
        void Visit(IAssembly const *pAsm);
        void Visit(IModule const *pMod);
        void Visit(IType const *pType);
        void Visit(IField const *pField);
        void Visit(IProperty const *pProp);
        void Visit(IMethod const *pMethod);
        void Visit(IMethodBody const *pBody);
        void Visit(IParameter const *pParam);
        void Visit(ILocal const *pLocal);
        void Visit(IInstruction const *pInst);
        void Visit(ICustomAttribute const *pCa);
        void Close();
    
    private:
        portable_executable_writer_pimpl_label_type *Pimpl();
        portable_executable_writer_pimpl_label_type const *Pimpl() const;
        void SetCOMMetaDataEmit(IMetaDataEmit2 *pComMetaEmt);
        void SetImageFlags(ComImageFlags const &imageFlags);
        void SetCreateFlags(CeeCreateFlags const &createFlags);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_H

