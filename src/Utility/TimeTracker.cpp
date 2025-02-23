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

    void TimeTracker::setTime(int elapsedTime)
    {
        overallTime+=elapsedTime;

        currentTimeQuantum = (currentTimeQuantum + elapsedTime) % QUEUE_TIME;
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
