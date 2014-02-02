/* 
 * File: MetadataTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_H
#include <Urasandesu/CppAnonym/Utilities/IsAnyT.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_H
#include <Urasandesu/CppAnonym/Traits/Predicatable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H
#include <Urasandesu/CppAnonym/Utilities/EqualTo.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H
#include <Urasandesu/CppAnonym/Traits/HashComputable.h>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
#include <Urasandesu/CppAnonym/ObjectTag.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
#include <Urasandesu/CppAnonym/Utilities/AnyPtr.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_IMETADATAIMPORT2IMPL_HPP
#include <Urasandesu/CppAnonym/Metadata/IMetaDataImport2Impl.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKey.hpp>
#endif


#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

// Forward Declarations
namespace Mock9254318F {

    class ATL_NO_VTABLE MockMetaDataImport;
    typedef Urasandesu::CppAnonym::Utilities::CComObjectSlim<MockMetaDataImport> MockMetaDataImportObject;

}   // namespace Mock9254318F {

namespace Mock9254318F {
    
    typedef std::vector<boost::any> AnyVector;

    class MockMetadataInfo
    {
    public:
        template<class T>
        T const &Map() const
        {
            MockMetadataInfo *pMutableThis = const_cast<MockMetadataInfo *>(this);
            return pMutableThis->Map<T>();    
        }

        template<class T>
        T &Map()
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;

            AnyVector::iterator result;
            result = std::find_if(m_typePtrs.begin(), m_typePtrs.end(), IsAnyT<shared_ptr<T> >()); 
            _ASSERTE(result != m_typePtrs.end());

            return *any_cast<shared_ptr<T> >(*result);
        }

        mutable AnyVector m_typePtrs;
    };

    class MockRuntimeHost
    {
    public:
        boost::filesystem::path const &GetCORSystemDirectoryPath() const
        {
            return m_corSystemDirectoryPath;
        }

        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

    class ATL_NO_VTABLE MockMetaDataImport : 
        public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
        public Urasandesu::CppAnonym::Metadata::IMetaDataImport2Impl<IMetaDataImport2>
    {
    public:
        MockMetaDataImport() { }

    BEGIN_COM_MAP(MockMetaDataImport)
        COM_INTERFACE_ENTRY_IID(IID_IMetaDataImport2, IMetaDataImport2)
    END_COM_MAP()

        DECLARE_PROTECT_FINAL_CONSTRUCT()

        HRESULT FinalConstruct() { return S_OK; }
        void FinalRelease() { }
    };

    struct TestApiHolder;

    namespace Detail {

        namespace mpl = boost::mpl;
        using mpl::map;
        using mpl::pair;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::StrongNaming;
        using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;

        struct TestApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, BaseMetadataDispenser<TestApiHolder> >, 
                pair<AssemblyMetadataLabel, BaseAssemblyMetadata<TestApiHolder> >, 
                pair<AssemblyNameMetadataLabel, BaseAssemblyNameMetadata<TestApiHolder> >, 
                pair<AssemblyNameMetadataHashLabel, BaseAssemblyNameMetadataHash<TestApiHolder> >, 
                pair<AssemblyNameMetadataEqualToLabel, BaseAssemblyNameMetadataEqualTo<TestApiHolder> >, 
                pair<ModuleMetadataLabel, BaseModuleMetadata<TestApiHolder> >, 
                pair<ModuleNameMetadataLabel, BaseModuleNameMetadata<TestApiHolder> >, 
                pair<ModuleNameMetadataHashLabel, BaseModuleNameMetadataHash<TestApiHolder> >,
                pair<ModuleNameMetadataEqualToLabel, BaseModuleNameMetadataEqualTo<TestApiHolder> >,
                pair<TypeMetadataLabel, BaseTypeMetadata<TestApiHolder> >, 
                pair<TypeNameMetadataLabel, BaseTypeNameMetadata<TestApiHolder> >, 
                pair<TypeNameMetadataHashLabel, BaseTypeNameMetadataHash<TestApiHolder> >, 
                pair<TypeNameMetadataEqualToLabel, BaseTypeNameMetadataEqualTo<TestApiHolder> >, 
                pair<MethodMetadataLabel, BaseMethodMetadata<TestApiHolder> >, 
                pair<MethodNameMetadataLabel, BaseMethodNameMetadata<TestApiHolder> >,
                pair<MethodNameMetadataHashLabel, BaseMethodNameMetadataHash<TestApiHolder> >,
                pair<MethodNameMetadataEqualToLabel, BaseMethodNameMetadataEqualTo<TestApiHolder> >,                 
                pair<RuntimeHostLabel, Mock9254318F::MockRuntimeHost>, 
                pair<MetadataInfoLabel, Mock9254318F::MockMetadataInfo>, 
                pair<FusionInfoLabel, BaseFusionInfo<TestApiHolder> >,
                pair<StrongNameKeyLabel, BaseStrongNameKey<TestApiHolder> >, 
                pair<StrongNameInfoLabel, BaseStrongNameInfo<TestApiHolder> >, 
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
                pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>,
                pair<IMetaDataImport2, IMetaDataImport2> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct TestApiHolder : 
        Detail::TestApiHolderImpl
    {
    };

    namespace Detail {

        typedef MockRuntimeHost RuntimeHost; 
        typedef MockMetadataInfo MetadataInfo;
        typedef BaseFusionInfo<TestApiHolder> FusionInfo;
        typedef BaseStrongNameInfo<TestApiHolder> StrongNameInfo;

        typedef BaseMetadataDispenser<TestApiHolder> MetadataDispenser;
        typedef BaseAssemblyMetadata<TestApiHolder> AssemblyMetadata;
        typedef BaseAssemblyNameMetadata<TestApiHolder> AssemblyNameMetadata;
        typedef BaseModuleMetadata<TestApiHolder> ModuleMetadata;
        typedef BaseModuleNameMetadata<TestApiHolder> ModuleNameMetadata;
        typedef BaseTypeMetadata<TestApiHolder> TypeMetadata;
        typedef BaseTypeNameMetadata<TestApiHolder> TypeNameMetadata;
        typedef BaseMethodMetadata<TestApiHolder> MethodMetadata;
        typedef BaseMethodNameMetadata<TestApiHolder> MethodNameMetadata;

    }   // namespace Detail {

    using Detail::RuntimeHost;
    using Detail::MetadataInfo;
    using Detail::FusionInfo;
    using Detail::StrongNameInfo;
    using Detail::MetadataDispenser;
    using Detail::AssemblyMetadata;
    using Detail::AssemblyNameMetadata;
    using Detail::ModuleMetadata;
    using Detail::ModuleNameMetadata;
    using Detail::TypeMetadata;
    using Detail::TypeNameMetadata;
    using Detail::MethodMetadata;
    using Detail::MethodNameMetadata;

}   // namespace Mock9254318F {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Metadata_Test.*
namespace {

    //template<class Accessor>
    //class A
    //{
    //public:
    //    A() : m_val(0) { }
    //    int GetValue() const { return m_val; }
    //private:
    //    friend typename boost::mpl::identity<Accessor>::type;
    //    int m_val;
    //};
 
    //struct B
    //{
    //    template<class A>
    //    static void SetValue(A &a, int val)
    //    {
    //        a.m_val = val;
    //    }
    //};

    //CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_Test, Test_01)
    //{
    //    A<B> a;
    //    B::SetValue(a, 100);
    //    ASSERT_EQ(99, a.GetValue());
    //}


    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_Test, CombinationOfResolutionWayTest_All_01)
    {
        using namespace boost;
        using namespace Mock9254318F;
        using Urasandesu::CppAnonym::Metadata::CallingConventions;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<StrongNameInfo> pSnInfo(make_shared<StrongNameInfo>());
        pSnInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        pMetaInfo->m_typePtrs.push_back(pSnInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyNameMetadata *pMSCorLibName = NULL;
        {
            std::wstring name(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                              L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
            pMSCorLibName = pMetaDisp->NewAssemblyName(name);
        }

        ASSERT_STREQ(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                     L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86", pMSCorLibName->GetName().c_str());
        
        AssemblyMetadata const *pMSCorLib = NULL;
        pMSCorLib = pMSCorLibName->Resolve();
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());

        ModuleNameMetadata *pMSCorLibModuleName = NULL;
        {
            std::wstring name(L"CommonLanguageRuntimeLibrary");
            pMSCorLibModuleName = pMSCorLibName->NewModuleName(name);
        }

        ASSERT_STREQ(L"CommonLanguageRuntimeLibrary", pMSCorLibModuleName->GetName().c_str());

        ModuleMetadata const *pMSCorLibModule = NULL;
        pMSCorLibModule = pMSCorLibModuleName->Resolve();
        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());

        TypeNameMetadata *pConsoleName = NULL;
        {
            std::wstring name(L"System.Console");
            pConsoleName = pMSCorLibModuleName->NewTypeName(name);
        }

        ASSERT_STREQ(L"System.Console", pConsoleName->GetName().c_str());
        
        TypeMetadata const *pConsole = NULL;
        pConsole = pConsoleName->Resolve();
        ASSERT_EQ(0x02000089, pConsole->GetToken());

        MethodNameMetadata *pWriteLineName = NULL;
        {
            std::wstring name(L"WriteLine");
            CallingConventions callingConvention(CallingConventions::CC_STANDARD);
            TypeNameMetadata const *pRetTypeName = pMSCorLibModuleName->NewTypeName(L"System.Void");
            std::vector<TypeNameMetadata const *> paramTypeNames;
            paramTypeNames.push_back(pMSCorLibModuleName->NewTypeName(L"System.String"));
            pWriteLineName = pConsoleName->NewMethodName(name, callingConvention, *pRetTypeName, paramTypeNames);
        }

        ASSERT_STREQ(L"WriteLine", pWriteLineName->GetName().c_str());

        MethodMetadata const *pWriteLine = NULL;
        pWriteLine = pWriteLineName->Resolve();
        ASSERT_EQ(0x060007C9, pWriteLine->GetToken());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_Test, CombinationOfResolutionWayTest_FromAssembly_01)
    {
        namespace fs = boost::filesystem;
        using namespace boost;
        using namespace Mock9254318F;
        using Urasandesu::CppAnonym::Metadata::CallingConventions;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<StrongNameInfo> pSnInfo(make_shared<StrongNameInfo>());
        pSnInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        pMetaInfo->m_typePtrs.push_back(pSnInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyMetadata const *pMSCorLib = NULL;
        {
            fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
            pMSCorLib = pMetaDisp->LoadAssemblyFromFile(asmPath);
        }
                  
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());

        AssemblyNameMetadata const *pMSCorLibName = NULL;
        pMSCorLibName = pMSCorLib->GetAssemblyName();

        EXPECT_STREQ(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                     L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86", pMSCorLibName->GetName().c_str());

        ModuleNameMetadata *pMSCorLibModuleName = NULL;
        {
            std::wstring name(L"CommonLanguageRuntimeLibrary");
            pMSCorLibModuleName = pMSCorLib->NewModuleName(name);
        }

        ASSERT_STREQ(L"CommonLanguageRuntimeLibrary", pMSCorLibModuleName->GetName().c_str());

        ModuleMetadata const *pMSCorLibModule = NULL;
        pMSCorLibModule = pMSCorLibModuleName->Resolve();
        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_Test, CombinationOfResolutionWayTest_FromModule_01)
    {
        namespace fs = boost::filesystem;
        using namespace boost;
        using namespace Mock9254318F;
        using Urasandesu::CppAnonym::Metadata::CallingConventions;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<StrongNameInfo> pSnInfo(make_shared<StrongNameInfo>());
        pSnInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        pMetaInfo->m_typePtrs.push_back(pSnInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyMetadata const *pMSCorLib = NULL;
        {
            fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
            pMSCorLib = pMetaDisp->LoadAssemblyFromFile(asmPath);
        }

        ModuleMetadata const *pMSCorLibModule = NULL;
        {
            std::wstring name(L"CommonLanguageRuntimeLibrary");
            pMSCorLibModule = pMSCorLib->GetModule(name);
        }

        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());

        ModuleNameMetadata const *pMSCorLibModuleName = NULL;
        pMSCorLibModuleName = pMSCorLibModule->GetModuleName();

        ASSERT_STREQ(L"CommonLanguageRuntimeLibrary", pMSCorLibModuleName->GetName().c_str());

        TypeNameMetadata *pConsoleName = NULL;
        {
            std::wstring name(L"System.Console");
            pConsoleName = pMSCorLibModule->NewTypeName(name);
        }
        
        ASSERT_STREQ(L"System.Console", pConsoleName->GetName().c_str());

        TypeMetadata const *pConsole = NULL;
        pConsole = pConsoleName->Resolve();
        ASSERT_EQ(0x02000089, pConsole->GetToken());
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_Test, CombinationOfResolutionWayTest_FromType_01)
    {
        namespace fs = boost::filesystem;
        using namespace boost;
        using namespace Mock9254318F;
        using Urasandesu::CppAnonym::Metadata::CallingConventions;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<StrongNameInfo> pSnInfo(make_shared<StrongNameInfo>());
        pSnInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        pMetaInfo->m_typePtrs.push_back(pSnInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyMetadata const *pMSCorLib = NULL;
        {
            fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
            pMSCorLib = pMetaDisp->LoadAssemblyFromFile(asmPath);
        }

        ModuleMetadata const *pMSCorLibModule = NULL;
        {
            std::wstring name(L"CommonLanguageRuntimeLibrary");
            pMSCorLibModule = pMSCorLib->GetModule(name);
        }

        TypeMetadata const *pConsole = NULL;
        {
            std::wstring name(L"System.Console");
            pConsole = pMSCorLibModule->GetType(name);
        }

        TypeNameMetadata const *pConsoleName = NULL;
        pConsoleName = pConsole->GetTypeName();

        ASSERT_STREQ(L"System.Console", pConsoleName->GetName().c_str());

        MethodNameMetadata *pWriteLineName = NULL;
        {
            std::wstring name(L"WriteLine");
            CallingConventions callingConvention(CallingConventions::CC_STANDARD);
            TypeNameMetadata const *pRetTypeName = pMSCorLibModule->NewTypeName(L"System.Void");
            std::vector<TypeNameMetadata const *> paramTypeNames;
            paramTypeNames.push_back(pMSCorLibModule->NewTypeName(L"System.String"));
            pWriteLineName = pConsole->NewMethodName(name, callingConvention, *pRetTypeName, paramTypeNames);
        }

        ASSERT_STREQ(L"WriteLine", pWriteLineName->GetName().c_str());

        MethodMetadata const *pWriteLine = NULL;
        pWriteLine = pWriteLineName->Resolve();
        ASSERT_EQ(0x060007C9, pWriteLine->GetToken());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_Test, CombinationOfResolutionWayTest_FromMethod_01)
    {
        namespace fs = boost::filesystem;
        using namespace boost;
        using namespace Mock9254318F;
        using Urasandesu::CppAnonym::Metadata::CallingConventions;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<StrongNameInfo> pSnInfo(make_shared<StrongNameInfo>());
        pSnInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        pMetaInfo->m_typePtrs.push_back(pSnInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyMetadata const *pMSCorLib = NULL;
        {
            fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
            pMSCorLib = pMetaDisp->LoadAssemblyFromFile(asmPath);
        }

        ModuleMetadata const *pMSCorLibModule = NULL;
        {
            std::wstring name(L"CommonLanguageRuntimeLibrary");
            pMSCorLibModule = pMSCorLib->GetModule(name);
        }

        TypeMetadata const *pConsole = NULL;
        {
            std::wstring name(L"System.Console");
            pConsole = pMSCorLibModule->GetType(name);
        }

        MethodMetadata const *pWriteLine = NULL;
        {
            std::wstring name(L"WriteLine");
            CallingConventions callingConvention(CallingConventions::CC_STANDARD);
            TypeMetadata const *pRetType = pMSCorLibModule->GetType(L"System.Void");
            std::vector<TypeMetadata const *> paramTypes;
            paramTypes.push_back(pMSCorLibModule->GetType(L"System.String"));
            pWriteLine = pConsole->GetMethod(name, callingConvention, *pRetType, paramTypes);
        }

        MethodNameMetadata const *pWriteLineName = NULL;
        pWriteLineName = pWriteLine->GetMethodName();

        ASSERT_STREQ(L"WriteLine", pWriteLineName->GetName().c_str());
    }
}
