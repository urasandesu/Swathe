/* 
 * File: BaseFieldMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseFieldMetadataPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseFieldMetadataPimpl<ApiHolder>::BaseFieldMetadataPimpl(field_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr), 
        m_mdt(mdTokenNil), 
        m_mdtOwner(mdTokenNil), 
        m_callingConvention(CallingConventions::CC_UNREACHED), 
        m_attr(FieldAttributes::FA_UNREACHED), 
        m_pFieldType(nullptr), 
        m_pSrcField(nullptr)
    { }

#define SWATHE_DECLARE_BASE_FIELD_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdToken BaseFieldMetadataPimpl<ApiHolder>::GetToken() const
    {
        if (IsNilToken(m_mdt))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseFieldMetadataPimpl<ApiHolder>::GetName() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    CallingConventions BaseFieldMetadataPimpl<ApiHolder>::GetCallingConvention() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseFieldMetadataPimpl<ApiHolder>::GetFieldType() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    Signature const &BaseFieldMetadataPimpl<ApiHolder>::GetSignature() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseFieldMetadataPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;

        auto const &member = GetMember();
        auto const *const *ppDeclaringType = get<IType const *>(&member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    FieldProvider const &BaseFieldMetadataPimpl<ApiHolder>::GetMember() const
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!Empty(m_member))
            return m_member;

        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtFieldDef:
                if (m_sig.GetBlob().empty())
                    FillFieldDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig);
                FillFieldMember(m_pClass, m_mdtOwner, m_member);
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(!Empty(m_member));
        return m_member;
    }



    template<class ApiHolder>    
    IAssembly const *BaseFieldMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IField const *BaseFieldMetadataPimpl<ApiHolder>::GetSourceField() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //if (!m_srcFieldInit)
        //{
        //    auto mdtTarget = GetToken();
        //    if (TypeFromToken(mdtTarget) == mdtMemberRef)
        //    {
        //        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //    }
        //    else
        //    {
        //        if (TypeFromToken(mdtTarget) == mdtFieldDef)
        //            m_pSrcField = m_pClass;
        //        else
        //            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //    }
        //    m_srcFieldInit = true;
        //}
        //_ASSERTE(m_pSrcField);
        //return m_pSrcField;
    }



    template<class ApiHolder>    
    bool BaseFieldMetadataPimpl<ApiHolder>::Equals(IField const *pField) const
    {
        if (m_pClass == pField)
            return true;

        if (!pField)
            return false;

        auto const *pOtherField = dynamic_cast<class_type const *>(pField);
        if (!pOtherField)
            return m_pClass == pField->GetSourceField();

        return GetToken() == pOtherField->GetToken() &&
               GetDeclaringType() == pOtherField->GetDeclaringType() &&     // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
               GetAssembly() == pOtherField->GetAssembly();
    }



    template<class ApiHolder>    
    ULONG BaseFieldMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Utilities::HashValue;

        auto mdtTarget = GetToken();
        auto declaringTypeHash = HashValue(GetDeclaringType());    // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
        auto asmHash = HashValue(GetAssembly());
        return mdtTarget ^ declaringTypeHash ^ asmHash;
    }



    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::SetToken(mdToken mdt)
    {
        _ASSERTE(!IsNilToken(mdt));
        _ASSERTE(IsNilToken(m_mdt));
        m_mdt = mdt;
    }



    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::SetName(wstring const &name)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::SetFieldType(IType const *pFieldType)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::SetMember(FieldProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::FillFieldDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, FieldAttributes &attr, Signature &sig)
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
        auto hr = pComMetaImp->GetFieldProps(mdtTarget, &mdtOwner, wzname.c_array(), wzname.size(), &wznameLength, &dwattr, &pSig, &sigLength, &cplusTypeFlag, &pDefaultValue, &defaultValueLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        attr = FieldAttributes(dwattr);
        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BaseFieldMetadataPimpl<ApiHolder>::FillFieldMember(IField const *pField, mdToken mdtOwner, FieldProvider &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        _ASSERTE(pField);
        
        if (!Empty(member))
            return;
        
        auto const *pAsm = pField->GetAssembly();
        if (IsNilToken(mdtOwner))
            member = pAsm->GetMainModule();
        else if (TypeFromToken(mdtOwner) == mdtTypeDef)
            member = pAsm->GetType(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtTypeRef)
            member = pAsm->GetType(mdtOwner);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_HPP

