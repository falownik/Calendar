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
    std::vector <int> x_small = std::vector <int> (43);
    std::vector <int> y_small = std::vector <int> (43);
    std::vector <sf::Text> days = std::vector <sf::Text> (31);
    std::vector <sf::RectangleShape> rectangle = std::vector <sf::RectangleShape>(43);
    std::vector <sf::Text> text = std::vector <sf::Text>(8);
    sf::Font font;
    sf::RenderWindow Window;
    CalendarWindow (int xx = 100, int yy = 100, std::string mm = "none")
    {
        x = xx;
        y = yy;
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
        for (auto i = 1 ; i < 43 ; i++ )
            x_small[i] = x + ((i - 1) % 7) * 25 + 10;
        for (auto i = 1 ; i < 43 ; i++ )
            y_small[i] = y + ((i - 1) / 7) * 25 + 32;  

        for (auto i = 0 ; i < 31 ; i++ )
            days[i].setString(std::to_string(i));
        }
        void draw(int days);

};
class CalendarGui
{
public:
    std::vector <int> x = std::vector <int>(12);
    std::vector <int> y = std::vector <int>(12);
    std::vector <sf::RectangleShape> rectangle = std::vector <sf::RectangleShape>(12);
    std::vector <sf::Text> text = std::vector <sf::Text>(12);
    std::vector <CalendarWindow> calendar = std::vector <CalendarWindow>(12);
    sf::Font font;
    int year;
    sf::RenderWindow Window;
    CalendarGui(int xx,int yy, int years = 2018)
    {
        for ( auto i = 0 ; i < 12 ; i++ )
        {
            x[i] = ((i/3)+1)*(xx - 838);
            for ( auto k = 0 ; k < 32 ; k++ )
            {
                std::vector <int> x_temp = std::vector <int>(32);
                x_temp[k] = x[i] + ((k/6)+1) ;
            }
            
        }
        for ( auto i = 0 ; i < 12 ; i++ )
            y[i] = ((i%3)+1)*(yy - 630);
    Window.create(sf::VideoMode(1024, 762), "Calendar");
    }
    void drawCalendar(int xx, int yy, int years);
};
