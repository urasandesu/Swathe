/* 
 * File: StackBehaviour.h
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
#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOUR_H
#define URASANDESU_SWATHE_METADATA_STACKBEHAVIOUR_H

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURTYPES_H
#include <Urasandesu/Swathe/Metadata/StackBehaviourTypes.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOURFWD_H
#include <Urasandesu/Swathe/Metadata/StackBehaviourFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    class StackBehaviour
    {
    public:
        StackBehaviour(StackBehaviourTypes const &type) : 
            m_type(type)
        {
            m_typeList.push_back(type); 
        }

        StackBehaviour operator +(StackBehaviour const &other) const
        {
            return StackBehaviour(GetTypeList(), other.GetTypeList());
        }

        StackBehaviour &operator +=(StackBehaviour const &other)
        {
            m_typeList.insert(m_typeList.end(), other.GetTypeList().begin(), other.GetTypeList().end());
            return *this;
        }

        bool operator ==(StackBehaviour const &other) const
        {
            using namespace Urasandesu::CppAnonym::Collections;
            return SequenceEqual(GetTypeList().begin(), GetTypeList().end(), 
                                 other.GetTypeList().begin(), other.GetTypeList().end());
        }

        bool operator !=(StackBehaviour const &other) const
        {
            return !(*this == other);
        }

        StackBehaviourTypes GetType() const { return m_type; }
        std::vector<StackBehaviourTypes> const &GetTypeList() const { return m_typeList; }

    private:
        StackBehaviour(std::vector<StackBehaviourTypes> const &typeList1, std::vector<StackBehaviourTypes> const &typeList2)
        { 
            m_typeList.reserve(typeList1.size() + typeList2.size());
            m_typeList.insert(m_typeList.end(), typeList1.begin(), typeList1.end());
            m_typeList.insert(m_typeList.end(), typeList2.begin(), typeList2.end());
        }

        StackBehaviourTypes m_type;
        std::vector<StackBehaviourTypes> m_typeList;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_STACKBEHAVIOUR_H
