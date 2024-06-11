
#include <SFML/Graphics.hpp>
#include <Personaje.hpp>
#include <Dragon.hpp>
#include <Ataque.hpp>
#include <list>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    Personaje personaje(sf::Vector2f(0, 0), sf::Color::Red);
    Dragon dragon(3, sf::Vector2f(20, 20));
    list<Ataque> ataques;

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
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left){
                    ataques.emplace_back(Ataque(
                        personaje.getPosX(),
                        personaje.getPosY(),
                        event.mouseButton.x,
                        event.mouseButton.y
                    ));
                }
            }
        }

        dragon.seguir(personaje.getPosX(), personaje.getPosY());

        for (auto &&ataque : ataques)
        {
            if (ataque.EstaVivo())
            {
                // Actualizar todos los ataques
                ataque.trayecto();
            }
        }

        window.clear();
        personaje.draw(window);
        dragon.draw(window);

        for (auto &&ataque : ataques)
        {
            if (ataque.EstaVivo())
            {
                // Dibujar todos los ataques
                ataque.draw(window);
            }
        }

        window.display();
    }

    return 0;
}
