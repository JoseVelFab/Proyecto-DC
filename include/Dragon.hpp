#pragma once
#include <Imagen.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

using namespace std;

class Dragon
{
private:
    Imagen dragon;
    sf::Vector2f posicionDeComparacion;
    sf::Clock clock;
    bool vida = true;
    int nivel_actual, nivel_actualD, nivel;   
    float velocidad;

    void ActualizarNivel()
    {
        if (nivel > 5 || nivel < 1)
        {
            nivel = 1;
        }
        this->nivel_actual = 22 + 2 * nivel;
        Print(1);
    }

    void Print(int a)
    {
        if (clock.getElapsedTime().asSeconds() > .5)
        {
            if (a == 1)
            {
                dragon.cambiarImagen(GetNivelActual(), baseY);
            }
            else
            {
                this->nivel_actualD = GetNivelActual() + 1;
                dragon.cambiarImagen(nivel_actualD, baseY);
            }
        }
        else
        {
            dragon.cambiarImagen(1, 25);
        }
    }

public:
    int baseY = 68;
    Dragon(int nivel)
    {
        this->nivel = nivel;
        ActualizarNivel();
    }

    Dragon(int nivel, sf::Vector2f requisito)
    {

        this->nivel = nivel;
        ActualizarNivel();
        dragon.mover(requisito.x, requisito.y);
    }

    int GetNivelActual()
    {
        return nivel_actual;
    }

    sf::Vector2f GetPosicion()
    {
        return dragon.ObtenerVectorCoordenadas();
    }

    void IncrementarNivel()
    {
        nivel++;
        ActualizarNivel();
    }

    void DecrementarNivel()
    {
        if (clock.getElapsedTime().asSeconds() > .50)
        {
            if (nivel == 1)
            {
                this->vida = false;
            }
            nivel--;
            ActualizarNivel();
            clock.restart();
        }
    }

    void Seguir(sf::Vector2f posicionObjetivo)
    {
        if (posicionObjetivo.x - dragon.coordenadas.x < 0)
        {
            dragon.mover(-1, 0);
            Print(1);
        }
        if (posicionObjetivo.x - dragon.coordenadas.x > 0)
        {
            dragon.mover(1, 0);
            Print(0);
        }
        if (posicionObjetivo.y - dragon.coordenadas.y < 0)
        {
            dragon.mover(0, -1);
        }
        if (posicionObjetivo.y - dragon.coordenadas.y > 0)
        {
            dragon.mover(0, 1);
        }
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(dragon.getSprite());
    }

    bool Vive()
    {
        return vida;
    }
    ~Dragon() {}
};