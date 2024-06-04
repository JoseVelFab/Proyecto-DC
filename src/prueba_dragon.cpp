#include <Dragon.hpp>
#include <Escenario.hpp>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Inicializar
    sf::RenderWindow window(sf::VideoMode(600, 400), "DinoChrome");
    Escenario escenario;

    while (window.isOpen())
    {

        // Actualizar
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            // if (event.type == sf::Event::KeyPressed)
            // {
            //     cout << "Tecla presionada: " << event.key.code << endl;
            //     if (event.key.code == sf::Keyboard::Up)
            //     {
            //         dragon.incrementarNivel();
            //     }
            // }
        }

        // Dibujar
        window.clear();
        escenario.Dibujar(window);
        window.display();
    }

    return 0;
}
