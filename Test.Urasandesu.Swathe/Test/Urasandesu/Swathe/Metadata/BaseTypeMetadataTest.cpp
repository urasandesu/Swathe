#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_H
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H
#include <Urasandesu/CppAnonym/Utilities/Hash.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
#include <Urasandesu/CppAnonym/ObjectTag.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
#include <Urasandesu/CppAnonym/Utilities/AnyPtr.h>
#endif

#ifndef URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H
#include <Urasandesu/CppAnonym/DefaultSTDMETHODWrapper.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_IMETADATAIMPORT2IMPL_HPP
#include <Urasandesu/CppAnonym/Metadata/IMetaDataImport2Impl.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEINSTRUCTION_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseInstruction.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYWRITER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodBodyWriter.hpp>
#endif

namespace {

    class ATL_NO_VTABLE MyMetaDataImport;
    typedef Urasandesu::CppAnonym::Utilities::CComObjectSlim<MyMetaDataImport> MyMetaDataImportObject;

}

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class TestAssemblyMetadataApiType
    >    
    class BaseTestAssemblyMetadata
    {
    public:
        typedef BaseTestAssemblyMetadata<TestAssemblyMetadataApiType> this_type;

        typedef typename Traits::ApiAt<TestAssemblyMetadataApiType, Interfaces::AssemblyMetadataApiHolderLabel, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename Traits::ApiAt<TestAssemblyMetadataApiType, Interfaces::AssemblyMetadataApiHolderLabel, Interfaces::TypeMetadataLabel>::type type_metadata_type;

        template<class T>
        T const &Map() const 
        {
            if (m_pType.IsEmpty())
            {
                m_pType = new T();
            } 
            return m_pType;
        }

        type_metadata_type const *GetType(std::wstring const &name, TypeKinds const &kind) const
        {
            if (name == CONSOLE_NAME)
            {
                if (m_pConsole.IsEmpty())
                {
                    this_type *pMutableThis = const_cast<this_type *>(this);

                    MyMetaDataImportObject *pMetaImpApi_ = NULL;
                    MyMetaDataImportObject::CreateInstance(&pMetaImpApi_); 
                    ATL::CComPtr<metadata_import_api_type> pMetaImpApi(pMetaImpApi_);

                    m_pConsole = new type_metadata_type();
                    type_metadata_type *pConsole = m_pConsole;
                    pConsole->Init(*pMutableThis, *pMetaImpApi);
                    pConsole->SetName(name);
                    pConsole->SetKind(TypeKinds::TK_CLASS);
                }
                return m_pConsole;
            }
            return NULL;
        }

        void SetName(std::wstring const &name)
        {
        }

    private:
        static std::wstring const CONSOLE_NAME;
        mutable Utilities::AnyPtr m_pType;
        mutable Utilities::AnyPtr m_pConsole;
    };
    
    template<
        class TestAssemblyMetadataApiType
    >    
    std::wstring const BaseTestAssemblyMetadata<TestAssemblyMetadataApiType>::CONSOLE_NAME = std::wstring(L"System.Console");

    template<
        class TestMetadataDispenserApiType
    >    
    class BaseTestMetadataDispenser
    {
    public:
        typedef BaseTestMetadataDispenser<TestMetadataDispenserApiType> this_type;

        typedef typename Traits::ApiAt<TestMetadataDispenserApiType, Interfaces::MetadataDispenserApiHolderLabel, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        
        assembly_metadata_type const *LoadAssembly(std::wstring const &name) const
        {
            if (m_pMSCorLib.IsEmpty())
            {
                m_pMSCorLib = new assembly_metadata_type();
                assembly_metadata_type *pMSCorLib = m_pMSCorLib;
                pMSCorLib->SetName(L"mscorlib, Version=2.0.0.0," 
                                   L" Culture=neutral, PublicKeyToken=b77a5c561934e089");
            }
            return m_pMSCorLib;
        }

    private:
        mutable Utilities::AnyPtr m_pMSCorLib;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test.*
namespace {

    void SetupApis(boost::filesystem::path const &asmPath, 
                   std::wstring const &typeName, 
                   IMetaDataDispenserEx **ppMetaDispApi, 
                   IMetaDataImport2 **ppMetaImpApi, 
                   mdTypeDef &mdtd)
    {
        namespace fs = boost::filesystem;

        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(ppMetaDispApi))
        ); 

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaDispApi)->OpenScope(asmPath.c_str(), ofRead, 
                                        IID_IMetaDataImport2, 
                                        reinterpret_cast<IUnknown **>(ppMetaImpApi))
        );

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaImpApi)->FindTypeDefByName(typeName.c_str(), NULL, &mdtd)
        );
    }

