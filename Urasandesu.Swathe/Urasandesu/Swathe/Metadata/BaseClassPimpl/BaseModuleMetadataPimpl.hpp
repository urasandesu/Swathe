/* 
 * File: BaseModuleMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseModuleMetadataPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseModuleMetadataPimpl<ApiHolder>::BaseModuleMetadataPimpl(module_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr),
        m_mdm(mdModuleNil), 
        m_typesInit(false), 
        m_pSrcMod(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_MODULE_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseModuleMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }
    
    
    template<class ApiHolder>    
    mdModule BaseModuleMetadataPimpl<ApiHolder>::GetToken() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_mdm == mdModuleNil)
        {
            auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();
            auto hr = comMetaImp.GetModuleFromScope(&m_mdm);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return m_mdm;
    }
    
    
    template<class ApiHolder>    
    wstring const &BaseModuleMetadataPimpl<ApiHolder>::GetName() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_name == MetadataSpecialValues::MODULE_NAME_OF_MAIN)
        {
            auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();
            
            auto wzname = array<WCHAR, MAX_SYM_NAME>();
            auto length = 0ul;
            auto mvid = GUID();
            auto hr = comMetaImp.GetScopeProps(wzname.c_array(), wzname.size(), &length, &mvid);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_name = wzname.data();
        }
        else if (m_name.empty())
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }
    
    
    template<class ApiHolder>    
    IType const *BaseModuleMetadataPimpl<ApiHolder>::GetType(wstring const &fullName) const
    {
        return m_pAsm->GetType(fullName, static_cast<IModule const *>(m_pClass));
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseModuleMetadataPimpl<ApiHolder>::GetTypes() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_typesInit)
        {
            auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();

            auto hEnum = static_cast<HCORENUM>(nullptr);
                BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                {
                    if (hEnum)
                        comMetaImp.CloseEnum(hEnum);
                }
                BOOST_SCOPE_EXIT_END
            auto mdtds = array<mdTypeDef, 16>();
            auto count = 0ul;
            auto hr = E_FAIL;
            do
            {
                hr = comMetaImp.EnumTypeDefs(&hEnum, mdtds.c_array(), mdtds.size(), &count);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_types.reserve(m_types.size() + count);
                for (auto i = 0u; i < count; ++i)
                {
                    auto const *pType = m_pAsm->GetType(mdtds[i]);
                    m_types.push_back(pType);
                }
            } while (0 < count);

            m_typesInit = true;
        }
        return m_types;
    }



    template<class ApiHolder>    
    IAssembly const *BaseModuleMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }
    
    
    
    template<class ApiHolder>    
    IModule const *BaseModuleMetadataPimpl<ApiHolder>::GetSourceModule() const
    {
        return m_pSrcMod == nullptr ? m_pClass : m_pSrcMod->GetSourceModule();
    }
    
    
    
    template<class ApiHolder>    
    IType const *BaseModuleMetadataPimpl<ApiHolder>::ResolveType(IType const *pType) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }

    
    
    template<class ApiHolder>    
    void BaseModuleMetadataPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMODULEMETADATAPIMPL_HPP

