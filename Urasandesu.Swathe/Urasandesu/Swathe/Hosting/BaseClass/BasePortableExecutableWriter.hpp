/* 
 * File: BasePortableExecutableWriter.hpp
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_HPP
#define URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_HPP

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableWriter.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

    template<class ApiHolder>    
    BasePortableExecutableWriter<ApiHolder>::BasePortableExecutableWriter()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(portable_executable_writer_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(portable_executable_writer_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())portable_executable_writer_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BasePortableExecutableWriter<ApiHolder>::~BasePortableExecutableWriter()
    {
        Pimpl()->~portable_executable_writer_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BasePortableExecutableWriter<ApiHolder>::portable_executable_writer_pimpl_label_type *BasePortableExecutableWriter<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<portable_executable_writer_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BasePortableExecutableWriter<ApiHolder>::portable_executable_writer_pimpl_label_type const *BasePortableExecutableWriter<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_PORTABLE_EXECUTABLE_WRITER_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Initialize(portable_executable_info_label_type *pPEInfo, strong_name_info_label_type const *pSnInfo)
    {
        Pimpl()->Initialize(pPEInfo, pSnInfo);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IAssembly const *pAsm)
    {
        Pimpl()->Visit(pAsm);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IModule const *pMod)
    {
        Pimpl()->Visit(pMod);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IType const *pType)
    {
        Pimpl()->Visit(pType);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IField const *pField)
    {
        Pimpl()->Visit(pField);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IProperty const *pProp)
    {
        Pimpl()->Visit(pProp);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IMethod const *pMethod)
    {
        Pimpl()->Visit(pMethod);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IMethodBody const *pBody)
    {
        Pimpl()->Visit(pBody);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IParameter const *pParam)
    {
        Pimpl()->Visit(pParam);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(ILocal const *pLocal)
    {
        Pimpl()->Visit(pLocal);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(IInstruction const *pInst)
    {
        Pimpl()->Visit(pInst);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Visit(ICustomAttribute const *pCa)
    {
        Pimpl()->Visit(pCa);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::Close()
    {
        Pimpl()->Close();
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::SetCOMMetaDataEmit(IMetaDataEmit2 *pComMetaEmt)
    {
        Pimpl()->SetCOMMetaDataEmit(pComMetaEmt);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::SetImageFlags(ComImageFlags const &imageFlags)
    {
        Pimpl()->SetImageFlags(imageFlags);
    }

    template<class ApiHolder>    
    void BasePortableExecutableWriter<ApiHolder>::SetCreateFlags(CeeCreateFlags const &createFlags)
    {
        Pimpl()->SetCreateFlags(createFlags);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_HPP

