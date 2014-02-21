/* 
 * File: BaseCustomAttributeMetadata.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_CUSTOMATTRIBUTEMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/CustomAttributeMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseCustomAttributeMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::vector;

    template<
        class ApiHolder
    >    
    class BaseCustomAttributeMetadata : 
        public ICustomAttribute
    {
    public:
        SWATHE_BEGIN_CUSTOM_ATTRIBUTE_METADATA_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_CUSTOM_ATTRIBUTE_METADATA_FACADE_TYPEDEF_ALIAS
        SWATHE_END_CUSTOM_ATTRIBUTE_METADATA_FACADE_TYPEDEF_ALIAS
        
        BaseCustomAttributeMetadata();
        ~BaseCustomAttributeMetadata();

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
        ICustomAttribute const *GetSourceCustomAttribute() const;
    
    private:
        custom_attribute_metadata_pimpl_label_type *Pimpl();
        custom_attribute_metadata_pimpl_label_type const *Pimpl() const;
        void SetToken(mdToken mdt);
        void SetMember(CustomAttributeProvider const &member);

#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 136;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_H

