#include "Utility/TimeTracker.h"
#include "macros.h"
#include <iostream>

namespace Utility
{

    TimeTracker::TimeTracker()
    {
        overallTime = 0;
        currentTimeQuantum = 0;
    }

    TimeTracker& TimeTracker::getInstance()
    {
        static TimeTracker timeTracker;
        return timeTracker;
    }

    void TimeTracker::tick()
    {
        overallTime+=1;
        if (currentTimeQuantum >= QUEUE_TIME)
        {
            currentTimeQuantum = 0;
        }
        else
        {
            currentTimeQuantum+=1;
        }
    }

    int TimeTracker::getTime() const
    {
        return overallTime;
    }

    int TimeTracker::getCurrentTimeQuantum() const
    {
        return currentTimeQuantum;
    }

} // namespace Utility
