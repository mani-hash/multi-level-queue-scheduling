#ifndef PROCESS_BLOCK_H
#define PROCESS_BLOCK_H

#include <string>

namespace Process
{
    enum ProcessState
    {
        READY,
        ACTIVE,
        WAITING,
        COMPLETE,
    };

    class ProcessControlBlock
    {
        private:
            int processId;
            ProcessState state;
            int priority;
            int arrivalTime;
            int burstTime;
            int waitingTime;
            int remainingBurstTime;

        public:
            ProcessControlBlock
            (
                int processId,
                ProcessState state,
                int priority,
                int arrivalTime,
                int burstTime,
                int waitingTime
            );

            int getProcessId() const;

            int getArrivalTime() const;

            int getBurstTime() const;

            int getWaitingTime() const;

            void setWaitingTime(int elapsedTime);

            int getRemainingBurstTime() const;

            void setRemainingBurstTime(int elapsedTime);

            int getPriority() const;

            bool operator>(const ProcessControlBlock& otherProcess) const;

            bool operator<(const ProcessControlBlock& otherProcess) const;

            ProcessState getState() const;

            void setState(ProcessState state);

    };
}

#endif