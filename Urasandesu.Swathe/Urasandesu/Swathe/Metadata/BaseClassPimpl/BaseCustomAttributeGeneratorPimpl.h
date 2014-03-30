/* 
 * File: BaseCustomAttributeGeneratorPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_CUSTOMATTRIBUTEGENERATORPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/CustomAttributeGeneratorPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseCustomAttributeGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::blank;
    using boost::static_visitor;
    using boost::variant;
    using std::vector;

    template<
        class ApiHolder
    >    
    class BaseCustomAttributeGeneratorPimpl
    {
    public:
        SWATHE_BEGIN_CUSTOM_ATTRIBUTE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_CUSTOM_ATTRIBUTE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_CUSTOM_ATTRIBUTE_GENERATOR_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseCustomAttributeGeneratorPimpl(custom_attribute_generator_label_type *pClass);

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        Signature const &GetSignature() const;
        IMethod const *GetConstructor() const;
        vector<CustomAttributeArgument> const &GetConstructorArguments() const;
        vector<IProperty const *> const &GetNamedProperties() const;
        vector<CustomAttributeArgument> const &GetPropertyValues() const;
        vector<IField const *> const &GetNamedFields() const;
        vector<CustomAttributeArgument> const &GetFieldValues() const;
        CustomAttributeProvider const &GetMember() const;
        IAssembly const *GetAssembly() const;
        IType const *GetAttributeType() const;
        ICustomAttribute const *GetSourceCustomAttribute() const;
        bool Equals(IType const *pAttributeType) const;
        
    private:
        struct get_token_visitor;
        struct assign_member_visitor;
        struct resolve_argument_visitor;
        void SetConstructor(IMethod const *pCtor);
        void SetConstructorArguments(vector<CustomAttributeArgument> const &constructorArgs);
        void SetNamedProperties(vector<IProperty const *> const &namedProperties);
        void SetPropertyValues(vector<CustomAttributeArgument> const &propertyValues);
        mdToken GetTargetToken() const;
        void SetMember(CustomAttributeProvider const &member);
        void Accept(IMetadataVisitor *pVisitor) const;

        mutable custom_attribute_generator_label_type *m_pClass;
        mutable assembly_generator_label_type *m_pAsmGen;
        mutable mdToken m_mdt;
        mutable mdToken m_mdtTarget;
        mutable bool m_ctorInit;
        mutable IMethod const *m_pCtor;
        mutable bool m_constructorArgsInit;
        mutable vector<CustomAttributeArgument> m_constructorArgs;
        mutable bool m_namedPropsInit;
        mutable vector<IProperty const *> m_namedProps;
        mutable bool m_propValuesInit;
        mutable vector<CustomAttributeArgument> m_propValues;
        mutable bool m_namedFieldsInit;
        mutable vector<IField const *> m_namedFields;
        mutable bool m_fieldValuesInit;
        mutable vector<CustomAttributeArgument> m_fieldValues;
        mutable Signature m_sig;
        mutable CustomAttributeProvider m_member;
        ICustomAttribute const *m_pSrcCas;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEGENERATORPIMPL_H

