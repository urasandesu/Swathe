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
    void BaseMetadataInfo<ApiHolder>::Initialize(runtime_host_label_type *pRuntime)
    {
        Pimpl()->Initialize(pRuntime);
    }
    
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
    void BaseMetadataInfo<ApiHolder>::RegisterAssemblyCore(TempPtr<assembly_metadata_label_type> &pAsm)
    {
        Pimpl()->RegisterAssemblyCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadAssemblyCore(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->UnloadAssemblyCore(pAsm);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::module_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewModuleCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewModuleCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterModuleCore(TempPtr<module_metadata_label_type> &pMod)
    {
        Pimpl()->RegisterModuleCore(pMod);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadModuleCore(module_metadata_label_type *pMod)
    {
        Pimpl()->UnloadModuleCore(pMod);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::type_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewTypeCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewTypeCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterTypeCore(TempPtr<type_metadata_label_type> &pType)
    {
        Pimpl()->RegisterTypeCore(pType);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadTypeCore(type_metadata_label_type *pType)
    {
        Pimpl()->UnloadTypeCore(pType);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewMethodCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewMethodCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterMethodCore(TempPtr<method_metadata_label_type> &pMethod)
    {
        Pimpl()->RegisterMethodCore(pMethod);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadMethodCore(method_metadata_label_type *pMethod)
    {
        Pimpl()->UnloadMethodCore(pMethod);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_body_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewMethodBodyCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewMethodBodyCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterMethodBodyCore(TempPtr<method_body_metadata_label_type> &pBody)
    {
        Pimpl()->RegisterMethodBodyCore(pBody);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadMethodBodyCore(method_body_metadata_label_type *pBody)
    {
        Pimpl()->UnloadMethodBodyCore(pBody);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::parameter_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewParameterCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewParameterCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterParameterCore(TempPtr<parameter_metadata_label_type> &pParam)
    {
        Pimpl()->RegisterParameterCore(pParam);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadParameterCore(parameter_metadata_label_type *pParam)
    {
        Pimpl()->UnloadParameterCore(pParam);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::local_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewLocalCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewLocalCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterLocalCore(TempPtr<local_metadata_label_type> &pLocal)
    {
        Pimpl()->RegisterLocalCore(pLocal);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadLocalCore(local_metadata_label_type *pLocal)
    {
        Pimpl()->UnloadLocalCore(pLocal);
    }
    
    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::property_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewPropertyCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewPropertyCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterPropertyCore(TempPtr<property_metadata_label_type> &pProp)
    {
        Pimpl()->RegisterPropertyCore(pProp);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadPropertyCore(property_metadata_label_type *pProp)
    {
        Pimpl()->UnloadPropertyCore(pProp);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::field_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewFieldCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewFieldCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterFieldCore(TempPtr<field_metadata_label_type> &pField)
    {
        Pimpl()->RegisterFieldCore(pField);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadFieldCore(field_metadata_label_type *pField)
    {
        Pimpl()->UnloadFieldCore(pField);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::custom_attribute_metadata_label_type> BaseMetadataInfo<ApiHolder>::NewCustomAttributeCore(assembly_metadata_label_type *pAsm) const
    {
        return Pimpl()->NewCustomAttributeCore(pAsm);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterCustomAttributeCore(TempPtr<custom_attribute_metadata_label_type> &pCa)
    {
        Pimpl()->RegisterCustomAttributeCore(pCa);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadCustomAttributeCore(custom_attribute_metadata_label_type *pCa)
    {
        Pimpl()->UnloadCustomAttributeCore(pCa);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::assembly_generator_label_type> BaseMetadataInfo<ApiHolder>::NewAssemblyGeneratorCore(metadata_dispenser_label_type *pDisp) const
    {
        return Pimpl()->NewAssemblyGeneratorCore(pDisp);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterAssemblyGeneratorCore(TempPtr<assembly_generator_label_type> &pAsmGen)
    {
        Pimpl()->RegisterAssemblyGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadAssemblyGeneratorCore(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->UnloadAssemblyGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::module_generator_label_type> BaseMetadataInfo<ApiHolder>::NewModuleGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewModuleGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterModuleGeneratorCore(TempPtr<module_generator_label_type> &pModGen)
    {
        Pimpl()->RegisterModuleGeneratorCore(pModGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadModuleGeneratorCore(module_generator_label_type *pModGen)
    {
        Pimpl()->UnloadModuleGeneratorCore(pModGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::type_generator_label_type> BaseMetadataInfo<ApiHolder>::NewTypeGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewTypeGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterTypeGeneratorCore(TempPtr<type_generator_label_type> &pTypeGen)
    {
        Pimpl()->RegisterTypeGeneratorCore(pTypeGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadTypeGeneratorCore(type_generator_label_type *pTypeGen)
    {
        Pimpl()->UnloadTypeGeneratorCore(pTypeGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_generator_label_type> BaseMetadataInfo<ApiHolder>::NewMethodGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewMethodGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterMethodGeneratorCore(TempPtr<method_generator_label_type> &pMethodGen)
    {
        Pimpl()->RegisterMethodGeneratorCore(pMethodGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadMethodGeneratorCore(method_generator_label_type *pMethodGen)
    {
        Pimpl()->UnloadMethodGeneratorCore(pMethodGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::parameter_generator_label_type> BaseMetadataInfo<ApiHolder>::NewParameterGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewParameterGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterParameterGeneratorCore(TempPtr<parameter_generator_label_type> &pParamGen)
    {
        Pimpl()->RegisterParameterGeneratorCore(pParamGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadParameterGeneratorCore(parameter_generator_label_type *pParamGen)
    {
        Pimpl()->UnloadParameterGeneratorCore(pParamGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::property_generator_label_type> BaseMetadataInfo<ApiHolder>::NewPropertyGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewPropertyGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterPropertyGeneratorCore(TempPtr<property_generator_label_type> &pPropGen)
    {
        Pimpl()->RegisterPropertyGeneratorCore(pPropGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadPropertyGeneratorCore(property_generator_label_type *pPropGen)
    {
        Pimpl()->UnloadPropertyGeneratorCore(pPropGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::field_generator_label_type> BaseMetadataInfo<ApiHolder>::NewFieldGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewFieldGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterFieldGeneratorCore(TempPtr<field_generator_label_type> &pFieldGen)
    {
        Pimpl()->RegisterFieldGeneratorCore(pFieldGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadFieldGeneratorCore(field_generator_label_type *pFieldGen)
    {
        Pimpl()->UnloadFieldGeneratorCore(pFieldGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::method_body_generator_label_type> BaseMetadataInfo<ApiHolder>::NewMethodBodyGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewMethodBodyGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterMethodBodyGeneratorCore(TempPtr<method_body_generator_label_type> &pBodyGen)
    {
        Pimpl()->RegisterMethodBodyGeneratorCore(pBodyGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadMethodBodyGeneratorCore(method_body_generator_label_type *pBodyGen)
    {
        Pimpl()->UnloadMethodBodyGeneratorCore(pBodyGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::local_generator_label_type> BaseMetadataInfo<ApiHolder>::NewLocalGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewLocalGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterLocalGeneratorCore(TempPtr<local_generator_label_type> &pLocalGen)
    {
        Pimpl()->RegisterLocalGeneratorCore(pLocalGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadLocalGeneratorCore(local_generator_label_type *pLocalGen)
    {
        Pimpl()->UnloadLocalGeneratorCore(pLocalGen);
    }

    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfo<ApiHolder>::custom_attribute_generator_label_type> BaseMetadataInfo<ApiHolder>::NewCustomAttributeGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        return Pimpl()->NewCustomAttributeGeneratorCore(pAsmGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::RegisterCustomAttributeGeneratorCore(TempPtr<custom_attribute_generator_label_type> &pCaGen)
    {
        Pimpl()->RegisterCustomAttributeGeneratorCore(pCaGen);
    }

    template<class ApiHolder>    
    void BaseMetadataInfo<ApiHolder>::UnloadCustomAttributeGeneratorCore(custom_attribute_generator_label_type *pCaGen)
    {
        Pimpl()->UnloadCustomAttributeGeneratorCore(pCaGen);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_HPP

