/* 
 * File: BaseFieldGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseFieldGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseFieldGeneratorPimpl<ApiHolder>::BaseFieldGeneratorPimpl(field_generator_label_type *pClass) : 
        m_pClass(pClass),
        m_pAsmGen(nullptr),
        m_declaringTypeInit(false), 
        m_mdt(mdTokenNil),
        m_pFieldType(nullptr), 
        m_fieldTypeInit(false), 
        m_attr(FieldAttributes::FA_UNREACHED), 
        m_pSrcField(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_FIELD_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseFieldGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdToken BaseFieldGeneratorPimpl<ApiHolder>::GetToken() const
    {
        BOOST_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            BOOST_LOG_NAMED_SCOPE("if (IsNilToken(m_mdt))");

            if (!m_pSrcField)
            {
                BOOST_LOG_NAMED_SCOPE("if (!m_pSrcField)");

                auto mdtTarget = GetDeclaringType()->GetToken();
                auto const &name = GetName();
                auto const *pFieldType = GetFieldType();
                auto attr = GetAttribute();
                auto const &sig = m_pClass->GetSignature();
                auto const &blob = sig.GetBlob();
                CPPANONYM_D_LOGW1(L"Getting Field Generator Token... 1: %|1$s|", name);
                auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                auto hr = comMetaEmt.DefineField(mdtTarget, name.c_str(), attr.Value(), &blob[0], blob.size(), ELEMENT_TYPE_END, nullptr, 0, &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            else
            {
                BOOST_LOG_NAMED_SCOPE("if (m_pSrcField)");

                if (!m_pAsmGen->IsModifiable())
                {
                    BOOST_LOG_NAMED_SCOPE("if (!m_pAsmGen->IsModifiable())");

                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    BOOST_LOG_NAMED_SCOPE("if (m_pAsmGen->IsModifiable())");

                    CPPANONYM_D_LOGW(L"Getting Field Generator Token... 2: Modifiable Field");
                    m_mdt = m_pSrcField->GetToken();
                }
            }
            CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mdt);
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseFieldGeneratorPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }



    template<class ApiHolder>    
    CallingConventions BaseFieldGeneratorPimpl<ApiHolder>::GetCallingConvention() const
    {
        return CallingConventions::CC_FIELD;
    }



    template<class ApiHolder>    
    IType const *BaseFieldGeneratorPimpl<ApiHolder>::GetFieldType() const
    {
        if (!m_fieldTypeInit)
        {
            if (m_pFieldType == nullptr)
            {
                if (m_pSrcField == nullptr)
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    m_pFieldType = m_pAsmGen->Resolve(m_pSrcField->GetFieldType());
                }
            }
            else
            {
                m_pFieldType = m_pAsmGen->Resolve(m_pFieldType);
            }
            m_fieldTypeInit = true;
        }
        return m_pFieldType;
    }



    template<class ApiHolder>    
    Signature const &BaseFieldGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }



    template<class ApiHolder>    
    IType const *BaseFieldGeneratorPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!m_declaringTypeInit)
        {
            if (Empty(m_member))
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }

            m_declaringTypeInit = true;
        }

        auto const *const *ppDeclaringType = get<IType const *>(&m_member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    IAssembly const *BaseFieldGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    IField const *BaseFieldGeneratorPimpl<ApiHolder>::GetSourceField() const
    {
        return m_pSrcField == nullptr ? m_pClass : m_pSrcField->GetSourceField();
    }



    template<class ApiHolder>    
    FieldAttributes BaseFieldGeneratorPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == FieldAttributes::FA_UNREACHED)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_attr;
    }



    template<class ApiHolder>    
    void BaseFieldGeneratorPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }



    template<class ApiHolder>    
    void BaseFieldGeneratorPimpl<ApiHolder>::SetFieldType(IType const *pFieldType)
    {
        _ASSERTE(pFieldType != nullptr);
        _ASSERTE(m_pFieldType == nullptr);
        m_pFieldType = pFieldType;
    }



    template<class ApiHolder>    
    void BaseFieldGeneratorPimpl<ApiHolder>::SetAttributes(FieldAttributes const &attr)
    {
        _ASSERTE(attr != FieldAttributes::FA_UNREACHED);
        _ASSERTE(m_attr == FieldAttributes::FA_UNREACHED);
        m_attr = attr;
    }



    template<class ApiHolder>    
    void BaseFieldGeneratorPimpl<ApiHolder>::SetSourceField(IField const *pSrcField)
    {
        _ASSERTE(pSrcField != nullptr);
        _ASSERTE(m_pSrcField == nullptr);
        m_pSrcField = pSrcField;
    }



    template<class ApiHolder>    
    void BaseFieldGeneratorPimpl<ApiHolder>::SetMember(FieldProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseFieldGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);

        // TODO: Field 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i).first->Accept(pVisitor);

        m_pClass->GetFieldType();   // resolves the Type of this Field.
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDGENERATORPIMPL_HPP

