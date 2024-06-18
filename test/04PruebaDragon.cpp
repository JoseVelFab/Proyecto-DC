#include <Dragon.hpp>
#include <imagen.hpp>
// #include <Escenario.hpp>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Inicializar
    sf::RenderWindow window(sf::VideoMode(600, 400), "DinoChrome");
    // Escenario escenario;
    Dragon dragon(1);
    std::cout << "Nivel Actual: " << dragon.GetNivelActual() << std::endl;
    Imagen enemigo(dragon.GetNivelActual(),dragon.baseY);
    

    while (window.isOpen())
    {

        // Actualizar
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                cout << "Tecla presionada: " << event.key.code << endl;
                if (event.key.code == sf::Keyboard::Up)
                {
                    dragon.IncrementarNivel();
                    std::cout << "Nivel Actual: " << dragon.GetNivelActual() << std::endl;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    dragon.DecrementarNivel();
                    std::cout << "Nivel Actual: " << dragon.GetNivelActual() << std::endl;
                }
            }
        }

        
        
        // Dibujar
        enemigo.cambiarImagen(dragon.GetNivelActual(),dragon.baseY);
        
        window.clear();
        window.draw(enemigo.getSprite());
        window.display();
    }

    return 0;
}