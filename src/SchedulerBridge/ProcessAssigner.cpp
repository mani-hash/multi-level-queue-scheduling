#include "SchedulerBridge/ProcessAssigner.h"
#include "Utility/TimeTracker.h"

namespace SchedulerBridge
{

    ProcessAssigner::ProcessAssigner(std::shared_ptr<Process::ProcessTable> processTable): 
        processTable(processTable) {}

    std::vector<std::reference_wrapper<Process::ProcessControlBlock>>
        ProcessAssigner::getArrivedProcesses() const
    {
        Utility::TimeTracker& time = Utility::TimeTracker::getInstance();

        const std::vector<Process::ProcessControlBlock>& processes = processTable
            ->getProcessList();

        std::vector<std::reference_wrapper<Process::ProcessControlBlock>> arrivedProcesses;

        for (auto process = processes.cbegin(); process != processes.cend(); ++process)
        {
            if (process->getArrivalTime() < time.getTime())
            {
                continue;
            }
            else if (process->getArrivalTime() > time.getTime())
            {
                break;
            }
            else
            {
                Process::ProcessControlBlock* retrievedProcess = processTable
                    ->getProcess(process->getProcessId());

                if (retrievedProcess == nullptr)
                {
                    perror("Process is not available\n");
                    exit(EXIT_FAILURE);
                }

                Process::ProcessControlBlock& referenceProcess = *retrievedProcess; 

                arrivedProcesses.push_back(referenceProcess);
            }
        }

        return arrivedProcesses;
    }

} // namespace SchedulerBridge
