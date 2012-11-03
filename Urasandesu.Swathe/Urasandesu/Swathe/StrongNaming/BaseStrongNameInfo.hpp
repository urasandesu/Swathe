#pragma once
#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#define URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFO_HPP

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/Swathe/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/Swathe/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace StrongNaming {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct StrongNameInfoApiAt : 
        CppAnonym::Traits::ApiAt<ApiCartridgesHolder, Interfaces::StrongNameInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class StrongNameInfoApiHolder
    >    
    class BaseStrongNameInfo : 
        public SmartPtrChain<
            BaseStrongNameInfo<StrongNameInfoApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type>
            >
        >,
        SmartHeapProvider<
            boost::mpl::vector<
                typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Interfaces::StrongNameKeyLabel>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseStrongNameInfo<StrongNameInfoApiHolder> this_type;

        typedef typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        typedef typename provider_of<strong_name_key_type>::type strong_name_key_provider_type;

        boost::shared_ptr<strong_name_key_type const> GetStrongNameKey(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize) const
        {
            strong_name_key_provider_type &provider = ProviderOf<strong_name_key_type>();
            boost::shared_ptr<strong_name_key_type> pSnKey = provider.NewObject();
            pSnKey->SetPublicKeyBlob(pubKeyBlob, pubKeyBlobSize);
            return pSnKey;
        }

        boost::shared_ptr<strong_name_key_type const> GetStrongNameKey(std::wstring const &snkFilePath) const
        {
            typedef std::vector<BYTE, Utilities::StackAllocator<BYTE> > ByteVector;
            ByteVector keyPair;
            DWORD keyPairSize = 0;
            PublicKeyBlob *pPubKeyBlob = NULL;
            DWORD pubKeyBlobSize = 0;
            HANDLE hSnk = NULL;
            hSnk = ::CreateFileW(snkFilePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, 
                                    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
            if (hSnk == INVALID_HANDLE_VALUE)
                BOOST_THROW_EXCEPTION(SwatheSystemException(::GetLastError()));
            BOOST_SCOPE_EXIT((&hSnk))
            {
                ::CloseHandle(hSnk);
            }
            BOOST_SCOPE_EXIT_END
            
            keyPairSize = ::GetFileSize(hSnk, NULL);
            if (keyPairSize == -1)
                BOOST_THROW_EXCEPTION(SwatheSystemException(::GetLastError()));

            if (keyPairSize == 0)
                return boost::shared_ptr<strong_name_key_type const>();
            
            keyPair.resize(keyPairSize);
            if (::ReadFile(hSnk, &keyPair[0], keyPairSize, &keyPairSize, NULL) == FALSE)
                BOOST_THROW_EXCEPTION(SwatheSystemException(::GetLastError()));

            if (!::StrongNameGetPublicKey(NULL, &keyPair[0], keyPairSize, reinterpret_cast<BYTE **>(&pPubKeyBlob), &pubKeyBlobSize))
                BOOST_THROW_EXCEPTION(SwatheCOMException(::StrongNameErrorInfo()));
            BOOST_SCOPE_EXIT((&pubKeyBlobSize)(&pPubKeyBlob))
            {
                if (pubKeyBlobSize)
                    ::StrongNameFreeBuffer(reinterpret_cast<BYTE *>(pPubKeyBlob));
            }
            BOOST_SCOPE_EXIT_END

            if (pubKeyBlobSize == 0)
                return boost::shared_ptr<strong_name_key_type const>();

            return GetStrongNameKey(*pPubKeyBlob, pubKeyBlobSize);
        }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming {

#endif  // #ifndef URASANDESU_SWATHE_STRONGNAMING_BASESTRONGNAMEINFO_HPP