#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

class Imagen
{
private:
    sf::Sprite sprite;
    sf::Texture textureC;
    int coord_x,coord_y;
    const int ancho = 32;
    const int alto = 32;
    float x,y;

    void check(){
        if (!textureC.loadFromFile("./assets/images/ProjectUtumno_full.png"))
        {
            // Manejo de error si no se puede cargar la imagen
            throw runtime_error("Error al cargar la imagen");
        }
    }
public:
    sf::Vector2f coordenadas;
    sf::Vector2f ObtenerVectorCoordenadas(){
        return this->coordenadas;
    }
    Imagen() {
        check();
    }
    
    Imagen(int coord_x,int coord_y) {
        check();
        cambiarImagen(coord_x,coord_y);
    }
    sf::Sprite& getSprite(){
    return this->sprite;
    }

    void cambiarImagen(int coord_x,int coord_y){
        if (coord_x<0 || coord_y<0 || coord_x>64 || coord_y>95)
        {
            throw runtime_error("Coordenadas fuera de rango");
        }
        this->coord_x=coord_x-1;
        this->coord_y=coord_y-1;
        this->sprite.setTexture(textureC);
        this->sprite.setTextureRect(
            sf::IntRect(
                this->coord_x*ancho,
                this->coord_y*alto,
                this->ancho,
                this->alto
            )
        );
    }

    void posicion(sf::Vector2f posicionI)
    {
        this->sprite.setPosition(posicionI);
        this->coordenadas.x= posicionI.x;
        this->coordenadas.y=posicionI.y;

    }

    void mover(float x, float y){
        this->sprite.move(x,y);
        this->coordenadas.x += x;
        this->coordenadas.y += y;
    }
    ~Imagen() {}
};