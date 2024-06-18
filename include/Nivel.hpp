#pragma once
class Nivel
{
private:
    int NumeroNivel;
public:
    Nivel() {
        NumeroNivel = 1;
        
    }
    int GetNivelActual() {
        return NumeroNivel;
    }
    int SiguienteNivel() {
        return NumeroNivel++;
    }
    ~Nivel() {}
};