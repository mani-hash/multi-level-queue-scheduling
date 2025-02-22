#include <iostream>
#include "Process/process.h"
#include "Process/Generator/LowestProcessGenerator.h"

namespace Process::Generator
{

    LowestProcessGenerator::LowestProcessGenerator(std::shared_ptr<ProcessTable> processTable):
    ProcessGenerator(Q3, processTable) {}

    void LowestProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"LOWEST\" priority processes = ";
        std::cin >> noOfProcesses;
    }

} // namespace Process::Generator
