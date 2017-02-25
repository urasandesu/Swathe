/* 
 * File: AssemblyCacheUninstallDispositions.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2017 Akira Sugiura
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
#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEUNINSTALLDISPOSITIONS_H
#define URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEUNINSTALLDISPOSITIONS_H

namespace Urasandesu { namespace Swathe { namespace Fusion {

    namespace AssemblyCacheUninstallDispositionsDetail {

        struct AssemblyCacheUninstallDispositionsDef
        {
            enum type
            {
                ACUD_UNINSTALLED = IASSEMBLYCACHE_UNINSTALL_DISPOSITION_UNINSTALLED, 
                ACUD_STILL_IN_USE = IASSEMBLYCACHE_UNINSTALL_DISPOSITION_STILL_IN_USE, 
                ACUD_ALREADY_UNINSTALLED = IASSEMBLYCACHE_UNINSTALL_DISPOSITION_ALREADY_UNINSTALLED, 
                ACUD_DELETE_PENDING = IASSEMBLYCACHE_UNINSTALL_DISPOSITION_DELETE_PENDING, 
                ACUD_HAS_INSTALL_REFERENCES = IASSEMBLYCACHE_UNINSTALL_DISPOSITION_HAS_INSTALL_REFERENCES, 
                ACUD_REFERENCE_NOT_FOUND = IASSEMBLYCACHE_UNINSTALL_DISPOSITION_REFERENCE_NOT_FOUND, 
                ACUD_UNREACHED
            };
        };

    }   // AssemblyCacheUninstallDispositionsDetail

    typedef Urasandesu::CppAnonym::SafeEnum<AssemblyCacheUninstallDispositionsDetail::AssemblyCacheUninstallDispositionsDef> AssemblyCacheUninstallDispositions;

}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEUNINSTALLDISPOSITIONS_H
