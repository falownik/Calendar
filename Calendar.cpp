#include <iostream>
#include <ctime>
#include "grafics.hpp"
#include "SFML/Graphics.hpp"

int main (void)
{

CalendarGui cal(1600,800,2018); 
cal.drawCalendar(1024,768,2018);
sf::Font font;
sf::Text text;
    font.loadFromFile("arial.ttf");
    text.setString("Okurwa");
         text.setFillColor(sf::Color::Yellow);
            text.setCharacterSize(50);
            text.setPosition(100, 100);
            text.setFont(font); 
while (cal.Window.isOpen())
{
   sf::Event event;
   while (cal.Window.pollEvent(event))

   {
       if (event.type == sf::Event::Closed)
            cal.Window.close();
        }
        cal.Window.clear();
        cal.Window.draw(text);
        cal.drawCalendar(1024,768,2018);
        cal.Window.display();
}
}