/* 
 * File: BaseMethodMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/MethodMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 
    
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMethodMetadata : 
        public IMethod
    {
    public:
        SWATHE_BEGIN_METHOD_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseMethodMetadata();
        ~BaseMethodMetadata();

        void Initialize(assembly_metadata_label_type *pAsm);
        mdToken GetToken() const;
        wstring const &GetName() const;
        CallingConventions GetCallingConvention() const;
        MethodAttributes GetAttribute() const;
        IType const *GetReturnType() const;
        vector<IParameter const *> const &GetParameters() const;
        IMethodBody const *GetMethodBody() const;
        ULONG GetCodeRVA() const;
        bool IsStatic() const;
        bool IsGenericMethod() const;
        bool IsGenericMethodDefinition() const;
        vector<IType const *> const &GetGenericArguments() const;
        Signature const &GetSignature() const;
        IMethod const *MakeGenericMethod(vector<IType const *> const &genericArgs) const;
        IAssembly const *GetAssembly() const;
        IType const *GetDeclaringType() const;
        IMethod const *GetDeclaringMethod() const;
        MethodProvider const &GetMember() const;
        IMethod const *GetSourceMethod() const;
        IDispenser const *GetDispenser() const;
        IParameter const *GetParameter(ULONG position, IType const *pParamType) const;
        void OutDebugInfo() const;
    
    private:
        method_metadata_pimpl_label_type *Pimpl();
        method_metadata_pimpl_label_type const *Pimpl() const;
        void SetILMethodBody(COR_ILMETHOD *pILBody);
        void SetToken(mdMethodDef mdmd);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetReturnType(IType const *pRetType);
        void SetParameters(vector<IParameter const *> const &params);
        void SetMember(MethodProvider const &member);
        void SetGenericArguments(vector<IType const *> const &genericArgs);
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 136;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_H

