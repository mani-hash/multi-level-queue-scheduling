#include <iostream>
#include "process.h"
#include "LowestProcessGenerator.h"

namespace Process::Generator
{

    LowestProcessGenerator::LowestProcessGenerator(): ProcessGenerator(Q3) {}

    void LowestProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"LOWEST\" priority processes = ";
        std::cin >> noOfProcesses;
    }

} // namespace Process::Generator
