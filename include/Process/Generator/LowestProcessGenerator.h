#ifndef LOWESTPROCESSGENERATOR_H
#define LOWESTPROCESSGENERATOR_H

#include "ProcessGenerator.h"

namespace Process::Generator
{

    class LowestProcessGenerator: public ProcessGenerator
    {
        public:
            LowestProcessGenerator();
            
            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // LOWESTPROCESSGENERATOR_H
