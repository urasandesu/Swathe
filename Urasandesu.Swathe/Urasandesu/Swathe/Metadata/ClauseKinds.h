/* 
 * File: ClauseKinds.h
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
#ifndef URASANDESU_SWATHE_METADATA_CLAUSEKINDS_H
#define URASANDESU_SWATHE_METADATA_CLAUSEKINDS_H

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace ClauseKindsDetail {

        using Urasandesu::CppAnonym::SafeEnum;

        struct ClauseKindsDef
        {
            enum type
            {
                CK_NONE = COR_ILEXCEPTION_CLAUSE_NONE, 
                CK_FILTER = COR_ILEXCEPTION_CLAUSE_FILTER, 
                CK_FINALLY = COR_ILEXCEPTION_CLAUSE_FINALLY, 
                CK_FAULT = COR_ILEXCEPTION_CLAUSE_FAULT, 
                CK_CATCH = 0x0010, 
                CK_UNREACHED = 0xFFFF
            };
            
            // TODO: 1 ケタ目を使えば簡単に変換ができる想定。必要であれば、変換メソッドをここに。
            static CorExceptionFlag ToCorExceptionFlag(Urasandesu::CppAnonym::SafeEnum<ClauseKindsDetail::ClauseKindsDef> const &clauseKind)
            {
                return static_cast<CorExceptionFlag>(clauseKind.Value() & 0x000F);
            }

            static Urasandesu::CppAnonym::SafeEnum<ClauseKindsDetail::ClauseKindsDef> ToClauseKinds(CorExceptionFlag flags, DWORD classToken)
            {
                using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

                if (flags == COR_ILEXCEPTION_CLAUSE_NONE && IsNilToken(classToken))
                    return CK_NONE;
                else if (flags == COR_ILEXCEPTION_CLAUSE_FILTER)
                    return CK_FILTER;
                else if (flags == COR_ILEXCEPTION_CLAUSE_FINALLY)
                    return CK_FINALLY;
                else if (flags == COR_ILEXCEPTION_CLAUSE_FAULT)
                    return CK_FAULT;
                else if (flags == COR_ILEXCEPTION_CLAUSE_NONE)
                    return CK_CATCH;
                else
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
            }
        };

    }   // namespace ClauseKindsDetail {

    typedef Urasandesu::CppAnonym::SafeEnum<ClauseKindsDetail::ClauseKindsDef> ClauseKinds;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_CLAUSEKINDS_H
