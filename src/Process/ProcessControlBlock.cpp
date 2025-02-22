#include <iostream>
#include "Process/ProcessControlBlock.h"

namespace Process
{
    ProcessControlBlock::ProcessControlBlock
    (
        int processId,
        std::string state,
        int priority,
        int arrivalTime,
        int burstTime
    )
    {
        this->processId = processId;
        this->state = state;
        this->priority = priority;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->remainingBurstTime = burstTime;
    }

    int ProcessControlBlock::getProcessId() const
    {
        return processId;
    }

    int ProcessControlBlock::getArrivalTime() const
    {
        return arrivalTime;
    }

    int ProcessControlBlock::getBurstTime() const
    {
        return burstTime;
    }

    int ProcessControlBlock::getRemainingBurstTime() const
    {
        return remainingBurstTime;
    }

    void ProcessControlBlock::setRemainingBurstTime(int elapsedTime)
    {
        remainingBurstTime = burstTime - elapsedTime;
    }

    int ProcessControlBlock::getPriority() const
    {
        return priority; 
    }

    bool ProcessControlBlock::operator<(const ProcessControlBlock& otherProcess) const
    {
        return burstTime < otherProcess.burstTime;
    }

    bool ProcessControlBlock::operator>(const ProcessControlBlock& otherProcess) const
    {
        return burstTime > otherProcess.burstTime;
    }
}