/* 
 * File: BasePropertyGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/PropertyGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETERFWD_H
#include <Urasandesu/Swathe/Metadata/IParameterFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BasePropertyGenerator : 
        public IProperty
    {
    public:
        SWATHE_BEGIN_PROPERTY_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROPERTY_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROPERTY_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BasePropertyGenerator();
        ~BasePropertyGenerator();

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
        void SetSetMethod(IMethod const *pGetMethod);
        parameter_generator_label_type *DefineParameter(ULONG position, IType const *pParamType);
    
    private:
        property_generator_pimpl_label_type *Pimpl();
        property_generator_pimpl_label_type const *Pimpl() const;
        void SetName(wstring const &name);
        void SetPropertyType(IType const *pPropType);
        void SetParameters(vector<IParameter const *> const &params);
        void SetAttributes(PropertyAttributes const &attr);
        void SetSourceProperty(IProperty const *pSrcProp);
        void SetMember(PropertyProvider const &member);
        void Accept(IMetadataVisitor *pVisitor) const;
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 120;
#else
        static INT const PIMPL_TYPE_SIZE = 208;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_H

