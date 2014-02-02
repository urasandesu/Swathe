/* 
 * File: BaseInstructionGenerator.hpp
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


#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEINSTRUCTIONGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEINSTRUCTIONGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEINSTRUCTIONGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseInstructionGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseInstructionGenerator<ApiHolder>::BaseInstructionGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(instruction_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(instruction_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())instruction_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseInstructionGenerator<ApiHolder>::~BaseInstructionGenerator()
    {
        Pimpl()->~instruction_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseInstructionGenerator<ApiHolder>::instruction_generator_pimpl_label_type *BaseInstructionGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<instruction_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseInstructionGenerator<ApiHolder>::instruction_generator_pimpl_label_type const *BaseInstructionGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_INSTRUCTION_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    


    template<class ApiHolder>    
    void BaseInstructionGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdToken BaseInstructionGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    OpCode const &BaseInstructionGenerator<ApiHolder>::GetOpCode() const
    {
        return Pimpl()->GetOpCode();
    }

    template<class ApiHolder>    
    Operand const &BaseInstructionGenerator<ApiHolder>::GetOperand() const
    {
        return Pimpl()->GetOperand();
    }

    template<class ApiHolder>    
    SIZE_T BaseInstructionGenerator<ApiHolder>::GetSize() const
    {
        return Pimpl()->GetSize();
    }

    template<class ApiHolder>    
    UINT BaseInstructionGenerator<ApiHolder>::GetPopingCount() const
    {
        return Pimpl()->GetPopingCount();
    }

    template<class ApiHolder>    
    UINT BaseInstructionGenerator<ApiHolder>::GetPushingCount() const
    {
        return Pimpl()->GetPushingCount();
    }

    template<class ApiHolder>    
    vector<BYTE> const &BaseInstructionGenerator<ApiHolder>::GetRawData() const
    {
        return Pimpl()->GetRawData();
    }

    template<class ApiHolder>    
    void BaseInstructionGenerator<ApiHolder>::SetMethodBody(method_body_generator_label_type *pBodyGen)
    {
        Pimpl()->SetMethodBody(pBodyGen);
    }

    template<class ApiHolder>    
    void BaseInstructionGenerator<ApiHolder>::SetOpCode(OpCode const &opCode)
    {
        Pimpl()->SetOpCode(opCode);
    }

    template<class ApiHolder>    
    void BaseInstructionGenerator<ApiHolder>::SetOperand(Operand const &operand)
    {
        Pimpl()->SetOperand(operand);
    }

    template<class ApiHolder>    
    void BaseInstructionGenerator<ApiHolder>::SetIndex(SIZE_T index)
    {
        Pimpl()->SetIndex(index);
    }

    template<class ApiHolder>    
    void BaseInstructionGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEINSTRUCTIONGENERATOR_HPP

