/* 
 * File: BaseTypeMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseTypeMetadataPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseTypeMetadataPimpl<ApiHolder>::BaseTypeMetadataPimpl(type_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr),
        m_mdt(mdTokenNil), 
        m_mdtResolutionScope(mdTokenNil), 
        m_mdtExt(mdTokenNil), 
        m_mdtOwner(mdTokenNil), 
        m_genericParamPos(static_cast<ULONG>(-1)), 
        m_genericArgsInit(false), 
        m_interfacesInit(false), 
        m_methodsInit(false), 
        m_propsInit(false),
        m_casInit(false), 
        m_kind(TypeKinds::TK_UNREACHED), 
        m_attr(TypeAttributes::TA_UNREACHED), 
        m_baseTypeInit(false), 
        m_pBaseType(nullptr), 
        m_srcTypeInit(false), 
        m_pSrcType(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_TYPE_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdToken BaseTypeMetadataPimpl<ApiHolder>::GetToken() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            _ASSERTE(!m_fullName.empty());

            auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();
            auto hr = comMetaImp.FindTypeDefByName(m_fullName.c_str(), NULL, &m_mdt);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseTypeMetadataPimpl<ApiHolder>::GetFullName() const
    {
        if (m_fullName.empty())
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtTypeDef)
                FillTypeDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_fullName, m_attr, m_mdtExt);
            else if (TypeFromToken(mdtTarget) == mdtTypeRef)
                FillTypeRefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_fullName, m_mdtResolutionScope);
            else if (TypeFromToken(mdtTarget) == mdtGenericParam)
                FillGenericParamProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_genericParamPos, m_mdtOwner, m_fullName);
            else if (TypeFromToken(mdtTarget) == mdtTypeSpec)
                m_fullName = GetDeclaringType()->GetFullName();
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        _ASSERTE(!m_fullName.empty());
        return m_fullName;
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsGenericParameter() const
    {
        return TypeFromToken(GetToken()) == mdtGenericParam;
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsGenericType() const
    {
        return !GetGenericArguments().empty();
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsGenericTypeDefinition() const
    {
        if (!IsGenericType())
        {
            return false;
        }
        else
        {
            if (m_kind == TypeKinds::TK_GENERICINST)
            {
                return false;
            }
            else
            {
                auto mdtTarget = GetToken();
                if (TypeFromToken(mdtTarget) == mdtTypeDef)
                    return true;
                else if (TypeFromToken(mdtTarget) == mdtTypeRef)
                    return true;
                else if (TypeFromToken(mdtTarget) == mdtGenericParam)
                    return true;
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                //return GetKind() == TypeKinds::TK_GENERICINST;
            }
        }
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsByRef() const
    {
        return m_kind == TypeKinds::TK_BYREF;
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsArray() const
    {
        return m_kind == TypeKinds::TK_SZARRAY;
    }



    template<class ApiHolder>    
    ULONG BaseTypeMetadataPimpl<ApiHolder>::GetGenericParameterPosition() const
    {
        if (m_genericParamPos == static_cast<ULONG>(-1))
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtGenericParam)
                FillGenericParamProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_genericParamPos, m_mdtOwner, m_fullName);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_genericParamPos;
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeMetadataPimpl<ApiHolder>::GetGenericArguments() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_genericArgsInit)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtGenericParam)
            {
                // nop
            }
            else
            {
                auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();

                auto hEnum = static_cast<HCORENUM>(nullptr);
                    BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                    {
                        if (hEnum)
                            comMetaImp.CloseEnum(hEnum);
                    }
                    BOOST_SCOPE_EXIT_END
                auto mdgps = array<mdGenericParam, 16>();
                auto count = 0ul;
                auto hr = E_FAIL;
                do
                {
                    hr = comMetaImp.EnumGenericParams(&hEnum, mdtTarget, mdgps.c_array(), mdgps.size(), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_genericArgs.reserve(m_genericArgs.size() + count);
                    for (auto i = 0u; i < count; ++i)
                    {
                        auto pGenericArg = m_pAsm->GetType(mdgps[i], TypeKinds::TK_VAR, false, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
                        m_genericArgs.push_back(pGenericArg);
                    }
                } while (0 < count);
            }

            m_genericArgsInit = true;
        }
        return m_genericArgs;
    }



    template<class ApiHolder>    
    Signature const &BaseTypeMetadataPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetGenericTypeDefinition() const
    {
        if (!m_pSrcType)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            //return m_pDeclaringType;  // TODO: m_member から取得。
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
    }



    template<class ApiHolder>    
    TypeAttributes BaseTypeMetadataPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == TypeAttributes::TA_UNREACHED)
        {
            if (!m_pSrcType)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                auto mdtTarget = GetToken();
                if (TypeFromToken(mdtTarget) == mdtTypeDef)
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                    //FillTypeDefProperties(this, mdtTarget, m_pMod, m_fullName, m_attr, m_pBaseType);  // TODO: m_member を補填する。
                    //m_modInit = true;
                }
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
        }
        return m_attr;
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetBaseType() const
    {
        if (!m_baseTypeInit)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtTypeDef)
            {
                if (IsNilToken(m_mdtExt))
                    FillTypeDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_fullName, m_attr, m_mdtExt);
                FillTypeDefBaseType(m_pClass, m_mdtExt, m_baseTypeInit, m_pBaseType);
            }
            else if (TypeFromToken(mdtTarget) == mdtTypeRef)
            {
                m_pBaseType = GetSourceType()->GetBaseType();
                m_baseTypeInit = true;
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
        }
        _ASSERTE(m_baseTypeInit);
        return m_pBaseType;
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeMetadataPimpl<ApiHolder>::GetInterfaces() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_interfacesInit)
        {
            if (!m_pSrcType)
            {
                auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();

                auto hEnum = static_cast<HCORENUM>(nullptr);
                    BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                    {
                        if (hEnum)
                            comMetaImp.CloseEnum(hEnum);
                    }
                    BOOST_SCOPE_EXIT_END
                auto mdiis = array<mdInterfaceImpl, 16>();
                auto count = 0ul;
                auto hr = E_FAIL;
                auto mdtTarget = GetToken();
                do
                {
                    hr = comMetaImp.EnumInterfaceImpls(&hEnum, mdtTarget, mdiis.c_array(), mdiis.size(), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_interfaces.reserve(m_interfaces.size() + count);
                    for (auto i = 0u; i < count; ++i)
                    {
                        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                        //auto pInterfaceImpl = m_pDisp->GetType(m_pAsm, mdiis[i], TypeKinds::TK_UNREACHED, false, MetadataSpecialValues::EMPTY_TYPES, nullptr, nullptr, nullptr);
                        //auto pInterfaceImpl = m_pAsm->GetType(mdiis[i], TypeKinds::TK_UNREACHED, false, MetadataSpecialValues::EMPTY_TYPES, nullptr, nullptr, nullptr);  // TODO: こんな感じの I/F 欲しい。
                        //m_interfaces.push_back(pInterfaceImpl);
                    }
                } while (0 < count);
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            m_interfacesInit = true;
        }
        return m_interfaces;
    }



    template<class ApiHolder>    
    IModule const *BaseTypeMetadataPimpl<ApiHolder>::GetModule() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (Empty(m_member))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

        auto const *const *ppModule = get<IModule const *>(&m_member);
        return !ppModule ? nullptr : *ppModule;
    }



    template<class ApiHolder>    
    IAssembly const *BaseTypeMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (Empty(m_member))
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtGenericParam)
            {
                if (IsNilToken(m_mdtOwner))
                    FillGenericParamProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_genericParamPos, m_mdtOwner, m_fullName);
                FillGenericParamOwner(m_pClass, m_mdtOwner, m_member);
            }
            else if (TypeFromToken(mdtTarget) == mdtTypeSpec)
            {
                if (m_sig.GetBlob().empty())
                    FillTypeSpecSignature(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_sig);
                FillTypeSpecProperties(m_pClass, m_sig, m_kind, m_member, m_genericArgsInit, m_genericArgs);
            }
            else
            {
                if (TypeFromToken(mdtTarget) == mdtTypeDef)
                    m_member = m_pAsm->GetMainModule();
                else 
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
        }

        auto const *const *ppDeclaringType = get<IType const *>(&m_member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetDeclaringMethod() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (Empty(m_member))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

        auto const *const *ppDeclaringMethod = get<IMethod const *>(&m_member);
        return !ppDeclaringMethod ? nullptr : *ppDeclaringMethod;
    }



    template<class ApiHolder>    
    TypeProvider const &BaseTypeMetadataPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetMethod(mdToken mdt) const
    {
        return m_pAsm->GetMethod(mdt, CallingConventions::CC_UNREACHED, false, MetadataSpecialValues::EMPTY_TYPES, nullptr, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IProperty const *BaseTypeMetadataPimpl<ApiHolder>::GetProperty(mdToken mdt) const
    {
        return m_pAsm->GetProperty(mdt, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::ResolveMethod(IMethod const *pMethod) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IProperty const *BaseTypeMetadataPimpl<ApiHolder>::ResolveProperty(IProperty const *pProp) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IField const *BaseTypeMetadataPimpl<ApiHolder>::ResolveField(IField const *pField) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::ResolveType(IType const *pType) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsDefined(IType const *pAttrType, bool inherit) const
    {
        using boost::empty;
        return !empty(GetCustomAttributes(pAttrType, inherit));
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeMetadataPimpl<ApiHolder>::GetCustomAttributes(bool inherit) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_casInit)
        {
            auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();

            auto hEnum = static_cast<HCORENUM>(nullptr);
                BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                {
                    if (hEnum)
                        comMetaImp.CloseEnum(hEnum);
                }
                BOOST_SCOPE_EXIT_END
            auto mdcas = array<mdCustomAttribute, 16>();
            auto count = 0ul;
            auto hr = E_FAIL;
            auto mdtTarget = GetToken();
            do
            {
                hr = comMetaImp.EnumCustomAttributes(&hEnum, mdtTarget, 0, mdcas.c_array(), mdcas.size(), &count);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_cas.reserve(m_cas.size() + count);
                for (auto i = 0u; i < count; ++i)
                {
                    auto pCas = m_pAsm->GetCustomAttribute(mdcas[i], static_cast<IType const *>(m_pClass));
                    m_cas.push_back(pCas);
                }
            } while (0 < count);

            m_casInit = true;
        }

        if (inherit)
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());

        return m_cas;
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeMetadataPimpl<ApiHolder>::GetCustomAttributes(IType const *pAttributeType, bool inherit) const
    {
        using boost::adaptors::filtered;
        using std::function;
        
        auto cas = GetCustomAttributes(inherit);
        auto isTarget = function<bool (ICustomAttribute const *)>();
        isTarget = [pAttributeType](ICustomAttribute const *pCas) { return pCas->GetAttributeType()->GetSourceType() == pAttributeType->GetSourceType(); };
        return cas | filtered(isTarget);
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetSourceType() const
    {
        if (!m_srcTypeInit)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtTypeRef)
            {
                if (IsNilToken(m_mdtResolutionScope))
                    FillTypeRefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_fullName, m_mdtResolutionScope);
                FillTypeRefSourceType(m_pClass, m_mdtResolutionScope, m_fullName, m_srcTypeInit, m_pSrcType);
            }
            else
            {
                if (TypeFromToken(mdtTarget) == mdtTypeDef)
                    m_pSrcType = m_pClass;
                else if (TypeFromToken(mdtTarget) == mdtGenericParam)
                    m_pSrcType = m_pClass;
                else if (TypeFromToken(mdtTarget) == mdtTypeSpec)
                    m_pSrcType = GetDeclaringType()->GetSourceType();
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                m_srcTypeInit = true;
            }
        }
        _ASSERTE(m_pSrcType);
        return m_pSrcType;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::OutDebugInfo(ULONG indent) const
    {
#ifdef OUTPUT_DEBUG
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        D_WCOUTI(indent, L"");
        D_WCOUTI(indent, L"TypeMetadata -----------------------------------------------------");
        D_WCOUTI1(indent, L"m_pClass: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pClass));
        D_WCOUTI1(indent, L"m_pAsm: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pAsm));
        D_WCOUTI1(indent, L"m_member: %|1$d|", m_member.which());
        D_WCOUTI1(indent, L"m_mdt: 0x%|1$08X|", m_mdt);
        D_WCOUTI1(indent, L"m_mdtResolutionScope: 0x%|1$08X|", m_mdtResolutionScope);
        D_WCOUTI1(indent, L"m_mdtExt: 0x%|1$08X|", m_mdtExt);
        D_WCOUTI1(indent, L"m_mdtOwner: 0x%|1$08X|", m_mdtOwner);
        D_WCOUTI1(indent, L"m_fullName: %|1$s|", m_fullName);
        D_WCOUTI1(indent, L"m_genericParamPos: %|1$d|", m_genericParamPos);
        D_WCOUTI1(indent, L"m_genericArgsInit: %|1$d|", m_genericArgsInit);
        D_WCOUTI1(indent, L"m_genericArgs.size(): %|1$d|", m_genericArgs.size());
        for (auto i = m_genericArgs.begin(), i_end = m_genericArgs.end(); i != i_end; ++i)
            (*i)->OutDebugInfo(indent + 4);
        D_WCOUTI1(indent, L"m_interfacesInit: %|1$d|", m_interfacesInit);
        D_WCOUTI1(indent, L"m_interfaces.size(): %|1$d|", m_interfaces.size());
        D_WCOUTI1(indent, L"m_methodsInit: %|1$d|", m_methodsInit);
        D_WCOUTI1(indent, L"m_methods.size(): %|1$d|", m_methods.size());
        D_WCOUTI1(indent, L"m_propsInit: %|1$d|", m_propsInit);
        D_WCOUTI1(indent, L"m_props.size(): %|1$d|", m_props.size());
        D_WCOUTI1(indent, L"m_casInit: %|1$d|", m_casInit);
        D_WCOUTI1(indent, L"m_cas.size(): %|1$d|", m_cas.size());
        auto const &blob = m_sig.GetBlob();
        std::wcout << std::wstring(indent, L' ') << L"m_sig:";
        for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
            std::wcout << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
        std::wcout << std::endl;
        D_WCOUTI1(indent, L"m_kind: %|1$d|", m_kind.Value());
        if (m_kind == TypeKinds::TK_BYREF)
        {
            _ASSERTE(!Empty(m_member));
            GetDeclaringType()->OutDebugInfo(indent + 4);
        }
        D_WCOUTI1(indent, L"m_attr: %|1$d|", m_attr.Value());
        D_WCOUTI1(indent, L"m_baseTypeInit: %|1$d|", m_baseTypeInit);
        D_WCOUTI1(indent, L"m_pBaseType: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pBaseType));
        if (m_pBaseType)
            m_pBaseType->OutDebugInfo(indent + 4);
        D_WCOUTI1(indent, L"m_srcTypeInit: %|1$d|", m_srcTypeInit);
        D_WCOUTI1(indent, L"m_pSrcType: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pSrcType));
        if (m_pSrcType && m_pSrcType != m_pClass)
            m_pSrcType->OutDebugInfo(indent + 4);
        D_WCOUTI(indent, L"------------------------------------------------------------------");
        D_WCOUTI(indent, L"");
#endif
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakeArrayType() const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_SZARRAY, false, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakeGenericType(vector<IType const *> const &genericArgs) const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_GENERICINST, true, genericArgs, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakeByRefType() const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_BYREF, false, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetMethod(wstring const &name) const
    {
        return m_pAsm->GetMethod(name, CallingConventions::CC_UNREACHED, nullptr, false, MetadataSpecialValues::EMPTY_PARAMETERS, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetMethod(wstring const &name, vector<IType const *> const &paramTypes) const
    {
        using boost::adaptors::filtered;
        using boost::copy;
        using std::back_inserter;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto methods = m_pClass->GetMethods();
        auto results = vector<IMethod const *>();
        auto isTarget = 
            [&](IMethod const *pMethod) -> bool
            { 
                using boost::adaptors::transformed;
                using std::function;
                using Urasandesu::CppAnonym::Collections::SequenceEqual;
                                  
                auto toType = function<IType const *(IParameter const *)>();
                toType = [](IParameter const *pParam) { return pParam->GetParameterType(); };
                auto typeEqualTo = [](IType const *x, IType const *y) { return x->GetSourceType() == y->GetSourceType(); };
                return pMethod->GetName() == name && 
                        SequenceEqual(pMethod->GetParameters() | transformed(toType), paramTypes, typeEqualTo); 
            };
        copy(methods | filtered(isTarget), back_inserter(results));
        
        if (results.size() == 0)
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_NOTFOUND));
        
        if (1 < results.size())
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_DUPLICATE));
        
        return results[0];
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes) const
    {
        using boost::adaptors::filtered;
        using boost::copy;
        using std::back_inserter;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto methods = m_pClass->GetMethods();
        auto results = vector<IMethod const *>();
        auto isTarget = 
            [&](IMethod const *pMethod) -> bool
            { 
                using boost::adaptors::transformed;
                using std::function;
                using Urasandesu::CppAnonym::Collections::SequenceEqual;
                                  
                auto toType = function<IType const *(IParameter const *)>();
                toType = [](IParameter const *pParam) { return pParam->GetParameterType(); };
                auto typeEqualTo = [](IType const *x, IType const *y) { return x->GetSourceType() == y->GetSourceType(); };
                return pMethod->GetName() == name && 
                        pMethod->GetCallingConvention() == callingConvention && 
                        pMethod->GetReturnType()->GetSourceType() == pRetType->GetSourceType() && 
                        SequenceEqual(pMethod->GetParameters() | transformed(toType), paramTypes, typeEqualTo); 
            };
        copy(methods | filtered(isTarget), back_inserter(results));
        
        if (results.size() == 0)
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_NOTFOUND));
        
        if (1 < results.size())
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_DUPLICATE));
        
        return results[0];
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetConstructor(vector<IType const *> const &paramTypes) const
    {
        auto const *pMSCorLib = m_pAsm->GetAssembly(MetadataSpecialValues::ASSEMBLY_FULL_NAME_OF_MSCORLIB);
        auto const *pMSCorLibDll = pMSCorLib->GetMainModule();
        auto const *pVoid = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_VOID);
        return m_pClass->GetMethod(MetadataSpecialValues::METHOD_NAME_OF_CTOR, CallingConventions::CC_HAS_THIS, pVoid, paramTypes);
    }



    template<class ApiHolder>    
    IProperty const *BaseTypeMetadataPimpl<ApiHolder>::GetProperty(wstring const &name) const
    {
        using std::find_if;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto const &props = m_pClass->GetProperties();
        auto result = find_if(props.begin(), props.end(), [&](IProperty const *prop) { return prop->GetName() == name; });
        if (result == props.end())
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_NOTFOUND));
        
        return *result;
    }



    template<class ApiHolder>    
    IMethodPtrRange BaseTypeMetadataPimpl<ApiHolder>::GetMethods() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_methodsInit)
        {
            auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();

            auto hEnum = static_cast<HCORENUM>(nullptr);
                BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                {
                    if (hEnum)
                        comMetaImp.CloseEnum(hEnum);
                }
                BOOST_SCOPE_EXIT_END
            auto mdmds = array<mdMethodDef, 16>();
            auto count = 0ul;
            auto hr = E_FAIL;
            auto mdtTarget = m_pClass->GetToken();
            do
            {
                hr = comMetaImp.EnumMethods(&hEnum, mdtTarget, mdmds.c_array(), mdmds.size(), &count);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_methods.reserve(m_methods.size() + count);
                for (auto i = 0u; i < count; ++i)
                {
                    auto const *pMethod = GetMethod(mdmds[i]);
                    m_methods.push_back(pMethod);
                }
            } while (0 < count);

            m_methodsInit = true;
        }
        return m_methods;
    }



    template<class ApiHolder>    
    IMethodPtrRange BaseTypeMetadataPimpl<ApiHolder>::GetConstructors() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<IProperty const *> const &BaseTypeMetadataPimpl<ApiHolder>::GetProperties() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_propsInit)
        {
            auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();

            auto hEnum = static_cast<HCORENUM>(nullptr);
                BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                {
                    if (hEnum)
                        comMetaImp.CloseEnum(hEnum);
                }
                BOOST_SCOPE_EXIT_END
            auto mdps = array<mdProperty, 16>();
            auto count = 0ul;
            auto hr = E_FAIL;
            auto mdtTarget = m_pClass->GetToken();
            do
            {
                hr = comMetaImp.EnumProperties(&hEnum, mdtTarget, mdps.c_array(), mdps.size(), &count);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_props.reserve(m_props.size() + count);
                for (auto i = 0u; i < count; ++i)
                {
                    auto pProp = GetProperty(mdps[i]);
                    m_props.push_back(pProp);
                }
            } while (0 < count);

            m_propsInit = true;
        }
        return m_props;
    }



    template<class ApiHolder>    
    TypeKinds BaseTypeMetadataPimpl<ApiHolder>::GetKind() const
    {
        if (m_kind == TypeKinds::TK_UNREACHED)
        {
            auto const &fullName = GetFullName();
            if (m_kind == TypeKinds::TK_UNREACHED)
            {
                m_kind = MetadataSpecialValues::ToTypeKind(fullName);
                if (m_kind == TypeKinds::TK_UNREACHED)
                {
                    auto const &baseTypeFullName = GetBaseType()->GetFullName();
                    m_kind = MetadataSpecialValues::ToTypeKind(fullName, baseTypeFullName);
                }
            }
        }
        return m_kind;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::SetToken(mdToken mdt)
    {
        _ASSERTE(IsNilToken(m_mdt));
        m_mdt = mdt;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::SetFullName(wstring const &fullName)
    {
        _ASSERTE(!fullName.empty());
        _ASSERTE(m_fullName.empty());
        m_fullName = fullName;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::SetMember(TypeProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::SetGenericArguments(vector<IType const *> const &genericArgs)
    {
        _ASSERTE(!genericArgs.empty());
        _ASSERTE(!m_genericArgsInit);
        m_genericArgsInit = true;
        m_genericArgs = genericArgs;        
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::SetKind(TypeKinds const &kind)
    {
        _ASSERTE(m_kind == TypeKinds::TK_UNREACHED);
        m_kind = kind;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, wstring &fullName, TypeAttributes &attr, mdToken &mdtExt)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(IsNilToken(mdtExt));

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto dwattr = 0ul;
        auto length = 0ul;
        auto hr = pComMetaImp->GetTypeDefProps(mdtTarget, wzname.c_array(), wzname.size(), &length, &dwattr, &mdtExt);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        fullName = wzname.data();
        attr = TypeAttributes(dwattr);
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefBaseType(IType const *pType, mdToken mdtExt, bool &baseTypeInit, IType const *&pBaseType)
    {
        _ASSERTE(pType);
        
        if (IsNilToken(mdtExt)) // e.g. System.Object
            return;
        
        if (baseTypeInit)
            return;
        
        auto const *pAsm = pType->GetAssembly();
        pBaseType = pAsm->GetType(mdtExt);
        baseTypeInit = true;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeRefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, wstring &fullName, mdToken &mdtResolutionScope)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(IsNilToken(mdtResolutionScope));

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto length = 0ul;
        auto hr = pComMetaImp->GetTypeRefProps(mdtTarget, &mdtResolutionScope, wzname.c_array(), wzname.size(), &length);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        fullName = wzname.data();
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeRefSourceType(IType const *pType, mdToken mdtResolutionScope, wstring const &fullName, bool &srcTypeInit, IType const *&pSrcType)
    {
        _ASSERTE(pType);
        _ASSERTE(!IsNilToken(mdtResolutionScope));
        _ASSERTE(!fullName.empty());
        
        if (srcTypeInit)
            return;

        if (TypeFromToken(mdtResolutionScope) == mdtAssemblyRef)
        {
            auto const *pAsm = pType->GetAssembly();
            auto const *pRefAsm = pAsm->GetAssemblyReference(mdtResolutionScope);
            auto const &metadata = pRefAsm->GetAssemblyMetadata();
            auto const *pRefSrcAsm = pAsm->GetAssembly(pRefAsm->GetFullName(), pRefAsm->GetProcessorArchitectures());
            pSrcType = pRefSrcAsm->GetType(fullName);
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        srcTypeInit = true;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillGenericParamProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, ULONG &genericParamPos, mdToken &mdtOwner, wstring &fullName)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(IsNilToken(mdtOwner));

        auto genericParamFlags = 0ul;
        auto reserved = 0ul;
        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto length = 0ul;
        auto hr = pComMetaImp->GetGenericParamProps(mdtTarget, &genericParamPos, &genericParamFlags, &mdtOwner, &reserved, wzname.c_array(), wzname.size(), &length);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        fullName = wzname.data();
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillGenericParamOwner(IType const *pType, mdToken mdtOwner, TypeProvider &member)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        _ASSERTE(pType);
        _ASSERTE(!IsNilToken(mdtOwner));
        
        if (!Empty(member))
            return;
        
        auto const *pAsm = pType->GetAssembly();
        if (TypeFromToken(mdtOwner) == mdtTypeDef)
            member = pAsm->GetType(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtMethodDef)
            member = pAsm->GetMethod(mdtOwner);
        else
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeSpecSignature(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, Signature &sig)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);

        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto hr = pComMetaImp->GetTypeSpecFromToken(mdtTarget, &pSig, &sigLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeSpecProperties(IType const *pType, Signature const &sig, TypeKinds &kind, TypeProvider &member, bool &genericArgsInit, vector<IType const *> &genericArgs)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pType);
        auto const &blob = sig.GetBlob();
        _ASSERTE(!blob.empty());
        kind = TypeKinds(blob[0]);
        switch (kind.Value())
        {
            case TypeKinds::TK_GENERICINST:
                {
                    auto const *pDeclaringType = static_cast<IType *>(nullptr);
                    sig.Decode(pType, kind, pDeclaringType, genericArgs);
                    member = pDeclaringType;
                    genericArgsInit = true;
                }
                break;

            default:
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                break;
        }
    }
    
    
    
    //template<class ApiHolder>    
    //void BaseTypeMetadataPimpl<ApiHolder>::FillAttributes(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, IType const *pOwner, bool &casInit, vector<ICustomAttribute const *> &cas)
    //{
    //    using boost::array;
    //    using Urasandesu::CppAnonym::CppAnonymCOMException;
    //    
    //    _ASSERTE(pComMetaImp);
    //    _ASSERTE(!IsNilToken(mdtTarget));
    //    
    //    auto const *pAsm = pOwner->GetAssembly();

    //    auto hEnum = static_cast<HCORENUM>(nullptr);
    //        BOOST_SCOPE_EXIT((&hEnum)(&pComMetaImp))
    //        {
    //            if (hEnum)
    //                pComMetaImp->CloseEnum(hEnum);
    //        }
    //        BOOST_SCOPE_EXIT_END
    //    auto mdcas = array<mdCustomAttribute, 16>();
    //    auto count = 0ul;
    //    auto hr = E_FAIL;
    //    do
    //    {
    //        hr = pComMetaImp->EnumCustomAttributes(&hEnum, mdtTarget, 0, mdcas.c_array(), mdcas.size(), &count);
    //        if (FAILED(hr))
    //            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

    //        cas.reserve(cas.size() + count);
    //        for (auto i = 0u; i < count; ++i)
    //        {
    //            auto pCas = pAsm->GetCustomAttribute(mdcas[i]);
    //            cas.push_back(pCas);
    //        }
    //    } while (0 < count);
    //    
    //    casInit = true;
    //}

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_HPP

