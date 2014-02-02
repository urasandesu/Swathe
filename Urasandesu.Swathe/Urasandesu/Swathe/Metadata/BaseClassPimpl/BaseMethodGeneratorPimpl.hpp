/* 
 * File: BaseMethodGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMethodGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATARESOLVER_H
#include <Urasandesu/Swathe/Metadata/MetadataResolver.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseMethodGeneratorPimpl<ApiHolder>::BaseMethodGeneratorPimpl(method_generator_label_type *pClass) : 
        m_pClass(pClass),
        m_pAsmGen(nullptr), 
        m_mdt(mdTokenNil), 
        m_callingConvention(CallingConventions::CC_UNREACHED), 
        m_pRetType(nullptr), 
        m_retTypeInit(false), 
        m_paramsInit(false), 
        m_genericArgsInit(false), 
        m_attr(MethodAttributes::MA_UNREACHED), 
        m_pBody(nullptr), 
        m_pBodyGen(nullptr), 
        m_pSrcMethod(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_METHOD_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdToken BaseMethodGeneratorPimpl<ApiHolder>::GetToken() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            if (!m_pSrcMethod)
            {
                auto isGenericMethodInstance = IsGenericMethod() && !IsGenericMethodDefinition();
                if (isGenericMethodInstance)
                {
                    // TODO: Generic な Method の Instance の場合、DefineMethodSpec での生成が必要になる！
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    auto mdtTarget = GetDeclaringType()->GetToken();
                    auto const &name = m_pClass->GetName();
                    auto attr = m_pClass->GetAttribute();
                    auto const &sig = m_pClass->GetSignature();
                    auto const &blob = sig.GetBlob();
                    D_WCOUT1(L"Getting Method Generator Token... 2: %|1$s|", name);
                    auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                    auto hr = comMetaEmt.DefineMethod(mdtTarget, name.c_str(), attr.Value(), &blob[0], blob.size(), 0, 0, &m_mdt);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
            }
            else
            {
                if (!m_pAsmGen->IsModifiable())
                {
                    auto isGenericMethodInstance = IsGenericMethod() && !IsGenericMethodDefinition();
                    if (isGenericMethodInstance)
                    {
                        D_WCOUT(L"Getting Method Generator Token... 3: Generic Method Instance");
                        auto mdtTarget = GetDeclaringMethod()->GetToken();
                        auto const &sig = m_pClass->GetSignature();
                        auto const &blob = sig.GetBlob();
                        auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                        auto hr = comMetaEmt.DefineMethodSpec(mdtTarget, &blob[0], blob.size(), &m_mdt);
                        if (FAILED(hr))
                            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                    }
                    else
                    {
                        auto mdtTarget = GetDeclaringType()->GetToken();
                        auto const &name = GetName();
                        auto const &sig = m_pClass->GetSignature();
                        auto const &blob = sig.GetBlob();
                        D_WCOUT1(L"Getting Method Generator Token... 4: %|1$s|", name);
#ifdef OUTPUT_DEBUG
                        std::wcout << L"Signature:";
                        for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
                            std::wcout << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
                        std::wcout << std::endl;
#endif
                        auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                        auto hr = comMetaEmt.DefineMemberRef(mdtTarget, name.c_str(), &blob[0], blob.size(), &m_mdt);
                        if (FAILED(hr))
                            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                    }
                }
                else
                {
                    m_mdt = m_pSrcMethod->GetToken();
                }
            }
            D_WCOUT1(L"Token: 0x%|1$08X|", m_mdt);
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseMethodGeneratorPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            if (m_pSrcMethod == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_name = m_pSrcMethod->GetName();
            }
        }
        return m_name;
    }



    template<class ApiHolder>    
    CallingConventions BaseMethodGeneratorPimpl<ApiHolder>::GetCallingConvention() const
    {
        if (m_callingConvention == CallingConventions::CC_UNREACHED)
        {
            if (m_pSrcMethod == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                auto isGenericMethodInstance = IsGenericMethod() && !IsGenericMethodDefinition();
                if (isGenericMethodInstance)
                    m_callingConvention = CallingConventions::CC_GENERIC_INST;
                else
                    m_callingConvention = m_pSrcMethod->GetCallingConvention();
            }
        }
        return m_callingConvention;
    }



    template<class ApiHolder>    
    MethodAttributes BaseMethodGeneratorPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == MethodAttributes::MA_UNREACHED)
        {
            if (m_pSrcMethod == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_attr = m_pSrcMethod->GetAttribute();
            }
        }
        return m_attr;
    }



    template<class ApiHolder>    
    IType const *BaseMethodGeneratorPimpl<ApiHolder>::GetReturnType() const
    {
        if (!m_retTypeInit)
        {
            if (m_pRetType == nullptr)
            {
                if (m_pSrcMethod == nullptr)
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
                else
                {
                    m_pRetType = MetadataResolver::Resolve(m_pSrcMethod->GetReturnType());
                }
            }
            else
            {
                m_pRetType = MetadataResolver::Resolve(m_pRetType);
            }
            m_retTypeInit = true;
        }
        return m_pRetType;
    }



    template<class ApiHolder>    
    vector<IParameter const *> const &BaseMethodGeneratorPimpl<ApiHolder>::GetParameters() const
    {
        if (!m_paramsInit)
        {
            if (!m_pSrcMethod)
            {
                // nop
            }
            else
            {
                auto const &params = m_pSrcMethod->GetParameters();
                for (auto i = params.begin(), i_end = params.end(); i != i_end; ++i)
                    m_params.push_back(m_pClass->ResolveParameter(*i));
            }

            m_paramsInit = true;
        }
        return m_params;
    }



    template<class ApiHolder>    
    IMethodBody const *BaseMethodGeneratorPimpl<ApiHolder>::GetMethodBody() const
    {
        if (!m_pBody)
        {
            if (!m_pSrcMethod)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_pBody = MetadataResolver::Resolve(m_pSrcMethod->GetMethodBody());
            }
        }
        return m_pBody;
    }



    template<class ApiHolder>    
    ULONG BaseMethodGeneratorPimpl<ApiHolder>::GetCodeRVA() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    bool BaseMethodGeneratorPimpl<ApiHolder>::IsStatic() const
    {
        if (!m_pSrcMethod)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pSrcMethod->IsStatic();
        }
    }



    template<class ApiHolder>    
    bool BaseMethodGeneratorPimpl<ApiHolder>::IsGenericMethod() const
    {
        return !GetGenericArguments().empty();
    }



    template<class ApiHolder>    
    bool BaseMethodGeneratorPimpl<ApiHolder>::IsGenericMethodDefinition() const
    {
        if (!m_pSrcMethod)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pSrcMethod->IsGenericMethodDefinition();
        }
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseMethodGeneratorPimpl<ApiHolder>::GetGenericArguments() const
    {
        if (!m_genericArgsInit)
        {
            if (!m_pSrcMethod)
            {
                if (m_genericArgs.empty())
                {
                    // nop
                }
                else
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
            }
            else
            {
                auto const &genericArgs = m_pSrcMethod->GetGenericArguments();
                for (auto i = genericArgs.begin(), i_end = genericArgs.end(); i != i_end; ++i)
                    m_genericArgs.push_back(MetadataResolver::Resolve(*i));
            }
            m_genericArgsInit = true;
        }
        return m_genericArgs;
    }



    template<class ApiHolder>    
    Signature const &BaseMethodGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        //{
        //    auto isGenericMethodInstance = IsGenericMethod() && !IsGenericMethodDefinition();
        //    if (isGenericMethodInstance)
        //        m_sig.Encode(m_pClass, m_pClass->GetCallingConvention(), m_pClass->GetGenericArguments());
        //    else
        //        m_sig.Encode(m_pClass, m_pClass->GetCallingConvention(), m_pClass->GetReturnType(), m_pClass->GetParameters());
        //}
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodGeneratorPimpl<ApiHolder>::MakeGenericMethod(vector<IType const *> const &genericArgs) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IAssembly const *BaseMethodGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    IType const *BaseMethodGeneratorPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (Empty(m_member))
        {
            _ASSERTE(m_pSrcMethod);
            auto const *pDeclaringType = m_pSrcMethod->GetDeclaringType();
            if (pDeclaringType)
                m_member = MetadataResolver::Resolve(pDeclaringType);
        }

        auto const *const *ppDeclaringType = get<IType const *>(&m_member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodGeneratorPimpl<ApiHolder>::GetDeclaringMethod() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (Empty(m_member))
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

        auto const *const *ppDeclaringMethod = get<IMethod const *>(&m_member);
        return !ppDeclaringMethod ? nullptr : *ppDeclaringMethod;

        //if (!m_declaringMethodInit)   // TODO: m_member へ統合。
        //{
        //    if (!m_pSrcMethod)
        //    {
        //        // nop
        //    }
        //    else
        //    {
        //        auto const *pDeclaringMethod = m_pSrcMethod->GetDeclaringMethod();
        //        if (pDeclaringMethod)
        //            m_pDeclaringMethod = MetadataResolver::Resolve(pDeclaringMethod);
        //    }
        //    m_declaringMethodInit = true;
        //}
        //return m_pDeclaringMethod;
    }



    template<class ApiHolder>    
    MethodProvider const &BaseMethodGeneratorPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodGeneratorPimpl<ApiHolder>::GetSourceMethod() const
    {
        return m_pSrcMethod == nullptr ? m_pClass : m_pSrcMethod->GetSourceMethod();
    }



    template<class ApiHolder>    
    IDispenser const *BaseMethodGeneratorPimpl<ApiHolder>::GetDispenser() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //return m_pDisp;
        // TODO: この I/F は削除。
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodGeneratorPimpl<ApiHolder>::ResolveMethod(IMethod const *pMethod) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<pair<method_generator_label_type const *, SIZE_T> > MethodGenToIndex;
        typedef MethodGenToIndex::value_type Value;
        
        _ASSERTE(m_pClass->GetSourceMethod() == pMethod->GetDeclaringMethod()->GetSourceMethod());

        auto const &methodGenToIndex = m_pAsmGen->GetMethodGeneratorToIndex();
        auto isMine = [&](Value const &v) { return v.first->GetDeclaringMethod() == m_pClass; };
        auto myMethodGenToIndex = methodGenToIndex | filtered(isMine);
        auto isAlreadyExist = [&](Value const &v) { return v.first->GetSourceMethod() == pMethod->GetSourceMethod(); };
        auto result = FindIf(myMethodGenToIndex, isAlreadyExist);
        if (result)
            return (*result).first;
        
        return m_pAsmGen->DefineMethod(pMethod, static_cast<IMethod const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseMethodGeneratorPimpl<ApiHolder>::ResolveType(IType const *pType) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<pair<type_generator_label_type const *, SIZE_T> > TypeGenToIndex;
        typedef TypeGenToIndex::value_type Value;
        
        _ASSERTE(m_pClass->GetSourceMethod() == pType->GetDeclaringMethod()->GetSourceMethod());

        auto const &typeGenToIndex = m_pAsmGen->GetTypeGeneratorToIndex();
        auto isMine = [&](Value const &v) { return v.first->GetDeclaringMethod() == m_pClass; };
        auto myTypeGenToIndex = typeGenToIndex | filtered(isMine);
        auto isAlreadyExist = [&](Value const &v) { return v.first->GetSourceType() == pType->GetSourceType(); };
        auto result = FindIf(myTypeGenToIndex, isAlreadyExist);
        if (result)
            return (*result).first;

        return m_pAsmGen->DefineType(pType, static_cast<IMethod const *>(m_pClass));
    }



    template<class ApiHolder>    
    IMethodBody const *BaseMethodGeneratorPimpl<ApiHolder>::ResolveMethodBody(IMethodBody const *pBody) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<pair<method_body_generator_label_type const *, SIZE_T> > MethodBodyGenToIndex;
        typedef MethodBodyGenToIndex::value_type Value;

        auto const &bodyGenToIndex = m_pAsmGen->GetMethodBodyGeneratorToIndex();
        auto isMine = [&](Value const &v) { return v.first->GetMethod() == m_pClass; };
        auto myBodyGenToIndex = bodyGenToIndex | filtered(isMine);
        auto isAlreadyExist = [&](Value const &v) { return v.first->GetSourceMethodBody() == pBody->GetSourceMethodBody(); };
        auto result = FindIf(myBodyGenToIndex, isAlreadyExist);
        if (result)
            return (*result).first;

        return m_pAsmGen->DefineMethodBody(pBody, m_pClass);
    }



    template<class ApiHolder>    
    IParameter const *BaseMethodGeneratorPimpl<ApiHolder>::ResolveParameter(IParameter const *pParam) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<pair<parameter_generator_label_type const *, SIZE_T> > ParamGenToIndex;
        typedef ParamGenToIndex::value_type Value;

        auto const &paramGenToIndex = m_pAsmGen->GetParameterGeneratorToIndex();
        auto isMine = [&](Value const &v) { return v.first->GetMethod() == m_pClass; };
        auto myParamGenToIndex = paramGenToIndex | filtered(isMine);
        auto isAlreadyExist = [&](Value const &v) { return v.first->GetSourceParameter() == pParam->GetSourceParameter(); };
        auto result = FindIf(myParamGenToIndex, isAlreadyExist);
        if (result)
            return (*result).first;

        return m_pAsmGen->DefineParameter(pParam, static_cast<IMethod const *>(m_pClass));
    }



    template<class ApiHolder>    
    IParameter const *BaseMethodGeneratorPimpl<ApiHolder>::GetParameter(ULONG position, IType const *pParamType) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        if (m_pSrcMethod == nullptr)
        {
            typedef vector<pair<parameter_generator_label_type const *, SIZE_T> > ParamGenToIndex;
            typedef ParamGenToIndex::value_type Value;

            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            //auto const &paramGenToIndex = m_pDisp->GetParameterGeneratorToIndex();
            //auto const &paramGenToIndex = m_pDisp->GetParameterGeneratorToIndex();    // TODO: こんな I/F が欲しい。
            //auto isMine = [&](Value const &v) { return GetMethod(v.first->GetMember()) == m_pClass; };
            //auto myParamGenToIndex = paramGenToIndex | filtered(isMine);
            //auto isAlreadyExist = [&](Value const &v) { return v.first->GetPosition() == position &&
            //                                                   v.first->GetParameterType()->GetSourceType() == pParamType->GetSourceType(); };
            //auto result = FindIf(myParamGenToIndex, isAlreadyExist);
            //if (result)
            //    return (*result).first;

            //return m_pDisp->DefineParameter(m_pClass, m_pAsmGen, position, pParamType);
        }
        else
        {
            return MetadataResolver::Resolve(m_pSrcMethod->GetParameter(position, pParamType));
        }
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::OutDebugInfo(ULONG indent) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    typename BaseMethodGeneratorPimpl<ApiHolder>::method_body_generator_label_type *BaseMethodGeneratorPimpl<ApiHolder>::DefineMethodBody()
    {
        if (!m_pBodyGen)
            m_pBodyGen = m_pAsmGen->DefineMethodBody(nullptr, m_pClass);
        return m_pBodyGen;
    }



    template<class ApiHolder>    
    typename BaseMethodGeneratorPimpl<ApiHolder>::parameter_generator_label_type *BaseMethodGeneratorPimpl<ApiHolder>::DefineParameter(ULONG position, IType const *pParamType)
    {
        m_paramsInit = false;
        auto *pParamGen = m_pAsmGen->DefineParameter(position, pParamType, static_cast<IMethod const *>(m_pClass));
        if (m_params.size() <= position)
            m_params.resize(position + 1);
        m_params.at(position) = pParamGen;
        return pParamGen;
    }

    
    
    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetToken(mdToken mdt)
    {
        _ASSERTE(IsNilToken(m_mdt));
        m_mdt = mdt;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetCallingConvention(CallingConventions const &callingConvention)
    {
        _ASSERTE(callingConvention != CallingConventions::CC_UNREACHED);
        _ASSERTE(m_callingConvention == CallingConventions::CC_UNREACHED);
        m_callingConvention = callingConvention;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetReturnType(IType const *pRetType)
    {
        _ASSERTE(pRetType != nullptr);
        _ASSERTE(m_pRetType == nullptr);
        m_pRetType = pRetType;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetParameters(vector<IParameter const *> const &params)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetAttributes(MethodAttributes const &attr)
    {
        _ASSERTE(attr != MethodAttributes::MA_UNREACHED);
        _ASSERTE(m_attr == MethodAttributes::MA_UNREACHED);
        m_attr = attr;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetMember(MethodProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetSourceMethod(IMethod const *pSrcMethod)
    {
        _ASSERTE(m_pSrcMethod == nullptr);
        m_pSrcMethod = pSrcMethod;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);

        // TODO: Method 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i).first->Accept(pVisitor);

        m_pClass->GetReturnType();   // resolves the return Type of this Method.

        m_pClass->GetParameters();   // resolves the Parameters of this Method.
        auto const &paramGenToIndex = m_pAsmGen->GetParameterGeneratorToIndex();
        for (auto i = 0ul; i < paramGenToIndex.size(); ++i)
            if (paramGenToIndex[i].first->GetMethod() == m_pClass)
                paramGenToIndex[i].first->Accept(pVisitor);

        auto const &methodBodyGenToIndex = m_pAsmGen->GetMethodBodyGeneratorToIndex();
        for (auto i = 0ul; i < methodBodyGenToIndex.size(); ++i)
            if (methodBodyGenToIndex[i].first->GetMethod() == m_pClass)
                methodBodyGenToIndex[i].first->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_HPP

