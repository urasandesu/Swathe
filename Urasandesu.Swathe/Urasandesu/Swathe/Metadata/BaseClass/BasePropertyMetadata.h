/* 
 * File: BasePropertyMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PROPERTYMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/PropertyMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
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

#ifndef URASANDESU_SWATHE_METADATA_IMODULEFWD_H
#include <Urasandesu/Swathe/Metadata/IModuleFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BasePropertyMetadata : 
        public IProperty
    {
    public:
        SWATHE_BEGIN_PROPERTY_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PROPERTY_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PROPERTY_METADATA_FACADE_TYPEDEF_ALIAS
        
        BasePropertyMetadata();
        ~BasePropertyMetadata();
    
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
        property_metadata_pimpl_label_type *Pimpl();
        property_metadata_pimpl_label_type const *Pimpl() const;
        void SetToken(mdProperty mdp);
        void SetName(wstring const &name);
        void SetCallingConvention(CallingConventions const &callingConvention);
        void SetPropertyType(IType const *pPropType);
        void SetMember(PropertyProvider const &member);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
#ifdef _M_IX86
        static INT const PIMPL_TYPE_SIZE = 120;
#else
        static INT const PIMPL_TYPE_SIZE = 184;
#endif
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYMETADATA_H

