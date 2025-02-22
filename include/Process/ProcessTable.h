#ifndef PROCESSTABLE_H
#define PROCESSTABLE_H

#include <vector>
#include "ProcessControlBlock.h"

namespace Process
{

    class ProcessTable 
    {
        private:
            std::vector<ProcessControlBlock> processes;

        public:
            void addProcess(const ProcessControlBlock& process);

            void removeProcess(int processId);

            ProcessControlBlock* getProcess(int processId);

            void sort();
    };

} // namespace Process

#endif // PROCESSTABLE_H
