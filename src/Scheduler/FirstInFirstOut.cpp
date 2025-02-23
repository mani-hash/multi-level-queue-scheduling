#include <iostream>
#include <queue>
#include "macros.h"
#include "Scheduler/FirstInFirstOut.h"
#include "Process/ProcessControlBlock.h"

namespace Scheduler
{
    FirstInFirstOut::FirstInFirstOut(std::string queueName)
    {
        this->queueName = queueName;
    }

    void FirstInFirstOut::addToQueue(Process::ProcessControlBlock& process)
    {
        process.setState(Process::WAITING);
        queue.push(std::ref(process));
    }

    int FirstInFirstOut::removeFromQueueIfComplete()
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

    int FirstInFirstOut::execute(int executableTime)
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

        Process::ProcessControlBlock& process = queue.front().get();
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

    void FirstInFirstOut::idleQueue()
    {
        if (queue.empty())
        {
            return;
        }

        queue.front().get().setState(Process::WAITING);
    }
}