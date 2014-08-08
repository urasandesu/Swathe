/* 
 * File: BaseLocalGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_LOCALGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/LocalGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseLocalGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATUREFWD_H
#include <Urasandesu/Swathe/Metadata/SignatureFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODYFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodBodyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCALFWD_H
#include <Urasandesu/Swathe/Metadata/ILocalFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<
        class ApiHolder
    >    
    class BaseLocalGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_LOCAL_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_LOCAL_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_LOCAL_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseLocalGeneratorPimpl(local_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        SIZE_T GetLocalIndex() const;
        IType const *GetLocalType() const;
        Signature const &GetSignature() const;
        IMethodBody const *GetMethodBody() const;
        IAssembly const *GetAssembly() const;
        ILocal const *GetSourceLocal() const;
        bool Equals(ILocal const *pLocal) const;
        size_t GetHashCode() const;
        
    private:
        void SetLocalIndex(SIZE_T index);
        void SetLocalType(IType const *pLocalType);
        void SetMethodBody(IMethodBody const *pBody);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable local_generator_label_type *m_pClass;
        assembly_generator_label_type *m_pAsmGen;
        IMethodBody const *m_pBody;
        mutable mdToken m_mdt;
        SIZE_T m_index;
        mutable bool m_localTypeInit;
        mutable IType const *m_pLocalType;
        ILocal const *m_pSrcLocal;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASELOCALGENERATORPIMPL_H

