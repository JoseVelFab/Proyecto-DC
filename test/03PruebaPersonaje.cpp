#include<Personaje.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Personaje");
    Personaje mc(sf::Vector2f(0,0) );

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mc.mover(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mc.mover(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            mc.mover(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            mc.mover(0, -1);
        }
        }

        window.clear();
        mc.draw(window);
        window.display();
    }
    return 0;
}
