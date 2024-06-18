#pragma once
#include <Ataque.hpp>
#include <list>
#include <SFML/Graphics.hpp>

using namespace std;

class AdminAtaque
{
private:
    list<Ataque> ataques;

public:
    AdminAtaque()
    {
    }
    void EliminarTodo()
    {
        ataques.clear();
    }
    void NuevoAtaque(sf::Vector2f posicionPersonaje, float mouseX, float mouseY)
    {
        ataques.emplace_back(Ataque(
           posicionPersonaje,
            mouseX,
            mouseY));
    }

    void Actualizacion()
    {
        int i=0, 
            NE = 0;

        for (auto &&ataque : ataques)
        {
            if (ataque.EstaVivo())
            {
                ataque.trayecto();
            }
            else
            {
                NE++;
            }
        }
        for (i=0; i < NE;i++)
        {
            ataques.pop_front();
        }
    }

    bool CheckHit(sf::Vector2f enemigoPosicion)
    {
        for (auto &&ataque : ataques)
        {
            if (ataque.Comparar(enemigoPosicion))
            {
                return true;
            }
        }
        return false;
    }

    void draw(sf::RenderWindow &window)
    {
        for (auto &&ataque : ataques)
        {
            ataque.draw(window);

        }
    }
    
    ~AdminAtaque()
    {
    }
};