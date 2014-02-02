/* 
 * File: Test.Urasandesu.Swathe.cpp
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


// Test.Urasandesu.Swathe.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_SWATHE_APIHOLDERS_DEFAULTSWATHESTORAGEAPIHOLDER_H
#include <Urasandesu/Swathe/DefaultClassApiHolder/DefaultSwatheStorageApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_SWATHESTORAGE_H
#include <Urasandesu/Swathe/SwatheStorage.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFO_H
#include <Urasandesu/Swathe/Hosting/HostInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_RUNTIMEHOST_H
#include <Urasandesu/Swathe/Hosting/RuntimeHost.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultPortableExecutableInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFO_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATAINFO_H
#include <Urasandesu/Swathe/Metadata/MetadataInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADISPENSER_H
#include <Urasandesu/Swathe/Metadata/MetadataDispenser.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATA_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultModuleMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATA_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATA_H
#include <Urasandesu/Swathe/Metadata/TypeMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODMETADATA_H
#include <Urasandesu/Swathe/Metadata/MethodMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATA_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATA_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/DefaultClassApiHolder/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFO_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_DEFAULTCLASSAPIHOLDER_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/DefaultClassApiHolder/DefaultStrongNameKeyApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEKEY_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameKey.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/AssemblyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultModuleGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/ModuleGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/TypeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTFIELDGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultFieldGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_FIELDGENERATOR_H
#include <Urasandesu/Swathe/Metadata/FieldGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODGENERATOR_H
#include <Urasandesu/Swathe/Metadata/MethodGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/PropertyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTLOCALGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultLocalGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATOR_H
#include <Urasandesu/Swathe/Metadata/LocalGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEWRITERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultPortableExecutableWriterApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEWRITER_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableWriter.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTCUSTOMATTRIBUTEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultCustomAttributeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CUSTOMATTRIBUTEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/CustomAttributeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATARESOLVER_H
#include <Urasandesu/Swathe/Metadata/MetadataResolver.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFO_H
#include <Urasandesu/Swathe/Fusion/FusionInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYCACHEAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyCacheApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHE_H
#include <Urasandesu/Swathe/Fusion/AssemblyCache.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/Swathe/Fusion/AssemblyInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYNAMEAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyNameApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAME_H
#include <Urasandesu/Swathe/Fusion/AssemblyName.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYNAMERANGEAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyNameRangeApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMERANGE_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameRange.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYNAMEITERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Fusion/DefaultClassApiHolder/DefaultAssemblyNameIteratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYNAMEITERATOR_H
#include <Urasandesu/Swathe/Fusion/AssemblyNameIterator.h>
#endif

// Test.Urasandesu.Swathe.exe --gtest_filter=Urasandesu_Swathe_Test3.*
namespace {

    CPPANONYM_TEST(Urasandesu_Swathe_Test3, Test_01)
    {
        //::_CrtSetBreakAlloc(5471);
        using Urasandesu::CppAnonym::Utilities::AutoPtr;

        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace Urasandesu::Swathe::StrongNaming;
        using boost::assign::operator +=;
        using boost::get;
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::Empty;

        auto const *pHost = HostInfo::CreateHost();
        ASSERT_TRUE(pHost != nullptr);

        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntime != nullptr);

        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        ASSERT_TRUE(pMetaInfo != nullptr);

        auto *pMetaDisp = pMetaInfo->CreateDispenser();
        ASSERT_TRUE(pMetaDisp != nullptr);

        auto const *pSystemCore = pMetaDisp->GetAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, " 
                                                         L"PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                                       L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        ASSERT_TRUE(pMSCorLib != nullptr);
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());   // !! CAUTION: This is CORRECT !!

        auto const *pSystemCoreDll = pSystemCore->GetModule(L"System.Core.dll");
        ASSERT_EQ(0x00000001, pSystemCoreDll->GetToken());

        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        ASSERT_EQ(0x00000001, pMSCorLibDll->GetToken());

        auto const *pVoid = pMSCorLibDll->GetType(L"System.Void");
        ASSERT_EQ(0x02000125, pVoid->GetToken());

        auto const *pObject = pMSCorLibDll->GetType(L"System.Object");
        ASSERT_EQ(0x02000002, pObject->GetToken());

        auto const *pIntPtr = pMSCorLibDll->GetType(L"System.IntPtr");
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());

        auto const *pDateTime = pMSCorLibDll->GetType(L"System.DateTime");
        ASSERT_EQ(0x02000032, pDateTime->GetToken());

        auto const *pFunc1 = pSystemCoreDll->GetType(L"System.Func`1");
        ASSERT_TRUE(pFunc1->IsGenericType());
        ASSERT_TRUE(pFunc1->IsGenericTypeDefinition());
        {
            auto const &genericArgs = pFunc1->GetGenericArguments();
            ASSERT_EQ(1, genericArgs.size());
            for (auto i = 0u; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_TRUE(genericArgs[i]->IsGenericParameter());
                        ASSERT_EQ(0x2A000010, genericArgs[i]->GetToken());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
        }
        ASSERT_EQ(0x02000058, pFunc1->GetToken());

        auto const *pFunc1DateTime = static_cast<IType *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pDateTime);
            pFunc1DateTime = pFunc1->MakeGenericType(genericArgs);
        }
        ASSERT_TRUE(pFunc1DateTime->IsGenericType());
        ASSERT_FALSE(pFunc1DateTime->IsGenericTypeDefinition());
        {
            auto const &genericArgs = pFunc1DateTime->GetGenericArguments();
            ASSERT_EQ(1, genericArgs.size());
            for (auto i = 0u; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_FALSE(genericArgs[i]->IsGenericParameter());
                        ASSERT_EQ(0x02000032, genericArgs[i]->GetToken());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
        }
        ASSERT_EQ(0x02000058, pFunc1DateTime->GetToken());   // !! CAUTION: This is CORRECT !!

        auto const *pFunc1DateTime_ctor = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pObject);
            params.push_back(pIntPtr);
            pFunc1DateTime_ctor = pFunc1DateTime->GetMethod(L".ctor", CallingConventions::CC_HAS_THIS, pVoid, params);
        }
        ASSERT_EQ(0x06000232, pFunc1DateTime_ctor->GetToken());   // !! CAUTION: This is CORRECT !!

        auto const *pDateTime_get_UtcNow = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            pDateTime_get_UtcNow = pDateTime->GetMethod(L"get_UtcNow", CallingConventions::CC_STANDARD, pDateTime, params);
        }
        ASSERT_EQ(0x060002D3, pDateTime_get_UtcNow->GetToken());

        auto const *pDateTime_ToLocalTime = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            pDateTime_ToLocalTime = pDateTime->GetMethod(L"ToLocalTime", CallingConventions::CC_HAS_THIS, pDateTime, params);
        }
        ASSERT_EQ(0x060002E7, pDateTime_ToLocalTime->GetToken());




        auto const *pSnInfo = pRuntime->GetInfo<StrongNameInfo>();
        ASSERT_TRUE(pSnInfo != nullptr);

        auto pSnKey = pSnInfo->NewStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        auto const &publicKey = pSnKey->GetPublicKey();
        auto PUB_KEY_BLOB = vector<BYTE>();
        PUB_KEY_BLOB += 
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x19, 0xc4, 0x67, 0xdf, 0x70, 0xd1, 0xae, 0xf6, 
            0x96, 0x95, 0xf6, 0x8e, 0x65, 0xaf, 0x52, 0x46, 
            0x0b, 0x8e, 0x00, 0x94, 0x1f, 0x4a, 0x17, 0x5f, 
            0x4d, 0xf8, 0xd3, 0x70, 0x9f, 0x1a, 0x32, 0xd9, 
            0xf3, 0xff, 0xf6, 0xfd, 0x68, 0xb8, 0x79, 0xdc, 
            0x3d, 0xad, 0x60, 0x63, 0x2a, 0x9b, 0x6d, 0x9a, 
            0x5f, 0xc1, 0x9e, 0xf8, 0xb9, 0xd9, 0xae, 0x7a, 
            0xe9, 0xfe, 0x2a, 0xf2, 0x5e, 0x29, 0x02, 0x1b, 
            0xa2, 0x66, 0xad, 0x0b, 0x83, 0x7f, 0xc8, 0x22, 
            0x2f, 0xf5, 0x51, 0x55, 0x67, 0x68, 0xa1, 0x1b, 
            0xae, 0x1d, 0xe5, 0xf7, 0xca, 0xad, 0xf8, 0xc7, 
            0x78, 0x19, 0xfc, 0xfb, 0x8b, 0x3b, 0x73, 0x0b, 
            0x38, 0xe1, 0xeb, 0xcd, 0x68, 0x3d, 0x12, 0xdd, 
            0x87, 0x4f, 0x42, 0x8f, 0xbb, 0x0d, 0xb5, 0xd6, 
            0x92, 0xda, 0xfa, 0x66, 0xa3, 0xe3, 0x6a, 0x8b, 
            0x28, 0xb2, 0x36, 0xb8, 0xde, 0x56, 0x07, 0xda
        ;

        ASSERT_EQ(148, publicKey.size());
        for (auto i = 0u; i < publicKey.size(); ++i)
            ASSERT_EQ(PUB_KEY_BLOB[PUB_KEY_BLOB.size() - publicKey.size() + i], publicKey[i]);
        
        auto *pMSCorLibPrigGen = pMetaDisp->DefineAssemblyWithPartialName(L"mscorlib.Prig");
        pMSCorLibPrigGen->SetStrongNameKey(pSnKey);
        ASSERT_EQ(wstring(L"mscorlib.Prig"), pMSCorLibPrigGen->GetName());
        ASSERT_TRUE(pMSCorLibPrigGen->GetStrongNameKey());

        auto *pMSCorLibPrigDllGen = pMSCorLibPrigGen->DefineModule(L"mscorlib.Prig.dll");
        ASSERT_EQ(wstring(L"mscorlib.Prig.dll"), pMSCorLibPrigDllGen->GetName());

        auto *pPDateTimeGen = pMSCorLibPrigDllGen->DefineType(L"System.Prig.PDateTime",
                                                              TypeAttributes::TA_PUBLIC | 
                                                              TypeAttributes::TA_ABSTRACT | 
                                                              TypeAttributes::TA_ANSI_CLASS | 
                                                              TypeAttributes::TA_SEALED | 
                                                              TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_EQ(wstring(L"System.Prig.PDateTime"), pPDateTimeGen->GetFullName());
        ASSERT_TRUE((pPDateTimeGen->GetAttribute() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_FALSE((pPDateTimeGen->GetAttribute() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);

        auto *pNowGetGen = pPDateTimeGen->DefineNestedType(L"NowGet", 
                                                           TypeAttributes::TA_ABSTRACT | 
                                                           TypeAttributes::TA_ANSI_CLASS | 
                                                           TypeAttributes::TA_SEALED | 
                                                           TypeAttributes::TA_NESTED_PUBLIC | 
                                                           TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_EQ(wstring(L"NowGet"), pNowGetGen->GetFullName());
        ASSERT_TRUE((pNowGetGen->GetAttribute() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_TRUE((pNowGetGen->GetAttribute() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);
        
        auto *pNowGetGen_m_body = pNowGetGen->DefineField(L"m_body", 
                                                          pFunc1DateTime, 
                                                          FieldAttributes::FA_PRIVATE | 
                                                          FieldAttributes::FA_STATIC);
        ASSERT_EQ(wstring(L"m_body"), pNowGetGen_m_body->GetName());
        ASSERT_TRUE((pNowGetGen_m_body->GetAttribute() & FieldAttributes::FA_PRIVATE) == FieldAttributes::FA_PRIVATE);
        ASSERT_FALSE((pNowGetGen_m_body->GetAttribute() & FieldAttributes::FA_PUBLIC) == FieldAttributes::FA_PUBLIC);

        auto *pNowGetGen_get_Body = pNowGetGen->DefineMethod(L"get_Body", 
                                                             MethodAttributes::MA_PUBLIC | 
                                                             MethodAttributes::MA_HIDE_BY_SIG | 
                                                             MethodAttributes::MA_SPECIAL_NAME | 
                                                             MethodAttributes::MA_STATIC, 
                                                             CallingConventions::CC_STANDARD, 
                                                             pFunc1DateTime, 
                                                             vector<IType const *>());
        ASSERT_EQ(wstring(L"get_Body"), pNowGetGen_get_Body->GetName());
        ASSERT_TRUE(pNowGetGen_get_Body->GetCallingConvention() == CallingConventions::CC_STANDARD);
        ASSERT_EQ(0, pNowGetGen_get_Body->GetParameters().size());
        ASSERT_TRUE((pNowGetGen_get_Body->GetAttribute() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pNowGetGen_get_Body->GetAttribute() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        auto set_BodyParams = vector<IType const *>();
        set_BodyParams.push_back(pFunc1DateTime);
        auto *pNowGetGen_set_Body = pNowGetGen->DefineMethod(L"set_Body",
                                                             MethodAttributes::MA_PUBLIC | 
                                                             MethodAttributes::MA_HIDE_BY_SIG | 
                                                             MethodAttributes::MA_SPECIAL_NAME | 
                                                             MethodAttributes::MA_STATIC, 
                                                             CallingConventions::CC_STANDARD, 
                                                             pVoid, 
                                                             set_BodyParams);
        ASSERT_EQ(wstring(L"set_Body"), pNowGetGen_set_Body->GetName());
        ASSERT_TRUE(pNowGetGen_set_Body->GetCallingConvention() == CallingConventions::CC_STANDARD);
        ASSERT_EQ(1, pNowGetGen_set_Body->GetParameters().size());
        ASSERT_TRUE((pNowGetGen_set_Body->GetAttribute() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pNowGetGen_set_Body->GetAttribute() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        auto *pNowGetGen_Body = pNowGetGen->DefineProperty(L"Body", 
                                                           PropertyAttributes::PA_NONE, 
                                                           pFunc1DateTime, 
                                                           vector<IType const *>());
        pNowGetGen_Body->SetGetMethod(pNowGetGen_get_Body);
        pNowGetGen_Body->SetSetMethod(pNowGetGen_set_Body);
        ASSERT_EQ(wstring(L"Body"), pNowGetGen_Body->GetName());
        ASSERT_TRUE(pNowGetGen_Body->GetPropertyType()->GetSourceType() == pFunc1DateTime->GetSourceType());
        ASSERT_EQ(0, pNowGetGen_Body->GetParameters().size());
        ASSERT_TRUE((pNowGetGen_Body->GetAttribute() & PropertyAttributes::PA_NONE) == PropertyAttributes::PA_NONE);
        ASSERT_FALSE((pNowGetGen_Body->GetAttribute() & PropertyAttributes::PA_SPECIAL_NAME) == PropertyAttributes::PA_SPECIAL_NAME);
        ASSERT_TRUE(pNowGetGen_Body->GetGetMethod() == pNowGetGen_get_Body);
        ASSERT_TRUE(pNowGetGen_Body->GetSetMethod() == pNowGetGen_set_Body);

        auto *pNowGetGen_cctor = pNowGetGen->DefineMethod(L".cctor", 
                                                          MethodAttributes::MA_PUBLIC | 
                                                          MethodAttributes::MA_HIDE_BY_SIG | 
                                                          MethodAttributes::MA_SPECIAL_NAME | 
                                                          MethodAttributes::MA_STATIC, 
                                                          CallingConventions::CC_STANDARD, 
                                                          pVoid, 
                                                          vector<IType const *>());
        
        auto *pNowGetGen_Initializeget_Body = pNowGetGen->DefineMethod(L"Initializeget_Body", 
                                                                       MethodAttributes::MA_PUBLIC | 
                                                                       MethodAttributes::MA_HIDE_BY_SIG | 
                                                                       MethodAttributes::MA_SPECIAL_NAME | 
                                                                       MethodAttributes::MA_STATIC, 
                                                                       CallingConventions::CC_STANDARD, 
                                                                       pDateTime, 
                                                                       vector<IType const *>());
        
        {
            auto *pBody = pNowGetGen_get_Body->DefineMethodBody();
            pBody->Emit(OpCodes::Ldsfld, pNowGetGen_m_body);
            pBody->Emit(OpCodes::Ret);
            {
                auto const &insts = pBody->GetInstructions();
                ASSERT_EQ(2, insts.size());
                for (auto i = 0; i < insts.size(); ++i)
                {
                    auto const &opcode = insts[i]->GetOpCode();
                    auto const &operand = insts[i]->GetOperand();
                    switch (i)
                    {
                        case 0:
                            ASSERT_EQ(&OpCodes::Ldsfld, &opcode);
                            ASSERT_EQ(pNowGetGen_m_body, get<IField const *>(operand));
                            break;
                        case 1:
                            ASSERT_EQ(&OpCodes::Ret, &opcode);
                            ASSERT_TRUE(Empty(operand));
                            break;
                        default:
                            FAIL() << "We shouldn't get here!!";
                    }
                }
            }
        }
        {
            auto *pBody = pNowGetGen_set_Body->DefineMethodBody();
            pBody->Emit(OpCodes::Ldarg_0);
            pBody->Emit(OpCodes::Stsfld, pNowGetGen_m_body);
            pBody->Emit(OpCodes::Ret);
        }
        {
            auto *pBody = pNowGetGen_cctor->DefineMethodBody();
            pBody->Emit(OpCodes::Ldnull);
            pBody->Emit(OpCodes::Ldftn, pNowGetGen_Initializeget_Body);
            pBody->Emit(OpCodes::Newobj, pFunc1DateTime_ctor);
            pBody->Emit(OpCodes::Stsfld, pNowGetGen_m_body);
            pBody->Emit(OpCodes::Ret);
        }
        {
            auto *pBody = pNowGetGen_Initializeget_Body->DefineMethodBody();
            auto *pLocal0 = pBody->DefineLocal(pDateTime);
            pBody->Emit(OpCodes::Call, pDateTime_get_UtcNow);
            pBody->Emit(OpCodes::Stloc_0);
            pBody->Emit(OpCodes::Ldloca, static_cast<SHORT>(0x00));
            pBody->Emit(OpCodes::Call, pDateTime_ToLocalTime);
            pBody->Emit(OpCodes::Ret);
        }

        pMSCorLibPrigGen->Save(PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
    }



    CPPANONYM_TEST(Urasandesu_Swathe_Test3, Test_02)
    {
        using Urasandesu::CppAnonym::Utilities::AutoPtr;

        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace Urasandesu::Swathe::StrongNaming;
        using boost::assign::operator +=;
        using boost::get;
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::Empty;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                                       L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");

        auto const *pPrigFramework = pMetaDisp->GetAssembly(L"Urasandesu.Prig.Framework, Version=1.0.0.0, Culture=neutral, "
                                                            L"PublicKeyToken=acabb3ef0ebf69ce, processorArchitecture=x86");

        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        auto const *pPrigFrameworkDll = pPrigFramework->GetModule(L"Urasandesu.Prig.Framework.dll");

        auto const *pVoid = pMSCorLibDll->GetType(L"System.Void");
        auto const *pDateTime = pMSCorLibDll->GetType(L"System.DateTime");
        auto const *pUInt32 = pMSCorLibDll->GetType(L"System.UInt32");
        auto const *pString = pMSCorLibDll->GetType(L"System.String");
        auto const *pType = pMSCorLibDll->GetType(L"System.Type");
        auto const *pRuntimeTypeHandle = pMSCorLibDll->GetType(L"System.RuntimeTypeHandle");
        auto const *pAssembly = pMSCorLibDll->GetType(L"System.Reflection.Assembly");
        auto const *pIndirectableAttrType = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectableAttribute");
        auto const *pIndirectionInfo = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectionInfo");
        auto const *pIndirectionHolder1 = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectionHolder`1");
        auto const *pIndirectionFunc1 = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectionFunc`1");
        auto const *pLooseCrossDomainAccessor = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.LooseCrossDomainAccessor");

        auto const *pIndirectionFunc1DateTime = static_cast<IType *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pDateTime);
            pIndirectionFunc1DateTime = pIndirectionFunc1->MakeGenericType(genericArgs);
        }
        auto const *pIndirectionHolder1IndirectionFunc1DateTime = static_cast<IType *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pIndirectionFunc1DateTime);
            pIndirectionHolder1IndirectionFunc1DateTime = pIndirectionHolder1->MakeGenericType(genericArgs);
        }

        auto const *pIndirectionInfo_set_AssemblyName = pIndirectionInfo->GetMethod(L"set_AssemblyName");
        auto const *pIndirectionInfo_set_Token = pIndirectionInfo->GetMethod(L"set_Token");
        auto const *pLooseCrossDomainAccessor_TryGet = pLooseCrossDomainAccessor->GetMethod(L"TryGet");
        auto const *pLooseCrossDomainAccessor_GetOrRegister = pLooseCrossDomainAccessor->GetMethod(L"GetOrRegister");
        auto const *pIndirectionHolder1IndirectionFunc1DateTime_TryRemove = pIndirectionHolder1IndirectionFunc1DateTime->GetMethod(L"TryRemove");
        auto const *pIndirectionHolder1IndirectionFunc1DateTime_AddOrUpdate = pIndirectionHolder1IndirectionFunc1DateTime->GetMethod(L"AddOrUpdate");
        auto const *pIndirectableAttr_ctor = static_cast<IMethod *>(nullptr);
        {
            auto paramTypes = vector<IType const *>();
            paramTypes.push_back(pUInt32);
            pIndirectableAttr_ctor = pIndirectableAttrType->GetConstructor(paramTypes);
        }

        auto const *pLooseCrossDomainAccessor_TryGetIndirectionHolder1IndirectionFunc1DateTime = static_cast<IMethod *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pIndirectionHolder1IndirectionFunc1DateTime);
            pLooseCrossDomainAccessor_TryGetIndirectionHolder1IndirectionFunc1DateTime = pLooseCrossDomainAccessor_TryGet->MakeGenericMethod(genericArgs);
        }

        auto const *pLooseCrossDomainAccessor_GetOrRegisterIndirectionHolder1IndirectionFunc1DateTime = static_cast<IMethod *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pIndirectionHolder1IndirectionFunc1DateTime);
            pLooseCrossDomainAccessor_GetOrRegisterIndirectionHolder1IndirectionFunc1DateTime = pLooseCrossDomainAccessor_GetOrRegister->MakeGenericMethod(genericArgs);
        }




        auto const *pSnInfo = pRuntime->GetInfo<StrongNameInfo>();
        auto pSnKey = pSnInfo->NewStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");

        auto *pMSCorLibPrigGen = pMetaDisp->DefineAssemblyWithPartialName(L"mscorlib.Prig");
        pMSCorLibPrigGen->SetStrongNameKey(pSnKey);

        auto *pIndirectableAttrGen = static_cast<ICustomAttribute *>(nullptr);
        {
            auto constructorArgs = vector<CustomAttributeArgument>();
            constructorArgs.push_back(0x060002D2u);
            pIndirectableAttrGen = pMSCorLibPrigGen->DefineCustomAttribute(pIndirectableAttr_ctor, constructorArgs);
        }

        auto *pMSCorLibPrigDllGen = pMSCorLibPrigGen->DefineModule(L"mscorlib.Prig.dll");

        auto *pPDateTimeGen = pMSCorLibPrigDllGen->DefineType(L"System.Prig.PDateTime",
                                                              TypeAttributes::TA_PUBLIC |
                                                              TypeAttributes::TA_ABSTRACT |
                                                              TypeAttributes::TA_ANSI_CLASS |
                                                              TypeAttributes::TA_SEALED |
                                                              TypeAttributes::TA_BEFORE_FIELD_INIT);

        auto *pNowGetGen = pPDateTimeGen->DefineNestedType(L"NowGet",
                                                           TypeAttributes::TA_ABSTRACT |
                                                           TypeAttributes::TA_ANSI_CLASS |
                                                           TypeAttributes::TA_SEALED |
                                                           TypeAttributes::TA_NESTED_PUBLIC |
                                                           TypeAttributes::TA_BEFORE_FIELD_INIT);

        auto set_BodyParams = vector<IType const *>();
        set_BodyParams.push_back(pIndirectionFunc1DateTime);
        auto *pNowGetGen_set_Body = pNowGetGen->DefineMethod(L"set_Body",
                                                             MethodAttributes::MA_PUBLIC |
                                                             MethodAttributes::MA_HIDE_BY_SIG |
                                                             MethodAttributes::MA_SPECIAL_NAME |
                                                             MethodAttributes::MA_STATIC,
                                                             CallingConventions::CC_STANDARD,
                                                             pVoid,
                                                             set_BodyParams);

        auto *pNowGetGen_Body = pNowGetGen->DefineProperty(L"Body",
                                                           PropertyAttributes::PA_NONE,
                                                           pIndirectionFunc1DateTime,
                                                           vector<IType const *>());
        pNowGetGen_Body->SetSetMethod(pNowGetGen_set_Body);

        {
            auto *pBodyGen = pNowGetGen_set_Body->DefineMethodBody();

            auto *pLocal0_info = pBodyGen->DefineLocal(pIndirectionInfo);
            auto *pLocal1_holder = pBodyGen->DefineLocal(pIndirectionHolder1IndirectionFunc1DateTime);
            auto *pLocal2_method = pBodyGen->DefineLocal(pIndirectionFunc1DateTime);
            auto *pLocal3_V_3 = pBodyGen->DefineLocal(pIndirectionHolder1IndirectionFunc1DateTime);

            auto label0 = pBodyGen->DefineLabel();
            auto label1 = pBodyGen->DefineLabel();

            pBodyGen->Emit(OpCodes::Ldloca_S, pLocal0_info);
            pBodyGen->Emit(OpCodes::Initobj, pIndirectionInfo);
            pBodyGen->Emit(OpCodes::Ldloca_S, pLocal0_info);
            pBodyGen->Emit(OpCodes::Ldstr, L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
            pBodyGen->Emit(OpCodes::Call, pIndirectionInfo_set_AssemblyName);
            pBodyGen->Emit(OpCodes::Ldloca_S, pLocal0_info);
            pBodyGen->Emit(OpCodes::Ldc_I4, 0x60002d2);
            pBodyGen->Emit(OpCodes::Call, pIndirectionInfo_set_Token);
            pBodyGen->Emit(OpCodes::Ldarg_0);
            pBodyGen->Emit(OpCodes::Brtrue_S, label0);

            pBodyGen->Emit(OpCodes::Ldnull);
            pBodyGen->Emit(OpCodes::Stloc_1);
            pBodyGen->Emit(OpCodes::Ldloca_S, pLocal1_holder);
            pBodyGen->Emit(OpCodes::Call, pLooseCrossDomainAccessor_TryGetIndirectionHolder1IndirectionFunc1DateTime);
            pBodyGen->Emit(OpCodes::Brfalse_S, label1);

            pBodyGen->Emit(OpCodes::Ldnull);
            pBodyGen->Emit(OpCodes::Stloc_2);
            pBodyGen->Emit(OpCodes::Ldloc_1);
            pBodyGen->Emit(OpCodes::Ldloc_0);
            pBodyGen->Emit(OpCodes::Ldloca_S, pLocal2_method);
            pBodyGen->Emit(OpCodes::Callvirt, pIndirectionHolder1IndirectionFunc1DateTime_TryRemove);
            pBodyGen->Emit(OpCodes::Pop);
            pBodyGen->Emit(OpCodes::Ret);

            pBodyGen->MarkLabel(label0);
            pBodyGen->Emit(OpCodes::Call, pLooseCrossDomainAccessor_GetOrRegisterIndirectionHolder1IndirectionFunc1DateTime);
            pBodyGen->Emit(OpCodes::Stloc_3);
            pBodyGen->Emit(OpCodes::Ldloc_3);
            pBodyGen->Emit(OpCodes::Ldloc_0);
            pBodyGen->Emit(OpCodes::Ldarg_0);
            pBodyGen->Emit(OpCodes::Callvirt, pIndirectionHolder1IndirectionFunc1DateTime_AddOrUpdate);
            pBodyGen->Emit(OpCodes::Pop);
            pBodyGen->MarkLabel(label1);
            pBodyGen->Emit(OpCodes::Ret);
        }

        pMSCorLibPrigGen->Save(PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
    }



    CPPANONYM_TEST(Urasandesu_Swathe_Test3, Test_03)
    {
        using Urasandesu::CppAnonym::Utilities::AutoPtr;

        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace Urasandesu::Swathe::StrongNaming;
        using boost::assign::operator +=;
        using boost::get;
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::Empty;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                                       L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");

        auto const *pPrigFramework = pMetaDisp->GetAssembly(L"Urasandesu.Prig.Framework, Version=1.0.0.0, Culture=neutral, "
                                                            L"PublicKeyToken=acabb3ef0ebf69ce, processorArchitecture=x86");

        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        auto const *pPrigFrameworkDll = pPrigFramework->GetModule(L"Urasandesu.Prig.Framework.dll");

        auto const *pDateTime = pMSCorLibDll->GetType(L"System.DateTime");
        auto const *pIndirectionInfo = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectionInfo");
        auto const *pIndirectionHolder1 = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectionHolder`1");
        auto const *pIndirectionFunc1 = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectionFunc`1");
        auto const *pLooseCrossDomainAccessor = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.LooseCrossDomainAccessor");

        auto const *pIndirectionFunc1DateTime = static_cast<IType *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pDateTime);
            pIndirectionFunc1DateTime = pIndirectionFunc1->MakeGenericType(genericArgs);
        }
        auto const *pIndirectionHolder1IndirectionFunc1DateTime = static_cast<IType *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pIndirectionFunc1DateTime);
            pIndirectionHolder1IndirectionFunc1DateTime = pIndirectionHolder1->MakeGenericType(genericArgs);
        }

        auto const *pDateTime_get_UtcNow = pDateTime->GetMethod(L"get_UtcNow");
        auto const *pDateTime_ToLocalTime = pDateTime->GetMethod(L"ToLocalTime");
        auto const *pIndirectionInfo_set_AssemblyName = pIndirectionInfo->GetMethod(L"set_AssemblyName");
        auto const *pIndirectionInfo_set_Token = pIndirectionInfo->GetMethod(L"set_Token");
        auto const *pIndirectionFunc1DateTime_Invoke = pIndirectionFunc1DateTime->GetMethod(L"Invoke");
        auto const *pLooseCrossDomainAccessor_TryGet = pLooseCrossDomainAccessor->GetMethod(L"TryGet");
        auto const *pIndirectionHolder1IndirectionFunc1DateTime_TryGet = pIndirectionHolder1IndirectionFunc1DateTime->GetMethod(L"TryGet");

        auto const *pLooseCrossDomainAccessor_TryGetIndirectionHolder1IndirectionFunc1DateTime = static_cast<IMethod *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pIndirectionHolder1IndirectionFunc1DateTime);
            pLooseCrossDomainAccessor_TryGetIndirectionHolder1IndirectionFunc1DateTime = pLooseCrossDomainAccessor_TryGet->MakeGenericMethod(genericArgs);
        }




        auto const *pSnInfo = pRuntime->GetInfo<StrongNameInfo>();
        auto pSnKey = pSnInfo->NewStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");

        auto *pMSCorLibIndGen = pMetaDisp->DefineAssemblyWithPartialName(L"mscorlib.Indirect");
        pMSCorLibIndGen->SetStrongNameKey(pSnKey);

        auto *pMSCorLibIndDllGen = pMSCorLibIndGen->DefineModule(L"mscorlib.Indirect.dll");

        auto *pIDateTimeGen = pMSCorLibIndDllGen->DefineType(L"System.Indirect.IDateTime",
                                                             TypeAttributes::TA_PUBLIC |
                                                             TypeAttributes::TA_ABSTRACT |
                                                             TypeAttributes::TA_ANSI_CLASS |
                                                             TypeAttributes::TA_SEALED |
                                                             TypeAttributes::TA_BEFORE_FIELD_INIT);

        auto *pIDateTimeGen_get_Now = pIDateTimeGen->DefineMethod(L"get_Now",
                                                                  MethodAttributes::MA_PUBLIC |
                                                                  MethodAttributes::MA_HIDE_BY_SIG |
                                                                  MethodAttributes::MA_SPECIAL_NAME |
                                                                  MethodAttributes::MA_STATIC,
                                                                  CallingConventions::CC_STANDARD,
                                                                  pDateTime,
                                                                  MetadataSpecialValues::EMPTY_TYPES);

        {
            auto *pNewBodyGen = pIDateTimeGen_get_Now->DefineMethodBody();

            auto *pLocal0 = pNewBodyGen->DefineLocal(pDateTime);
            auto *pLocal1_holder = pNewBodyGen->DefineLocal(pIndirectionHolder1IndirectionFunc1DateTime);
            auto *pLocal2_info = pNewBodyGen->DefineLocal(pIndirectionInfo);
            auto *pLocal3_get_Now = pNewBodyGen->DefineLocal(pIndirectionFunc1DateTime);

            auto label0 = pNewBodyGen->DefineLabel();

            pNewBodyGen->Emit(OpCodes::Ldnull);
            pNewBodyGen->Emit(OpCodes::Stloc_S, pLocal1_holder);
            pNewBodyGen->Emit(OpCodes::Ldloca_S, pLocal1_holder);
            pNewBodyGen->Emit(OpCodes::Call, pLooseCrossDomainAccessor_TryGetIndirectionHolder1IndirectionFunc1DateTime);
            pNewBodyGen->Emit(OpCodes::Brfalse_S, label0);

            pNewBodyGen->Emit(OpCodes::Ldloca_S, pLocal2_info);
            pNewBodyGen->Emit(OpCodes::Initobj, pIndirectionInfo);
            pNewBodyGen->Emit(OpCodes::Ldloca_S, pLocal2_info);
            pNewBodyGen->Emit(OpCodes::Ldstr, L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
            pNewBodyGen->Emit(OpCodes::Call, pIndirectionInfo_set_AssemblyName);
            pNewBodyGen->Emit(OpCodes::Ldloca_S, pLocal2_info);
            pNewBodyGen->Emit(OpCodes::Ldc_I4, 0x60002d2);
            pNewBodyGen->Emit(OpCodes::Call, pIndirectionInfo_set_Token);
            pNewBodyGen->Emit(OpCodes::Ldnull);
            pNewBodyGen->Emit(OpCodes::Stloc_S, pLocal3_get_Now);
            pNewBodyGen->Emit(OpCodes::Ldloc_S, pLocal1_holder);
            pNewBodyGen->Emit(OpCodes::Ldloc_S, pLocal2_info);
            pNewBodyGen->Emit(OpCodes::Ldloca_S, pLocal3_get_Now);
            pNewBodyGen->Emit(OpCodes::Callvirt, pIndirectionHolder1IndirectionFunc1DateTime_TryGet);
            pNewBodyGen->Emit(OpCodes::Brfalse_S, label0);

            pNewBodyGen->Emit(OpCodes::Ldloc_S, pLocal3_get_Now);
            pNewBodyGen->Emit(OpCodes::Callvirt, pIndirectionFunc1DateTime_Invoke);
            pNewBodyGen->Emit(OpCodes::Ret);

            pNewBodyGen->MarkLabel(label0);
            pNewBodyGen->Emit(OpCodes::Call, pDateTime_get_UtcNow);
            pNewBodyGen->Emit(OpCodes::Stloc_0);
            pNewBodyGen->Emit(OpCodes::Ldloca, static_cast<SHORT>(0x00));
            pNewBodyGen->Emit(OpCodes::Call, pDateTime_ToLocalTime);
            pNewBodyGen->Emit(OpCodes::Ret);
        }

        pMSCorLibIndGen->Save(PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
    }



    CPPANONYM_TEST(Urasandesu_Swathe_Test3, Test_04)
    {
        using Urasandesu::CppAnonym::Utilities::AutoPtr;

        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace Urasandesu::Swathe::StrongNaming;
        using boost::assign::operator +=;
        using boost::get;
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::Empty;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                                       L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");

        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");


        auto const *pVoid = pMSCorLibDll->GetType(L"System.Void");
        auto const *pInt32 = pMSCorLibDll->GetType(L"System.Int32");
        auto const *pString = pMSCorLibDll->GetType(L"System.String");
        auto const *pStreamReader = pMSCorLibDll->GetType(L"System.IO.StreamReader");
        auto const *pChar = pMSCorLibDll->GetType(L"System.Char");
        auto const *pIOException = pMSCorLibDll->GetType(L"System.IO.IOException");
        auto const *pTextReader = pMSCorLibDll->GetType(L"System.IO.TextReader");
        auto const *pException = pMSCorLibDll->GetType(L"System.Exception");
        auto const *pConsole = pMSCorLibDll->GetType(L"System.Console");
        auto const *pObject = pMSCorLibDll->GetType(L"System.Object");

        auto const *pStreamReader_ctor_string = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pString);
            pStreamReader_ctor_string = pStreamReader->GetConstructor(params);
        }
        auto const *pTextReader_ReadBlock_CharArr_Int32_Int32 = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pChar->MakeArrayType());
            params.push_back(pInt32);
            params.push_back(pInt32);
            pTextReader_ReadBlock_CharArr_Int32_Int32 = pTextReader->GetMethod(L"ReadBlock", params);
        }
        auto const *pTextReader_Close = pTextReader->GetMethod(L"Close");
        auto const *pException_get_Message = pException->GetMethod(L"get_Message");
        auto const *pConsole_WriteLine_string_object_object = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pString);
            params.push_back(pObject);
            params.push_back(pObject);
            pConsole_WriteLine_string_object_object = pConsole->GetMethod(L"WriteLine", params);
        }



        auto const *pSnInfo = pRuntime->GetInfo<StrongNameInfo>();
        auto pSnKey = pSnInfo->NewStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");

        auto *pMSCorLibEHGen = pMetaDisp->DefineAssemblyWithPartialName(L"mscorlib.EH");
        pMSCorLibEHGen->SetStrongNameKey(pSnKey);

        auto *pMSCorLibEHDllGen = pMSCorLibEHGen->DefineModule(L"mscorlib.EH.dll");

        auto *pEHClassGen = pMSCorLibEHDllGen->DefineType(L"mscorlib.Prig.EHClass",
                                                          TypeAttributes::TA_PUBLIC |
                                                          TypeAttributes::TA_AUTO_CLASS |
                                                          TypeAttributes::TA_ANSI_CLASS |
                                                          TypeAttributes::TA_BEFORE_FIELD_INIT);

        auto *pEHClassGen_ReadFile = static_cast<MethodGenerator *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pString);
            params.push_back(pInt32);
            pEHClassGen_ReadFile = pEHClassGen->DefineMethod(L"ReadFile",
                                                             MethodAttributes::MA_PUBLIC | 
                                                             MethodAttributes::MA_HIDE_BY_SIG, 
                                                             CallingConventions::CC_HAS_THIS, 
                                                             pVoid,
                                                             params);
        }

        {
            auto *pBodyGen = pEHClassGen_ReadFile->DefineMethodBody();

            auto *pLocal0_file = pBodyGen->DefineLocal(pStreamReader);
            auto *pLocal1_buffer = pBodyGen->DefineLocal(pChar->MakeArrayType());
            auto *pLocal2_e = pBodyGen->DefineLocal(pIOException);

            auto label0 = pBodyGen->DefineLabel();

            pBodyGen->Emit(OpCodes::Ldnull);
            pBodyGen->Emit(OpCodes::Stloc_0);
            pBodyGen->Emit(OpCodes::Ldc_I4_S, static_cast<BYTE>(10));
            pBodyGen->Emit(OpCodes::Newarr, pChar);
            pBodyGen->Emit(OpCodes::Stloc_1);

            pBodyGen->BeginExceptionBlock();
            {
                pBodyGen->Emit(OpCodes::Ldarg_1);
                pBodyGen->Emit(OpCodes::Newobj, pStreamReader_ctor_string);
                pBodyGen->Emit(OpCodes::Stloc_0);
                pBodyGen->Emit(OpCodes::Ldloc_0);
                pBodyGen->Emit(OpCodes::Ldloc_1);
                pBodyGen->Emit(OpCodes::Ldarg_2);
                pBodyGen->Emit(OpCodes::Ldloc_1);
                pBodyGen->Emit(OpCodes::Ldlen);
                pBodyGen->Emit(OpCodes::Conv_I4);
                pBodyGen->Emit(OpCodes::Callvirt, pTextReader_ReadBlock_CharArr_Int32_Int32);
                pBodyGen->Emit(OpCodes::Pop);
            }
            pBodyGen->BeginCatchBlock(pIOException);
            {
                pBodyGen->Emit(OpCodes::Stloc_2);
                pBodyGen->Emit(OpCodes::Ldstr, L"Error reading from {0}. Message = {1}");
                pBodyGen->Emit(OpCodes::Ldarg_1);
                pBodyGen->Emit(OpCodes::Ldloc_2);
                pBodyGen->Emit(OpCodes::Callvirt, pException_get_Message);
                pBodyGen->Emit(OpCodes::Call, pConsole_WriteLine_string_object_object);
            }
            pBodyGen->BeginFinallyBlock();
            {
                pBodyGen->Emit(OpCodes::Ldloc_0);
                pBodyGen->Emit(OpCodes::Brfalse_S, label0);
                pBodyGen->Emit(OpCodes::Ldloc_0);
                pBodyGen->Emit(OpCodes::Callvirt, pTextReader_Close);
                pBodyGen->MarkLabel(label0);
            }
            pBodyGen->EndExceptionBlock();

            pBodyGen->Emit(OpCodes::Ret);
        }

        pMSCorLibEHGen->Save(PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, GetCustomAttributesTest_01)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;

        using boost::begin;
        using boost::distance;
        using boost::get;
        using boost::filesystem::canonical;
        using boost::filesystem::path;
        
        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();
        
        auto prigFrameworkPath = canonical(path(L"Urasandesu.Prig.Framework.dll"));
        auto const *pPrigFramework = pMetaDisp->GetAssemblyFrom(prigFrameworkPath);
        auto const *pPrigFrameworkDll = pPrigFramework->GetMainModule();
        auto const *pIndirectableAttrInfo = pPrigFrameworkDll->GetType(L"Urasandesu.Prig.Framework.IndirectableAttribute");
        
        auto mscorlibPrigPath = canonical(path(L"..\\mscorlib.Prig\\bin\\Debug\\mscorlib.Prig.dll"));
        auto const *pMSCorLibPrig = pMetaDisp->GetAssemblyFrom(mscorlibPrigPath);
        auto indirectableAttrs = pMSCorLibPrig->GetCustomAttributes(pIndirectableAttrInfo, false);
        ASSERT_EQ(1, distance(indirectableAttrs));
        auto const *pIndirectableAttr = *begin(indirectableAttrs);
        auto const &args = pIndirectableAttr->GetConstructorArguments();
        ASSERT_EQ(1, args.size());
        auto mdmdTarget = get<UINT>(args[0]);
        ASSERT_EQ(0x060002D2, mdmdTarget);
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, GetExceptionClausesTest_01)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;

        using boost::filesystem::canonical;
        using boost::filesystem::path;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::Empty;
        
        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();
        
        auto mscorlibPrigPath = canonical(path(L"..\\mscorlib.Prig\\bin\\Debug\\mscorlib.Prig.dll"));
        auto const *pMSCorLibPrig = pMetaDisp->GetAssemblyFrom(mscorlibPrigPath);
        auto const *pMSCorLibPrigDll = pMSCorLibPrig->GetMainModule();
        auto const *pEHClass = pMSCorLibPrigDll->GetType(L"mscorlib.Prig.EHClass");
        auto const *pEHClass_ReadFile = pEHClass->GetMethod(L"ReadFile");
        {
            auto const *pBody = pEHClass_ReadFile->GetMethodBody();
            auto insts = pBody->GetInstructions();
            ASSERT_EQ(46, insts.size());

            auto exClauses = pBody->GetExceptionClauses();
            ASSERT_EQ(2, exClauses.size());
            {
                auto i = 0ul;
                BOOST_FOREACH (auto const &exClause, exClauses)
                {
                    auto clauseKind = exClause.GetClauseKind();
                    auto tryStart = exClause.GetTryStart();
                    auto tryEnd = exClause.GetTryEnd();
                    auto clauseStart = exClause.GetClauseStart();
                    auto clauseEnd = exClause.GetClauseEnd();
                    
                    auto const &tryStartOpcode = (*tryStart)->GetOpCode();
                    auto const &tryStartOperand = (*tryStart)->GetOperand();
                    
                    auto const &tryEndOpcode = (*tryEnd)->GetOpCode();
                    auto const &tryEndOperand = (*tryEnd)->GetOperand();
                    
                    auto const &clauseStartOpcode = (*clauseStart)->GetOpCode();
                    auto const &clauseStartOperand = (*clauseStart)->GetOperand();
                    
                    auto const &clauseEndOpcode = (*clauseEnd)->GetOpCode();
                    auto const &clauseEndOperand = (*clauseEnd)->GetOperand();

                    switch (i++)
                    {
                        case 0:
                            {
                                ASSERT_TRUE(clauseKind == ClauseKinds::CK_CATCH);

                                ASSERT_EQ(&OpCodes::Nop, &tryStartOpcode);
                                ASSERT_TRUE(Empty(tryStartOperand));

                                ASSERT_EQ(&OpCodes::Stloc_2, &tryEndOpcode);
                                ASSERT_TRUE(Empty(tryEndOperand));

                                ASSERT_EQ(&OpCodes::Stloc_2, &clauseStartOpcode);
                                ASSERT_TRUE(Empty(clauseStartOperand));

                                ASSERT_EQ(&OpCodes::Nop, &clauseEndOpcode);
                                ASSERT_TRUE(Empty(clauseEndOperand));

                                ASSERT_EQ(wstring(L"System.IO.IOException"), exClause.GetExceptionType()->GetFullName());
                            }
                            break;
                        case 1:
                            {
                                ASSERT_TRUE(clauseKind == ClauseKinds::CK_FINALLY);

                                ASSERT_EQ(&OpCodes::Nop, &tryStartOpcode);
                                ASSERT_TRUE(Empty(tryStartOperand));

                                ASSERT_EQ(&OpCodes::Nop, &tryEndOpcode);
                                ASSERT_TRUE(Empty(tryEndOperand));

                                ASSERT_EQ(&OpCodes::Nop, &clauseStartOpcode);
                                ASSERT_TRUE(Empty(clauseStartOperand));

                                ASSERT_EQ(&OpCodes::Nop, &clauseEndOpcode);
                                ASSERT_TRUE(Empty(clauseEndOperand));
                            }
                            break;
                        default:
                            FAIL() << "We shouldn't get here!!";
                            break;
                    }
                }
            }
        }
    }


    CPPANONYM_TEST(Urasandesu_Swathe_Test3, GetParamPropsTest_01)
    {
        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace Urasandesu::Swathe::StrongNaming;
        using boost::adaptors::filtered;
        using boost::assign::operator +=;
        using boost::get;
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::AutoPtr;
        using Urasandesu::CppAnonym::Utilities::Empty;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                                       L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");

        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");

        auto const *pInt32 = pMSCorLibDll->GetType(L"System.Int32");

#if 0
        auto const *pInt32_TryParse_string_int = static_cast<IMethod const *>(nullptr);
        {
            auto methods = pInt32->GetMethods();
            pInt32_TryParse_string_int = *(methods | filtered([](IMethod const *pMethod) { return pMethod->GetToken() == 0x06000B2B; })).begin();
        }

        auto const &params = pInt32_TryParse_string_int->GetParameters();
        ASSERT_EQ(2, params.size());
        auto i = 0ul;
        BOOST_FOREACH (auto const &pParam, params)
        {
            switch (i++)
            {
                case 0:
                    {
                        ASSERT_EQ(wstring(L"s"), pParam->GetName());
                        ASSERT_TRUE(pParam->GetAttribute() == ParameterAttributes::PA_NONE);
                        ASSERT_FALSE(pParam->GetParameterType()->IsByRef());
                        ASSERT_EQ(1, pParam->GetPosition());
                    }
                    break;
                case 1:
                    {
                        ASSERT_EQ(wstring(L"result"), pParam->GetName());
                        ASSERT_TRUE(pParam->GetAttribute() == ParameterAttributes::PA_OUT);
                        ASSERT_TRUE(pParam->GetParameterType()->IsByRef());
                        ASSERT_EQ(2, pParam->GetPosition());
                    }
                    break;
                default:
                    FAIL() << "We shouldn't get here!!";
                    break;
            }
        }
#endif
        auto const *pInt32_ToString_string_IFormatProvider = static_cast<IMethod const *>(nullptr);
        {
            auto methods = pInt32->GetMethods();
            pInt32_ToString_string_IFormatProvider = *(methods | filtered([](IMethod const *pMethod) { return pMethod->GetToken() == 0x06000B26; })).begin();
        }

        auto const &params = pInt32_ToString_string_IFormatProvider->GetParameters();
        ASSERT_EQ(2, params.size());
        auto i = 0ul;
        BOOST_FOREACH (auto const &pParam, params)
        {
            switch (i++)
            {
                case 0:
                    {
                        ASSERT_EQ(wstring(L"format"), pParam->GetName());
                        ASSERT_TRUE(pParam->GetAttribute() == ParameterAttributes::PA_NONE);
                        ASSERT_FALSE(pParam->GetParameterType()->IsByRef());
                        ASSERT_EQ(1, pParam->GetPosition());
                    }
                    break;
                case 1:
                    {
                        ASSERT_EQ(wstring(L"provider"), pParam->GetName());
                        ASSERT_TRUE(pParam->GetAttribute() == ParameterAttributes::PA_NONE);
                        ASSERT_FALSE(pParam->GetParameterType()->IsByRef());
                        ASSERT_EQ(2, pParam->GetPosition());
                    }
                    break;
                default:
                    FAIL() << "We shouldn't get here!!";
                    break;
            }
        }
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, EnumerateAssemblyNameTest_01)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Fusion;
        
        using boost::distance;
        using boost::filesystem::equivalent;        
        using boost::filesystem::path;
        using std::wstring;
        
        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pFuInfo = pRuntime->GetInfo<FusionInfo>();

        auto pAsmCache = pFuInfo->NewAssemblyCache();
        auto pAsmInfo = pAsmCache->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, 
                                                     L"mscorlib, Version=2.0.0.0, Culture=neutral, "
                                                     L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        auto const &asmPath = pAsmInfo->GetAssemblyPath();
        ASSERT_TRUE(equivalent(L"c:\\Windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll", asmPath));

        auto pCondition = pFuInfo->NewAssemblyName(L"mscorlib, Version=2.0.0.0, " 
                                                   L"Culture=neutral, PublicKeyToken=b77a5c561934e089", 
                                                   NewAssemblyNameFlags::NANF_CANOF_PARSE_DISPLAY_NAME);
        ASSERT_TRUE(pCondition->GetPlatform() == Platform::PF_NONE);
        auto pAsmNames = pFuInfo->EnumerateAssemblyName(pCondition, AssemblyCacheFlags::ACF_GAC);
        ASSERT_EQ(2, distance(*pAsmNames));
        {
            auto i = 0ul;
            BOOST_FOREACH (auto const &pAsmName, *pAsmNames)
                switch (i++)
                {
                    case 0:
                        ASSERT_EQ(wstring(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                          L"PublicKeyToken=b77a5c561934e089, processorArchitecture=AMD64"), pAsmName->GetFullName());
                        ASSERT_TRUE(pAsmName->GetPlatform() == Platform::PF_AMD64);
                        break;
                    case 1:
                        ASSERT_EQ(wstring(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                          L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86"), pAsmName->GetFullName());
                        ASSERT_TRUE(pAsmName->GetPlatform() == Platform::PF_I386);
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                        break;
                }
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, EnumerateAssemblyNameTest_02)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Fusion;
        
        using boost::distance;
        using boost::filesystem::equivalent;        
        using boost::filesystem::path;
        using std::wstring;
        
        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pFuInfo = pRuntime->GetInfo<FusionInfo>();

        auto pCondition = pFuInfo->NewAssemblyName(L"hoge, Version=2.0.0.0, " 
                                                   L"Culture=neutral, PublicKeyToken=b77a5c561934e089", 
                                                   NewAssemblyNameFlags::NANF_CANOF_PARSE_DISPLAY_NAME);
        auto pAsmNames = pFuInfo->EnumerateAssemblyName(pCondition, AssemblyCacheFlags::ACF_GAC);
        ASSERT_EQ(0, distance(*pAsmNames));
        ASSERT_EQ(wstring(L"hoge"), pCondition->GetName());

    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, EnumerateInstructionsTest_01)
    {
        using Urasandesu::CppAnonym::Utilities::AutoPtr;

        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using boost::get;
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::Empty;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v2.0.50727");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                                       L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        auto const *pDateTime = pMSCorLibDll->GetType(L"System.DateTime");
        auto const *pDateTime_get_Now = pDateTime->GetMethod(L"get_Now");
        ASSERT_TRUE(pDateTime_get_Now != nullptr);
        {
            auto *pBody = pDateTime_get_Now->GetMethodBody();

            auto const &locals = pBody->GetLocals();
            ASSERT_EQ(1, locals.size());

            ASSERT_EQ(0, locals[0]->GetLocalIndex());
            ASSERT_EQ(wstring(L"System.DateTime"), locals[0]->GetLocalType()->GetFullName());


            auto const &insts = pBody->GetInstructions();
            ASSERT_EQ(5, insts.size());

            ASSERT_EQ(&OpCodes::Call, &insts[0]->GetOpCode());
            ASSERT_EQ(wstring(L"get_UtcNow"), get<IMethod const *>(insts[0]->GetOperand())->GetName());

            ASSERT_EQ(&OpCodes::Stloc_0, &insts[1]->GetOpCode());

            ASSERT_EQ(&OpCodes::Ldloca_S, &insts[2]->GetOpCode());
            ASSERT_EQ(0, get<ILocal const *>(insts[2]->GetOperand())->GetLocalIndex());

            ASSERT_EQ(&OpCodes::Call, &insts[3]->GetOpCode());
            ASSERT_EQ(wstring(L"ToLocalTime"), get<IMethod const *>(insts[3]->GetOperand())->GetName());

            ASSERT_EQ(&OpCodes::Ret, &insts[4]->GetOpCode());
        }
    }
}
