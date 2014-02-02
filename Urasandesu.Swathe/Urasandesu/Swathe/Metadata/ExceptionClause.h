/* 
 * File: ExceptionClause.h
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
#ifndef URASANDESU_SWATHE_METADATA_EXCEPTIONCLAUSE_H
#define URASANDESU_SWATHE_METADATA_EXCEPTIONCLAUSE_H

#ifndef URASANDESU_SWATHE_METADATA_EXCEPTIONCLAUSEFWD_H
#include <Urasandesu/Swathe/Metadata/ExceptionClauseFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CLAUSEKINDS_H
#include <Urasandesu/Swathe/Metadata/ClauseKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTIONFWD_H
#include <Urasandesu/Swathe/Metadata/IInstructionFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 

    namespace ExceptionClauseDetail {
        
        using boost::blank;
        using boost::variant;
        using Urasandesu::CppAnonym::Utilities::Empty;

        class ExceptionClauseImpl
        {
        public:
            explicit ExceptionClauseImpl(IInstructionPtrRange::iterator const &begin) : 
                m_clauseKind(ClauseKinds::CK_UNREACHED), 
                m_begin(begin)
            { }

            ClauseKinds GetClauseKind() const
            {
                return m_clauseKind;
            }

            void SetClauseKind(ClauseKinds const &clauseKind)
            {
                _ASSERTE(m_clauseKind == ClauseKinds::CK_UNREACHED);
                m_clauseKind = clauseKind;
            }

            IInstructionPtrRange::iterator GetTryStart() const
            {
                return m_tryStart;
            }

            void SetTryStart(IInstructionPtrRange::iterator const &tryStart)
            {
                _ASSERTE(m_tryStart == IInstructionPtrRange::iterator());
                m_tryStart = tryStart;
            }

            SIZE_T GetTryStartIndex() const
            {
                return GetTryStart() - m_begin;
            }

            IInstructionPtrRange::iterator GetTryEnd() const
            {
                return m_tryEnd;
            }

            void SetTryEnd(IInstructionPtrRange::iterator const &tryEnd)
            {
                _ASSERTE(m_tryEnd == IInstructionPtrRange::iterator());
                m_tryEnd = tryEnd;
            }

            SIZE_T GetTryEndIndex() const
            {
                return GetTryEnd() - m_begin;
            }

            IInstructionPtrRange::iterator GetClauseStart() const
            {
                return m_clauseStart;
            }

            void SetClauseStart(IInstructionPtrRange::iterator const &clauseStart)
            {
                _ASSERTE(m_clauseStart == IInstructionPtrRange::iterator());
                m_clauseStart = clauseStart;
            }

            SIZE_T GetClauseStartIndex() const
            {
                return GetClauseStart() - m_begin;
            }

            IInstructionPtrRange::iterator GetClauseEnd() const
            {
                return m_clauseEnd;
            }

            void SetClauseEnd(IInstructionPtrRange::iterator const &clauseEnd)
            {
                _ASSERTE(m_clauseEnd == IInstructionPtrRange::iterator());
                m_clauseEnd = clauseEnd;
            }

            SIZE_T GetClauseEndIndex() const
            {
                return GetClauseEnd() - m_begin;
            }

            IInstructionPtrRange::iterator GetFilterStart() const
            {
                using boost::get;
                return get<IInstructionPtrRange::iterator>(m_filterStartOrExType);
            }

            void SetFilterStart(IInstructionPtrRange::iterator const &filterStart)
            {
                _ASSERTE(Empty(m_filterStartOrExType));
                m_filterStartOrExType = filterStart;
            }

            SIZE_T GetFilterStartIndex() const
            {
                return GetFilterStart() - m_begin;
            }

            IType const *GetExceptionType() const
            {
                using boost::get;
                return get<IType const *>(m_filterStartOrExType);
            }

            void SetExceptionType(IType const *pExType)
            {
                _ASSERTE(Empty(m_filterStartOrExType));
                m_filterStartOrExType = pExType;
            }

        private:
            ClauseKinds m_clauseKind;
            IInstructionPtrRange::iterator m_begin;
            IInstructionPtrRange::iterator m_tryStart;
            IInstructionPtrRange::iterator m_tryEnd;
            IInstructionPtrRange::iterator m_clauseStart;
            IInstructionPtrRange::iterator m_clauseEnd;
            variant<blank, IInstructionPtrRange::iterator, IType const *> m_filterStartOrExType;
        };

    }   // namespace ExceptionClauseDetail {

    struct ExceptionClause : 
        ExceptionClauseDetail::ExceptionClauseImpl
    {
        explicit ExceptionClause(IInstructionPtrRange::iterator const &begin) : 
            ExceptionClauseDetail::ExceptionClauseImpl(begin)
        { }
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_EXCEPTIONCLAUSE_H

