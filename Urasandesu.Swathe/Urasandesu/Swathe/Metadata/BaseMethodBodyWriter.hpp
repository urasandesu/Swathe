#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITER_HPP
#define URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITER_HPP

#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODBODYWRITERAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodBodyWriterApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/Swathe/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTION_HPP
#include <Urasandesu/Swathe/Metadata/BaseInstruction.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_INSTRUCTIONLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/InstructionLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITERFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseMethodBodyWriterFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodBodyWriterApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodBodyWriterApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodBodyWriterApiHolder
    >
    class BaseMethodBodyWriter :
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::InstructionLabel>::type, VeryQuickHeapButMustUseSubscriptOperator>
            >
        >
    {
    public:
        typedef BaseMethodBodyWriter<MethodBodyWriterApiHolder> this_type;

        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::MethodMetadataGeneratorLabel>::type method_metadata_generator_type;
        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::IFieldNameMetadataLabel>::type i_field_name_metadata_type;
        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::IMethodNameMetadataLabel>::type i_method_name_metadata_type;
        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::IMethodMetadataLabel>::type i_method_metadata_type;        
        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::LocalsNameMetadataGeneratorLabel>::type locals_name_metadata_generator_type;
        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Interfaces::InstructionLabel>::type instruction_type;
        typedef typename MethodBodyWriterApiAt<MethodBodyWriterApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;        

        typedef ObjectTag<instruction_type, VeryQuickHeapButMustUseSubscriptOperator> instruction_obj_tag_type;
        typedef typename type_decided_by<instruction_obj_tag_type>::type instruction_heap_type;

        BaseMethodBodyWriter() : 
            m_pMethodNameGenAsScope(NULL),
            m_instructionsInitialized(false),
            m_rawHeaderInitialized(false),
            m_rawHeader(COR_ILMETHOD_FAT()),
            m_rawBodyMaxStackInitialized(false),
            m_rawBodyMaxStack(0)
        { }
        
        void Init(method_name_metadata_generator_type &methodNameGenAsScope) const
        {
            _ASSERTE(m_pMethodNameGenAsScope == NULL);
            m_pMethodNameGenAsScope = &methodNameGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            //_ASSERTE(m_pModNameAsScope != NULL || m_pModAsScope != NULL);
            //if (m_pModNameAsScope != NULL)
            //    return m_pModNameAsScope->Map<T>();
            //else
            //    return m_pModAsScope->GetModuleNameCore()->Map<T>();
            _ASSERTE(m_pMethodNameGenAsScope != NULL);
            return m_pMethodNameGenAsScope->Map<T>();
        }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        locals_name_metadata_generator_type const &GetLocalsName() const
        {
            if (!m_pLocalsName.get())
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                m_pLocalsName = boost::make_shared<locals_name_metadata_generator_type>();
                m_pLocalsName->Init(*pMutableThis);
            }
            return *m_pLocalsName.get();
        }
        //local_name_metadata_generator_type *NewLocalNameMetadataGenerator(type_metadata_type const &localType)
        //{
        //    this_type *pMutableThis = const_cast<this_type *>(this);

        //    local_name_metadata_generator_type *pLocalNameMetaGen = NULL;
        //    pLocalNameMetaGen = pMutableThis->LocalNameMetadataGeneratorHeap().New();
        //    pLocalNameMetaGen->Init(*pMutableThis);
        //    pLocalNameMetaGen->SetLocalType(localType);
        //    return pLocalNameMetaGen;
        //}

        void EmitWriteLine(std::wstring const &s)
        {
            typedef OpCodes OpCodes;
            {
                instruction_type *pInst = NewInstruction();
                pInst->SetOpCode(OpCodes::Ldstr);
                pInst->SetOprand(s);
            }
            {
                instruction_type *pInst = NewInstruction();
                pInst->SetOpCode(OpCodes::Call);

                this_type const *immutableThis = this;

                metadata_dispenser_type const *pMetaDisp = immutableThis->Map<metadata_dispenser_type>();

                assembly_name_metadata_type const *pMSCorLibName = NULL;
                {
                    std::wstring name(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                      L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
                    pMSCorLibName = pMetaDisp->NewAssemblyName(name);
                }

                type_name_metadata_type const *pConsoleName = NULL;
                {
                    std::wstring name(L"System.Console");
                    TypeKinds kind(TypeKinds::TK_CLASS);
                    pConsoleName = pMSCorLibName->NewTypeName(name, kind);
                }

                method_name_metadata_type const *pWriteLineName = NULL;
                {
                    std::wstring name(L"WriteLine");
                    CallingConventions callingConvention(CallingConventions::CC_STANDARD);
                    type_name_metadata_type const *pRetTypeName = NULL;
                    pRetTypeName = pMSCorLibName->NewTypeName(L"System.Void", TypeKinds::TK_VOID);
                    std::vector<type_name_metadata_type const *> paramTypeNames;
                    paramTypeNames.push_back(pMSCorLibName->NewTypeName(L"System.String", TypeKinds::TK_STRING));
                    pWriteLineName = pConsoleName->NewMethodName(name, callingConvention, *pRetTypeName, paramTypeNames);
                }

                pInst->SetOprand(pWriteLineName);
            }
        }

        void Emit(OpCode const &op)
        {
            instruction_type *pInst = NewInstruction();
            pInst->SetOpCode(op);
        }

        void Emit(OpCode const &op, int val)
        {
            if (&op != &OpCodes::Ldloca)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            instruction_type *pInst = NewInstruction();
            pInst->SetOpCode(op);
            pInst->SetOprand(val);
        }

        void Emit(OpCode const &op, i_field_name_metadata_type const &fieldName)
        {
            if (&op != &OpCodes::Ldsfld && 
                &op != &OpCodes::Stsfld)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            instruction_type *pInst = NewInstruction();
            pInst->SetOpCode(op);
            pInst->SetOprand(&fieldName);
        }

        void Emit(OpCode const &op, i_method_name_metadata_type const &methodName)
        {
            if (&op != &OpCodes::Ldftn &&
                &op != &OpCodes::Newobj &&
                &op != &OpCodes::Call)
            {
                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
            }
            instruction_type *pInst = NewInstruction();
            pInst->SetOpCode(op);
            pInst->SetOprand(&methodName);
        }

        void Emit(OpCode const &op, i_method_metadata_type const &method)
        {
            Emit(op, method.GetMethodName());
        }

        std::vector<instruction_type const *> const &GetInstructions() const
        {
            if (!m_instructionsInitialized)
            {
                SIZE_T size = InstructionHeap().Size();
                std::vector<instruction_type const *> instructions(size);
                for (SIZE_T i = 0; i < size; ++i)
                    instructions[i] = InstructionHeap()[i];
                instructions.swap(m_instructions);
                m_instructionsInitialized = true;
            }
            return m_instructions;
        }

        COR_ILMETHOD_FAT const &GetRawHeader() const
        {
            if (!m_instructionsInitialized || !m_rawHeaderInitialized)
            {
                ::ZeroMemory(&m_rawHeader, sizeof(COR_ILMETHOD_FAT));
                m_rawHeader.SetMaxStack(GetRawBodyMaxStack());
                m_rawHeader.SetCodeSize(GetRawBody().Size());
                m_rawHeader.SetLocalVarSigTok(GetLocalsName().Resolve().GetToken());
                m_rawHeader.SetFlags(GetRawHeaderFlags());
                m_rawHeaderInitialized = true;
            }
            return m_rawHeader;
        }

        UINT GetRawHeaderFlags() const
        {
            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
        }

        SimpleBlob const &GetRawBody() const
        {
            if (!m_pRawBody.get())
            {
                m_pRawBody = boost::make_shared<SimpleBlob>();
                std::vector<instruction_type const *> const &insts = GetInstructions();
                typedef std::vector<instruction_type const *>::const_iterator ConstIterator;
                for (ConstIterator ci = insts.cbegin(), ci_end = insts.cend(); ci != ci_end; ++ci)
                    (*ci)->PutTo(*m_pRawBody.get());
            }
            return *m_pRawBody.get(); 
        }

        UINT GetRawBodyMaxStack() const
        {
            if (!m_instructionsInitialized || !m_rawBodyMaxStackInitialized)
            {
                std::vector<instruction_type const *> const &insts = GetInstructions();
                UINT current = 0;
                m_rawBodyMaxStack = 0;
                typedef std::vector<instruction_type const *>::const_iterator ConstIterator;
                for (ConstIterator ci = insts.cbegin(), ci_end = insts.cend(); ci != ci_end; ++ci)
                {
                    current -= (*ci)->GetPopingCount();
                    current += (*ci)->GetPushingCount();
                    if (m_rawBodyMaxStack < current)
                        m_rawBodyMaxStack = current;
                }
        
                if (m_rawBodyMaxStack == 2)
                {
                    BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                }
            }
            return m_rawBodyMaxStack;
        }

    private:
        friend typename method_name_metadata_generator_type;
        friend typename method_metadata_generator_type;

        instruction_type *NewInstruction()
        {
            m_instructionsInitialized = false;
            instruction_type *pInst = NULL;
            pInst = InstructionHeap().New();
            pInst->Init(*this);
            return pInst;
        }

        instruction_heap_type &InstructionHeap()
        {
            return Of<instruction_obj_tag_type>();
        }
        
        instruction_heap_type const &InstructionHeap() const
        {
            return Of<instruction_obj_tag_type>();
        }

        ULONG SaveTo(pe_writer_host_type &peWriterHost) const
        {
            COR_ILMETHOD_FAT const &rawHeader = GetRawHeader();
            SimpleBlob const &rawBody = GetRawBody();
            return peWriterHost.WriteMethodBody(rawHeader, rawBody);
        }

        mutable method_name_metadata_generator_type *m_pMethodNameGenAsScope;
        mutable bool m_instructionsInitialized;
        mutable std::vector<instruction_type const *> m_instructions;
        boost::shared_ptr<locals_name_metadata_generator_type> mutable m_pLocalsName;
        mutable bool m_rawHeaderInitialized;
        mutable COR_ILMETHOD_FAT m_rawHeader;
        mutable bool m_rawBodyMaxStackInitialized;
        mutable UINT m_rawBodyMaxStack;
        mutable boost::shared_ptr<SimpleBlob> m_pRawBody;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEMETHODBODYWRITER_HPP