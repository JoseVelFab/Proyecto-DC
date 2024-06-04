#pragma once
#include <SFML/Graphics.hpp>
class Imagen
{
private:
    sf::Sprite sprite;
    sf::Texture textureC;
    int coord_x,coord_y;
    const int ancho = 32;
    const int alto = 32;
public:
    Imagen(int coord_x,int coord_y) {
        
        if (!textureC.loadFromFile("./assets/images/ProjectUtumno_full.png"))
        {
            // Manejo de error si no se puede cargar la imagen
            throw "Error al cargar la imagen";
        }
        cambiarImagen(coord_x,coord_y);
    }
    sf::Sprite& getSprite(){
    return this->sprite;
    }

    void cambiarImagen(int coord_x,int coord_y){
        if (coord_x<0 || coord_y<0 || coord_x>64 || coord_y>95)
        {
            throw "Error en las coordenadas";
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
    ~Imagen() {}
};