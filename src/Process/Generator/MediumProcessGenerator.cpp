#include <iostream>
#include "Process/process.h"
#include "Process/Generator/MediumProcessGenerator.h"

namespace Process::Generator
{

    MediumProcessGenerator::MediumProcessGenerator(std::shared_ptr<ProcessTable> processTable):
    ProcessGenerator(Q2, processTable) {}

    void MediumProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"MEDIUM\" priority processes = ";
        std::cin >> noOfProcesses;

        if (noOfProcesses < 0)
        {
            throw new std::invalid_argument("Number of processes can't be negative\n");
        }
    }

} // namespace Process::Generator
