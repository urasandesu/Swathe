/* 
 * File: BaseMethodGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METHODGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/MethodGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
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

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::apply_visitor;
    using boost::static_visitor;
    using std::pair;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMethodGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_METHOD_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseMethodGeneratorPimpl(method_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        wstring const &GetName() const;
        CallingConventions GetCallingConvention() const;
        MethodImplAttributes GetMethodImplementationFlags() const;
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
        type_generator_label_type *GetDeclaringTypeGenerator();
        IMethod const *GetDeclaringMethod() const;
        MethodProvider const &GetMember() const;
        IMethod const *GetSourceMethod() const;
        bool Equals(IMethod const *pMethod) const;
        size_t GetHashCode() const;
        IParameter const *GetParameter(ULONG position, IType const *pParamType) const;
        MethodAttributes GetAttribute() const;
        void OutDebugInfo() const;
        method_body_generator_label_type *DefineMethodBody();
        parameter_generator_label_type *DefineParameter(ULONG position, IType const *pParamType);
        void DefineGenericParameters(vector<wstring> const &names);
        void DefineGenericParameters(vector<wstring> const &names, vector<type_generator_label_type *> &genericArgGens);
        void SetImplementationFlags(MethodImplAttributes const &implAttr);
        
    private:
        void SetToken(mdToken mdt);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetReturnType(IType const *pRetType);
        void SetParameters(vector<IParameter const *> const &params);
        void SetAttributes(MethodAttributes const &attr);
        void SetMember(MethodProvider const &member);
        void SetGenericArguments(vector<IType const *> const &genericArgs);
        void SetSourceMethod(IMethod const *pSrcMethod);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable method_generator_label_type *m_pClass;
        mutable assembly_generator_label_type *m_pAsmGen;
        mutable bool m_declaringTypeInit;
        mutable bool m_declaringMethodInit;
        mutable MethodProvider m_member;
        mutable mdToken m_mdt;
        mutable wstring m_name;        
        mutable CallingConventions m_callingConvention;
        mutable IType const *m_pRetType;
        mutable bool m_retTypeInit;
        mutable bool m_paramsInit;
        mutable vector<IParameter const *> m_params;
        mutable MethodAttributes m_attr;
        mutable MethodImplAttributes m_implAttr;
        mutable bool m_genericArgsInit;
        mutable vector<IType const *> m_genericArgs;
        mutable Signature m_sig;
        mutable IMethodBody const *m_pBody;
        mutable method_body_generator_label_type *m_pBodyGen;
        IMethod const *m_pSrcMethod;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_H

