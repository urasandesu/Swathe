/* 
 * File: IMetaDataImport2ImplTest.cpp
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

#ifndef URASANDESU_CPPANONYM_METADATA_IMETADATAIMPORT2IMPL_HPP
#include <Urasandesu/CppAnonym/Metadata/IMetaDataImport2Impl.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Metadata_IMetaDataImport2ImplTest.*
namespace {

    namespace _98EEDB1F {

        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::Utilities;

        
        class ATL_NO_VTABLE MyMetaDataImportDefault;
        typedef CComObjectSlim<MyMetaDataImportDefault> MyMetaDataImportDefaultObject;

        class ATL_NO_VTABLE MyMetaDataImportDefault : 
            public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
            public IMetaDataImport2Impl<IMetaDataImport2>
        {
        public:
            MyMetaDataImportDefault() { }

        BEGIN_COM_MAP(MyMetaDataImportDefault)
            COM_INTERFACE_ENTRY_IID(IID_IMetaDataImport2, IMetaDataImport2)
        END_COM_MAP()

            DECLARE_PROTECT_FINAL_CONSTRUCT()

            HRESULT FinalConstruct() { return S_OK; }
            void FinalRelease() { }
        };

    }   // namespace _98EEDB1F {

    TEST(Urasandesu_CppAnonym_Metadata_IMetaDataImport2ImplTest, Test_01)
    {
        using namespace _98EEDB1F;

        MyMetaDataImportDefaultObject *pMetaImp_ = NULL;
        ASSERT_HRESULT_SUCCEEDED(MyMetaDataImportDefaultObject::CreateInstance(&pMetaImp_)); 
        ATL::CComPtr<IMetaDataImport2> pMetaImp(pMetaImp_);

        mdModule mdm = mdModuleNil;
        ASSERT_HRESULT_SUCCEEDED(pMetaImp->GetModuleFromScope(&mdm)); 

        ASSERT_EQ(mdModuleNil, mdm);
    }

    
    
    
    
    namespace _98EEDB1F {

        class ATL_NO_VTABLE MyMetaDataImportSpecialized;
        typedef CComObjectSlim<MyMetaDataImportSpecialized> MyMetaDataImportSpecializedObject;

        class ATL_NO_VTABLE MyMetaDataImportSpecialized : 
            public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
            public IMetaDataImport2Impl<IMetaDataImport2>
        {
        public:
            MyMetaDataImportSpecialized() { }

        BEGIN_COM_MAP(MyMetaDataImportSpecialized)
            COM_INTERFACE_ENTRY_IID(IID_IMetaDataImport2, IMetaDataImport2)
        END_COM_MAP()

            DECLARE_PROTECT_FINAL_CONSTRUCT()

            HRESULT FinalConstruct() { return S_OK; }
            void FinalRelease() { }

        protected:
            STDMETHOD(GetModuleFromScopeCore)(mdModule *pmd)
            {
                *pmd = mdtModule + 1;
                return S_OK;
            }
        };

    }   // namespace _98EEDB1F {

    TEST(Urasandesu_CppAnonym_Metadata_IMetaDataImport2ImplTest, Test_02)
    {
        using namespace _98EEDB1F;

        MyMetaDataImportSpecializedObject *pMetaImp_ = NULL;
        ASSERT_HRESULT_SUCCEEDED(MyMetaDataImportSpecializedObject::CreateInstance(&pMetaImp_)); 
        ATL::CComPtr<IMetaDataImport2> pMetaImp(pMetaImp_);

        mdModule mdm = mdModuleNil;
        ASSERT_HRESULT_SUCCEEDED(pMetaImp->GetModuleFromScope(&mdm)); 

        ASSERT_EQ(0x00000001, mdm);
    }
}
