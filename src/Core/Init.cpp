#include "Init.h"

#include <iostream>
#include <memory>
#include "HighestProcessGenerator.h"
#include "HighProcessGenerator.h"
#include "MediumProcessGenerator.h"
#include "LowestProcessGenerator.h"

namespace Core
{

    Init::Init(): processTable(std::make_shared<Process::ProcessTable>())
    {
        initiateAllProcess();
        initiateProcessTable();
    }

    void Init::initiateAllProcess()
    {
        Process::Generator::HighestProcessGenerator highestProcessGen(processTable);
        highestProcessGen.getProcessCountFromUser();
        highestProcessGen.generate();

        Process::Generator::HighProcessGenerator highProcessGen(processTable);
        highProcessGen.getProcessCountFromUser();
        highProcessGen.generate();

        Process::Generator::MediumProcessGenerator mediumProcessGen(processTable);
        mediumProcessGen.getProcessCountFromUser();
        mediumProcessGen.generate();

        Process::Generator::LowestProcessGenerator lowestProcessGen(processTable);
        lowestProcessGen.getProcessCountFromUser();
        lowestProcessGen.generate();
    }

    void Init::initiateProcessTable()
    {
        processTable->sort();
    }

    Init& Init::getInstance()
    {
        static Init instance;
        return instance;
    }

    std::shared_ptr<Process::ProcessTable> Init::getProcessTable() const
    {
        return processTable;
    }

} // namespace Core
