#pragma once
#include <Personaje.hpp>

class KitMovimiento
{
private:
    Personaje personaje(sf::Vector2f(0,0),sf::Color::Red);
public:
    KitMovimiento(class &coso) {
        this->personaje = coso; 
    }
    void flechas()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            coso.move(coso.velocidad*-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            coso.move(coso.velocidad*1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            coso.move(0, coso.velocidad*-1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            coso.move(0, coso.velocidad*1);
        }
    }
    ~KitMovimiento() {}
}
;