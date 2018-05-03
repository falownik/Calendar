#include <iostream>
#include <ctime>
#include "grafics.hpp"
#include "SFML/Graphics.hpp"

int Calendar::getFirstDay(int m)
{
    tm timeStruct = {};
        timeStruct.tm_year = year - 1900;
        timeStruct.tm_mon = m - 1;
        timeStruct.tm_mday = 1;
        timeStruct.tm_hour = 6;
        mktime( &timeStruct );
        return timeStruct.tm_wday;
    }
    int Calendar::getNumberOfDays(int month)
    {
        return daysInMonth[month];
    }
    void Calendar::setYear(int y)
    {
                //Set year
        year = y;
        //Set number of days except February
        daysInMonth[0] = 0;
        daysInMonth[1] = 31;
        daysInMonth[3] = 31;
        daysInMonth[4] = 30;
        daysInMonth[5] = 31;
        daysInMonth[6] = 30;
        daysInMonth[7] = 31;
        daysInMonth[8] = 31;
        daysInMonth[9] = 30;
        daysInMonth[10] = 31;
        daysInMonth[11] = 30;
        daysInMonth[12] = 31;
        //Set number of days od February in term of leap year
        if (((y%4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
            daysInMonth[2] = 29;
        else
            daysInMonth[2] = 28;
        //Set names of months
        nameOfMonth[0] = "not a month";
        nameOfMonth[1] =  "January";
        nameOfMonth[2] =  "February";
        nameOfMonth[3] =  "March";
        nameOfMonth[4] = "April";
        nameOfMonth[5] = "May";
        nameOfMonth[6] = "June";
        nameOfMonth[7] = "July";
        nameOfMonth[8] = "August";
        nameOfMonth[9] = "September";
        nameOfMonth[10] = "October";
        nameOfMonth[11] = "November";
        nameOfMonth[12] = "December";
    }
int main (void)
{

CalendarGui cal(1600,800,2018); 
Calendar calendar (2018,2);
while (cal.Window.isOpen())
{
   sf::Event event;
   while (cal.Window.pollEvent(event))
   {
       if (event.type == sf::Event::Closed)
            cal.Window.close();

        if (event.type == sf::Event::MouseButtonPressed)
{
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
    }
}
        }
        cal.Window.clear();
        cal.drawCalendar(1024,768,2018);

}
}