#include <iostream>
#include "ProcessGenerator.h"

namespace Process::Generator
{

    ProcessGenerator::ProcessGenerator(const PriorityRange priorityRange) :
    priorityRange(priorityRange), rng(priorityRange.min, priorityRange.max) {}

    void ProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter the count of processes = ";
        std::cin >> noOfProcesses;
    }

    ProcessControlBlock* ProcessGenerator::createProcess(int priorityLevel)
    {
        ProcessControlBlock process(
            1,
            "",
            getPriorityForProcess(),
            200,
            3000
        );

        return &process;
    }

    int ProcessGenerator::getPriorityForProcess()
    {
        return rng.generate();
    }

} // namespace Process::Generator
