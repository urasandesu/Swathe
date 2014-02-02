/* 
 * File: BaseModuleGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseModuleGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATARESOLVER_H
#include <Urasandesu/Swathe/Metadata/MetadataResolver.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseModuleGeneratorPimpl<ApiHolder>::BaseModuleGeneratorPimpl(module_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsmGen(nullptr), 
        m_mdt(mdTokenNil), 
        m_pSrcMod(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_MODULE_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseModuleGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdModule BaseModuleGeneratorPimpl<ApiHolder>::GetToken() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            if (m_pSrcMod == nullptr)
            {
                auto const &name = GetName();
                auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                auto hr = comMetaEmt.SetModuleProps(name.c_str());
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
                m_mdt = 0x00000001; // NOTE: The metadata token of Module shall be constant value.
            }
            else
            {
                m_mdt = m_pSrcMod->GetToken();
            }
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseModuleGeneratorPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            if (m_pSrcMod == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_name = m_pSrcMod->GetName();
            }
        }
        return m_name;
    }



    template<class ApiHolder>    
    IType const *BaseModuleGeneratorPimpl<ApiHolder>::GetType(wstring const &fullName) const
    {
        if (m_pSrcMod == nullptr)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return MetadataResolver::Resolve(m_pSrcMod->GetType(fullName));
        }
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseModuleGeneratorPimpl<ApiHolder>::GetTypes() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IAssembly const *BaseModuleGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    IModule const *BaseModuleGeneratorPimpl<ApiHolder>::GetSourceModule() const
    {
        return m_pSrcMod == nullptr ? m_pClass : m_pSrcMod->GetSourceModule();
    }



    template<class ApiHolder>    
    IType const *BaseModuleGeneratorPimpl<ApiHolder>::ResolveType(IType const *pType) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<pair<type_generator_label_type const *, SIZE_T> > TypeGenToIndex;
        typedef TypeGenToIndex::value_type Value;

        _ASSERTE(m_pClass->GetSourceModule() == pType->GetModule()->GetSourceModule());

        auto const &typeGenToIndex = m_pAsmGen->GetTypeGeneratorToIndex();
        auto isMine = [&](Value const &v) { return v.first->GetModule() == m_pClass; };
        auto myTypeGenToIndex = typeGenToIndex | filtered(isMine);
        auto isAlreadyExist = [&](Value const &v) { return v.first->GetSourceType() == pType->GetSourceType(); };
        auto result = FindIf(myTypeGenToIndex, isAlreadyExist);
        if (result)
            return (*result).first;
        
        return m_pAsmGen->DefineType(pType, static_cast<IModule const *>(m_pClass));
    }



    template<class ApiHolder>    
    typename BaseModuleGeneratorPimpl<ApiHolder>::type_generator_label_type *BaseModuleGeneratorPimpl<ApiHolder>::DefineType(wstring const &fullName, TypeAttributes const &attr)
    {
        return m_pAsmGen->DefineType(fullName, attr, static_cast<IModule const *>(m_pClass));
    }



    template<class ApiHolder>    
    void BaseModuleGeneratorPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }



    template<class ApiHolder>    
    void BaseModuleGeneratorPimpl<ApiHolder>::SetSourceModule(IModule const *pSrcMod)
    {
        _ASSERTE(m_pSrcMod == nullptr);
        _ASSERTE(pSrcMod != nullptr);
        m_pSrcMod = pSrcMod;
    }



    template<class ApiHolder>    
    void BaseModuleGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        using boost::adaptors::filtered;

        pVisitor->Visit(m_pClass);

        // TODO: Module 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i).first->Accept(pVisitor);

        auto const &typeGenToIndex = m_pAsmGen->GetTypeGeneratorToIndex();
        for (auto i = 0ul; i < typeGenToIndex.size(); ++i)
            if (typeGenToIndex[i].first->GetModule() == m_pClass)
                typeGenToIndex[i].first->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEGENERATORPIMPL_HPP

