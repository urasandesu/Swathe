// Test.Urasandesu.Swathe.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

// foward declarations
namespace Urasandesu { namespace Swathe { namespace Interfaces {

}}} // namespace Urasandesu { namespace Swathe { namespace Interfaces {

namespace Urasandesu { namespace Swathe { namespace ApiHolders {

}}} // namespace Urasandesu { namespace Swathe { namespace ApiHolders {

namespace Urasandesu { namespace Swathe {

}}   // namespace Urasandesu { namespace Swathe {

namespace Urasandesu { namespace Swathe { namespace Utilities {

}}}   // namespace Urasandesu { namespace Swathe { namespace Utilities {

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace Hosting {

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming {

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace Metadata {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace Fusion {

}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion {

namespace Urasandesu { namespace Swathe { namespace ApiHolders {

}}} // namespace Urasandesu { namespace Swathe { namespace ApiHolders {

#ifndef URASANDESU_SWATHE_APIHOLDERS_DEFAULTSWATHESTORAGEAPIHOLDER_H
#include <Urasandesu/Swathe/ApiHolders/DefaultSwatheStorageApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_BASECPPANONYMSTORAGE_H
#include <Urasandesu/Swathe/BaseSwatheStorage.h>
#endif

namespace Urasandesu { namespace Swathe {

}}   // namespace Urasandesu { namespace Swathe {

namespace Urasandesu { namespace Swathe { namespace Utilities {

}}}   // namespace Urasandesu { namespace Swathe { namespace Utilities {

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

    namespace DefaultHostInfoApiHolderDetail {
        
        //using boost::mpl::map;
        //using boost::mpl::pair;
        //using namespace Urasandesu::Swathe::Hosting::Interfaces;

        //struct DefaultHostInfoApiHolderImpl
        //{
        //    typedef map<
        //        pair<HostInfoLabel, HostInfo>,
        //        pair<HostInfoPersistedHandlerLabel, HostInfoPersistedHandler>,
        //        pair<RuntimeHostLabel, RuntimeHost>,
        //        pair<RuntimeHostPersistedHandlerLabel, RuntimeHostPersistedHandler>
        //    > api_cartridges;
        //};

    }   // namespace DefaultHostInfoApiHolderDetail {

    struct DefaultHostInfoApiHolder /*: 
        DefaultHostInfoApiHolderDetail::DefaultHostInfoApiHolderImpl*/
    {
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace Hosting {

    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfo
    {
    public:
        BaseHostInfo()
        { }
    };

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace Swathe { namespace StrongNaming {

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace Metadata {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace Swathe { namespace Fusion {

}}}   // namespace Urasandesu { namespace Swathe { namespace Fusion {


// Test.Urasandesu.Swathe.exe --gtest_filter=Urasandesu_Swathe_Test3.*
namespace {

    CPPANONYM_TEST(Urasandesu_Swathe_Test3, Test_01)
    {
        using namespace Urasandesu::Swathe;
        using namespace Urasandesu::Swathe::Hosting;

        HostInfo &hostInfo = SwatheStorage::Object<HostInfo>();
        std::cout << "Hoge!!" << std::endl;
        std::cout << "Hoge!!" << std::endl;
    }

}
