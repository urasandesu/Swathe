/* 
 * File: BaseParameterMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_PARAMETERMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/ParameterMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseParameterMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::blank;
    using boost::static_visitor;
    using boost::variant;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseParameterMetadataPimpl
    {
    public:
        SWATHE_BEGIN_PARAMETER_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PARAMETER_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PARAMETER_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseParameterMetadataPimpl(parameter_metadata_label_type *pClass);
        
        void Initialize(assembly_metadata_label_type *pAsm);
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
        size_t GetHashCode() const;
        void OutDebugInfo() const;

    private:
        struct get_token_visitor;
        struct are_equal_visitor;
        void SetMember(ParameterProvider const &member);
        void SetPosition(ULONG position);
        void SetParameterType(IType const *pParamType);
        static void FillParamDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, ULONG &position, wstring &name, ParameterAttributes &attr);

        mutable parameter_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        mutable mdToken m_mdt;
        mutable mdToken m_mdtOwner;
        mutable wstring m_name;
        mutable ULONG m_position;
        mutable ParameterAttributes m_attr;        
        IType const *m_pParamType;
        mutable ParameterProvider m_member;
        IParameter const *m_pSrcParam;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPL_H

