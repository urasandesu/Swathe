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

#ifndef URASANDESU_SWATHE_H
#include <Urasandesu/Swathe.h>
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

        auto const *pSystemCore = pMetaDisp->GetAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        ASSERT_TRUE(pMSCorLib != nullptr);
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());   // !! CAUTION: This is CORRECT !!

        auto const *pSystemCoreDll = pSystemCore->GetModule(L"System.Core.dll");
        ASSERT_EQ(0x00000001, pSystemCoreDll->GetToken());

        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        ASSERT_EQ(0x00000001, pMSCorLibDll->GetToken());

        auto const *pVoid = pMSCorLibDll->GetType(L"System.Void");
#ifdef _M_IX86
        ASSERT_EQ(0x02000125, pVoid->GetToken());
#else
        ASSERT_EQ(0x0200013B, pVoid->GetToken());
#endif
        
        auto const *pObject = pMSCorLibDll->GetType(L"System.Object");
        ASSERT_EQ(0x02000002, pObject->GetToken());

        auto const *pIntPtr = pMSCorLibDll->GetType(L"System.IntPtr");
#ifdef _M_IX86
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());
#else
        ASSERT_EQ(0x020000C7, pIntPtr->GetToken());
#endif

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
        ASSERT_TRUE(pFunc1DateTime_ctor != nullptr);
        ASSERT_EQ(0x06000232, pFunc1DateTime_ctor->GetToken());   // !! CAUTION: This is CORRECT !!
                                                                  // User defined TypeSpec will be invalid until saving the assembly.

        auto const *pDateTime_get_UtcNow = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            pDateTime_get_UtcNow = pDateTime->GetMethod(L"get_UtcNow", CallingConventions::CC_STANDARD, pDateTime, params);
        }
        ASSERT_TRUE(pDateTime_get_UtcNow != nullptr);
#ifdef _M_IX86
        ASSERT_EQ(0x060002D3, pDateTime_get_UtcNow->GetToken());
#else
        ASSERT_EQ(0x060002D6, pDateTime_get_UtcNow->GetToken());
#endif

        auto const *pDateTime_ToLocalTime = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            pDateTime_ToLocalTime = pDateTime->GetMethod(L"ToLocalTime", CallingConventions::CC_HAS_THIS, pDateTime, params);
        }
        ASSERT_TRUE(pDateTime_ToLocalTime != nullptr);
#ifdef _M_IX86
        ASSERT_EQ(0x060002E7, pDateTime_ToLocalTime->GetToken());
#else
        ASSERT_EQ(0x060002EA, pDateTime_ToLocalTime->GetToken());
#endif




        auto const *pSnInfo = pRuntime->GetInfo<StrongNameInfo>();
        ASSERT_TRUE(pSnInfo != nullptr);

        auto pSnKey = pSnInfo->NewStrongNameKey(L"..\\..\\..\\Test.Urasandesu.Swathe.snk");
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
        ASSERT_TRUE(pNowGetGen_Body->GetPropertyType()->GetSourceType()->Equals(pFunc1DateTime->GetSourceType()));
        ASSERT_EQ(0, pNowGetGen_Body->GetParameters().size());
        ASSERT_TRUE((pNowGetGen_Body->GetAttribute() & PropertyAttributes::PA_NONE) == PropertyAttributes::PA_NONE);
        ASSERT_FALSE((pNowGetGen_Body->GetAttribute() & PropertyAttributes::PA_SPECIAL_NAME) == PropertyAttributes::PA_SPECIAL_NAME);
        ASSERT_TRUE(pNowGetGen_Body->GetGetMethod()->Equals(pNowGetGen_get_Body));
        ASSERT_TRUE(pNowGetGen_Body->GetSetMethod()->Equals(pNowGetGen_set_Body));

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

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
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
#ifdef _M_IX86
            pInt32_ToString_string_IFormatProvider = *(methods | filtered([](IMethod const *pMethod) { return pMethod->GetToken() == 0x06000B26; })).begin();
#else
            pInt32_ToString_string_IFormatProvider = *(methods | filtered([](IMethod const *pMethod) { return pMethod->GetToken() == 0x06000B29; })).begin();
