#ifndef HIGHPROCESSGENERATOR_H
#define HIGHPROCESSGENERATOR_H

#include <memory>
#include "ProcessGenerator.h"

namespace Process::Generator
{

    class HighProcessGenerator: public ProcessGenerator
    {
        public:
            HighProcessGenerator(std::shared_ptr<ProcessTable> processTable);
            
            void getProcessCountFromUser() override;
    };

} // namespace Process::Generator

#endif // HIGHPROCESSGENERATOR_H
