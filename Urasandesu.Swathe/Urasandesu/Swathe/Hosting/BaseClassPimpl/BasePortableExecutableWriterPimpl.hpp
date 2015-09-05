/* 
 * File: BasePortableExecutableWriterPimpl.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPL_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPL_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPL_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BasePortableExecutableWriterPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELD_H
#include <Urasandesu/Swathe/Metadata/IField.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODY_H
#include <Urasandesu/Swathe/Metadata/IMethodBody.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCAL_H
#include <Urasandesu/Swathe/Metadata/ILocal.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTION_H
#include <Urasandesu/Swathe/Metadata/IInstruction.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BasePortableExecutableWriterPimpl<ApiHolder>::BasePortableExecutableWriterPimpl(portable_executable_writer_label_type *pClass) : 
        m_pClass(pClass), 
        m_pPEInfo(nullptr), 
        m_pSnInfo(nullptr), 
        m_imageFlags(ComImageFlags::CIF_UNREACHED), 
        m_createFlags(CeeCreateFlags::CCF_UNREACHED), 
        m_ceeFile(nullptr), 
        m_isClosed(false)
    { }

    template<class ApiHolder>    
    BasePortableExecutableWriterPimpl<ApiHolder>::~BasePortableExecutableWriterPimpl()
    {
        try
        {
            Close();
        }
        catch (...)
        {
#ifdef OUTPUT_DEBUG
            std::cout << boost::diagnostic_information(boost::current_exception()) << std::endl;
#endif
        }
    }
    
#define SWATHE_DECLARE_BASE_PORTABLE_EXECUTABLE_WRITER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Initialize(portable_executable_info_label_type *pPEInfo, strong_name_info_label_type const *pSnInfo)
    {
        _ASSERTE(pPEInfo);
        _ASSERTE(!m_pPEInfo);
        m_pPEInfo = pPEInfo;

        _ASSERTE(pSnInfo);
        _ASSERTE(!m_pSnInfo);
        m_pSnInfo = pSnInfo;
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IAssembly const *pAsm)
    {
        pAsm->GetToken();
        m_resolvedAsms.push_back(pAsm);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IModule const *pMod)
    {
        pMod->GetToken();
        m_resolvedMods.push_back(pMod);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IType const *pType)
    {
        pType->GetToken();
        m_resolvedTypes.push_back(pType);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IField const *pField)
    {
        pField->GetToken();
        m_resolvedFields.push_back(pField);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IProperty const *pProp)
    {
        pProp->GetToken();
        m_resolvedProps.push_back(pProp);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IMethod const *pMethod)
    {
        pMethod->GetToken();
        m_resolvedMethods.push_back(pMethod);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IMethodBody const *pBody)
    {
        pBody->GetToken();
        m_resolvedMethodBodies.push_back(pBody);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IParameter const *pParam)
    {
        pParam->GetToken();
        m_resolvedParams.push_back(pParam);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(ILocal const *pLocal)
    {
        pLocal->GetToken();
        m_resolvedLocals.push_back(pLocal);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(IInstruction const *pInst)
    {
        pInst->GetToken();
        // Instructions are not persisted, so shall not keep raw pointer.
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Visit(ICustomAttribute const *pCa)
    {
        pCa->GetToken();
        m_resolvedCas.push_back(pCa);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Close()
    {
        auto *_this = this;
        BOOST_SCOPE_EXIT((&_this))
        {
            _this->Finalize();
        }
        BOOST_SCOPE_EXIT_END


        if (m_isClosed || 
            m_resolvedAsms.empty() || 
            m_resolvedMods.empty())
            return;
        

        auto const &modName = m_resolvedMods[0]->GetName();
        EmitOptions(modName);
        
        auto textSection = GetTextSection();
        for (auto i = m_resolvedMethodBodies.begin(), i_end = m_resolvedMethodBodies.end(); i != i_end; ++i)
            EmitMethodBody(*i, textSection);

        auto const &pSnKey = m_resolvedAsms[0]->GetStrongNameKey();
        if (pSnKey)
            EmitStrongNameReservedArea(pSnKey, textSection);

        EmitMetaData();

        EmitEnd();

        if (pSnKey)
            EmitStrongName(modName, pSnKey);
        
        m_isClosed = true;        
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::Finalize()
    {
        if (!m_ceeFile)
        {
            auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
            comCeeFileGen.DestroyCeeFile(&m_ceeFile);
            m_ceeFile = nullptr;
        }
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetCOMMetaDataEmit(IMetaDataEmit2 *pComMetaEmt)
    {
        _ASSERTE(m_pComMetaEmt.p == nullptr);
        m_pComMetaEmt = pComMetaEmt;
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetImageFlags(ComImageFlags const &imageFlags)
    {
        _ASSERTE(m_imageFlags == ComImageFlags::CIF_UNREACHED);
        _ASSERTE(imageFlags != ComImageFlags::CIF_UNREACHED);
        m_imageFlags = imageFlags;
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetCreateFlags(CeeCreateFlags const &createFlags)
    {
        _ASSERTE(m_createFlags == CeeCreateFlags::CCF_UNREACHED);
        _ASSERTE(createFlags != CeeCreateFlags::CCF_UNREACHED);
        m_createFlags = createFlags;
    }



    template<class ApiHolder>    
    HCEESECTION BasePortableExecutableWriterPimpl<ApiHolder>::GetTextSection()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto textSection = static_cast<HCEESECTION>(nullptr);
        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.GetIlSection(comCeeFile, &textSection);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        return textSection;
    }
    
    
    
    template<class ApiHolder>    
    BYTE *BasePortableExecutableWriterPimpl<ApiHolder>::GetSectionBlock(HCEESECTION textSection, ULONG totalSize, ULONG align)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto *pBuffer = static_cast<BYTE *>(nullptr);
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.GetSectionBlock(textSection, totalSize, align, reinterpret_cast<void **>(&pBuffer));
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        return pBuffer;
    }



    template<class ApiHolder>    
    ULONG BasePortableExecutableWriterPimpl<ApiHolder>::GetSectionDataLen(HCEESECTION textSection)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto offset = 0ul;
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.GetSectionDataLen(textSection, &offset);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        return offset;
    }



    template<class ApiHolder>    
    ULONG BasePortableExecutableWriterPimpl<ApiHolder>::GetCodeRVA(ULONG offset)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto codeRVA = 0ul;
        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.GetMethodRVA(comCeeFile, offset, &codeRVA);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        return codeRVA;
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::EmitOptions(wstring const &modName)
    {
        CPPANONYM_LOG_FUNCTION();

        SetOutputFileName(modName);
        CPPANONYM_D_LOGW1(L"Module Name: %|1$s|", modName);
        SetComImageFlags();
        SetSubsystem();
        SetDllSwitch();
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::EmitMethodBody(IMethodBody const *pBody, HCEESECTION &textSection)
    {
        CPPANONYM_LOG_FUNCTION();

        auto const &header = pBody->GetRawHeader();
        auto const &body = pBody->GetRawBody();
        auto const &ehClauses = pBody->GetRawEHClauses();
        auto moreSections = !ehClauses.empty();
        auto codeSize = body.size();
        auto codeSizeAligned = codeSize;
        if (moreSections)
            codeSizeAligned = (codeSizeAligned + 3) & ~3;
        auto headerSize = COR_ILMETHOD::Size(&header, moreSections);
        auto ehSize = ehClauses.empty() ? 0 : COR_ILMETHOD_SECT_EH::Size(static_cast<UINT>(ehClauses.size()), &ehClauses[0]);
        auto totalSize = headerSize + codeSizeAligned + ehSize;
        CPPANONYM_D_LOGW1(L"Header IsFat?: %|1$d|", (headerSize != 1));
        CPPANONYM_D_LOGW1(L"Header Size: %|1$d|", headerSize);
        CPPANONYM_D_LOGW1(L"EH Clauses Count: %|1$d|", ehClauses.size());
        CPPANONYM_D_LOGW1(L"More Sections: %|1$d|", moreSections);
        CPPANONYM_D_LOGW1(L"EH Clauses Size: %|1$d|", ehSize);
        CPPANONYM_D_LOGW1(L"Local Variable Token: 0x%|1$08X|", header.GetLocalVarSigTok());
        CPPANONYM_D_LOGW1(L"Method Body Total Size: %|1$d|", totalSize);

        
        auto pBuffer = GetSectionBlock(textSection, static_cast<ULONG>(totalSize), headerSize != 1 ? 4 : 1);
        auto offset = GetSectionDataLen(textSection);
        offset -= static_cast<ULONG>(totalSize);
        auto codeRVA = GetCodeRVA(offset);
        CPPANONYM_D_LOGW1(L"Method RVA: 0x%|1$08X|", codeRVA);

        SetMethodProps(pBody->GetMethod(), codeRVA);

        
        pBuffer += COR_ILMETHOD::Emit(headerSize, &header, moreSections, pBuffer);
        
        ::ZeroMemory(pBuffer, codeSizeAligned);
        ::memcpy_s(pBuffer, totalSize - headerSize, &body[0], body.size());
        pBuffer += codeSizeAligned;
        
        if (!ehClauses.empty())
            pBuffer += COR_ILMETHOD_SECT_EH::Emit(ehSize, static_cast<UINT>(ehClauses.size()), &ehClauses[0], false, pBuffer);
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::EmitStrongNameReservedArea(AutoPtr<IStrongNameKey const> const &pSnKey, HCEESECTION &textSection)
    {
        CPPANONYM_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto reserveSize = pSnKey->GetSignatureSize();
        CPPANONYM_D_LOGW1(L"Strong Name Reserve Size: %|1$d|", reserveSize);

        auto pBuffer = GetSectionBlock(textSection, reserveSize, 1);
        auto offset = GetSectionDataLen(textSection);
        offset -= reserveSize;
        auto codeRVA = GetCodeRVA(offset);

        ::ZeroMemory(pBuffer, reserveSize);
        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.SetStrongNameEntry(comCeeFile, reserveSize, codeRVA);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::EmitMetaData()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.EmitMetaDataEx(comCeeFile, m_pComMetaEmt);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::EmitEnd()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.GenerateCeeFile(comCeeFile);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::EmitStrongName(wstring const &modName, AutoPtr<IStrongNameKey const> const &pSnKey)
    {
        m_pSnInfo->SetSignature(modName, pSnKey.Get());
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetOutputFileName(wstring const &modName)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.SetOutputFileName(comCeeFile, const_cast<LPWSTR>(modName.c_str()));
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetComImageFlags()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.SetComImageFlags(comCeeFile, m_imageFlags.Value());
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetSubsystem()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        // TODO: 外から与えてもらわないと決められない。.NET の AssemblyBuilder には、SetEntryPoint(MethodInfo, PEFileKinds) ってメソッドがあるから、それっぽいのを追加。
        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.SetSubsystem(comCeeFile, IMAGE_SUBSYSTEM_WINDOWS_CUI, 4, 0);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetDllSwitch()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        // TODO: 外から与えてもらわないと決められない。.NET の AssemblyBuilder には、SetEntryPoint(MethodInfo, PEFileKinds) ってメソッドがあるから、それっぽいのを追加。

        auto &comCeeFile = GetCOMCeeFile();
        auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
        auto hr = comCeeFileGen.SetDllSwitch(comCeeFile, true);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BasePortableExecutableWriterPimpl<ApiHolder>::SetMethodProps(IMethod const *pMethod, ULONG codeRVA)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto hr = m_pComMetaEmt->SetMethodProps(pMethod->GetToken(), -1, codeRVA, 0);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    HCEEFILE &BasePortableExecutableWriterPimpl<ApiHolder>::GetCOMCeeFile()
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (!m_ceeFile)
        {
            auto &comCeeFileGen = m_pPEInfo->GetCOMCeeFileGen();
            auto hr = comCeeFileGen.CreateCeeFileEx(&m_ceeFile, m_createFlags.Value());
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }
        return m_ceeFile;
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEPORTABLEEXECUTABLEWRITERPIMPL_HPP

