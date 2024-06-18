#pragma once
#include <SFML/Graphics.hpp>
#include <random>
using namespace std;

class  AdministradorMapa
{
private:
    sf::Sprite sprite;
    sf::Texture texturaC, texturaD, texturaI, texturaM, texturaMo;

    void check()
    {
        if (!texturaC.loadFromFile("./assets/images/Mapas/Castillo.png"))
        {
            throw runtime_error("Error al cargar la imagen");
        }
        if (!texturaD.loadFromFile("./assets/images/Mapas/Desierto.png"))
        {
            throw runtime_error("Error al cargar la imagen");
        }
        if (!texturaI.loadFromFile("./assets/images/Mapas/Infierno.png"))
        {
            throw runtime_error("Error al cargar la imagen");
        }
        if (!texturaM.loadFromFile("./assets/images/Mapas/Mapa.png"))
        {
            throw runtime_error("Error al cargar la imagen");
        }
        if (!texturaMo.loadFromFile("./assets/images/Mapas/montania.png"))
        {
            throw runtime_error("Error al cargar la imagen");
        }
    }

    int MapaAlelatorio()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 5);
        return distrib(gen);
    }

public:
    AdministradorMapa()
    {
        check();
    }
    sf::Sprite &getSprite()
    {
        return this->sprite;
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(getSprite());
    }

    void Elegirmapa()
    {
        switch (MapaAlelatorio())
        {
        case 1:
            this->sprite.setTexture(texturaC);
            break;
        case 2:
            this->sprite.setTexture(texturaD);
            break;
        case 3:
            this->sprite.setTexture(texturaI);
            break;
        case 4:
            this->sprite.setTexture(texturaM);
            break;
        case 5:
            this->sprite.setTexture(texturaMo);
            break;
        default:
            break;
        }
    }

    ~AdministradorMapa() {}
};