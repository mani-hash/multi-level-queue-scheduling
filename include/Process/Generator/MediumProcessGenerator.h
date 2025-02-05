#ifndef MEDIUMPROCESSGENERATOR_H
#define MEDIUMPROCESSGENERATOR_H

#include "ProcessGenerator.h"

namespace Process::Generator
{

    class MediumProcessGenerator: public ProcessGenerator
    {
        public:
            MediumProcessGenerator();

            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // MEDIUMPROCESSGENERATOR_H
