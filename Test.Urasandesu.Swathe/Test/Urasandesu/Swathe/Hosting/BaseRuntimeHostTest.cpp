/* 
 * File: BaseRuntimeHostTest.cpp
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

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPI_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHost.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseRuntimeHostTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseRuntimeHostTest, Test_01)
    {
        namespace fs = boost::filesystem;
        
        typedef Urasandesu::CppAnonym::Hosting::RuntimeHost RuntimeHost;
        
        RuntimeHost runtimeHost;
        std::wstring const &corVersion = runtimeHost.GetCORVersion();
        ASSERT_STREQ(L"v2.0.50727", corVersion.c_str());

        fs::path const &corSystemDirectoryPath = runtimeHost.GetCORSystemDirectoryPath();
        fs::path expected(L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\");
        ASSERT_TRUE(fs::equivalent(expected, corSystemDirectoryPath)) 
            << "Expected: " << expected.c_str() << ", Actual: " << corSystemDirectoryPath.c_str();
    }

    TEST(Urasandesu_CppAnonym_Hosting_BaseRuntimeHostTest, GetInfoTest_FusionInfo_01)
    {
        namespace fs = boost::filesystem;
        
        typedef Urasandesu::CppAnonym::Hosting::RuntimeHost RuntimeHost;
        
        RuntimeHost runtimeHost;
        typedef RuntimeHost::fusion_info_type FusionInfo;

        FusionInfo const &fuInfo = runtimeHost.Map<FusionInfo>();
        FusionInfo const &fuInfo2 = runtimeHost.Map<FusionInfo>();
        ASSERT_EQ(&fuInfo, &fuInfo2);
    }

    TEST(Urasandesu_CppAnonym_Hosting_BaseRuntimeHostTest, GetInfoTest_MetadataInfo_01)
    {
        namespace fs = boost::filesystem;
        
        typedef Urasandesu::CppAnonym::Hosting::RuntimeHost RuntimeHost;
        
        RuntimeHost runtimeHost;
        typedef RuntimeHost::metadata_info_type MetaInfo;

        MetaInfo const &metaInfo = runtimeHost.Map<MetaInfo>();
        MetaInfo const &metaInfo2 = runtimeHost.Map<MetaInfo>();
        ASSERT_EQ(&metaInfo, &metaInfo2);
    }


#if 0
    TEST(Urasandesu_CppAnonym_Hosting_BaseRuntimeHostTest, Test_02)
    {
        namespace fs = boost::filesystem;

        struct TestRuntimeHostApi
        {
        };
        
        typedef Urasandesu::CppAnonym::Hosting::BaseRuntimeHost<TestRuntimeHostApi> RuntimeHost;
        RuntimeHost runtimeHost;
        typedef RuntimeHost::metadata_info_type MetaInfo;
        MetaInfo const *pMetaInfo = runtimeHost.GetInfo<MetaInfo>();
        ASSERT_FALSE(pMetaInfo == NULL);

        MetaInfo const *pMetaInfo2 = runtimeHost.GetInfo<MetaInfo>();
        ASSERT_EQ(pMetaInfo, pMetaInfo2);
    }
#endif
}
