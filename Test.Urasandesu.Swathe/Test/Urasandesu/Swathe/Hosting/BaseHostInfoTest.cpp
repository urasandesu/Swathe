#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
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

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct DefaultStrongNameInfoApiHolder { };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMetadataInfoApiHolder { };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseHostInfoTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseHostInfoTest, Test_01)
    {
        typedef Urasandesu::CppAnonym::Hosting::HostInfo HostInfo;
        typedef HostInfo::runtime_host_type RuntimeHost;

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");
        RuntimeHost const *pRuntimeHost2 = hostInfo.GetRuntime(L"v2.0.50727");
        ASSERT_EQ(pRuntimeHost, pRuntimeHost2); 
    }
}
