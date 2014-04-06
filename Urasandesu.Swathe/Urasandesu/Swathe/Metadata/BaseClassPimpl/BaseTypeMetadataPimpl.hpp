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
        m_genericParamPos(-1), 
        m_genericArgsInit(false), 
        m_interfacesInit(false), 
        m_methodsInit(false), 
        m_propsInit(false),
        m_casInit(false), 
        m_isNestedInit(false), 
        m_isNested(false), 
        m_kind(TypeKinds::TK_UNREACHED), 
        m_attr(TypeAttributes::TA_UNREACHED), 
        m_baseTypeInit(false), 
        m_pBaseType(nullptr), 
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
        if (!IsNilToken(m_mdt))
            return m_mdt;
        
        switch (m_kind.Value())
        {
            case TypeKinds::TK_VAR:
            case TypeKinds::TK_MVAR:
                FillTypeVariableToken(&m_pAsm->GetCOMMetaDataImport(), m_kind, m_genericParamPos, m_mdt);
                break;
            
            default:
                FillTypeDefToken(&m_pAsm->GetCOMMetaDataImport(), m_fullName, m_mdt);
                break;
        }
        _ASSERTE(!IsNilToken(m_mdt));
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseTypeMetadataPimpl<ApiHolder>::GetFullName() const
    {
        if (!m_fullName.empty())
            return m_fullName;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                m_pAsm->FillTypeDefProperties(mdtTarget, m_fullName, m_attr, m_mdtExt);
                break;
            
            case mdtTypeRef:
                m_pAsm->FillTypeRefProperties(mdtTarget, m_fullName, m_mdtResolutionScope);
                break;
            
            case mdtGenericParam:
                FillGenericParamProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_genericParamPos, m_mdtOwner, m_fullName);
                break;
            
            case mdtTypeSpec:
                m_fullName = GetDeclaringType()->GetFullName();
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(!m_fullName.empty());
        return m_fullName;
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsValueType() const
    {
        auto kind = GetKind();
        switch (kind.Value())
        {
            case TypeKinds::TK_VOID:
            case TypeKinds::TK_BOOLEAN:
            case TypeKinds::TK_CHAR:
            case TypeKinds::TK_I1:
            case TypeKinds::TK_U1:
            case TypeKinds::TK_I2:
            case TypeKinds::TK_U2:
            case TypeKinds::TK_I4:
            case TypeKinds::TK_U4:
            case TypeKinds::TK_I8:
            case TypeKinds::TK_U8:
            case TypeKinds::TK_R4:
            case TypeKinds::TK_R8:
            case TypeKinds::TK_I:
            case TypeKinds::TK_VALUETYPE:
                return true;
            default:
                return false;
        }
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
            return false;
        
        if (m_kind == TypeKinds::TK_GENERICINST)
            return false;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
            case mdtTypeRef:
            case mdtGenericParam:
                return true;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
     }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsByRef() const
    {
        return GetKind() == TypeKinds::TK_BYREF;
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsArray() const
    {
        return GetKind() == TypeKinds::TK_SZARRAY;
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::IsNested() const
    {
        if (m_isNestedInit)
            return m_isNested;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                {
                    if (IsNilToken(m_mdtExt))
                        m_pAsm->FillTypeDefProperties(mdtTarget, m_fullName, m_attr, m_mdtExt);
                    
                    auto vis = m_attr & TypeAttributes::TA_VISIBILITY_MASK;
                    m_isNested = TypeAttributes::TA_NESTED_PUBLIC <= vis && vis <= TypeAttributes::TA_NESTED_FAMOR_ASSEM;
                }
                break;
            
            case mdtTypeRef:
                if (IsNilToken(m_mdtResolutionScope))
                    m_pAsm->FillTypeRefProperties(mdtTarget, m_fullName, m_mdtResolutionScope);
                
                m_isNested = TypeFromToken(m_mdtResolutionScope) == mdtTypeRef;
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        m_isNestedInit = true;
        return m_isNested;
    }



    template<class ApiHolder>    
    ULONG BaseTypeMetadataPimpl<ApiHolder>::GetGenericParameterPosition() const
    {
        if (m_genericParamPos != -1)
            return m_genericParamPos;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtGenericParam:
                FillGenericParamProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_genericParamPos, m_mdtOwner, m_fullName);
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_genericParamPos != -1);
        return m_genericParamPos;
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeMetadataPimpl<ApiHolder>::GetGenericArguments() const
    {
        if (m_genericArgsInit)
            return m_genericArgs;
            
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                FillTypeDefGenericParams(&m_pAsm->GetCOMMetaDataImport(), m_pClass, mdtTarget, m_genericArgsInit, m_genericArgs);
                break;

            case mdtTypeRef:
                m_genericArgs = GetSourceType()->GetGenericArguments();
                m_genericArgsInit = true;
                break;

            case mdtTypeSpec:
                GetDeclaringType();
                break;

            case mdtGenericParam:
            case mdtTypeVar:
            case mdtTypeMVar:
                // nop
                m_genericArgsInit = true;
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_genericArgsInit);
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
    TypeAttributes BaseTypeMetadataPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr != TypeAttributes::TA_UNREACHED)
            return m_attr;
        
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetBaseType() const
    {
        if (m_baseTypeInit)
            return m_pBaseType;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                if (IsNilToken(m_mdtExt))
                    m_pAsm->FillTypeDefProperties(mdtTarget, m_fullName, m_attr, m_mdtExt);
                FillTypeDefBaseType(m_pClass, m_mdtExt, m_baseTypeInit, m_pBaseType);
                break;
            
            case mdtTypeRef:
                m_pBaseType = GetSourceType()->GetBaseType();
                m_baseTypeInit = true;
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_baseTypeInit);
        //_ASSERTE(m_pBaseType);    // Don't assert m_pBaseType, because it is allowed nullptr(e.g. System.Object).
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
                    hr = comMetaImp.EnumInterfaceImpls(&hEnum, mdtTarget, mdiis.c_array(), static_cast<ULONG>(mdiis.size()), &count);
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

        auto const &member = GetMember();
        auto const *const *ppModule = get<IModule const *>(&member);
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

        auto const &member = GetMember();
        auto const *const *ppDeclaringType = get<IType const *>(&member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetDeclaringMethod() const
    {
        using boost::get;

        auto const &member = GetMember();
        auto const *const *ppDeclaringMethod = get<IMethod const *>(&member);
        return !ppDeclaringMethod ? nullptr : *ppDeclaringMethod;
    }



    template<class ApiHolder>    
    TypeProvider const &BaseTypeMetadataPimpl<ApiHolder>::GetMember() const
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!Empty(m_member))
            return m_member;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                {
                    if (IsNilToken(m_mdtExt))
                        m_pAsm->FillTypeDefProperties(mdtTarget, m_fullName, m_attr, m_mdtExt);
                
                    auto visibility = m_attr & TypeAttributes::TA_VISIBILITY_MASK;
                    if (TypeAttributes::TA_NESTED_PUBLIC <= visibility && visibility <= TypeAttributes::TA_NESTED_FAMOR_ASSEM)
                        FillNestedTypeOwner(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_mdtOwner);
                
                    FillTypeMember(m_pClass, m_mdtOwner, m_member);
                }
                break;
                
            case mdtTypeRef:
                m_member = GetSourceType()->GetMember();
                break;
                
            case mdtGenericParam:
                if (IsNilToken(m_mdtOwner))
                    FillGenericParamProperties(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_genericParamPos, m_mdtOwner, m_fullName);
                FillTypeMember(m_pClass, m_mdtOwner, m_member);
                break;
                
            case mdtTypeSpec:
                if (m_sig.GetBlob().empty())
                    FillTypeSpecSignature(&m_pAsm->GetCOMMetaDataImport(), mdtTarget, m_sig);
                FillTypeSpecProperties(m_pClass, m_sig, m_kind, m_member, m_genericArgsInit, m_genericArgs, m_genericParamPos);
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
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetNestedType(mdToken mdt) const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_UNREACHED, -1, false, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetGenericParameter(mdToken mdt) const
    {
        return m_pAsm->GetType(mdt, TypeKinds::TK_VAR, -1, false, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    ICustomAttribute const *BaseTypeMetadataPimpl<ApiHolder>::GetCustomAttribute(mdToken mdt) const
    {
        return m_pAsm->GetCustomAttribute(mdt, static_cast<IType const *>(m_pClass));
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
    bool BaseTypeMetadataPimpl<ApiHolder>::IsDefined(IType const *pAttrType) const
    {
        using boost::empty;
        return !empty(GetCustomAttributes(pAttrType));
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeMetadataPimpl<ApiHolder>::GetCustomAttributes() const
    {
        if (m_casInit)
            return m_cas;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                FillTypeDefCustomAttributes(&m_pAsm->GetCOMMetaDataImport(), m_pClass, mdtTarget, m_casInit, m_cas);
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_casInit);
        return m_cas;
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeMetadataPimpl<ApiHolder>::GetCustomAttributes(IType const *pAttributeType) const
    {
        using boost::adaptors::filtered;
        using std::function;
        
        auto cas = GetCustomAttributes();
        auto isTarget = function<bool (ICustomAttribute const *)>();
        isTarget = [pAttributeType](ICustomAttribute const *pCas) { return pCas->GetAttributeType()->GetSourceType() == pAttributeType->GetSourceType(); };
        return cas | filtered(isTarget);
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetSourceType() const
    {
        if (m_pSrcType)
            return m_pSrcType;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
            case mdtGenericParam:
            case mdtTypeVar:
            case mdtTypeMVar:
                m_pSrcType = m_pClass;
                break;
            
            case mdtTypeRef:
                if (IsNilToken(m_mdtResolutionScope))
                    m_pAsm->FillTypeRefProperties(mdtTarget, m_fullName, m_mdtResolutionScope);
                FillTypeRefSourceType(m_pClass, m_mdtResolutionScope, m_fullName, m_pSrcType);
                break;
            
            case mdtTypeSpec:
                m_pSrcType = GetDeclaringType()->GetSourceType();
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_pSrcType);
        return m_pSrcType;
    }



    template<class ApiHolder>    
    bool BaseTypeMetadataPimpl<ApiHolder>::Equals(IType const *pType) const
    {
        using Urasandesu::CppAnonym::Collections::SequenceEqual;

        if (m_pClass == pType)
            return true;

        if (!pType)
            return false;

        auto const *pOtherType = dynamic_cast<class_type const *>(pType);
        if (!pOtherType)
            return m_pClass == pType->GetSourceType();
        
        auto isThisDefinition = !IsGenericType() || IsGenericTypeDefinition();
        auto isOtherDefinition = !pOtherType->IsGenericType() || pOtherType->IsGenericTypeDefinition();
        if (isThisDefinition != isOtherDefinition)
            return false;
        
        if (isThisDefinition && isOtherDefinition)
            return GetToken() == pOtherType->GetToken() &&
                   GetKind() == pOtherType->GetKind() && 
                   GetDeclaringType() == pOtherType->GetDeclaringType() &&  // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
                   GetAssembly() == pOtherType->GetAssembly();
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
            case mdtTypeRef:
            case mdtGenericParam:
            case mdtTypeVar:
            case mdtTypeMVar:
                return GetToken() == pOtherType->GetToken() &&
                       GetKind() == pOtherType->GetKind() && 
                       GetDeclaringType() == pOtherType->GetDeclaringType() &&  // to determine whether this member is gave from Generic Type Definition or Generic Type Instance
                       GetAssembly() == pOtherType->GetAssembly() &&
                       SequenceEqual(GetGenericArguments(), pOtherType->GetGenericArguments());
                
            case mdtTypeSpec:
                return GetToken() == pOtherType->GetToken() &&
                       GetAssembly() == pOtherType->GetAssembly();

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
    }



    template<class ApiHolder>    
    size_t BaseTypeMetadataPimpl<ApiHolder>::GetHashCode() const
    {
        using Urasandesu::CppAnonym::Collections::SequenceHashValue;
        using Urasandesu::CppAnonym::Utilities::HashValue;
            
        auto isDefinition = !IsGenericType() || IsGenericTypeDefinition();
        auto mdtTarget = GetToken();
        auto kindHash = 0;
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeRef:
            case mdtTypeSpec:
                kindHash = 0;
                break;
            
            case mdtTypeDef:
            case mdtGenericParam:
            case mdtTypeVar:
            case mdtTypeMVar:
                kindHash = GetKind().Value();
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        auto asmHash = HashValue(GetAssembly());
        
        return isDefinition ? 
                    (mdtTarget ^ kindHash ^ asmHash) : 
                    (mdtTarget ^ kindHash ^ asmHash ^ SequenceHashValue(GetGenericArguments()));
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::OutDebugInfo() const
    {
        BOOST_LOG_FUNCTION();

        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        CPPANONYM_D_LOGW(L"");
        CPPANONYM_D_LOGW(L"TypeMetadata -----------------------------------------------------");
        CPPANONYM_D_LOGW1(L"m_pClass: 0x%|1|", reinterpret_cast<void *>(m_pClass));
        CPPANONYM_D_LOGW1(L"m_pAsm: 0x%|1|", reinterpret_cast<void *>(m_pAsm));
        CPPANONYM_D_LOGW1(L"m_member: %|1$d|", m_member.which());
        CPPANONYM_D_LOGW1(L"m_mdt: 0x%|1$08X|", m_mdt);
        CPPANONYM_D_LOGW1(L"m_mdtResolutionScope: 0x%|1$08X|", m_mdtResolutionScope);
        CPPANONYM_D_LOGW1(L"m_mdtExt: 0x%|1$08X|", m_mdtExt);
        CPPANONYM_D_LOGW1(L"m_mdtOwner: 0x%|1$08X|", m_mdtOwner);
        CPPANONYM_D_LOGW1(L"m_fullName: %|1$s|", m_fullName);
        CPPANONYM_D_LOGW1(L"m_genericParamPos: %|1$d|", m_genericParamPos);
        CPPANONYM_D_LOGW1(L"m_genericArgsInit: %|1$d|", m_genericArgsInit);
        CPPANONYM_D_LOGW1(L"m_genericArgs.size(): %|1$d|", m_genericArgs.size());
        if (CPPANONYM_D_LOG_ENABLED())
        {
            for (auto i = m_genericArgs.begin(), i_end = m_genericArgs.end(); i != i_end; ++i)
                (*i)->OutDebugInfo();
        }
        CPPANONYM_D_LOGW1(L"m_interfacesInit: %|1$d|", m_interfacesInit);
        CPPANONYM_D_LOGW1(L"m_interfaces.size(): %|1$d|", m_interfaces.size());
        CPPANONYM_D_LOGW1(L"m_methodsInit: %|1$d|", m_methodsInit);
        CPPANONYM_D_LOGW1(L"m_methods.size(): %|1$d|", m_methods.size());
        CPPANONYM_D_LOGW1(L"m_propsInit: %|1$d|", m_propsInit);
        CPPANONYM_D_LOGW1(L"m_props.size(): %|1$d|", m_props.size());
        CPPANONYM_D_LOGW1(L"m_casInit: %|1$d|", m_casInit);
        CPPANONYM_D_LOGW1(L"m_cas.size(): %|1$d|", m_cas.size());
        if (CPPANONYM_D_LOG_ENABLED())
        {
            auto const &blob = m_sig.GetBlob();
            auto oss = std::wostringstream();
            oss << L"m_sig:";
            for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
                oss << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
            CPPANONYM_D_LOGW(oss.str());
        }
        CPPANONYM_D_LOGW1(L"m_kind: 0x%|1$02X|", m_kind.Value());
        CPPANONYM_D_LOGW1(L"m_attr: %|1$d|", m_attr.Value());
        CPPANONYM_D_LOGW1(L"m_baseTypeInit: %|1$d|", m_baseTypeInit);
        CPPANONYM_D_LOGW1(L"m_pBaseType: 0x%|1|", reinterpret_cast<void const *>(m_pBaseType));
        if (CPPANONYM_D_LOG_ENABLED())
        {
            if (m_pBaseType)
                m_pBaseType->OutDebugInfo();
        }
        CPPANONYM_D_LOGW1(L"m_pSrcType: 0x%|1|", reinterpret_cast<void const *>(m_pSrcType));
        if (CPPANONYM_D_LOG_ENABLED())
        {
            if (m_pSrcType && m_pSrcType != m_pClass)
                m_pSrcType->OutDebugInfo();
        }
        CPPANONYM_D_LOGW(L"------------------------------------------------------------------");
        CPPANONYM_D_LOGW(L"");
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakeArrayType() const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_SZARRAY, -1, true, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakeGenericType(vector<IType const *> const &genericArgs) const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_GENERICINST, -1, true, genericArgs, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakePointerType() const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_PTR, -1, true, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakeByRefType() const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_BYREF, -1, true, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::MakePinnedType() const
    {
        return m_pAsm->GetType(GetToken(), TypeKinds::TK_PINNED, -1, true, MetadataSpecialValues::EMPTY_TYPES, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    IType const *BaseTypeMetadataPimpl<ApiHolder>::GetNestedType(wstring const &name) const
    {
        using boost::adaptors::filtered;
        using boost::copy;
        using std::back_inserter;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto types = m_pClass->GetNestedTypes();
        auto results = vector<IType const *>();
        auto isTarget = [&](IType const *pType) -> bool { return pType->GetFullName() == name; };
        copy(types | filtered(isTarget), back_inserter(results));
        
        if (results.size() == 0)
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_NOTFOUND));
        
        if (1 < results.size())
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_DUPLICATE));
        
        return results[0];
    }



    struct MethodParamToType : 
        std::unary_function<IParameter const *, IType const *>
    {
        IType const *operator ()(IParameter const *pParam) const
        {
            return pParam->GetParameterType();
        }
    };

    struct MethodSigTypeEqualTo : 
        std::binary_function<IType const *, IType const *, bool>
    {
        bool operator ()(IType const *x, IType const *y) const
        {
            return x->GetSourceType() == y->GetSourceType();
        }
    };

    template<class ApiHolder>    
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetMethod(wstring const &name) const
    {
        using boost::adaptors::filtered;
        using boost::copy;
        using std::back_inserter;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto methods = m_pClass->GetMethods();
        auto results = vector<IMethod const *>();
        auto isTarget = [&](IMethod const *pMethod) -> bool { return pMethod->GetName() == name; };
        copy(methods | filtered(isTarget), back_inserter(results));
        
        if (results.size() == 0)
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_NOTFOUND));
        
        if (1 < results.size())
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_DUPLICATE));
        
        return results[0];
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
                using Urasandesu::CppAnonym::Collections::SequenceEqual;
                                  
                auto toType = MethodParamToType();
                auto typeEqualTo = MethodSigTypeEqualTo();
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
                                  
                auto toType = MethodParamToType();
                auto typeEqualTo = MethodSigTypeEqualTo();
                return pMethod->GetName() == name && 
                       pMethod->GetCallingConvention() == callingConvention && 
                       typeEqualTo(pMethod->GetReturnType(), pRetType) && 
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
    IMethod const *BaseTypeMetadataPimpl<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IParameter const *> const &params) const
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
                using Urasandesu::CppAnonym::Collections::SequenceEqual;
                                  
                auto toType = MethodParamToType();
                auto typeEqualTo = MethodSigTypeEqualTo();
                return pMethod->GetName() == name && 
                       pMethod->GetCallingConvention() == callingConvention && 
                       typeEqualTo(pMethod->GetReturnType(), pRetType) && 
                       SequenceEqual(pMethod->GetParameters() | transformed(toType), params | transformed(toType), typeEqualTo); 
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
        auto const *pMSCorLib = m_pAsm->GetAssembly(MetadataSpecialValues::ASSEMBLY_FULL_NAME_OF_MSCORLIB, m_pAsm->GetProcessorArchitectures());
        auto const *pMSCorLibDll = pMSCorLib->GetMainModule();
        auto const *pVoid = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_VOID);
        return m_pClass->GetMethod(MetadataSpecialValues::METHOD_NAME_OF_CTOR, CallingConventions::CC_HAS_THIS, pVoid, paramTypes);
    }



    template<class ApiHolder>    
    IProperty const *BaseTypeMetadataPimpl<ApiHolder>::GetProperty(wstring const &name) const
    {
        using std::find_if;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto props = m_pClass->GetProperties();
        auto result = find_if(props.begin(), props.end(), [&](IProperty const *prop) { return prop->GetName() == name; });
        if (result == props.end())
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_NOTFOUND));
        
        return *result;
    }



    template<class ApiHolder>    
    ITypePtrRange BaseTypeMetadataPimpl<ApiHolder>::GetNestedTypes() const
    {
        using boost::adaptors::filtered;
        using std::function;
        
        auto types = m_pAsm->GetTypes();
        auto const *pClass = m_pClass;
        auto isTarget = function<bool (IType const *)>();
        isTarget = [pClass](IType const *pType) { return !pType->GetDeclaringType() ? false : pType->GetDeclaringType()->Equals(pClass); };
        return types | filtered(isTarget);
    }



    template<class ApiHolder>    
    IMethodPtrRange BaseTypeMetadataPimpl<ApiHolder>::GetMethods() const
    {
        if (m_methodsInit)
            return m_methods;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                FillTypeDefMethods(&m_pAsm->GetCOMMetaDataImport(), m_pClass, mdtTarget, m_methodsInit, m_methods);
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_methodsInit);
        return m_methods;
    }



    template<class ApiHolder>    
    IMethodPtrRange BaseTypeMetadataPimpl<ApiHolder>::GetConstructors() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IPropertyPtrRange BaseTypeMetadataPimpl<ApiHolder>::GetProperties() const
    {
        if (m_propsInit)
            return m_props;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                FillTypeDefProperties(&m_pAsm->GetCOMMetaDataImport(), m_pClass, mdtTarget, m_propsInit, m_props);
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        _ASSERTE(m_propsInit);
        return m_props;
    }



    template<class ApiHolder>    
    TypeKinds BaseTypeMetadataPimpl<ApiHolder>::GetKind() const 
    {
        if (m_kind != TypeKinds::TK_UNREACHED)
            return m_kind;
        
        auto const &fullName = GetFullName();
        if (m_kind != TypeKinds::TK_UNREACHED)  // If this type is a TypeSpec, TypeKinds should have been already set.
            return m_kind;
        
        m_kind = MetadataSpecialValues::ToTypeKind(fullName);
        if (m_kind != TypeKinds::TK_UNREACHED)
            return m_kind;
        
        m_kind = TypeKinds::TK_CLASS;
        if (m_attr & TypeAttributes::TA_INTERFACE)  // This check is a experiment. Note that any interfaces don't have its base type. 
            return m_kind;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtTypeDef:
                {
                    if (IsNilToken(m_mdtExt))
                        m_pAsm->FillTypeDefProperties(mdtTarget, m_fullName, m_attr, m_mdtExt);
                    
                    if (TypeFromToken(m_mdtExt) == mdtTypeSpec) // This check is shortcut for CRTP. e.g. class A<T> : B<A<T>>.
                        return m_kind = TypeKinds::TK_CLASS;
                    
                    auto const *pBaseType = GetBaseType();
                    _ASSERTE(pBaseType);
                    auto const &baseTypeFullName = pBaseType->GetFullName();
                    m_kind = MetadataSpecialValues::ToTypeKind(fullName, baseTypeFullName);
                    return m_kind;
                }
            
            case mdtTypeRef:
                return m_kind = GetSourceType()->GetKind();

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
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
        _ASSERTE(!m_genericArgsInit);
        m_genericArgsInit = true;
        m_genericArgs = genericArgs;        
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::SetGenericParameterPosition(ULONG genericParamPos)
    {
        _ASSERTE(m_genericParamPos == -1);
        m_genericParamPos = genericParamPos;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::SetKind(TypeKinds const &kind)
    {
        _ASSERTE(m_kind == TypeKinds::TK_UNREACHED);
        m_kind = kind;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefToken(IMetaDataImport2 *pComMetaImp, wstring const &fullName, mdToken &mdt)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(pComMetaImp);
        _ASSERTE(IsNilToken(mdt));
        _ASSERTE(!fullName.empty());

        auto hr = pComMetaImp->FindTypeDefByName(fullName.c_str(), NULL, &mdt);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefBaseType(IType const *pType, mdToken mdtExt, bool &baseTypeInit, IType const *&pBaseType)
    {
        _ASSERTE(pType);
        
        BOOST_SCOPE_EXIT((&baseTypeInit))
        {
            baseTypeInit = true;
        }
        BOOST_SCOPE_EXIT_END

        if (IsNilToken(mdtExt)) // e.g. System.Object
            return;
        
        if (baseTypeInit)
            return;
        
        auto const *pAsm = pType->GetAssembly();
        pBaseType = pAsm->GetType(mdtExt);
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefGenericParams(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &genericArgsInit, vector<IType const *> &genericArgs)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        
        if (genericArgsInit)
            return;
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&pComMetaImp))
        {
            if (hEnum)
                pComMetaImp->CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdgps = array<mdGenericParam, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = pComMetaImp->EnumGenericParams(&hEnum, mdtTarget, mdgps.c_array(), static_cast<ULONG>(mdgps.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            genericArgs.reserve(genericArgs.size() + count);
            for (auto i = 0u; i < count; ++i)
            {
                auto const *pGenericArg = pType->GetGenericParameter(mdgps[i]);
                genericArgs.push_back(pGenericArg);
            }
        } while (0 < count);
        
        genericArgsInit = true;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefCustomAttributes(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &casInit, vector<ICustomAttribute const *> &cas)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        
        if (casInit)
            return;
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&pComMetaImp))
        {
            if (hEnum)
                pComMetaImp->CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdcas = array<mdCustomAttribute, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = pComMetaImp->EnumCustomAttributes(&hEnum, mdtTarget, 0, mdcas.c_array(), static_cast<ULONG>(mdcas.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            cas.reserve(cas.size() + count);
            for (auto i = 0u; i < count; ++i)
            {
                auto const *pCas = pType->GetCustomAttribute(mdcas[i]);
                cas.push_back(pCas);
            }
        } while (0 < count);
        
        casInit = true;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefMethods(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &methodsInit, vector<IMethod const *> &methods)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        
        if (methodsInit)
            return;
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&pComMetaImp))
        {
            if (hEnum)
                pComMetaImp->CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdmds = array<mdMethodDef, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = pComMetaImp->EnumMethods(&hEnum, mdtTarget, mdmds.c_array(), static_cast<ULONG>(mdmds.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            methods.reserve(methods.size() + count);
            for (auto i = 0u; i < count; ++i)
            {
                auto const *pMethod = pType->GetMethod(mdmds[i]);
                methods.push_back(pMethod);
            }
        } while (0 < count);
        
        methodsInit = true;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeDefProperties(IMetaDataImport2 *pComMetaImp, IType const *pType, mdToken mdtTarget, bool &propsInit, vector<IProperty const *> &props)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(!IsNilToken(mdtTarget));
        
        if (propsInit)
            return;
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&pComMetaImp))
        {
            if (hEnum)
                pComMetaImp->CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdps = array<mdProperty, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = pComMetaImp->EnumProperties(&hEnum, mdtTarget, mdps.c_array(), static_cast<ULONG>(mdps.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            props.reserve(props.size() + count);
            for (auto i = 0u; i < count; ++i)
            {
                auto const *pProp = pType->GetProperty(mdps[i]);
                props.push_back(pProp);
            }
        } while (0 < count);
        
        propsInit = true;
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillNestedTypeOwner(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        _ASSERTE(IsNilToken(mdtOwner));

        auto hr = pComMetaImp->GetNestedClassProps(mdtTarget, &mdtOwner);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeRefSourceType(IType const *pType, mdToken mdtResolutionScope, wstring const &fullName, IType const *&pSrcType)
    {
        _ASSERTE(pType);
        _ASSERTE(!IsNilToken(mdtResolutionScope));
        _ASSERTE(!fullName.empty());
        
        if (pSrcType)
            return;

        if (TypeFromToken(mdtResolutionScope) == mdtAssemblyRef)
        {
            auto const *pAsm = pType->GetAssembly();
            auto const *pRefAsm = pAsm->GetAssemblyReference(mdtResolutionScope);
            auto const &metadata = pRefAsm->GetAssemblyMetadata();
            auto const *pRefSrcAsm = pAsm->GetAssembly(pRefAsm->GetFullName(), pRefAsm->GetProcessorArchitectures());
            pSrcType = pRefSrcAsm->GetType(fullName);
        }
        else if (TypeFromToken(mdtResolutionScope) == mdtTypeRef)
        {
            auto const *pAsm = pType->GetAssembly();
            auto const *pRefType = pAsm->GetType(mdtResolutionScope);
            auto const *pRefSrcType = pRefType->GetSourceType();
            pSrcType = pRefSrcType->GetNestedType(fullName);
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
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
        auto hr = pComMetaImp->GetGenericParamProps(mdtTarget, &genericParamPos, &genericParamFlags, &mdtOwner, &reserved, wzname.c_array(), static_cast<ULONG>(wzname.size()), &length);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        fullName = wzname.data();
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeMember(IType const *pType, mdToken mdtOwner, TypeProvider &member)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        _ASSERTE(pType);
        
        if (!Empty(member))
            return;
        
        auto const *pAsm = pType->GetAssembly();
        if (IsNilToken(mdtOwner))
            member = pAsm->GetMainModule();
        else if (TypeFromToken(mdtOwner) == mdtTypeDef)
            member = pAsm->GetType(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtTypeRef)
            member = pAsm->GetType(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtMethodDef)
            member = pAsm->GetMethod(mdtOwner);
        else if (TypeFromToken(mdtOwner) == mdtMemberRef)
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
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeSpecProperties(IType const *pType, Signature const &sig, TypeKinds &kind, TypeProvider &member, bool &genericArgsInit, vector<IType const *> &genericArgs, ULONG &genericParamPos)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pType);
        auto const &blob = sig.GetBlob();
        _ASSERTE(!blob.empty());
        kind = TypeKinds(blob[0]);
        switch (kind.Value())
        {
            case TypeKinds::TK_PTR:
            case TypeKinds::TK_SZARRAY:
                {
                    auto const *pDeclaringType = static_cast<IType *>(nullptr);
                    sig.Decode(pType, kind, pDeclaringType);
                    member = pDeclaringType;
                    genericArgsInit = true;
                }
                break;
            
            case TypeKinds::TK_GENERICINST:
                {
                    auto const *pDeclaringType = static_cast<IType *>(nullptr);
                    sig.Decode(pType, kind, pDeclaringType, genericArgs);
                    member = pDeclaringType;
                    genericArgsInit = true;
                }
                break;

            case TypeKinds::TK_VAR:
            case TypeKinds::TK_MVAR:
                {
                    auto const *pAsm = pType->GetAssembly();
                    sig.Decode(pType, kind, genericParamPos);
                    member = pAsm->GetMainModule();
                    genericArgsInit = true;
                }
                break;

            default:
                {
                    auto oss = std::wostringstream();
                    oss << boost::wformat(L"kind.Value():  %|1$02X|") % kind.Value();
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
                }
                break;
        }
    }



    template<class ApiHolder>    
    void BaseTypeMetadataPimpl<ApiHolder>::FillTypeVariableToken(IMetaDataImport2 *pComMetaImp, TypeKinds const &targetKind, ULONG targetPos, mdToken &mdt)
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        _ASSERTE(pComMetaImp);
        _ASSERTE(targetKind != TypeKinds::TK_UNREACHED);
        _ASSERTE(targetPos != -1);
        _ASSERTE(IsNilToken(mdt));

        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&pComMetaImp))
        {
            if (hEnum)
                pComMetaImp->CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdtss = array<mdTypeSpec, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = pComMetaImp->EnumTypeSpecs(&hEnum, mdtss.c_array(), static_cast<ULONG>(mdtss.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            for (auto i = 0u; i < count; ++i)
            {
                auto sig = Signature();
                FillTypeSpecSignature(pComMetaImp, mdtss[i], sig);
                
                auto const &blob = sig.GetBlob();
                _ASSERTE(!blob.empty());
                auto index = 0ul;
                auto kind = TypeKinds(blob[index++]);
                if (kind != targetKind)
                    continue;
                
                auto pos = 0ul;
                index += ::CorSigUncompressData(&blob[index], &pos);
                if (pos != targetPos)
                    continue;
                
                // In this case, the type is used by a method body.
                mdt = mdtss[i];
                return;
            }
        } while (0 < count);

        // In this case, the type is only used by a signature(For convenience, a special value is specified as the metadata token).
        switch (targetKind.Value())
        {
            case TypeKinds::TK_VAR:
                mdt = TokenFromRid(targetPos + 1, mdtTypeVar);
                break;

            case TypeKinds::TK_MVAR:
                mdt = TokenFromRid(targetPos + 1, mdtTypeMVar);
                break;

            default:
                {
                    auto oss = std::wostringstream();
                    oss << boost::wformat(L"targetKind.Value():  %|1$02X|") % targetKind.Value();
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(oss.str()));
                }
                break;
        }
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEMETADATAPIMPL_HPP

