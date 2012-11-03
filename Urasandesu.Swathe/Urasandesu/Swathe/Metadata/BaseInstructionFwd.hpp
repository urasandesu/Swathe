#pragma once
#ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTIONFWD_HPP
#define URASANDESU_SWATHE_METADATA_BASEINSTRUCTIONFWD_HPP

#ifndef URASANDESU_SWATHE_METADATA_APIHOLDERS_DEFAULTINSTRUCTIONAPIHOLDERFWD_H
#include <Urasandesu/Swathe/Metadata/ApiHolders/DefaultInstructionApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    template<
        class InstructionApiHolder = ApiHolders::DefaultInstructionApiHolder
    >    
    class BaseInstruction;

    typedef BaseInstruction<> Instruction;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_BASEINSTRUCTIONFWD_HPP