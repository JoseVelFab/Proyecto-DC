#pragma once
#include <Imagen.hpp>

using namespace std;

class Dragon
{
private:
    Imagen dragon;
    int nivel_actual,nivel_actualD,nivel;
    float x,y;
    float seguirx,seguiry;


    void actualizarNivel(){
        if (nivel>5 || nivel<1){
            nivel=1;
        }
        this->nivel_actual = 22+2*nivel;
        print(1);
    }

    void print(bool a){
        if (a==1){
            dragon.cambiarImagen(getNivelActual(),baseY);
        }else{
            this->nivel_actualD = getNivelActual()+1;
            dragon.cambiarImagen(nivel_actualD,baseY);
            }
    }
    


public:
    int baseY=68;
    Dragon(int nivel){
        this->nivel = nivel;
        actualizarNivel();
    }

    Dragon(int nivel,sf::Vector2f posicion) {
        this->x = posicion.x;
        this->y = posicion.y;

        this->nivel = nivel;
        actualizarNivel();
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
        if (seguirx-this->x<0){
            dragon.mover(-1,0);
            this->x--;
            print(1);
        }
        if (seguirx-this->x>0){
            dragon.mover(1,0);
            this->x++;
            print(0); 
        }
        if (seguiry-this->y<0){
            dragon.mover(0,-1);
            this->y--; 
        }
        if (seguiry-this->y>0){
            dragon.mover(0,1);
            this->y++;
        }
    }


    void draw(sf::RenderWindow &window)
    {
        window.draw(dragon.getSprite());
    }
   
    ~Dragon() {}
};