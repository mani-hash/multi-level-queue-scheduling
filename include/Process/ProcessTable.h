#ifndef PROCESSTABLE_H
#define PROCESSTABLE_H

#include <vector>
#include <map>
#include "Process/ProcessControlBlock.h"

namespace Process
{

    class ProcessTable 
    {
        private:
            std::vector<ProcessControlBlock> processes;
            int terminatedProcess;

        public:
            ProcessTable();

            void addProcess(const ProcessControlBlock& process);

            void removeProcess(int processId);

            ProcessControlBlock* getProcess(int processId);

            void sort();

            const std::vector<ProcessControlBlock>& getProcessList() const;

            int getTerminatedProcessCount() const;

            void incrementTerminatedProcessCount();

            int getAllProcessCount() const;

            void incrementWaitingTime(int elapsedTime);

            std::map<std::string, float> getAverageWaitingTimes() const;

            std::map<std::string, float> getAverageTurnAroundTimes() const;
    };

} // namespace Process

#endif // PROCESSTABLE_H
