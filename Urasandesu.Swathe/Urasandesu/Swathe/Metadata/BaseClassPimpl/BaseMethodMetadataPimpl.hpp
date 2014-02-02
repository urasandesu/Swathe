/* 
 * File: BaseMethodMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodMetadataPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseMethodMetadataPimpl<ApiHolder>::BaseMethodMetadataPimpl(method_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsm(nullptr), 
        m_mdt(mdTokenNil),
        m_mdtOwner(mdTokenNil), 
        m_callingConvention(CallingConventions::CC_UNREACHED), 
        m_retTypeInit(false), 
        m_pRetType(nullptr),
        m_paramsInit(false),
        m_genericArgsInit(false), 
        m_pILBody(nullptr), 
        m_pBody(nullptr), 
        m_pSrcMethod(nullptr), 
        m_attr(MethodAttributes::MA_UNREACHED), 
        m_codeRva(static_cast<ULONG>(-1))
    { }
    
#define SWATHE_DECLARE_BASE_METHOD_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        _ASSERTE(pAsm);
        _ASSERTE(!m_pAsm);
        m_pAsm = pAsm;
    }



    template<class ApiHolder>    
    mdToken BaseMethodMetadataPimpl<ApiHolder>::GetToken() const
    {
        using boost::adaptors::filtered;
        using boost::copy;
        using std::back_inserter;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::SimpleBlob;

        if (IsNilToken(m_mdt))
        {
            _ASSERTE(!m_name.empty());
            if (m_callingConvention == CallingConventions::CC_UNREACHED)
            {
                auto methods = GetDeclaringType()->GetMethods();
                auto results = vector<IMethod const *>();
                auto isTarget = [&](IMethod const *pMethod) { return pMethod->GetName() == m_name; };
                copy(methods | filtered(isTarget), back_inserter(results));
                
                if (results.size() == 0)
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_NOTFOUND));
                
                if (1 < results.size())
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_DUPLICATE));
                
                m_mdt = results[0]->GetToken();
            }
            else
            {
                _ASSERTE(m_pRetType);
            
                auto const &sig = m_pClass->GetSignature();
                auto const &blob = sig.GetBlob();
                auto &comMetaImp = m_pAsm->GetCOMMetaDataImport();
                auto hr = comMetaImp.FindMethod(GetDeclaringType()->GetToken(), m_name.c_str(), &blob[0], blob.size(), &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseMethodMetadataPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtMethodDef)
                FillMethodDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }



    template<class ApiHolder>    
    CallingConventions BaseMethodMetadataPimpl<ApiHolder>::GetCallingConvention() const
    {
        if (m_callingConvention == CallingConventions::CC_UNREACHED)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtMethodDef)
            {
                if (m_sig.GetBlob().empty())
                    FillMethodDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
            }
            else if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                if (m_sig.GetBlob().empty())
                    FillMethodRefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_sig);
            }
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());

            FillMethodSigProperties(m_pClass, m_sig, m_callingConvention, m_retTypeInit, m_pRetType, m_paramsInit, m_params);
        }
        return m_callingConvention;
    }



    template<class ApiHolder>    
    MethodAttributes BaseMethodMetadataPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == MethodAttributes::MA_UNREACHED)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            //auto mdtTarget = GetToken();
            //if (TypeFromToken(mdtTarget) == mdtMethodDef)
            //{
            //    auto const *pDeclaringType = static_cast<IType *>(nullptr);
            //    FillMethodDefProperties(this, mdtTarget, m_pDeclaringType, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
            //    if (!m_declaringTypeInit)
            //        m_pDeclaringType = pDeclaringType;
            //}
            //else
            //    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_attr;
    }



    template<class ApiHolder>    
    IType const *BaseMethodMetadataPimpl<ApiHolder>::GetReturnType() const
    {
        if (!m_retTypeInit)
        {
            auto callingConvention = GetCallingConvention();
            if (callingConvention & CallingConventions::CC_GENERIC_INST)
            {
                auto const *pDeclaringMethod = GetDeclaringMethod();
                m_pRetType = pDeclaringMethod->GetReturnType();
            }

            m_retTypeInit = true;
        }
        return m_pRetType;
    }



    template<class ApiHolder>    
    vector<IParameter const *> const &BaseMethodMetadataPimpl<ApiHolder>::GetParameters() const
    {
        if (!m_paramsInit)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtMethodDef)
            {
                if (m_sig.GetBlob().empty())
                    FillMethodDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
            }
            else if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                if (m_sig.GetBlob().empty())
                    FillMethodRefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_sig);
            }
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            
            FillMethodSigProperties(m_pClass, m_sig, m_callingConvention, m_retTypeInit, m_pRetType, m_paramsInit, m_params);
        }
        return m_params;
    }



    template<class ApiHolder>    
    IMethodBody const *BaseMethodMetadataPimpl<ApiHolder>::GetMethodBody() const
    {
        if (!m_pBody)
            m_pBody = m_pAsm->GetMethodBody(m_pILBody, m_pClass);
        return m_pBody;
    }



    template<class ApiHolder>    
    ULONG BaseMethodMetadataPimpl<ApiHolder>::GetCodeRVA() const
    {
        if (m_codeRva == static_cast<ULONG>(-1))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_codeRva;
    }



    template<class ApiHolder>    
    bool BaseMethodMetadataPimpl<ApiHolder>::IsStatic() const
    {
        return !(GetCallingConvention() & CallingConventions::CC_HAS_THIS);
    }



    template<class ApiHolder>    
    bool BaseMethodMetadataPimpl<ApiHolder>::IsGenericMethod() const
    {
        return !GetGenericArguments().empty();
    }



    template<class ApiHolder>    
    bool BaseMethodMetadataPimpl<ApiHolder>::IsGenericMethodDefinition() const
    {
        if (!IsGenericMethod())
        {
            return false;
        }
        else
        {
            if (m_callingConvention & CallingConventions::CC_GENERIC_INST)
            {
                return false;
            }
            else
            {
                auto mdtTarget = GetToken();
                if (TypeFromToken(mdtTarget) == mdtMethodDef)
                    return true;
                else if (TypeFromToken(mdtTarget) == mdtMemberRef)
                    return true;
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                //return !m_pDeclaringMethod;
            }
        }
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseMethodMetadataPimpl<ApiHolder>::GetGenericArguments() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_genericArgsInit)
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
            auto mdtTarget = GetToken();
            do
            {
                hr = comMetaImp.EnumGenericParams(&hEnum, mdtTarget, mdgps.c_array(), mdgps.size(), &count);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_genericArgs.reserve(m_genericArgs.size() + count);
                for (auto i = 0u; i < count; ++i)
                {
                    auto pGenericArg = m_pAsm->GetType(mdgps[i], TypeKinds::TK_MVAR, false, MetadataSpecialValues::EMPTY_TYPES, static_cast<IMethod const *>(m_pClass));
                    m_genericArgs.push_back(pGenericArg);
                }
            } while (0 < count);

            m_genericArgsInit = true;
        }
        return m_genericArgs;
    }



    template<class ApiHolder>    
    Signature const &BaseMethodMetadataPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodMetadataPimpl<ApiHolder>::MakeGenericMethod(vector<IType const *> const &genericArgs) const
    {
        return m_pAsm->GetMethod(GetToken(), GetCallingConvention() | CallingConventions::CC_GENERIC_INST, true, genericArgs, nullptr, static_cast<IMethod const *>(m_pClass));
    }



    template<class ApiHolder>    
    IAssembly const *BaseMethodMetadataPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsm;
    }



    template<class ApiHolder>    
    IType const *BaseMethodMetadataPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (Empty(m_member))
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtMethodDef)
            {
                if (m_sig.GetBlob().empty())
                    FillMethodDefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
                FillMethodDefMember(m_pClass, m_mdtOwner, m_member);
            }
            else if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                if (m_sig.GetBlob().empty())
                    FillMethodRefProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner, m_name, m_sig);
                FillMethodRefMember(m_pClass, m_mdtOwner, m_member);
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
        }

        auto const *const *ppDeclaringType = get<IType const *>(&m_member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodMetadataPimpl<ApiHolder>::GetDeclaringMethod() const
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
    MethodProvider const &BaseMethodMetadataPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodMetadataPimpl<ApiHolder>::GetSourceMethod() const
    {
        return m_pSrcMethod == nullptr ? m_pClass : m_pSrcMethod->GetSourceMethod();
    }



    template<class ApiHolder>    
    IDispenser const *BaseMethodMetadataPimpl<ApiHolder>::GetDispenser() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //return m_pDisp;
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodMetadataPimpl<ApiHolder>::ResolveMethod(IMethod const *pMethod) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseMethodMetadataPimpl<ApiHolder>::ResolveType(IType const *pType) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethodBody const *BaseMethodMetadataPimpl<ApiHolder>::ResolveMethodBody(IMethodBody const *pBody) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IParameter const *BaseMethodMetadataPimpl<ApiHolder>::ResolveParameter(IParameter const *pParam) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IParameter const *BaseMethodMetadataPimpl<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        return m_pAsm->GetParameter(position, pParamType, static_cast<IMethod const *>(m_pClass));
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::OutDebugInfo(ULONG indent) const
    {
#ifdef OUTPUT_DEBUG
        D_WCOUTI(indent, L"");
        D_WCOUTI(indent, L"MethodMetadata -----------------------------------------------------");
        D_WCOUTI1(indent, L"m_pClass: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pClass));
        D_WCOUTI1(indent, L"m_pAsm: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pAsm));
        D_WCOUTI1(indent, L"m_member: %|1$d|", m_member.which());
        D_WCOUTI1(indent, L"m_mdt: 0x%|1$08X|", m_mdt);
        D_WCOUTI1(indent, L"m_mdtOwner: 0x%|1$08X|", m_mdtOwner);
        D_WCOUTI1(indent, L"m_name: %|1$s|", m_name);
        D_WCOUTI1(indent, L"m_callingConvention: %|1$d|", m_callingConvention.Value());
        D_WCOUTI1(indent, L"m_pRetType: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pRetType));
        if (m_pRetType)
            m_pRetType->OutDebugInfo(indent + 4);
        D_WCOUTI1(indent, L"m_paramsInit: %|1$d|", m_paramsInit);
        D_WCOUTI1(indent, L"m_params.size(): %|1$d|", m_params.size());
        for (auto i = m_params.begin(), i_end = m_params.end(); i != i_end; ++i)
            (*i)->OutDebugInfo(indent + 4);
        D_WCOUTI1(indent, L"m_genericArgsInit: %|1$d|", m_genericArgsInit);
        D_WCOUTI1(indent, L"m_genericArgs.size(): %|1$d|", m_genericArgs.size());
        for (auto i = m_genericArgs.begin(), i_end = m_genericArgs.end(); i != i_end; ++i)
            (*i)->OutDebugInfo(indent + 4);
        auto const &blob = m_sig.GetBlob();
        std::wcout << std::wstring(indent, L' ') << L"m_sig:";
        for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
            std::wcout << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
        std::wcout << std::endl;
        D_WCOUTI1(indent, L"m_pILBody: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pILBody));
        D_WCOUTI1(indent, L"m_pBody: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pBody));
        D_WCOUTI1(indent, L"m_pSrcMethod: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pSrcMethod));
        if (m_pSrcMethod && m_pSrcMethod != m_pClass)
            m_pSrcMethod->OutDebugInfo(indent + 4);
        D_WCOUTI1(indent, L"m_attr: %|1$d|", m_attr.Value());
        D_WCOUTI1(indent, L"m_codeRva: %|1$d|", m_codeRva);
        D_WCOUTI1(indent, L"m_implFlags: %|1$d|", m_implFlags.Value());
        D_WCOUTI(indent, L"------------------------------------------------------------------");
        D_WCOUTI(indent, L"");
#endif
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetILMethodBody(COR_ILMETHOD *pILBody)
    {
        _ASSERTE(!m_pILBody);
        m_pILBody = pILBody;
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetToken(mdMethodDef mdmd)
    {
        _ASSERTE(IsNilToken(m_mdt));
        m_mdt = mdmd;
    }

    
    
    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        _ASSERTE(m_callingConvention == CallingConventions::CC_UNREACHED);
        m_callingConvention = callingConvention;
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetReturnType(IType const *pRetType)
    {
        _ASSERTE(!m_pRetType);
        m_pRetType = pRetType;
        if (m_pRetType)
            m_retTypeInit = true;
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetParameters(vector<IParameter const *> const &params)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetMember(MethodProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::SetGenericArguments(vector<IType const *> const &genericArgs)
    {
        _ASSERTE(!m_genericArgsInit);
        m_genericArgs = genericArgs;
        m_genericArgsInit = true;
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, MethodAttributes &attr, Signature &sig, ULONG &codeRva, MethodImplAttributes &implFlags)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(sig.GetBlob().empty());

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto wznameLength = 0ul;
        auto dwattr = 0ul;
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto dwimplFlags = 0ul;
        auto hr = pComMetaImp->GetMethodProps(mdtTarget, &mdtOwner, wzname.c_array(), wzname.size(), &wznameLength, &dwattr, &pSig, &sigLength, &codeRva, &dwimplFlags);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        attr = MethodAttributes(dwattr);
        sig.SetBlob(pSig, sigLength);
        implFlags = MethodImplAttributes(dwimplFlags);
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodDefMember(IMethod const *pMethod, mdToken mdtOwner, MethodProvider &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        _ASSERTE(pMethod);
        
        if (!Empty(member))
            return;
        
        auto const *pAsm = pMethod->GetAssembly();
        if (IsNilToken(mdtOwner))
            member = pAsm->GetMainModule();
        else
            member = pAsm->GetType(mdtOwner);
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodRefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, Signature &sig)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(sig.GetBlob().empty());

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto wznameLength = 0ul;
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto hr = pComMetaImp->GetMemberRefProps(mdtTarget, &mdtOwner, wzname.c_array(), wzname.size(), &wznameLength, &pSig, &sigLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodRefMember(IMethod const *pMethod, mdToken mdtOwner, MethodProvider &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        _ASSERTE(pMethod);
        
        if (!Empty(member))
            return;
        
        auto const *pAsm = pMethod->GetAssembly();
        if (IsNilToken(mdtOwner))
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        else
            member = pAsm->GetType(mdtOwner);
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodSigProperties(IMethod const *pMethod, Signature const &sig, CallingConventions &callingConvention, bool &retTypeInit, IType const *&pRetType, bool &paramsInit, vector<IParameter const *> &params)
    {
        _ASSERTE(pMethod);
        _ASSERTE(!sig.GetBlob().empty());
        
        auto const &blob = sig.GetBlob();
        auto _callingConvention = CallingConventions(blob[0]);
        auto const *_pRetType = static_cast<IType *>(nullptr);
        auto _params = vector<IParameter const *>();
        if (_callingConvention & CallingConventions::CC_GENERIC)
        {
            auto genericArgs = vector<IType const *>(); // temporary variable, because the signature has only the number of generic arguments.
            sig.Decode(pMethod, _callingConvention, genericArgs, _pRetType, _params);
        }
        else
        {
            sig.Decode(pMethod, _callingConvention, _pRetType, _params);
        }
        
        if (callingConvention == CallingConventions::CC_UNREACHED)
            callingConvention = _callingConvention;

        if (!retTypeInit)
        {
            pRetType = _pRetType;
            retTypeInit = true;
        }
        
        if (!paramsInit)
        {
            params = _params;
            paramsInit = true;
        }
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODMETADATAPIMPL_HPP

