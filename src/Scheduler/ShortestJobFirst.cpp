#include "Scheduler/ShortestJobFirst.h"
#include "macros.h"
#include <iostream>

namespace Scheduler
{
    ShortestJobFirst::ShortestJobFirst(std::string queueName)
    {
        this->queueName = queueName;
    }

    bool ShortestJobFirst::shouldPreempt(Process::ProcessControlBlock &process)
    {
        Process::ProcessControlBlock& currentProcess = queue.top().get();

        if (currentProcess.getRemainingBurstTime() > process.getRemainingBurstTime())
        {
            return true;
        }

        return false;
    }

    void ShortestJobFirst::addToQueue(Process::ProcessControlBlock &process)
    {
        if (!queue.empty() && shouldPreempt(process))
        {
            queue.top().get().setState(Process::WAITING);
            process.setState(Process::ACTIVE);
        }
        else
        {
            process.setState(Process::WAITING);
        }

        queue.push(std::ref(process));
    }

    int ShortestJobFirst::removeFromQueueIfComplete()
    {
        if (queue.empty())
        {
            return -1;
        }

        Process::ProcessControlBlock& process = queue.top().get();
        int processId = -1;

        if (process.getRemainingBurstTime() <= 0)
        {
            process.setState(Process::COMPLETE);
            processId = process.getProcessId();
            queue.pop();
        }

        return processId;
    }

    int ShortestJobFirst::execute(int executableTime)
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

        Process::ProcessControlBlock& process = queue.top().get();
        process.setState(Process::ACTIVE);

        int remainingBurstTime = process.getRemainingBurstTime();
        
        if (executableTime > remainingBurstTime)
        {
            executedTime = remainingBurstTime;
        }
        else
        {
            executedTime = executableTime;
        }

        process.setRemainingBurstTime(executedTime);

        return executedTime;
    }

    void ShortestJobFirst::idleQueue()
    {
        if (queue.empty())
        {
            return;
        }

        queue.top().get().setState(Process::WAITING);
    }
}