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

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseMethodGeneratorPimpl<ApiHolder>::BaseMethodGeneratorPimpl(method_generator_label_type *pClass) : 
        m_pClass(pClass),
        m_pAsmGen(nullptr), 
        m_declaringTypeInit(false), 
        m_declaringMethodInit(false), 
        m_mdt(mdTokenNil), 
        m_callingConvention(CallingConventions::CC_UNREACHED), 
        m_pRetType(nullptr), 
        m_retTypeInit(false), 
        m_paramsInit(false), 
        m_isPropsReModified(false), 
        m_genericArgsInit(false), 
        m_attr(MethodAttributes::MA_UNREACHED), 
        m_implAttr(MethodImplAttributes::MIA_UNREACHED), 
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
        CPPANONYM_LOG_FUNCTION();

        if (IsNilToken(m_mdt))
        {
            CPPANONYM_LOG_NAMED_SCOPE("if (IsNilToken(m_mdt))");

            if (!m_pSrcMethod)
            {
                CPPANONYM_LOG_NAMED_SCOPE("if (!m_pSrcMethod)");

                auto isGenericMethodInstance = IsGenericMethod() && !IsGenericMethodDefinition();
                if (isGenericMethodInstance)
                {
                    CPPANONYM_LOG_NAMED_SCOPE("if (isGenericMethodInstance)");
                    
                    m_pAsmGen->UpdateMethodSpec(GetDeclaringMethod()->GetToken(), GetSignature(), m_mdt);
                }
                else
                {
                    CPPANONYM_LOG_NAMED_SCOPE("if (!isGenericMethodInstance)");
                    
                    auto implAttr = GetMethodImplementationFlags();
                    auto codeRva = implAttr != MethodImplAttributes::MIA_IL ? 0 : m_pAsmGen->GetValidRVA();
                    m_pAsmGen->UpdateMethodDef(GetDeclaringType()->GetToken(), GetName(), GetAttribute(), GetSignature(), codeRva, implAttr, m_mdt);
                    
                    if (IsGenericMethod())
                    {
                        CPPANONYM_LOG_NAMED_SCOPE("if (IsGenericMethod())");
                        
                        // We have to resolve the metadata token of the generic parameters beforehand because they are not accessed during the signature calculation.
                        auto const &genericArgs = GetGenericArguments();
                        BOOST_FOREACH (auto const &pGenericArg, genericArgs)
                            pGenericArg->GetToken();
                    }
                }
            }
            else
            {
                CPPANONYM_LOG_NAMED_SCOPE("if (m_pSrcMethod)");

                if (!m_pAsmGen->IsModifiable())
                {
                    CPPANONYM_LOG_NAMED_SCOPE("if (!m_pAsmGen->IsModifiable())");

                    auto isGenericMethodInstance = IsGenericMethod() && !IsGenericMethodDefinition();
                    if (isGenericMethodInstance)
                    {
                        CPPANONYM_LOG_NAMED_SCOPE("if (isGenericMethodInstance)");
                        
                        m_pAsmGen->UpdateMethodSpec(GetDeclaringMethod()->GetToken(), GetSignature(), m_mdt);
                    }
                    else
                    {
                        CPPANONYM_LOG_NAMED_SCOPE("if (!isGenericMethodInstance)");

                        auto const *pSrcMethod = m_pSrcMethod->GetSourceMethod();
                        auto const *pSrcAsm = pSrcMethod->GetAssembly();
                        m_pAsmGen->UpdateImportMember(pSrcAsm, pSrcMethod->GetToken(), GetDeclaringType()->GetToken(), m_mdt);
                    }
                }
                else
                {
                    CPPANONYM_LOG_NAMED_SCOPE("if (m_pAsmGen->IsModifiable())");
                    
                    auto const *pSrcMethodGen = dynamic_cast<class_type const *>(m_pSrcMethod);
                    if (!pSrcMethodGen)
                    {
                        CPPANONYM_LOG_NAMED_SCOPE("if (!pSrcMethodGen)");

                        m_mdt = m_pSrcMethod->GetToken();
                        CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mdt);
                    }
                    else
                    {
                        CPPANONYM_LOG_NAMED_SCOPE("if (pSrcMethodGen)");

                        auto const *pDeclaringType = GetDeclaringType();
                        auto isDeclaringGenericInstanceType = pDeclaringType->IsGenericType() && !pDeclaringType->IsGenericTypeDefinition();
                        if (isDeclaringGenericInstanceType)
                        {
                            CPPANONYM_LOG_NAMED_SCOPE("if (isDeclaringGenericInstanceType)");

                            m_pSrcMethod->GetToken();   // We have to resolve the metadata token of the source method beforehand because the MemberRef token is resolved by its name.
                            m_pAsmGen->UpdateMemberRef(GetDeclaringType()->GetToken(), GetName(), GetSignature(), m_mdt);
                        }
                        else
                        {
                            CPPANONYM_LOG_NAMED_SCOPE("if (!isDeclaringGenericInstanceType)");

                            m_mdt = m_pSrcMethod->GetToken();
                            CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mdt);
                        }
                    }
                }
            }
            m_isPropsReModified = false;
        }
        if (m_isPropsReModified)
        {
            if (m_pSrcMethod && TypeFromToken(m_mdt) == mdtMethodDef)
            {
                auto implAttr = GetMethodImplementationFlags();
                auto codeRva = implAttr != MethodImplAttributes::MIA_IL ? 0 : m_pAsmGen->GetValidRVA();
                m_pAsmGen->UpdateMethodDefProperties(m_mdt, GetAttribute(), codeRva, implAttr);
                m_pSrcMethod->ResetProperties();
            }
            m_isPropsReModified = false;
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
    MethodImplAttributes BaseMethodGeneratorPimpl<ApiHolder>::GetMethodImplementationFlags() const
    {
        if (m_implAttr == MethodImplAttributes::MIA_UNREACHED)
        {
            if (!m_pSrcMethod)
            {
                m_implAttr = MethodImplAttributes::MIA_IL;
            }
            else
            {
                m_implAttr = m_pSrcMethod->GetMethodImplementationFlags();
            }
        }
        return m_implAttr;
    }



    template<class ApiHolder>    
    IType const *BaseMethodGeneratorPimpl<ApiHolder>::GetReturnType() const
    {
        if (!m_retTypeInit)
        {
            if (!m_pRetType)
            {
                if (!m_pSrcMethod)
                {
                    auto const *pDeclaringMethod = GetDeclaringMethod();
                    if (!pDeclaringMethod)
                    {
                        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                    }
                    else
                    {
                        m_pRetType = m_pAsmGen->Resolve(pDeclaringMethod->GetReturnType());
                    }
                }
                else
                {
                    m_pRetType = m_pAsmGen->Resolve(m_pSrcMethod->GetReturnType());
                }
            }
            else
            {
                m_pRetType = m_pAsmGen->Resolve(m_pRetType);
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
                    m_params.push_back(m_pAsmGen->Resolve(*i));
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
                m_pBody = m_pAsmGen->Resolve(m_pSrcMethod->GetMethodBody());
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
            return !(GetCallingConvention() & CallingConventions::CC_HAS_THIS);
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
            return IsGenericMethod() && !(m_callingConvention & CallingConventions::CC_GENERIC_INST);
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
                    m_genericArgs.push_back(m_pAsmGen->Resolve(*i));
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
        if (!m_pSrcMethod)
        {
            return m_pAsmGen->DefineMethod(mdTokenNil, CallingConventions::CC_GENERIC_INST, true, genericArgs, nullptr, nullptr, static_cast<IMethod const *>(m_pClass));
        }
        else
        {
            auto const *pSrcMethodGen = dynamic_cast<class_type const *>(m_pSrcMethod);
            if (!pSrcMethodGen)
            {
                return m_pAsmGen->Resolve(m_pSrcMethod->MakeGenericMethod(genericArgs));
            }
            else
            {
                return m_pAsmGen->DefineMethod(mdTokenNil, CallingConventions::CC_GENERIC_INST, true, genericArgs, nullptr, nullptr, static_cast<IMethod const *>(m_pClass));
            }
        }
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

        if (!m_declaringTypeInit)
        {
            if (Empty(m_member))
            {
                _ASSERTE(m_pSrcMethod);
                auto const *pDeclaringType = m_pSrcMethod->GetDeclaringType();
                if (pDeclaringType)
                    m_member = m_pAsmGen->Resolve(pDeclaringType);
            }

            m_declaringTypeInit = true;
        }

        auto const *const *ppDeclaringType = get<IType const *>(&m_member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    typename BaseMethodGeneratorPimpl<ApiHolder>::type_generator_label_type *BaseMethodGeneratorPimpl<ApiHolder>::GetDeclaringTypeGenerator()
    {
        using boost::polymorphic_cast;
        return polymorphic_cast<type_generator_label_type *>(const_cast<IType *>(const_cast<class_pimpl_type *>(this)->GetDeclaringType()));
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodGeneratorPimpl<ApiHolder>::GetDeclaringMethod() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!m_declaringMethodInit)
        {
            if (Empty(m_member))
            {
                _ASSERTE(m_pSrcMethod);
                auto const *pDeclaringMethod = m_pSrcMethod->GetDeclaringMethod();
                if (pDeclaringMethod)
                    m_member = m_pAsmGen->Resolve(pDeclaringMethod);
            }

            m_declaringMethodInit = true;
        }

        auto const *const *ppDeclaringMethod = get<IMethod const *>(&m_member);
        return !ppDeclaringMethod ? nullptr : *ppDeclaringMethod;
    }



    template<class ApiHolder>    
    MethodProvider const &BaseMethodGeneratorPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseMethodGeneratorPimpl<ApiHolder>::GetSourceMethod() const
    {
        return !m_pSrcMethod ? m_pClass : m_pSrcMethod;
    }



    template<class ApiHolder>    
    bool BaseMethodGeneratorPimpl<ApiHolder>::Equals(IMethod const *pMethod) const
    {
        if (m_pClass == pMethod)
            return true;

        if (!pMethod)
            return false;

        auto const *pOtherMethodGen = dynamic_cast<class_type const *>(pMethod);
        if (!pOtherMethodGen)
        {
            auto const *pSrcMethodGen = dynamic_cast<class_type const *>(m_pSrcMethod);
            if (pSrcMethodGen)
                return false;
            
            return pMethod->Equals(m_pSrcMethod);
        }
        
        auto const *pSrcMethod = GetSourceMethod();
        auto const *pOtherSrcMethod = pOtherMethodGen->GetSourceMethod();
        if (pSrcMethod != pOtherSrcMethod)
            return false;
        
        if (m_pClass == pSrcMethod)
            return pOtherMethodGen == pOtherSrcMethod;
        
        return true;
    }



    template<class ApiHolder>    
    size_t BaseMethodGeneratorPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Utilities::HashValue;
        return !m_pSrcMethod ? HashValue(m_pClass) : m_pSrcMethod->GetHashCode();
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
            return m_pAsmGen->Resolve(m_pSrcMethod->GetParameter(position, pParamType));
        }
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::ResetProperties() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::OutDebugInfo() const
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
        _ASSERTE(0ul < position);
        m_paramsInit = false;
        auto *pParamGen = m_pAsmGen->DefineParameter(position, pParamType, static_cast<IMethod const *>(m_pClass));
        if (m_params.size() < position)
            m_params.resize(position);
        m_params.at(position - 1ul) = pParamGen;
        return pParamGen;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::DefineGenericParameters(vector<wstring> const &names)
    {
        auto genericArgGens = vector<type_generator_label_type *>();
        genericArgGens.reserve(names.size());
        DefineGenericParameters(names, genericArgGens);
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::DefineGenericParameters(vector<wstring> const &names, vector<type_generator_label_type *> &genericArgGens)
    {
        _ASSERTE(!m_genericArgsInit);

        for (auto i = 0u; i < names.size(); ++i)
        {
            auto *pGenericArgGen = m_pAsmGen->DefineType(names[i], TypeAttributes::TA_UNREACHED, nullptr, TypeKinds::TK_MVAR, GenericParamAttributes::GPA_NON_VARIANT, i, static_cast<IMethod const *>(m_pClass));
            m_genericArgs.push_back(pGenericArgGen);
            genericArgGens.push_back(pGenericArgGen);
        }
        m_genericArgsInit = true;
        
        _ASSERTE(m_callingConvention != CallingConventions::CC_UNREACHED);
        m_callingConvention = m_callingConvention | CallingConventions::CC_GENERIC;
    }

    
    
    template<class ApiHolder>    
    typename BaseMethodGeneratorPimpl<ApiHolder>::method_generator_label_type *BaseMethodGeneratorPimpl<ApiHolder>::CloneShell(wstring const &newName)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(m_pSrcMethod);
        auto mdmd = GetToken();
        _ASSERTE(TypeFromToken(mdmd) == mdtMethodDef);
        _ASSERTE(!IsGenericMethod());
        auto const &sig = GetSignature();
        _ASSERTE(!sig.GetBlob().empty());
        auto const &blob = sig.GetBlob();
        
        
        auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
        
        auto pComMetaImp = ATL::CComPtr<IMetaDataImport2>();
        {
            auto hr = comMetaEmt.QueryInterface(IID_IMetaDataImport2, reinterpret_cast<void **>(&pComMetaImp));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        
        auto mdmdNew = mdTokenNil;
        auto callingConvention = CallingConventions(blob[0]);
        {
            auto wzname = array<WCHAR, MAX_SYM_NAME>();
            auto wznameLength = 0ul;
            auto mdtOwner = mdTokenNil;
            auto dwattr = 0ul;
            auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
            auto sigLength = 0ul;
            auto codeRva = 0ul;
            auto dwimplFlags = 0ul;
            {
                auto hr = pComMetaImp->GetMethodProps(mdmd, &mdtOwner, wzname.c_array(), static_cast<ULONG>(wzname.size()), &wznameLength, &dwattr, &pSig, &sigLength, &codeRva, &dwimplFlags);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            
            codeRva = dwimplFlags != MethodImplAttributes::MIA_IL ? 0 : m_pAsmGen->GetValidRVA();
            {
                auto hr = comMetaEmt.DefineMethod(mdtOwner, newName.c_str(), dwattr, pSig, sigLength, codeRva, dwimplFlags, &mdmdNew);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
        }

        {
            auto dwMappingFlags = 0ul;
            auto wzname = array<WCHAR, MAX_SYM_NAME>();
            auto wznameLength = 0ul;
            auto mdmr = mdTokenNil;
            {
                auto hr = pComMetaImp->GetPinvokeMap(mdmd, &dwMappingFlags, wzname.c_array(), static_cast<ULONG>(wzname.size()), &wznameLength, &mdmr);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }

            {
                auto hr = comMetaEmt.DefinePinvokeMap(mdmdNew, dwMappingFlags, wzname.c_array(), mdmr);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
        }
        
        auto mdpds = vector<mdParamDef>();
        {
            auto hEnum = static_cast<HCORENUM>(nullptr);
            BOOST_SCOPE_EXIT((&hEnum)(pComMetaImp))
            {
                if (hEnum)
                    pComMetaImp->CloseEnum(hEnum);
            }
            BOOST_SCOPE_EXIT_END
            auto mdpds_ = array<mdParamDef, 16>();
            auto count = 0ul;
            auto hr = E_FAIL;
            do
            {
                hr = pComMetaImp->EnumParams(&hEnum, mdmd, mdpds_.c_array(), static_cast<ULONG>(mdpds_.size()), &count);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                mdpds.reserve(mdpds.size() + count);
                for (auto i = 0u; i < count; ++i)
                    mdpds.push_back(mdpds_[i]);
            } while (0 < count);
        }
        
        BOOST_FOREACH (auto const &mdpd, mdpds)
        {
            auto mdtOwner = mdTokenNil;
            auto position = 0ul;
            auto wzname = array<WCHAR, MAX_SYM_NAME>();
            auto wznameLength = 0ul;
            auto dwattr = 0ul;
            auto cplusTypeFlag = 0ul;
            auto const *pDefaultValue = static_cast<UVCP_CONSTANT>(nullptr);
            auto defaultValueLength = 0ul;
            {
                auto hr = pComMetaImp->GetParamProps(mdpd, &mdtOwner, &position, wzname.c_array(), static_cast<ULONG>(wzname.size()), &wznameLength, &dwattr, &cplusTypeFlag, &pDefaultValue, &defaultValueLength);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            
            auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
            auto sigLength = 0ul;
            {
                auto hr = pComMetaImp->GetFieldMarshal(mdpd, &pSig, &sigLength);
                if (hr != CLDB_E_RECORD_NOTFOUND && FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            
            auto mdpdNew = mdTokenNil;
            {
                auto hr = comMetaEmt.DefineParam(mdmdNew, position, wzname.c_array(), dwattr, cplusTypeFlag, pDefaultValue, defaultValueLength, &mdpdNew);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            
            if (sigLength)
            {
                auto hr = comMetaEmt.SetFieldMarshal(mdpdNew, pSig, sigLength);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
        }

        return m_pAsmGen->DefineMethod(mdmdNew, callingConvention, true, MetadataSpecialValues::EMPTY_TYPES, nullptr, m_pAsmGen->GetMethod(mdmdNew), m_pSrcMethod->GetMember());
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetAttributes(MethodAttributes const &attr)
    {
        m_attr = attr;
        m_isPropsReModified = true;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetImplementationFlags(MethodImplAttributes const &implAttr)
    {
        m_implAttr = implAttr;
        m_isPropsReModified = true;
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
        _ASSERTE(m_callingConvention == CallingConventions::CC_UNREACHED);
        m_callingConvention = callingConvention;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetReturnType(IType const *pRetType)
    {
        _ASSERTE(!m_pRetType);
        m_pRetType = pRetType;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetParameters(vector<IParameter const *> const &params)
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetMember(MethodProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetGenericArguments(vector<IType const *> const &genericArgs)
    {
        _ASSERTE(!m_genericArgsInit);
        m_genericArgs = genericArgs;
        m_genericArgsInit = true;
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::SetSourceMethod(IMethod const *pSrcMethod)
    {
        _ASSERTE(!m_pSrcMethod);
        auto const *pSrcMethodGen = dynamic_cast<class_type const *>(pSrcMethod);
        if (!pSrcMethodGen)
            m_pSrcMethod = pSrcMethod;
        else
            m_pSrcMethod = pSrcMethodGen->GetSourceMethod();
    }



    template<class ApiHolder>    
    void BaseMethodGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);

        // TODO: Method 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i)->Accept(pVisitor);

        m_pClass->GetReturnType();   // resolves the return Type of this Method.

        m_pClass->GetParameters();   // resolves the Parameters of this Method.
        auto const &paramGenToIndex = m_pAsmGen->GetParameterGeneratorToIndex();
        for (auto i = 0ul; i < paramGenToIndex.size(); ++i)
            if (m_pClass->Equals(paramGenToIndex[i]->GetMethod()))
                paramGenToIndex[i]->Accept(pVisitor);

        auto const &methodBodyGenToIndex = m_pAsmGen->GetMethodBodyGeneratorToIndex();
        for (auto i = 0ul; i < methodBodyGenToIndex.size(); ++i)
            if (m_pClass->Equals(methodBodyGenToIndex[i]->GetMethod()))
                methodBodyGenToIndex[i]->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETHODGENERATORPIMPL_HPP

