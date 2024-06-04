#include<Personaje.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Personaje");
    Personaje mc(sf::Vector2f(0,0),sf::Color::Red);

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
            mc.move(mc.velocidad*-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mc.move(mc.velocidad*1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            mc.move(0, mc.velocidad*-1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            mc.move(0, mc.velocidad*1);
        }
        }

        window.clear();
        mc.draw(window);
        window.display();
    }
    return 0;
}
