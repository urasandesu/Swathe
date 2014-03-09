/* 
 * File: Signature.h
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
#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#define URASANDESU_SWATHE_METADATA_SIGNATURE_H

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYFWD_H
#include <Urasandesu/Swathe/Metadata/IPropertyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALFWD_H
#include <Urasandesu/Swathe/Metadata/ILocalFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATUREFWD_H
#include <Urasandesu/Swathe/Metadata/SignatureFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 
    
    namespace SignatureDetail {
    
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::SimpleBlob;
    
        class SignatureImpl
        {
        public:
            SignatureImpl();
            ~SignatureImpl();

            void Encode(IType const *pType);
            void Encode(IMethod const *pMethod);
            void Encode(IProperty const *pProp);
            void Encode(IField const *pField);
            void Encode(IMethodBody const *pBody);
            void Encode(ICustomAttribute const *pCa);

            void Decode(IType const *pType, TypeKinds &kind, IType const *&pDeclaringType, vector<IType const *> &genericArgs) const;
            void Decode(IMethod const *pMethod, CallingConventions &callingConvention, vector<IType const *> &genericArgs, IType const *&pRetType, vector<IParameter const *> &params) const;
            void Decode(IMethod const *pMethod, CallingConventions &callingConvention, IType const *&pRetType, vector<IParameter const *> &params) const;
            void Decode(IMethod const *pMethod, CallingConventions &callingConvention, vector<IType const *> &genericArgs) const;
            void Decode(IMethodBody const *pBody, CallingConventions &callingConvention, vector<ILocal const *> &locals) const;
            void Decode(IProperty const *pProp, CallingConventions &callingConvention, IType const *&pPropType, vector<IParameter const *> &params) const;
            void Decode(ICustomAttribute const *pCa, vector<CustomAttributeArgument> &constructorArgs, vector<IProperty const *> &namedProps, vector<CustomAttributeArgument> &propValues, vector<IField const *> &namedFields, vector<CustomAttributeArgument> &fieldValues) const;
            
            void SetBlob(PCCOR_SIGNATURE pSig, ULONG sigLength);
            vector<COR_SIGNATURE> const &GetBlob() const;
        
        private:
            SignatureImplPimpl *Pimpl();
            SignatureImplPimpl const *Pimpl() const;
#ifdef _DEBUG
            static INT const PIMPL_TYPE_SIZE = 128;
#else
            static INT const PIMPL_TYPE_SIZE = 16;
#endif
            typedef boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
            storage_type m_storage;
        };

    }   // namespace SignatureDetail {

    struct Signature : 
        SignatureDetail::SignatureImpl
    {
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_SIGNATURE_H

