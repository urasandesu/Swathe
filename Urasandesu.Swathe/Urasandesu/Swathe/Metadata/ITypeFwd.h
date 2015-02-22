/* 
 * File: ITypeFwd.h
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
#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#define URASANDESU_SWATHE_METADATA_ITYPEFWD_H

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 
    
    struct IType;
    struct IMethod;

    typedef boost::variant<
        boost::blank,
        IModule const *, 
        IType const *, 
        IMethod const *
    > TypeProvider;

    typedef boost::any_range<IType const *, boost::single_pass_traversal_tag, IType const *, std::ptrdiff_t> ITypePtrRange;

    class ArrayDimension
    {
    public:
        typedef ArrayDimension this_type;
        
        ArrayDimension() : 
            m_size(-1), 
            m_lowerBound(-1)
        { }
        
        ArrayDimension(UINT size, UINT lowerBound) : 
            m_size(size), 
            m_lowerBound(lowerBound)
        { }
        
        UINT GetSize() const { return m_size; }
        UINT GetLowerBound() const { return m_lowerBound; }
        
        bool operator ==(this_type const &other) const { return m_size == other.m_size && m_lowerBound == other.m_lowerBound; }
        bool operator !=(this_type const &other) const { return !(*this == other); }

    private:
        UINT m_size;
        UINT m_lowerBound;
    };
        
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_ITYPEFWD_H

