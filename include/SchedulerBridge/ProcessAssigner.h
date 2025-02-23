#ifndef PROCESSASSIGNER_H
#define PROCESSASSIGNER_H

#include <memory>
#include "Process/ProcessTable.h"

namespace SchedulerBridge
{

    class ProcessAssigner 
    {
        private:
            const std::shared_ptr<Process::ProcessTable> processTable;

            static int nextProcessIndex;
        public:
            ProcessAssigner(std::shared_ptr<Process::ProcessTable> processTable);

            std::vector<std::reference_wrapper<Process::ProcessControlBlock>>
                getArrivedProcesses() const;

            int getTimeUntilNextProcessAssignment() const;
    };

} // namespace SchedulerBridge

#endif // PROCESSASSIGNER_H
