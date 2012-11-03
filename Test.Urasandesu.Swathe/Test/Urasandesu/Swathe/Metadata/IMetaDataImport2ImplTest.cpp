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
