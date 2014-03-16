/* 
 * File: BasePropertyGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_PROPERTYGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/PropertyGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BasePropertyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
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
    class BasePropertyGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_PROPERTY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROPERTY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROPERTY_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BasePropertyGeneratorPimpl(property_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
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
        void SetGetMethod(IMethod const *pGetMethod);
        void SetSetMethod(IMethod const *pSetMethod);
        parameter_generator_label_type *DefineParameter(ULONG position, IType const *pParamType);
        
    private:
        void SetName(wstring const &name);
        void SetPropertyType(IType const *pPropType);
        void SetParameters(vector<IParameter const *> const &params);
        void SetAttributes(PropertyAttributes const &attr);
        void SetSourceProperty(IProperty const *pSrcProp);
        void SetMember(PropertyProvider const &member);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable property_generator_label_type *m_pClass;
        mutable assembly_generator_label_type *m_pAsmGen;
        mutable bool m_declaringTypeInit;
        mutable PropertyProvider m_member;
        mutable mdToken m_mdt;
        mutable wstring m_name;
        mutable CallingConventions m_callingConvention;
        mutable IType const *m_pPropType;
        mutable bool m_propTypeInit;
        mutable bool m_paramsInit;
        mutable vector<IParameter const *> m_params;
        PropertyAttributes m_attr;
        mutable IMethod const *m_pGetMethod;
        mutable bool m_getMethodInit;
        mutable IMethod const *m_pSetMethod;
        mutable bool m_setMethodInit;
        mutable Signature m_sig;
        IProperty const *m_pSrcProp;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_H

