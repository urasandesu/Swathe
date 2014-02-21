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
        m_srcFieldInit(false), 
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
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IAssembly const *BaseFieldMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IField const *BaseFieldMetadataPimpl<ApiHolder>::GetSourceField() const
    {
        if (!m_srcFieldInit)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                if (TypeFromToken(mdtTarget) == mdtFieldDef)
                    m_pSrcField = m_pClass;
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            m_srcFieldInit = true;
        }
        _ASSERTE(m_pSrcField);
        return m_pSrcField;
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

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEFIELDMETADATAPIMPL_HPP

