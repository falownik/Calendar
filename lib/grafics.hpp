#include <include/SFML/Graphics.hpp>
#include <Calendar.hpp>
#include <iostream>
#include <string>

#ifndef GROUP_INCLUDED_HPP
#define GROUP_INCLUDED_HPP

#include <vector>
#include <functional>

class Group : public sf::Drawable {
public:
    Group();
    virtual ~Group() = default;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const sf::Drawable& operator[](std::size_t index);
    std::size_t push_back(const sf::Drawable& drawable);
    const sf::Drawable& pop_back();

private:
    std::vector<std::reference_wrapper<const sf::Drawable>> m_drawables;
};

#endif

class CalendarWindow
{
    public:
    int x;
    int y;
    int tileSizeX = 22, tileSizeY = 22;
    std::vector <int> x_small = std::vector <int> (50);
    std::vector <int> y_small = std::vector <int> (50);
    std::vector <sf::Text> days = std::vector <sf::Text> (32);
    std::vector <sf::RectangleShape> rectangle = std::vector <sf::RectangleShape>(50);
    std::vector <sf::Text> text = std::vector <sf::Text>(8);
    sf::Font font;
    Group group;
    sf::RenderWindow Window;
    CalendarWindow (int xx = 100, int yy = 100, std::string mm = "none")
    {
        x = xx;
        y = yy;
        font.loadFromFile("arial.ttf");
        for (auto i = 0 ; i < 8 ; i++)
            text[i].setFont(font);

        text[0].setString(mm);
        text[1].setString("Mo");
        text[2].setString("Tu");
        text[3].setString("We");
        text[4].setString("Th");
        text[5].setString("Fr");
        text[6].setString("Sa");
        text[7].setString("Su");

        x_small[0] = x + 10;
        y_small[0] = y;
        for (auto i = 1 ; i < 50 ; i++ )
            x_small[i] = x + ((i - 1) % 7) * 25 + 10;
        for (auto i = 1 ; i < 50 ; i++ )
            y_small[i] = y + ((i - 1) / 7) * 25 + 32;  

        for (auto i = 0 ; i < 32 ; i++ )
            days[i].setString(std::to_string(i));
        }
        Group draw(int firstDay, int numberOfDays, int xx, int yy);
        void setPosition(int xx, int yy);
        void setMonth(int year, int month);

};
class CalendarGui
{
public:
    std::vector <int> x = std::vector <int>(12);
    std::vector <int> y = std::vector <int>(12);
    std::vector <CalendarWindow> calendar = std::vector <CalendarWindow>(12);
    sf::Text yearString;
    sf::Font font;
    Calendar calDate;
    int year;
    sf::RenderWindow Window;
    CalendarGui(int xx,int yy, int years = 2018)
    {
        for ( auto i = 0 ; i < 12 ; i++ )
            x[i] = ((i%4)+1)*(int(0.112*xx)) + 600;

        for ( auto i = 0 ; i < 12 ; i++ )
            y[i] = ((i/4)+1)*(int(0.26*yy)) - 100;

        Window.create(sf::VideoMode(xx, yy), "Calendar");
        Window.setFramerateLimit(30);
    }
    void setYear(int year);
    void drawCalendar(int xx, int yy, int years);
    void addEvent();
    Calendar getDate(sf::Vector2i);
};
class Button 
{
public:
   sf::Texture image;
   sf::Text text; 
   sf::Font font;
   sf::RectangleShape rectangle;
   Group group;
   int x, y;
   int width, height;
   Button(){}
   void setButton(int xx, int yy, int width, int height, std::string name);
};
class NotificationGui
{
public:
    sf::RectangleShape rectangle;
    sf::Text title, info, date;
    Event envent;
    int x, y;
    int width, height;
    NotificationGui(){}
    void setNotification(Calendar date, Time time, std::string title, std::string info);
    void updateDate(Calendar date);
    void updateTime(Time time);
    void updateTitle(std::string title);
    void updateInfo(std::string info);
};