/* 
 * File: BaseAssemblyGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseAssemblyGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_COMIMAGEFLAGS_H
#include <Urasandesu/Swathe/Hosting/ComImageFlags.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_CEECREATEFLAGS_H
#include <Urasandesu/Swathe/Hosting/CeeCreateFlags.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseAssemblyGeneratorPimpl<ApiHolder>::BaseAssemblyGeneratorPimpl(assembly_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pMetaInfo(nullptr), 
        m_pDisp(nullptr), 
        m_pPEInfo(nullptr),
        m_mda(mdAssemblyNil),
        m_amdInit(false),
        m_casInit(false),
        m_refAsmsInit(false), 
        m_isSaving(false), 
        m_pSavingAsmGen(nullptr), 
        m_pSrcAsm(nullptr), 
        m_isModifiable(false)
    { }

    
    
    template<class ApiHolder>    
    BaseAssemblyGeneratorPimpl<ApiHolder>::~BaseAssemblyGeneratorPimpl()
    { 
        BOOST_FOREACH (auto const &pModGen, m_modGens)
            m_pMetaInfo->UnloadModuleGeneratorCore(pModGen);

        BOOST_FOREACH (auto const &pTypeGen, m_typeGens)
            m_pMetaInfo->UnloadTypeGeneratorCore(pTypeGen);

        BOOST_FOREACH (auto const &pFieldGen, m_fieldGens)
            m_pMetaInfo->UnloadFieldGeneratorCore(pFieldGen);

        BOOST_FOREACH (auto const &pMethodGen, m_methodGens)
            m_pMetaInfo->UnloadMethodGeneratorCore(pMethodGen);

        BOOST_FOREACH (auto const &pBodyGen, m_bodyGens)
            m_pMetaInfo->UnloadMethodBodyGeneratorCore(pBodyGen);

        BOOST_FOREACH (auto const &pLocalGen, m_localGens)
            m_pMetaInfo->UnloadLocalGeneratorCore(pLocalGen);

        BOOST_FOREACH (auto const &pParamGen, m_paramGens)
            m_pMetaInfo->UnloadParameterGeneratorCore(pParamGen);

        BOOST_FOREACH (auto const &pPropGen, m_propGens)
            m_pMetaInfo->UnloadPropertyGeneratorCore(pPropGen);

        BOOST_FOREACH (auto const &pCaGen, m_caGens)
            m_pMetaInfo->UnloadCustomAttributeGeneratorCore(pCaGen);
    }
    
#define SWATHE_DECLARE_BASE_ASSEMBLY_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::Initialize(metadata_info_label_type *pMetaInfo, metadata_dispenser_label_type *pDisp, portable_executable_info_label_type const *pPEInfo)
    {
        _ASSERTE(pMetaInfo);
        _ASSERTE(!m_pMetaInfo);
        m_pMetaInfo = pMetaInfo;

        _ASSERTE(pDisp);
        _ASSERTE(!m_pDisp);
        m_pDisp = pDisp;

        _ASSERTE(pPEInfo);
        _ASSERTE(!m_pPEInfo);
        m_pPEInfo = pPEInfo;
    }



    template<class ApiHolder>    
    mdAssembly BaseAssemblyGeneratorPimpl<ApiHolder>::GetToken() const
    {
        CPPANONYM_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mda))
        {
            CPPANONYM_LOG_NAMED_SCOPE("if (IsNilToken(m_mda))");

            if (!m_pSrcAsm)
            {
                CPPANONYM_LOG_NAMED_SCOPE("if (!m_pSrcAsm)");

                _ASSERTE(!m_name.empty());
                _ASSERTE(m_pSnKey);
                ::ZeroMemory(&m_amd, sizeof(ASSEMBLYMETADATA));
                
                CPPANONYM_D_LOGW1(L"Getting Assembly Generator Token... 1: %|1$s|", m_name);
                auto const &pubKeyBlob = m_pSnKey->GetPublicKeyBlob();
                auto pubKeyBlobSize = m_pSnKey->GetPublicKeyBlobSize();
                auto &comMetaAsmEmt = m_pClass->GetCOMMetaDataAssemblyEmit();
                auto hr = comMetaAsmEmt.DefineAssembly(&pubKeyBlob, pubKeyBlobSize, CALG_SHA1, m_name.c_str(), &m_amd, AssemblyFlags::AF_PA_NONE, &m_mda);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
                m_amdInit = true;
            }
            else
            {
                CPPANONYM_LOG_NAMED_SCOPE("if (m_pSrcAsm)");

                auto const &pSnKey = m_pSrcAsm->GetStrongNameKey();
                auto const &pubKeyToken = pSnKey->GetPublicKeyToken();
                auto const &name = m_pSrcAsm->GetName();
                auto const &amd = m_pSrcAsm->GetAssemblyMetadata();
                auto asmFlags = m_pSrcAsm->GetFlags();
                asmFlags &= ~AssemblyFlags::AF_PUBLIC_KEY;
                CPPANONYM_D_LOGW1(L"Getting Assembly Generator Token... 2: %|1$s|", name);
                auto &comMetaAsmEmt = m_pClass->GetCOMMetaDataAssemblyEmit();   // TODO: この辺実装中。。。
                auto hr = comMetaAsmEmt.DefineAssemblyRef(&pubKeyToken[0], static_cast<ULONG>(pubKeyToken.size()), name.c_str(), &amd, NULL, 0, asmFlags.Value(), &m_mda);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mda);
        }
        return m_mda;
    }



    template<class ApiHolder>    
    wstring const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetFullName() const
    {
        if (m_fullName.empty())
        {
            if (m_pSrcAsm == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_fullName = m_pSrcAsm->GetFullName();
            }
        }
        return m_fullName;
    }



    template<class ApiHolder>    
    path const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetLocation() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IModule const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetMainModule() const
    {
        if (m_pSrcAsm == nullptr)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pClass->Resolve(m_pSrcAsm->GetMainModule());
        }
    }



    template<class ApiHolder>    
    IModule const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetModule(wstring const &name) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }
    
    
    
    template<class ApiHolder>    
    AutoPtr<IStrongNameKey const> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetStrongNameKey() const
    {
        if (!m_pSnKey)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_pSnKey;
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::SetStrongNameKey(AutoPtr<IStrongNameKey const> const &pSnKey)
    {
        _ASSERTE(!m_pSnKey);
        _ASSERTE(pSnKey);
        m_pSnKey = pSnKey;
    }
    
    
    
    template<class ApiHolder>    
    wstring const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetName() const
    {
        if (m_name.empty())
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        return m_name;
    }
    
    
    
    template<class ApiHolder>    
    ASSEMBLYMETADATA const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetAssemblyMetadata() const
    {
        if (!m_pSrcAsm)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pSrcAsm->GetAssemblyMetadata();
        }
    }
    
    
    
    template<class ApiHolder>    
    Version const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetVersion() const
    {
        if (!m_pSrcAsm)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pSrcAsm->GetVersion();
        }
    }



    template<class ApiHolder>    
    wstring const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetCultureName() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    wstring const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetImageRuntimeVersion() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    AssemblyFlags BaseAssemblyGeneratorPimpl<ApiHolder>::GetFlags() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }
    
    
    
    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetSourceAssembly() const
    {
        return m_pSrcAsm == nullptr ? m_pClass : m_pSrcAsm->GetSourceAssembly();
    }
    
    
    
    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetTargetAssembly() const
    {
        return m_pSavingAsmGen;
    }



    template<class ApiHolder>    
    IDispenser const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetDispenser() const
    {
        return m_pDisp;
    }
    
    
    
    template<class ApiHolder>    
    IField const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetField(mdToken mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetMethod(mdToken mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetMethod(mdToken mdt, COR_ILMETHOD *pILBody) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetType(mdToken mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetType(wstring const &fullName) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetGenericTypeParameter(ULONG genericParamPos) const
    {
        if (!m_pSrcAsm)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pClass->Resolve(m_pSrcAsm->GetGenericTypeParameter(genericParamPos));
        }
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetGenericMethodParameter(ULONG genericParamPos) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<ProcessorArchitecture> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetProcessorArchitectures() const
    {
        if (!m_pSrcAsm)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pSrcAsm->GetProcessorArchitectures();
        }
    }



    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetAssembly(wstring const &fullName) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetAssembly(wstring const &fullName, vector<ProcessorArchitecture> const &procArchs) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IAssembly const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetAssemblyReference(mdAssemblyRef mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ICustomAttribute const *BaseAssemblyGeneratorPimpl<ApiHolder>::GetCustomAttribute(mdToken mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseAssemblyGeneratorPimpl<ApiHolder>::GetCustomAttributes() const
    {
        if (!m_casInit)
        {
            if (m_pSrcAsm == nullptr)
            {
                if (m_cas.empty())
                {
                    FillDefaultAttributes(this, m_cas);
                }
                else
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
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
    ICustomAttributePtrRange BaseAssemblyGeneratorPimpl<ApiHolder>::GetCustomAttributes(IType const *pAttributeType) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::module_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineModule(wstring const &name)
    {
        auto pNewModGen = NewModuleGenerator(name);
        pNewModGen.Persist();
        return pNewModGen.Get();
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::Save(PortableExecutableKinds const &portableExecutableKind, ImageFileMachine const &imageFileMachine)
    {
        using Urasandesu::Swathe::Hosting::ComImageFlags;
        using Urasandesu::Swathe::Hosting::CeeCreateFlags;

        typedef typename class_type::assembly_saving_prepared AssemblySavingPrepared;

        auto _ = AssemblySavingPrepared(m_pClass);

        auto imageFlags = ComImageFlags();
        imageFlags = ComImageFlags::CIF_ILONLY;
        if (portableExecutableKind & PortableExecutableKinds::PEK_32BIT_REQUIRED)
            imageFlags |= ComImageFlags::CIF_32BITREQUIRED;

        auto createFlags = CeeCreateFlags();
        if (portableExecutableKind & PortableExecutableKinds::PEK_IL_ONLY)
        {
            if (portableExecutableKind & PortableExecutableKinds::PEK_32PLUS)
            {
                createFlags = CeeCreateFlags::CCF_PE64;
                if (imageFileMachine == ImageFileMachine::IFM_I386)
                    createFlags |= CeeCreateFlags::CCF_I386;
                else if (imageFileMachine == ImageFileMachine::IFM_IA64)
                    createFlags |= CeeCreateFlags::CCF_IA64;
                else if (imageFileMachine == ImageFileMachine::IFM_AMD64)
                    createFlags |= CeeCreateFlags::CCF_AMD64;
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else if (portableExecutableKind & PortableExecutableKinds::PEK_32BIT_REQUIRED)
            {
                createFlags = CeeCreateFlags::CCF_PURE_IL;
            }
            else
            {
                createFlags = CeeCreateFlags::CCF_PURE_IL;
            }
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

        auto pVisitor = m_pPEInfo->CreateWriter(&GetCOMMetaDataEmit(), imageFlags, createFlags);
        m_pClass->Accept(pVisitor.Get());
        pVisitor->Close();
    }
    
    
    
    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::custom_attribute_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineCustomAttribute(IMethod const *pCtor, vector<CustomAttributeArgument> const &constructorArgs)
    {
        return m_pClass->DefineCustomAttribute(pCtor, true, constructorArgs, false, MetadataSpecialValues::EMPTY_PROPERTIES, false, MetadataSpecialValues::EMPTY_CUSTOM_ATTRIBUTE_ARGUMENTS, static_cast<IAssembly const *>(m_pClass));
    }
    
    
    
    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::custom_attribute_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineCustomAttribute(IMethod const *pCtor, vector<CustomAttributeArgument> const &constructorArgs, vector<IProperty const *> const &namedProperties, vector<CustomAttributeArgument> const &propertyValues)
    {
        return m_pClass->DefineCustomAttribute(pCtor, true, constructorArgs, true, namedProperties, true, propertyValues, static_cast<IAssembly const *>(m_pClass));
    }
    
    
    
    template<class ApiHolder>    
    ITypePtrRange BaseAssemblyGeneratorPimpl<ApiHolder>::GetTypes() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    bool BaseAssemblyGeneratorPimpl<ApiHolder>::Equals(IAssembly const *pAsm) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    size_t BaseAssemblyGeneratorPimpl<ApiHolder>::GetHashCode() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    AutoPtr<IPortableExecutableReader const> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetPortableExecutableReader() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    vector<IAssembly const *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetReferencedAssemblies() const
    {
        CPPANONYM_LOG_FUNCTION();

        if (!m_refAsmsInit)
        {
            CPPANONYM_LOG_NAMED_SCOPE("if (!m_refAsmsInit)");

            if (m_refAsmGens.empty())
                FillDefaultReferencedAssemblies(this, m_refAsmGens);
            
            if (CPPANONYM_D_LOG_ENABLED())
            {
                BOOST_FOREACH (auto const *pRefAsmGen, m_refAsmGens)
                {
                    auto const &fullName = pRefAsmGen->GetSourceAssembly()->GetFullName();
                    CPPANONYM_D_LOGW1(L"Reference Assembly: %|1$s|)", fullName);
                }
            }

            m_refAsms = vector<IAssembly const *>();
            m_refAsms.reserve(m_refAsmGens.size());
            m_refAsms.assign(m_refAsmGens.begin(), m_refAsmGens.end());
            m_refAsmsInit = true;
        }
        return m_refAsms;
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::GetModifiableMethod(mdToken mdt, COR_ILMETHOD *pILBody) const
    {
        auto const *pAsm = m_pClass->GetSourceAssembly();
        auto const *pSrcMethod = pAsm->GetMethod(mdt, pILBody);
        
        auto pNewMethodGen = NewMethodGenerator(mdt, pSrcMethod, MethodProvider());
        pNewMethodGen.Persist();
        return pNewMethodGen.Get();
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::SetFullName(wstring const &fullName)
    {
        _ASSERTE(!fullName.empty());
        _ASSERTE(m_fullName.empty());
        m_fullName = fullName;
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::SetName(wstring const &name)
    {
        _ASSERTE(!name.empty());
        _ASSERTE(m_name.empty());
        m_name = name;
    }
    
    
    
    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::SetCOMMetaDataEmit(IMetaDataEmit2 *pComMetaEmt)
    {
        _ASSERTE(m_pComMetaEmt.p == nullptr);
        _ASSERTE(pComMetaEmt != nullptr);
        m_pComMetaEmt = pComMetaEmt;
        m_isModifiable = true;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::SetSourceAssembly(IAssembly const *pSrcAsm)
    {
        _ASSERTE(m_pSrcAsm == nullptr);
        _ASSERTE(pSrcAsm != nullptr);
        m_pSrcAsm = pSrcAsm;
    }



    template<class ApiHolder>    
    bool BaseAssemblyGeneratorPimpl<ApiHolder>::IsModifiable() const
    {
        return m_isModifiable;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        using boost::get;

        pVisitor->Visit(m_pClass);

        m_pClass->GetCustomAttributes();   // resolves default custom attributes of this Assembly.
        auto const &caGenToIndex = m_pClass->GetCustomAttributeGeneratorToIndex();
        for (auto i = 0ul; i < caGenToIndex.size(); ++i)
            if (caGenToIndex[i]->GetAssembly() == m_pClass)
                caGenToIndex[i]->Accept(pVisitor);

        auto const &modGenToIndex = m_pClass->GetModuleGeneratorToIndex();
        for (auto i = 0ul; i < modGenToIndex.size(); ++i)
            if (modGenToIndex[i]->GetAssembly() == m_pClass)
                modGenToIndex[i]->Accept(pVisitor);

        //for (auto i = 0ul; i < m_refAsmGens.size(); ++i)
        //    m_refAsmGens[i]->Accept(pVisitor);
    }
    
    
    
    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::module_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineModule(IModule const *pSrcMod)
    {
        auto pNewModGen = NewModuleGenerator(pSrcMod);
        pNewModGen.Persist();
        return pNewModGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::module_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewModuleGenerator(wstring const &name) const
    {
        auto pModGen = m_pMetaInfo->NewModuleGeneratorCore(m_pClass);
        pModGen->SetName(name);
        return pModGen;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::module_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewModuleGenerator(IModule const *pSrcMod) const
    {
        auto pModGen = m_pMetaInfo->NewModuleGeneratorCore(m_pClass);
        pModGen->SetSourceModule(pSrcMod);
        return pModGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterModuleGenerator(TempPtr<module_generator_label_type> &pModGen)
    {
        m_pMetaInfo->RegisterModuleGeneratorCore(pModGen);
        m_modGens.push_back(pModGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::type_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineType(wstring const &fullName, TypeAttributes const &attr, TypeProvider const &member)
    {
        auto pNewTypeGen = NewTypeGenerator(fullName, attr, member);
        pNewTypeGen.Persist();
        return pNewTypeGen.Get();
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::type_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineType(IType const *pSrcType, TypeProvider const &member)
    {
        auto pNewTypeGen = NewTypeGenerator(pSrcType, member);
        pNewTypeGen.Persist();
        return pNewTypeGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::type_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewTypeGenerator(wstring const &fullName, TypeAttributes const &attr, TypeProvider const &member) const
    {
        auto pTypeGen = m_pMetaInfo->NewTypeGeneratorCore(m_pClass);
        pTypeGen->SetFullName(fullName);
        pTypeGen->SetAttributes(attr);
        pTypeGen->SetMember(member);
        return pTypeGen;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::type_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewTypeGenerator(IType const *pSrcType, TypeProvider const &member) const
    {
        auto pTypeGen = m_pMetaInfo->NewTypeGeneratorCore(m_pClass);
        pTypeGen->SetSourceType(pSrcType);
        pTypeGen->SetMember(member);
        return pTypeGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterTypeGenerator(TempPtr<type_generator_label_type> &pTypeGen)
    {
        m_pMetaInfo->RegisterTypeGeneratorCore(pTypeGen);
        m_typeGens.push_back(pTypeGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineMethod(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member)
    {
        auto pNewMethodGen = NewMethodGenerator(name, attr, callingConvention, pRetType, paramsSpecified, params, member);
        pNewMethodGen.Persist();
        return pNewMethodGen.Get();
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineMethod(IMethod const *pSrcMethod, MethodProvider const &member)
    {
        auto pNewMethodGen = NewMethodGenerator(mdTokenNil, pSrcMethod, member);
        pNewMethodGen.Persist();
        return pNewMethodGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewMethodGenerator(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, bool paramsSpecified, vector<IParameter const *> const &params, MethodProvider const &member) const
    {
        auto pMethodGen = m_pMetaInfo->NewMethodGeneratorCore(m_pClass);
        pMethodGen->SetName(name);
        pMethodGen->SetAttributes(attr);
        pMethodGen->SetCallingConvention(callingConvention);
        pMethodGen->SetReturnType(pRetType);
        if (paramsSpecified)
            pMethodGen->SetParameters(params);
        pMethodGen->SetMember(member);
        return pMethodGen;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewMethodGenerator(mdToken mdt, IMethod const *pSrcMethod, MethodProvider const &member) const
    {
        auto pMethodGen = m_pMetaInfo->NewMethodGeneratorCore(m_pClass);
        pMethodGen->SetToken(mdt);
        pMethodGen->SetSourceMethod(pSrcMethod);
        pMethodGen->SetMember(member);
        return pMethodGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterMethodGenerator(TempPtr<method_generator_label_type> &pMethodGen)
    {
        m_pMetaInfo->RegisterMethodGeneratorCore(pMethodGen);
        m_methodGens.push_back(pMethodGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::property_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineProperty(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, bool paramsSpecified, vector<IParameter const *> const &params, PropertyProvider const &member)
    {
        auto pNewPropGen = NewPropertyGenerator(name, attr, pPropType, paramsSpecified, params, member);
        pNewPropGen.Persist();
        return pNewPropGen.Get();
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::property_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineProperty(IProperty const *pSrcProp, PropertyProvider const &member)
    {
        auto pNewPropGen = NewPropertyGenerator(pSrcProp, member);
        pNewPropGen.Persist();
        return pNewPropGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::property_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewPropertyGenerator(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, bool paramsSpecified, vector<IParameter const *> const &params, PropertyProvider const &member) const
    {
        auto pPropGen = m_pMetaInfo->NewPropertyGeneratorCore(m_pClass);
        pPropGen->SetName(name);
        pPropGen->SetAttributes(attr);
        pPropGen->SetPropertyType(pPropType);
        if (paramsSpecified)
            pPropGen->SetParameters(params);
        pPropGen->SetMember(member);
        return pPropGen;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::property_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewPropertyGenerator(IProperty const *pSrcProp, PropertyProvider const &member) const
    {
        auto pPropGen = m_pMetaInfo->NewPropertyGeneratorCore(m_pClass);
        pPropGen->SetSourceProperty(pSrcProp);
        pPropGen->SetMember(member);
        return pPropGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterPropertyGenerator(TempPtr<property_generator_label_type> &pPropGen)
    {
        m_pMetaInfo->RegisterPropertyGeneratorCore(pPropGen);
        m_propGens.push_back(pPropGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::field_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineField(wstring const &name, IType const *pFieldType, FieldAttributes const &attr, FieldProvider const &member)
    {
        auto pNewFieldGen = NewFieldGenerator(name, pFieldType, attr, member);
        pNewFieldGen.Persist();
        return pNewFieldGen.Get();
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::field_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineField(IField const *pSrcField, FieldProvider const &member)
    {
        auto pNewFieldGen = NewFieldGenerator(pSrcField, member);
        pNewFieldGen.Persist();
        return pNewFieldGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::field_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewFieldGenerator(wstring const &name, IType const *pFieldType, FieldAttributes const &attr, FieldProvider const &member) const
    {
        auto pFieldGen = m_pMetaInfo->NewFieldGeneratorCore(m_pClass);
        pFieldGen->SetName(name);
        pFieldGen->SetFieldType(pFieldType);
        pFieldGen->SetAttributes(attr);
        pFieldGen->SetMember(member);
        return pFieldGen;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::field_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewFieldGenerator(IField const *pSrcField, FieldProvider const &member) const
    {
        auto pFieldGen = m_pMetaInfo->NewFieldGeneratorCore(m_pClass);
        pFieldGen->SetSourceField(pSrcField);
        pFieldGen->SetMember(member);
        return pFieldGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterFieldGenerator(TempPtr<field_generator_label_type> &pFieldGen)
    {
        m_pMetaInfo->RegisterFieldGeneratorCore(pFieldGen);
        m_fieldGens.push_back(pFieldGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_body_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineMethodBody(IMethodBody const *pSrcBody, IMethod const *pMethod)
    {
        auto pNewMethodBodyGen = NewMethodBodyGenerator(pSrcBody, pMethod);
        pNewMethodBodyGen.Persist();
        return pNewMethodBodyGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_body_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewMethodBodyGenerator(IMethodBody const *pSrcBody, IMethod const *pMethod) const
    {
        auto pBodyGen = m_pMetaInfo->NewMethodBodyGeneratorCore(m_pClass);
        pBodyGen->SetSourceMethodBody(pSrcBody);
        pBodyGen->SetMethod(pMethod);
        return pBodyGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterMethodBodyGenerator(TempPtr<method_body_generator_label_type> &pBodyGen)
    {
        m_pMetaInfo->RegisterMethodBodyGeneratorCore(pBodyGen);
        m_bodyGens.push_back(pBodyGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::parameter_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineParameter(ULONG position, IType const *pParamType, ParameterProvider const &member)
    {
        auto pNewParamGen = NewParameterGenerator(position, pParamType, member);
        pNewParamGen.Persist();
        return pNewParamGen.Get();
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::parameter_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineParameter(IParameter const *pSrcParam, ParameterProvider const &member)
    {
        auto pNewParamGen = NewParameterGenerator(pSrcParam, member);
        pNewParamGen.Persist();
        return pNewParamGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::parameter_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewParameterGenerator(ULONG position, IType const *pParamType, ParameterProvider const &member) const
    {
        auto pParamGen = m_pMetaInfo->NewParameterGeneratorCore(m_pClass);
        pParamGen->SetPosition(position);
        pParamGen->SetParameterType(pParamType);
        pParamGen->SetMember(member);
        return pParamGen;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::parameter_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewParameterGenerator(IParameter const *pSrcParam, ParameterProvider const &member) const
    {
        auto pParamGen = m_pMetaInfo->NewParameterGeneratorCore(m_pClass);
        pParamGen->SetSourceParameter(pSrcParam);
        pParamGen->SetMember(member);
        return pParamGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterParameterGenerator(TempPtr<parameter_generator_label_type> &pParamGen)
    {
        m_pMetaInfo->RegisterParameterGeneratorCore(pParamGen);
        m_paramGens.push_back(pParamGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::local_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineLocal(SIZE_T index, IType const *pLocalType, IMethodBody const *pBody)
    {
        auto pNewLocalGen = NewLocalGenerator(index, pLocalType, pBody);
        pNewLocalGen.Persist();
        return pNewLocalGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::local_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewLocalGenerator(SIZE_T index, IType const *pLocalType, IMethodBody const *pBody) const
    {
        auto pLocalGen = m_pMetaInfo->NewLocalGeneratorCore(m_pClass);
        pLocalGen->SetLocalIndex(index);
        pLocalGen->SetLocalType(pLocalType);
        pLocalGen->SetMethodBody(pBody);
        return pLocalGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterLocalGenerator(TempPtr<local_generator_label_type> &pLocalGen)
    {
        m_pMetaInfo->RegisterLocalGeneratorCore(pLocalGen);
        m_localGens.push_back(pLocalGen.Get());
    }



    template<class ApiHolder>    
    typename BaseAssemblyGeneratorPimpl<ApiHolder>::custom_attribute_generator_label_type *BaseAssemblyGeneratorPimpl<ApiHolder>::DefineCustomAttribute(IMethod const *pCtor, bool constructorArgsSpecified, vector<CustomAttributeArgument> const &constructorArgs, bool namedPropertiesSpecified, vector<IProperty const *> const &namedProperties, bool propertyValuesSpecified, vector<CustomAttributeArgument> const &propertyValues, CustomAttributeProvider const &member)
    {
        auto pNewCaGen = NewCustomAttributeGenerator(pCtor, constructorArgsSpecified, constructorArgs, namedPropertiesSpecified, namedProperties, propertyValuesSpecified, propertyValues, member);
        pNewCaGen.Persist();
        return pNewCaGen.Get();
    }



    template<class ApiHolder>    
    TempPtr<typename BaseAssemblyGeneratorPimpl<ApiHolder>::custom_attribute_generator_label_type> BaseAssemblyGeneratorPimpl<ApiHolder>::NewCustomAttributeGenerator(IMethod const *pCtor, bool constructorArgsSpecified, vector<CustomAttributeArgument> const &constructorArgs, bool namedPropertiesSpecified, vector<IProperty const *> const &namedProperties, bool propertyValuesSpecified, vector<CustomAttributeArgument> const &propertyValues, CustomAttributeProvider const &member) const
    {
        auto pCaGen = m_pMetaInfo->NewCustomAttributeGeneratorCore(m_pClass);
        pCaGen->SetConstructor(pCtor);
        if (constructorArgsSpecified)
            pCaGen->SetConstructorArguments(constructorArgs);
        if (namedPropertiesSpecified)
            pCaGen->SetNamedProperties(namedProperties);
        if (propertyValuesSpecified)
            pCaGen->SetPropertyValues(propertyValues);
        pCaGen->SetMember(member);
        return pCaGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::RegisterCustomAttributeGenerator(TempPtr<custom_attribute_generator_label_type> &pCaGen)
    {
        m_pMetaInfo->RegisterCustomAttributeGeneratorCore(pCaGen);
        m_caGens.push_back(pCaGen.Get());
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::module_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetModuleGeneratorToIndex() const
    {
        return m_modGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::type_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetTypeGeneratorToIndex() const
    {
        return m_typeGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::field_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetFieldGeneratorToIndex() const
    {
        return m_fieldGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetMethodGeneratorToIndex() const
    {
        return m_methodGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::method_body_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetMethodBodyGeneratorToIndex() const
    {
        return m_bodyGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::local_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetLocalGeneratorToIndex() const
    {
        return m_localGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::parameter_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetParameterGeneratorToIndex() const
    {
        return m_paramGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::property_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetPropertyGeneratorToIndex() const
    {
        return m_propGens;
    }



    template<class ApiHolder>    
    vector<typename BaseAssemblyGeneratorPimpl<ApiHolder>::custom_attribute_generator_label_type *> const &BaseAssemblyGeneratorPimpl<ApiHolder>::GetCustomAttributeGeneratorToIndex() const
    {
        return m_caGens;
    }



    template<class ApiHolder>    
    IModule const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(IModule const *pMod) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<module_generator_label_type const *> ModGens;
        typedef ModGens::value_type Value;

        auto *pRefAsmGen = m_pDisp->ResolveAssembly(pMod->GetAssembly());
        auto const &modGenToIndex = pRefAsmGen->GetModuleGeneratorToIndex();
        auto isAlreadyExist = [&](Value const &v) { return v->Equals(pMod); };
        auto result = FindIf(modGenToIndex, isAlreadyExist);
        if (result)
            return *result;

        return pRefAsmGen->DefineModule(pMod);
    }



    template<class ApiHolder>    
    IType const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(IType const *pType) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<type_generator_label_type const *> TypeGens;
        typedef TypeGens::value_type Value;

        auto *pRefAsmGen = m_pDisp->ResolveAssembly(pType->GetAssembly());
        auto const &typeGenToIndex = pRefAsmGen->GetTypeGeneratorToIndex();
        auto isAlreadyExist = [&](Value const &v) { return v->Equals(pType); };
        auto result = FindIf(typeGenToIndex, isAlreadyExist);
        if (result)
            return *result;

        return pRefAsmGen->DefineType(pType, TypeProvider());
    }



    template<class ApiHolder>    
    IField const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(IField const *pField) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<field_generator_label_type const *> FieldGens;
        typedef FieldGens::value_type Value;

        auto *pRefAsmGen = m_pDisp->ResolveAssembly(pField->GetAssembly());
        auto const &fieldGenToIndex = pRefAsmGen->GetFieldGeneratorToIndex();
        auto isAlreadyExist = [&](Value const &v) { return v->Equals(pField); };
        auto result = FindIf(fieldGenToIndex, isAlreadyExist);
        if (result)
            return *result;

        return pRefAsmGen->DefineField(pField, FieldProvider());
    }



    template<class ApiHolder>    
    IProperty const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(IProperty const *pProp) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<property_generator_label_type const *> PropertyGens;
        typedef PropertyGens::value_type Value;

        auto *pRefAsmGen = m_pDisp->ResolveAssembly(pProp->GetAssembly());
        auto const &propGenToIndex = pRefAsmGen->GetPropertyGeneratorToIndex();
        auto isAlreadyExist = [&](Value const &v) { return v->Equals(pProp); };
        auto result = FindIf(propGenToIndex, isAlreadyExist);
        if (result)
            return *result;

        return pRefAsmGen->DefineProperty(pProp, PropertyProvider());
    }



    template<class ApiHolder>    
    IMethod const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(IMethod const *pMethod) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<method_generator_label_type const *> MethodGens;
        typedef MethodGens::value_type Value;

        auto *pRefAsmGen = m_pDisp->ResolveAssembly(pMethod->GetAssembly());
        auto const &methodGenToIndex = pRefAsmGen->GetMethodGeneratorToIndex();
        auto isAlreadyExist = [&](Value const &v) { return v->Equals(pMethod); };
        auto result = FindIf(methodGenToIndex, isAlreadyExist);
        if (result)
            return *result;

        return pRefAsmGen->DefineMethod(pMethod, MethodProvider());
    }



    template<class ApiHolder>    
    IMethodBody const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(IMethodBody const *pBody) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<method_body_generator_label_type const *> MethodBodyGens;
        typedef MethodBodyGens::value_type Value;

        auto *pRefAsmGen = m_pDisp->ResolveAssembly(pBody->GetAssembly());
        auto const &bodyGenToIndex = pRefAsmGen->GetMethodBodyGeneratorToIndex();
        auto isAlreadyExist = [&](Value const &v) { return v->Equals(pBody); };
        auto result = FindIf(bodyGenToIndex, isAlreadyExist);
        if (result)
            return *result;

        return pRefAsmGen->DefineMethodBody(pBody, nullptr);
    }



    template<class ApiHolder>    
    IParameter const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(IParameter const *pParam) const
    {
        using boost::adaptors::filtered;
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef vector<parameter_generator_label_type const *> ParamGens;
        typedef ParamGens::value_type Value;

        auto *pRefAsmGen = m_pDisp->ResolveAssembly(pParam->GetAssembly());
        auto const &paramGenToIndex = pRefAsmGen->GetParameterGeneratorToIndex();
        auto isAlreadyExist = [&](Value const &v) { return v->Equals(pParam); };
        auto result = FindIf(paramGenToIndex, isAlreadyExist);
        if (result)
            return *result;

        return pRefAsmGen->DefineParameter(pParam, ParameterProvider());
    }



    template<class ApiHolder>    
    ILocal const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(ILocal const *pLocal) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ICustomAttribute const *BaseAssemblyGeneratorPimpl<ApiHolder>::Resolve(ICustomAttribute const *pCa) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMetaDataAssemblyEmit &BaseAssemblyGeneratorPimpl<ApiHolder>::GetCOMMetaDataAssemblyEmit()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pSavingAsmGen == nullptr)
        {
            if (m_pComMetaAsmEmt.p == nullptr)
            {
                auto &comMetaEmt = m_pClass->GetCOMMetaDataEmit();
                auto hr = comMetaEmt.QueryInterface(IID_IMetaDataAssemblyEmit, 
                                                    reinterpret_cast<void **>(&m_pComMetaAsmEmt));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaAsmEmt;
        }
        else
        {
            return m_pSavingAsmGen->GetCOMMetaDataAssemblyEmit();
        }
    }
    
    
    
    template<class ApiHolder>    
    IMetaDataEmit2 &BaseAssemblyGeneratorPimpl<ApiHolder>::GetCOMMetaDataEmit()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (m_pSavingAsmGen == nullptr)
        {
            if (m_pComMetaEmt.p == nullptr)
            {
                auto &comMetaDisp = m_pDisp->GetCOMMetaDataDispenser();

                auto hr = comMetaDisp.DefineScope(CLSID_CorMetaDataRuntime, 0, IID_IMetaDataEmit2, 
                                                  reinterpret_cast<IUnknown **>(&m_pComMetaEmt));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaEmt.p;
        }
        else
        {
            return m_pSavingAsmGen->GetCOMMetaDataEmit();
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::AddReferencedAssembly(assembly_generator_label_type *pAsmGen)
    {
        using Urasandesu::CppAnonym::Collections::FindIf;

        typedef decltype(m_refAsmGens) RefAsmGens;
        typedef RefAsmGens::value_type Value;

        if (m_pClass->GetSourceAssembly() == pAsmGen->GetSourceAssembly())
            return;

        if (m_refAsmGens.empty())
            FillDefaultReferencedAssemblies(this, m_refAsmGens);

        auto result = FindIf(m_refAsmGens, [&](Value const &v) { return v->GetSourceAssembly() == pAsmGen->GetSourceAssembly(); });
        if (result)
        {
            _ASSERTE(!(*result)->GetTargetAssembly());
            (*result)->SetSavingAssembly(m_pClass);
        }
        else
        {
            m_refAsmsInit = false;
            m_refAsmGens.push_back(pAsmGen);
            pAsmGen->SetSavingAssembly(m_pClass);
        }
    }



    template<class ApiHolder>    
    bool BaseAssemblyGeneratorPimpl<ApiHolder>::IsSaving() const
    {
        return m_isSaving;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::SetSavingAssembly(assembly_generator_label_type *pSavingAsmGen)
    {
        m_pSavingAsmGen = pSavingAsmGen;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::PrepareSaving()
    {
        m_isSaving = true;
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::DisposeSaving()
    {
        try
        {
            m_isSaving = false;
            BOOST_FOREACH (auto &pRefAsmGen, m_refAsmGens)
                pRefAsmGen->SetSavingAssembly(nullptr);
        }
        catch (...)
        {
#ifdef OUTPUT_DEBUG
            std::cout << boost::diagnostic_information(boost::current_exception()) << std::endl;
#endif
        }
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::FillDefaultAttributes(assembly_generator_pimpl_label_type const *_this, vector<ICustomAttribute const *> &cas)
    {
        using boost::adaptors::filtered;

        auto *pClass = _this->m_pClass;
        auto *pDisp = _this->m_pDisp;

        auto const *pMSCorLib = pDisp->GetAssembly(MetadataSpecialValues::ASSEMBLY_FULL_NAME_OF_MSCORLIB);
        auto const *pMSCorLibDll = pMSCorLib->GetMainModule();

        auto const *pVoid = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_VOID);
        auto const *pInt32 = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_INT32);

                
        auto const *pCompilationRelaxations = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_COMPILATION_RELAXATIONS_ATTRIBUTE);
        auto const *pCompilationRelaxations_ctor = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pInt32);
            pCompilationRelaxations_ctor = pCompilationRelaxations->GetConstructor(params);
            _ASSERTE(pCompilationRelaxations_ctor);
        }

        auto const *pRuntimeCompatibility = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_RUNTIME_COMPATIBILITY_ATTRIBUTE);
        auto const *pRuntimeCompatibility_ctor = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            pRuntimeCompatibility_ctor = pRuntimeCompatibility->GetConstructor(params);
            _ASSERTE(pRuntimeCompatibility_ctor);
        }
        auto const *pRuntimeCompatibility_WrapNonExceptionThrows = static_cast<IProperty *>(nullptr);
        {
            pRuntimeCompatibility_WrapNonExceptionThrows = pRuntimeCompatibility->GetProperty(L"WrapNonExceptionThrows");
        }


        auto *pCompilationRelaxationsGen = static_cast<CustomAttributeGenerator *>(nullptr);
        {
            auto constructorArgs = vector<CustomAttributeArgument>();
            constructorArgs.push_back(8);
            pCompilationRelaxationsGen = pClass->DefineCustomAttribute(pCompilationRelaxations_ctor, constructorArgs);
        }

        auto *pRuntimeCompatibilityGen = static_cast<CustomAttributeGenerator *>(nullptr);
        {
            auto constructorArgs = vector<CustomAttributeArgument>();
            auto namedProperties = vector<IProperty const *>();
            namedProperties.push_back(pRuntimeCompatibility_WrapNonExceptionThrows);
            auto propertyValues = vector<CustomAttributeArgument>();
            propertyValues.push_back(true);
            pRuntimeCompatibilityGen = pClass->DefineCustomAttribute(pRuntimeCompatibility_ctor, constructorArgs, namedProperties, propertyValues);
        }


                    
        typedef vector<custom_attribute_generator_label_type const *> CaGens;
        typedef CaGens::value_type Value;

        auto const &caGenToIndex = pClass->GetCustomAttributeGeneratorToIndex();
        auto isMine = [&](Value const &v) { return v->GetAssembly() == pClass; };
        auto myCaGens = caGenToIndex | filtered(isMine);
        BOOST_FOREACH (auto const &pCaGen, myCaGens)
            cas.push_back(pCaGen);
    }



    template<class ApiHolder>    
    void BaseAssemblyGeneratorPimpl<ApiHolder>::FillDefaultReferencedAssemblies(assembly_generator_pimpl_label_type const *_this, vector<assembly_generator_label_type *> &refAsmGens)
    {
        auto *pDisp = _this->m_pDisp;

        auto const *pMSCorLib = pDisp->GetAssembly(MetadataSpecialValues::ASSEMBLY_FULL_NAME_OF_MSCORLIB);
        auto *pMSCorLibGen = pDisp->ResolveOrDefineAssembly(pMSCorLib);
        refAsmGens.push_back(pMSCorLibGen);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYGENERATORPIMPL_HPP

