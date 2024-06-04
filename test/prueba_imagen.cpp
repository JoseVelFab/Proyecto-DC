#include <Imagen.hpp>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Inicializar
    sf::RenderWindow window(sf::VideoMode(600, 400), "DinoChrome");
    Imagen imagen(2, 2);

    while (window.isOpen())
    {

        // Actualizar
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                cout << "Tecla presionada: " << event.key.code << endl;
                if (event.key.code == sf::Keyboard::Left)
                {
                    imagen.cambiarImagen(1, 2);
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    imagen.cambiarImagen(2, 2);
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    imagen.cambiarImagen(3, 2);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    imagen.cambiarImagen(4, 2);
                }
            }
        }
        // Dibujar
        window.clear();
        window.draw(imagen.getSprite());
        window.display();
    }

    return 0;
}
