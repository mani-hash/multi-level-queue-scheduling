#ifndef LOWESTPROCESSGENERATOR_H
#define LOWESTPROCESSGENERATOR_H

#include <memory>
#include "Process/Generator/ProcessGenerator.h"

namespace Process::Generator
{

    class LowestProcessGenerator: public ProcessGenerator
    {
        public:
            LowestProcessGenerator(std::shared_ptr<ProcessTable> processTable);
            
            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // LOWESTPROCESSGENERATOR_H
