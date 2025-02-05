#ifndef PROCESSGENERATOR_H
#define PROCESSGENERATOR_H

#include "process.h"
#include "ProcessControlBlock.h"
#include "RandomNumberGenerator.h"

namespace Process::Generator
{

    class ProcessGenerator 
    {
        protected:
            int noOfProcesses = 0;
            PriorityRange priorityRange;
            Utility::RandomNumberGenerator rng;

        public:
            ProcessGenerator(const PriorityRange priorityRange);

            virtual void getProcessCountFromUser();

            int getPriorityForProcess();

            ProcessControlBlock* createProcess(int priorityLevel);
    };

} // namespace Process::Generator

#endif // PROCESSGENERATOR_H
