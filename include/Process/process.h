#ifndef PROCESS_H
#define PROCESS_H

namespace Process
{
    typedef struct PriorityRange
    {
        int min;
        int max;
    } PriorityRange;

    const PriorityRange Q0 = { -20, -10};
    const PriorityRange Q1 = { -9, 0 };
    const PriorityRange Q2 = { 1, 10 };
    const PriorityRange Q3 = { 11, 20 }; 
}

#endif // PROCESS_H