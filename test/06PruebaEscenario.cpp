#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba de Escenario");
    
    sf::Texture texture;
    if (!texture.loadFromFile("assets/Mapa/Mapa.png"))
    {
        // Error al cargar la imagen
        return -1;
    }
    
    sf::Sprite background(texture);
    window.setSize(sf::Vector2u(texture.getSize().x, texture.getSize().y));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear();
        window.draw(background);
        window.display();
    }
    
    return 0;
}