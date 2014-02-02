/* 
 * File: StackBehaviours.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP
#define URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOUR_H
#include <Urasandesu/Swathe/Metadata/StackBehaviour.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class StackBehaviours
    {
    public:
        inline static StackBehaviour const &Pop0() { static StackBehaviour b(StackBehaviourTypes::SBT_POP0); return b; }
        inline static StackBehaviour const &Pop1() { static StackBehaviour b(StackBehaviourTypes::SBT_POP1); return b; }
        inline static StackBehaviour const &PopI() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_I); return b; }
        inline static StackBehaviour const &PopI8() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_I8); return b; }
        inline static StackBehaviour const &PopR4() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_R4); return b; }
        inline static StackBehaviour const &PopR8() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_R8); return b; }
        inline static StackBehaviour const &PopRef() { static StackBehaviour b(StackBehaviourTypes::SBT_POP_REF); return b; }
        inline static StackBehaviour const &Push0() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH0); return b; }
        inline static StackBehaviour const &Push1() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH1); return b; }
        inline static StackBehaviour const &PushI() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_I); return b; }
        inline static StackBehaviour const &PushI8() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_I8); return b; }
        inline static StackBehaviour const &PushR4() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_R4); return b; }
        inline static StackBehaviour const &PushR8() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_R8); return b; }
        inline static StackBehaviour const &PushRef() { static StackBehaviour b(StackBehaviourTypes::SBT_PUSH_REF); return b; }
        inline static StackBehaviour const &VarPop() { static StackBehaviour b(StackBehaviourTypes::SBT_VAR_POP); return b; }
        inline static StackBehaviour const &VarPush() { static StackBehaviour b(StackBehaviourTypes::SBT_VAR_PUSH); return b; }
    private:
        StackBehaviours() { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURS_HPP