#if 0
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadata<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        std::wstring typeName(L"System.Func`1");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);
        mdToken mdt = typeMeta.GetToken();


        // Assert
        ASSERT_EQ(0x02000058, mdt);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi;

        struct TestMethodMetadataApi : 
            MethodMetadataApiHolderLabel
        {
            typedef boost::mpl::vector<TestTypeMetadataApi, IMetaDataImport2> external_api_types;
        };

        struct TestTypeMetadataApi : 
            TypeMetadataApiHolderLabel  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadata<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;
        typedef TypeMetadata::method_metadata_type MethodMetadata;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        std::wstring typeName(L"System.Func`1");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);

        
        std::wstring name(L".ctor");
        
        CallingConventions callConvention = CallingConventions::CC_HAS_THIS;
        
        TypeMetadata retType;
        retType.SetKind(TypeKinds::TK_VOID);
        
        std::vector<TypeMetadata const *> paramTypes;
        TypeMetadata paramType0(TypeKinds::TK_OBJECT);
        paramTypes.push_back(&paramType0);
        TypeMetadata paramType1(TypeKinds::TK_I);
        paramTypes.push_back(&paramType1);
        
        MethodMetadata const *pMethodMeta = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);
        ASSERT_FALSE(pMethodMeta == NULL);
        mdToken mdt = pMethodMeta->GetToken();

        MethodMetadata const *pMethodMeta2 = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);


        // Assert
        ASSERT_EQ(0x06000232, mdt);
        ASSERT_EQ(pMethodMeta, pMethodMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_03)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi;

        struct TestMethodMetadataApi : 
            MethodMetadataApiHolderLabel
        {
            typedef boost::mpl::vector<TestTypeMetadataApi, IMetaDataImport2> external_api_types;
        };

        struct TestTypeMetadataApi : 
            TypeMetadataApiHolderLabel  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadata<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;
        typedef TypeMetadata::method_metadata_type MethodMetadata;

        fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
        std::wstring typeName(L"System.DateTime");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);

        
        std::wstring name(L"get_Now");
        
        CallingConventions callConvention = CallingConventions::CC_STANDARD;
        
        TypeMetadata retType;
        retType.SetKind(TypeKinds::TK_VALUETYPE);
        retType.SetKey(mdtd);
        
        std::vector<TypeMetadata const *> paramTypes;

        MethodMetadata const *pMethodMeta = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);
        ASSERT_FALSE(pMethodMeta == NULL);
        mdToken mdt = pMethodMeta->GetToken();

        MethodMetadata const *pMethodMeta2 = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);


        // Assert
        ASSERT_EQ(0x060002D2, mdt);
        ASSERT_EQ(pMethodMeta, pMethodMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_04)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;
     
        typedef OpCodes OpCodes;
        ASSERT_STREQ(L"CEE_NOP,nop,Pop0,Push0,InlineNone,IPrimitive,1,0xFF,0x00,NEXT", OpCodes::Nop.CStr());
        ASSERT_EQ(OpCodeTypes::CEE_NOP, OpCodes::Nop.GetType().Value());
        ASSERT_STREQ(L"nop", OpCodes::Nop.GetName().c_str());
        ASSERT_EQ(StackBehaviourTypes::SBT_POP0, OpCodes::Nop.GetBehaviour0().GetType().Value());
        ASSERT_EQ(StackBehaviourTypes::SBT_PUSH0, OpCodes::Nop.GetBehaviour1().GetType().Value());
        ASSERT_EQ(OperandParamTypes::OPT_INLINE_NONE, OpCodes::Nop.GetOperandParam().GetType().Value());
        ASSERT_EQ(OpCodeKindTypes::OKT_I_PRIMITIVE, OpCodes::Nop.GetOpCodeKind().GetType().Value());
        ASSERT_EQ(1, OpCodes::Nop.GetLength());
        ASSERT_EQ(0xFF, OpCodes::Nop.GetByte1());
        ASSERT_EQ(0x00, OpCodes::Nop.GetByte2());
        ASSERT_EQ(ControlFlowTypes::CFT_NEXT, OpCodes::Nop.GetControlFlow().GetType().Value());
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_05)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
        expected += StackBehaviours::PopRef();
     
        typedef OpCodes OpCodes;
        ASSERT_STREQ(L"CEE_STELEM_REF,stelem.ref,PopRef+PopI+PopRef,Push0,InlineNone,IObjModel,1,0xFF,0xA2,NEXT", OpCodes::Stelem_Ref.CStr());
        ASSERT_TRUE(expected == OpCodes::Stelem_Ref.GetBehaviour0());
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_06)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
     
        typedef OpCodes OpCodes;
        ASSERT_TRUE(expected != OpCodes::Stfld.GetBehaviour0());
    }

