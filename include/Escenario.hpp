/* #pragma once
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
}; */

#include <Imagen.hpp>
#include <conio.h>
#include <iostream>
#pragma once
#define Filas 4
#define Columnas 4

using namespace std;
using namespace system;

class Escenario
{
private:
    
public:
    Escenario() {}
    ~Escenario() {}
};

void imprimirMatriz (){
    int matrizInici0[Filas][Columnas] = {
        {3, 2, 2, 3},
        {2, 1, 1, 2},
        {1, 1, 1, 1},
        {3, 2, 2, 3},
    };
    Console::Clear();
    for (int i = 0, i < Filas, i++)
    {
        for (int j = 0; j < Columnas; j++)
        {
            if (matrizInici0[i][j]==1)
            {
                Console::ForegroundColor = ConsoleColor::Green;
                cout << (char)219;
            }
            if (matrizInici0[i][j]==1)
            {
                Console::ForegroundColor = ConsoleColor::Brown;
                cout << (char)219;
            }
            if (matrizInici0[i][j]==1)
            {
                Console::ForegroundColor = ConsoleColor::Blue;
                cout << (char)219;
            }
        }
        cout << "\n";
    }
};