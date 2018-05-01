#include <iostream>
#include <ctime>
#include <stdexcept>

class Calendar 
{
    public:
    int day, days, month, year, dayOfWeek;
    bool isLeap;
    Calendar (int y, int m, int d = 1)
    {
        if (m > 0 && m < 13)
            month = m;
        else 
            throw std::out_of_range("there's no such month");

        if (((y%4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
            isLeap == true;
        else
            isLeap = false;
        
        if ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 )
            days == 31;
        else if ( m == 4 || m == 6 || m == 9 || m == 11)
            days = 30;
        else if (m == 2 && isLeap == true)
            days = 29;
        else 
            days = 28;

        tm timeStruct = {};
        timeStruct.tm_year = y - 1900;
        timeStruct.tm_mon = m - 1;
        timeStruct.tm_mday = d;
        timeStruct.tm_hour = 12;
        mktime( &timeStruct );
        dayOfWeek = timeStruct.tm_wday;
        

    }


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
