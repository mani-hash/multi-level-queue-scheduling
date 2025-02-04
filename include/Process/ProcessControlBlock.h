#ifndef PROCESS_BLOCK_H
#define PROCESS_BLOCK_H

#include <string>

namespace Process
{
    class ProcessControlBlock
    {
        private:
            int processId;
            std::string state;
            int priority;
            int arrivalTime;
            int burstTime;
            int remainingBurstTime;

        public:
            ProcessControlBlock
            (
                int processId,
                std::string state,
                int priority,
                int arrivalTime,
                int burstTime
            );

            int getProcessId() const;

            int getBurstTime() const;

            int getRemainingBurstTime() const;

            void setRemainingBurstTime(int elapsedTime);

    };
}

#endif