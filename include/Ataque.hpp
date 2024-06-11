#pragma once
#include <Imagen.hpp>

using namespace std;

class Ataque
{
private:
    Imagen ataque;
    int nivel_actual, nivel;
    float x, y, fx, fy;
    int f = 1;
    int tiempoTrasncurrido = 0;
    int duracion = 100;

public:
    int baseY = 69;

    Ataque()
    {
        ProyectarImagen();
    }

    Ataque(float x, float y, float fx, float fy)
    {
        this->x = x;
        this->y = y;
        this->fx = fx;
        this->fy = fy;

        ataque.mover(x, y);
    }

    void trayecto()
    {
        this->f++;
        if (fx - x < 0)
        {
            ataque.mover(-1, 0);
            this->x--;
        }
        if (fx - x > 0)
        {
            ataque.mover(1, 0);
            this->x++;
        }
        if (fy - y < 0)
        {
            ataque.mover(0, -1);
            this->y--;
        }
        if (fy - this->y > 0)
        {
            ataque.mover(0, 1);
            this->y++;
        }
        if (f > 4)
        {
            this->f = 1;
        }
        ProyectarImagen();
    }

    void ProyectarImagen()
    {
        ataque.cambiarImagen(37 + this->f, baseY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(ataque.getSprite());
    }

    bool EstaVivo(){
        if (this->tiempoTrasncurrido < this->duracion)
        {
            this->tiempoTrasncurrido += 1;
            return true;
        }else
        {
            return false;
        }
        
        
    }

    ~Ataque() {}
};