#endif

    CPPANONYM_TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_08)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym;

        cout << "Hello, World!!" << endl;

        //int i = 10;
        //ASSERT_EQ(3, i);

        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
    }

    // 
    CPPANONYM_TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_09)
    {

    }


    ////class ATL_NO_VTABLE MyMetaDataImport;
    ////typedef Urasandesu::CppAnonym::Utilities::CComObjectSlim<MyMetaDataImport> MyMetaDataImportObject;

    //class ATL_NO_VTABLE MyMetaDataImport : 
    //    public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
    //    public Urasandesu::CppAnonym::Metadata::IMetaDataImport2Impl<IMetaDataImport2>
    //{
    //public:
    //    MyMetaDataImport() { }

    //BEGIN_COM_MAP(MyMetaDataImport)
    //    COM_INTERFACE_ENTRY_IID(IID_IMetaDataImport2, IMetaDataImport2)
    //END_COM_MAP()

    //    DECLARE_PROTECT_FINAL_CONSTRUCT()

    //    HRESULT FinalConstruct() { return S_OK; }
    //    void FinalRelease() { }
    //};

    //CPPANONYM_TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_07)
    //{
    //    // TODO: せっかく NotImplementedException スローしてるのに Google Test で丸められちゃう。カスタム class 作ったほうが良さそうね。
    //    namespace fs = boost::filesystem;
    //    namespace mpl = boost::mpl;
    //    using namespace Urasandesu::CppAnonym;
    //    using namespace Urasandesu::CppAnonym::Metadata;
    //    using boost::any_cast;

    //    typedef OpCodes OpCodes;
    //    typedef OpCode OpCode;

    //    struct TestAssemblyMetadataApiHolder;

    //    struct TestMetadataDispenserApiHolder
    //    {
    //        typedef mpl::map<mpl::pair<Interfaces::AssemblyMetadataApiHolderLabel, TestAssemblyMetadataApiHolder>, 
    //                         mpl::pair<Interfaces::AssemblyMetadataLabel, BaseTestAssemblyMetadata<TestAssemblyMetadataApiHolder>>> api_cartridges;
    //    };

    //    struct TestTypeMetadataApiHolder;
    //
    //    struct TestAssemblyMetadataApiHolder
    //    {
    //        typedef mpl::map<mpl::pair<Interfaces::TypeMetadataApiHolderLabel, TestTypeMetadataApiHolder>,
    //                         mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder>>, 
    //                         mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
    //                         mpl::pair<Interfaces::MetadataDispenserLabel, BaseTestMetadataDispenser<TestMetadataDispenserApiHolder>>> api_cartridges;
    //    };

    //    struct TestMethodMetadataApiHolder;
    //    struct TestMethodBodyWriterApiHolder;

    //    struct TestMethodNameMetadataApiHolder
    //    {
    //        typedef mpl::map<mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder> > > api_cartridges;
    //    };

    //    struct TestTypeMetadataApiHolder
    //    {
    //        typedef mpl::map<mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
    //                         mpl::pair<Interfaces::AssemblyMetadataApiHolderLabel, TestAssemblyMetadataApiHolder>,
    //                         mpl::pair<Interfaces::MethodMetadataApiHolderLabel, TestMethodMetadataApiHolder>, 
    //                         mpl::pair<Interfaces::MethodBodyWriterApiHolderLabel, TestMethodBodyWriterApiHolder>, 
    //                         mpl::pair<Interfaces::AssemblyMetadataLabel, BaseTestAssemblyMetadata<TestAssemblyMetadataApiHolder> >, 
    //                         mpl::pair<Interfaces::MethodNameMetadataLabel, BaseMethodNameMetadata<TestMethodMetadataApiHolder> >, 
    //                         mpl::pair<Interfaces::MethodMetadataLabel, BaseMethodMetadata<TestMethodMetadataApiHolder> >, 
    //                         mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder> >,
    //                         mpl::pair<Interfaces::MethodNameMetadataLabel, BaseMethodNameMetadata<TestMethodNameMetadataApiHolder> > > api_cartridges;
    //    };

    //    struct TestMethodMetadataApiHolder
    //    {
    //        typedef mpl::map<mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
    //                         mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder> >, 
    //                         mpl::pair<Interfaces::MethodNameMetadataLabel, BaseMethodNameMetadata<TestMethodNameMetadataApiHolder> > > api_cartridges;
    //    };

    //    struct TestMethodBodyWriterApiHolder
    //    {
    //        typedef mpl::map<mpl::pair<Interfaces::MetadataDispenserLabel, BaseTestMetadataDispenser<TestMetadataDispenserApiHolder>>,
    //                         mpl::pair<Interfaces::AssemblyMetadataLabel, BaseTestAssemblyMetadata<TestAssemblyMetadataApiHolder>>, 
    //                         mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder>>, 
    //                         mpl::pair<Interfaces::MethodMetadataLabel, BaseMethodMetadata<TestMethodMetadataApiHolder>>> api_cartridges;
    //    };

    //    typedef BaseMethodBodyWriter<TestMethodBodyWriterApiHolder> MethodBodyWriter;
    //    typedef MethodBodyWriter::method_metadata_type MethodMetadata;
    //    typedef MethodMetadata::type_metadata_type TypeMetadata;
    //    typedef MethodMetadata::metadata_import_api_type MetaDataImportApi;
    //    typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;

    //    AssemblyMetadata asmMeta;
    //    
    //    MyMetaDataImportObject *pMetaImpApi_ = NULL;
    //    ASSERT_HRESULT_SUCCEEDED(MyMetaDataImportObject::CreateInstance(&pMetaImpApi_)); 
    //    ATL::CComPtr<MetaDataImportApi> pMetaImpApi(pMetaImpApi_);
    //    //MetaDataImportApi *pMetaImpApi = NULL;

    //    TypeMetadata typeMeta;
    //    typeMeta.Init(asmMeta, *pMetaImpApi);

    //    MethodMetadata methodMeta;
    //    methodMeta.Init(typeMeta, *pMetaImpApi); 
    //    
    //    MethodBodyWriter gen;
    //    gen.Init(methodMeta);
    //    gen.EmitWriteLine(L"Hello, world!!");
    //    gen.Emit(OpCodes::Ret);

    //    std::vector<Instruction const *> const &insts = gen.GetInstructions();
    //    ASSERT_EQ(3, insts.size());
    //    {
    //        OpCode const &op = insts[0]->GetOpCode();
    //        std::wstring const &s = any_cast<std::wstring const &>(insts[0]->GetOprand());
    //        ASSERT_EQ(&OpCodes::Ldstr, &op);
    //        ASSERT_STREQ(L"Hello, world!!", s.c_str());
    //    }
    //    {
    //        OpCode const &op = insts[1]->GetOpCode();
    //        MethodMetadata const *pMethodMeta = any_cast<MethodMetadata const *>(insts[1]->GetOprand());
    //        ASSERT_EQ(&OpCodes::Call, &op);
    //        ASSERT_STREQ(L"WriteLine", pMethodMeta->GetName().c_str());
    //    }
    //    {
    //        OpCode const &op = insts[2]->GetOpCode();
    //        ASSERT_EQ(&OpCodes::Ret, &op);
    //    }
    //}
}
