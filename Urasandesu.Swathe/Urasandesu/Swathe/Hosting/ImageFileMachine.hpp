#pragma once
#ifndef URASANDESU_SWATHE_HOSTING_IMAGEFILEMACHINE_HPP
#define URASANDESU_SWATHE_HOSTING_IMAGEFILEMACHINE_HPP

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting {

    namespace ImageFileMachineDetail {

        struct ImageFileMachineDef
        {
            enum type
            {
                IFM_I386, 
                IFM_IA64, 
                IFM_AMD64, 
                IFM_UNREACHED
            };
        };

    }   // namespace ImageFileMachineDetail {

    typedef SafeEnum<ImageFileMachineDetail::ImageFileMachineDef> ImageFileMachine;

}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting {

#endif  // #ifndef URASANDESU_SWATHE_HOSTING_IMAGEFILEMACHINE_HPP