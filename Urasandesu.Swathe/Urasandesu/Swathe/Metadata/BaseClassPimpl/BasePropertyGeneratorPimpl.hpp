/* 
 * File: BasePropertyGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BasePropertyGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BasePropertyGeneratorPimpl<ApiHolder>::BasePropertyGeneratorPimpl(property_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsmGen(nullptr), 
        m_declaringTypeInit(false), 
        m_mdt(mdTokenNil), 
        m_callingConvention(CallingConventions::CC_UNREACHED), 
        m_pPropType(nullptr), 
        m_propTypeInit(false), 
        m_paramsInit(false), 
        m_attr(PropertyAttributes::PA_UNREACHED), 
        m_pGetMethod(nullptr), 
        m_getMethodInit(false), 
        m_pSetMethod(nullptr), 
        m_setMethodInit(false), 
        m_pSrcProp(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_PROPERTY_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdProperty BasePropertyGeneratorPimpl<ApiHolder>::GetToken() const
    {
        BOOST_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            BOOST_LOG_NAMED_SCOPE("if (IsNilToken(m_mdt))");

            if (!m_pSrcProp)
            {
                BOOST_LOG_NAMED_SCOPE("if (!m_pSrcProp)");

                // TODO: 仮実装
                auto mdtTarget = GetDeclaringType()->GetToken();
                auto const &name = m_pClass->GetName();
                auto attr = m_pClass->GetAttribute();
                auto const &sig = m_pClass->GetSignature();
                auto const &blob = sig.GetBlob();
                auto mdtSetter = m_pClass->GetSetMethod() ? m_pClass->GetSetMethod()->GetToken() : mdTokenNil;
                auto mdtGetter = m_pClass->GetGetMethod() ? m_pClass->GetGetMethod()->GetToken() : mdTokenNil;
                CPPANONYM_D_LOGW1(L"Getting Property Generator Token... 1: %|1$s|", name);
                auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                auto hr = comMetaEmt.DefineProperty(mdtTarget, name.c_str(), attr.Value(), &blob[0], blob.size(), ELEMENT_TYPE_VOID, NULL, 0, mdtSetter, mdtGetter, NULL, &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            else
            {
                BOOST_LOG_NAMED_SCOPE("if (m_pSrcProp)");

                // TODO: 仮実装
                auto mdtSetter = m_pClass->GetSetMethod()->GetToken();
                auto mdtGetter = m_pClass->GetGetMethod()->GetToken();
                m_mdt = IsNilToken(mdtSetter) ? mdtGetter : mdtSetter;
            }
            CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mdt);
        }
        return m_mdt;
    }
    
    
    
    template<class ApiHolder>    
    wstring const &BasePropertyGeneratorPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            if (m_pSrcProp == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_name = m_pSrcProp->GetName();
            }
        }
        return m_name;
    }
    
    
    
    template<class ApiHolder>    
    CallingConventions BasePropertyGeneratorPimpl<ApiHolder>::GetCallingConvention() const
    {
        if (m_callingConvention == CallingConventions::CC_UNREACHED)
        {
            if (m_pSrcProp == nullptr)
            {
                auto const *pGetMethod = m_pClass->GetGetMethod();
                auto const *pSetMethod = m_pClass->GetSetMethod();
                _ASSERTE(pGetMethod || pSetMethod);
                auto callingConvention = pGetMethod ? pGetMethod->GetCallingConvention() : pSetMethod->GetCallingConvention();
                if (callingConvention & CallingConventions::CC_HAS_THIS)
                {
                    m_callingConvention = CallingConventions::CC_PROPERTY & CallingConventions::CC_HAS_THIS;
                }
                else
                {
                    m_callingConvention = CallingConventions::CC_PROPERTY;
                }
            }
            else
            {
                m_callingConvention = m_pSrcProp->GetCallingConvention();
            }
        }
        return m_callingConvention;
    }
    
    
    
    template<class ApiHolder>    
    IType const *BasePropertyGeneratorPimpl<ApiHolder>::GetPropertyType() const
    {
        if (!m_propTypeInit)
        {
            if (m_pPropType == nullptr)
            {
                if (m_pSrcProp == nullptr)
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    m_pPropType = m_pAsmGen->Resolve(m_pSrcProp->GetPropertyType());
                }
            }
            else
            {
                m_pPropType = m_pAsmGen->Resolve(m_pPropType);
            }
            m_propTypeInit = true;
        }
        return m_pPropType;
    }
    
    
    
    template<class ApiHolder>    
    vector<IParameter const *> const &BasePropertyGeneratorPimpl<ApiHolder>::GetParameters() const
    {
        if (!m_paramsInit)
        {
            if (!m_pSrcProp)
            {
                // nop
            }
            else
            {
                auto const &params = m_pSrcProp->GetParameters();
                for (auto i = params.begin(), i_end = params.end(); i != i_end; ++i)
                    m_params.push_back(m_pAsmGen->Resolve(*i));
            }

            m_paramsInit = true;
        }
        return m_params;
    }



    template<class ApiHolder>    
    PropertyAttributes BasePropertyGeneratorPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == PropertyAttributes::PA_UNREACHED)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_attr;
    }
    
    
    
    template<class ApiHolder>    
    IMethod const *BasePropertyGeneratorPimpl<ApiHolder>::GetGetMethod() const
    {
        if (!m_getMethodInit)
        {
            if (m_pGetMethod == nullptr)
            {
                if (m_pSrcProp == nullptr)
                {
                    // nop
                }
                else
                {
                    m_pGetMethod = m_pAsmGen->Resolve(m_pSrcProp->GetGetMethod());
                }
            }
            else
            {
                m_pGetMethod = m_pAsmGen->Resolve(m_pGetMethod);
            }
            m_getMethodInit = true;
        }
        return m_pGetMethod;
    }
    
    
    
    template<class ApiHolder>    
    IMethod const *BasePropertyGeneratorPimpl<ApiHolder>::GetSetMethod() const
    {
        if (!m_setMethodInit)
        {
            if (m_pSetMethod == nullptr)
            {
                if (m_pSrcProp == nullptr)
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    m_pSetMethod = m_pAsmGen->Resolve(m_pSrcProp->GetSetMethod());
                }
            }
            else
            {
                m_pSetMethod = m_pAsmGen->Resolve(m_pSetMethod);
            }
            m_setMethodInit = true;
        }
        return m_pSetMethod;
    }
    
    
    
    template<class ApiHolder>    
    Signature const &BasePropertyGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }
    
    
    
    template<class ApiHolder>    
    IType const *BasePropertyGeneratorPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!m_declaringTypeInit)
        {
            if (Empty(m_member))
            {
                _ASSERTE(m_pSrcProp);
                auto const *pDeclaringType = m_pSrcProp->GetDeclaringType();
                if (pDeclaringType)
                    m_member = m_pAsmGen->Resolve(pDeclaringType);
            }

            m_declaringTypeInit = true;
        }

        auto const *const *ppDeclaringType = get<IType const *>(&m_member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }
    
    
    
    template<class ApiHolder>    
    PropertyProvider const &BasePropertyGeneratorPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IProperty const *BasePropertyGeneratorPimpl<ApiHolder>::GetSourceProperty() const
    {
        return !m_pSrcProp ? m_pClass : m_pSrcProp;
    }



    template<class ApiHolder>    
    IParameter const *BasePropertyGeneratorPimpl<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    bool BasePropertyGeneratorPimpl<ApiHolder>::Equals(IProperty const *pProp) const
    {
        if (m_pClass == pProp)
            return true;

        if (!pProp)
            return false;

        auto const *pOtherPropGen = dynamic_cast<class_type const *>(pProp);
        if (!pOtherPropGen)
            return pProp->Equals(m_pSrcProp);
        
        return GetSourceProperty() == pOtherPropGen->GetSourceProperty();
    }



    template<class ApiHolder>    
    ULONG BasePropertyGeneratorPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Utilities::HashValue;
        return !m_pSrcProp ? HashValue(m_pClass) : m_pSrcProp->GetHashCode();
    }



    template<class ApiHolder>    
    IAssembly const *BasePropertyGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetGetMethod(IMethod const *pGetMethod)
    {
        m_pGetMethod = pGetMethod;
    }
    
    
    
    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetSetMethod(IMethod const *pSetMethod)
    {
        m_pSetMethod = pSetMethod;
    }
    
    
    
    template<class ApiHolder>    
    typename BasePropertyGeneratorPimpl<ApiHolder>::parameter_generator_label_type *BasePropertyGeneratorPimpl<ApiHolder>::DefineParameter(ULONG position, IType const *pParamType)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }
    
    
    
    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetPropertyType(IType const *pPropType)
    {
        _ASSERTE(pPropType != nullptr);
        _ASSERTE(m_pPropType == nullptr);
        m_pPropType = pPropType;
    }
    
    
    
    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetParameters(vector<IParameter const *> const &params)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetAttributes(PropertyAttributes const &attr)
    {
        _ASSERTE(attr != PropertyAttributes::PA_UNREACHED);
        _ASSERTE(m_attr == PropertyAttributes::PA_UNREACHED);
        m_attr = attr;
    }
    
    
    
    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetSourceProperty(IProperty const *pSrcProp)
    {
        _ASSERTE(pSrcProp != nullptr);
        _ASSERTE(m_pSrcProp == nullptr);
        m_pSrcProp = pSrcProp;
    }



    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::SetMember(PropertyProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BasePropertyGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);

        // TODO: Property 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i).first->Accept(pVisitor);
        
        m_pClass->GetPropertyType();   // resolves the Type of this Property.
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_HPP

