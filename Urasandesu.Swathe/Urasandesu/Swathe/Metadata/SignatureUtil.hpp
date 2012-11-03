#pragma once
#ifndef URASANDESU_SWATHE_METADATA_SIGNATUREUTIL_HPP
#define URASANDESU_SWATHE_METADATA_SIGNATUREUTIL_HPP

#ifndef URASANDESU_SWATHE_SIMPLEBLOB_H
#include <Urasandesu/Swathe/SimpleBlob.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    struct SignatureUtil
    {
        template<class SignatureHolder>
        static void PutSignatures(SimpleBlob &sb, SignatureHolder const &sigHolder)
        {
            typedef std::vector<COR_SIGNATURE>::const_iterator Iterator;
            std::vector<COR_SIGNATURE> const &sigs = sigHolder.GetSignatures();
            for (Iterator i = sigs.cbegin(), i_end = sigs.cend(); i != i_end; ++i)
                sb.Put<COR_SIGNATURE>(*i);
        }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_SIGNATUREUTIL_HPP