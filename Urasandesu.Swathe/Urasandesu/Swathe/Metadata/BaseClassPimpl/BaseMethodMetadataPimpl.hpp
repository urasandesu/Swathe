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
        m_srcMethodInit(false), 
        m_pSrcMethod(nullptr), 
        m_attr(MethodAttributes::MA_UNREACHED), 
        m_codeRva(-1)
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
                auto hr = comMetaImp.FindMethod(GetDeclaringType()->GetToken(), m_name.c_str(), &blob[0], static_cast<ULONG>(blob.size()), &m_mdt);
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
                m_pAsm->FillMethodDefProperties(mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
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
                    m_pAsm->FillMethodDefProperties(mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
                FillMethodSigProperties(m_pClass, m_sig, m_callingConvention, m_retTypeInit, m_pRetType, m_paramsInit, m_params);
            }
            else if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                if (m_sig.GetBlob().empty())
                    m_pAsm->FillMemberRefProperties(mdtTarget, m_mdtOwner, m_name, m_sig);
                FillMethodSigProperties(m_pClass, m_sig, m_callingConvention, m_retTypeInit, m_pRetType, m_paramsInit, m_params);
            }
            else if (TypeFromToken(mdtTarget) == mdtMethodSpec)
            {
                m_callingConvention = GetDeclaringMethod()->GetCallingConvention() | CallingConventions::CC_GENERIC_INST;
            }
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
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
                    m_pAsm->FillMethodDefProperties(mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
            
                FillMethodSigProperties(m_pClass, m_sig, m_callingConvention, m_retTypeInit, m_pRetType, m_paramsInit, m_params);
            }
            else if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                if (m_sig.GetBlob().empty())
                    m_pAsm->FillMemberRefProperties(mdtTarget, m_mdtOwner, m_name, m_sig);
            
                FillMethodSigProperties(m_pClass, m_sig, m_callingConvention, m_retTypeInit, m_pRetType, m_paramsInit, m_params);
            }
            else if (TypeFromToken(mdtTarget) == mdtMethodSpec)
            {
                auto const *pDeclaringMethod = GetDeclaringMethod();
                auto const &params = pDeclaringMethod->GetParameters();
                m_params.reserve(params.size());
                BOOST_FOREACH (auto const &pParam, params)
                    m_params.push_back(GetParameter(pParam->GetPosition(), pParam->GetParameterType()));
            }
            else
            {
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
            }
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
        if (m_codeRva == -1)
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
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtMethodDef)
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
                    hr = comMetaImp.EnumGenericParams(&hEnum, mdtTarget, mdgps.c_array(), static_cast<ULONG>(mdgps.size()), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_genericArgs.reserve(m_genericArgs.size() + count);
                    for (auto i = 0u; i < count; ++i)
                    {
                        auto pGenericArg = m_pAsm->GetType(mdgps[i], TypeKinds::TK_MVAR, static_cast<ULONG>(m_genericArgs.size()), false, MetadataSpecialValues::EMPTY_TYPES, static_cast<IMethod const *>(m_pClass));
                        m_genericArgs.push_back(pGenericArg);
                    }
                } while (0 < count);
            }
            else if (TypeFromToken(mdtTarget) == mdtMethodSpec)
            {
                GetDeclaringMethod();
                FillMethodSpecProperties(m_pClass, m_sig, m_callingConvention, m_genericArgsInit, m_genericArgs);
            }
            else if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                m_genericArgs = GetSourceMethod()->GetGenericArguments();
            }
            else
            {
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
            }

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

        auto const &member = GetMember();
        auto const *const *ppDeclaringType = get<IType const *>(&member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodMetadataPimpl<ApiHolder>::GetDeclaringMethod() const
    {
        using boost::get;

        auto const &member = GetMember();
        auto const *const *ppDeclaringMethod = get<IMethod const *>(&member);
        return !ppDeclaringMethod ? nullptr : *ppDeclaringMethod;
    }



    template<class ApiHolder>    
    MethodProvider const &BaseMethodMetadataPimpl<ApiHolder>::GetMember() const
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!Empty(m_member))
            return m_member;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtMethodDef:
                if (m_sig.GetBlob().empty())
                    m_pAsm->FillMethodDefProperties(mdtTarget, m_mdtOwner, m_name, m_attr, m_sig, m_codeRva, m_implFlags);
                FillMethodMember(m_pClass, m_mdtOwner, m_member);
                break;
                
            case mdtMemberRef:
                if (m_sig.GetBlob().empty())
                    m_pAsm->FillMemberRefProperties(mdtTarget, m_mdtOwner, m_name, m_sig);
                FillMethodMember(m_pClass, m_mdtOwner, m_member);
                break;
                
            case mdtMethodSpec:
                if (m_sig.GetBlob().empty())
                    m_pAsm->FillMethodSpecProperties(mdtTarget, m_mdtOwner, m_sig);
                FillMethodMember(m_pClass, m_mdtOwner, m_member);
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(!Empty(m_member));
        return m_member;
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodMetadataPimpl<ApiHolder>::GetSourceMethod() const
    {
        if (!m_srcMethodInit)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtMemberRef)
            {
                if (m_sig.GetBlob().empty())
                    m_pAsm->FillMemberRefProperties(mdtTarget, m_mdtOwner, m_name, m_sig);
                FillMethodSigProperties(m_pClass, m_sig, m_callingConvention, m_retTypeInit, m_pRetType, m_paramsInit, m_params);
                FillMethodRefSourceMethod(m_pClass, m_mdtOwner, m_name, m_callingConvention, m_pRetType, m_params, m_srcMethodInit, m_pSrcMethod);
            }
            else
            {
                if (TypeFromToken(mdtTarget) == mdtMethodDef)
                    m_pSrcMethod = m_pClass;
                else if (TypeFromToken(mdtTarget) == mdtMethodSpec)
                    m_pSrcMethod = GetDeclaringMethod()->GetSourceMethod();
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                m_srcMethodInit = true;
            }
        }
        _ASSERTE(m_pSrcMethod);
        return m_pSrcMethod;
    }



    template<class ApiHolder>    
    bool BaseMethodMetadataPimpl<ApiHolder>::Equals(IMethod const *pMethod) const
    {
        using Urasandesu::CppAnonym::Collections::SequenceEqual;

        if (m_pClass == pMethod)
            return true;

        if (!pMethod)
            return false;

        auto const *pOtherMethod = dynamic_cast<class_type const *>(pMethod);
        if (!pOtherMethod)
            return m_pClass == pMethod->GetSourceMethod();

        auto isThisDefinition = !IsGenericMethod() || IsGenericMethodDefinition();
        auto isOtherDefinition = !pMethod->IsGenericMethod() || pMethod->IsGenericMethodDefinition();
        if (isThisDefinition != isOtherDefinition)
            return false;
        
        if (isThisDefinition && isOtherDefinition)
            return GetToken() == pOtherMethod->GetToken() &&
                   GetDeclaringType() == pOtherMethod->GetDeclaringType() &&  // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
                   GetAssembly() == pOtherMethod->GetAssembly();
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtMethodDef:
            case mdtMemberRef:
                return GetToken() == pOtherMethod->GetToken() &&
                       GetDeclaringType() == pOtherMethod->GetDeclaringType() &&  // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
                       GetAssembly() == pOtherMethod->GetAssembly() &&
                       SequenceEqual(GetGenericArguments(), pOtherMethod->GetGenericArguments());
                
            case mdtMethodSpec:
                return GetToken() == pOtherMethod->GetToken() &&
                       GetAssembly() == pOtherMethod->GetAssembly();

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
    }



    template<class ApiHolder>    
    size_t BaseMethodMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Collections::SequenceHashValue;
        using Urasandesu::CppAnonym::Utilities::HashValue;

        auto isDefinition = !IsGenericMethod() || IsGenericMethodDefinition();
        auto mdtTarget = GetToken();
        auto declaringTypeHash = HashValue(GetDeclaringType());    // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
        auto asmHash = HashValue(GetAssembly());

        return isDefinition ? 
                    (mdtTarget ^ declaringTypeHash ^ asmHash) : 
                    (mdtTarget ^ declaringTypeHash ^ asmHash ^ SequenceHashValue(GetGenericArguments()));
    }



    template<class ApiHolder>    
    IParameter const *BaseMethodMetadataPimpl<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        return m_pAsm->GetParameter(position, pParamType, static_cast<IMethod const *>(m_pClass));
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::OutDebugInfo() const
    {
        CPPANONYM_LOG_FUNCTION();

        CPPANONYM_D_LOGW(L"");
        CPPANONYM_D_LOGW(L"MethodMetadata -----------------------------------------------------");
        CPPANONYM_D_LOGW1(L"m_pClass: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pClass));
        CPPANONYM_D_LOGW1(L"m_pAsm: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pAsm));
        CPPANONYM_D_LOGW1(L"m_member: %|1$d|", m_member.which());
        CPPANONYM_D_LOGW1(L"m_mdt: 0x%|1$08X|", m_mdt);
        CPPANONYM_D_LOGW1(L"m_mdtOwner: 0x%|1$08X|", m_mdtOwner);
        CPPANONYM_D_LOGW1(L"m_name: %|1$s|", m_name);
        CPPANONYM_D_LOGW1(L"m_callingConvention: %|1$d|", m_callingConvention.Value());
        CPPANONYM_D_LOGW1(L"m_pRetType: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pRetType));
        if (CPPANONYM_D_LOG_ENABLED())
        {
            if (m_pRetType)
                m_pRetType->OutDebugInfo();
        }
        CPPANONYM_D_LOGW1(L"m_paramsInit: %|1$d|", m_paramsInit);
        CPPANONYM_D_LOGW1(L"m_params.size(): %|1$d|", m_params.size());
        if (CPPANONYM_D_LOG_ENABLED())
        {
            for (auto i = m_params.begin(), i_end = m_params.end(); i != i_end; ++i)
                (*i)->OutDebugInfo();
        }
        CPPANONYM_D_LOGW1(L"m_genericArgsInit: %|1$d|", m_genericArgsInit);
        CPPANONYM_D_LOGW1(L"m_genericArgs.size(): %|1$d|", m_genericArgs.size());
        if (CPPANONYM_D_LOG_ENABLED())
        {
            for (auto i = m_genericArgs.begin(), i_end = m_genericArgs.end(); i != i_end; ++i)
                (*i)->OutDebugInfo();
        }
        if (CPPANONYM_D_LOG_ENABLED())
        {
            auto const &blob = m_sig.GetBlob();
            auto oss = std::wostringstream();
            oss << L"m_sig:";
            for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
                oss << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
            CPPANONYM_D_LOGW(oss.str());
        }
        CPPANONYM_D_LOGW1(L"m_pILBody: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pILBody));
        CPPANONYM_D_LOGW1(L"m_pBody: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pBody));
        CPPANONYM_D_LOGW1(L"m_pSrcMethod: 0x%|1$08X|", reinterpret_cast<DWORD>(m_pSrcMethod));
        if (CPPANONYM_D_LOG_ENABLED())
        {
            if (m_pSrcMethod && m_pSrcMethod != m_pClass)
                m_pSrcMethod->OutDebugInfo();
        }
        CPPANONYM_D_LOGW1(L"m_attr: %|1$d|", m_attr.Value());
        CPPANONYM_D_LOGW1(L"m_codeRva: %|1$d|", m_codeRva);
        CPPANONYM_D_LOGW1(L"m_implFlags: %|1$d|", m_implFlags.Value());
        CPPANONYM_D_LOGW(L"------------------------------------------------------------------");
        CPPANONYM_D_LOGW(L"");
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
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodMember(IMethod const *pMethod, mdToken mdtOwner, MethodProvider &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        _ASSERTE(pMethod);
        
        if (!Empty(member))
            return;
        
        auto const *pAsm = pMethod->GetAssembly();
        if (IsNilToken(mdtOwner))
            member = pAsm->GetMainModule();
        else if (TypeFromToken(mdtOwner) == mdtTypeDef)
            member = pAsm->GetType(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtTypeRef)
            member = pAsm->GetType(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtTypeSpec)
            member = pAsm->GetType(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtMethodDef)
            member = pAsm->GetMethod(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtMemberRef)
            member = pAsm->GetMethod(mdtOwner);
        else
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodRefSourceMethod(IMethod const *pMethod, mdToken mdtOwner, wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IParameter const *> const &params, bool &srcMethodInit, IMethod const *&pSrcMethod)
    {
        _ASSERTE(pMethod);
        _ASSERTE(!IsNilToken(mdtOwner));
        _ASSERTE(!name.empty());
        
        if (srcMethodInit)
            return;

        if (TypeFromToken(mdtOwner) == mdtTypeRef)
        {
            auto const *pAsm = pMethod->GetAssembly();
            auto const *pRefType = pAsm->GetType(mdtOwner);
            auto const *pRefSrcType = pRefType->GetSourceType();
            pSrcMethod = pRefSrcType->GetMethod(name, callingConvention, pRetType, params);
            _ASSERTE(pSrcMethod);
        }
        else if (TypeFromToken(mdtOwner) == mdtTypeSpec)
        {
            auto const *pAsm = pMethod->GetAssembly();
            auto const *pRefType = pAsm->GetType(mdtOwner);
            auto const *pRefSrcType = pRefType->GetSourceType();
            pSrcMethod = pRefSrcType->GetMethod(name, callingConvention, pRetType, params);
            _ASSERTE(pSrcMethod);
        }
        else
        {
            auto oss = std::wostringstream();
            oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtOwner;
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        srcMethodInit = true;
    }



    template<class ApiHolder>    
    void BaseMethodMetadataPimpl<ApiHolder>::FillMethodSpecProperties(IMethod const *pMethod, Signature const &sig, CallingConventions &callingConvention, bool &genericArgsInit, vector<IType const *> &genericArgs)
    {
        _ASSERTE(pMethod);
        _ASSERTE(!sig.GetBlob().empty());
        
        auto const &blob = sig.GetBlob();
        auto _callingConvention = CallingConventions(blob[0]);
        if (_callingConvention & CallingConventions::CC_GENERIC_INST)
        {
            auto _genericArgs = vector<IType const *>();
            sig.Decode(pMethod, _callingConvention, _genericArgs);
            if (!genericArgsInit)
            {
                genericArgs = _genericArgs;
                genericArgsInit = true;
            }
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

        if (callingConvention == CallingConventions::CC_UNREACHED)
            callingConvention = _callingConvention;
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

