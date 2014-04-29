/* 
 * File: IAssembly.h
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
#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#define URASANDESU_SWATHE_METADATA_IASSEMBLY_H

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTEFWD_H
#include <Urasandesu/Swathe/Metadata/ICustomAttributeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_IPORTABLEEXECUTABLEREADER_H
#include <Urasandesu/Swathe/Hosting/IPortableExecutableReader.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_ISTRONGNAMEKEYFWD_H
#include <Urasandesu/Swathe/StrongNaming/IStrongNameKeyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYFLAGS_H
#include <Urasandesu/Swathe/Metadata/AssemblyFlags.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROCESSORARCHITECTURE_HPP
#include <Urasandesu/Swathe/Metadata/ProcessorArchitecture.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 
    
    struct IAssembly
    {
        IAssembly() { }
        virtual mdAssembly GetToken() const = 0;
        virtual std::wstring const &GetFullName() const = 0;
        virtual IModule const *GetMainModule() const = 0;
        virtual IModule const *GetModule(std::wstring const &name) const = 0;
        virtual Urasandesu::CppAnonym::Utilities::AutoPtr<StrongNaming::IStrongNameKey const> const &GetStrongNameKey() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual ASSEMBLYMETADATA const &GetAssemblyMetadata() const = 0;
        virtual AssemblyFlags GetFlags() const = 0;
        virtual IAssembly const *GetSourceAssembly() const = 0;
        virtual IAssembly const *GetTargetAssembly() const = 0;
        virtual IDispenser const *GetDispenser() const = 0;
        virtual IField const *GetField(mdToken mdt) const = 0;
        virtual IMethod const *GetMethod(mdToken mdt) const = 0;
        virtual IMethod const *GetMethod(mdToken mdt, COR_ILMETHOD *pILBody) const = 0;
        virtual IType const *GetType(mdToken mdt) const = 0;
        virtual IType const *GetType(std::wstring const &fullName) const = 0;
        virtual IType const *GetGenericTypeParameter(ULONG genericParamPos) const = 0;
        virtual IType const *GetGenericMethodParameter(ULONG genericParamPos) const = 0;
        virtual std::vector<ProcessorArchitecture> const &GetProcessorArchitectures() const = 0;
        virtual IAssembly const *GetAssembly(std::wstring const &fullName) const = 0;
        virtual IAssembly const *GetAssembly(std::wstring const &fullName, std::vector<ProcessorArchitecture> const &procArchs) const = 0;
        virtual IAssembly const *GetAssemblyReference(mdAssemblyRef mdt) const = 0;
        virtual ICustomAttribute const *GetCustomAttribute(mdToken mdt) const = 0;
        virtual ICustomAttributePtrRange GetCustomAttributes() const = 0;
        virtual ICustomAttributePtrRange GetCustomAttributes(IType const *pAttributeType) const = 0;
        virtual ITypePtrRange GetTypes() const = 0;
        virtual Urasandesu::CppAnonym::Utilities::AutoPtr<Hosting::IPortableExecutableReader const> const &GetPortableExecutableReader() const = 0;
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_IASSEMBLY_H