#endif
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
        using Urasandesu::CppAnonym::Version;
        
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
                        ASSERT_TRUE(pAsmName->GetVersion() == Version(2, 0, 0, 0));
                        break;
                    case 1:
                        ASSERT_EQ(wstring(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                          L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86"), pAsmName->GetFullName());
                        ASSERT_TRUE(pAsmName->GetPlatform() == Platform::PF_I386);
                        ASSERT_TRUE(pAsmName->GetVersion() == Version(2, 0, 0, 0));
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
            ASSERT_EQ(0, get<BYTE>(insts[2]->GetOperand()));

            ASSERT_EQ(&OpCodes::Call, &insts[3]->GetOpCode());
            ASSERT_EQ(wstring(L"ToLocalTime"), get<IMethod const *>(insts[3]->GetOperand())->GetName());

            ASSERT_EQ(&OpCodes::Ret, &insts[4]->GetOpCode());
        }
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, EnumerateInstructionsTest_02)
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
        auto const *pRuntime = pHost->GetRuntime(L"v4.0.30319");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pSystem = pMetaDisp->GetAssembly(L"System, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        auto const *pSystemDll = pSystem->GetModule(L"System.dll");
        auto const *pWebClient = pSystemDll->GetType(L"System.Net.WebClient");
        auto const *pWebClient_add_DownloadStringCompleted = pWebClient->GetMethod(L"add_DownloadStringCompleted");

        ASSERT_TRUE(pWebClient_add_DownloadStringCompleted != nullptr);
        {
            auto *pBody = pWebClient_add_DownloadStringCompleted->GetMethodBody();

            auto const &locals = pBody->GetLocals();
            ASSERT_EQ(3, locals.size());
            
            auto const &insts = pBody->GetInstructions();
            BOOST_FOREACH (auto const &pInst, insts)
            {
                auto const &opcode = pInst->GetOpCode();
                std::wcout << opcode.GetName() << std::endl;
            }
        }
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, GetRuntimesTest_01)
    {
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::Swathe::Hosting;
        using boost::remove_reference;
        using std::map;
        using std::wstring;

        auto const *pHost = HostInfo::CreateHost();
        auto const &runtimes = pHost->GetRuntimes();
        ASSERT_EQ(2, runtimes.size());

        ASSERT_TRUE(runtimes.find(L"v2.0.50727") != runtimes.end());
        ASSERT_TRUE(runtimes.find(L"v3.5")       == runtimes.end());
        ASSERT_TRUE(runtimes.find(L"v4.0.30319") != runtimes.end());

        
        typedef remove_reference<RemoveConst<decltype(runtimes)>::type>::type Runtimes;
        typedef Runtimes::key_type Key;
        typedef Runtimes::mapped_type Mapped;
        auto orderedRuntimes = map<Key, Mapped>(runtimes.begin(), runtimes.end());
        ASSERT_TRUE(wstring(L"v4.0.30319") == (*orderedRuntimes.rbegin()).first);
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, GetImageRuntimeVersionTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Fusion;
        using namespace Urasandesu::Swathe::Metadata;
        using boost::distance;
        using std::wstring;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v4.0.30319");
        
        auto const *pFuInfo = pRuntime->GetInfo<FusionInfo>();
        auto pCondition = pFuInfo->NewAssemblyName(L"mscorlib", NewAssemblyNameFlags::NANF_CANOF_PARSE_DISPLAY_NAME);
        auto pAsmNames = pFuInfo->EnumerateAssemblyName(pCondition, AssemblyCacheFlags::ACF_GAC);
        ASSERT_EQ(4, distance(*pAsmNames));
        
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();
        auto i = 0ul;
        BOOST_FOREACH (auto const &pAsmName, *pAsmNames)
        {
            auto const *pMSCorLib = pMetaDisp->GetAssembly(pAsmName->GetFullName());
            auto const &ver = pMSCorLib->GetVersion();
            auto const &cultureName = pMSCorLib->GetCultureName();
            auto const &procArchs = pMSCorLib->GetProcessorArchitectures();
            auto const &runtimeVer = pMSCorLib->GetImageRuntimeVersion();
            std::wcout << pMSCorLib->GetFullName() << std::endl;
            switch (i++)
            {
                case 0:
                    ASSERT_EQ(Version(2, 0, 0, 0), ver);
                    ASSERT_EQ(wstring(), cultureName);
                    ASSERT_TRUE(procArchs[0] == ProcessorArchitecture::PA_AMD64);
                    ASSERT_EQ(wstring(L"v2.0.50727"), runtimeVer);
                    break;
                case 1:
                    ASSERT_EQ(Version(2, 0, 0, 0), ver);
                    ASSERT_EQ(wstring(), cultureName);
                    ASSERT_TRUE(procArchs[0] == ProcessorArchitecture::PA_INTEL);
                    ASSERT_EQ(wstring(L"v2.0.50727"), runtimeVer);
                    break;
                case 2:
                    ASSERT_EQ(Version(4, 0, 0, 0), ver);
                    ASSERT_EQ(wstring(), cultureName);
                    ASSERT_TRUE(procArchs[0] == ProcessorArchitecture::PA_AMD64);
                    ASSERT_EQ(wstring(L"v4.0.30319"), runtimeVer);
                    break;
                case 3:
                    ASSERT_EQ(Version(4, 0, 0, 0), ver);
                    ASSERT_EQ(wstring(), cultureName);
                    ASSERT_TRUE(procArchs[0] == ProcessorArchitecture::PA_INTEL);
                    ASSERT_EQ(wstring(L"v4.0.30319"), runtimeVer);
                    break;
                default:
                    FAIL() << "We shouldn't get here!!";
                    break;
            }
        }
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, SampleForGetMethod_01)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace std;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v4.0.30319");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        auto const *pIEnumerable1 = pMSCorLibDll->GetType(L"System.Collections.Generic.IEnumerable`1");
        auto const *pInt32 = pMSCorLibDll->GetType(L"System.Int32");
        auto const *pIEnumerable1Int32 = static_cast<IType *>(nullptr);
        {
            auto genericArgs = vector<IType const *>();
            genericArgs.push_back(pInt32);
            pIEnumerable1Int32 = pIEnumerable1->MakeGenericType(genericArgs);
        }

        auto const *pSystemCore = pMetaDisp->GetAssembly(L"System.Core, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        auto const *pSystemCoreDll = pSystemCore->GetModule(L"System.Core.dll");
        auto const *pEnumerable = pSystemCoreDll->GetType(L"System.Linq.Enumerable");
        auto const *pEnumerable_Average_IEnumerable1Int32 = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pIEnumerable1Int32);
            pEnumerable_Average_IEnumerable1Int32 = pEnumerable->GetMethod(L"Average", params);
        }

        ASSERT_TRUE(pEnumerable_Average_IEnumerable1Int32 != nullptr);
        ASSERT_EQ(0x06000844, pEnumerable_Average_IEnumerable1Int32->GetToken());
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, SampleForGetMethod_02_00)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace std;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v4.0.30319");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        auto const *pEnum = pMSCorLibDll->GetType(L"System.Enum");
        auto const *pType = pMSCorLibDll->GetType(L"System.Type");
        auto const *pObject = pMSCorLibDll->GetType(L"System.Object");
        auto const *pEnum_ToObjectTypeObject = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pType);
            params.push_back(pObject);
            pEnum_ToObjectTypeObject = pEnum->GetMethod(L"ToObject", params);
        }

        ASSERT_TRUE(pEnum_ToObjectTypeObject != nullptr);
        {
            auto *pBody = pEnum_ToObjectTypeObject->GetMethodBody();

            auto const &exClauses = pBody->GetExceptionClauses();
            ASSERT_TRUE(exClauses.empty());
        }
    }


    
    CPPANONYM_TEST(Urasandesu_Swathe_Test3, SampleForGetMethod_02_01)
    {
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using namespace std;

        auto const *pHost = HostInfo::CreateHost();
        auto const *pRuntime = pHost->GetRuntime(L"v4.0.30319");
        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pMetaDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        auto const *pAppDomain = pMSCorLibDll->GetType(L"System.AppDomain");
        auto const *pString = pMSCorLibDll->GetType(L"System.String");
        auto const *pAppDomain_GetData = static_cast<IMethod *>(nullptr);
        {
            auto params = vector<IType const *>();
            params.push_back(pString);
            pAppDomain_GetData = pAppDomain->GetMethod(L"GetData", params);
        }

        ASSERT_TRUE(pAppDomain_GetData != nullptr);
        {
            auto *pBody = pAppDomain_GetData->GetMethodBody();

            auto const &exClauses = pBody->GetExceptionClauses();
            ASSERT_FALSE(exClauses.empty());
        }
    }



    CPPANONYM_TEST(Urasandesu_Swathe_Test3, DelegateTest_01)
    {
        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Metadata;
        using std::vector;
        using std::wstring;

        auto const *pHost = HostInfo::CreateHost();

        auto const *pRuntime = pHost->GetRuntime(L"v4.0.30319");

        auto const *pMetaInfo = pRuntime->GetInfo<MetadataInfo>();
        auto *pDisp = pMetaInfo->CreateDispenser();

        auto const *pMSCorLib = pDisp->GetAssembly(L"mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
        auto const *pMSCorLibDll = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");

        auto const *pObject = pMSCorLibDll->GetType(L"System.Object");
        auto const *pMulticastDelegate = pMSCorLibDll->GetType(L"System.MulticastDelegate");
        auto const *pDateTime = pMSCorLibDll->GetType(L"System.DateTime");
        auto const *pIntPtr = pMSCorLibDll->GetType(L"System.IntPtr");



        auto *pStubDriverGen = pDisp->DefineAssemblyWithPartialName(L"StubDriver");
        auto *pStubDriverDllGen = pStubDriverGen->DefineModule(L"StubDriver.dll");

        // In actually, this type is that an indirection target method is declared.
        auto *pProgramGen = 
            pStubDriverDllGen->DefineType(L"StubDriver.Program",
                                          TypeAttributes::TA_PUBLIC | 
                                          TypeAttributes::TA_ABSTRACT | 
                                          TypeAttributes::TA_AUTO_CLASS | 
                                          TypeAttributes::TA_ANSI_CLASS | 
                                          TypeAttributes::TA_BEFORE_FIELD_INIT);

        auto pIndDlgtGen = static_cast<TypeGenerator *>(nullptr);
        {
            // In actually, these information are gotten from an indirection target method.
            auto mdTarget = 0x0600000D;
            auto targetName = wstring(L"get_Now");
            auto name = boost::str(boost::wformat(L"IndirectionDelegate%|1$d|For%|2$s|") % RidFromToken(mdTarget) % targetName);
            auto attr = TypeAttributes::TA_AUTO_CLASS | TypeAttributes::TA_ANSI_CLASS | TypeAttributes::TA_SEALED | TypeAttributes::TA_NESTED_PRIVATE;
            auto const *pBaseType = pMulticastDelegate;
            pIndDlgtGen = pProgramGen->DefineNestedType(name, attr, pBaseType);
        }

        auto *pIndDlgtGen_ctor = static_cast<MethodGenerator *>(nullptr);
        {
            auto attr = MethodAttributes::MA_PUBLIC | MethodAttributes::MA_HIDE_BY_SIG | MethodAttributes::MA_SPECIAL_NAME | MethodAttributes::MA_RT_SPECIAL_NAME;
            auto callingConvention = CallingConventions::CC_HAS_THIS;
            auto paramTypes = vector<IType const *>();
            paramTypes.push_back(pObject);
            paramTypes.push_back(pIntPtr);
            pIndDlgtGen_ctor = pIndDlgtGen->DefineConstructor(attr, callingConvention, paramTypes);
            
            auto implAttr = MethodImplAttributes::MIA_RUNTIME | MethodImplAttributes::MIA_MANAGED;
            pIndDlgtGen_ctor->SetImplementationFlags(implAttr);
        }

        auto *pIndDlgtGen_Invoke = static_cast<MethodGenerator *>(nullptr);
        {
            auto name = wstring(L"Invoke");
            auto attr = MethodAttributes::MA_PUBLIC | MethodAttributes::MA_HIDE_BY_SIG | MethodAttributes::MA_NEW_SLOT | MethodAttributes::MA_VIRTUAL;
            auto callingConvention = CallingConventions::CC_HAS_THIS;
            auto const *pRetType = pDateTime;
            auto const &paramTypes = MetadataSpecialValues::EMPTY_TYPES;
            pIndDlgtGen_Invoke = pIndDlgtGen->DefineMethod(name, attr, callingConvention, pRetType, paramTypes);
            
            auto implAttr = MethodImplAttributes::MIA_RUNTIME | MethodImplAttributes::MIA_MANAGED;
            pIndDlgtGen_Invoke->SetImplementationFlags(implAttr);
        }

        pStubDriverGen->Save(PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
    }



    namespace _819E4142 {

        namespace Details {

            using boost::filesystem::path;
            using std::vector;

            void FillPrigAssemblyToGACPaths(path const &libPath, vector<path> &prigAsmToGACPaths)
            {
                using boost::filesystem::directory_iterator;
                using boost::filesystem::is_regular_file;
                using std::regex_constants::icase;
                using std::regex_search;
                using std::wregex;

                auto patternStr = L"(Urasandesu\\.NAnonym\\.dll)|(Urasandesu\\.Prig\\.Framework\\.dll)";
                auto pattern = wregex(patternStr, icase);
                for (directory_iterator i(libPath), i_end; i != i_end; ++i)
                {
                    if (!is_regular_file(i->status()))
                        continue;
            
                    if (!regex_search(i->path().filename().native(), pattern))
                        continue;
            
                    prigAsmToGACPaths.push_back(canonical(i->path()));
                }
            }

        } // namespace Details {

        using Details::FillPrigAssemblyToGACPaths;

    } // namespace _819E4142 {

    CPPANONYM_TEST(Urasandesu_Swathe_Test3, Fusion_API_can_install_to_GAC)
    {
        using namespace _819E4142;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Fusion;

        using boost::distance;
        using boost::filesystem::path;
        using boost::remove_reference;
        using std::map;
        using std::vector;
        using std::wstring;

        auto const *pHost = HostInfo::CreateHost();
        auto const &runtimes = pHost->GetRuntimes();
            
        typedef remove_reference<RemoveConst<decltype(runtimes)>::type>::type Runtimes;
        typedef Runtimes::key_type Key;
        typedef Runtimes::mapped_type Mapped;
        auto orderedRuntimes = map<Key, Mapped>(runtimes.begin(), runtimes.end());
        auto const *pLatestRuntime = (*orderedRuntimes.rbegin()).second;

        auto libPath = path(L"..\\..\\..\\..\\..\\Debug\\AnyCPU");
        auto prigAsmToGACPaths = vector<path>();
        FillPrigAssemblyToGACPaths(libPath, prigAsmToGACPaths);

        auto const *pFuInfo = pLatestRuntime->GetInfo<FusionInfo>();

        {
            auto pAsmCache = pFuInfo->NewAssemblyCache();
            BOOST_FOREACH (auto const &prigAsmToGACPath, prigAsmToGACPaths)
                pAsmCache->InstallAssembly(AssemblyCacheInstallFlags::ACIF_REFRESH, prigAsmToGACPath);
        }

        {
            auto pAsmCache = pFuInfo->NewAssemblyCache();
            BOOST_FOREACH (auto const &prigAsmToGACPath, prigAsmToGACPaths)
            {
                auto pCondition = pFuInfo->NewAssemblyName(prigAsmToGACPath.stem().native(), NewAssemblyNameFlags::NANF_CANOF_PARSE_DISPLAY_NAME);
                auto pAsmNames = pFuInfo->EnumerateAssemblyName(pCondition, AssemblyCacheFlags::ACF_GAC);
                ASSERT_EQ(1, distance(*pAsmNames));
            }
        }
    }



    CPPANONYM_TEST(Urasandesu_Swathe_Test3, Fusion_API_can_uninstall_from_GAC)
    {
        using namespace _819E4142;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;
        using namespace Urasandesu::Swathe::Fusion;

        using boost::distance;
        using boost::filesystem::path;
        using boost::remove_reference;
        using std::map;
        using std::vector;
        using std::wstring;

        auto const *pHost = HostInfo::CreateHost();
        auto const &runtimes = pHost->GetRuntimes();
            
        typedef remove_reference<RemoveConst<decltype(runtimes)>::type>::type Runtimes;
        typedef Runtimes::key_type Key;
        typedef Runtimes::mapped_type Mapped;
        auto orderedRuntimes = map<Key, Mapped>(runtimes.begin(), runtimes.end());
        auto const *pLatestRuntime = (*orderedRuntimes.rbegin()).second;

        auto libPath = path(L"..\\..\\..\\..\\..\\Debug\\AnyCPU");
        auto prigAsmToGACPaths = vector<path>();
        FillPrigAssemblyToGACPaths(libPath, prigAsmToGACPaths);

        auto const *pFuInfo = pLatestRuntime->GetInfo<FusionInfo>();

        {
            auto pAsmCache = pFuInfo->NewAssemblyCache();
            BOOST_FOREACH (auto const &prigAsmToGACPath, prigAsmToGACPaths)
                ASSERT_TRUE(pAsmCache->UninstallAssembly(prigAsmToGACPath.stem().native()) == AssemblyCacheUninstallDispositions::ACUD_UNINSTALLED);
        }

        BOOST_FOREACH (auto const &pair, runtimes)
        {
            auto pAsmCache = pFuInfo->NewAssemblyCache();
            BOOST_FOREACH (auto const &prigAsmToGACPath, prigAsmToGACPaths)
            {
                auto pCondition = pFuInfo->NewAssemblyName(prigAsmToGACPath.stem().native(), NewAssemblyNameFlags::NANF_CANOF_PARSE_DISPLAY_NAME);
                auto pAsmNames = pFuInfo->EnumerateAssemblyName(pCondition, AssemblyCacheFlags::ACF_GAC);
                ASSERT_EQ(0, distance(*pAsmNames));
            }
        }
    }
}
