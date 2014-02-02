/* 
 * File: BaseCustomAttributeMetadataPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_CUSTOMATTRIBUTEMETADATAPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/CustomAttributeMetadataPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseCustomAttributeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using std::vector;
    
    template<
        class ApiHolder
    >    
    class BaseCustomAttributeMetadataPimpl
    {
    public:
        SWATHE_BEGIN_CUSTOM_ATTRIBUTE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_CUSTOM_ATTRIBUTE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_CUSTOM_ATTRIBUTE_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseCustomAttributeMetadataPimpl(custom_attribute_metadata_label_type *pClass);

        void Initialize(assembly_metadata_label_type *pAsm);
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
        
    private:
        void SetToken(mdToken mdt);
        void SetMember(CustomAttributeProvider const &member);
        static void FillCustomAttributeProperties(IMetaDataImport2 *pComMetaImp, mdToken mdtTarget, Signature &sig, mdToken &mdtOwner, mdToken &mdtCtor);
        static void FillCustomAttributeConstructor(ICustomAttribute const *pCa, mdToken mdtTarget, IMethod const *&pCtor);

        mutable custom_attribute_metadata_label_type *m_pClass;
        assembly_metadata_label_type *m_pAsm;
        mutable CustomAttributeProvider m_member;
        mdToken m_mdt;
        mutable mdToken m_mdtOwner;
        mutable mdToken m_mdtCtor;
        mutable Signature m_sig;
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
        mutable IType const *m_pAttrType;
        
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASECUSTOMATTRIBUTEMETADATAPIMPL_H

