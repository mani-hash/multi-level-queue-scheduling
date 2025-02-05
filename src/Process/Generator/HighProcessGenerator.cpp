#include <iostream>
#include "process.h"
#include "HighProcessGenerator.h"

namespace Process::Generator
{

    HighProcessGenerator::HighProcessGenerator(): ProcessGenerator(Q1) {}

    void HighProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"HIGH\" priority processes = ";
        std::cin >> noOfProcesses;
    }

} // namespace Process::Generator
