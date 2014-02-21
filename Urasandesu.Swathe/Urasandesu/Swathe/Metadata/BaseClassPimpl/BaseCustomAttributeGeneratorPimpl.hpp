/* 
 * File: BaseCustomAttributeGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseCustomAttributeGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseCustomAttributeGeneratorPimpl<ApiHolder>::BaseCustomAttributeGeneratorPimpl(custom_attribute_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsmGen(nullptr), 
        m_mdt(mdTokenNil),
        m_mdtTarget(mdTokenNil), 
        m_ctorInit(false), 
        m_pCtor(nullptr), 
        m_constructorArgsInit(false), 
        m_namedPropsInit(false), 
        m_propValuesInit(false), 
        m_namedFieldsInit(false), 
        m_fieldValuesInit(false), 
        m_pSrcCas(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_CUSTOM_ATTRIBUTE_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseCustomAttributeGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdToken BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetToken() const
    {
        BOOST_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            BOOST_LOG_NAMED_SCOPE("if (IsNilToken(m_mdt))");

            CPPANONYM_D_LOGW(L"Getting Custom Attribute Generator Token... 1");
            auto const &sig = m_pClass->GetSignature();
            auto const &blob = sig.GetBlob();
            auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
            auto hr = comMetaEmt.DefineCustomAttribute(GetTargetToken(), GetConstructor()->GetToken(), &blob[0], blob.size(), &m_mdt);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mdt);
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    Signature const &BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }



    template<class ApiHolder>    
    IMethod const *BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetConstructor() const
    {
        if (!m_ctorInit)
        {
            if (m_pCtor == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_pCtor = m_pAsmGen->Resolve(m_pCtor);
            }
            m_ctorInit = true;
        }
        return m_pCtor;
    }



    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetConstructorArguments() const
    {
        using boost::apply_visitor;

        if (!m_constructorArgsInit)
        {
            for (auto i = m_constructorArgs.begin(), i_end = m_constructorArgs.end(); i != i_end; ++i)
                *i = apply_visitor(resolve_argument_visitor(m_pAsmGen), *i);
            m_constructorArgsInit = true;
        }
        return m_constructorArgs;
    }




    template<class ApiHolder>    
    vector<IProperty const *> const &BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetNamedProperties() const
    {
        if (!m_namedPropsInit)
        {
            for (auto i = m_namedProps.begin(), i_end = m_namedProps.end(); i != i_end; ++i)
                *i = m_pAsmGen->Resolve(*i);
            m_namedPropsInit = true;
        }
        return m_namedProps;
    }



    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetPropertyValues() const
    {
        using boost::apply_visitor;

        if (!m_propValuesInit)
        {
            for (auto i = m_propValues.begin(), i_end = m_propValues.end(); i != i_end; ++i)
                *i = apply_visitor(resolve_argument_visitor(m_pAsmGen), *i);
            m_propValuesInit = true;
        }
        return m_propValues;
    }



    template<class ApiHolder>    
    vector<IField const *> const &BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetNamedFields() const
    {
        if (!m_namedFieldsInit)
        {
            for (auto i = m_namedFields.begin(), i_end = m_namedFields.end(); i != i_end; ++i)
                *i = m_pAsmGen->Resolve(*i);
            m_namedFieldsInit = true;
        }
        return m_namedFields;
    }



    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetFieldValues() const
    {
        if (!m_fieldValuesInit)
        {
            for (auto i = m_fieldValues.begin(), i_end = m_fieldValues.end(); i != i_end; ++i)
                *i = apply_visitor(resolve_argument_visitor(m_pAsmGen), *i);
            m_fieldValuesInit = true;
        }
        return m_fieldValues;
    }



    template<class ApiHolder>    
    CustomAttributeProvider const &BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }


    
    template<class ApiHolder>    
    IAssembly const *BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    ICustomAttribute const *BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetSourceCustomAttribute() const
    {
        return !m_pSrcCas ? m_pClass : m_pSrcCas->GetSourceCustomAttribute();
    }



    template<class ApiHolder>    
    IType const *BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetAttributeType() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    struct BaseCustomAttributeGeneratorPimpl<ApiHolder>::get_token_visitor : 
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
    struct BaseCustomAttributeGeneratorPimpl<ApiHolder>::assign_member_visitor : 
        static_visitor<>
    {
        assign_member_visitor(CustomAttributeProvider &member) : 
            m_member(member)
        { }

        void operator ()(assembly_generator_label_type const *v) const
        {
            m_member = static_cast<IAssembly const *>(v);
        }

        void operator ()(blank const &) const
        {
            // nop
        }

        CustomAttributeProvider &m_member;
    };



    template<class ApiHolder>    
    struct BaseCustomAttributeGeneratorPimpl<ApiHolder>::resolve_argument_visitor : 
        static_visitor<CustomAttributeArgument>
    {
        resolve_argument_visitor(assembly_generator_label_type const *pAsmGen) : 
            m_pAsmGen(pAsmGen)
        { }

        template<class T>
        CustomAttributeArgument operator ()(T const &v) const
        {
            return v;
        }

        template<>
        CustomAttributeArgument operator ()<IType const *>(IType const *const &v) const
        {
            return m_pAsmGen->Resolve(v);
        }

        assembly_generator_label_type const *m_pAsmGen;
    };



    template<class ApiHolder>    
    void BaseCustomAttributeGeneratorPimpl<ApiHolder>::SetConstructor(IMethod const *pCtor)
    {
        _ASSERTE(pCtor != nullptr);
        _ASSERTE(m_pCtor == nullptr);
        m_pCtor = pCtor;
    }



    template<class ApiHolder>    
    void BaseCustomAttributeGeneratorPimpl<ApiHolder>::SetConstructorArguments(vector<CustomAttributeArgument> const &constructorArgs)
    {
        _ASSERTE(!m_constructorArgsInit);
        m_constructorArgs = constructorArgs;
    }



    template<class ApiHolder>    
    void BaseCustomAttributeGeneratorPimpl<ApiHolder>::SetNamedProperties(vector<IProperty const *> const &namedProps)
    {
        _ASSERTE(!m_namedPropsInit);
        m_namedProps = namedProps;
    }



    template<class ApiHolder>    
    void BaseCustomAttributeGeneratorPimpl<ApiHolder>::SetPropertyValues(vector<CustomAttributeArgument> const &propValues)
    {
        _ASSERTE(!m_propValuesInit);
        m_propValues = propValues;
    }



    template<class ApiHolder>    
    mdToken BaseCustomAttributeGeneratorPimpl<ApiHolder>::GetTargetToken() const
    {
        using boost::apply_visitor;

        if (IsNilToken(m_mdtTarget))
            m_mdtTarget = apply_visitor(get_token_visitor(), m_member);
        _ASSERTE(!IsNilToken(m_mdtTarget));
        return m_mdtTarget;
    }



    template<class ApiHolder>    
    void BaseCustomAttributeGeneratorPimpl<ApiHolder>::SetMember(CustomAttributeProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseCustomAttributeGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPL_HPP

