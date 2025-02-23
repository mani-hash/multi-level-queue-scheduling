#ifndef SHORTEST_JOB_FIRST_H
#define SHORTEST_JOB_FIRST_H

#include <iostream>
#include <queue>
#include <functional>
#include "Process/ProcessControlBlock.h"
#include "Scheduler/BaseScheduler.h"

namespace Scheduler
{
    typedef struct ReferenceProcessComparator {
        bool operator()
        (
            const std::reference_wrapper<Process::ProcessControlBlock>& processLeft,
            const std::reference_wrapper<Process::ProcessControlBlock>& processRight
        ) const
        {
            return processLeft.get().getRemainingBurstTime() > processRight.get().getRemainingBurstTime();
        }
    } ReferenceProcessComparator;

    class ShortestJobFirst : public BaseScheduler
    {
        private:
            std::priority_queue
            <
                std::reference_wrapper<Process::ProcessControlBlock>,
                std::vector<std::reference_wrapper<Process::ProcessControlBlock>>,
                ReferenceProcessComparator
            > queue;

            bool shouldPreempt(Process::ProcessControlBlock &process);

        public:
            ShortestJobFirst(std::string queueName);

            void addToQueue(Process::ProcessControlBlock& process);

            int removeFromQueueIfComplete();

            void execute();

            void idleQueue();
    };
}

#endif