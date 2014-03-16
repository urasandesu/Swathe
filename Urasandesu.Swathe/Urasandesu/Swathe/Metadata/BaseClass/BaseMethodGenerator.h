/* 
 * File: BaseMethodGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/MethodGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
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
    class BaseMethodGenerator : 
        public IMethod
    {
    public:
        SWATHE_BEGIN_METHOD_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseMethodGenerator();
        ~BaseMethodGenerator();

        void Initialize(assembly_generator_label_type *pAsmGen);
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
        bool Equals(IMethod const *pMethod) const;
        size_t GetHashCode() const;
        //IDispenser const *GetDispenser() const;
        IParameter const *GetParameter(ULONG position, IType const *pParamType) const;
        void OutDebugInfo() const;
        method_body_generator_label_type *DefineMethodBody();
        parameter_generator_label_type *DefineParameter(ULONG position, IType const *pParamType);

    private:
        method_generator_pimpl_label_type *Pimpl();
        method_generator_pimpl_label_type const *Pimpl() const;
        void SetToken(mdToken mdt);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetReturnType(IType const *pRetType);
        void SetParameters(vector<IParameter const *> const &params);
        void SetAttributes(MethodAttributes const &attr);
        void SetMember(MethodProvider const &member);
        void SetSourceMethod(IMethod const *pSrcMethod);
        void Accept(IMetadataVisitor *pVisitor) const;

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 128;
#else
        static INT const PIMPL_TYPE_SIZE = 216;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_H

