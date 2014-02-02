/* 
 * File: BaseStrongNameKeyTest.cpp
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

//#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
//#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKey.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<
        class StrongNameInfoApiHolder
    >    
    class BaseStrongNameInfo
    {
    };
}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseStrongNameKeyTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseStrongNameKeyTest, GetPublicKeyTest_01)
    {
        using namespace Urasandesu::CppAnonym::StrongNaming;

        // Arrange
        struct TestStrongNameKeyApi
        {
        };
        
        typedef BaseStrongNameKey<TestStrongNameKeyApi> StrongNameKey;
        StrongNameKey snKey;

        typedef StrongNameKey::strong_name_info_type StrongNameInfo;
        StrongNameInfo snInfo;

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x6f, 0x4a, 0x1b, 0x2b, 0x8c, 0xa3, 0xfc, 0x55, 
            0x67, 0xc7, 0x60, 0x45, 0xb7, 0x32, 0x0a, 0x45, 
            0xc1, 0x80, 0x35, 0xf5, 0x10, 0xca, 0x4f, 0x2f, 
            0xb4, 0x79, 0x64, 0x83, 0x06, 0xa0, 0x7a, 0x29, 
            0xd2, 0xd8, 0xf0, 0x5a, 0x70, 0xeb, 0xbb, 0xd0, 
            0x32, 0xbb, 0x09, 0x87, 0x99, 0xc9, 0x22, 0x65, 
            0x4e, 0xab, 0xeb, 0xaf, 0x7b, 0x84, 0xd3, 0x92, 
            0x7c, 0x23, 0x5e, 0x6d, 0xe5, 0x4a, 0x3b, 0xaf, 
            0xba, 0x5a, 0x2f, 0x27, 0x65, 0x3a, 0xf0, 0x52, 
            0xf0, 0x57, 0xf0, 0x06, 0x5a, 0xc7, 0x71, 0xd7, 
            0x22, 0x12, 0x7b, 0xbb, 0xa1, 0xcd, 0x01, 0xc8, 
            0xa6, 0x65, 0xfd, 0x2f, 0xf0, 0xdd, 0xa3, 0x61, 
            0x08, 0x61, 0x28, 0x9a, 0xe4, 0xd0, 0x5c, 0xcc, 
            0xdd, 0x6d, 0x35, 0xb6, 0xe6, 0xab, 0x46, 0xb8, 
            0xa6, 0xf8, 0xd1, 0x65, 0xad, 0x7f, 0x3f, 0xca, 
            0xcc, 0x5f, 0xdf, 0x62, 0x4b, 0xd7, 0x36, 0x98
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);


        // Act
        PublicKeyBlob const *pPubKeyBlob = reinterpret_cast<PublicKeyBlob const *>(PUB_KEY_BLOB);
        snKey.Init(snInfo, pPubKeyBlob, PUB_KEY_BLOB_SIZE);
        std::vector<BYTE> const &publicKey = snKey.GetPublicKey();


        // Assert
        ASSERT_EQ(148, publicKey.size());
        for (UINT i = 0; i < publicKey.size(); ++i)
            ASSERT_EQ(PUB_KEY_BLOB[PUB_KEY_BLOB_SIZE - publicKey.size() + i], publicKey[i]);
    }


    TEST(Urasandesu_CppAnonym_Hosting_BaseStrongNameKeyTest, GetPublicKeyTokenTest_For3rdPartyAssembly_01)
    {
        using namespace Urasandesu::CppAnonym::StrongNaming;

        // Arrange
        struct TestStrongNameKeyApi
        {
        };
        
        typedef BaseStrongNameKey<TestStrongNameKeyApi> StrongNameKey;
        StrongNameKey snKey;

        typedef StrongNameKey::strong_name_info_type StrongNameInfo;
        StrongNameInfo snInfo;

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x6f, 0x4a, 0x1b, 0x2b, 0x8c, 0xa3, 0xfc, 0x55, 
            0x67, 0xc7, 0x60, 0x45, 0xb7, 0x32, 0x0a, 0x45, 
            0xc1, 0x80, 0x35, 0xf5, 0x10, 0xca, 0x4f, 0x2f, 
            0xb4, 0x79, 0x64, 0x83, 0x06, 0xa0, 0x7a, 0x29, 
            0xd2, 0xd8, 0xf0, 0x5a, 0x70, 0xeb, 0xbb, 0xd0, 
            0x32, 0xbb, 0x09, 0x87, 0x99, 0xc9, 0x22, 0x65, 
            0x4e, 0xab, 0xeb, 0xaf, 0x7b, 0x84, 0xd3, 0x92, 
            0x7c, 0x23, 0x5e, 0x6d, 0xe5, 0x4a, 0x3b, 0xaf, 
            0xba, 0x5a, 0x2f, 0x27, 0x65, 0x3a, 0xf0, 0x52, 
            0xf0, 0x57, 0xf0, 0x06, 0x5a, 0xc7, 0x71, 0xd7, 
            0x22, 0x12, 0x7b, 0xbb, 0xa1, 0xcd, 0x01, 0xc8, 
            0xa6, 0x65, 0xfd, 0x2f, 0xf0, 0xdd, 0xa3, 0x61, 
            0x08, 0x61, 0x28, 0x9a, 0xe4, 0xd0, 0x5c, 0xcc, 
            0xdd, 0x6d, 0x35, 0xb6, 0xe6, 0xab, 0x46, 0xb8, 
            0xa6, 0xf8, 0xd1, 0x65, 0xad, 0x7f, 0x3f, 0xca, 
            0xcc, 0x5f, 0xdf, 0x62, 0x4b, 0xd7, 0x36, 0x98
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);
        BYTE const PUB_KEY_TOKEN[] = { 0xce, 0x9e, 0x95, 0xb0, 0x43, 0x34, 0xd5, 0xfb };


        // Act
        PublicKeyBlob const *pPubKeyBlob = reinterpret_cast<PublicKeyBlob const *>(PUB_KEY_BLOB);
        snKey.Init(snInfo, pPubKeyBlob, PUB_KEY_BLOB_SIZE);
        std::vector<BYTE> const &publicKeyToken = snKey.GetPublicKeyToken();


        // Assert
        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
    }


    TEST(Urasandesu_CppAnonym_Hosting_BaseStrongNameKeyTest, GetPublicKeyTokenTest_ForMsAssembly_01)
    {
        using namespace Urasandesu::CppAnonym::StrongNaming;

        // Arrange
        struct TestStrongNameKeyApi
        {
        };
        
        typedef BaseStrongNameKey<TestStrongNameKeyApi> StrongNameKey;
        StrongNameKey snKey;

        typedef StrongNameKey::strong_name_info_type StrongNameInfo;
        StrongNameInfo snInfo;

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);
        BYTE const PUB_KEY_TOKEN[] = { 0xb7, 0x7a, 0x5c, 0x56, 0x19, 0x34, 0xe0, 0x89 };


        // Act
        PublicKeyBlob const *pPubKeyBlob = reinterpret_cast<PublicKeyBlob const *>(PUB_KEY_BLOB);
        snKey.Init(snInfo, pPubKeyBlob, PUB_KEY_BLOB_SIZE);
        std::vector<BYTE> const &publicKeyToken = snKey.GetPublicKeyToken();


        // Assert
        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
    }
}
