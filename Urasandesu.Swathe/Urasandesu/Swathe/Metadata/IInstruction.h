/* 
 * File: IInstruction.h
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
#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTION_H
#define URASANDESU_SWATHE_METADATA_IINSTRUCTION_H

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTIONFWD_H
#include <Urasandesu/Swathe/Metadata/IInstructionFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_OPCODE_H
#include <Urasandesu/Swathe/Metadata/OpCode.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 

    struct IInstruction
    {
        IInstruction() { }
        virtual mdToken GetToken() const = 0;
        virtual OpCode const &GetOpCode() const = 0;
        virtual Operand const &GetOperand() const = 0;
        virtual SIZE_T GetSize() const = 0;
        virtual UINT GetPopingCount() const = 0;
        virtual UINT GetPushingCount() const = 0;
        virtual std::vector<BYTE> const &GetRawData() const = 0;
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_IINSTRUCTION_H

