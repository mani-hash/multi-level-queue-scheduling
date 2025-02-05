#include <iostream>
#include "process.h"
#include "MediumProcessGenerator.h"

namespace Process::Generator
{

    MediumProcessGenerator::MediumProcessGenerator(): ProcessGenerator(Q2) {}

    void MediumProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter number of \"MEDIUM\" priority processes = ";
        std::cin >> noOfProcesses;
    }

} // namespace Process::Generator
