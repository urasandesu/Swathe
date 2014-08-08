/* 
 * File: BaseLocalMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseLocalMetadataPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseLocalMetadataPimpl<ApiHolder>::BaseLocalMetadataPimpl(local_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr), 
        m_pBody(nullptr), 
        m_mdt(mdTokenNil), 
        m_index(static_cast<ULONG>(-1)), 
        m_pLocalType(nullptr)
    { }

#define SWATHE_DECLARE_BASE_LOCAL_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseLocalMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdToken BaseLocalMetadataPimpl<ApiHolder>::GetToken() const
    {
        // Local does not have its metadata token, but the rule that GetToken surely returns the identity of the scope is convenient.
        // In this case, GetToken returns the index of local variables.
        if (IsNilToken(m_mdt))
        {
            m_mdt = static_cast<mdToken>(m_pClass->GetLocalIndex());
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    SIZE_T BaseLocalMetadataPimpl<ApiHolder>::GetLocalIndex() const
    {
        return m_index;
    }



    template<class ApiHolder>    
    IType const *BaseLocalMetadataPimpl<ApiHolder>::GetLocalType() const
    {
        return m_pLocalType;
    }



    template<class ApiHolder>    
    Signature const &BaseLocalMetadataPimpl<ApiHolder>::GetSignature() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethodBody const *BaseLocalMetadataPimpl<ApiHolder>::GetMethodBody() const
    {
        return m_pBody;
    }



    template<class ApiHolder>    
    ILocal const *BaseLocalMetadataPimpl<ApiHolder>::GetSourceLocal() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    bool BaseLocalMetadataPimpl<ApiHolder>::Equals(ILocal const *pLocal) const
    {
        if (m_pClass == pLocal)
            return true;

        if (!pLocal)
            return false;

        auto const *pOtherLocal = dynamic_cast<class_type const *>(pLocal);
        if (!pOtherLocal)
            return m_pClass == pLocal->GetSourceLocal();

        auto isEqual = true;
        if (isEqual)
            isEqual &= GetToken() == pOtherLocal->GetToken();
        
        if (isEqual && !GetMethodBody())
            isEqual &= !pOtherLocal->GetMethodBody();
        else if (isEqual)
            isEqual &= GetMethodBody()->Equals(pOtherLocal->GetMethodBody());
        
        if (isEqual)
            isEqual &= GetAssembly()->Equals(pOtherLocal->GetAssembly());
        
        return isEqual;
    }



    template<class ApiHolder>    
    size_t BaseLocalMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        return GetToken();
    }



    template<class ApiHolder>    
    IAssembly const *BaseLocalMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    void BaseLocalMetadataPimpl<ApiHolder>::SetMethodBody(IMethodBody const *pBody)
    {
        _ASSERTE(!m_pBody);
        m_pBody = pBody;
    }



    template<class ApiHolder>    
    void BaseLocalMetadataPimpl<ApiHolder>::SetLocalIndex(ULONG index)
    {
        _ASSERTE(m_index == static_cast<ULONG>(-1));
        m_index = index;
    }



    template<class ApiHolder>    
    void BaseLocalMetadataPimpl<ApiHolder>::SetLocalType(IType const *pLocalType)
    {
        _ASSERTE(!m_pLocalType);
        m_pLocalType = pLocalType;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALMETADATAPIMPL_HPP

