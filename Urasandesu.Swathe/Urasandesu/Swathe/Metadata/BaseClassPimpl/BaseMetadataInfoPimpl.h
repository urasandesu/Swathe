/* 
 * File: BaseMetadataInfoPimpl.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METADATAINFOPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplFacade/MetadataInfoPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMetadataInfoPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using boost::unordered_set;
    using Urasandesu::CppAnonym::Utilities::TempPtr;

    template<
        class ApiHolder
    >    
    class BaseMetadataInfoPimpl
    {
    public:
        SWATHE_BEGIN_METADATA_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METADATA_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METADATA_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseMetadataInfoPimpl(metadata_info_label_type *pClass);
        ~BaseMetadataInfoPimpl();

        void Initialize(runtime_host_label_type *pRuntime);
        metadata_dispenser_label_type *CreateDispenser() const;
        void UnloadDispenser(metadata_dispenser_label_type *pDisp) const;
        runtime_host_label_type const *GetRuntime() const;
        
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        TempPtr<metadata_dispenser_label_type> NewDispenser() const;
        void RegisterDispenser(TempPtr<metadata_dispenser_label_type> &pDisp);

        TempPtr<assembly_metadata_label_type> NewAssemblyCore(metadata_dispenser_label_type *pDisp) const;
        void RegisterAssemblyCore(TempPtr<assembly_metadata_label_type> &pAsm);
        void UnloadAssemblyCore(assembly_metadata_label_type *pAsm);

        TempPtr<module_metadata_label_type> NewModuleCore(assembly_metadata_label_type *pAsm) const;
        void RegisterModuleCore(TempPtr<module_metadata_label_type> &pMod);
        void UnloadModuleCore(module_metadata_label_type *pMod);

        TempPtr<type_metadata_label_type> NewTypeCore(assembly_metadata_label_type *pAsm) const;
        void RegisterTypeCore(TempPtr<type_metadata_label_type> &pType);
        void UnloadTypeCore(type_metadata_label_type *pType);

        TempPtr<method_metadata_label_type> NewMethodCore(assembly_metadata_label_type *pAsm) const;
        void RegisterMethodCore(TempPtr<method_metadata_label_type> &pMethod);
        void UnloadMethodCore(method_metadata_label_type *pMethod);

        TempPtr<method_body_metadata_label_type> NewMethodBodyCore(assembly_metadata_label_type *pAsm) const;
        void RegisterMethodBodyCore(TempPtr<method_body_metadata_label_type> &pBody);
        void UnloadMethodBodyCore(method_body_metadata_label_type *pBody);

        TempPtr<parameter_metadata_label_type> NewParameterCore(assembly_metadata_label_type *pAsm) const;
        void RegisterParameterCore(TempPtr<parameter_metadata_label_type> &pParam);
        void UnloadParameterCore(parameter_metadata_label_type *pParam);

        TempPtr<local_metadata_label_type> NewLocalCore(assembly_metadata_label_type *pAsm) const;
        void RegisterLocalCore(TempPtr<local_metadata_label_type> &pLocal);
        void UnloadLocalCore(local_metadata_label_type *pLocal);

        TempPtr<property_metadata_label_type> NewPropertyCore(assembly_metadata_label_type *pAsm) const;
        void RegisterPropertyCore(TempPtr<property_metadata_label_type> &pProp);
        void UnloadPropertyCore(property_metadata_label_type *pProp);

        TempPtr<field_metadata_label_type> NewFieldCore(assembly_metadata_label_type *pAsm) const;
        void RegisterFieldCore(TempPtr<field_metadata_label_type> &pField);
        void UnloadFieldCore(field_metadata_label_type *pField);

        TempPtr<custom_attribute_metadata_label_type> NewCustomAttributeCore(assembly_metadata_label_type *pAsm) const;
        void RegisterCustomAttributeCore(TempPtr<custom_attribute_metadata_label_type> &pCa);
        void UnloadCustomAttributeCore(custom_attribute_metadata_label_type *pCa);

        TempPtr<assembly_generator_label_type> NewAssemblyGeneratorCore(metadata_dispenser_label_type *pDisp) const;
        void RegisterAssemblyGeneratorCore(TempPtr<assembly_generator_label_type> &pAsmGen);
        void UnloadAssemblyGeneratorCore(assembly_generator_label_type *pAsmGen);

        TempPtr<module_generator_label_type> NewModuleGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterModuleGeneratorCore(TempPtr<module_generator_label_type> &pModGen);
        void UnloadModuleGeneratorCore(module_generator_label_type *pModGen);

        TempPtr<type_generator_label_type> NewTypeGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterTypeGeneratorCore(TempPtr<type_generator_label_type> &pTypeGen);
        void UnloadTypeGeneratorCore(type_generator_label_type *pTypeGen);

        TempPtr<method_generator_label_type> NewMethodGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterMethodGeneratorCore(TempPtr<method_generator_label_type> &pMethodGen);
        void UnloadMethodGeneratorCore(method_generator_label_type *pMethodGen);

        TempPtr<parameter_generator_label_type> NewParameterGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterParameterGeneratorCore(TempPtr<parameter_generator_label_type> &pParamGen);
        void UnloadParameterGeneratorCore(parameter_generator_label_type *pParamGen);

        TempPtr<property_generator_label_type> NewPropertyGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterPropertyGeneratorCore(TempPtr<property_generator_label_type> &pPropGen);
        void UnloadPropertyGeneratorCore(property_generator_label_type *pPropGen);

        TempPtr<field_generator_label_type> NewFieldGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterFieldGeneratorCore(TempPtr<field_generator_label_type> &pFieldGen);
        void UnloadFieldGeneratorCore(field_generator_label_type *pFieldGen);

        TempPtr<method_body_generator_label_type> NewMethodBodyGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterMethodBodyGeneratorCore(TempPtr<method_body_generator_label_type> &pBodyGen);
        void UnloadMethodBodyGeneratorCore(method_body_generator_label_type *pBodyGen);

        TempPtr<local_generator_label_type> NewLocalGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterLocalGeneratorCore(TempPtr<local_generator_label_type> &pLocalGen);
        void UnloadLocalGeneratorCore(local_generator_label_type *pLocalGen);

        TempPtr<custom_attribute_generator_label_type> NewCustomAttributeGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        void RegisterCustomAttributeGeneratorCore(TempPtr<custom_attribute_generator_label_type> &pCaGen);
        void UnloadCustomAttributeGeneratorCore(custom_attribute_generator_label_type *pCaGen);

#ifdef _DEBUG
#ifdef _M_IX86
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 1024;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 2048;
#endif
#else
#ifdef _M_IX86
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 672;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 1344;
#endif
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable metadata_info_label_type *m_pClass;
        runtime_host_label_type *m_pRuntime;
        mutable unordered_set<metadata_dispenser_label_type *> m_disps;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_H

