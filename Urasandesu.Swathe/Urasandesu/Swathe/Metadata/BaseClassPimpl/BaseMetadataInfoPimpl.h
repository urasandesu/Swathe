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
    using boost::unordered_map;
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

        metadata_dispenser_label_type *CreateDispenser() const;
        void UnloadDispenser(metadata_dispenser_label_type *pDisp) const;
        runtime_host_label_type const *GetRuntime() const;
        
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        void Initialize(runtime_host_label_type const *pRuntime);
        TempPtr<metadata_dispenser_label_type> NewDispenser() const;
        void RegisterDispenser(TempPtr<metadata_dispenser_label_type> &pDisp);

        TempPtr<assembly_metadata_label_type> NewAssemblyCore(metadata_dispenser_label_type *pDisp) const;
        assembly_metadata_label_type *GetAssemblyCore(SIZE_T index) const;
        SIZE_T RegisterAssemblyCore(TempPtr<assembly_metadata_label_type> &pAsm);

        TempPtr<module_metadata_label_type> NewModuleCore(assembly_metadata_label_type *pAsm) const;
        module_metadata_label_type *GetModuleCore(SIZE_T index) const;
        SIZE_T RegisterModuleCore(TempPtr<module_metadata_label_type> &pMod);

        TempPtr<type_metadata_label_type> NewTypeCore(assembly_metadata_label_type *pAsm) const;
        type_metadata_label_type *GetTypeCore(SIZE_T index) const;
        SIZE_T RegisterTypeCore(TempPtr<type_metadata_label_type> &pType);

        TempPtr<method_metadata_label_type> NewMethodCore(assembly_metadata_label_type *pAsm) const;
        method_metadata_label_type *GetMethodCore(SIZE_T index) const;
        SIZE_T RegisterMethodCore(TempPtr<method_metadata_label_type> &pMethod);

        TempPtr<method_body_metadata_label_type> NewMethodBodyCore(assembly_metadata_label_type *pAsm) const;
        method_body_metadata_label_type *GetMethodBodyCore(SIZE_T index) const;
        SIZE_T RegisterMethodBodyCore(TempPtr<method_body_metadata_label_type> &pBody);

        TempPtr<parameter_metadata_label_type> NewParameterCore(assembly_metadata_label_type *pAsm) const;
        parameter_metadata_label_type *GetParameterCore(SIZE_T index) const;
        SIZE_T RegisterParameterCore(TempPtr<parameter_metadata_label_type> &pParam);

        TempPtr<local_metadata_label_type> NewLocalCore(assembly_metadata_label_type *pAsm) const;
        local_metadata_label_type *GetLocalCore(SIZE_T index) const;
        SIZE_T RegisterLocalCore(TempPtr<local_metadata_label_type> &pLocal);

        TempPtr<property_metadata_label_type> NewPropertyCore(assembly_metadata_label_type *pAsm) const;
        property_metadata_label_type *GetPropertyCore(SIZE_T index) const;
        SIZE_T RegisterPropertyCore(TempPtr<property_metadata_label_type> &pProp);

        TempPtr<field_metadata_label_type> NewFieldCore(assembly_metadata_label_type *pAsm) const;
        field_metadata_label_type *GetFieldCore(SIZE_T index) const;
        SIZE_T RegisterFieldCore(TempPtr<field_metadata_label_type> &pField);

        TempPtr<custom_attribute_metadata_label_type> NewCustomAttributeCore(assembly_metadata_label_type *pAsm) const;
        custom_attribute_metadata_label_type *GetCustomAttributeCore(SIZE_T index) const;
        SIZE_T RegisterCustomAttributeCore(TempPtr<custom_attribute_metadata_label_type> &pCa);

        TempPtr<assembly_generator_label_type> NewAssemblyGeneratorCore(metadata_dispenser_label_type *pDisp) const;
        assembly_generator_label_type *GetAssemblyGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterAssemblyGeneratorCore(TempPtr<assembly_generator_label_type> &pAsmGen);

        TempPtr<module_generator_label_type> NewModuleGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        module_generator_label_type *GetModuleGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterModuleGeneratorCore(TempPtr<module_generator_label_type> &pModGen);

        TempPtr<type_generator_label_type> NewTypeGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        type_generator_label_type *GetTypeGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterTypeGeneratorCore(TempPtr<type_generator_label_type> &pTypeGen);

        TempPtr<method_generator_label_type> NewMethodGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        method_generator_label_type *GetMethodGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterMethodGeneratorCore(TempPtr<method_generator_label_type> &pMethodGen);

        TempPtr<parameter_generator_label_type> NewParameterGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        parameter_generator_label_type *GetParameterGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterParameterGeneratorCore(TempPtr<parameter_generator_label_type> &pParamGen);

        TempPtr<property_generator_label_type> NewPropertyGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        property_generator_label_type *GetPropertyGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterPropertyGeneratorCore(TempPtr<property_generator_label_type> &pPropGen);

        TempPtr<field_generator_label_type> NewFieldGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        field_generator_label_type *GetFieldGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterFieldGeneratorCore(TempPtr<field_generator_label_type> &pFieldGen);

        TempPtr<method_body_generator_label_type> NewMethodBodyGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        method_body_generator_label_type *GetMethodBodyGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterMethodBodyGeneratorCore(TempPtr<method_body_generator_label_type> &pBodyGen);

        TempPtr<local_generator_label_type> NewLocalGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        local_generator_label_type *GetLocalGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterLocalGeneratorCore(TempPtr<local_generator_label_type> &pLocalGen);

        TempPtr<custom_attribute_generator_label_type> NewCustomAttributeGeneratorCore(assembly_generator_label_type *pAsmGen) const;
        custom_attribute_generator_label_type *GetCustomAttributeGeneratorCore(SIZE_T index) const;
        SIZE_T RegisterCustomAttributeGeneratorCore(TempPtr<custom_attribute_generator_label_type> &pCaGen);

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
        runtime_host_label_type const *m_pRuntime;
        mutable unordered_map<metadata_dispenser_label_type *, SIZE_T> m_dispToIndex;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_H

