/* 
 * File: ProcessorArchitecture.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_PROCESSORARCHITECTURE_HPP
#define URASANDESU_SWATHE_METADATA_PROCESSORARCHITECTURE_HPP

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace ProcessorArchitectureDetail {

        struct ProcessorArchitectureDef
        {
            enum type
            {
                PA_INTEL = PROCESSOR_ARCHITECTURE_INTEL, 
                PA_MIPS = PROCESSOR_ARCHITECTURE_MIPS, 
                PA_ALPHA = PROCESSOR_ARCHITECTURE_ALPHA, 
                PA_PPC = PROCESSOR_ARCHITECTURE_PPC, 
                PA_SHX = PROCESSOR_ARCHITECTURE_SHX, 
                PA_ARM = PROCESSOR_ARCHITECTURE_ARM, 
                PA_IA64 = PROCESSOR_ARCHITECTURE_IA64, 
                PA_ALPHA64 = PROCESSOR_ARCHITECTURE_ALPHA64, 
                PA_MSIL = PROCESSOR_ARCHITECTURE_MSIL, 
                PA_AMD64 = PROCESSOR_ARCHITECTURE_AMD64, 
                PA_IA32_ON_WIN64 = PROCESSOR_ARCHITECTURE_IA32_ON_WIN64, 
                PA_UNKNOWN = PROCESSOR_ARCHITECTURE_UNKNOWN
            };
        };

    }   // ProcessorArchitectureDetail

    typedef Urasandesu::CppAnonym::SafeEnum<ProcessorArchitectureDetail::ProcessorArchitectureDef> ProcessorArchitecture;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_PROCESSORARCHITECTURE_HPP
