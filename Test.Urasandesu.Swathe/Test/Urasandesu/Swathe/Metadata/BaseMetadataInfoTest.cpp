/* 
 * File: BaseMetadataInfoTest.cpp
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

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiHolder
    >
    class BaseTestRuntimeHost
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseMetadataInfoTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseMetadataInfoTest, Test_01)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestMetadataInfoApi;

        struct TestMetadataDispenserApi
        {
            typedef mpl::map<mpl::pair<Interfaces::MetadataInfoLabel, BaseMetadataInfo<TestMetadataInfoApi>>> api_cartridges;
        };

        struct TestMetadataInfoApi
        {
            typedef mpl::map<mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Hosting::BaseTestRuntimeHost<mpl::void_>>, 
                             mpl::pair<Interfaces::MetadataDispenserLabel, BaseMetadataDispenser<TestMetadataDispenserApi>>> api_cartridges;
        };

        typedef BaseMetadataInfo<TestMetadataInfoApi> MetadataInfo;
        typedef MetadataInfo::runtime_host_type RuntimeHost;

        RuntimeHost runtimeHost;

        // Act
        MetadataInfo metaInfo;
        metaInfo.Init(runtimeHost);

        // Assert
        typedef MetadataInfo::metadata_dispenser_type MetadataDispenser;
        //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::this_type, boost::use_default>));
        //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::metadata_dispenser_api_type, boost::use_default>));
        MetadataDispenser const *pMetaDisp = metaInfo.CreateDispenser();
        ASSERT_FALSE(pMetaDisp == NULL);
    }


    //TEST(Urasandesu_CppAnonym_Hosting_BaseMetadataInfoTest, Test_02)
    //{
    //    namespace fs = boost::filesystem;
    //    using namespace Urasandesu::CppAnonym::Metadata;

    //    // Arrange
    //    struct TestMetadataInfoApi
    //    {
    //    };

    //    typedef BaseMetadataInfo<TestMetadataInfoApi> MetadataInfo;
    //    typedef MetadataInfo::runtime_host_type RuntimeHost;

    //    RuntimeHost runtimeHost;

    //    // Act
    //    MetadataInfo metaInfo;
    //    metaInfo.Init(runtimeHost);

    //    // Assert
    //    typedef MetadataInfo::metadata_dispenser_type MetadataDispenser;
    //    //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::this_type, boost::use_default>));
    //    //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::metadata_dispenser_api_type, boost::use_default>));
    //    boost::shared_ptr<MetadataDispenser const> pMetaDisp = metaInfo.CreateDispenser();
    //    ASSERT_FALSE(pMetaDisp.get() == NULL);
    //}
}
