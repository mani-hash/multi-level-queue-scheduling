#ifndef QUEUEASSIGNER_H
#define QUEUEASSIGNER_H

#include "Process/ProcessControlBlock.h"
#include "Scheduler/BaseScheduler.h"
#include "Scheduler/FirstInFirstOut.h"
#include "Scheduler/RoundRobin.h"
#include "Scheduler/ShortestJobFirst.h"

namespace SchedulerBridge
{

    class QueueAssigner 
    {
        public:
            static void determineScheduler
            (
                Process::ProcessControlBlock& process,
                Scheduler::RoundRobin& queue0,
                Scheduler::ShortestJobFirst& queue1,
                Scheduler::ShortestJobFirst& queue2,
                Scheduler::FirstInFirstOut& queue3
            );
    };

} // namespace SchedulerBridge

#endif // QUEUEASSIGNER_H
