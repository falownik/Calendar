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
int year = 2018;
CalendarGui cal(1600,800,year); 
cal.ReadEvent();
Button buttonAddEvent;
Button buttonIncrementYear;
Button buttonDecrementYear;
Button buttonUpdateEvent;
buttonUpdateEvent.setButton(1200,20, 60, 50,"update\nevent");
buttonAddEvent.setButton(1300,20, 50, 50,"add\nevent");
buttonIncrementYear.setButton(1500, 20, 80, 50,"next");
buttonDecrementYear.setButton(1400,20, 80, 50,"previous");
cal.printEvent();

while (cal.Window.isOpen())
{
    sf::Event event;
    while (cal.Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            cal.Window.close();

        switch (event.type)
        {
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (event.mouseButton.x > buttonDecrementYear.x && event.mouseButton.x < buttonDecrementYear.x + buttonDecrementYear.width)
                    if (event.mouseButton.y > buttonDecrementYear.y && event.mouseButton.y < buttonDecrementYear.y + buttonDecrementYear.height)
                        year--;

                if (event.mouseButton.x > buttonIncrementYear.x && event.mouseButton.x < buttonIncrementYear.x + buttonIncrementYear.width)
                    if (event.mouseButton.y > buttonIncrementYear.y && event.mouseButton.y < buttonIncrementYear.y + buttonIncrementYear.height)
                        year++;

                if (event.mouseButton.x > buttonAddEvent.x && event.mouseButton.x < buttonAddEvent.x + buttonAddEvent.width)
                    if (event.mouseButton.y > buttonAddEvent.y && event.mouseButton.y < buttonAddEvent.y + buttonAddEvent.height)
                    {
                        cal.addEvent();
                    }
                if (event.mouseButton.x > buttonUpdateEvent.x && event.mouseButton.x < buttonUpdateEvent.x + buttonUpdateEvent.width)
                    if (event.mouseButton.y > buttonUpdateEvent.y && event.mouseButton.y < buttonUpdateEvent.y + buttonUpdateEvent.height)
                    {
                        cal.updateEvent();
                    }
            }
            break;
            /*
            case sf::Event::KeyPressed:
                if (sf::Event::KeyEvent::alt)
                ;
                break;
                */
            default:
                break;
        }


    }
    cal.Window.clear();
    for(unsigned int i = 0; i < cal.event.size(); i++)
        cal.Window.draw(cal.event[i].group);
    cal.Window.draw(buttonDecrementYear.group);
    cal.Window.draw(buttonAddEvent.group);
    cal.Window.draw(buttonUpdateEvent.group);
    cal.Window.draw(buttonIncrementYear.group);
    cal.drawCalendar(1600, 800, year);
}
}