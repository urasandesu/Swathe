/* 
 * File: BaseParameterGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseParameterGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseParameterGeneratorPimpl<ApiHolder>::BaseParameterGeneratorPimpl(parameter_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsmGen(nullptr), 
        m_mdt(mdTokenNil),
        m_position(static_cast<ULONG>(-1)), 
        m_nameInit(false), 
        m_attr(ParameterAttributes::PA_UNREACHED), 
        m_paramTypeInit(false), 
        m_pParamType(nullptr), 
        m_methodInit(false), 
        m_pSrcParam(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_PARAMETER_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseParameterGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdToken BaseParameterGeneratorPimpl<ApiHolder>::GetToken() const
    {
        BOOST_LOG_FUNCTION();

        using boost::apply_visitor;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            BOOST_LOG_NAMED_SCOPE("if (IsNilToken(m_mdt))");

            if (!m_pSrcParam)
            {
                BOOST_LOG_NAMED_SCOPE("if (!m_pSrcParam)");

                auto mdtTarget = apply_visitor(get_token_visitor(), m_member);
                auto pos = m_pClass->GetPosition();
                auto const &name = m_pClass->GetName();
                auto attr = m_pClass->GetAttribute();
                CPPANONYM_D_LOGW1(L"Getting Parameter Generator Token... 1: %|1$s|", name);
                auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                auto hr = comMetaEmt.DefineParam(mdtTarget, pos, name.c_str(), attr.Value(), ELEMENT_TYPE_VOID, NULL, 0, &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            else
            {
                // TODO: 仮実装
                m_mdt = m_pSrcParam->GetToken();
            }
            CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mdt);
        }
        return m_mdt;
    }
    
    
    
    template<class ApiHolder>    
    ULONG BaseParameterGeneratorPimpl<ApiHolder>::GetPosition() const
    {
        if (m_position == static_cast<ULONG>(-1))
        {
            if (!m_pSrcParam)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_position = m_pSrcParam->GetPosition();
            }
        }
        return m_position;
    }
    
    
    
    template<class ApiHolder>    
    wstring const &BaseParameterGeneratorPimpl<ApiHolder>::GetName() const
    {
        if (!m_nameInit)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }
    
    
    
    template<class ApiHolder>    
    ParameterAttributes BaseParameterGeneratorPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == ParameterAttributes::PA_UNREACHED)
            m_attr = !m_pSrcParam ? ParameterAttributes::PA_NONE : m_pSrcParam->GetAttribute();
        return m_attr;
    }
    
    
    
    template<class ApiHolder>    
    IType const *BaseParameterGeneratorPimpl<ApiHolder>::GetParameterType() const
    {
        if (!m_paramTypeInit)
        {
            if (!m_pParamType)
            {
                if (!m_pSrcParam)
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    m_pParamType = m_pAsmGen->Resolve(m_pSrcParam->GetParameterType());
                }
            }
            else
            {
                m_pParamType = m_pAsmGen->Resolve(m_pParamType);
            }
            m_paramTypeInit = true;
        }
        return m_pParamType;
    }
    
    
    
    template<class ApiHolder>    
    Signature const &BaseParameterGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        return GetParameterType()->GetSignature();
    }
    
    
    
    template<class ApiHolder>    
    IMethod const *BaseParameterGeneratorPimpl<ApiHolder>::GetMethod() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!m_methodInit)
        {
            if (Empty(m_member))
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }

            m_methodInit = true;
        }

        auto const *const *ppMethod = get<IMethod const *>(&m_member);
        return !ppMethod ? nullptr : *ppMethod;
    }



    template<class ApiHolder>    
    IProperty const *BaseParameterGeneratorPimpl<ApiHolder>::GetProperty() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ParameterProvider const &BaseParameterGeneratorPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }
    
    
    
    template<class ApiHolder>    
    IAssembly const *BaseParameterGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    IParameter const *BaseParameterGeneratorPimpl<ApiHolder>::GetSourceParameter() const
    {
        return !m_pSrcParam ? m_pClass : m_pSrcParam;
    }



    template<class ApiHolder>    
    bool BaseParameterGeneratorPimpl<ApiHolder>::Equals(IParameter const *pParam) const
    {
        if (m_pClass == pParam)
            return true;

        if (!pParam)
            return false;

        auto const *pOtherParamGen = dynamic_cast<class_type const *>(pParam);
        if (!pOtherParamGen)
            return pParam->Equals(m_pSrcParam);
        
        return GetSourceParameter() == pOtherParamGen->GetSourceParameter();
    }



    template<class ApiHolder>    
    ULONG BaseParameterGeneratorPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Utilities::HashValue;
        return !m_pSrcParam ? HashValue(m_pClass) : m_pSrcParam->GetHashCode();
    }



    template<class ApiHolder>    
    void BaseParameterGeneratorPimpl<ApiHolder>::OutDebugInfo() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    struct BaseParameterGeneratorPimpl<ApiHolder>::get_token_visitor : 
        static_visitor<mdToken>
    {
        template<class T>
        mdToken operator ()(T const &v) const
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
    struct BaseParameterGeneratorPimpl<ApiHolder>::assign_member_visitor : 
        static_visitor<>
    {
        assign_member_visitor(ParameterProvider &member) : 
            m_member(member)
        { }

        void operator ()(method_generator_label_type const *v) const
        {
            m_member = static_cast<IMethod const *>(v);
        }

        void operator ()(blank const &) const
        {
            // nop
        }

        ParameterProvider &m_member;
    };



    template<class ApiHolder>    
    void BaseParameterGeneratorPimpl<ApiHolder>::SetPosition(ULONG position)
    {
        _ASSERTE(m_position == static_cast<ULONG>(-1));
        _ASSERTE(0ul < position);
        m_position = position;
        m_nameInit = true;
    }
    
    
    
    template<class ApiHolder>    
    void BaseParameterGeneratorPimpl<ApiHolder>::SetParameterType(IType const *pParamType)
    {
        _ASSERTE(m_pParamType == nullptr);
        _ASSERTE(pParamType != nullptr);
        m_pParamType = pParamType;
    }
    
    
    
    template<class ApiHolder>    
    void BaseParameterGeneratorPimpl<ApiHolder>::SetSourceParameter(IParameter const *pSrcParam)
    {
        _ASSERTE(pSrcParam != nullptr);
        _ASSERTE(m_pSrcParam == nullptr);
        m_pSrcParam = pSrcParam;
    }



    template<class ApiHolder>    
    void BaseParameterGeneratorPimpl<ApiHolder>::SetMember(ParameterProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseParameterGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);

        // TODO: Parameter 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i).first->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPARAMETERGENERATORPIMPL_HPP

