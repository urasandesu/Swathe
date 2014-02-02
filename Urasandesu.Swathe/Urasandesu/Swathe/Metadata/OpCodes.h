/* 
 * File: OpCodes.h
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
#ifndef URASANDESU_SWATHE_METADATA_OPCODES_H
#define URASANDESU_SWATHE_METADATA_OPCODES_H

#ifndef URASANDESU_SWATHE_METADATA_OPCODE_H
#include <Urasandesu/Swathe/Metadata/OpCode.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class OpCodes
    {
    public:
#define OPDEF_EX(canonicalName, canonicalNameEx) \
        static const OpCodeDetail::OpCode_<OpCodeTypes::canonicalName> canonicalNameEx;
#include <Urasandesu/Swathe/Metadata/OpCodeEx.def>
#undef OPDEF_EX
        
        static OpCode const &GetOpCode(BYTE const *i, BYTE const *i_end)
        {
            using Urasandesu::CppAnonym::CppAnonymNotSupportedException;
            
            auto byte1 = static_cast<BYTE>(0);
            auto byte2 = static_cast<BYTE>(0);
            auto const _STP1 = static_cast<BYTE>(STP1);     // STP1(0xFE) is defined in %INCLUDE%\opcode.def. It expresses the prefix code 1 for Standard Map.
            auto const _REFPRE = static_cast<BYTE>(REFPRE); // REFPRE(0xFF) is defined in %INCLUDE%\opcode.def. It expresses the prefix for Reference Code Encoding.
            if (*i == _STP1)
            {
                byte1 = *i;
                byte2 = *(i + 1);
            }
            else
            {
                byte1 = _REFPRE;
                byte2 = *i;
            }
            
#define OPDEF_EX(canonicalName, canonicalNameEx) \
            if (byte1 == canonicalNameEx.GetByte1() && byte2 == canonicalNameEx.GetByte2()) \
            { \
                _ASSERTE(i + canonicalNameEx.GetLength() <= i_end); \
                return canonicalNameEx; \
            }
#include <Urasandesu/Swathe/Metadata/OpCodeEx.def>
#undef OPDEF_EX
            
            BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
        }
        
    private:
        OpCodes() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_OPCODES_H
