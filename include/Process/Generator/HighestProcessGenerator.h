#ifndef HIGHESTPROCESSGENERATOR_H
#define HIGHESTPROCESSGENERATOR_H

#include <memory>
#include "Process/Generator/ProcessGenerator.h"

namespace Process::Generator
{

    class HighestProcessGenerator: public ProcessGenerator
    {
        public:
            HighestProcessGenerator(std::shared_ptr<ProcessTable> processTable);
            
            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // HIGHESTPROCESSGENERATOR_H
