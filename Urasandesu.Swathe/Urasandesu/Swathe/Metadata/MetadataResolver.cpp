/* 
 * File: MetadataResolver.cpp
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

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSER_H
#include <Urasandesu/Swathe/Metadata/IDispenser.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELD_H
#include <Urasandesu/Swathe/Metadata/IField.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODY_H
#include <Urasandesu/Swathe/Metadata/IMethodBody.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCAL_H
#include <Urasandesu/Swathe/Metadata/ILocal.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IINSTRUCTION_H
#include <Urasandesu/Swathe/Metadata/IInstruction.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATARESOLVER_H
#include <Urasandesu/Swathe/Metadata/MetadataResolver.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace MetadataResolverDetail {

        using boost::blank;
        using boost::apply_visitor;
        using boost::static_visitor;

        IDispenser const *MetadataResolverImpl::Resolve(IDispenser const *pDisp)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

        
        
        IAssembly const *MetadataResolverImpl::Resolve(IAssembly const *pAsm)
        {
            if (!pAsm)
                return nullptr;
            else if (auto const *pDisp = pAsm->GetDispenser())
                return pDisp->ResolveAssembly(pAsm);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        IModule const *MetadataResolverImpl::Resolve(IModule const *pMod)
        {
            if (!pMod)
                return nullptr;
            else if (auto const *pAsm = Resolve(pMod->GetAssembly()))
                return pAsm->ResolveModule(pMod);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        IType const *MetadataResolverImpl::Resolve(IType const *pType)
        {
            if (!pType)
                return nullptr;

            auto kind = pType->GetKind();

            if (!pType)
                return nullptr;
            else if (auto const *pDeclaringType = Resolve(pType->GetDeclaringType()))
                return pDeclaringType->ResolveType(pType);
            else if (auto const *pDeclaringMethod = Resolve(pType->GetDeclaringMethod()))
                return pDeclaringMethod->ResolveType(pType);
            else if (auto const *pMod = Resolve(pType->GetModule()))
                return pMod->ResolveType(pType);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        IField const *MetadataResolverImpl::Resolve(IField const *pField)
        {
            if (!pField)
                return nullptr;
            else if (auto const *pType = Resolve(pField->GetDeclaringType()))
                return pType->ResolveField(pField);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        IProperty const *MetadataResolverImpl::Resolve(IProperty const *pProp)
        {
            if (!pProp)
                return nullptr;
            else if (auto const *pType = Resolve(pProp->GetDeclaringType()))
                return pType->ResolveProperty(pProp);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        IMethod const *MetadataResolverImpl::Resolve(IMethod const *pMethod)
        {
            //if (pMethod)
            //{
            //    auto const *pType = pMethod->GetDeclaringType();
            //    if (!pType)
            //        D_WCOUT(L"Test Test");
            //}

            if (!pMethod)
                return nullptr;
            else if (auto const *pDeclaringMethod = Resolve(pMethod->GetDeclaringMethod()))
                return pDeclaringMethod->ResolveMethod(pMethod);
            else if (auto const *pDeclaringType = Resolve(pMethod->GetDeclaringType()))
                return pDeclaringType->ResolveMethod(pMethod);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        struct ResolveParameterMemberVisitor : 
            static_visitor<IParameter const *>
        {
            ResolveParameterMemberVisitor(IParameter const *pParam) : 
                m_pParam(pParam)
            { }

            template<class T>
            IParameter const *operator ()(T const &v) const;

            template<>
            IParameter const *operator ()<blank>(blank const &) const
            {
                return nullptr;
            }

            template<>
            IParameter const *operator ()<IMethod const *>(IMethod const *const &pMember) const
            {
                if (!pMember)
                    return nullptr;
                else if (auto const *pMethod = MetadataResolver::Resolve(pMember))
                    return pMethod->ResolveParameter(m_pParam);
                else
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }

            template<>
            IParameter const *operator ()<IProperty const *>(IProperty const * const &pProp) const
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }

            IParameter const *m_pParam;
        };

        IParameter const *MetadataResolverImpl::Resolve(IParameter const *pParam)
        {
            return apply_visitor(ResolveParameterMemberVisitor(pParam), pParam->GetMember());
        }



        IMethodBody const *MetadataResolverImpl::Resolve(IMethodBody const *pBody)
        {
            if (!pBody)
                return nullptr;
            else if (auto const *pMethod = Resolve(pBody->GetMethod()))
                return pMethod->ResolveMethodBody(pBody);
            else
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        ILocal const *MetadataResolverImpl::Resolve(ILocal const *pLocal)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        IInstruction const *MetadataResolverImpl::Resolve(IInstruction const *pInst)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }



        ICustomAttribute const *MetadataResolverImpl::Resolve(ICustomAttribute const *pCa)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }

    }   // namespace MetadataResolverDetail {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {
