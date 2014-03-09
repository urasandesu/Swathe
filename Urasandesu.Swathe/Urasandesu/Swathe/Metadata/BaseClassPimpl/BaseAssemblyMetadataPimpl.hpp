/* 
 * File: BaseAssemblyMetadataPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseAssemblyMetadataPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAssemblyMetadataPimpl<ApiHolder>::BaseAssemblyMetadataPimpl(assembly_metadata_label_type *pClass) : 
        m_pClass(pClass), 
        m_pMetaInfo(nullptr), 
        m_pDisp(nullptr),
        m_pPEInfo(nullptr), 
        m_pFuInfo(nullptr),
        m_pSnInfo(nullptr),
        m_mdt(mdTokenNil), 
        m_casInit(false), 
        m_typesInit(false), 
        m_asmFlags(AssemblyFlags::AF_UNREACHED),
        m_asmStorageInit(false), 
        m_openFlags(ofRead), 
        m_pOpeningAsm(nullptr), 
        m_pSrcAsm(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_METADATA_PIMPL_ADDITIONAL_INSTANTIATION \
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::Initialize(metadata_info_label_type *pMetaInfo, metadata_dispenser_label_type *pDisp, portable_executable_info_label_type const *pPEInfo, fusion_info_label_type const *pFuInfo, strong_name_info_label_type const *pSnInfo)
    {
        _ASSERTE(!m_pMetaInfo);
        _ASSERTE(pMetaInfo);
        m_pMetaInfo = pMetaInfo;

        _ASSERTE(!m_pDisp);
        _ASSERTE(pDisp);
        m_pDisp = pDisp;

        _ASSERTE(!m_pPEInfo);
        _ASSERTE(pPEInfo);
        m_pPEInfo = pPEInfo;

        _ASSERTE(!m_pFuInfo);
        _ASSERTE(pFuInfo);
        m_pFuInfo = pFuInfo;

        _ASSERTE(!m_pSnInfo);
        _ASSERTE(pSnInfo);
        m_pSnInfo = pSnInfo;
    }



    template<class ApiHolder>    
    mdAssembly BaseAssemblyMetadataPimpl<ApiHolder>::GetToken() const
    {
        BOOST_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            auto &comMetaAsmImp = m_pClass->GetCOMMetaDataAssemblyImport();
            auto hr = comMetaAsmImp.GetAssemblyFromScope(&m_mdt);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }

        return m_mdt;
    }
    
    
    
    template<class ApiHolder>    
    wstring const &BaseAssemblyMetadataPimpl<ApiHolder>::GetFullName() const
    {
        using std::wostringstream;
        using Urasandesu::CppAnonym::Collections::SequenceToString;

        if (m_fullName.empty())
        {
            auto const &name = m_pClass->GetName();
            auto const &amd = m_pClass->GetAssemblyMetadata();
            auto const pSnKey = m_pClass->GetStrongNameKey();

            auto oss = wostringstream();
            oss << name;
            oss << L", Version=" << amd.usMajorVersion << L"." << amd.usMinorVersion << L"." << amd.usBuildNumber << L"." << amd.usRevisionNumber;
            oss << L", Culture=";
            if (!amd.cbLocale)
                oss << L"neutral";
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            oss << L", PublicKeyToken=";
            if (!pSnKey)
            {
                oss << L"null";
            }
            else
            {
                auto const &pubKeyToken = pSnKey->GetPublicKeyToken();
                oss << SequenceToString(pubKeyToken.begin(), pubKeyToken.end());
            }
            //if (!amd.rProcessor)
            //{
            //    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            //}
            //else
            //{
            //    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            //}
            m_fullName = oss.str();
        }
        return m_fullName;
    }
    
    
    
    template<class ApiHolder>    
    IModule const *BaseAssemblyMetadataPimpl<ApiHolder>::GetMainModule() const
    {
        return GetModule(MetadataSpecialValues::MODULE_NAME_OF_MAIN);
    }
    
    
    
    template<class ApiHolder>    
    IModule const *BaseAssemblyMetadataPimpl<ApiHolder>::GetModule(wstring const &name) const
    {
        return m_pClass->GetModuleCore(name);
    }
    
    
    
    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> const &BaseAssemblyMetadataPimpl<ApiHolder>::GetStrongNameKey() const
    {
        if (!m_pSnKey)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtAssembly)
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_procArchs, m_asmFlags);
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_pSnKey;
    }
    
    
    
    template<class ApiHolder>    
    wstring const &BaseAssemblyMetadataPimpl<ApiHolder>::GetName() const
    {
        if (m_asmFlags == AssemblyFlags::AF_UNREACHED)  // Name property has the potential to be incomplete, so we use the Flags property instead of it
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtAssembly)
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_procArchs, m_asmFlags);
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
                FillAssemblyRefProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_procArchs, m_asmFlags);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }
    
    
    
    template<class ApiHolder>    
    ASSEMBLYMETADATA const &BaseAssemblyMetadataPimpl<ApiHolder>::GetAssemblyMetadata() const
    {
        if (m_asmFlags == AssemblyFlags::AF_UNREACHED) // ASSEMBLYMETADATA can't validate whether it has already initialized, so we use the Flags property instead of it. Flags property has value necessarily.
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtAssembly)
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_procArchs, m_asmFlags);
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_amd;
    }
    
    
    
    template<class ApiHolder>    
    AssemblyFlags BaseAssemblyMetadataPimpl<ApiHolder>::GetFlags() const
    {
        if (m_asmFlags == AssemblyFlags::AF_UNREACHED)
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtAssembly)
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_procArchs, m_asmFlags);
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_asmFlags;
    }
    
    
    
    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadataPimpl<ApiHolder>::GetSourceAssembly() const
    {
        return m_pSrcAsm == nullptr ? m_pClass : m_pSrcAsm->GetSourceAssembly();
    }
    
    
    
    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadataPimpl<ApiHolder>::GetTargetAssembly() const
    {
        return m_pOpeningAsm;
    }



    template<class ApiHolder>    
    IDispenser const *BaseAssemblyMetadataPimpl<ApiHolder>::GetDispenser() const
    {
        return m_pDisp;
    }
    
    
    
    template<class ApiHolder>    
    IField const *BaseAssemblyMetadataPimpl<ApiHolder>::GetField(mdToken mdt) const
    {
        return m_pClass->GetField(mdt, FieldProvider());
    }



    template<class ApiHolder>    
    IMethod const *BaseAssemblyMetadataPimpl<ApiHolder>::GetMethod(mdToken mdt) const
    {
        return m_pClass->GetMethod(mdt, CallingConventions::CC_UNREACHED, false, MetadataSpecialValues::EMPTY_TYPES, nullptr, MethodProvider());
    }



    template<class ApiHolder>    
    IMethod const *BaseAssemblyMetadataPimpl<ApiHolder>::GetMethod(mdToken mdt, COR_ILMETHOD *pILBody) const
    {
        return m_pClass->GetMethod(mdt, CallingConventions::CC_UNREACHED, false, MetadataSpecialValues::EMPTY_TYPES, pILBody, MethodProvider());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyMetadataPimpl<ApiHolder>::GetType(mdToken mdt) const
    {
        return m_pClass->GetType(mdt, TypeKinds::TK_UNREACHED, static_cast<ULONG>(-1), false, MetadataSpecialValues::EMPTY_TYPES, TypeProvider());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyMetadataPimpl<ApiHolder>::GetType(wstring const &fullName) const
    {
        return m_pClass->GetType(fullName, TypeProvider());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyMetadataPimpl<ApiHolder>::GetGenericTypeParameter(ULONG genericParamPos) const
    {
        return m_pClass->GetType(TokenFromRid(genericParamPos + 1, mdtTypeVar), TypeKinds::TK_VAR, genericParamPos, false, MetadataSpecialValues::EMPTY_TYPES, GetMainModule());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyMetadataPimpl<ApiHolder>::GetGenericMethodParameter(ULONG genericParamPos) const
    {
        return m_pClass->GetType(TokenFromRid(genericParamPos + 1, mdtTypeMVar), TypeKinds::TK_MVAR, genericParamPos, false, MetadataSpecialValues::EMPTY_TYPES, GetMainModule());
    }



    template<class ApiHolder>    
    vector<ProcessorArchitecture> const &BaseAssemblyMetadataPimpl<ApiHolder>::GetProcessorArchitectures() const
    {
        return m_procArchs;
    }



    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadataPimpl<ApiHolder>::GetAssembly(wstring const &fullName) const
    {
        return m_pDisp->GetAssembly(fullName);
    }



    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadataPimpl<ApiHolder>::GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        return m_pDisp->GetAssemblyCore(fullName, procArchs);
    }



    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadataPimpl<ApiHolder>::GetAssemblyReference(mdAssemblyRef mdt) const
    {
        return m_pDisp->GetAssemblyRefCore(m_pClass, mdt);
    }
    

    
    template<class ApiHolder>    
    ICustomAttribute const *BaseAssemblyMetadataPimpl<ApiHolder>::GetCustomAttribute(mdToken mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseAssemblyMetadataPimpl<ApiHolder>::GetCustomAttributes() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_casInit)
        {
            if (!m_pSrcAsm)
            {
                auto &comMetaImp = m_pClass->GetCOMMetaDataImport();

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
                        auto pCas = m_pClass->GetCustomAttribute(mdcas[i], static_cast<IAssembly const *>(m_pClass));
                        m_cas.push_back(pCas);
                    }
                } while (0 < count);
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }

            m_casInit = true;
        }

        return m_cas;
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseAssemblyMetadataPimpl<ApiHolder>::GetCustomAttributes(IType const *pAttributeType) const
    {
        using boost::adaptors::filtered;
        using std::function;
        
        auto cas = GetCustomAttributes();
        auto isTarget = function<bool (ICustomAttribute const *)>();
        isTarget = [pAttributeType](ICustomAttribute const *pCas) { return pCas->GetAttributeType()->GetSourceType() == pAttributeType->GetSourceType(); };
        return cas | filtered(isTarget);
    }



    template<class ApiHolder>    
    ITypePtrRange BaseAssemblyMetadataPimpl<ApiHolder>::GetTypes() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_typesInit)
        {
            if (!m_pSrcAsm)
            {
                auto &comMetaImp = m_pClass->GetCOMMetaDataImport();

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
                        auto pType = m_pClass->GetType(mdtds[i]);
                        m_types.push_back(pType);
                    }
                } while (0 < count);
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }

            m_typesInit = true;
        }

        return m_types;
    }



    template<class ApiHolder>    
    iterator_range<BYTE const *> BaseAssemblyMetadataPimpl<ApiHolder>::GetAssemblyStorage() const
    {
        if (!m_asmStorageInit)
        {
            auto pReader = m_pPEInfo->CreateReader(&GetCOMMetaDataImport(), GetAssemblyFilePath());
            m_asmStorage = pReader->GetMappedFileSource();
            m_asmStorageInit = true;
        }
        return m_asmStorage;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::Exists() const
    {
        using boost::filesystem::path;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pComMetaImp.p != nullptr)
            return true;

        auto &comMetaDisp = m_pDisp->GetCOMMetaDataDispenser();

        auto &asmPath = path();
        asmPath /= m_name + L".dll";
        auto openFlags = m_pClass->GetOpenFlags();
        auto hr = comMetaDisp.OpenScope(asmPath.c_str(), openFlags, 
                                        IID_IMetaDataImport2, reinterpret_cast<IUnknown **>(&m_pComMetaImp));
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        else
            return true;
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetFullName(wstring const &fullName)
    {
        _ASSERTE(!fullName.empty());
        _ASSERTE(m_fullName.empty());
        m_fullName = fullName;
    }
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetCOMMetaDataImport(IMetaDataImport2 *pComMetaImp)
    {
        _ASSERTE(m_pComMetaImp.p == nullptr);
        _ASSERTE(pComMetaImp != nullptr);
        m_pComMetaImp = pComMetaImp;
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetAssemblyFilePath(path const &asmPath)
    {
        _ASSERTE(!asmPath.empty());
        _ASSERTE(m_asmPath.empty());
        m_asmPath = asmPath;
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetToken(mdToken mdt)
    {
        _ASSERTE(!IsNilToken(mdt));
        _ASSERTE(IsNilToken(m_mdt));
        m_mdt = mdt;
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::module_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetModuleCore(wstring const &name) const
    {
        auto pNewMod = NewModule(name);

        auto *pExistingMod = static_cast<module_metadata_label_type *>(nullptr);
        if (!TryGetModule(*pNewMod, pExistingMod))
        {
            pNewMod.Persist();
            return pNewMod.Get();
        }
        else
        {
            return pExistingMod;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::module_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewModule(wstring const &name) const
    {
        auto pMod = m_pMetaInfo->NewModuleCore(m_pClass);
        pMod->SetName(name);
        return pMod;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetModule(module_metadata_label_type const &mod, module_metadata_label_type *&pExistingMod) const
    {
        if (m_modToIndex.find(&mod) == m_modToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_modToIndex[&mod];
            pExistingMod = m_pMetaInfo->GetModuleCore(index);
            return true;
        }
    }
    


    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterModule(TempPtr<module_metadata_label_type> &pMod)
    {
        auto &mod = *pMod;
        m_modToIndex[&mod] = m_pMetaInfo->RegisterModuleCore(pMod);
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::type_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetType(wstring const &fullName, TypeProvider const &member) const
    {
        auto pNewType = NewType(fullName, member);

        auto *pExistingType = static_cast<type_metadata_label_type *>(nullptr);
        if (!TryGetType(*pNewType, pExistingType))
        {
            pNewType.Persist();
            return pNewType.Get();
        }
        else
        {
            return pExistingType;
        }
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::type_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetType(mdToken mdt, TypeKinds const &kind, ULONG genericParamPos, bool genericArgsSpecified, vector<IType const *> const &genericArgs, TypeProvider const &member) const
    {
        auto pNewType = NewType(mdt, kind, genericParamPos, genericArgsSpecified, genericArgs, member);

        auto *pExistingType = static_cast<type_metadata_label_type *>(nullptr);
        if (!TryGetType(*pNewType, pExistingType))
        {
            pNewType.Persist();
            return pNewType.Get();
        }
        else
        {
            return pExistingType;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::type_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewType(wstring const &fullName, TypeProvider const &member) const
    {
        auto pType = m_pMetaInfo->NewTypeCore(m_pClass);
        pType->SetFullName(fullName);
        pType->SetMember(member);
        return pType;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::type_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewType(mdToken mdt, TypeKinds const &kind, ULONG genericParamPos, bool genericArgsSpecified, vector<IType const *> const &genericArgs, TypeProvider const &member) const
    {
        auto pType = m_pMetaInfo->NewTypeCore(m_pClass);
        _ASSERTE(!IsNilToken(mdt) || genericArgsSpecified || kind == TypeKinds::TK_GENERICINST || TypeKinds::TK_BYREF);
        pType->SetToken(mdt);
        pType->SetKind(kind);
        pType->SetGenericParameterPosition(genericParamPos);
        if (genericArgsSpecified)
            pType->SetGenericArguments(genericArgs);
        pType->SetMember(member);
        return pType;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetType(type_metadata_label_type const &type, type_metadata_label_type *&pExistingType) const
    {
        if (m_typeToIndex.find(&type) == m_typeToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_typeToIndex[&type];
            pExistingType = m_pMetaInfo->GetTypeCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterType(TempPtr<type_metadata_label_type> &pType)
    {
        auto &type = *pType;
        m_typeToIndex[&type] = m_pMetaInfo->RegisterTypeCore(pType);
    }
    


    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::method_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member) const
    {
        auto pNewMethod = NewMethod(name, callingConvention, pRetType, paramsSpecified, params, member);

        auto *pExistingMethod = static_cast<method_metadata_label_type *>(nullptr);
        if (!TryGetMethod(*pNewMethod, pExistingMethod))
        {
            pNewMethod.Persist();
            return pNewMethod.Get();
        }
        else
        {
            return pExistingMethod;
        }
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::method_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetMethod(mdToken mdt, CallingConventions const &callingConvention, bool genericArgsSpecified, vector<IType const *> const &genericArgs, COR_ILMETHOD *pILBody, MethodProvider const &member) const
    {
        auto pNewMethod = NewMethod(mdt, callingConvention, genericArgsSpecified, genericArgs, pILBody, member);

        auto *pExistingMethod = static_cast<method_metadata_label_type *>(nullptr);
        if (!TryGetMethod(*pNewMethod, pExistingMethod))
        {
            pNewMethod.Persist();
            return pNewMethod.Get();
        }
        else
        {
            return pExistingMethod;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::method_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member) const
    {
        auto pMethod = m_pMetaInfo->NewMethodCore(m_pClass);
        pMethod->SetName(name);
        pMethod->SetCallingConvention(callingConvention);
        pMethod->SetReturnType(pRetType);
        if (paramsSpecified)
            pMethod->SetParameters(params);
        pMethod->SetMember(member);
        return pMethod;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::method_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewMethod(mdToken mdt, CallingConventions const &callingConvention, bool genericArgsSpecified, vector<IType const *> const &genericArgs, COR_ILMETHOD *pILBody, MethodProvider const &member) const
    {
        auto pMethod = m_pMetaInfo->NewMethodCore(m_pClass);
        _ASSERTE(!IsNilToken(mdt) || genericArgsSpecified);
        pMethod->SetToken(mdt);
        pMethod->SetCallingConvention(callingConvention);
        pMethod->SetILMethodBody(pILBody);
        if (genericArgsSpecified)
            pMethod->SetGenericArguments(genericArgs);
        pMethod->SetMember(member);
        return pMethod;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetMethod(method_metadata_label_type const &method, method_metadata_label_type *&pExistingMethod) const
    {
        if (m_methodToIndex.find(&method) == m_methodToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_methodToIndex[&method];
            pExistingMethod = m_pMetaInfo->GetMethodCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterMethod(TempPtr<method_metadata_label_type> &pMethod)
    {
        auto &method = *pMethod;
        m_methodToIndex[&method] = m_pMetaInfo->RegisterMethodCore(pMethod);
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::method_body_metadata_label_type *BaseAssemblyMetadataPimpl<ApiHolder>::GetMethodBody(COR_ILMETHOD *pILBody, IMethod const *pMethod) const
    {
        auto pNewBody = NewMethodBody(pILBody, pMethod);

        auto *pExistingBody = static_cast<method_body_metadata_label_type *>(nullptr);
        if (!TryGetMethodBody(*pNewBody, pExistingBody))
        {
            pNewBody.Persist();
            return pNewBody.Get();
        }
        else
        {
            return pExistingBody;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::method_body_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewMethodBody(COR_ILMETHOD *pILBody, IMethod const *pMethod) const
    {
        auto pBody = m_pMetaInfo->NewMethodBodyCore(m_pClass);
        pBody->SetILBody(pILBody);
        pBody->SetMethod(pMethod);
        return pBody;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetMethodBody(method_body_metadata_label_type const &body, method_body_metadata_label_type *&pExistingBody) const
    {
        if (m_bodyToIndex.find(&body) == m_bodyToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_bodyToIndex[&body];
            pExistingBody = m_pMetaInfo->GetMethodBodyCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterMethodBody(TempPtr<method_body_metadata_label_type> &pBody)
    {
        auto &body = *pBody;
        m_bodyToIndex[&body] = m_pMetaInfo->RegisterMethodBodyCore(pBody);
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::parameter_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetParameter(ULONG position, IType const *pParamType, ParameterProvider const &member) const
    {
        auto pNewParam = NewParameter(position, pParamType, member);

        auto *pExistingParam = static_cast<parameter_metadata_label_type *>(nullptr);
        if (!TryGetParameter(*pNewParam, pExistingParam))
        {
            pNewParam.Persist();
            return pNewParam.Get();
        }
        else
        {
            return pExistingParam;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::parameter_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewParameter(ULONG position, IType const *pParamType, ParameterProvider const &member) const
    {
        auto pParam = m_pMetaInfo->NewParameterCore(m_pClass);
        pParam->SetPosition(position);
        pParam->SetParameterType(pParamType);
        pParam->SetMember(member);
        return pParam;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetParameter(parameter_metadata_label_type const &param, parameter_metadata_label_type *&pExistingParam) const
    {
        if (m_paramToIndex.find(&param) == m_paramToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_paramToIndex[&param];
            pExistingParam = m_pMetaInfo->GetParameterCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterParameter(TempPtr<parameter_metadata_label_type> &pParam)
    {
        auto &param = *pParam;
        m_paramToIndex[&param] = m_pMetaInfo->RegisterParameterCore(pParam);
    }
    


    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::local_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetLocal(ULONG index, IType const *pLocalType, IMethodBody const *pBody) const
    {
        auto pNewLocal = NewLocal(index, pLocalType, pBody);

        auto *pExistingLocal = static_cast<local_metadata_label_type *>(nullptr);
        if (!TryGetLocal(*pNewLocal, pExistingLocal))
        {
            pNewLocal.Persist();
            return pNewLocal.Get();
        }
        else
        {
            return pExistingLocal;
        }
    }


    
    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::local_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewLocal(ULONG index, IType const *pLocalType, IMethodBody const *pBody) const
    {
        auto pLocal = m_pMetaInfo->NewLocalCore(m_pClass);
        pLocal->SetLocalIndex(index);
        pLocal->SetLocalType(pLocalType);
        pLocal->SetMethodBody(pBody);
        return pLocal;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetLocal(local_metadata_label_type const &local, local_metadata_label_type *&pExistingLocal) const
    {
        if (m_localToIndex.find(&local) == m_localToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_localToIndex[&local];
            pExistingLocal = m_pMetaInfo->GetLocalCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterLocal(TempPtr<local_metadata_label_type> &pLocal)
    {
        auto &local = *pLocal;
        m_localToIndex[&local] = m_pMetaInfo->RegisterLocalCore(pLocal);
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::property_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetProperty(mdToken mdt, PropertyProvider const &member) const
    {
        auto pNewProp = NewProperty(mdt, member);

        auto *pExistingProp = static_cast<property_metadata_label_type *>(nullptr);
        if (!TryGetProperty(*pNewProp, pExistingProp))
        {
            pNewProp.Persist();
            return pNewProp.Get();
        }
        else
        {
            return pExistingProp;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::property_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewProperty(mdToken mdt, PropertyProvider const &member) const
    {
        auto pProp = m_pMetaInfo->NewPropertyCore(m_pClass);
        pProp->SetToken(mdt);
        pProp->SetMember(member);
        return pProp;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetProperty(property_metadata_label_type const &prop, property_metadata_label_type *&pExistingProp) const
    {
        if (m_propToIndex.find(&prop) == m_propToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_propToIndex[&prop];
            pExistingProp = m_pMetaInfo->GetPropertyCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterProperty(TempPtr<property_metadata_label_type> &pProp)
    {
        auto &prop = *pProp;
        m_propToIndex[&prop] = m_pMetaInfo->RegisterPropertyCore(pProp);
    }
    


    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::field_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetField(mdToken mdt, FieldProvider const &member) const
    {
        auto pNewField = NewField(mdt, member);

        auto *pExistingField = static_cast<field_metadata_label_type *>(nullptr);
        if (!TryGetField(*pNewField, pExistingField))
        {
            pNewField.Persist();
            return pNewField.Get();
        }
        else
        {
            return pExistingField;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::field_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewField(mdToken mdt, FieldProvider const &member) const
    {
        auto pField = m_pMetaInfo->NewFieldCore(m_pClass);
        pField->SetToken(mdt);
        pField->SetMember(member);
        return pField;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetField(field_metadata_label_type const &field, field_metadata_label_type *&pExistingField) const
    {
        if (m_fieldToIndex.find(&field) == m_fieldToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_fieldToIndex[&field];
            pExistingField = m_pMetaInfo->GetFieldCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterField(TempPtr<field_metadata_label_type> &pField)
    {
        auto &field = *pField;
        m_fieldToIndex[&field] = m_pMetaInfo->RegisterFieldCore(pField);
    }



    template<class ApiHolder>    
    typename BaseAssemblyMetadataPimpl<ApiHolder>::custom_attribute_metadata_label_type const *BaseAssemblyMetadataPimpl<ApiHolder>::GetCustomAttribute(mdToken mdt, CustomAttributeProvider const &member) const
    {
        auto pNewCas = NewCustomAttribute(mdt, member);

        auto *pExistingCas = static_cast<custom_attribute_metadata_label_type *>(nullptr);
        if (!TryGetCustomAttribute(*pNewCas, pExistingCas))
        {
            pNewCas.Persist();
            return pNewCas.Get();
        }
        else
        {
            return pExistingCas;
        }
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyMetadataPimpl<ApiHolder>::custom_attribute_metadata_label_type> BaseAssemblyMetadataPimpl<ApiHolder>::NewCustomAttribute(mdToken mdt, CustomAttributeProvider const &member) const
    {
        auto pCa = m_pMetaInfo->NewCustomAttributeCore(m_pClass);
        pCa->SetToken(mdt);
        pCa->SetMember(member);
        return pCa;
    }



    template<class ApiHolder>    
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetCustomAttribute(custom_attribute_metadata_label_type const &cas, custom_attribute_metadata_label_type *&pExistingCas) const
    {
        if (m_casToIndex.find(&cas) == m_casToIndex.end())
        {
            return false;
        }
        else
        {
            auto index = m_casToIndex[&cas];
            pExistingCas = m_pMetaInfo->GetCustomAttributeCore(index);
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterCustomAttribute(TempPtr<custom_attribute_metadata_label_type> &pCas)
    {
        auto &cas = *pCas;
        m_casToIndex[&cas] = m_pMetaInfo->RegisterCustomAttributeCore(pCas);
    }



    template<class ApiHolder>    
    IMetaDataAssemblyImport &BaseAssemblyMetadataPimpl<ApiHolder>::GetCOMMetaDataAssemblyImport() const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pOpeningAsm == nullptr)
        {
            if (m_pComMetaAsmImp.p == nullptr)
            {
                auto &comMetaImp = m_pClass->GetCOMMetaDataImport();
                auto hr = comMetaImp.QueryInterface(IID_IMetaDataAssemblyImport, 
                                                    reinterpret_cast<void **>(&m_pComMetaAsmImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaAsmImp;
        }
        else
        {
            return m_pOpeningAsm->GetCOMMetaDataAssemblyImport();
        }
    }
    
    
    template<class ApiHolder>    
    IMetaDataImport2 &BaseAssemblyMetadataPimpl<ApiHolder>::GetCOMMetaDataImport() const
    {
        using boost::filesystem::path;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pOpeningAsm == nullptr)
        {
            if (m_pComMetaImp.p == nullptr)
            {
                auto &comMetaDisp = m_pDisp->GetCOMMetaDataDispenser();

                auto const &asmPath = m_pClass->GetAssemblyFilePath();
                auto openFlags = m_pClass->GetOpenFlags();
                auto hr = comMetaDisp.OpenScope(asmPath.c_str(), openFlags, 
                                                IID_IMetaDataImport2, reinterpret_cast<IUnknown **>(&m_pComMetaImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaImp.p;
        }
        else
        {
            return m_pOpeningAsm->GetCOMMetaDataImport();
        }
    }
    
    
    
    Platform ToPlatform(ProcessorArchitecture const &procArchs)
    {
        using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

        switch (procArchs.Value())
        {
            case ProcessorArchitecture::PA_INTEL:
                return Platform::PF_I386;
            case ProcessorArchitecture::PA_IA64:
                return Platform::PF_IA64;
            case ProcessorArchitecture::PA_AMD64:
                return Platform::PF_AMD64;
            case ProcessorArchitecture::PA_MSIL:
                return Platform::PF_MSIL;
            default:
                BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
        }
    }



    template<class ApiHolder>    
    path const &BaseAssemblyMetadataPimpl<ApiHolder>::GetAssemblyFilePath() const
    {
        using boost::adaptors::filtered;
        using Urasandesu::Swathe::Fusion::NewAssemblyNameFlags;
        using Urasandesu::Swathe::Fusion::AssemblyCacheFlags; 
        

        if (m_asmPath.empty())
        {
            _ASSERTE(!m_fullName.empty());

            auto pCondition = m_pFuInfo->NewAssemblyName(m_fullName, NewAssemblyNameFlags::NANF_CANOF_PARSE_DISPLAY_NAME);
            auto pAsmNames = m_pFuInfo->EnumerateAssemblyName(pCondition, AssemblyCacheFlags::ACF_GAC);
            
            typedef unordered_map<Platform, AutoPtr<assembly_name_label_type const>, Hash<Platform>, EqualTo<Platform> > AssemblyNameMap;
            typedef AssemblyNameMap::value_type Value;

            auto candidates = AssemblyNameMap();
            BOOST_FOREACH (auto const &pAsmName, *pAsmNames)
                candidates[pAsmName->GetPlatform()] = pAsmName;

            if (candidates.empty())
                ResolveAssemblyPathByCurrentDirectory(this, pCondition->GetName(), m_asmPath);
            else
                ResolveAssemblyPathByGAC(this, candidates, m_asmPath);
        }
        return m_asmPath;
    }
    
    
    
    template<class ApiHolder>    
    DWORD BaseAssemblyMetadataPimpl<ApiHolder>::GetOpenFlags() const
    {
        return m_openFlags;
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetOpenFlags(DWORD openFlags)
    {
        _ASSERTE(openFlags != ofRead);
        _ASSERTE(m_openFlags == ofRead);

        m_openFlags = openFlags;
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetOpeningAssembly(assembly_metadata_label_type const *pOpeningAsm)
    {
        m_pOpeningAsm = pOpeningAsm;    // TODO: うーん・・・良くない考え！！Def と Ref の関係、COM インターフェースを絡めて整理したほうがいいんじゃない？？
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::SetProcessorArchitectures(vector<ProcessorArchitecture> const &procArchs)
    {
        _ASSERTE(m_procArchs.empty());
        _ASSERTE(!procArchs.empty());
        m_procArchs = procArchs;
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillAssemblyProperties(assembly_metadata_pimpl_label_type const *_this, mdToken mdtTarget, wstring &name, AutoPtr<IStrongNameKey const> &pSnKey, ASSEMBLYMETADATA &amd,  vector<WCHAR> &locale, vector<OSINFO> &os, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags)
    {
        using Urasandesu::CppAnonym::Collections::ResizeIfAvailable;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto const *pSnInfo = _this->m_pSnInfo;
        auto &comMetaAsmImp = _this->GetCOMMetaDataAssemblyImport();

        auto hr = E_FAIL;
        auto *pPubKeyBlob = static_cast<void *>(nullptr);
        auto pubKeyBlobSize = 0ul;
        auto wzname = vector<WCHAR>();
        auto wznameSize = 0ul;
        ::ZeroMemory(&amd, sizeof(ASSEMBLYMETADATA));
        auto dwasmFlags = 0ul;
        hr = comMetaAsmImp.GetAssemblyProps(mdtTarget, NULL, NULL, NULL, NULL, 0, &wznameSize, &amd, &dwasmFlags);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        wzname.resize(wznameSize);
        amd.szLocale = ResizeIfAvailable(amd.cbLocale, locale);
        amd.rOS = ResizeIfAvailable(amd.ulOS, os);
        amd.rProcessor = reinterpret_cast<DWORD *>(ResizeIfAvailable(amd.ulProcessor, procArchs));
        hr = comMetaAsmImp.GetAssemblyProps(mdtTarget, const_cast<const void**>(&pPubKeyBlob), &pubKeyBlobSize, NULL, &wzname[0], wznameSize, NULL, &amd, NULL);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = &wzname[0];
        asmFlags = AssemblyFlags(dwasmFlags);
        pSnKey = pSnInfo->NewStrongNameKey(*reinterpret_cast<PublicKeyBlob *>(pPubKeyBlob), pubKeyBlobSize);
        if (!amd.rProcessor)
            FillPlatform(_this, amd, procArchs, asmFlags);
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillAssemblyRefProperties(assembly_metadata_pimpl_label_type const *_this, mdToken mdtTarget, wstring &name, AutoPtr<IStrongNameKey const> &pSnKey, ASSEMBLYMETADATA &amd,  vector<WCHAR> &locale, vector<OSINFO> &os, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags)
    {
        using Urasandesu::CppAnonym::Collections::ResizeIfAvailable;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto const *pSnInfo = _this->m_pSnInfo;
        auto &comMetaAsmImp = _this->GetCOMMetaDataAssemblyImport();

        auto hr = E_FAIL;
        auto *pPubKeyOrToken = static_cast<void *>(nullptr);
        auto pubKeyOrTokenSize = 0ul;
        auto wzname = vector<WCHAR>();
        auto wznameSize = 0ul;
        ::ZeroMemory(&amd, sizeof(ASSEMBLYMETADATA));
        auto *pHashValue = static_cast<void *>(nullptr);
        auto hashValueSize = 0ul;
        auto dwasmFlags = 0ul;
        hr = comMetaAsmImp.GetAssemblyRefProps(mdtTarget, nullptr, nullptr, nullptr, 0, &wznameSize, &amd, nullptr, nullptr, &dwasmFlags);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        wzname.resize(wznameSize);
        amd.szLocale = ResizeIfAvailable(amd.cbLocale, locale);
        amd.rOS = ResizeIfAvailable(amd.ulOS, os);
        amd.rProcessor = reinterpret_cast<DWORD *>(ResizeIfAvailable(amd.ulProcessor, procArchs));
        hr = comMetaAsmImp.GetAssemblyRefProps(mdtTarget, const_cast<void const **>(&pPubKeyOrToken), &pubKeyOrTokenSize, &wzname[0], wznameSize, nullptr, &amd, nullptr, nullptr, nullptr);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = &wzname[0];
        asmFlags = AssemblyFlags(dwasmFlags);
        if ((asmFlags & AssemblyFlags::AF_PUBLIC_KEY) != 0)
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        else
            pSnKey = pSnInfo->NewStrongNameKeyWithToken(pPubKeyOrToken, pubKeyOrTokenSize);
        if (!amd.rProcessor)
            FillPlatform(_this, amd, procArchs, asmFlags);
    }



    //template<class ApiHolder>    
    //void BaseAssemblyMetadataPimpl<ApiHolder>::FillAttributes(assembly_metadata_pimpl_label_type const *_this, vector<ICustomAttribute const *> &cas)
    //{
    //    using boost::array;
    //    using Urasandesu::CppAnonym::CppAnonymCOMException;

    //    auto *pClass = _this->m_pClass;
    //    auto *pDisp = _this->m_pDisp;

    //    auto &comMetaImp = pClass->GetCOMMetaDataImport();

    //    auto hEnum = static_cast<HCORENUM>(nullptr);
    //        BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
    //        {
    //            if (hEnum)
    //                comMetaImp.CloseEnum(hEnum);
    //        }
    //        BOOST_SCOPE_EXIT_END
    //    auto mdtTarget = pClass->GetToken();
    //    auto mdcas = array<mdCustomAttribute, 16>();
    //    auto count = 0ul;
    //    auto hr = E_FAIL;
    //    do
    //    {
    //        hr = comMetaImp.EnumCustomAttributes(&hEnum, mdtTarget, 0, mdcas.c_array(), mdcas.size(), &count);
    //        if (FAILED(hr))
    //            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

    //        cas.reserve(cas.size() + count);
    //        for (auto i = 0u; i < count; ++i)
    //        {
    //            auto pCas = pClass->GetCustomAttribute(mdcas[i], static_cast<IAssembly const *>(pClass));
    //            cas.push_back(pCas);
    //        }
    //    } while (0 < count);
    //}



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillPlatform(assembly_metadata_pimpl_label_type const *_this, ASSEMBLYMETADATA &amd, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags)
    {
        using Urasandesu::CppAnonym::Collections::ResizeIfAvailable;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto &comMetaImp = _this->GetCOMMetaDataImport();
        
        auto dwPEKind = 0ul;
        auto dwMachine = 0ul;
        auto hr = comMetaImp.GetPEKind(&dwPEKind, &dwMachine);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        amd.ulProcessor = 2ul;
        amd.rProcessor = reinterpret_cast<DWORD *>(ResizeIfAvailable(amd.ulProcessor, procArchs));
        if (dwPEKind & pe32Plus)
        {
            if (dwMachine != IMAGE_FILE_MACHINE_I386)
            {
                if (dwMachine == IMAGE_FILE_MACHINE_IA64)
                {
                    procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_IA64);
                    procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
                    asmFlags |= AssemblyFlags::AF_PA_IA64;
                }
                else if (dwMachine == IMAGE_FILE_MACHINE_AMD64)
                {
                    procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64);
                    procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
                    asmFlags |= AssemblyFlags::AF_PA_AMD64;
                }
            }
            else
            {
                if (dwPEKind & peILonly)
                {
                    procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
                    auto sysInfo = SYSTEM_INFO();
                    ::ZeroMemory(&sysInfo, sizeof(SYSTEM_INFO));
                    ::GetSystemInfo(&sysInfo);
                    procArchs[1] = ProcessorArchitecture(sysInfo.wProcessorArchitecture);
                    asmFlags |= AssemblyFlags::AF_PA_MSIL;
                }
            }
        }
        else
        {
            if (dwMachine == IMAGE_FILE_MACHINE_I386)
            {
                if (dwPEKind & pe32BitRequired)
                {
                    procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_INTEL);
                    procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
                    asmFlags |= AssemblyFlags::AF_PA_X86;
                }
                else if (dwPEKind & peILonly)
                {
                    procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
                    auto sysInfo = SYSTEM_INFO();
                    ::ZeroMemory(&sysInfo, sizeof(SYSTEM_INFO));
                    ::GetSystemInfo(&sysInfo);
                    procArchs[1] = ProcessorArchitecture(sysInfo.wProcessorArchitecture);
                    asmFlags |= AssemblyFlags::AF_PA_MSIL;
                }
                else
                {
                    procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_INTEL);
                    procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
                    asmFlags |= AssemblyFlags::AF_PA_X86;
                }
            }
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::ResolveAssemblyPathByCurrentDirectory(assembly_metadata_pimpl_label_type const *_this, wstring const &name, path &asmPath)
    {
        asmPath = name + L".dll";
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::ResolveAssemblyPathByGAC(assembly_metadata_pimpl_label_type const *_this, unordered_map<Platform, AutoPtr<assembly_name_label_type const>, Hash<Platform>, EqualTo<Platform> > const &candidates, path &asmPath)
    {
        using boost::adaptors::transformed;        
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        using Urasandesu::CppAnonym::Collections::FindIf;
        using Urasandesu::Swathe::Fusion::AssemblyQueryTypes;

        auto const *pFuInfo = _this->m_pFuInfo;

        if (candidates.size() == 1)
        {
            auto pAsmName = (*candidates.begin()).second;
            auto pAsmCache = pFuInfo->NewAssemblyCache();
            auto pAsmInfo = pAsmCache->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, pAsmName->GetFullName());
            asmPath = pAsmInfo->GetAssemblyPath();
        }
        else
        {
            auto const &procArchs = _this->m_procArchs;

            _ASSERTE(!procArchs.empty());
            auto isTarget = [&](Platform const &platform) { return candidates.find(platform) != candidates.end(); };
            auto result = FindIf(procArchs | transformed(ToPlatform), isTarget);
            if (!result)
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(ERROR_FILE_NOT_FOUND));

            auto pAsmName = candidates.at(*result);
            auto pAsmCache = pFuInfo->NewAssemblyCache();
            auto pAsmInfo = pAsmCache->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, pAsmName->GetFullName());
            asmPath = pAsmInfo->GetAssemblyPath();
        }
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYMETADATAPIMPL_HPP

