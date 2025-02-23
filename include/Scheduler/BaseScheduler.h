#ifndef BASESCHEDULER_H
#define BASESCHEDULER_H

#include <iostream>
#include "Process/ProcessControlBlock.h"

namespace Scheduler
{

    class BaseScheduler 
    {
        protected:
            std::string queueName;
        public:
            virtual ~BaseScheduler() = default;
            
            virtual void addToQueue(Process::ProcessControlBlock& process) = 0;

            virtual int removeFromQueueIfComplete() = 0;

            virtual int execute(int executableTime) = 0;

            virtual void idleQueue() = 0;
    };

} // namespace Scheduler

#endif // BASESCHEDULER_H
