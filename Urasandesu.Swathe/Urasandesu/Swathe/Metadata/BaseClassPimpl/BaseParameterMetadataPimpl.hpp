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
    IParameter const *BaseParameterMetadataPimpl<ApiHolder>::GetSourceParameter() const
    {
        return m_pSrcParam == nullptr ? m_pClass : m_pSrcParam->GetSourceParameter();
    }



    template<class ApiHolder>    
    void BaseParameterMetadataPimpl<ApiHolder>::OutDebugInfo(ULONG indent) const
    {
#ifdef OUTPUT_DEBUG
        D_WCOUTI(indent, L"");
        D_WCOUTI(indent, L"ParameterMetadata -----------------------------------------------------");
        D_WCOUTI1(indent, L"m_pClass: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pClass));
        D_WCOUTI1(indent, L"m_pAsm: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pAsm));
        D_WCOUTI1(indent, L"m_mdt: 0x%|1$08X|", m_mdt);
        D_WCOUTI1(indent, L"m_mdtOwner: 0x%|1$08X|", m_mdtOwner);
        D_WCOUTI1(indent, L"m_name: %|1$s|", m_name);
        D_WCOUTI1(indent, L"m_position: %|1$d|", m_position);
        D_WCOUTI1(indent, L"m_attr: %|1$d|", m_attr.Value());
        D_WCOUTI1(indent, L"m_pParamType: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pParamType));
        if (m_pParamType)
            m_pParamType->OutDebugInfo(indent + 4);
        D_WCOUTI1(indent, L"m_member: %|1$d|", m_member.which());
        D_WCOUTI1(indent, L"m_pSrcParam: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pSrcParam));
        if (m_pSrcParam && m_pSrcParam != m_pClass)
            m_pSrcParam->OutDebugInfo(indent + 4);
        D_WCOUTI(indent, L"------------------------------------------------------------------");
        D_WCOUTI(indent, L"");
#endif
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

