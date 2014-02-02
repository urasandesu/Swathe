/* 
 * File: BaseFusionInfoTest.cpp
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


#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiHolder
    >
    class BaseTestRuntimeHost
    {
    public:
        boost::filesystem::path const &GetCORSystemDirectoryPath() const
        {
            return m_corSystemDirectoryPath;
        }

        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Fusion_BaseFusionInfoTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Fusion_BaseFusionInfoTest, Test_01)
    {
        namespace fs = boost::filesystem;
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Fusion;

        // Arrange
        struct TestFusionInfoApi
        {
            //typedef INT runtime_host_api_type;
            typedef mpl::map<mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Hosting::BaseTestRuntimeHost<mpl::void_>>> api_cartridges;
        };
        typedef BaseFusionInfo<TestFusionInfoApi> FusionInfo;
        typedef FusionInfo::runtime_host_type RuntimeHost;

        RuntimeHost runtimeHost;
        runtimeHost.m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";


        // Act
        FusionInfo fuInfo;
        fuInfo.Init(runtimeHost);

        std::wstring assemblyName(L"System.Core, Version=3.5.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        boost::shared_ptr<AssemblyInfo> pAsmInfo = fuInfo.QueryAssemblyInfo(AssemblyQueryTypes::AQT_GET_SIZE, assemblyName);


        // Assert        
        fs::path expected(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ASSERT_TRUE(fs::equivalent(expected, pAsmInfo->GetAssemblyPath()));
        ASSERT_EQ(652, pAsmInfo->GetAssemblySizeInKB());
    }

    TEST(Urasandesu_CppAnonym_Fusion_BaseFusionInfoTest, Test_02)
    {
        namespace fs = boost::filesystem;
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Fusion;

        // Arrange
        struct TestFusionInfoApi
        {
            //typedef INT runtime_host_api_type;
            typedef mpl::map<mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Hosting::BaseTestRuntimeHost<mpl::void_>>> api_cartridges;
        };
        typedef BaseFusionInfo<TestFusionInfoApi> FusionInfo;
        typedef FusionInfo::runtime_host_type RuntimeHost;

        RuntimeHost runtimeHost;
        runtimeHost.m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";


        // Act
        FusionInfo fuInfo;
        fuInfo.Init(runtimeHost);

        std::wstring assemblyName(L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        boost::shared_ptr<AssemblyInfo> pAsmInfo = fuInfo.QueryAssemblyInfo(AssemblyQueryTypes::AQT_GET_SIZE, assemblyName);


        // Assert        
        fs::path expected(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
        ASSERT_TRUE(fs::equivalent(expected, pAsmInfo->GetAssemblyPath()))
            << "Expected: " << expected.c_str() << ", Actual: " << pAsmInfo->GetAssemblyPath().c_str();
        ASSERT_EQ(5464, pAsmInfo->GetAssemblySizeInKB());
    }
}
