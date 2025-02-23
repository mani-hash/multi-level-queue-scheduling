#include <iostream>
#include "Core/Init.h"
#include "Core/Main.h"
#include "Utility/TimeTracker.h"

int main()
{
    Core::Init& Init = Core::Init::getInstance();
    Utility::TimeTracker& time = Utility::TimeTracker::getInstance();
    Core::Main main(Init.getProcessTable());

    main.execute();
    return 0;
}