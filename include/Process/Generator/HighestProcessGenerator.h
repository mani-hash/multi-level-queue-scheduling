#ifndef HIGHESTPROCESSGENERATOR_H
#define HIGHESTPROCESSGENERATOR_H

#include "ProcessGenerator.h"

namespace Process::Generator
{

    class HighestProcessGenerator: public ProcessGenerator
    {
        public:
            HighestProcessGenerator();
            
            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // HIGHESTPROCESSGENERATOR_H
