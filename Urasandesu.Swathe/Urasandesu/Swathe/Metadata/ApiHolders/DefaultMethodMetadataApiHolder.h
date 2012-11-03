#pragma once
#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#define URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

    namespace DefaultMethodMetadataApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::Swathe::Metadata::Interfaces;

        struct DefaultMethodMetadataApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace DefaultMethodMetadataApiHolderDetail {
    
    struct DefaultMethodMetadataApiHolder : 
        DefaultMethodMetadataApiHolderDetail::DefaultMethodMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H