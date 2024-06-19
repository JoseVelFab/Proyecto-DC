#pragma once
#include <Imagen.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

using namespace std;

class Ataque
{
private:
    Imagen ataque;
    sf::Vector2f destino, cambio, posicion0;
    int f = 1;
    int duracion = 500, tiempoTranscurrido;
    float rangoDeAtaque = 32;
    float pendiente;

    bool DireccionCheck()
    {
        sf::Vector2f diferencial;
        diferencial.x = abs(destino.x - posicion0.x);
        diferencial.y = abs(destino.y - posicion0.y);
        if (diferencial.y > diferencial.x)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void ActualizarLocalizacion()
    {
        if (DireccionCheck() == true)
        {
            ataque.mover(cambio.x, cambio.x * pendiente);
        }
        else
        {
            ataque.mover(cambio.y * pendiente, cambio.y);
        }
    }

public:
    int baseY = 69;

    Ataque(sf::Vector2f posicionInicio, float destinox, float destinoy)
    {
        // cout << "Ataque creado" << endl;
        this->posicion0 = posicionInicio;
        this->destino.x = destinox;
        this->destino.y = destinoy;
        ataque.mover(posicionInicio.x, posicionInicio.y);
        CalculoVariables();
    }

    void CalculoVariables()
    {
        this->pendiente = (destino.y - posicion0.y) / (destino.x - posicion0.x);
        if (DireccionCheck() == true)
        {
            if (destino.x - posicion0.x > 0)
            {
                this->cambio.x = 1;
            }
            else
            {
                this->cambio.x = -1;
            }
        }
        else
        {
            pendiente = 1 / pendiente;
            if (destino.y - posicion0.y > 0)
            {
                this->cambio.y = 1;
            }
            else
            {
                this->cambio.y = -1;
            }
        }
    }

    void trayecto()
    {
        f++;
        if (f > 3)
        {
            this->f = 1;
        }

        ProyectarImagen();
        ActualizarLocalizacion();
    }

    void ProyectarImagen()
    {
        ataque.cambiarImagen(37 + this->f, baseY);
    }

    void draw(sf::RenderWindow &window)
    {
        // cout << "Ataque dibujado" << endl;
        window.draw(ataque.getSprite());
    }

    bool EstaVivo()
    {
        tiempoTranscurrido += 1;
        if (tiempoTranscurrido < duracion)
        {
            if (tiempoTranscurrido > (duracion - 50))
            {
                int imagenEnX = 10 + ((duracion - tiempoTranscurrido) / 10);
                ataque.cambiarImagen(imagenEnX, 27);
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Comparar(sf::Vector2f enemigo)
    {
        if (
            (enemigo.x - 10) <= ataque.coordenadas.x &&
            (enemigo.y - 10) <= ataque.coordenadas.y &&
            (enemigo.x + 32) >= ataque.coordenadas.x &&
            (enemigo.y + 32) >= ataque.coordenadas.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ~Ataque() {}
};
