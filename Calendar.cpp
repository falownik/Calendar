#include <iostream>
#include <ctime>
#include "Calendar.hpp"

int main (void)
{
    Calendar cal(2010,1);
    std::cout << cal.dayOfWeek;
    return 0;
}