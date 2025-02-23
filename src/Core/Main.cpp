#include "Core/Main.h"

#include <memory>
#include <functional>
#include <map>
#include "macros.h"
#include "Utility/TimeTracker.h"
#include "SchedulerBridge/QueueAssigner.h"
#include "SchedulerBridge/ProcessAssigner.h"

namespace Core
{

    Main::Main(std::shared_ptr<Process::ProcessTable> processTable): processTable(processTable)
    {
        queues[0] = std::make_unique<Scheduler::RoundRobin>("Queue 0");
        queues[1] = std::make_unique<Scheduler::ShortestJobFirst>("Queue 1");
        queues[2] = std::make_unique<Scheduler::ShortestJobFirst>("Queue 2");
        queues[3] = std::make_unique<Scheduler::FirstInFirstOut>("Queue 3");
    }

    void Main::execute()
    {
        Utility::TimeTracker& time = Utility::TimeTracker::getInstance();
        SchedulerBridge::QueueAssigner queueAssigner;
        SchedulerBridge::ProcessAssigner processAssigner(processTable);

        int currentQueueIndex = 0;

        while (processTable->getTerminatedProcessCount() != processTable->getAllProcessCount())
        {
            std::vector<std::reference_wrapper<Process::ProcessControlBlock>> arrivedProcesses = 
                processAssigner.getArrivedProcesses();

            for (auto processIter = arrivedProcesses.begin(); processIter != arrivedProcesses.end(); ++processIter)
            {
                Process::ProcessControlBlock &process = processIter->get();
                queueAssigner.determineScheduler
                (
                    process,
                    dynamic_cast<Scheduler::RoundRobin&>(*queues[0]),
                    dynamic_cast<Scheduler::ShortestJobFirst&>(*queues[1]),
                    dynamic_cast<Scheduler::ShortestJobFirst&>(*queues[2]),
                    dynamic_cast<Scheduler::FirstInFirstOut&>(*queues[3])
                );
            }

            // get execution time until next new process arrives
            int executableTimeUntilNextProcess = 
                processAssigner.getTimeUntilNextProcessAssignment();

            int remainingTimeQuantum = QUEUE_TIME - time.getCurrentTimeQuantum();

            int executableTime = 0;

            if (executableTimeUntilNextProcess <= 0)
            {
                executableTime = QUEUE_TIME;
            }
            else
            {
                executableTime = executableTimeUntilNextProcess;

                 // change execution time if it exceeds the time quantum
                if (executableTime > remainingTimeQuantum)
                {
                    executableTime = remainingTimeQuantum;
                }
            }

            int executedTime = queues[currentQueueIndex]->execute(executableTime);

            int processId = queues[currentQueueIndex]->removeFromQueueIfComplete();

            if (processId >= 0)
            {
                processTable->incrementTerminatedProcessCount();
            }

            processTable->incrementWaitingTime(executedTime);

            if (executedTime + remainingTimeQuantum >= QUEUE_TIME || executedTime == 0)
            {
                queues[currentQueueIndex]->idleQueue();
                currentQueueIndex = (currentQueueIndex + 1) % 4;
            }

            time.setTime(executableTimeUntilNextProcess, executedTime);
        }        
    }

    void Main::displayQueueStatistics() const
    {
        std::map<std::string, float> averageWaitingTimes = processTable->getAverageWaitingTimes();
        std::map<std::string, float> averageTurnAroundTimes = processTable->getAverageTurnAroundTimes();
        
        std::cout << "Queue Statistics" << std::endl;
        
        std::cout << "Q0 - Round Robin Queue" << std::endl;

        std::cout 
            << "\t - Average Waiting time = " << averageWaitingTimes["q0"] / 1000.0
            << " seconds" << std::endl;
        std::cout 
            << "\t - Average Turn around time = " << averageTurnAroundTimes["q0"] /1000.0
            << " seconds" << std::endl;

        std::cout << "Q1 - Shortest Job First Queue" << std::endl;

        std::cout 
            << "\t - Average Waiting time = " << averageWaitingTimes["q1"] / 1000.0
            <<  " seconds" << std::endl;
        std::cout 
            << "\t - Average Turn around time = " << averageTurnAroundTimes["q1"] / 1000.0
            << " seconds" << std::endl;

        std::cout << "Q2 - Shortest Job First Queue" << std::endl;

        std::cout 
            << "\t - Average Waiting time = " << averageWaitingTimes["q2"] / 1000.0
            << " seconds" << std::endl;
        std::cout 
            << "\t - Average Turn around time = " << averageTurnAroundTimes["q2"] / 1000.0
            << " seconds" << std::endl;

        std::cout << "Q3 - First In First Out Queue" << std::endl;

        std::cout 
            << "\t - Average Waiting time = " << averageWaitingTimes["q3"] / 1000.0
            << " seconds" << std::endl;
        std::cout 
            << "\t - Average Turn around time = " << averageTurnAroundTimes["q3"] / 1000.0
            << " seconds" << std::endl;
    }

} // namespace Core
