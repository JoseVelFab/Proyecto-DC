#pragma once
#include <Imagen.hpp>

class Personaje
{
private:
    Imagen prota,vida;
    float offsetX, offsetY;
    double velocidad = 5;
    sf::Vector2f dimencionesVentana;
public:
    Personaje(sf::Vector2f posicion)
    {
        dimencionesVentana = posicion;
        this->prota.cambiarImagen(1, 61);
        this->vida.cambiarImagen(61, 50);
        vida.mover(posicion.x/2, posicion.y/2+10);
        prota.mover(posicion.x/2, posicion.y/2);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(prota.getSprite());
        window.draw(vida.getSprite());
    }

    sf::Vector2f GetPosicion()
    {
        return prota.coordenadas;
    }

    void MoverAlPersonaje(float offsetX, float offsetY)
    {
        offsetX = offsetX * velocidad;
        offsetY = offsetY * velocidad;
        prota.mover(offsetX, offsetY);
        SeguirPersonaje();
    }
    void SeguirPersonaje()
    {
        vida.mover(prota.coordenadas.x, prota.coordenadas.y+10);
    }

    void Correr()
    {
        cout << "Corriendo" << endl;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (GetPosicion().x > 0)
            {
                MoverAlPersonaje(-1, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (GetPosicion().x < dimencionesVentana.x - 32)
            {
                MoverAlPersonaje(1, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (GetPosicion().y > 0)
            {
                MoverAlPersonaje(0, -1);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (GetPosicion().y < dimencionesVentana.y - 52)
            {
                MoverAlPersonaje(0, 1);
            }
        }
    }
    ~Personaje() {}
};