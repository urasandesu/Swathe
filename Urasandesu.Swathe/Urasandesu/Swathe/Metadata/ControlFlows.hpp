/* 
 * File: ControlFlows.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP
#define URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP

#ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOW_H
#include <Urasandesu/Swathe/Metadata/ControlFlow.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class ControlFlows
    {
    public:
        inline static ControlFlow const &Branch() { static ControlFlow f(ControlFlowTypes::CFT_BRANCH); return f; }
        inline static ControlFlow const &Break() { static ControlFlow f(ControlFlowTypes::CFT_BREAK); return f; }
        inline static ControlFlow const &Call() { static ControlFlow f(ControlFlowTypes::CFT_CALL); return f; }
        inline static ControlFlow const &CondBranch() { static ControlFlow f(ControlFlowTypes::CFT_COND_BRANCH); return f; }
        inline static ControlFlow const &Meta() { static ControlFlow f(ControlFlowTypes::CFT_META); return f; }
        inline static ControlFlow const &Next() { static ControlFlow f(ControlFlowTypes::CFT_NEXT); return f; }
        inline static ControlFlow const &Return() { static ControlFlow f(ControlFlowTypes::CFT_RETURN); return f; }
        inline static ControlFlow const &Throw() { static ControlFlow f(ControlFlowTypes::CFT_THROW); return f; }
    private:
        ControlFlows() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_CONTROLFLOWS_HPP
