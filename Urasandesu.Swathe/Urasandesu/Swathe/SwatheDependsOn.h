/* 
 * File: SwatheDependsOn.h
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
#ifndef URASANDESU_SWATHE_SWATHEDEPENDSON_H
#define URASANDESU_SWATHE_SWATHEDEPENDSON_H

#ifndef URASANDESU_CPPANONYM_H
#include <Urasandesu/CppAnonym.h>
#endif

#include <corhlpr.h>    // This header needs the definitions. You must include the 
                        // implementation file, named corhlpr.cpp at only once. 
                        // In this time, I include it in stdafx.cpp.
#include <fusion.h>
#include <mscoree.h>

namespace Urasandesu { namespace Swathe {

}}   // namespace Urasandesu { namespace Swathe {

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINGDEPENDSON_H
#include <Urasandesu/Swathe/Hosting/HostingDependsOn.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADEPENDSON_H
#include <Urasandesu/Swathe/Metadata/MetadataDependsOn.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_PROFILINGDEPENDSON_H
#include <Urasandesu/Swathe/Profiling/ProfilingDependsOn.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMINGDEPENDSON_H
#include <Urasandesu/Swathe/StrongNaming/StrongNamingDependsOn.h>
#endif

#endif  // #ifndef URASANDESU_SWATHE_SWATHEDEPENDSON_H
