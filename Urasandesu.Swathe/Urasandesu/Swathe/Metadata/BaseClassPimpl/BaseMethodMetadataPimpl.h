/* 
 * File: BaseMethodMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METHODMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/MethodMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODIMPLATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodImplAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
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

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERHASH_H
#include <Urasandesu/Swathe/Metadata/IParameterHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETEREQUALTO_H
#include <Urasandesu/Swathe/Metadata/IParameterEqualTo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::unordered_map;
    using std::vector;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMethodMetadataPimpl
    {
    public:
        SWATHE_BEGIN_METHOD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METHOD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METHOD_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseMethodMetadataPimpl(method_metadata_label_type *pClass);

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
        bool Equals(IMethod const *pMethod) const;
        ULONG GetHashCode() const;
        //IDispenser const *GetDispenser() const;
        IParameter const *GetParameter(ULONG position, IType const *pParamType) const;
        void OutDebugInfo() const;
        
    private:
        void SetILMethodBody(COR_ILMETHOD *pILBody);
        void SetToken(mdMethodDef mdmd);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetReturnType(IType const *pRetType);
        void SetParameters(vector<IParameter const *> const &params);
        void SetMember(MethodProvider const &member);
        void SetGenericArguments(vector<IType const *> const &genericArgs);
        static void FillMethodDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, MethodAttributes &attr, Signature &sig, ULONG &codeRva, MethodImplAttributes &implFlags);
        static void FillMethodMember(IMethod const *pMethod, mdToken mdtOwner, MethodProvider &member);
        static void FillMethodRefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, Signature &sig);
        //static void FillMethodRefMember(IMethod const *pMethod, mdToken mdtOwner, MethodProvider &member);
        static void FillMethodRefSourceMethod(IMethod const *pMethod, mdToken mdtOwner, wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IParameter const *> const &params, bool &srcMethodInit, IMethod const *&pSrcMethod);
        static void FillMethodSpecSignature(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, Signature &sig);
        static void FillMethodSpecProperties(IMethod const *pMethod, Signature const &sig, CallingConventions &callingConvention, bool &genericArgsInit, vector<IType const *> &genericArgs);
        static void FillMethodSigProperties(IMethod const *pMethod, Signature const &sig, CallingConventions &callingConvention, bool &retTypeInit, IType const *&pRetType, bool &paramsInit, vector<IParameter const *> &params);
        
        mutable method_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        mutable MethodProvider m_member;
        mutable mdToken m_mdt;
        mutable mdToken m_mdtOwner;
        mutable wstring m_name;
        mutable CallingConventions m_callingConvention;
        mutable bool m_retTypeInit;
        mutable IType const *m_pRetType;
        mutable bool m_paramsInit;
        mutable vector<IParameter const *> m_params;
        mutable bool m_genericArgsInit;
        mutable vector<IType const *> m_genericArgs;
        mutable Signature m_sig;
        COR_ILMETHOD *m_pILBody;
        mutable method_body_metadata_label_type *m_pBody;
        mutable bool m_srcMethodInit;
        mutable IMethod const *m_pSrcMethod;
        mutable MethodAttributes m_attr;
        mutable ULONG m_codeRva;
        mutable MethodImplAttributes m_implFlags;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPL_H

