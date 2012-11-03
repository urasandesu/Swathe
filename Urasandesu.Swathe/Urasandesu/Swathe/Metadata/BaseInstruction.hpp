#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTION_HPP
#define URASANDESU_SWATHE_METADATA_BASEINSTRUCTION_HPP

#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_METHODBODYWRITERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/MethodBodyWriterLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_INTERFACES_INSTRUCTIONAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/Metadata/Interfaces/InstructionApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTIONFWD_HPP
#include <Urasandesu/Swathe/Metadata/BaseInstructionFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OpCode;

    template<class ApiCartridgesHolder, class ApiLabel>
    struct InstructionApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::InstructionApiHolderLabel, ApiLabel>
    {
    };

    // TODO: We should make BaseReadOnlyInstruction to parse an existing IL stream.
    template<
        class InstructionApiHolder
    >    
    class BaseInstruction
    {
    public:
        typedef BaseInstruction<InstructionApiHolder> this_type;

        typedef typename InstructionApiAt<InstructionApiHolder, Interfaces::MethodBodyWriterLabel>::type method_body_writer_type;
        typedef typename InstructionApiAt<InstructionApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename InstructionApiAt<InstructionApiHolder, Interfaces::IMethodNameMetadataLabel>::type i_method_name_metadata_type;
        typedef typename InstructionApiAt<InstructionApiHolder, Interfaces::IFieldNameMetadataLabel>::type i_field_name_metadata_type;

        BaseInstruction() :
            m_pBodyAsScope(NULL),
            m_pOpCode(NULL),
            m_popingCountInitialized(false),
            m_popingCount(0),
            m_pushingCountInitialized(false),
            m_pushingCount(0)
        { }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pBodyAsScope != NULL); return m_pBodyAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return *this; }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        inline OpCode const &GetOpCode() const
        {
            _ASSERTE(m_pOpCode != NULL);
            return *m_pOpCode;
        }
        
        inline void SetOpCode(OpCode const &opCode)
        {
            m_pOpCode = &opCode;
            Reset();
        }

        inline boost::any const &GetOprand() const
        {
            return m_oprand;
        }

        inline void SetOprand(boost::any const &oprand)
        {
            m_oprand = oprand;
            Reset();
        }

        UINT GetPopingCount() const
        {
            using Interfaces::MetadataSpecialValues;

            if (!m_popingCountInitialized)
            {
                StackBehaviour const &behaviour0 = GetOpCode().GetBehaviour0();
                std::vector<StackBehaviourTypes> const &typeList = behaviour0.GetTypeList();
                m_popingCount = 0;
                typedef std::vector<StackBehaviourTypes>::const_iterator ConstIterator;
                for (ConstIterator ci = typeList.cbegin(), ci_end = typeList.cend(); ci != ci_end; ++ci)
                {
                    switch ((*ci).Value())
                    {
                        case StackBehaviourTypes::SBT_POP0:
                            // no effect
                            break;
                        case StackBehaviourTypes::SBT_POP1:
                        case StackBehaviourTypes::SBT_POP_I:
                        case StackBehaviourTypes::SBT_POP_I8:
                        case StackBehaviourTypes::SBT_POP_R4:
                        case StackBehaviourTypes::SBT_POP_R8:
                        case StackBehaviourTypes::SBT_POP_REF:
                            ++m_popingCount;
                            break;
                        case StackBehaviourTypes::SBT_VAR_POP: 
                            if (&GetOpCode() == &OpCodes::Call ||
                                &GetOpCode() == &OpCodes::Calli ||
                                &GetOpCode() == &OpCodes::Callvirt ||
                                &GetOpCode() == &OpCodes::Newobj)
                            {
                                boost::any const &operand = GetOprand();
                                i_method_name_metadata_type const *pMethodName = NULL;
                                pMethodName = boost::any_cast<i_method_name_metadata_type const *>(operand);
                                m_popingCount += pMethodName->GetParameterTypeNames().size();
                            }
                            else if (&GetOpCode() == &OpCodes::Ret)
                            {
                                method_name_metadata_generator_type const &methodNameGen = Map<method_name_metadata_generator_type>();
                                m_popingCount = methodNameGen.GetName() == MetadataSpecialValues::TYPE_NAME_OF_VOID ? 0 : 1;
                            }
                            else
                            {
                                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                            }
                            break;
                        default:
                            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                    }
                }
                m_popingCountInitialized = true;
            }
            return m_popingCount;
        }

        UINT GetPushingCount() const
        {
            using Interfaces::MetadataSpecialValues;

            if (!m_pushingCountInitialized)
            {
                StackBehaviour const &behaviour1 = GetOpCode().GetBehaviour1();
                std::vector<StackBehaviourTypes> const &typeList = behaviour1.GetTypeList();
                m_pushingCount = 0;
                typedef std::vector<StackBehaviourTypes>::const_iterator ConstIterator;
                for (ConstIterator ci = typeList.cbegin(), ci_end = typeList.cend(); ci != ci_end; ++ci)
                {
                    switch ((*ci).Value())
                    {
                        case StackBehaviourTypes::SBT_PUSH0:
                            // no effect
                            break;
                        case StackBehaviourTypes::SBT_PUSH1:
                        case StackBehaviourTypes::SBT_PUSH_I:
                        case StackBehaviourTypes::SBT_PUSH_I8:
                        case StackBehaviourTypes::SBT_PUSH_R4:
                        case StackBehaviourTypes::SBT_PUSH_R8:
                        case StackBehaviourTypes::SBT_PUSH_REF:
                            ++m_pushingCount;
                            break;
                        case StackBehaviourTypes::SBT_VAR_PUSH: 
                            if (&GetOpCode() == &OpCodes::Call ||
                                &GetOpCode() == &OpCodes::Calli ||
                                &GetOpCode() == &OpCodes::Callvirt)
                            {
                                boost::any const &operand = GetOprand();
                                i_method_name_metadata_type const *pMethodName = NULL;
                                pMethodName = boost::any_cast<i_method_name_metadata_type const *>(operand);
                                m_pushingCount = pMethodName->GetReturnTypeName().GetName() == MetadataSpecialValues::TYPE_NAME_OF_VOID ? 0 : 1;
                            }
                            else
                            {
                                BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                            }
                            break;
                        default:
                            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                    }
                }
                m_pushingCountInitialized = true;
            }
            return m_pushingCount;
        }

        void PutTo(SimpleBlob &blob) const
        {
            if (!m_pBlob.get())
            {
                m_pBlob = boost::make_shared<SimpleBlob>();
                if (GetOpCode().GetByte1() == 0xff)
                {
                    m_pBlob->Put<BYTE>(GetOpCode().GetByte2());
                }
                else
                {
                    m_pBlob->Put<BYTE>(GetOpCode().GetByte1());
                    m_pBlob->Put<BYTE>(GetOpCode().GetByte2());
                }

                OperandParam const &operandParam = GetOpCode().GetOperandParam();
                switch (operandParam.GetType().Value())
                {
                    case OperandParamTypes::OPT_INLINE_NONE: 
                        // no effect
                        break;
                    case OperandParamTypes::OPT_INLINE_BR_TARGET: 
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_FIELD:
                        {
                            boost::any const &operand = GetOprand();
                            i_field_name_metadata_type const *pFieldName = NULL;
                            pFieldName = boost::any_cast<i_field_name_metadata_type const *>(operand);
                            m_pBlob->Put<mdToken>(pFieldName->Resolve().GetToken());
                        }
                        break;
                    case OperandParamTypes::OPT_INLINE_I:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_I8:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_METHOD:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_R:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_SIG:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_STRING:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_SWITCH:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_TOK:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_TYPE:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_INLINE_VAR:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_SHORT_INLINE_BR_TARGET:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_SHORT_INLINE_I:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_SHORT_INLINE_R:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    case OperandParamTypes::OPT_SHORT_INLINE_VAR:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        break;
                    default:
                        BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                }
            }
            
            for (BYTE const *ci = m_pBlob->Ptr(), *ci_end = ci + m_pBlob->Size(); ci != ci_end; ++ci)
                blob.Put<BYTE>(*ci);
        }

    private:
        friend typename method_body_writer_type;

        void Init(method_body_writer_type &bodyAsScope) const
        {
            _ASSERTE(m_pBodyAsScope == NULL);
            m_pBodyAsScope = &bodyAsScope;
        }

        void Reset()
        {
            m_popingCountInitialized = false;
            m_pushingCountInitialized = false;
        }

        mutable method_body_writer_type *m_pBodyAsScope;
        OpCode const *m_pOpCode;
        boost::any m_oprand;
        mutable bool m_popingCountInitialized;
        mutable UINT m_popingCount;
        mutable bool m_pushingCountInitialized;
        mutable UINT m_pushingCount;
        mutable boost::shared_ptr<SimpleBlob> m_pBlob;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTION_HPP