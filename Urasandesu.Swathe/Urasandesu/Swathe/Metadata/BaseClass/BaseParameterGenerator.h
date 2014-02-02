/* 
 * File: BaseParameterGenerator.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_H
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_PARAMETERGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/ParameterGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseParameterGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITORFWD_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseParameterGenerator : 
        public IParameter
    {
    public:
        SWATHE_BEGIN_PARAMETER_GENERATOR_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_PARAMETER_GENERATOR_FACADE_TYPEDEF_ALIAS
        SWATHE_END_PARAMETER_GENERATOR_FACADE_TYPEDEF_ALIAS
        
        BaseParameterGenerator();
        ~BaseParameterGenerator();

        void Initialize(assembly_generator_label_type *pAsmGen);
        mdToken GetToken() const;
        ULONG GetPosition() const;
        wstring const &GetName() const;
        ParameterAttributes GetAttribute() const;
        IType const *GetParameterType() const;
        Signature const &GetSignature() const;
        IMethod const *GetMethod() const;
        IProperty const *GetProperty() const;
        ParameterProvider const &GetMember() const;
        IParameter const *GetSourceParameter() const;
        void OutDebugInfo(ULONG indent) const;
    
    private:
        parameter_generator_pimpl_label_type *Pimpl();
        parameter_generator_pimpl_label_type const *Pimpl() const;
        void SetPosition(ULONG position);
        void SetParameterType(IType const *pParamType);
        void SetSourceParameter(IParameter const *pSrcParam);
        void SetMember(ParameterProvider const &member);
        void Accept(IMetadataVisitor *pVisitor) const;
#ifdef _DEBUG
        static INT const PIMPL_TYPE_SIZE = 1024;
#else
        static INT const PIMPL_TYPE_SIZE = 40;
#endif
        typedef typename boost::aligned_storage<PIMPL_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_H

