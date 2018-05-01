#include <iostream>
#include <ctime>
#include "grafics.hpp"
#include "SFML/Graphics.hpp"

int main (void)
{
sf::RenderWindow Window;
Group grupa;
sf::RectangleShape rectangle;
rectangle.setPosition(100,100);
rectangle.setSize(sf::Vector2f(100,100));
rectangle.setFillColor(sf::Color::Red);
grupa.push_back(rectangle);
Window.create(sf::VideoMode(1024, 762), "Calendar");
//CalendarGui cal(1024,768,2018); 
//CalendarWindow s(100,100,"Jan");

   //     s.draw(1);
    //    s.Window.display();

//cal.drawCalendar(1024,768,2018);
while (Window.isOpen())
{
   sf::Event event;
   while (Window.pollEvent(event))

   {
       if (event.type == sf::Event::Closed)
            Window.close();
        }
        Window.clear();
        Window.draw(grupa);
        Window.display();
    //cal.drawCalendar(11,11,2018);
//Window.display();

}
}