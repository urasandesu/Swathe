/* 
 * File: BaseLocalGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseLocalGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseLocalGeneratorPimpl<ApiHolder>::BaseLocalGeneratorPimpl(local_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsmGen(nullptr), 
        m_pBody(nullptr),
        m_mdt(mdTokenNil), 
        m_index(static_cast<SIZE_T>(-1)),
        m_localTypeInit(false), 
        m_pLocalType(nullptr), 
        m_pSrcLocal(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_LOCAL_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseLocalGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdToken BaseLocalGeneratorPimpl<ApiHolder>::GetToken() const
    {
        // Local does not have its metadata token, but the rule that GetToken surely returns the identity of the scope is convenient.
        // In this case, GetToken returns the index of local variables.
        if (IsNilToken(m_mdt))
        {
            m_mdt = m_pClass->GetLocalIndex();
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    SIZE_T BaseLocalGeneratorPimpl<ApiHolder>::GetLocalIndex() const
    {
        return m_index;
    }



    template<class ApiHolder>    
    IType const *BaseLocalGeneratorPimpl<ApiHolder>::GetLocalType() const
    {
        if (!m_localTypeInit)
        {
            if (m_pLocalType == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_pLocalType = m_pAsmGen->Resolve(m_pLocalType);
            }
            m_localTypeInit = true;
        }
        return m_pLocalType;
    }



    template<class ApiHolder>    
    Signature const &BaseLocalGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        return GetLocalType()->GetSignature();
    }



    template<class ApiHolder>    
    IMethodBody const *BaseLocalGeneratorPimpl<ApiHolder>::GetMethodBody() const
    {
        return m_pBody;
    }



    template<class ApiHolder>    
    ILocal const *BaseLocalGeneratorPimpl<ApiHolder>::GetSourceLocal() const
    {
        return !m_pSrcLocal ? m_pClass : m_pSrcLocal->GetSourceLocal();
    }



    template<class ApiHolder>    
    IAssembly const *BaseLocalGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseLocalGeneratorPimpl<ApiHolder>::SetLocalIndex(SIZE_T index)
    {
        _ASSERTE(index != static_cast<SIZE_T>(-1));
        _ASSERTE(m_index == static_cast<SIZE_T>(-1));
        m_index = index;
    }



    template<class ApiHolder>    
    void BaseLocalGeneratorPimpl<ApiHolder>::SetLocalType(IType const *pLocalType)
    {
        _ASSERTE(pLocalType != nullptr);
        _ASSERTE(m_pLocalType == nullptr);
        m_pLocalType = pLocalType;
    }



    template<class ApiHolder>    
    void BaseLocalGeneratorPimpl<ApiHolder>::SetMethodBody(IMethodBody const *pBody)
    {
        _ASSERTE(!m_pBody);
        m_pBody = pBody;
    }



    template<class ApiHolder>    
    void BaseLocalGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPL_HPP

