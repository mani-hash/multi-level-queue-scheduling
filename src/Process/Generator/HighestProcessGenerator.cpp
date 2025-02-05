#include <iostream>
#include "process.h"
#include "HighestProcessGenerator.h"

namespace Process::Generator
{

    HighestProcessGenerator::HighestProcessGenerator(): ProcessGenerator(Q0) {}

    void HighestProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"HIGHEST\" priority processes = ";
        std::cin >> noOfProcesses;
    }


} // namespace Process::Generator
