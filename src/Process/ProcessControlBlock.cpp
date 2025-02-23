#include <iostream>
#include "Process/ProcessControlBlock.h"

namespace Process
{
    ProcessControlBlock::ProcessControlBlock
    (
        int processId,
        ProcessState state,
        int priority,
        int arrivalTime,
        int burstTime,
        int waitingTime
    )
    {
        this->processId = processId;
        this->state = state;
        this->priority = priority;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->waitingTime = waitingTime;
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

    int ProcessControlBlock::getWaitingTime() const
    {
        return waitingTime;
    }

    void ProcessControlBlock::incrementWaitingTime()
    {
        waitingTime+=1;
    }

    int ProcessControlBlock::getBurstTime() const
    {
        return burstTime;
    }

    int ProcessControlBlock::getRemainingBurstTime() const
    {
        return remainingBurstTime;
    }

    void ProcessControlBlock::decrementRemainingBurstTime()
    {
        remainingBurstTime-=1;
    }

    int ProcessControlBlock::getPriority() const
    {
        return priority; 
    }

    bool ProcessControlBlock::operator<(const ProcessControlBlock& otherProcess) const
    {
        return remainingBurstTime < otherProcess.remainingBurstTime;
    }

    bool ProcessControlBlock::operator>(const ProcessControlBlock& otherProcess) const
    {
        return remainingBurstTime > otherProcess.remainingBurstTime;
    }

    ProcessState ProcessControlBlock::getState() const
    {
        return state;
    }

    void ProcessControlBlock::setState(ProcessState state)
    {
        this->state = state;
    }
}