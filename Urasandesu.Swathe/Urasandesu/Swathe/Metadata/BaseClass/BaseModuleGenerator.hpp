/* 
 * File: BaseModuleGenerator.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseModuleGenerator.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseModuleGenerator<ApiHolder>::BaseModuleGenerator()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(module_generator_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(module_generator_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())module_generator_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseModuleGenerator<ApiHolder>::~BaseModuleGenerator()
    {
        Pimpl()->~module_generator_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseModuleGenerator<ApiHolder>::module_generator_pimpl_label_type *BaseModuleGenerator<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<module_generator_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseModuleGenerator<ApiHolder>::module_generator_pimpl_label_type const *BaseModuleGenerator<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_MODULE_GENERATOR_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseModuleGenerator<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        Pimpl()->Initialize(pAsmGen);
    }

    template<class ApiHolder>    
    mdModule BaseModuleGenerator<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    wstring const &BaseModuleGenerator<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }

    template<class ApiHolder>    
    IType const *BaseModuleGenerator<ApiHolder>::GetType(wstring const &fullName) const
    {
        return Pimpl()->GetType(fullName);
    }

    template<class ApiHolder>    
    vector<IType const *> const &BaseModuleGenerator<ApiHolder>::GetTypes() const
    {
        return Pimpl()->GetTypes();
    }

    template<class ApiHolder>    
    IAssembly const *BaseModuleGenerator<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IModule const *BaseModuleGenerator<ApiHolder>::GetSourceModule() const
    {
        return Pimpl()->GetSourceModule();
    }

    template<class ApiHolder>    
    typename BaseModuleGenerator<ApiHolder>::type_generator_label_type *BaseModuleGenerator<ApiHolder>::DefineType(wstring const &fullName, TypeAttributes const &attr)
    {
        return Pimpl()->DefineType(fullName, attr);
    }

    template<class ApiHolder>    
    void BaseModuleGenerator<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

    template<class ApiHolder>    
    void BaseModuleGenerator<ApiHolder>::SetSourceModule(IModule const *pSrcMod)
    {
        Pimpl()->SetSourceModule(pSrcMod);
    }

    template<class ApiHolder>    
    void BaseModuleGenerator<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        Pimpl()->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_HPP

