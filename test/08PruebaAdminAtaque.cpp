
#include <SFML/Graphics.hpp>
#include <Personaje.hpp>
#include <Dragon.hpp> 
#include <AdminAtaque.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    Personaje personaje(sf::Vector2f(50, 50));
    Dragon dragon(3, sf::Vector2f(20, 20));
    AdminAtaque ataques;

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
                personaje.mover(-1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                personaje.mover(1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                personaje.mover(0, -1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                personaje.mover(0,1);
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left){
                    ataques.NuevoAtaque(personaje.GetPosicion(),
                                        event.mouseButton.x,
                                        event.mouseButton.y);
                }
            }
        }

        dragon.Seguir(personaje.GetPosicion());
        ataques.Actualizacion();

        window.clear();
        personaje.draw(window);
        dragon.draw(window);
        ataques.draw(window);

        window.display();
    }

    return 0;
}
