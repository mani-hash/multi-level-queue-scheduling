#include <iostream>
#include <memory>
#include "Process/Generator/ProcessGenerator.h"
#include "macros.h"

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

        if (noOfProcesses < 0)
        {
            throw new std::invalid_argument("Number of processes can't be negative\n");
        }
    }

    int ProcessGenerator::generateProcessId()
    {
        static int processCounter = 1;

        return processCounter++;
    }

    int ProcessGenerator::generateArrivalTime()
    {
        static Utility::RandomNumberGenerator arrivalTimeGenerator(0, PROGRAM_LIFE);

        return arrivalTimeGenerator.generate();
    }

    int ProcessGenerator::generateBurstTime()
    {
        static Utility::RandomNumberGenerator burstTimeGenerator(1, BURST_TIME);

        return burstTimeGenerator.generate();

    }

    ProcessControlBlock ProcessGenerator::createProcess(int priorityLevel)
    {
        ProcessControlBlock process(
            generateProcessId(),
            READY,
            priorityLevel,
            generateArrivalTime(),
            generateBurstTime(),
            0
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
