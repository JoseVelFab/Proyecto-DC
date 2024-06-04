#pragma once
#include <Imagen.hpp>
#include <SFML/Graphics.hpp>

class Personaje
{
private:
    sf::RectangleShape shape; 
    Imagen prota; 
    int ancho = 32;
    int alto = 32;
    float offsetX, offsetY;
public:
    double velocidad = 10;
    Personaje(sf::Vector2f posicion, sf::Color color) {
        this->prota.cambiarImagen(1, 61);
        shape.setSize(sf::Vector2f(ancho, alto));
        shape.setPosition(posicion); // Posición inicial cuadro
        prota.mover(posicion.x, posicion.y);
        shape.setFillColor(color);
    }
    void move(float offsetX, float offsetY)
    {
        shape.move(offsetX, offsetY);
        prota.mover(offsetX, offsetY);
    }

    float getPosX(){
        return shape.getPosition().x;
    }

    float getPosY(){
        return shape.getPosition().y;
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(prota.getSprite());
    }
    ~Personaje() {}
};