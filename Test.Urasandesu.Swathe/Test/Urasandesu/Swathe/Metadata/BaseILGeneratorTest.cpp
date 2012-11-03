#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_H
#include <Urasandesu/CppAnonym/Utilities/IsAnyT.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYWRITER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodBodyWriter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODES_H
#include <Urasandesu/CppAnonym/Metadata/OpCodes.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

// Forward Declaration    
namespace MockC17C4C45 {

    typedef std::vector<boost::any> AnyVector;

    class ATL_NO_VTABLE MockTypeFindable;

    class MockMetadataDispenser;

    class MockAssemblyNameMetadata;

    class MockTypeNameMetadata;

    class MockMethodMetadata;

    class MockMethodNameMetadata;

}   // namespace MockC17C4C45 {

namespace MockC17C4C45 {

    class ATL_NO_VTABLE MockTypeFindable : 
        boost::noncopyable
    {
    public:
        template<class T>
        T const &Map() const 
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;

            AnyVector::iterator result;
            result = std::find_if(m_typePtrs.begin(), m_typePtrs.end(), IsAnyT<shared_ptr<T> >()); 
            _ASSERTE(result != m_typePtrs.end());

            return any_cast<shared_ptr<T> >(*result).get();
        }

        mutable AnyVector m_typePtrs;
    };

    
    
    
    
    class MockMetadataDispenser : 
        public MockTypeFindable
    {
    public:
        typedef MockAssemblyNameMetadata assembly_name_metadata_type;

        MockMetadataDispenser() { }

        assembly_name_metadata_type *NewAssemblyName(std::wstring const &name) const
        {
            using boost::shared_ptr;
            using boost::make_shared;

            shared_ptr<assembly_name_metadata_type> pAsmNameMeta(make_shared<assembly_name_metadata_type>());
            m_asmNamePtrs.push_back(pAsmNameMeta);

            return pAsmNameMeta.get();
        }

        mutable AnyVector m_asmNamePtrs;
    };




    class MockAssemblyNameMetadata : 
        public MockTypeFindable
    {
    public:
        typedef MockTypeNameMetadata type_name_metadata_type;

        MockAssemblyNameMetadata() { }

        type_name_metadata_type *NewTypeName(std::wstring const &name, Urasandesu::CppAnonym::Metadata::TypeKinds const &kind) const
        {
            using boost::shared_ptr;
            using boost::make_shared;

            shared_ptr<type_name_metadata_type> pTypeNameMeta(make_shared<type_name_metadata_type>());
            m_typeNamePtrs.push_back(pTypeNameMeta);

            return pTypeNameMeta.get();
        }

        mutable AnyVector m_typeNamePtrs;
    };





    class MockTypeNameMetadata : 
        public MockTypeFindable
    {
    public:
        typedef MockTypeNameMetadata this_type;

        typedef MockMethodNameMetadata method_name_metadata_type;

        MockTypeNameMetadata() { }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 Urasandesu::CppAnonym::Metadata::CallingConventions const &callingConvention, 
                                                 this_type const &retTypeName, 
                                                 std::vector<this_type const *> const &paramTypeNames) const
        {
            using boost::shared_ptr;
            using boost::make_shared;

            shared_ptr<method_name_metadata_type> pMethodNameMeta(make_shared<method_name_metadata_type>());
            m_methodNamePtrs.push_back(pMethodNameMeta);

            return pMethodNameMeta.get();
        }
        
        mutable AnyVector m_methodNamePtrs;
    };
    
    
    
    
    
    class MockMethodMetadata : 
        public MockTypeFindable
    {
    public:
        MockMethodMetadata() { }

    };




    class MockMethodNameMetadata : 
        public MockTypeFindable
    {
    public:
        MockMethodNameMetadata() { }
    
    };
    
}   // namespace MockC17C4C45 {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Metadata_BaseMethodBodyWriterTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_BaseMethodBodyWriterTest, OpCodesTest_01)
    {
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





    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_BaseMethodBodyWriterTest, StackBehavioursTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
        expected += StackBehaviours::PopRef();
     
        typedef OpCodes OpCodes;
        ASSERT_STREQ(L"CEE_STELEM_REF,stelem.ref,PopRef+PopI+PopRef"
                     L",Push0,InlineNone,IObjModel,1,0xFF,0xA2,NEXT", OpCodes::Stelem_Ref.CStr());
        ASSERT_TRUE(expected == OpCodes::Stelem_Ref.GetBehaviour0());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_BaseMethodBodyWriterTest, StackBehavioursTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
     
        typedef OpCodes OpCodes;
        ASSERT_TRUE(expected != OpCodes::Stfld.GetBehaviour0());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Metadata_BaseMethodBodyWriterTest, EmitWriteLineTest_01)
    {
        namespace mpl = boost::mpl;
        using boost::any_cast;
        using boost::shared_ptr;
        using boost::make_shared;
        using namespace MockC17C4C45;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        struct TestApiHolder
        {
            typedef mpl::map<
                mpl::pair<Interfaces::MetadataDispenserLabel, MockMetadataDispenser>, 
                mpl::pair<Interfaces::AssemblyNameMetadataLabel, MockAssemblyNameMetadata>, 
                mpl::pair<Interfaces::TypeNameMetadataLabel, MockTypeNameMetadata>, 
                mpl::pair<Interfaces::MethodNameMetadataLabel, MockMethodNameMetadata>, 
                mpl::pair<Interfaces::MethodMetadataLabel, MockMethodMetadata>, 
                mpl::pair<IMetaDataImport2, IMetaDataImport2> 
            > api_cartridges;
        };

        typedef MockMetadataDispenser MetadataDispenser;
        typedef MockMethodMetadata MethodMetadata;
        typedef MockMethodNameMetadata MethodNameMetadata;
        typedef BaseMethodBodyWriter<TestApiHolder> MethodBodyWriter; 

        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());

        shared_ptr<MethodMetadata> pMethodMeta(make_shared<MethodMetadata>());
        pMethodMeta->m_typePtrs.push_back(pMetaDisp);

        shared_ptr<MethodBodyWriter> pGen(make_shared<MethodBodyWriter>());
        pGen->Init(*pMethodMeta);
        pGen->EmitWriteLine(L"Hello, world!!");
        pGen->Emit(OpCodes::Ret);

        std::vector<Instruction const *> const &insts = pGen->GetInstructions();
        ASSERT_EQ(3, insts.size());
        {
            OpCode const &op = insts[0]->GetOpCode();
            std::wstring const &s = any_cast<std::wstring const &>(insts[0]->GetOprand());
            ASSERT_EQ(&OpCodes::Ldstr, &op);
            ASSERT_STREQ(L"Hello, world!!", s.c_str());
        }
        {
            OpCode const &op = insts[1]->GetOpCode();
            MethodNameMetadata const *pMethodNameMeta = any_cast<MethodNameMetadata const *>(insts[1]->GetOprand());
            ASSERT_EQ(&OpCodes::Call, &op);
            ASSERT_TRUE(pMethodNameMeta != NULL);
        }
        {
            OpCode const &op = insts[2]->GetOpCode();
            ASSERT_EQ(&OpCodes::Ret, &op);
        }
    }
}
