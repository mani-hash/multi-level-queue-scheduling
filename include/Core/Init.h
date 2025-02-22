#ifndef INIT_H
#define INIT_H

#include <memory>
#include "ProcessTable.h"

namespace Core
{

    class Init 
    {
        private:
            std::shared_ptr<Process::ProcessTable> processTable;

            Init();

            void initiateAllProcess();

            void initiateProcessTable();

        public:
            static Init& getInstance();

            Init(const Init&) = delete;
            Init& operator = (const Init&) = delete;

            std::shared_ptr<Process::ProcessTable> getProcessTable() const;
    };

} // namespace Core

#endif // INIT_H
