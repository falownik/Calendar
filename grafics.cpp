#include <include/SFML/Graphics.hpp>
#include "grafics.hpp"
#include <iostream>

void CalendarGui::drawCalendar(int xx, int yy, int years)
{
    for (auto i = 0; i < 12 ; i++ )
        Window.draw(calendar[i].draw(1,x[i],y[i]));
}
Group CalendarWindow::draw (int day, int xx, int yy)
{
    Group group;
    this->setPosition(xx,yy);
    font.loadFromFile("arial.ttf");
    for (auto i = 0; i < 43; i++)
    {
        // Drawing Calendar's background
        /*
        rectangle[i].setPosition(sf::Vector2f(x_small[i], y_small[i]));
        if (i == 0)
            rectangle[i].setSize(sf::Vector2f(172, 26));
        else
            rectangle[i].setSize(sf::Vector2f(22, 22));
        if ((i % 2) == true)
            rectangle[i].setFillColor(sf::Color(89, 110, 90));
        else
            rectangle[i].setFillColor(sf::Color(10, 11, 150));
        group.push_back(rectangle[i]);
        */
        for (auto i = 0; i < 8; i++)
        {
         text[i].setFillColor(sf::Color::Yellow);
            text[i].setCharacterSize(17);
            text[i].setPosition(x_small[i], y_small[i]);
            text[i].setFont(font);
            group.push_back(text[i]);   
        }
        if (i > 6 && i < 37)
        {
            days[(i-6)].setFillColor(sf::Color::Yellow);
            days[(i-6)].setCharacterSize(17);
            days[(i-6)].setPosition(x_small[i], y_small[i]);
            days[(i-6)].setFont(font);
            group.push_back(days[(i-6)]);  
        }
    }
    return group;
}
void CalendarWindow::setPosition(int xx, int yy){
        x = xx;
        y = yy;
        x_small[0] = x + 10;
        y_small[0] = y;
        for (auto i = 1 ; i < 43 ; i++ )
            x_small[i] = x + ((i - 1) % 7) * 25 + 10;
        for (auto i = 1 ; i < 43 ; i++ )
            y_small[i] = y + ((i - 1) / 7) * 25 + 32;
        for (auto i = 0 ; i < 31 ; i++ )
            days[i].setString(std::to_string(i));
        void draw(int days);
        void setPosition(int xx, int yy);

};

Group::Group()
: m_drawables{} {

}

void Group::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(const auto& drawable : m_drawables) {
        target.draw(drawable, states);
    }
}

const sf::Drawable& Group::operator[](std::size_t index) {
    return m_drawables[index];
}

std::size_t Group::push_back(const sf::Drawable& drawable) {
    m_drawables.push_back(drawable);
    return m_drawables.size() - 1;
}

const sf::Drawable& Group::pop_back() {
    const auto& drawable = m_drawables.back();
    m_drawables.pop_back();
    return drawable;
}
