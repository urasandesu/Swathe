#pragma once
#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#define URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H

namespace Urasandesu { namespace Swathe { namespace Metadata {

    struct MetadataSpecialValues
    {
        static std::wstring const TYPE_NAME_OF_VOID;
        static std::wstring const TYPE_NAME_OF_BOOLEAN;
        static std::wstring const TYPE_NAME_OF_CHAR;
        static std::wstring const TYPE_NAME_OF_SBYTE;
        static std::wstring const TYPE_NAME_OF_BYTE;
        static std::wstring const TYPE_NAME_OF_INT16;
        static std::wstring const TYPE_NAME_OF_UINT16;
        static std::wstring const TYPE_NAME_OF_INT32;
        static std::wstring const TYPE_NAME_OF_UINT32;
        static std::wstring const TYPE_NAME_OF_INT64;
        static std::wstring const TYPE_NAME_OF_UINT64;
        static std::wstring const TYPE_NAME_OF_SINGLE;
        static std::wstring const TYPE_NAME_OF_DOUBLE;
        static std::wstring const TYPE_NAME_OF_STRING;
        static std::wstring const TYPE_NAME_OF_INTPTR;
        static std::wstring const TYPE_NAME_OF_OBJECT;
        static std::wstring const TYPE_NAME_OF_VALUETYPE;
        static std::wstring const GENERIC_TYPE_IDENTIFIER;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H