#pragma once
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEY_HPP

#ifndef URASANDESU_SWATHE_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/Swathe/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct StrongNameKeyApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::StrongNameKeyApiHolderLabel, ApiLabel>
    {
    };

    template<
        class StrongNameKeyApiHolder
    >    
    class BaseStrongNameKey
    {
    public:
        typedef BaseStrongNameKey<StrongNameKeyApiHolder> this_type;

        typedef typename StrongNameKeyApiAt<StrongNameKeyApiHolder, Interfaces::StrongNameInfoLabel>::type strong_name_info_type;

        BaseStrongNameKey() : 
            m_pubKeyBlobSize(0),
            m_publicKeyInitialized(false), 
            m_publicKeyTokenInitialized(false)
        { }

        std::vector<BYTE> const &GetPublicKey() const
        {
            if (!m_publicKeyInitialized)
            {
                if (m_pubKeyBlobSize)
                {
                    m_publicKey.reserve(m_pPubKeyBlob->cbPublicKey);
                    BYTE const *pPubKey = reinterpret_cast<BYTE const *>(m_pPubKeyBlob->PublicKey);
                    m_publicKey.assign(pPubKey, pPubKey + m_pPubKeyBlob->cbPublicKey);
                }
                m_publicKeyInitialized = true;
            }
            return m_publicKey;
        }

        std::vector<BYTE> const &GetPublicKeyToken() const
        {
            if (!m_publicKeyTokenInitialized)
            {
                if (m_pubKeyBlobSize)
                {
                    BYTE *pPubKeyToken = NULL;
                    DWORD pubKeyTokenSize = 0;
                    if (!::StrongNameTokenFromPublicKey(reinterpret_cast<BYTE *>(m_pPubKeyBlob.get()), 
                                                        m_pubKeyBlobSize, 
                                                        &pPubKeyToken, 
                                                        &pubKeyTokenSize))
                        BOOST_THROW_EXCEPTION(SwatheCOMException(::StrongNameErrorInfo()));
                    BOOST_SCOPE_EXIT((pPubKeyToken))
                    {
                        ::StrongNameFreeBuffer(pPubKeyToken);
                    }
                    BOOST_SCOPE_EXIT_END
                    
                    m_publicKeyToken.reserve(pubKeyTokenSize);
                    m_publicKeyToken.assign(pPubKeyToken, pPubKeyToken + pubKeyTokenSize);
                }
                m_publicKeyTokenInitialized = true;
            }
            return m_publicKeyToken;
        }

    private:
        friend typename strong_name_info_type;

        void SetPublicKeyBlob(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize)
        {
            m_pPubKeyBlob = std::auto_ptr<PublicKeyBlob>(reinterpret_cast<PublicKeyBlob *>(new BYTE[pubKeyBlobSize]));
            ::memcpy_s(m_pPubKeyBlob.get(), pubKeyBlobSize, &pubKeyBlob, pubKeyBlobSize);
            m_pubKeyBlobSize = pubKeyBlobSize;
        }

        std::auto_ptr<PublicKeyBlob> m_pPubKeyBlob;
        DWORD m_pubKeyBlobSize;
        mutable bool m_publicKeyInitialized;
        mutable std::vector<BYTE> m_publicKey;
        mutable bool m_publicKeyTokenInitialized;
        mutable std::vector<BYTE> m_publicKeyToken;
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming {

#endif  // #ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEKEY_HPP