#include <iostream>
#include "Process/process.h"
#include "Process/Generator/HighProcessGenerator.h"

namespace Process::Generator
{

    HighProcessGenerator::HighProcessGenerator(std::shared_ptr<ProcessTable> processTable):
    ProcessGenerator(Q1, processTable) {}

    void HighProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"HIGH\" priority processes = ";
        std::cin >> noOfProcesses;
    }

} // namespace Process::Generator
