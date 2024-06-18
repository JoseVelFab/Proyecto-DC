#include <SFML/System/Clock.hpp>

class Reloj
{
private:
    sf::Clock clock;

public:
    Reloj()
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

    ~Reloj() {}
};