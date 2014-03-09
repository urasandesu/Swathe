/* 
 * File: BaseParameterMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseParameterMetadataPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseParameterMetadataPimpl<ApiHolder>::BaseParameterMetadataPimpl(parameter_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr), 
        m_mdt(mdTokenNil),
        m_mdtOwner(mdTokenNil),
        m_position(static_cast<ULONG>(-1)), 
        m_attr(ParameterAttributes::PA_UNREACHED), 
        m_pParamType(nullptr), 
        m_pSrcParam(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_PARAMETER_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseParameterMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdToken BaseParameterMetadataPimpl<ApiHolder>::GetToken() const
    {
        using boost::apply_visitor;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            if (!m_pSrcParam)
            {
                auto mdtTarget = apply_visitor(get_token_visitor(), m_member);
                auto position = GetPosition();
                auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();
                auto hr = comMetaImp.GetParamForMethodIndex(mdtTarget, position, &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    ULONG BaseParameterMetadataPimpl<ApiHolder>::GetPosition() const
    {
        if (m_position == static_cast<ULONG>(-1))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_position;
    }



    template<class ApiHolder>    
    wstring const &BaseParameterMetadataPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtParamDef)
                FillParamDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_position, m_name, m_attr);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }



    template<class ApiHolder>    
    ParameterAttributes BaseParameterMetadataPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == ParameterAttributes::PA_UNREACHED)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtParamDef)
                FillParamDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_position, m_name, m_attr);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_attr;
    }



    template<class ApiHolder>    
    IType const *BaseParameterMetadataPimpl<ApiHolder>::GetParameterType() const
    {
        if (m_pParamType == nullptr)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_pParamType;
    }



    template<class ApiHolder>    
    Signature const &BaseParameterMetadataPimpl<ApiHolder>::GetSignature() const
    {
        if (m_pParamType == nullptr)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_pParamType->GetSignature();
    }



    template<class ApiHolder>    
    IMethod const *BaseParameterMetadataPimpl<ApiHolder>::GetMethod() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IProperty const *BaseParameterMetadataPimpl<ApiHolder>::GetProperty() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ParameterProvider const &BaseParameterMetadataPimpl<ApiHolder>::GetMember() const
    {
        return m_member;
    }



    template<class ApiHolder>    
    IAssembly const *BaseParameterMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IParameter const *BaseParameterMetadataPimpl<ApiHolder>::GetSourceParameter() const
    {
        return !m_pSrcParam ? m_pClass : m_pSrcParam;
    }



    template<class ApiHolder>    
    bool BaseParameterMetadataPimpl<ApiHolder>::Equals(IParameter const *pParam) const
    {
        if (m_pClass == pParam)
            return true;

        if (!pParam)
            return false;

        auto const *pOtherParam = dynamic_cast<class_type const *>(pParam);
        if (!pOtherParam)
            return m_pClass == pParam->GetSourceParameter();

        return GetPosition() == pOtherParam->GetPosition() &&
               GetParameterType() == pOtherParam->GetParameterType() &&     // to determine whether this parameter is ByRef
               GetMember() == pOtherParam->GetMember() &&
               GetAssembly() == pOtherParam->GetAssembly();
    }



    template<class ApiHolder>    
    ULONG BaseParameterMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Utilities::HashValue;
        using Urasandesu::CppAnonym::Utilities::GetPointer;

        auto position = GetPosition();
        auto paramTypeHash = HashValue(GetParameterType());     // to determine whether this parameter is ByRef
        auto memberHash = HashValue(GetPointer(GetMember()));
        auto asmHash = HashValue(GetAssembly());
        return position ^ paramTypeHash ^ memberHash ^ asmHash;
    }



    template<class ApiHolder>    
    void BaseParameterMetadataPimpl<ApiHolder>::OutDebugInfo() const
    {
        BOOST_LOG_FUNCTION();

        CPPANONYM_D_LOGW(L"");
        CPPANONYM_D_LOGW(L"ParameterMetadata -----------------------------------------------------");
        CPPANONYM_D_LOGW1(L"m_pClass: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pClass));
        CPPANONYM_D_LOGW1(L"m_pAsm: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pAsm));
        CPPANONYM_D_LOGW1(L"m_mdt: 0x%|1$08X|", m_mdt);
        CPPANONYM_D_LOGW1(L"m_mdtOwner: 0x%|1$08X|", m_mdtOwner);
        CPPANONYM_D_LOGW1(L"m_name: %|1$s|", m_name);
        CPPANONYM_D_LOGW1(L"m_position: %|1$d|", m_position);
        CPPANONYM_D_LOGW1(L"m_attr: %|1$d|", m_attr.Value());
        CPPANONYM_D_LOGW1(L"m_pParamType: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pParamType));
        if (CPPANONYM_D_LOG_ENABLED())
        {
            if (m_pParamType)
                m_pParamType->OutDebugInfo();
        }
        CPPANONYM_D_LOGW1(L"m_member: %|1$d|", m_member.which());
        CPPANONYM_D_LOGW1(L"m_pSrcParam: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pSrcParam));
        if (CPPANONYM_D_LOG_ENABLED())
        {
            if (m_pSrcParam && m_pSrcParam != m_pClass)
                m_pSrcParam->OutDebugInfo();
        }
        CPPANONYM_D_LOGW(L"------------------------------------------------------------------");
        CPPANONYM_D_LOGW(L"");
    }



    template<class ApiHolder>    
    struct BaseParameterMetadataPimpl<ApiHolder>::get_token_visitor : 
        static_visitor<mdToken>
    {
        template<class T>
        mdToken operator ()(T const &v) const
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

        template<>
        mdToken operator ()<IMethod const *>(IMethod const *const &v) const
        {
            return v->GetToken();
        }

        template<>
        mdToken operator ()<blank>(blank const &v) const
        {
            return mdTokenNil;
        }
    };



    template<class ApiHolder>    
    void BaseParameterMetadataPimpl<ApiHolder>::SetMember(ParameterProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseParameterMetadataPimpl<ApiHolder>::SetPosition(ULONG position)
    {
        _ASSERTE(m_position == static_cast<ULONG>(-1));
        _ASSERTE(0ul < position);
        m_position = position;
    }



    template<class ApiHolder>    
    void BaseParameterMetadataPimpl<ApiHolder>::SetParameterType(IType const *pParamType)
    {
        _ASSERTE(m_pParamType == nullptr);
        _ASSERTE(pParamType != nullptr);
        m_pParamType = pParamType;
    }



    template<class ApiHolder>    
    void BaseParameterMetadataPimpl<ApiHolder>::FillParamDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, ULONG &position, wstring &name, ParameterAttributes &attr)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto wznameLength = 0ul;
        auto dwattr = 0ul;
        auto cplusTypeFlag = 0ul;
        auto const *pDefaultValue = static_cast<UVCP_CONSTANT>(nullptr);
        auto defaultValueLength = 0ul;
        auto hr = pComMetaImp->GetParamProps(mdtTarget, &mdtOwner, &position, wzname.c_array(), wzname.size(), &wznameLength, &dwattr, &cplusTypeFlag, &pDefaultValue, &defaultValueLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        attr = ParameterAttributes(dwattr);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERMETADATAPIMPL_HPP

