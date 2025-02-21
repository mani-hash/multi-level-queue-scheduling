#include <iostream>
#include "process.h"
#include "MediumProcessGenerator.h"

namespace Process::Generator
{

    MediumProcessGenerator::MediumProcessGenerator(std::shared_ptr<ProcessTable> processTable):
    ProcessGenerator(Q2, processTable) {}

    void MediumProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"MEDIUM\" priority processes = ";
        std::cin >> noOfProcesses;
    }

} // namespace Process::Generator
