/* 
 * File: BasePortableExecutableWriterPimpl.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPL_H
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_PORTABLEEXECUTABLEWRITERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplFacade/PortableExecutableWriterPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BasePortableExecutableWriterPimplFwd.h>
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

#ifndef URASANDESU_SWATHE_STRONGNAMING_ISTRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/IStrongNameKey.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::AutoPtr;
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
    using Urasandesu::Swathe::StrongNaming::IStrongNameKey;

    template<
        class ApiHolder
    >    
    class BasePortableExecutableWriterPimpl
    {
    public:
        SWATHE_BEGIN_PORTABLE_EXECUTABLE_WRITER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PORTABLE_EXECUTABLE_WRITER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PORTABLE_EXECUTABLE_WRITER_PIMPL_FACADE_TYPEDEF_ALIAS

        BasePortableExecutableWriterPimpl(portable_executable_writer_label_type *pClass);
        ~BasePortableExecutableWriterPimpl();

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
        typedef HRESULT (__stdcall *CreateCeeFileGenPtr)(ICeeFileGen **ceeFileGen);
        typedef HRESULT (__stdcall *DestroyCeeFileGenPtr)(ICeeFileGen **ceeFileGen);
        void Finalize();
        void SetCOMMetaDataEmit(IMetaDataEmit2 *pComMetaEmt);
        void SetImageFlags(ComImageFlags const &imageFlags);
        void SetCreateFlags(CeeCreateFlags const &createFlags);
        HCEESECTION GetTextSection();
        BYTE *GetSectionBlock(HCEESECTION textSection, ULONG totalSize, ULONG align);
        ULONG GetSectionDataLen(HCEESECTION textSection);
        ULONG GetCodeRVA(ULONG offset);
        void EmitOptions(wstring const &modName);
        void EmitMethodBody(IMethodBody const *pBody, HCEESECTION &textSection);
        void EmitStrongNameReservedArea(AutoPtr<IStrongNameKey const> const &pSnKey, HCEESECTION &textSection);
        void EmitMetaData();
        void EmitEnd();
        void EmitStrongName(wstring const &modName, AutoPtr<IStrongNameKey const> const &pSnKey);
        void SetOutputFileName(wstring const &modName);
        void SetComImageFlags();
        void SetSubsystem();
        void SetDllSwitch();
        void SetMethodProps(IMethod const *pMethod, ULONG codeRVA);
        HCEEFILE &GetCOMCeeFile();

        mutable portable_executable_writer_label_type *m_pClass;
        portable_executable_info_label_type *m_pPEInfo;
        strong_name_info_label_type const *m_pSnInfo;
        vector<IAssembly const *> m_resolvedAsms;
        vector<IModule const *> m_resolvedMods;
        vector<IType const *> m_resolvedTypes;
        vector<IField const *> m_resolvedFields;
        vector<IProperty const *> m_resolvedProps;
        vector<IMethod const *> m_resolvedMethods;
        vector<IMethodBody const *> m_resolvedMethodBodies;
        vector<IParameter const *> m_resolvedParams;
        vector<ILocal const *> m_resolvedLocals;        
        vector<ICustomAttribute const *> m_resolvedCas;        
        ATL::CComPtr<IMetaDataEmit2> m_pComMetaEmt;
        ComImageFlags m_imageFlags;
        CeeCreateFlags m_createFlags;
        HCEEFILE m_ceeFile;
        bool m_isClosed;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPL_H

