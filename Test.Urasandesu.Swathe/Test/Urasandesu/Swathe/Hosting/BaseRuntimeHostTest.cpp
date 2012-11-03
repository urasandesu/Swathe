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
