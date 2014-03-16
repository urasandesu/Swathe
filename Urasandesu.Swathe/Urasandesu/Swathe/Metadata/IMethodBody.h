/* 
 * File: IMethodBody.h
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
#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODY_H
#define URASANDESU_SWATHE_METADATA_IMETHODBODY_H

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALFWD_H
#include <Urasandesu/Swathe/Metadata/ILocalFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTIONFWD_H
#include <Urasandesu/Swathe/Metadata/IInstructionFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_EXCEPTIONCLAUSE_H
#include <Urasandesu/Swathe/Metadata/ExceptionClause.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATUREFWD_H
#include <Urasandesu/Swathe/Metadata/SignatureFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 
    
    struct IMethodBody
    {
        IMethodBody() { };
        virtual mdToken GetToken() const = 0;
        virtual CallingConventions GetCallingConvention() const = 0;
        virtual std::vector<ILocal const *> const &GetLocals() const = 0;
        virtual IInstructionPtrRange GetInstructions() const = 0;
        virtual std::vector<ExceptionClause> const &GetExceptionClauses() const = 0;
        virtual Signature const &GetSignature() const = 0;
        virtual IMethod const *GetMethod() const = 0;
        virtual COR_ILMETHOD_FAT const &GetRawHeader() const = 0;
        virtual std::vector<BYTE> const &GetRawBody() const = 0;
        virtual UINT GetRawBodyMaxStack() const = 0;
        virtual std::vector<COR_ILMETHOD_SECT_EH_CLAUSE_FAT> const &GetRawEHClauses() const = 0;
        virtual IAssembly const *GetAssembly() const = 0;
        virtual IMethodBody const *GetSourceMethodBody() const = 0;
        virtual bool Equals(IMethodBody const *pBody) const = 0;
        virtual size_t GetHashCode() const = 0;
        virtual ILocal const *GetLocal(ULONG index, IType const *pLocalType) const = 0;
        virtual IInstructionPtrRange::iterator GetInstructionIterator(ULONG offset) const = 0;
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_IMETHODBODY_H

