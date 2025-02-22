#include "SchedulerBridge/QueueAssigner.h"

#include "Process/process.h"

namespace SchedulerBridge
{
    void QueueAssigner::determineScheduler
    (
        Process::ProcessControlBlock& process,
        Scheduler::RoundRobin& queue0,
        Scheduler::ShortestJobFirst& queue1,
        Scheduler::ShortestJobFirst& queue2,
        Scheduler::FirstInFirstOut& queue3
    )
    {
        int priority = process.getPriority();
        if (priority >= Process::Q0.min && priority <= Process::Q0.max)
        {
            queue0.addToQueue(process);
        }
        else if (priority >= Process::Q1.min && priority <= Process::Q1.max) 
        {
            queue1.addToQueue(process);
        }
        else if (priority >= Process::Q2.min && priority <= Process::Q2.max)
        {
            queue2.addToQueue(process);
        }
        else if (priority >= Process::Q3.min && priority <= Process::Q3.max)
        {
            queue3.addToQueue(process);
        }
    }

} // namespace SchedulerBridge
