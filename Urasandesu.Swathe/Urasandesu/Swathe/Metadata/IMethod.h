/* 
 * File: IMethod.h
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
#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#define URASANDESU_SWATHE_METADATA_IMETHOD_H

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATUREFWD_H
#include <Urasandesu/Swathe/Metadata/SignatureFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 

    struct IMethod
    {
        IMethod() { }
        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual CallingConventions GetCallingConvention() const = 0;
        virtual MethodAttributes GetAttribute() const = 0;
        virtual IType const *GetReturnType() const = 0;
        virtual std::vector<IParameter const *> const &GetParameters() const = 0;
        virtual IMethodBody const *GetMethodBody() const = 0;
        virtual ULONG GetCodeRVA() const = 0;
        virtual bool IsStatic() const = 0;
        virtual bool IsGenericMethod() const = 0;
        virtual bool IsGenericMethodDefinition() const = 0;
        virtual std::vector<IType const *> const &GetGenericArguments() const = 0;
        virtual Signature const &GetSignature() const = 0;
        virtual IMethod const *MakeGenericMethod(std::vector<IType const *> const &genericArgs) const = 0;
        virtual IAssembly const *GetAssembly() const = 0;
        virtual IType const *GetDeclaringType() const = 0;
        virtual IMethod const *GetDeclaringMethod() const = 0;
        virtual MethodProvider const &GetMember() const = 0;
        virtual IMethod const *GetSourceMethod() const = 0;
        virtual bool Equals(IMethod const *pMethod) const = 0;
        virtual ULONG GetHashCode() const = 0;
        virtual IParameter const *GetParameter(ULONG position, IType const *pParamType) const = 0;
        virtual void OutDebugInfo() const = 0;
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_IMETHOD_H

