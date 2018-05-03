#include <iostream>
#include <ctime>
#include <stdexcept>

class Calendar 
{
public:
    std::vector <int> daysInMonth = std::vector <int> (13);
    std::vector <std::string> nameOfMonth = std::vector <std::string> (13);
    int day, days, month, year, dayOfWeek;
    bool isLeap;
    Calendar(){}
    Calendar (int y, int d = 1)
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
    int getFirstDay(int m);
    int getNumberOfDays(int month);
    void setYear(int y);


};

class Time
{
    public:
    int minute, hour;
    Time(int m = 0, int h = 0)
    {
        if (m >= 0 && m <=59)
            minute = m;
        else
            throw std::out_of_range("not a time");

        if (h >= 0 && h <=59)
            hour = h;
            else
            throw std::out_of_range("not a time");
            
    }
};
class Events
{
 Calendar date;
 Time time;
 std::string title, info;
};
