
#include <SFML/Graphics.hpp>
#include <Personaje.hpp>
#include <Dragon.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    Personaje personaje(sf::Vector2f(0, 0), sf::Color::Red);
    Dragon dragon(1,sf::Vector2f(20, 20));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                personaje.move(personaje.velocidad * -1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                personaje.move(personaje.velocidad * 1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                personaje.move(0, personaje.velocidad * -1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                personaje.move(0, personaje.velocidad * 1);
            }
        }

        dragon.seguir(personaje.getPosX(), personaje.getPosY());

        window.clear();
        personaje.draw(window);
        dragon.draw(window);
        window.display();
    }

    return 0;
}
