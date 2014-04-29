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
        m_orderedTypesInit(false), 
        m_asmFlags(AssemblyFlags::AF_UNREACHED),
        m_refAsmsInit(false), 
        m_openFlags(ofRead), 
        m_pOpeningAsm(nullptr), 
        m_pSrcAsm(nullptr)
    { }

    
    
    template<class ApiHolder>    
    BaseAssemblyMetadataPimpl<ApiHolder>::~BaseAssemblyMetadataPimpl()
    { 
        BOOST_FOREACH (auto const &pMod, m_mods)
            m_pMetaInfo->UnloadModuleCore(pMod);

        BOOST_FOREACH (auto const &pType, m_types)
            m_pMetaInfo->UnloadTypeCore(pType);

        BOOST_FOREACH (auto const &pMethod, m_methods)
            m_pMetaInfo->UnloadMethodCore(pMethod);

        BOOST_FOREACH (auto const &pParam, m_params)
            m_pMetaInfo->UnloadParameterCore(pParam);

        BOOST_FOREACH (auto const &pLocal, m_locals)
            m_pMetaInfo->UnloadLocalCore(pLocal);

        BOOST_FOREACH (auto const &pBody, m_bodies)
            m_pMetaInfo->UnloadMethodBodyCore(pBody);

        BOOST_FOREACH (auto const &pProp, m_props)
            m_pMetaInfo->UnloadPropertyCore(pProp);

        BOOST_FOREACH (auto const &pField, m_fields)
            m_pMetaInfo->UnloadFieldCore(pField);

        BOOST_FOREACH (auto const &pCas, m_cass)
            m_pMetaInfo->UnloadCustomAttributeCore(pCas);
    }
    
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
        CPPANONYM_LOG_FUNCTION();

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
        if (m_asmFlags == AssemblyFlags::AF_UNREACHED)  // StrongNameKey property has the potential to be incomplete, so we use the Flags property instead of it
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtAssembly)
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_asmFlags);
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
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_asmFlags);
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
                FillAssemblyRefProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_asmFlags);
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
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_asmFlags);
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
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_asmFlags);
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        if (!(m_asmFlags & AssemblyFlags::AF_PA_MASK))
        {
            FillPlatformByCOMMetaDataImport(&GetCOMMetaDataImport(), m_amd, m_procArchs, m_asmFlags);
            if (m_procArchs.size() != 2 || m_procArchs[1] == ProcessorArchitecture::PA_UNKNOWN)
                FillPlatformByHeuristicAlgorithm(this, m_amd, m_procArchs, m_asmFlags);
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
        return m_pClass->GetType(mdTokenNil, TypeKinds::TK_VAR, genericParamPos, true, MetadataSpecialValues::EMPTY_TYPES, GetMainModule());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyMetadataPimpl<ApiHolder>::GetGenericMethodParameter(ULONG genericParamPos) const
    {
        return m_pClass->GetType(mdTokenNil, TypeKinds::TK_MVAR, genericParamPos, true, MetadataSpecialValues::EMPTY_TYPES, GetMainModule());
    }



    template<class ApiHolder>    
    vector<ProcessorArchitecture> const &BaseAssemblyMetadataPimpl<ApiHolder>::GetProcessorArchitectures() const
    {
        if (m_asmFlags == AssemblyFlags::AF_UNREACHED) // ProcessorArchitectures can't validate whether it has already initialized, so we use the Flags property instead of it. Flags property has value necessarily.
        {
            auto mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtAssembly)
                FillAssemblyProperties(this, mdtTarget, m_name, m_pSnKey, m_amd, m_locale, m_os, m_asmFlags);
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        if (!(m_asmFlags & AssemblyFlags::AF_PA_MASK))
        {
            FillPlatformByCOMMetaDataImport(&GetCOMMetaDataImport(), m_amd, m_procArchs, m_asmFlags);
            if (m_procArchs.size() != 2 || m_procArchs[1] == ProcessorArchitecture::PA_UNKNOWN)
                FillPlatformByHeuristicAlgorithm(this, m_amd, m_procArchs, m_asmFlags);
        }
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
                    hr = comMetaImp.EnumCustomAttributes(&hEnum, mdtTarget, 0, mdcas.c_array(), static_cast<ULONG>(mdcas.size()), &count);
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
        isTarget = [pAttributeType](ICustomAttribute const *pCas) { return pCas->Equals(pAttributeType); };
        return cas | filtered(isTarget);
    }



    template<class ApiHolder>    
    ITypePtrRange BaseAssemblyMetadataPimpl<ApiHolder>::GetTypes() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_orderedTypesInit)
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
                    hr = comMetaImp.EnumTypeDefs(&hEnum, mdtds.c_array(), static_cast<ULONG>(mdtds.size()), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_orderedTypes.reserve(m_orderedTypes.size() + count);
                    for (auto i = 0u; i < count; ++i)
                    {
                        auto pType = m_pClass->GetType(mdtds[i]);
                        m_orderedTypes.push_back(pType);
                    }
                } while (0 < count);
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }

            m_orderedTypesInit = true;
        }

        return m_orderedTypes;
    }



    template<class ApiHolder>    
    AutoPtr<IPortableExecutableReader const> const &BaseAssemblyMetadataPimpl<ApiHolder>::GetPortableExecutableReader() const
    {
        if (!m_pReader)
            m_pReader = m_pPEInfo->CreateReader(&GetCOMMetaDataImport(), GetAssemblyFilePath());
        return m_pReader;
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetModule(module_metadata_label_type &mod, module_metadata_label_type *&pExistingMod) const
    {
        auto result = m_mods.find(&mod);
        if (result == m_mods.end())
        {
            return false;
        }
        else
        {
            pExistingMod = *result;
            return true;
        }
    }
    


    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterModule(TempPtr<module_metadata_label_type> &pMod)
    {
        m_pMetaInfo->RegisterModuleCore(pMod);
        m_mods.insert(pMod.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetType(type_metadata_label_type &type, type_metadata_label_type *&pExistingType) const
    {
        auto result = m_types.find(&type);
        if (result == m_types.end())
        {
            return false;
        }
        else
        {
            pExistingType = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterType(TempPtr<type_metadata_label_type> &pType)
    {
        m_pMetaInfo->RegisterTypeCore(pType);
        m_types.insert(pType.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetMethod(method_metadata_label_type &method, method_metadata_label_type *&pExistingMethod) const
    {
        auto result = m_methods.find(&method);
        if (result == m_methods.end())
        {
            return false;
        }
        else
        {
            pExistingMethod = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterMethod(TempPtr<method_metadata_label_type> &pMethod)
    {
        m_pMetaInfo->RegisterMethodCore(pMethod);
        m_methods.insert(pMethod.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetMethodBody(method_body_metadata_label_type &body, method_body_metadata_label_type *&pExistingBody) const
    {
        auto result = m_bodies.find(&body);
        if (result == m_bodies.end())
        {
            return false;
        }
        else
        {
            pExistingBody = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterMethodBody(TempPtr<method_body_metadata_label_type> &pBody)
    {
        m_pMetaInfo->RegisterMethodBodyCore(pBody);
        m_bodies.insert(pBody.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetParameter(parameter_metadata_label_type &param, parameter_metadata_label_type *&pExistingParam) const
    {
        auto result = m_params.find(&param);
        if (result == m_params.end())
        {
            return false;
        }
        else
        {
            pExistingParam = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterParameter(TempPtr<parameter_metadata_label_type> &pParam)
    {
        m_pMetaInfo->RegisterParameterCore(pParam);
        m_params.insert(pParam.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetLocal(local_metadata_label_type &local, local_metadata_label_type *&pExistingLocal) const
    {
        auto result = m_locals.find(&local);
        if (result == m_locals.end())
        {
            return false;
        }
        else
        {
            pExistingLocal = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterLocal(TempPtr<local_metadata_label_type> &pLocal)
    {
        m_pMetaInfo->RegisterLocalCore(pLocal);
        m_locals.insert(pLocal.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetProperty(property_metadata_label_type &prop, property_metadata_label_type *&pExistingProp) const
    {
        auto result = m_props.find(&prop);
        if (result == m_props.end())
        {
            return false;
        }
        else
        {
            pExistingProp = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterProperty(TempPtr<property_metadata_label_type> &pProp)
    {
        m_pMetaInfo->RegisterPropertyCore(pProp);
        m_props.insert(pProp.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetField(field_metadata_label_type &field, field_metadata_label_type *&pExistingField) const
    {
        auto result = m_fields.find(&field);
        if (result == m_fields.end())
        {
            return false;
        }
        else
        {
            pExistingField = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterField(TempPtr<field_metadata_label_type> &pField)
    {
        m_pMetaInfo->RegisterFieldCore(pField);
        m_fields.insert(pField.Get());
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
    bool BaseAssemblyMetadataPimpl<ApiHolder>::TryGetCustomAttribute(custom_attribute_metadata_label_type &cas, custom_attribute_metadata_label_type *&pExistingCas) const
    {
        auto result = m_cass.find(&cas);
        if (result == m_cass.end())
        {
            return false;
        }
        else
        {
            pExistingCas = *result;
            return true;
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::RegisterCustomAttribute(TempPtr<custom_attribute_metadata_label_type> &pCas)
    {
        m_pMetaInfo->RegisterCustomAttributeCore(pCas);
        m_cass.insert(pCas.Get());
    }



    template<class ApiHolder>    
    IAssemblyPtrRange BaseAssemblyMetadataPimpl<ApiHolder>::GetAssemblyReferences() const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_refAsmsInit)
            return m_refAsms;
        
        auto mdtTarget = GetToken();
        switch (TypeFromToken(mdtTarget))
        {
            case mdtAssembly:
                {
                    auto asmRefs = vector<mdAssemblyRef>();
                    m_pClass->FillAssemblyRefs(asmRefs);
                    
                    m_refAsms.reserve(asmRefs.size());
                    BOOST_FOREACH (auto const &mdar, asmRefs)
                        m_refAsms.push_back(GetAssemblyReference(mdar));
                }
                break;

            default:
                auto oss = std::wostringstream();
                oss << boost::wformat(L"mdtTarget: 0x%|1$08X|") % mdtTarget;
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
        }
        m_refAsmsInit = true;
        return m_refAsms;
    }



    template<class ApiHolder>    
    IAssembly const *BaseAssemblyMetadataPimpl<ApiHolder>::GetAssemblyReference(wstring const &fullName) const
    {
        using boost::adaptors::filtered;
        using boost::copy;
        using std::back_inserter;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(!fullName.empty());
        
        auto refAsms = m_pClass->GetAssemblyReferences();
        auto results = vector<IAssembly const *>();
        auto isTarget = [&](IAssembly const *pAsm) { return pAsm->GetFullName() == fullName; };
        copy(refAsms | filtered(isTarget), back_inserter(results));
        
        if (results.empty())
            return nullptr;
        
        if (1 < results.size())
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(CLDB_E_RECORD_DUPLICATE));
        
        return results[0];
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyMetadataPimpl<ApiHolder>::GetTypeReference(IType const *pType) const
    {
        if (!pType)
            return nullptr;
        
        auto const *pTargetAsm = pType->GetAssembly();
        if (pTargetAsm == m_pClass)
            return pType;
        
        auto mdtTarget = mdTokenNil;
        if (pType->IsNested())
        {
            auto const *pDeclaringType = pType->GetDeclaringType();
            auto const *pRefType = GetTypeReference(pDeclaringType);
            if (!pRefType)
                return nullptr;
            
            mdtTarget = pRefType->GetToken();
        }
        else
        {
            auto const *pRefAsm = GetAssemblyReference(pTargetAsm->GetFullName());
            if (!pRefAsm)
                return nullptr;
            
            mdtTarget = pRefAsm->GetToken();
        }
        
        auto typeRefs = vector<mdTypeRef>();
        m_pClass->FillTypeRefs(pType->GetFullName(), typeRefs);
        if (typeRefs.empty())
            return nullptr;
        
        _ASSERTE(typeRefs.size() == 1);   // This validation will always pass because any types don't have the overloading.
        return GetType(typeRefs[0]);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillAssemblyRefs(vector<mdAssemblyRef> &asmRefs) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(TypeFromToken(GetToken()) == mdtAssembly);
        
        auto &comMetaAsmImp = GetCOMMetaDataAssemblyImport();
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&comMetaAsmImp))
        {
            if (hEnum)
                comMetaAsmImp.CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdars = array<mdAssemblyRef, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = comMetaAsmImp.EnumAssemblyRefs(&hEnum, mdars.c_array(), static_cast<ULONG>(mdars.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            asmRefs.reserve(asmRefs.size() + count);
            for (auto i = 0u; i < count; ++i)
                asmRefs.push_back(mdars[i]);
        } while (0 < count);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillTypeRefs(vector<mdTypeRef> &typeRefs) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto &comMetaImp = GetCOMMetaDataImport();
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
        {
            if (hEnum)
                comMetaImp.CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdtrs = array<mdTypeRef, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = comMetaImp.EnumTypeRefs(&hEnum, mdtrs.c_array(), static_cast<ULONG>(mdtrs.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            typeRefs.reserve(typeRefs.size() + count);
            for (auto i = 0u; i < count; ++i)
                typeRefs.push_back(mdtrs[i]);
        } while (0 < count);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillTypeRefs(wstring const &fullName, vector<mdTypeRef> &typeRefs) const
    {
        auto _typeRefs = vector<mdTypeRef>();
        FillTypeRefs(_typeRefs);
        
        BOOST_FOREACH (auto const &mdtr, _typeRefs)
        {
            auto _fullName = wstring();
            auto mdtResolutionScope = mdTokenNil;
            FillTypeRefProperties(mdtr, _fullName, mdtResolutionScope);
            if (fullName == _fullName)
                typeRefs.push_back(mdtr);
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillTypeDefMethodDefs(mdTypeDef mdtTarget, wstring const &name, vector<mdMethodDef> &methodDefs) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(!IsNilToken(mdtTarget));
        
        auto &comMetaImp = GetCOMMetaDataImport();
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
        {
            if (hEnum)
                comMetaImp.CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdmds = array<mdMethodDef, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = comMetaImp.EnumMethodsWithName(&hEnum, mdtTarget, name.c_str(), mdmds.c_array(), static_cast<ULONG>(mdmds.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            methodDefs.reserve(methodDefs.size() + count);
            for (auto i = 0u; i < count; ++i)
                methodDefs.push_back(mdmds[i]);
        } while (0 < count);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillTypeDefProperties(mdToken mdtTarget, wstring &fullName, TypeAttributes &attr, mdToken &mdtExt) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(IsNilToken(mdtExt));
        
        auto &comMetaImp = GetCOMMetaDataImport();

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto dwattr = 0ul;
        auto length = 0ul;
        auto hr = comMetaImp.GetTypeDefProps(mdtTarget, wzname.c_array(), static_cast<ULONG>(wzname.size()), &length, &dwattr, &mdtExt);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        fullName = wzname.data();
        attr = TypeAttributes(dwattr);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillTypeRefProperties(mdToken mdtTarget, wstring &fullName, mdToken &mdtResolutionScope) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(IsNilToken(mdtResolutionScope));
        
        auto &comMetaImp = GetCOMMetaDataImport();

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto length = 0ul;
        auto hr = comMetaImp.GetTypeRefProps(mdtTarget, &mdtResolutionScope, wzname.c_array(), static_cast<ULONG>(wzname.size()), &length);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        fullName = wzname.data();
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillMethodDefProperties(mdMethodDef mdtTarget, mdTypeDef &mdtOwner, wstring &name, MethodAttributes &attr, Signature &sig, ULONG &codeRva, MethodImplAttributes &implFlags) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(sig.GetBlob().empty());

        auto &comMetaImp = GetCOMMetaDataImport();

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto wznameLength = 0ul;
        auto dwattr = 0ul;
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto dwimplFlags = 0ul;
        auto hr = comMetaImp.GetMethodProps(mdtTarget, &mdtOwner, wzname.c_array(), static_cast<ULONG>(wzname.size()), &wznameLength, &dwattr, &pSig, &sigLength, &codeRva, &dwimplFlags);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        attr = MethodAttributes(dwattr);
        sig.SetBlob(pSig, sigLength);
        implFlags = MethodImplAttributes(dwimplFlags);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillMethodSpecProperties(mdMethodSpec mdtTarget, mdToken &mdtOwner, Signature &sig) const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(sig.GetBlob().empty());

        auto &comMetaImp = GetCOMMetaDataImport();

        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto hr = comMetaImp.GetMethodSpecProps(mdtTarget, &mdtOwner, &pSig, &sigLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillFieldDefProperties(mdFieldDef mdtTarget, mdToken &mdtOwner, wstring &name, FieldAttributes &attr, Signature &sig) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(sig.GetBlob().empty());

        auto &comMetaImp = GetCOMMetaDataImport();

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto wznameLength = 0ul;
        auto dwattr = 0ul;
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto cplusTypeFlag = 0ul;
        auto const *pDefaultValue = static_cast<UVCP_CONSTANT>(nullptr);
        auto defaultValueLength = 0ul;
        auto hr = comMetaImp.GetFieldProps(mdtTarget, &mdtOwner, wzname.c_array(), static_cast<ULONG>(wzname.size()), &wznameLength, &dwattr, &pSig, &sigLength, &cplusTypeFlag, &pDefaultValue, &defaultValueLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        attr = FieldAttributes(dwattr);
        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillScopeMemberRefs(mdToken mdtTarget, vector<mdMemberRef> &memberRefs) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(!IsNilToken(mdtTarget));
        
        auto &comMetaImp = GetCOMMetaDataImport();
        
        auto hEnum = HCORENUM();
        BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
        {
            if (hEnum)
                comMetaImp.CloseEnum(hEnum);
        }
        BOOST_SCOPE_EXIT_END
        auto mdmrs = array<mdMemberRef, 16>();
        auto count = 0ul;
        auto hr = E_FAIL;
        do
        {
            hr = comMetaImp.EnumMemberRefs(&hEnum, mdtTarget, mdmrs.c_array(), static_cast<ULONG>(mdmrs.size()), &count);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            memberRefs.reserve(memberRefs.size() + count);
            for (auto i = 0u; i < count; ++i)
                memberRefs.push_back(mdmrs[i]);
        } while (0 < count);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillScopeMemberRefs(mdToken mdtTarget, wstring const &name, vector<mdMemberRef> &memberRefs) const
    {
        _ASSERTE(!IsNilToken(mdtTarget));
        
        auto _memberRefs = vector<mdMemberRef>();
        FillScopeMemberRefs(mdtTarget, _memberRefs);
        
        BOOST_FOREACH (auto const &mdmr, _memberRefs)
        {
            auto mdtOwner = mdTokenNil;
            auto _name = wstring();
            auto sig = Signature();
            FillMemberRefProperties(mdmr, mdtOwner, _name, sig);
            if (name == _name)
                memberRefs.push_back(mdmr);
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillMemberRefProperties(mdMemberRef mdtTarget, mdToken &mdtOwner, wstring &name, Signature &sig) const
    {
        using boost::array;
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(sig.GetBlob().empty());
        
        auto &comMetaImp = GetCOMMetaDataImport();

        auto wzname = array<WCHAR, MAX_SYM_NAME>();
        auto wznameLength = 0ul;
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto hr = comMetaImp.GetMemberRefProps(mdtTarget, &mdtOwner, wzname.c_array(), static_cast<ULONG>(wzname.size()), &wznameLength, &pSig, &sigLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = wzname.data();
        sig.SetBlob(pSig, sigLength);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillCustomAttributeProperties(mdCustomAttribute mdtTarget, Signature &sig, mdToken &mdtOwner, mdToken &mdtCtor) const
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        _ASSERTE(!IsNilToken(mdtTarget));
        _ASSERTE(IsNilToken(mdtOwner));
        _ASSERTE(IsNilToken(mdtCtor));

        auto &comMetaImp = GetCOMMetaDataImport();
        
        auto const *pSig = static_cast<PCOR_SIGNATURE>(nullptr);
        auto sigLength = 0ul;
        auto hr = comMetaImp.GetCustomAttributeProps(mdtTarget, &mdtOwner, &mdtCtor, reinterpret_cast<void const **>(&pSig), &sigLength);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        sig.SetBlob(pSig, sigLength);
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
        using Urasandesu::CppAnonym::CppAnonymCOMException;
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

            _ASSERTE(!m_asmPath.empty());
            m_fullName.clear(); // This means that m_fullName can be filled completely by next GetFullName call when the assembly has been resolved.
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
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillAssemblyProperties(assembly_metadata_pimpl_label_type const *_this, mdToken mdtTarget, wstring &name, AutoPtr<IStrongNameKey const> &pSnKey, ASSEMBLYMETADATA &amd,  vector<WCHAR> &locale, vector<OSINFO> &os, AssemblyFlags &asmFlags)
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
        hr = comMetaAsmImp.GetAssemblyProps(mdtTarget, const_cast<const void**>(&pPubKeyBlob), &pubKeyBlobSize, NULL, &wzname[0], wznameSize, NULL, &amd, NULL);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = &wzname[0];
        asmFlags = AssemblyFlags(dwasmFlags);
        pSnKey = pSnInfo->NewStrongNameKey(*reinterpret_cast<PublicKeyBlob *>(pPubKeyBlob), pubKeyBlobSize);
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillAssemblyRefProperties(assembly_metadata_pimpl_label_type const *_this, mdToken mdtTarget, wstring &name, AutoPtr<IStrongNameKey const> &pSnKey, ASSEMBLYMETADATA &amd,  vector<WCHAR> &locale, vector<OSINFO> &os, AssemblyFlags &asmFlags)
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
        hr = comMetaAsmImp.GetAssemblyRefProps(mdtTarget, const_cast<void const **>(&pPubKeyOrToken), &pubKeyOrTokenSize, &wzname[0], wznameSize, nullptr, &amd, nullptr, nullptr, nullptr);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        name = &wzname[0];
        asmFlags = AssemblyFlags(dwasmFlags);
        if ((asmFlags & AssemblyFlags::AF_PUBLIC_KEY) != 0)
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        else
            pSnKey = pSnInfo->NewStrongNameKeyWithToken(pPubKeyOrToken, pubKeyOrTokenSize);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillPlatformByCOMMetaDataImport(IMetaDataImport2 *pComMetaImp, ASSEMBLYMETADATA &amd, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags)
    {
        using Urasandesu::CppAnonym::Collections::ResizeIfAvailable;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        _ASSERTE(pComMetaImp);
        
        auto dwPEKind = 0ul;
        auto dwMachine = 0ul;
        auto hr = pComMetaImp->GetPEKind(&dwPEKind, &dwMachine);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        if (hr == S_FALSE)
            return;
        
        FillPlatform(dwPEKind, dwMachine, amd, procArchs, asmFlags);
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillPlatformByHeuristicAlgorithm(assembly_metadata_pimpl_label_type const *_this, ASSEMBLYMETADATA &amd, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags)
    {
        using Urasandesu::CppAnonym::Collections::ResizeIfAvailable;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        if (procArchs.empty())
        {
            amd.ulProcessor = 2ul;
            amd.rProcessor = reinterpret_cast<DWORD *>(ResizeIfAvailable(amd.ulProcessor, procArchs));

            auto mdtTarget = _this->GetToken();
            if (TypeFromToken(mdtTarget) == mdtAssembly)
            {
                auto const &pPEReader = _this->GetPortableExecutableReader();
                auto dwPEKind = 0ul;
                auto dwMachine = 0ul;
                pPEReader->GetPEKind(dwPEKind, dwMachine);
                
                FillPlatform(dwPEKind, dwMachine, amd, procArchs, asmFlags);
            }
            else if (TypeFromToken(mdtTarget) == mdtAssemblyRef)
            {
#ifdef _M_IX86
                procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_INTEL);
                procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
#else
                procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64);
                procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
#endif
            }
            else
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
        }
        
        if (procArchs.size() == 2 && procArchs[1] == ProcessorArchitecture::PA_UNKNOWN)
        {
            auto sysInfo = SYSTEM_INFO();
            ::ZeroMemory(&sysInfo, sizeof(SYSTEM_INFO));
            ::GetSystemInfo(&sysInfo);
            procArchs[1] = ProcessorArchitecture(sysInfo.wProcessorArchitecture);
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyMetadataPimpl<ApiHolder>::FillPlatform(DWORD dwPEKind, DWORD dwMachine, ASSEMBLYMETADATA &amd, vector<ProcessorArchitecture> &procArchs, AssemblyFlags &asmFlags)
    {
        using Urasandesu::CppAnonym::Collections::ResizeIfAvailable;
        
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
                    procArchs[1] = ProcessorArchitecture::PA_UNKNOWN;
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
                    procArchs[1] = ProcessorArchitecture::PA_UNKNOWN;
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
            auto procArchs = _this->m_procArchs;
            if (procArchs.empty())
            {
                procArchs.resize(2);
#ifdef _M_IX86
                procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_INTEL);
                procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
#else
                procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64);
                procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
#endif
            }

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

