#include <iostream>
#include <SFML/Graphics.hpp>
#include <Personaje.hpp>
#include <AdministradorDragon.hpp>
#include <AdminAtaque.hpp>
#include <Reloj.hpp>
using namespace std;

int main()
{
    sf::Vector2f dimencionesVentana(800, 600);
    sf::RenderWindow window(sf::VideoMode(dimencionesVentana.x, dimencionesVentana.y), "Game");

    Personaje personaje(dimencionesVentana);
    AdministradorDragon dragones;
    AdminAtaque ataques;
    Reloj DescansoDaño, DescansoAtaque;

    dragones.GenerarDragones(15, 1, 5, dimencionesVentana);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {   
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    ataques.NuevoAtaque(personaje.GetPosicion(),
                                        event.mouseButton.x,
                                        event.mouseButton.y);
                }
            }
        }
        
        personaje.Correr();
        dragones.Actualizacion(personaje.GetPosicion());
        ataques.Actualizacion();
        list<sf::Vector2f> coordenadas = dragones.GetCoordenadas();
        if (DescansoDaño.Esperar(0.1))
        {
            for (auto &&coordenada : coordenadas)
            {
                if (ataques.CheckHit(coordenada) == true)
                {
                    dragones.EliminarDragon(coordenada);
                }
            }
        }

        window.clear();
        personaje.draw(window);
        dragones.draw(window);
        ataques.draw(window);

        window.display();
    }
    return 0;
}
