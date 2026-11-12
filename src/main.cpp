#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({600, 600}), "Puzzle 9 - Prueba");

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color(30, 30, 30));
        window.display();
    }
    return 0;
}