#pragma once
#include <vector>
#include <Imagen.hpp>

using namespace std;

class Dragon
{
private:
    int nivel_actual;
    vector<Imagen> niveles;
public:
    Dragon() {
        niveles.push_back(Imagen(23, 67));
        niveles.push_back(Imagen(23, 69));
        niveles.push_back(Imagen(23, 71));
        niveles.push_back(Imagen(23, 73));
        niveles.push_back(Imagen(23, 75));
        niveles.push_back(Imagen(23, 67));
        niveles.push_back(Imagen(23, 69));
        niveles.push_back(Imagen(23, 71));
        niveles.push_back(Imagen(23, 73));
        niveles.push_back(Imagen(23, 75));
        nivel_actual = 0;
    }
    ~Dragon() {}
    Imagen& getNivelActual(){
        return niveles[nivel_actual];
    }
    void incrementarNivel() {
        nivel_actual++;
    }
};