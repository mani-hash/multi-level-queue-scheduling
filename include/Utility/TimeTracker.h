#ifndef TIMETRACKER_H
#define TIMETRACKER_H

namespace Utility
{

    class TimeTracker 
    {
        private:
            int overallTime;
            int currentTimeQuantum;

            TimeTracker();
        public:
            static TimeTracker& getInstance();

            TimeTracker(const TimeTracker&) = delete;
            TimeTracker& operator = (const TimeTracker&) = delete;
            
            void tick();

            int getTime() const;

            int getCurrentTimeQuantum() const;

    };

} // namespace Utility

#endif // TIMETRACKER_H
