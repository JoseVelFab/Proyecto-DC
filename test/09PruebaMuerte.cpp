#include <iostream>
#include <SFML/Graphics.hpp>
#include <Personaje.hpp>
#include <Dragon.hpp> 
#include <AdminAtaque.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    Personaje personaje(sf::Vector2f(400,300));
    Dragon dragon(3, sf::Vector2f(500,300));
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
        
        if(ataques.CheckHit(dragon.GetPosicion())==true)
        {
            dragon.DecrementarNivel();
        }
        
        window.clear();
        personaje.draw(window);
        if (dragon.Vive()){
            dragon.draw(window);
        }
        
        ataques.draw(window);

        window.display();

    }

    return 0;
}
