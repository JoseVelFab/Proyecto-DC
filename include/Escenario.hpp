#pragma once
#include <Imagen.hpp>
#include <vector>

using namespace std;

class Escenario
{
private:
    vector<vector<Imagen>> imagenes;
public:
    Escenario() {
        for (int i = 0; i < 5; i++)
        {
            vector<Imagen> fila;
            for (int j = 0; j < 5; j++)
            {
                fila.push_back(Imagen(1, 5));
            }
            imagenes.push_back(fila);
        }
    }
    ~Escenario() {}

    void Dibujar(sf::RenderWindow &window){
        for (int i = 0; i < imagenes.size(); i++)
        {
            for (int j = 0; j < imagenes[i].size(); j++)
            {
                window.draw(imagenes[i][j].getSprite());
            }
        }
    }
};