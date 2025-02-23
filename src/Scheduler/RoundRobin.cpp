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
        if (!queue.empty() && currentTimeQuantum >= maxTimeQuantum)
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

    int RoundRobin::execute(int executableTime)
    {
        int executedTime = 0;

        // throw error if executable time is greater than time quantum
        if (executableTime > QUEUE_TIME)
        {
            throw new std::invalid_argument("Executable time cannot be greater than time quantum");
        }

        if (queue.empty())
        {
            return executedTime;
        }

        if (shouldPreempt())
        {
            applyPreemption();
        }

        Process::ProcessControlBlock& process = queue.front().get();
        process.setState(Process::ACTIVE);

        int remainingBurstTime = process.getRemainingBurstTime();
        int remainingQuantumTime = maxTimeQuantum - currentTimeQuantum;

        // calculate the time which is allowed for this process
        // each process is contrained by roud robin time quantum
        int availableTime = remainingBurstTime > remainingQuantumTime ?
            remainingQuantumTime : remainingBurstTime;
        
        if (executableTime > availableTime)
        {
            executedTime = availableTime;
        }
        else
        {
            executedTime = executableTime;
        }

        process.setRemainingBurstTime(executedTime);

        currentTimeQuantum = (currentTimeQuantum + executedTime) % maxTimeQuantum;

        return executedTime;
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