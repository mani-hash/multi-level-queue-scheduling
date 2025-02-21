#include <iostream>
#include "process.h"
#include "HighProcessGenerator.h"

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
