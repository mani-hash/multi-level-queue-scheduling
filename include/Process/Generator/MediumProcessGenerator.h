#ifndef MEDIUMPROCESSGENERATOR_H
#define MEDIUMPROCESSGENERATOR_H

#include <memory>
#include "ProcessGenerator.h"

namespace Process::Generator
{

    class MediumProcessGenerator: public ProcessGenerator
    {
        public:
            MediumProcessGenerator(std::shared_ptr<ProcessTable> processTable);

            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // MEDIUMPROCESSGENERATOR_H
