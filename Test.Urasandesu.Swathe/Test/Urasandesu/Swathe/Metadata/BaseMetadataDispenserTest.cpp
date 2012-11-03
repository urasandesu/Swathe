#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataInfoApiHolder
    >    
    class BaseTestMetadataInfoProtoB8DF5A21
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

//namespace Urasandesu { namespace CppAnonym { namespace Metadata {
//
//    struct AssemblyMetadataApiHolderLabel { };
//
//}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace MockD7E6BF16 {

    struct MockAssemblyNameMetadata
    {
        typedef INT type_name_metadata_heap_type;
    };

}   // namespace MockD7E6BF16 {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Metadata_BaseMetadataDispenserProtoB8DF5A21Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Metadata_BaseMetadataDispenserProtoB8DF5A21Test, Test_01)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestMetadataDispenserApi;

        struct TestAssemblyMetadataApi : 
            AssemblyMetadataApiHolderLabel
        {
            typedef boost::mpl::vector<TestMetadataDispenserApi, IMetaDataImport2> external_api_types;
            typedef mpl::map<mpl::pair<Interfaces::MetadataDispenserLabel, BaseMetadataDispenser<TestMetadataDispenserApi> >, 
                             mpl::pair<Interfaces::AssemblyNameMetadataLabel, MockD7E6BF16::MockAssemblyNameMetadata>, 
                             mpl::pair<IMetaDataImport2, IMetaDataImport2>> api_cartridges;
        };

        struct TestMetadataDispenserApi
        {
            typedef mpl::map<mpl::pair<Interfaces::MetadataInfoLabel, BaseTestMetadataInfoProtoB8DF5A21<mpl::void_> >, 
                             mpl::pair<Interfaces::AssemblyMetadataLabel, BaseAssemblyMetadata<TestAssemblyMetadataApi> > > api_cartridges;
        };
        typedef BaseMetadataDispenser<TestMetadataDispenserApi> MetadataDispenser;
        typedef MetadataDispenser::metadata_info_type MetadataInfo;

        MetadataInfo metaInfo;
        
        
        // Act
        MetadataDispenser metaDisp;
        metaDisp.Init(metaInfo);

        typedef MetadataDispenser::assembly_metadata_type AssemblyMetadata;
        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        AssemblyMetadata const *pAsmMeta = metaDisp.LoadAssemblyFromFile(asmPath);


        // Assert
        ASSERT_FALSE(pAsmMeta == NULL);
        AssemblyMetadata const *pAsmMeta2 = metaDisp.LoadAssemblyFromFile(asmPath);
        ASSERT_EQ(pAsmMeta, pAsmMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Metadata_BaseMetadataDispenserProtoB8DF5A21Test, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestMetadataDispenserApi;

        struct TestAssemblyMetadataApi : 
            AssemblyMetadataApiHolderLabel
        {
            typedef boost::mpl::vector<TestMetadataDispenserApi, IMetaDataImport2> external_api_types;
        };

        struct TestMetadataDispenserApi
        {
            typedef boost::mpl::vector<TestAssemblyMetadataApi> external_api_types;
        };
        typedef BaseMetadataDispenser<TestMetadataDispenserApi> MetadataDispenser;
        typedef MetadataDispenser::metadata_info_type MetadataInfo;

        MetadataInfo metaInfo;
        
        
        // Act
        MetadataDispenser metaDisp;
        metaDisp.Init(metaInfo);

        
    }
}
