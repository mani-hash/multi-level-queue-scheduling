#include <iostream>
#include <algorithm>
#include "Process/ProcessTable.h"
#include "Process/process.h"

namespace Process
{

    ProcessTable::ProcessTable(): terminatedProcess(0) {}

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

    int ProcessTable::getTerminatedProcessCount() const
    {
        return terminatedProcess;
    }

    void ProcessTable::incrementTerminatedProcessCount()
    {
        terminatedProcess+=1;
    }

    int ProcessTable::getAllProcessCount() const
    {
        return processes.size();
    }

    void ProcessTable::incrementWaitingTime(int elapsedTime)
    {
        for (auto processIter = processes.begin(); processIter != processes.end(); ++processIter)
        {
            if (processIter->getState() == WAITING)
            {
                processIter->setWaitingTime(elapsedTime);
            }
        }
    }

    std::map<std::string, double> ProcessTable::getAverageWaitingTimes() const
    {
        std::map<std::string, double> averageWaitingTimes;

        typedef struct WaitingTime
        {
            long int totalWaitingCount;
            int noOfProcess;
        } WaitingTime;

        WaitingTime q0 = {
            .totalWaitingCount = 0,
            .noOfProcess = 0
        };

        WaitingTime q1 = {
            .totalWaitingCount = 0,
            .noOfProcess = 0
        };

        WaitingTime q2 = {
            .totalWaitingCount = 0,
            .noOfProcess = 0
        };

        WaitingTime q3 = {
            .totalWaitingCount = 0,
            .noOfProcess = 0
        };

        for (auto processIter = processes.begin(); processIter != processes.end(); ++processIter)
        {
            int processPriority = processIter->getPriority();

            if (processPriority >= Q0.min && processPriority <= Q0.max)
            {
                q0.totalWaitingCount += processIter->getWaitingTime();
                q0.noOfProcess += 1;
            }
            else if (processPriority >= Q1.min && processPriority <= Q1.max)
            {
                q1.totalWaitingCount += processIter->getWaitingTime();
                q1.noOfProcess += 1;
            }
            else if (processPriority >= Q2.min && processPriority <= Q2.max)
            {
                q2.totalWaitingCount += processIter->getWaitingTime();
                q2.noOfProcess += 1;
            }
            else if (processPriority >= Q3.min && processPriority <= Q3.max)
            {
                q3.totalWaitingCount += processIter->getWaitingTime();
                q3.noOfProcess += 1;
            }
        }

        averageWaitingTimes["q0"] = static_cast<double>(q0.totalWaitingCount) / q0.noOfProcess;
        averageWaitingTimes["q1"] = static_cast<double>(q1.totalWaitingCount) / q1.noOfProcess;
        averageWaitingTimes["q2"] = static_cast<double>(q2.totalWaitingCount) / q2.noOfProcess;
        averageWaitingTimes["q3"] = static_cast<double>(q3.totalWaitingCount) / q3.noOfProcess;

        return averageWaitingTimes;
    }

    std::map<std::string, double> ProcessTable::getAverageTurnAroundTimes() const
    {
        std::map<std::string, double> averageTurnAroundTimes;

        typedef struct TurnAround
        {
            long int totalTurnAroundTime;
            int noOfProcess;
        } TurnAround;

        TurnAround q0 = {
            .totalTurnAroundTime = 0,
            .noOfProcess = 0
        };

        TurnAround q1 = {
            .totalTurnAroundTime = 0,
            .noOfProcess = 0
        };

        TurnAround q2 = {
            .totalTurnAroundTime = 0,
            .noOfProcess = 0
        };

        TurnAround q3 = {
            .totalTurnAroundTime = 0,
            .noOfProcess = 0
        };

        for (auto processIter = processes.begin(); processIter != processes.end(); ++processIter)
        {
            int processPriority = processIter->getPriority();
            long int turnaroundTime = processIter->getBurstTime() + processIter->getWaitingTime();

            if (processPriority >= Q0.min && processPriority <= Q0.max)
            {
                q0.totalTurnAroundTime += turnaroundTime;
                q0.noOfProcess += 1;
            }
            else if (processPriority >= Q1.min && processPriority <= Q1.max)
            {
                q1.totalTurnAroundTime += turnaroundTime;
                q1.noOfProcess += 1;
            }
            else if (processPriority >= Q2.min && processPriority <= Q2.max)
            {
                q2.totalTurnAroundTime += turnaroundTime;
                q2.noOfProcess += 1;
            }
            else if (processPriority >= Q3.min && processPriority <= Q3.max)
            {
                q3.totalTurnAroundTime += turnaroundTime;
                q3.noOfProcess += 1;
            }
        }

        averageTurnAroundTimes["q0"] = static_cast<double>(q0.totalTurnAroundTime) / q0.noOfProcess;
        averageTurnAroundTimes["q1"] = static_cast<double>(q1.totalTurnAroundTime) / q1.noOfProcess;
        averageTurnAroundTimes["q2"] = static_cast<double>(q2.totalTurnAroundTime) / q2.noOfProcess;
        averageTurnAroundTimes["q3"] = static_cast<double>(q3.totalTurnAroundTime) / q3.noOfProcess;

        return averageTurnAroundTimes;
    }

} // namespace Process
