#ifndef PROCESSTABLE_H
#define PROCESSTABLE_H

#include <vector>
#include "Process/ProcessControlBlock.h"

namespace Process
{

    class ProcessTable 
    {
        private:
            std::vector<ProcessControlBlock> processes;
            int terminatedProcess;

        public:
            void addProcess(const ProcessControlBlock& process);

            void removeProcess(int processId);

            ProcessControlBlock* getProcess(int processId);

            void sort();

            const std::vector<ProcessControlBlock>& getProcessList() const;

            int getTerminatedProcessCount() const;

            void incrementTerminatedProcessCount();

            int getAllProcessCount() const;

            void incrementWaitingTime();
    };

} // namespace Process

#endif // PROCESSTABLE_H
