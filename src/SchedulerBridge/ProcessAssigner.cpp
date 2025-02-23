#include "SchedulerBridge/ProcessAssigner.h"
#include <queue>
#include <functional>

namespace SchedulerBridge
{

    ProcessAssigner::ProcessAssigner(std::shared_ptr<Process::ProcessTable> processTable): 
        processTable(processTable) {}

    int ProcessAssigner::nextProcessIndex = 0;

    std::vector<std::reference_wrapper<Process::ProcessControlBlock>>
        ProcessAssigner::getArrivedProcesses() const
    {
        std::vector<std::reference_wrapper<Process::ProcessControlBlock>> availableProcesses;

        const std::vector<Process::ProcessControlBlock>& processes = processTable->getProcessList();

        int currentTime = processes[nextProcessIndex].getArrivalTime();

        while (processes[nextProcessIndex].getArrivalTime() <= currentTime)
        {
            Process::ProcessControlBlock* processPtr = 
                processTable->getProcess(processes[nextProcessIndex].getProcessId());

            Process::ProcessControlBlock& process = *processPtr;

            availableProcesses.push_back(std::ref(process));
            nextProcessIndex+=1;
        }

        return availableProcesses;
    }

    int ProcessAssigner::getTimeUntilNextProcessAssignment() const
    {
        const std::vector<Process::ProcessControlBlock>& processes = processTable->getProcessList();

        return processes[nextProcessIndex].getArrivalTime();
    }

} // namespace SchedulerBridge
