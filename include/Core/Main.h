#ifndef MAIN_H
#define MAIN_H

#include <memory>
#include "Process/ProcessTable.h"
#include "Scheduler/BaseScheduler.h"
#include "Scheduler/FirstInFirstOut.h"
#include "Scheduler/RoundRobin.h"
#include "Scheduler/ShortestJobFirst.h"

namespace Core
{

    class Main 
    {
        private:
            std::shared_ptr<Process::ProcessTable> processTable;

            std::unique_ptr<Scheduler::BaseScheduler> queues[4];

        public:
            Main(std::shared_ptr<Process::ProcessTable> processTable);

            void execute();

            void displayQueueStatistics() const;
    };

} // namespace Core

#endif // MAIN_H
