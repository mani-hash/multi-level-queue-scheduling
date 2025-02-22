#ifndef PROCESSGENERATOR_H
#define PROCESSGENERATOR_H

#include <memory>
#include "Process/process.h"
#include "Process/ProcessControlBlock.h"
#include "Process/ProcessTable.h"
#include "Utility/RandomNumberGenerator.h"

namespace Process::Generator
{

    class ProcessGenerator 
    {
        private:
            std::shared_ptr<ProcessTable> processTable;

            static int processIdCounter;

            int getPriorityForProcess();

            int generateProcessId();

            int generateArrivalTime();

            int generateBurstTime();

            ProcessControlBlock createProcess(int priorityLevel);

        protected:
            int noOfProcesses = 0;
            PriorityRange priorityRange;
            Utility::RandomNumberGenerator rng;

        public:
            ProcessGenerator(const PriorityRange priorityRange, std::shared_ptr<ProcessTable> processTable);

            virtual void getProcessCountFromUser();

            void generate();
    };

} // namespace Process::Generator

#endif // PROCESSGENERATOR_H
