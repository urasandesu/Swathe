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