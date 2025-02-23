#ifndef FIRST_IN_FIRST_OUT_H
#define FIRST_IN_FIRST_OUT_H

#include <iostream>
#include <queue>
#include "Process/ProcessControlBlock.h"
#include "Scheduler/BaseScheduler.h"
#include <functional>

namespace Scheduler
{
    class FirstInFirstOut : public BaseScheduler
    {
        private:
            std::queue<std::reference_wrapper<Process::ProcessControlBlock>> queue;

        public:
            FirstInFirstOut(std::string queueName);

            void addToQueue(Process::ProcessControlBlock& process);

            int removeFromQueueIfComplete();

            void execute();

            void idleQueue();
    };
}

#endif