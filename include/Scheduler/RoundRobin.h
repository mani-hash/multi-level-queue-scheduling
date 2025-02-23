#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <queue>
#include <iostream>
#include <functional>
#include "Scheduler/BaseScheduler.h"
#include "Process/ProcessControlBlock.h"

namespace Scheduler
{
    class RoundRobin : public BaseScheduler
    {
        private:
            std::queue<std::reference_wrapper<Process::ProcessControlBlock>> queue;

            int currentTimeQuantum;

            bool shouldPreempt();

            void applyPreemption();

        public:
            RoundRobin(std::string queueName);

            void addToQueue(Process::ProcessControlBlock& process);

            int removeFromQueueIfComplete();

            void execute();

            void idleQueue();
    };
}

#endif