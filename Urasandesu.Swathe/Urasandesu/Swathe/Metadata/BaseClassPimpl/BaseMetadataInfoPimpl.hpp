/* 
 * File: BaseMetadataInfoPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseMetadataInfoPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseMetadataInfoPimpl<ApiHolder>::BaseMetadataInfoPimpl(metadata_info_label_type *pClass) : 
        m_pClass(pClass), 
        m_pRuntime(nullptr)
    { 
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(base_heap_provider_type), ==, sizeof(storage_type));
#endif
        new(BaseHeapProvider())base_heap_provider_type();
    }

    template<class ApiHolder>    
    BaseMetadataInfoPimpl<ApiHolder>::~BaseMetadataInfoPimpl()
    {
        if (!m_disps.empty())
        {
            auto *pBaseProvider = BaseHeapProvider();
            auto &provider = pBaseProvider->FirstProviderOf<metadata_dispenser_label_type>();
            BOOST_FOREACH (auto const &pDisp, m_disps)
                provider.DeleteObject(pDisp);
        }

        BaseHeapProvider()->~base_heap_provider_type();
    }

    template<class ApiHolder>    
    typename BaseMetadataInfoPimpl<ApiHolder>::base_heap_provider_type *BaseMetadataInfoPimpl<ApiHolder>::BaseHeapProvider()
    {
        return reinterpret_cast<base_heap_provider_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseMetadataInfoPimpl<ApiHolder>::base_heap_provider_type const *BaseMetadataInfoPimpl<ApiHolder>::BaseHeapProvider() const
    {
        return const_cast<class_pimpl_type *>(this)->BaseHeapProvider();
    }
    
#define SWATHE_DECLARE_BASE_METADATA_INFO_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::Initialize(runtime_host_label_type *pRuntime)
    {
        _ASSERTE(!m_pRuntime);
        _ASSERTE(pRuntime);
        m_pRuntime = pRuntime;
    }



    template<class ApiHolder>    
    typename BaseMetadataInfoPimpl<ApiHolder>::metadata_dispenser_label_type *BaseMetadataInfoPimpl<ApiHolder>::CreateDispenser() const
    {
        using ATL::CComPtr;
        using Urasandesu::CppAnonym::CppAnonymCOMException;
        
        auto pNewDisp = NewDispenser();
        
        auto &comRuntimeInfo = m_pRuntime->GetCOMRuntimeInfo();
        
        auto pComMetaDisp = CComPtr<IMetaDataDispenserEx>();
        auto hr = comRuntimeInfo.GetInterface(CLSID_CorMetaDataDispenser, IID_IMetaDataDispenserEx, reinterpret_cast<LPVOID *>(&pComMetaDisp));
        if (FAILED(hr)) 
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        pNewDisp->SetCOMMetaDataDispenser(&*pComMetaDisp);
        
        pNewDisp.Persist();
        return pNewDisp.Get();
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadDispenser(metadata_dispenser_label_type *pDisp) const
    {
        auto result = m_disps.find(pDisp);
        if (result == m_disps.end())
            return;

        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<metadata_dispenser_label_type>();
        provider.DeleteObject(*result);

        m_disps.erase(result);
    }



    template<class ApiHolder>    
    typename BaseMetadataInfoPimpl<ApiHolder>::runtime_host_label_type const *BaseMetadataInfoPimpl<ApiHolder>::GetRuntime() const
    {
        return m_pRuntime;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::metadata_dispenser_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewDispenser() const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<metadata_dispenser_label_type>();
        auto pDisp = provider.NewObject();
        auto const *pRuntime = m_pClass->GetRuntime();
        auto const *pFuInfo = pRuntime->GetInfo<fusion_info_label_type>();
        pDisp->Initialize(m_pClass, pFuInfo);
        auto handler = metadata_dispenser_persisted_handler_label_type(m_pClass);
        provider.AddPersistedHandler(pDisp, handler);
        return pDisp;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterDispenser(TempPtr<metadata_dispenser_label_type> &pDisp)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<metadata_dispenser_label_type>();
        provider.RegisterObject(pDisp);
        m_disps.insert(pDisp.Get());
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::assembly_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewAssemblyCore(metadata_dispenser_label_type *pDisp) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_metadata_label_type>();
        auto pAsm = provider.NewObject();
        auto const *pRuntime = m_pClass->GetRuntime();
        auto const *pPEInfo = pRuntime->GetInfo<portable_executable_info_label_type>();
        auto const *pSnInfo = pRuntime->GetInfo<strong_name_info_label_type>();
        pAsm->Initialize(m_pClass, pDisp, pPEInfo, pSnInfo);
        auto handler = assembly_metadata_persisted_handler_label_type(pDisp);
        provider.AddPersistedHandler(pAsm, handler);
        return pAsm;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterAssemblyCore(TempPtr<assembly_metadata_label_type> &pAsm)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_metadata_label_type>();
        provider.RegisterObject(pAsm);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadAssemblyCore(assembly_metadata_label_type *pAsm)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_metadata_label_type>();
        provider.DeleteObject(pAsm);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::module_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewModuleCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_metadata_label_type>();
        auto pMod = provider.NewObject();
        pMod->Initialize(pAsm);
        auto handler = module_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pMod, handler);
        return pMod;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterModuleCore(TempPtr<module_metadata_label_type> &pMod)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_metadata_label_type>();
        provider.RegisterObject(pMod);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadModuleCore(module_metadata_label_type *pMod)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_metadata_label_type>();
        provider.DeleteObject(pMod);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::type_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewTypeCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<type_metadata_label_type>();
        auto pType = provider.NewObject();
        pType->Initialize(pAsm);
        auto handler = type_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pType, handler);
        return pType;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterTypeCore(TempPtr<type_metadata_label_type> &pType)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<type_metadata_label_type>();
        provider.RegisterObject(pType);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadTypeCore(type_metadata_label_type *pType)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<type_metadata_label_type>();
        provider.DeleteObject(pType);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::method_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewMethodCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_metadata_label_type>();
        auto pMethod = provider.NewObject();
        pMethod->Initialize(pAsm);
        auto handler = method_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pMethod, handler);
        return pMethod;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterMethodCore(TempPtr<method_metadata_label_type> &pMethod)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_metadata_label_type>();
        provider.RegisterObject(pMethod);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadMethodCore(method_metadata_label_type *pMethod)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_metadata_label_type>();
        provider.DeleteObject(pMethod);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::method_body_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewMethodBodyCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_body_metadata_label_type>();
        auto pBody = provider.NewObject();
        pBody->Initialize(pAsm);
        auto handler = method_body_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pBody, handler);
        return pBody;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterMethodBodyCore(TempPtr<method_body_metadata_label_type> &pBody)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_body_metadata_label_type>();
        provider.RegisterObject(pBody);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadMethodBodyCore(method_body_metadata_label_type *pBody)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_body_metadata_label_type>();
        provider.DeleteObject(pBody);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::parameter_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewParameterCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<parameter_metadata_label_type>();
        auto pParam = provider.NewObject();
        pParam->Initialize(pAsm);
        auto handler = parameter_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pParam, handler);
        return pParam;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterParameterCore(TempPtr<parameter_metadata_label_type> &pParam)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<parameter_metadata_label_type>();
        provider.RegisterObject(pParam);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadParameterCore(parameter_metadata_label_type *pParam)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<parameter_metadata_label_type>();
        provider.DeleteObject(pParam);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::local_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewLocalCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<local_metadata_label_type>();
        auto pLocal = provider.NewObject();
        pLocal->Initialize(pAsm);
        auto handler = local_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pLocal, handler);
        return pLocal;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterLocalCore(TempPtr<local_metadata_label_type> &pLocal)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<local_metadata_label_type>();
        provider.RegisterObject(pLocal);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadLocalCore(local_metadata_label_type *pLocal)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<local_metadata_label_type>();
        provider.DeleteObject(pLocal);
    }


    
    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::property_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewPropertyCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<property_metadata_label_type>();
        auto pProp = provider.NewObject();
        pProp->Initialize(pAsm);
        auto handler = property_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pProp, handler);
        return pProp;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterPropertyCore(TempPtr<property_metadata_label_type> &pProp)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<property_metadata_label_type>();
        provider.RegisterObject(pProp);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadPropertyCore(property_metadata_label_type *pProp)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<property_metadata_label_type>();
        provider.DeleteObject(pProp);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::field_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewFieldCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<field_metadata_label_type>();
        auto pField = provider.NewObject();
        pField->Initialize(pAsm);
        auto handler = field_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pField, handler);
        return pField;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterFieldCore(TempPtr<field_metadata_label_type> &pField)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<field_metadata_label_type>();
        provider.RegisterObject(pField);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadFieldCore(field_metadata_label_type *pField)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<field_metadata_label_type>();
        provider.DeleteObject(pField);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::custom_attribute_metadata_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewCustomAttributeCore(assembly_metadata_label_type *pAsm) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<custom_attribute_metadata_label_type>();
        auto pCa = provider.NewObject();
        pCa->Initialize(pAsm);
        auto handler = custom_attribute_metadata_persisted_handler_label_type(pAsm);
        provider.AddPersistedHandler(pCa, handler);
        return pCa;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterCustomAttributeCore(TempPtr<custom_attribute_metadata_label_type> &pCa)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<custom_attribute_metadata_label_type>();
        provider.RegisterObject(pCa);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadCustomAttributeCore(custom_attribute_metadata_label_type *pCa)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<custom_attribute_metadata_label_type>();
        provider.DeleteObject(pCa);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::assembly_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewAssemblyGeneratorCore(metadata_dispenser_label_type *pDisp) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_generator_label_type>();
        auto pAsmGen = provider.NewObject();
        auto const *pRuntime = m_pClass->GetRuntime();
        auto const *pPEInfo = pRuntime->GetInfo<portable_executable_info_label_type>();
        pAsmGen->Initialize(m_pClass, pDisp, pPEInfo);
        auto handler = assembly_generator_persisted_handler_label_type(pDisp);
        provider.AddPersistedHandler(pAsmGen, handler);
        return pAsmGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterAssemblyGeneratorCore(TempPtr<assembly_generator_label_type> &pAsmGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_generator_label_type>();
        provider.RegisterObject(pAsmGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadAssemblyGeneratorCore(assembly_generator_label_type *pAsmGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<assembly_generator_label_type>();
        provider.DeleteObject(pAsmGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::module_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewModuleGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_generator_label_type>();
        auto pModGen = provider.NewObject();
        pModGen->Initialize(pAsmGen);
        auto handler = module_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pModGen, handler);
        return pModGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterModuleGeneratorCore(TempPtr<module_generator_label_type> &pModGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_generator_label_type>();
        provider.RegisterObject(pModGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadModuleGeneratorCore(module_generator_label_type *pModGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<module_generator_label_type>();
        provider.DeleteObject(pModGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::type_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewTypeGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<type_generator_label_type>();
        auto pTypeGen = provider.NewObject();
        pTypeGen->Initialize(pAsmGen);
        auto handler = type_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pTypeGen, handler);
        return pTypeGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterTypeGeneratorCore(TempPtr<type_generator_label_type> &pTypeGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<type_generator_label_type>();
        provider.RegisterObject(pTypeGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadTypeGeneratorCore(type_generator_label_type *pTypeGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<type_generator_label_type>();
        provider.DeleteObject(pTypeGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::method_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewMethodGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_generator_label_type>();
        auto pMethodGen = provider.NewObject();
        pMethodGen->Initialize(pAsmGen);
        auto handler = method_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pMethodGen, handler);
        return pMethodGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterMethodGeneratorCore(TempPtr<method_generator_label_type> &pMethodGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_generator_label_type>();
        provider.RegisterObject(pMethodGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadMethodGeneratorCore(method_generator_label_type *pMethodGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_generator_label_type>();
        provider.DeleteObject(pMethodGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::parameter_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewParameterGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<parameter_generator_label_type>();
        auto pParamGen = provider.NewObject();
        pParamGen->Initialize(pAsmGen);
        auto handler = parameter_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pParamGen, handler);
        return pParamGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterParameterGeneratorCore(TempPtr<parameter_generator_label_type> &pParamGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<parameter_generator_label_type>();
        provider.RegisterObject(pParamGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadParameterGeneratorCore(parameter_generator_label_type *pParamGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<parameter_generator_label_type>();
        provider.DeleteObject(pParamGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::property_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewPropertyGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<property_generator_label_type>();
        auto pPropGen = provider.NewObject();
        pPropGen->Initialize(pAsmGen);
        auto handler = property_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pPropGen, handler);
        return pPropGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterPropertyGeneratorCore(TempPtr<property_generator_label_type> &pPropGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<property_generator_label_type>();
        provider.RegisterObject(pPropGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadPropertyGeneratorCore(property_generator_label_type *pPropGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<property_generator_label_type>();
        provider.DeleteObject(pPropGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::field_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewFieldGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<field_generator_label_type>();
        auto pFieldGen = provider.NewObject();
        pFieldGen->Initialize(pAsmGen);
        auto handler = field_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pFieldGen, handler);
        return pFieldGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterFieldGeneratorCore(TempPtr<field_generator_label_type> &pFieldGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<field_generator_label_type>();
        provider.RegisterObject(pFieldGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadFieldGeneratorCore(field_generator_label_type *pFieldGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<field_generator_label_type>();
        provider.DeleteObject(pFieldGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::method_body_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewMethodBodyGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_body_generator_label_type>();
        auto pBodyGen = provider.NewObject();
        pBodyGen->Initialize(pAsmGen);
        auto handler = method_body_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pBodyGen, handler);
        return pBodyGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterMethodBodyGeneratorCore(TempPtr<method_body_generator_label_type> &pBodyGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_body_generator_label_type>();
        provider.RegisterObject(pBodyGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadMethodBodyGeneratorCore(method_body_generator_label_type *pBodyGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<method_body_generator_label_type>();
        provider.DeleteObject(pBodyGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::local_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewLocalGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<local_generator_label_type>();
        auto pLocalGen = provider.NewObject();
        pLocalGen->Initialize(pAsmGen);
        auto handler = local_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pLocalGen, handler);
        return pLocalGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterLocalGeneratorCore(TempPtr<local_generator_label_type> &pLocalGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<local_generator_label_type>();
        provider.RegisterObject(pLocalGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadLocalGeneratorCore(local_generator_label_type *pLocalGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<local_generator_label_type>();
        provider.DeleteObject(pLocalGen);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseMetadataInfoPimpl<ApiHolder>::custom_attribute_generator_label_type> BaseMetadataInfoPimpl<ApiHolder>::NewCustomAttributeGeneratorCore(assembly_generator_label_type *pAsmGen) const
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<custom_attribute_generator_label_type>();
        auto pCaGen = provider.NewObject();
        pCaGen->Initialize(pAsmGen);
        auto handler = custom_attribute_generator_persisted_handler_label_type(pAsmGen);
        provider.AddPersistedHandler(pCaGen, handler);
        return pCaGen;
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::RegisterCustomAttributeGeneratorCore(TempPtr<custom_attribute_generator_label_type> &pCaGen)
    {
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<custom_attribute_generator_label_type>();
        provider.RegisterObject(pCaGen);
    }



    template<class ApiHolder>    
    void BaseMetadataInfoPimpl<ApiHolder>::UnloadCustomAttributeGeneratorCore(custom_attribute_generator_label_type *pCaGen)
    { 
        auto *pBaseProvider = BaseHeapProvider();
        auto &provider = pBaseProvider->FirstProviderOf<custom_attribute_generator_label_type>();
        provider.DeleteObject(pCaGen);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEMETADATAINFOPIMPL_HPP

