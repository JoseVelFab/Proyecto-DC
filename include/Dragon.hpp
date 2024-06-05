#pragma once

using namespace std;

class Dragon
{
private:
    Imagen dragon;
    int nivel_actual,nivel;
    float x,y;
    float seguirx,seguiry;
    void actualizarNivel(){
        if (nivel>5 || nivel<1){
            nivel=1;
        }
        this->nivel_actual = 22+2*nivel;
    }
public:
    int baseY=68;
     Dragon(int nivel) {
        this->nivel = nivel;
        actualizarNivel();
        dragon.cambiarImagen(getNivelActual(),baseY);
    }
    
    Dragon(int nivel,sf::Vector2f posicion) {
        this->nivel = nivel;
        actualizarNivel();
        dragon.cambiarImagen(getNivelActual(),baseY);
        dragon.mover(posicion.x, posicion.y);
    }

    int getNivelActual(){
        return nivel_actual;
    }
    void incrementarNivel(){
        nivel++;
        actualizarNivel();
    }
    void decrementarNivel(){
        nivel--;
        actualizarNivel();
    }  
    void seguir(float seguirx, float seguiry){
        if (seguirx<this->x){
            dragon.mover(-1,0);
            x=x-1;
        }
        if (seguirx>this->x){
            dragon.mover(1,0);
            x=x+1; 
        }
        if (seguiry<this->y){
            dragon.mover(0,-1);
            y=y-1; 
        }
        if (seguiry>this->y){
            dragon.mover(0,1);
            y=y+1;
        }
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(dragon.getSprite());
    }
   
    ~Dragon() {}
};