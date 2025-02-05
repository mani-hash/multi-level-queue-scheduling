#ifndef HIGHPROCESSGENERATOR_H
#define HIGHPROCESSGENERATOR_H

#include "ProcessGenerator.h"

namespace Process::Generator
{

    class HighProcessGenerator: public ProcessGenerator
    {
        public:
            HighProcessGenerator();
            
            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // HIGHPROCESSGENERATOR_H
