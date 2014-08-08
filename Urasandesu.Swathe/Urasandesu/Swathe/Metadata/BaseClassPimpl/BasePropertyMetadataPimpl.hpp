/* 
 * File: BasePropertyMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BasePropertyMetadataPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BasePropertyMetadataPimpl<ApiHolder>::BasePropertyMetadataPimpl(property_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr),
        m_mdp(mdPropertyNil),
        m_mdtOwner(mdTokenNil), 
        m_mdmdSetter(mdMethodDefNil), 
        m_mdmdGetter(mdMethodDefNil), 
        m_callingConvention(CallingConventions::CC_UNREACHED), 
        m_attr(PropertyAttributes::PA_UNREACHED),
        m_pPropType(nullptr),
        m_paramsInit(false), 
        m_pSetMethod(nullptr),
        m_pGetMethod(nullptr), 
        m_pSrcProp(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_PROPERTY_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    
    
    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdProperty BasePropertyMetadataPimpl<ApiHolder>::GetToken() const
    {
        if (IsNilToken(m_mdp))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_mdp;
    }
    
    
    
    template<class ApiHolder>    
    wstring const &BasePropertyMetadataPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtProperty)
                FillPropertyDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_mdmdSetter, m_mdmdGetter);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }
    
    
    
    template<class ApiHolder>    
    CallingConventions BasePropertyMetadataPimpl<ApiHolder>::GetCallingConvention() const
    {
        if (m_callingConvention == CallingConventions::CC_UNREACHED)
        {
            // TODO: m_sig から復元。Signature の Parse がもう必要になるとは・・・。
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_callingConvention;
    }
    
    
    
    template<class ApiHolder>    
    IType const *BasePropertyMetadataPimpl<ApiHolder>::GetPropertyType() const
    {
        if (!m_pPropType)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtProperty)
            {
                if (m_sig.GetBlob().empty())
                    FillPropertyDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_mdmdSetter, m_mdmdGetter);
            }
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());

            FillPropertySigProperties(m_pClass, m_sig, m_callingConvention, m_pPropType, m_params);
        }
        return m_pPropType;
    }
    
    
    
    template<class ApiHolder>    
    vector<IParameter const *> const &BasePropertyMetadataPimpl<ApiHolder>::GetParameters() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    PropertyAttributes BasePropertyMetadataPimpl<ApiHolder>::GetAttribute() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }
    
    
    
    template<class ApiHolder>    
    IMethod const *BasePropertyMetadataPimpl<ApiHolder>::GetGetMethod() const
    {
        if (m_pSrcProp == nullptr)
        {
            if (m_pGetMethod == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                return m_pGetMethod;
            }
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
    }
    
    
    
    template<class ApiHolder>    
    IMethod const *BasePropertyMetadataPimpl<ApiHolder>::GetSetMethod() const
    {
        if (m_pSrcProp == nullptr)
        {
            if (m_pSetMethod == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                return m_pSetMethod;
            }
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
    }
    
    
    
    template<class ApiHolder>    
    Signature const &BasePropertyMetadataPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }
    
    
    
    template<class ApiHolder>    
    IType const *BasePropertyMetadataPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;

        auto const &member = GetMember();
        auto const *const *ppDeclaringType = get<IType const *>(&member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }
    
    
    
    template<class ApiHolder>    
    PropertyProvider const &BasePropertyMetadataPimpl<ApiHolder>::GetMember() const
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!Empty(m_member))
            return m_member;

        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            //case mdtFieldDef:
            //    if (m_sig.GetBlob().empty())
            //        FillFieldDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig);
            //    FillFieldMember(m_pClass, m_mdtOwner, m_member);
            //    break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(!Empty(m_member));
        return m_member;
    }



    template<class ApiHolder>    
    IProperty const *BasePropertyMetadataPimpl<ApiHolder>::GetSourceProperty() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //return m_pSrcProp == nullptr ? m_pClass : m_pSrcProp->GetSourceProperty();
    }



    template<class ApiHolder>    
    bool BasePropertyMetadataPimpl<ApiHolder>::Equals(IProperty const *pProp) const
    {
        if (m_pClass == pProp)
            return true;

        if (!pProp)
            return false;

        auto const *pOtherProp = dynamic_cast<class_type const *>(pProp);
        if (!pOtherProp)
            return m_pClass->Equals(pProp->GetSourceProperty());

        auto isEqual = true;
        if (isEqual)
            isEqual &= GetToken() == pOtherProp->GetToken();
        
        // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
        if (isEqual && !GetDeclaringType())
            isEqual &= !pOtherProp->GetDeclaringType();
        else if (isEqual)
            isEqual &= GetDeclaringType()->Equals(pOtherProp->GetDeclaringType());
        
        if (isEqual)
            isEqual &= GetAssembly()->Equals(pOtherProp->GetAssembly());
        
        return isEqual;
    }



    template<class ApiHolder>    
    size_t BasePropertyMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        return GetToken();
    }



    template<class ApiHolder>    
    IAssembly const *BasePropertyMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IParameter const *BasePropertyMetadataPimpl<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::SetToken(mdProperty mdp)
    {
        _ASSERTE(!IsNilToken(mdp));
        _ASSERTE(IsNilToken(m_mdp));
        m_mdp = mdp;
    }
    
    
    
    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }
    
    
    
    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        _ASSERTE(callingConvention != CallingConventions::CC_UNREACHED);
        _ASSERTE(m_callingConvention == CallingConventions::CC_UNREACHED);
        m_callingConvention = callingConvention | CallingConventions::CC_PROPERTY;
    }
    
    
    
    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::SetPropertyType(IType const *pPropType)
    {
        _ASSERTE(pPropType != nullptr);
        _ASSERTE(m_pPropType == nullptr);
        m_pPropType = pPropType;
    }



    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::SetMember(PropertyProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::FillPropertyDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, PropertyAttributes &attr, Signature &sig, mdMethodDef &mdmdSetter, mdMethodDef &mdmdGetter)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(sig.GetBlob().empty());

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto wznameLength = 0ul;
        auto dwattr = 0ul;
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto cplusTypeFlag = 0ul;
        auto const *pDefaultValue = static_cast<UVCP_CONSTANT>(nullptr);
        auto defaultValueLength = 0ul;
        auto mdmds = array<mdMethodDef, 256>();
        auto mdmdsLength = 0ul;
        auto hr = pComMetaImp->GetPropertyProps(mdtTarget, &mdtOwner, wzname.c_array(), static_cast<ULONG>(wzname.size()), &wznameLength, &dwattr, &pSig, &sigLength, &cplusTypeFlag, &pDefaultValue, &defaultValueLength, &mdmdSetter, &mdmdGetter, mdmds.c_array(), static_cast<ULONG>(mdmds.size()), &mdmdsLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        attr = PropertyAttributes(dwattr);
        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::FillPropertyDefMember(IProperty const *pProp, mdToken mdtOwner, mdMethodDef mdmdSetter, mdMethodDef mdmdGetter, MethodProvider &member, IMethod const *&pSetMethod, IMethod const *&pGetMethod)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        _ASSERTE(pProp);
        
        auto const *pAsm = pProp->GetAssembly();
        if (Empty(member))
        {
            if (IsNilToken(mdtOwner))
                member = pAsm->GetMainModule();
            else
                member = pAsm->GetType(mdtOwner);
        }
        
        if (!pSetMethod && !IsNilToken(mdmdSetter))
            pSetMethod = pAsm->GetMethod(mdmdSetter);
        
        if (!pGetMethod && !IsNilToken(mdmdGetter))
            pGetMethod = pAsm->GetMethod(mdmdGetter);
    }



    template<class ApiHolder>    
    void BasePropertyMetadataPimpl<ApiHolder>::FillPropertySigProperties(IProperty const *pProp, Signature const &sig, CallingConventions &callingConvention, IType const *&pPropType, vector<IParameter const *> &params)
    {
        _ASSERTE(pProp);
        _ASSERTE(!sig.GetBlob().empty());
        
        if (callingConvention != CallingConventions::CC_UNREACHED)
            return;
        
        auto const &blob = sig.GetBlob();
        sig.Decode(pProp, callingConvention, pPropType, params);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPL_HPP

