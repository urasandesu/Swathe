/* 
 * File: BaseMetadataInfo.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataInfo.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseMetadataInfo<ApiHolder>::BaseMetadataInfo()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(metadata_info_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(metadata_info_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())metadata_info_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseMetadataInfo<ApiHolder>::~BaseMetadataInfo()
    {
        Pimpl()->~metadata_info_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::metadata_info_pimpl_label_type *BaseMetadataInfo<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<metadata_info_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::metadata_info_pimpl_label_type const *BaseMetadataInfo<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_METADATA_INFO_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::metadata_dispenser_label_type *BaseMetadataInfo<ApiHolder>::CreateDispenser() const
    {
        return Pimpl()->CreateDispenser();
    }
    
    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadDispenser(metadata_dispenser_label_type *pDisp) const
    {
        Pimpl()->UnloadDispenser(pDisp);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::runtime_host_label_type const *BaseMetadataInfo<ApiHolder>::GetRuntime() const
    {
        return Pimpl()->GetRuntime();
    }
    
    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::Initialize(runtime_host_label_type const *pRuntime)
    {
        Pimpl()->Initialize(pRuntime);
    }
    
    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterDispenser(TempPtr<metadata_dispenser_label_type> &pDisp)
    {
        Pimpl()->RegisterDispenser(pDisp);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::assembly_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewAssemblyCore(metadata_dispenser_label_type *pDisp) const
    {
        return Pimpl()->NewAssemblyCore(pDisp);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::assembly_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetAssemblyCore(SIZE_T index) const
    {
        return Pimpl()->GetAssemblyCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterAssemblyCore(TempPtr<assembly_metadata_label_type> &pAsm)
    {
        return Pimpl()->RegisterAssemblyCore(pAsm);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::module_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewModuleCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewModuleCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::module_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetModuleCore(SIZE_T index) const
    {
        return Pimpl()->GetModuleCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterModuleCore(TempPtr<module_metadata_label_type> &pMod)
    {
        return Pimpl()->RegisterModuleCore(pMod);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::type_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewTypeCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewTypeCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::type_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetTypeCore(SIZE_T index) const
    {
        return Pimpl()->GetTypeCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterTypeCore(TempPtr<type_metadata_label_type> &pType)
    {
        return Pimpl()->RegisterTypeCore(pType);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewMethodCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewMethodCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::method_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetMethodCore(SIZE_T index) const
    {
        return Pimpl()->GetMethodCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterMethodCore(TempPtr<method_metadata_label_type> &pMethod)
    {
        return Pimpl()->RegisterMethodCore(pMethod);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_body_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewMethodBodyCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewMethodBodyCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::method_body_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetMethodBodyCore(SIZE_T index) const
    {
        return Pimpl()->GetMethodBodyCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterMethodBodyCore(TempPtr<method_body_metadata_label_type> &pBody)
    {
        return Pimpl()->RegisterMethodBodyCore(pBody);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::parameter_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewParameterCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewParameterCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::parameter_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetParameterCore(SIZE_T index) const
    {
        return Pimpl()->GetParameterCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterParameterCore(TempPtr<parameter_metadata_label_type> &pParam)
    {
        return Pimpl()->RegisterParameterCore(pParam);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::local_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewLocalCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewLocalCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::local_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetLocalCore(SIZE_T index) const
    {
        return Pimpl()->GetLocalCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterLocalCore(TempPtr<local_metadata_label_type> &pLocal)
    {
        return Pimpl()->RegisterLocalCore(pLocal);
    }
    
    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::property_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewPropertyCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewPropertyCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::property_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetPropertyCore(SIZE_T index) const
    {
        return Pimpl()->GetPropertyCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterPropertyCore(TempPtr<property_metadata_label_type> &pProp)
    {
        return Pimpl()->RegisterPropertyCore(pProp);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::field_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewFieldCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewFieldCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::field_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetFieldCore(SIZE_T index) const
    {
        return Pimpl()->GetFieldCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterFieldCore(TempPtr<field_metadata_label_type> &pField)
    {
        return Pimpl()->RegisterFieldCore(pField);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::custom_attribute_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewCustomAttributeCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewCustomAttributeCore(pAsm);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::custom_attribute_metadata_label_type *BaseMetadataInfo<ApiHolder>::GetCustomAttributeCore(SIZE_T index) const
    {
        return Pimpl()->GetCustomAttributeCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterCustomAttributeCore(TempPtr<custom_attribute_metadata_label_type> &pCa)
    {
        return Pimpl()->RegisterCustomAttributeCore(pCa);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::assembly_generator_label_type> BaseMetadataInfo<ApiHolder>::NewAssemblyGeneratorCore(metadata_dispenser_label_type *pDisp) const
    {
        return Pimpl()->NewAssemblyGeneratorCore(pDisp);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::assembly_generator_label_type *BaseMetadataInfo<ApiHolder>::GetAssemblyGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetAssemblyGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterAssemblyGeneratorCore(TempPtr<assembly_generator_label_type> &pAsmGen)
    {
        return Pimpl()->RegisterAssemblyGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::module_generator_label_type> BaseMetadataInfo<ApiHolder>::NewModuleGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewModuleGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::module_generator_label_type *BaseMetadataInfo<ApiHolder>::GetModuleGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetModuleGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterModuleGeneratorCore(TempPtr<module_generator_label_type> &pModGen)
    {
        return Pimpl()->RegisterModuleGeneratorCore(pModGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::type_generator_label_type> BaseMetadataInfo<ApiHolder>::NewTypeGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewTypeGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::type_generator_label_type *BaseMetadataInfo<ApiHolder>::GetTypeGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetTypeGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterTypeGeneratorCore(TempPtr<type_generator_label_type> &pTypeGen)
    {
        return Pimpl()->RegisterTypeGeneratorCore(pTypeGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_generator_label_type> BaseMetadataInfo<ApiHolder>::NewMethodGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewMethodGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::method_generator_label_type *BaseMetadataInfo<ApiHolder>::GetMethodGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetMethodGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterMethodGeneratorCore(TempPtr<method_generator_label_type> &pMethodGen)
    {
        return Pimpl()->RegisterMethodGeneratorCore(pMethodGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::parameter_generator_label_type> BaseMetadataInfo<ApiHolder>::NewParameterGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewParameterGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::parameter_generator_label_type *BaseMetadataInfo<ApiHolder>::GetParameterGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetParameterGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterParameterGeneratorCore(TempPtr<parameter_generator_label_type> &pParamGen)
    {
        return Pimpl()->RegisterParameterGeneratorCore(pParamGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::property_generator_label_type> BaseMetadataInfo<ApiHolder>::NewPropertyGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewPropertyGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::property_generator_label_type *BaseMetadataInfo<ApiHolder>::GetPropertyGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetPropertyGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterPropertyGeneratorCore(TempPtr<property_generator_label_type> &pPropGen)
    {
        return Pimpl()->RegisterPropertyGeneratorCore(pPropGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::field_generator_label_type> BaseMetadataInfo<ApiHolder>::NewFieldGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewFieldGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::field_generator_label_type *BaseMetadataInfo<ApiHolder>::GetFieldGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetFieldGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterFieldGeneratorCore(TempPtr<field_generator_label_type> &pFieldGen)
    {
        return Pimpl()->RegisterFieldGeneratorCore(pFieldGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_body_generator_label_type> BaseMetadataInfo<ApiHolder>::NewMethodBodyGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewMethodBodyGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::method_body_generator_label_type *BaseMetadataInfo<ApiHolder>::GetMethodBodyGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetMethodBodyGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterMethodBodyGeneratorCore(TempPtr<method_body_generator_label_type> &pBodyGen)
    {
        return Pimpl()->RegisterMethodBodyGeneratorCore(pBodyGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::local_generator_label_type> BaseMetadataInfo<ApiHolder>::NewLocalGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewLocalGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::local_generator_label_type *BaseMetadataInfo<ApiHolder>::GetLocalGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetLocalGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterLocalGeneratorCore(TempPtr<local_generator_label_type> &pLocalGen)
    {
        return Pimpl()->RegisterLocalGeneratorCore(pLocalGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::custom_attribute_generator_label_type> BaseMetadataInfo<ApiHolder>::NewCustomAttributeGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewCustomAttributeGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfo<ApiHolder>::custom_attribute_generator_label_type *BaseMetadataInfo<ApiHolder>::GetCustomAttributeGeneratorCore(SIZE_T index) const
    {
        return Pimpl()->GetCustomAttributeGeneratorCore(index);
    }

    template<class ApiHolder>    
    SIZE_T BaseMetadataInfo<ApiHolder>::RegisterCustomAttributeGeneratorCore(TempPtr<custom_attribute_generator_label_type> &pCaGen)
    {
        return Pimpl()->RegisterCustomAttributeGeneratorCore(pCaGen);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_HPP

