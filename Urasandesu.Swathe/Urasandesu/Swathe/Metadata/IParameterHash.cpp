/* 
 * File: IParameterHash.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERHASH_H
#include <Urasandesu/Swathe/Metadata/IParameterHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace IParameterHashDetail {
        
        using boost::apply_visitor;
        using boost::blank;
        using boost::static_visitor;
        using Urasandesu::CppAnonym::Utilities::HashValue;

        struct ToPointerVisitor : 
            static_visitor<void const *>
        {
            template<class T>
            void const *operator ()(T const &p) const
            {
                return reinterpret_cast<void const *>(p);
            }

            template<>
            void const *operator ()<blank>(blank const &) const
            {
                return nullptr;
            }
        };

        IParameterHashImpl::result_type IParameterHashImpl::operator()(param_type v) const
        {
            return v->GetPosition() ^ HashValue(apply_visitor(ToPointerVisitor(), v->GetMember()));
        }

    }   // namespace IParameterHashDetail {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {
