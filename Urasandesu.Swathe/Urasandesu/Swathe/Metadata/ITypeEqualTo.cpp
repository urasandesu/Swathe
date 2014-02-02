/* 
 * File: ITypeEqualTo.cpp
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

#ifndef URASANDESU_SWATHE_METADATA_ITYPEEQUALTO_H
#include <Urasandesu/Swathe/Metadata/ITypeEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IAssemblyEqualTo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace ITypeEqualToDetail {

        using Urasandesu::CppAnonym::Collections::SequenceEqual;

        ITypeEqualToImpl::result_type ITypeEqualToImpl::operator()(param_type x, param_type y) const
        {
            if (!x && !y)
                return true;
            else if (!x || !y)
                return false;

            auto isXDefinition = !x->IsGenericType() || x->IsGenericTypeDefinition();
            auto isYDefinition = !y->IsGenericType() || y->IsGenericTypeDefinition();
            auto mdtTargetX = x->GetToken();
            auto mdtTargetY = y->GetToken();
            auto isByRefX = static_cast<INT>(x->IsByRef());
            auto isByRefY = static_cast<INT>(y->IsByRef());
            auto isArrayX = static_cast<INT>(x->IsArray());
            auto isArrayY = static_cast<INT>(y->IsArray());
            auto const *pAsmX = x->GetAssembly();
            auto const *pAsmY = y->GetAssembly();

            return (isXDefinition && isYDefinition) ? 
                        mdtTargetX == mdtTargetY && isByRefX == isByRefY && isArrayX == isArrayY && IAssemblyEqualTo()(pAsmX, pAsmY) : 
                        (isXDefinition || isYDefinition) ? 
                            false : 
                            (mdtTargetX == mdtTargetY && isByRefX == isByRefY && isArrayX == isArrayY && IAssemblyEqualTo()(pAsmX, pAsmY) && EqualTo(x->GetGenericArguments(), y->GetGenericArguments()));
        }

        ITypeEqualToImpl::result_type ITypeEqualToImpl::EqualTo(vector<IType const *> const &x, vector<IType const *> const &y)
        {
            return SequenceEqual(x.begin(), x.end(), y.begin(), y.end());
        }

    }   // namespace ITypeEqualToDetail {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {
