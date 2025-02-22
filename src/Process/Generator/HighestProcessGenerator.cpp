#include <iostream>
#include "Process/process.h"
#include "Process/Generator/HighestProcessGenerator.h"

namespace Process::Generator
{

    HighestProcessGenerator::HighestProcessGenerator(std::shared_ptr<ProcessTable> processTable):
    ProcessGenerator(Q0, processTable) {}

    void HighestProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"HIGHEST\" priority processes = ";
        std::cin >> noOfProcesses;
    }


} // namespace Process::Generator
