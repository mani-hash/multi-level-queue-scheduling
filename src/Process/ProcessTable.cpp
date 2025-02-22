#include <iostream>
#include <algorithm>
#include "Process/ProcessTable.h"

namespace Process
{

    void ProcessTable::addProcess(const ProcessControlBlock& process)
    {
        processes.push_back(process);
    }

    void ProcessTable::removeProcess(int processId)
    {
        processes.erase(std::remove_if(
            processes.begin(),
            processes.end(),
            [processId](const ProcessControlBlock& process)
            {
                return process.getProcessId() == processId;
            }
        ));
    }

    ProcessControlBlock* ProcessTable::getProcess(int processId)
    {
        for (auto& process: processes)
        {
            if (process.getProcessId() == processId)
            {
                return &process;
            }
        }

        return nullptr;

    }

    void ProcessTable::sort()
    {
        std::sort(processes.begin(), processes.end(), [](const ProcessControlBlock& processA, const ProcessControlBlock& processB) {
            return processA.getArrivalTime() < processB.getArrivalTime();
        });
    }

    const std::vector<ProcessControlBlock>& ProcessTable::getProcessList() const
    {
        return processes;
    }

} // namespace Process
