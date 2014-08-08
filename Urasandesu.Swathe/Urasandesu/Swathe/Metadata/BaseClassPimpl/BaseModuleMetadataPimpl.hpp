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
            auto hr = comMetaImp.GetScopeProps(wzname.c_array(), static_cast<ULONG>(wzname.size()), &length, &mvid);
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
    ITypePtrRange BaseModuleMetadataPimpl<ApiHolder>::GetTypes() const
    {
        using boost::adaptors::filtered;
        using std::function;
        
        auto types = m_pAsm->GetTypes();
        auto const *pClass = static_cast<IModule const *>(m_pClass);
        auto isTarget = function<bool (IType const *)>();
        isTarget = [pClass](IType const *pType) { return pClass->Equals(pType->GetModule()); };
        return types | filtered(isTarget);
    }



    template<class ApiHolder>    
    IAssembly const *BaseModuleMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }
    
    
    
    template<class ApiHolder>    
    IModule const *BaseModuleMetadataPimpl<ApiHolder>::GetSourceModule() const
    {
        if (m_pSrcMod)
            return m_pSrcMod;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtModule:
                m_pSrcMod = m_pClass;
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_pSrcMod);
        return m_pSrcMod;
    }



    template<class ApiHolder>    
    bool BaseModuleMetadataPimpl<ApiHolder>::Equals(IModule const *pMod) const
    {
        if (m_pClass == pMod)
            return true;

        if (!pMod)
            return false;

        auto const *pOtherMod = dynamic_cast<class_type const *>(pMod);
        if (!pOtherMod)
            return m_pClass->Equals(pMod->GetSourceModule());

        auto isEqual = true;
        if (isEqual)
            isEqual &= GetToken() == pOtherMod->GetToken();
        
        if (isEqual)
            isEqual &= GetName() == pOtherMod->GetName();
        
        if (isEqual)
            isEqual &= GetAssembly()->Equals(pOtherMod->GetAssembly());
        
        return isEqual;
    }



    template<class ApiHolder>    
    size_t BaseModuleMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        return GetToken();
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

