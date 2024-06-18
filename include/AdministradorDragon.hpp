#pragma once
#include <Dragon.hpp>
#include <list>
#include <SFML/Graphics.hpp>
#include <random>

using namespace std;

class AdministradorDragon
{
private:
    list<Dragon> dragones;

public:
    AdministradorDragon()
    {
    }

    void Actualizacion(sf::Vector2f personaje)
    {
        for (auto it = dragones.begin(); it != dragones.end(); ++it)
        {
            it->Seguir(personaje);
        
        }
    }


    int NumeroAleatorio(int limiteInferior,int limite)
    {
        std::random_device rd;  
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distrib(1, limite); 

        return distrib(gen);
    }

    void NuevoDragon(int Cabezas,sf::Vector2f posicion)
    {
        dragones.emplace_back(Dragon(NumeroAleatorio(1,5), posicion));
    }

    void draw(sf::RenderWindow &window)
    {
        for (auto &&dragon : dragones)
        {
            dragon.draw(window);
        }
    }

    void GenerarDragones(int numeroDragones,int minimoCabezas, int maximoCabezas,sf::Vector2f ventana){
        float limiteinferiorX = ventana.x/2 - ventana.x/10;
        float limiteinferiorY = ventana.y/2 - ventana.y/10;
        float limitesuperiorX = ventana.x/2 + ventana.x/10;
        float limitesuperiorY = ventana.y/2 + ventana.y/10;
        int coordenadaX, coordenadaY;
        for (int i = 0; i < numeroDragones; i++)
        {  
            do{
                coordenadaX = NumeroAleatorio(0,ventana.x); 
                coordenadaY = NumeroAleatorio(0,ventana.y);
            }while( limiteinferiorX < coordenadaX && 
                    limiteinferiorY < coordenadaY &&
                    limitesuperiorX > coordenadaX &&
                    limitesuperiorY > coordenadaY
                    );
            NuevoDragon(NumeroAleatorio(minimoCabezas,maximoCabezas),sf::Vector2f(coordenadaX,coordenadaY));
        }
    }

    list<sf::Vector2f> GetCoordenadas()
    {
        list<sf::Vector2f> coordenadas;
        for (auto &&dragon : dragones)
        {
            coordenadas.push_back(dragon.GetPosicion());
        }
        return coordenadas;
    }

    void EliminarDragon(sf::Vector2f coordenada)
    {
        for (auto it = dragones.begin(); it != dragones.end();)
        {
            if (it->GetPosicion() == coordenada)
            {
                it->DecrementarNivel();
                if (it->Vive() == false)
                {
                    it = dragones.erase(it);
                }
                else
                {
                    ++it;
                }
                break;
            }
            else
            {
                ++it;
            }
        }
    }
    
    bool ExistenDragones()
    {
        if (dragones.size() > 0)
        {
            return true;
        }
        else
        {
            return false;
        } 
    }

    ~AdministradorDragon()
    {
    }
};
