#include <SFML/Graphics.hp
class dragoncito
{
private:
    int cabeza;
    int coordenadasx,coordenadasy,casilla;
public:
    dragoncito() {
    sf::Texture texture;
        if (!texture.loadFromFile("assets/images/ProjectUtumno_full.png"))
        {
            // Manejo de error si no se puede cargar la imagen
            return -1;
        }
    casilla=32;
    coordenadasy=32*67;
    }

    void Get_Dragoncito(int cabeza){
        cabeza this->cabeza;
        switch (cabeza)
        {
        case 1:
            coordenadasx=32*23+32*0;
            break;
        case 2:
            coordenadasx=32*23+32*2;
            break;
        case 3:
            coordenadasx=32*23+32*4;
            break;
        case 4:
            coordenadasx=32*23+32*6;
            break;
        case 5:
            coordenadasx=32*23+32*8;
            break;
        case 6:
            coordenadasx=32*23+32*1;
            break;
        case 7:
            coordenadasx=32*23+32*3;
            break;
        case 8:
            coordenadasx=32*23+32*5;
            break;
        case 9:
            coordenadasx=32*23+32*7;
            break;
        case 10:
            coordenadasx=32*23+32*9;
            break;
        
        default:
            coordenadasx=32*23+32*1;
            break;
        }
        sprite.setTextureRect(sf::IntRect(coordenadasx,coordenadasy, casilla,casilla));
        clock.restart();
    }
    ~dragoncito() {}
};