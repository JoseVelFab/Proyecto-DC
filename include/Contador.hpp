#pragma once
#include <SFML/System/Clock.hpp>

/// @brief 
class Contador
{
private:
    sf::Clock clock;

public:
    Contador()
    {
        clock.restart();
    }

    float GetTiempo()
    {
        return clock.getElapsedTime().asSeconds();
    }

    bool Esperar(float segundos)
    {
        if (GetTiempo() >= segundos)
        {
            ResetearReloj();
            return true;
        }
        else
        {
            return false;
        }
    }

    void ResetearReloj()
    {
        clock.restart();
    }

    ~Contador() {}
};