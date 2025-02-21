#include <iostream>
#include <memory>
#include "ProcessGenerator.h"

namespace Process::Generator
{

    ProcessGenerator::ProcessGenerator
    (
        const PriorityRange priorityRange,
        std::shared_ptr<ProcessTable> processTable
    )
    :
    priorityRange(priorityRange),
    processTable(processTable),
    rng(priorityRange.min, priorityRange.max) {}

    void ProcessGenerator::getProcessCountFromUser()
    {
        std::cout << "Enter the count of processes = ";
        std::cin >> noOfProcesses;
    }

    int ProcessGenerator::generateProcessId()
    {
        static int processCounter = 0;

        return processCounter++;
    }

    int ProcessGenerator::generateBurstTime()
    {
        static Utility::RandomNumberGenerator burstTimeGenerator(1, 20000);

        return burstTimeGenerator.generate();

    }

    ProcessControlBlock ProcessGenerator::createProcess(int priorityLevel)
    {
        ProcessControlBlock process(
            generateProcessId(),
            "ready",
            priorityLevel,
            0,
            generateBurstTime()
        );

        return process;
    }

    int ProcessGenerator::getPriorityForProcess()
    {
        return rng.generate();
    }

    void ProcessGenerator::generate()
    {
        for (size_t processIndex = 0; processIndex < noOfProcesses; processIndex++)
        {
            int priorityLevel = getPriorityForProcess();
            ProcessControlBlock process = createProcess(priorityLevel);
            processTable->addProcess(process);
        }
        
    }

} // namespace Process::Generator
