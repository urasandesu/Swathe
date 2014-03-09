/* 
 * File: BaseParameterGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_PARAMETERGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/ParameterGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseParameterGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::blank;
    using boost::static_visitor;
    using boost::variant;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseParameterGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_PARAMETER_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PARAMETER_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PARAMETER_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseParameterGeneratorPimpl(parameter_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        ULONG GetPosition() const;
        wstring const &GetName() const;
        ParameterAttributes GetAttribute() const;
        IType const *GetParameterType() const;
        Signature const &GetSignature() const;
        IMethod const *GetMethod() const;
        IProperty const *GetProperty() const;
        ParameterProvider const &GetMember() const;
        IAssembly const *GetAssembly() const;
        IParameter const *GetSourceParameter() const;
        bool Equals(IParameter const *pParam) const;
        ULONG GetHashCode() const;
        void OutDebugInfo() const;
        
    private:
        struct get_token_visitor;
        struct assign_member_visitor;
        void SetPosition(ULONG position);
        void SetParameterType(IType const *pParamType);
        void SetSourceParameter(IParameter const *pSrcParam);
        void SetMember(ParameterProvider const &member);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable parameter_generator_label_type *m_pClass;
        assembly_generator_label_type *m_pAsmGen;
        mutable mdToken m_mdt;
        mutable ULONG m_position;
        mutable bool m_nameInit;
        mutable wstring m_name;
        mutable ParameterAttributes m_attr;
        mutable bool m_paramTypeInit;
        mutable IType const *m_pParamType;
        mutable bool m_methodInit;
        mutable ParameterProvider m_member;
        IParameter const *m_pSrcParam;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPL_H

