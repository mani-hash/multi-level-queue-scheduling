#include <iostream>
#include <queue>
#include "Scheduler/FirstInFirstOut.h"
#include "Process/ProcessControlBlock.h"
#include "Utility/TimeTracker.h"

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

    void FirstInFirstOut::execute()
    {
        if (queue.empty())
        {
            return;
        }

        Process::ProcessControlBlock& process = queue.front().get();
        process.setState(Process::ACTIVE);
        process.decrementRemainingBurstTime();
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