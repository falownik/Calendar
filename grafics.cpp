#include <include/SFML/Graphics.hpp>
#include "grafics.hpp"
#include <iostream>
#include <fstream>

void CalendarGui::drawCalendar(int xx, int yy, int years)
{
    //Window.clear(sf::Color(128,128,128));
    this->setYear(years);
    for (auto k = 0; k < 12 ; k++ )
    {
         Window.draw(calendar[k].draw(calDate.getFirstDay(k+1), calDate.daysInMonth[k+1], x[k],y[k]));
    }
        yearString.setFont(calendar[0].font);
        yearString.setString(std::to_string(years));
        yearString.setFillColor(sf::Color::Yellow);
        yearString.setPosition(sf::Vector2f(x[0] + 10, y[0] - 70));
        yearString.setCharacterSize(25);
        Window.draw(yearString);
    Window.display();
}

void CalendarGui::setYear(int years){
    calDate.setYear(years);
    for( auto a = 0;  a < 12 ; a ++)
        calendar[a].text[0].setString(calDate.nameOfMonth[a+1]);
}
Group CalendarWindow::draw (int firstDay, int daysInMonth, int xx, int yy)
{
    Group group;
    this->setPosition(xx,yy);

    for (auto i = 0; i < 50; i++)
    {
      
        // Drawing Calendar's background
        rectangle[i].setPosition(sf::Vector2f(x_small[i], y_small[i]));
        if (i == 0)
            rectangle[i].setSize(sf::Vector2f(172, 26));
        else
            rectangle[i].setSize(sf::Vector2f(tileSizeX, tileSizeY));
        if ((i % 2) == true)
            rectangle[i].setFillColor(sf::Color(83, 83, 83));
        else
            rectangle[i].setFillColor(sf::Color(67, 67, 67));
        group.push_back(rectangle[i]);
    }
    
    for (auto i = 0; i < 8; i++)
    {
            text[i].setPosition(x_small[i], y_small[i]);
            text[i].setCharacterSize(17);
            text[i].setFillColor(sf::Color::Yellow);
            text[i].setFont(font);
            group.push_back(text[i]);   
        }
        
    for (auto i = 7; i < 7 + daysInMonth; i++)
    {
            days[i - 6].setFont(font);
            days[i - 6].setFillColor(sf::Color::Yellow);
            days[i - 6].setCharacterSize(17);
            // correction for standard, in which Sunday is 0
            if (firstDay == 0)
                firstDay = 7;
            days[i - 6].setPosition(x_small[i + firstDay], y_small[i + firstDay]);
            group.push_back(days[i - 6]);  
        }
    return group;
}
void CalendarWindow::setPosition(int xx, int yy){
        x = xx;
        y = yy;
        x_small[0] = x + 10;
        y_small[0] = y;
        for (auto i = 1 ; i < 50 ; i++ )
            x_small[i] = x + ((i - 1) % 7) * 25 + 10;
        for (auto i = 1 ; i < 50 ; i++ )
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

void Button::setButton (int xx, int yy, int w, int h, std::string name)
{
    x = xx; y = yy; width = w; height = h;
font.loadFromFile("arial.ttf");
text.setFont(font);
text.setString(name);
text.setFillColor(sf::Color::Yellow);
text.setPosition(sf::Vector2f(xx,yy));
text.setCharacterSize(17);
rectangle.setPosition(sf::Vector2f(xx,yy));
rectangle.setSize(sf::Vector2f(w,h));
rectangle.setFillColor(sf::Color::Red);
group.push_back(rectangle);
group.push_back(text);
}


void EventGui::setEvent(int numberOfEvent)
{
    std::string tit, i;
    tit = title.getString();
    i = info.getString();
    std::fstream file;
    file.open("events/events.txt", std::fstream::app);
    if (!file)
        std::cout << "something went wrong" << std::endl;

    file << numberOfEvent << " " << event.time.hour << " " << event.time.minute << " " 
    << event.date.day << " " << event.date.month << " " << event.date.year << std::endl;
    file << tit << std::endl;
    file << i << std::endl;

    file.close();

}
void EventGui::dateToString()
{

    dateInString.setString(std::to_string(event.time.hour) + ":" + std::to_string(event.time.minute) + "   " + std::to_string(event.date.day) + "." + std::to_string(event.date.month) + "." + std::to_string(event.date.year));

}
void CalendarGui::printEvent()
{
    for (unsigned int i = 0; i < event.size() ; i++)
    {
        font.loadFromFile("arial.ttf");
        event[i].width = 500;
        event[i].height = 70;
        event[i].rectangle.setSize(sf::Vector2f(event[i].width, event[i].height));
        event[i].rectangle.setPosition(sf::Vector2f(10, 10 + (event[i].height + 10)*i));
        event[i].rectangle.setFillColor(sf::Color(100,100,100));
        event[i].group.push_back(event[i].rectangle);

        event[i].title.setFont(font);
        event[i].title.setFillColor(sf::Color::Yellow);
        event[i].title.setPosition(sf::Vector2f(10,(event[i].height + 10)*i + 10));
        event[i].title.setCharacterSize(17);
        event[i].group.push_back(event[i].title);

        event[i].info.setPosition(sf::Vector2f(10, (event[i].height + 10)*i + 30));
        event[i].info.setCharacterSize(17);
        event[i].group.push_back(event[i].info);

        event[i].dateInString.setFont(font);
        event[i].dateToString();
        event[i].dateInString.setCharacterSize(17);
        event[i].dateInString.setPosition(sf::Vector2f( 10, (event[i].height + 10)*i + 50));
        event[i].group.push_back(event[i].dateInString);

    }
}


void CalendarGui::addEvent()
{
    EventGui e;
    std::string tit, i;
    e.font.loadFromFile("arial.ttf");

    std::cout << std::endl << " Podaj nazwę wydarzenia:";
    std::getline (std::cin , tit);

    std::cout << std::endl << " Podaj opis wydarzenia: ";
    std::getline (std::cin, i);

    std::cin.sync();

    std::cout << std::endl << " Podaj rok: ";
    std::cin >> e.event.date.year;

    std::cout << std::endl << " Podaj miesiąc: ";
    std::cin >> e.event.date.month;

    std::cout << std::endl << " Podaj dzien: ";
    std::cin >> e.event.date.day;

    std::cout << std::endl << " Podaj godzine: ";
    std::cin >> e.event.time.hour;

    std::cout << std::endl << " Podaj minute: ";
    std::cin >> e.event.time.minute;

    std::cin.sync();

    e.title.setFont(font);
    e.info.setFont(font);
    e.title.setString(tit);
    e.info.setString(i);

    event.erase(event.begin(), event.end());
    e.setEvent(event.size());
    this->ReadEvent();

     this->printEvent();
}
void CalendarGui::ReadEvent()
{
    EventGui eventgui;
    std::string tit, inf;
    int id;
    std::ifstream file;
    file.open("events/events.txt");
    if (!file)
    {
        std::cout << "something went wrong" << std::endl;
        return;
    }

    while(!file.eof())
    {
        file >> id; // ommiting id
        file >> eventgui.event.time.hour;
        file >> eventgui.event.time.minute;
        file >> eventgui.event.date.day;
        file >> eventgui.event.date.month;
        file >> eventgui.event.date.year;
        file.ignore(1,'\n'); 
        std::getline (file, tit);
        std::getline (file, inf);
        eventgui.title.setFont(font);
        eventgui.info.setFont(font);
        eventgui.title.setString(tit);
        eventgui.info.setString(inf);

        if (file.fail() && !file.eof())
        {
            std::cout << "Bład formatowania danych, prosze poprawic" << std::endl;
            return;
        }

        event.push_back(eventgui);

    }
    event.pop_back();

    file.close();
}

void CalendarGui::updateEvent()
{
    event.erase(event.begin(), event.end());
    this->ReadEvent();
    this->printEvent();
}



