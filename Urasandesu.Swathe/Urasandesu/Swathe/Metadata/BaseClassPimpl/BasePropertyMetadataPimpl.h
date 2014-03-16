/* 
 * File: BasePropertyMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_PROPERTYMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/PropertyMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BasePropertyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BasePropertyMetadataPimpl
    {
    public:
        SWATHE_BEGIN_PROPERTY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROPERTY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROPERTY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BasePropertyMetadataPimpl(property_metadata_label_type *pClass);

        void Initialize(assembly_metadata_label_type *pAsm);
        mdProperty GetToken() const;
        wstring const &GetName() const;
        CallingConventions GetCallingConvention() const;
        IType const *GetPropertyType() const;
        vector<IParameter const *> const &GetParameters() const;
        PropertyAttributes GetAttribute() const;
        IMethod const *GetGetMethod() const;
        IMethod const *GetSetMethod() const;
        Signature const &GetSignature() const;
        IType const *GetDeclaringType() const;
        PropertyProvider const &GetMember() const;
        IProperty const *GetSourceProperty() const;
        bool Equals(IProperty const *pProp) const;
        size_t GetHashCode() const;
        IAssembly const *GetAssembly() const;
        IParameter const *GetParameter(ULONG position, IType const *pParamType) const;
        
    private:
        void SetToken(mdProperty mdp);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetPropertyType(IType const *pPropType);
        void SetMember(PropertyProvider const &member);
        static void FillPropertyDefProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, mdToken &mdtOwner, wstring &name, PropertyAttributes &attr, Signature &sig, mdMethodDef &mdmdSetter, mdMethodDef &mdmdGetter);
        static void FillPropertyDefMember(IProperty const *pProp, mdToken mdtOwner, mdMethodDef mdmdSetter, mdMethodDef mdmdGetter, MethodProvider &member, IMethod const *&pSetMethod, IMethod const *&pGetMethod);
        static void FillPropertySigProperties(IProperty const *pProp, Signature const &sig, CallingConventions &callingConvention, IType const *&pPropType, vector<IParameter const *> &params);

        mutable property_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        mutable PropertyProvider m_member;
        mutable mdProperty m_mdp;
        mutable mdToken m_mdtOwner;
        mutable mdMethodDef m_mdmdSetter;
        mutable mdMethodDef m_mdmdGetter;
        mutable wstring m_name;
        mutable CallingConventions m_callingConvention;
        mutable PropertyAttributes m_attr;
        mutable IType const *m_pPropType;
        mutable bool m_paramsInit;
        mutable vector<IParameter const *> m_params;
        mutable Signature m_sig;
        mutable IMethod const *m_pSetMethod;
        mutable IMethod const *m_pGetMethod;
        IProperty const *m_pSrcProp;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYMETADATAPIMPL_H

