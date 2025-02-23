#include "SchedulerBridge/ProcessAssigner.h"
#include <queue>
#include <functional>
#include "Utility/TimeTracker.h"

namespace SchedulerBridge
{

    ProcessAssigner::ProcessAssigner(std::shared_ptr<Process::ProcessTable> processTable): 
        processTable(processTable) {}

    int ProcessAssigner::nextProcessIndex = 0;

    std::vector<std::reference_wrapper<Process::ProcessControlBlock>>
        ProcessAssigner::getArrivedProcesses() const
    {
        std::vector<std::reference_wrapper<Process::ProcessControlBlock>> availableProcesses;
        Utility::TimeTracker& time = Utility::TimeTracker::getInstance();
        int currentTime = time.getTime();

        const std::vector<Process::ProcessControlBlock>& processes = processTable->getProcessList();

        while (processes[nextProcessIndex].getArrivalTime() <= currentTime)
        {
            Process::ProcessControlBlock* processPtr = 
                processTable->getProcess(processes[nextProcessIndex].getProcessId());

            Process::ProcessControlBlock& process = *processPtr;

            availableProcesses.push_back(process);
            nextProcessIndex+=1;
        }

        return availableProcesses;
    }

} // namespace SchedulerBridge
