/* 
 * File: BaseCustomAttributeMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseCustomAttributeMetadataPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseCustomAttributeMetadataPimpl<ApiHolder>::BaseCustomAttributeMetadataPimpl(custom_attribute_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr), 
        m_mdt(mdTokenNil), 
        m_mdtOwner(mdTokenNil), 
        m_mdtCtor(mdTokenNil), 
        m_pCtor(nullptr), 
        m_constructorArgsInit(false), 
        m_namedPropsInit(false), 
        m_propValuesInit(false), 
        m_namedFieldsInit(false), 
        m_fieldValuesInit(false), 
        m_pAttrType(nullptr)
    { }

#define SWATHE_DECLARE_BASE_CUSTOM_ATTRIBUTE_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseCustomAttributeMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdToken BaseCustomAttributeMetadataPimpl<ApiHolder>::GetToken() const
    {
        if (IsNilToken(m_mdt))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    Signature const &BaseCustomAttributeMetadataPimpl<ApiHolder>::GetSignature() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseCustomAttributeMetadataPimpl<ApiHolder>::GetConstructor() const
    {
        return m_pCtor;
    }



    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeMetadataPimpl<ApiHolder>::GetConstructorArguments() const
    {
        if (!m_constructorArgsInit)
        {
            auto const &blob = m_sig.GetBlob();
            _ASSERTE(!blob.empty());
            _ASSERTE(m_pCtor);
            m_sig.Decode(m_pClass, m_constructorArgs, m_namedProps, m_propValues, m_namedFields, m_fieldValues);
            m_constructorArgsInit = true;
            m_namedPropsInit = true;
            m_propValuesInit = true;
            m_namedFieldsInit = true;
            m_fieldValuesInit = true;
        }
        return m_constructorArgs;
    }



    template<class ApiHolder>    
    vector<IProperty const *> const &BaseCustomAttributeMetadataPimpl<ApiHolder>::GetNamedProperties() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeMetadataPimpl<ApiHolder>::GetPropertyValues() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<IField const *> const &BaseCustomAttributeMetadataPimpl<ApiHolder>::GetNamedFields() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeMetadataPimpl<ApiHolder>::GetFieldValues() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    CustomAttributeProvider const &BaseCustomAttributeMetadataPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IAssembly const *BaseCustomAttributeMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IType const *BaseCustomAttributeMetadataPimpl<ApiHolder>::GetAttributeType() const
    {
        if (!m_pCtor)
        {
            auto mdtTarget = GetToken();
            if (IsNilToken(m_mdtCtor))
                FillCustomAttributeProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_sig, m_mdtOwner, m_mdtCtor);
            FillCustomAttributeConstructor(m_pClass, m_mdtCtor, m_pCtor);
        }
        return m_pCtor->GetDeclaringType();
    }



    template<class ApiHolder>    
    void BaseCustomAttributeMetadataPimpl<ApiHolder>::SetToken(mdToken mdt)
    {
        _ASSERTE(!IsNilToken(mdt));
        _ASSERTE(IsNilToken(m_mdt));
        m_mdt = mdt;
    }



    template<class ApiHolder>    
    void BaseCustomAttributeMetadataPimpl<ApiHolder>::SetMember(CustomAttributeProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseCustomAttributeMetadataPimpl<ApiHolder>::FillCustomAttributeProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, Signature &sig, mdToken &mdtOwner, mdToken &mdtCtor)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(IsNilToken(mdtOwner));
        _ASSERTE(IsNilToken(mdtCtor));
        
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto hr = pComMetaImp->GetCustomAttributeProps(mdtTarget, &mdtOwner, &mdtCtor, reinterpret_cast<void const **>(&pSig), &sigLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BaseCustomAttributeMetadataPimpl<ApiHolder>::FillCustomAttributeConstructor(ICustomAttribute const *pCa, mdToken mdtTarget, IMethod const *&pCtor)
    {
        _ASSERTE(pCa);
        
        if (pCtor)
            return;
        
        auto const *pAsm = pCa->GetAssembly();
        if (TypeFromToken(mdtTarget) == mdtMemberRef)
            pCtor = pAsm->GetMethod(mdtTarget);
        else if (TypeFromToken(mdtTarget) == mdtMethodDef)
            pCtor = pAsm->GetMethod(mdtTarget);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }
    
}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPL_HPP

