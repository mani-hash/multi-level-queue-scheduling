#include "Scheduler/RoundRobin.h"
#include "Process/ProcessControlBlock.h"
#include <iostream>
#include "macros.h"

namespace Scheduler
{
    RoundRobin::RoundRobin(std::string queueName)
    {
        this->queueName = queueName;
        this->currentTimeQuantum = 0;
    }

    bool RoundRobin::shouldPreempt()
    {
        if (!queue.empty() && currentTimeQuantum >= TIME_QUANTUM)
        {
            return true;
        }

        return false;
    }

    void RoundRobin::applyPreemption()
    {
        if (queue.empty())
        {
            return;
        }

        Process::ProcessControlBlock& process = queue.front().get();
        process.setState(Process::WAITING);
        queue.pop();
        queue.push(std::ref(process));
    }

    void RoundRobin::addToQueue(Process::ProcessControlBlock &process)
    {
        process.setState(Process::WAITING);
        queue.push(std::ref(process));
    }

    int RoundRobin::removeFromQueueIfComplete()
    {
        if (queue.empty())
        {
            return -1;
        }

        Process::ProcessControlBlock& process = queue.front().get();
        int processId = -1;

        if (process.getRemainingBurstTime() <= 0)
        {
            process.setState(Process::COMPLETE);
            processId = process.getProcessId();
            queue.pop();
        }

        return processId;
    }

    void RoundRobin::execute()
    {
        if (queue.empty())
        {
            return;
        }

        if (shouldPreempt())
        {
            applyPreemption();
        }

        Process::ProcessControlBlock& process = queue.front().get();
        process.setState(Process::ACTIVE);

        process.decrementRemainingBurstTime();

        currentTimeQuantum+=1;
    }

    void RoundRobin::idleQueue()
    {
        if (queue.empty())
        {
            return;
        }

        queue.front().get().setState(Process::WAITING);
    }
    
}