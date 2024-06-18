#pragma once
class AdminisradorNivel
{
private:
    int NumeroNivel;
public:
    AdministradorNivel() {
        NumeroNivel = 1;
        
    }
    int GetNivelActual() {
        return NumeroNivel;
    }
    int SiguienteNivel() {
        return NumeroNivel++;
    }
    ~AdministradorNivel() {}
};