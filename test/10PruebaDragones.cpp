
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Personaje.hpp>
#include <AdministradorDragon.hpp> 
#include <AdminAtaque.hpp>
#include <Contador.hpp>
using namespace std;

int main()
{
    sf::Vector2f ventana(800, 600);
    sf::RenderWindow window(sf::VideoMode(ventana.x,ventana.y), "Game");

    Personaje personaje(sf::Vector2f(400,300));
    AdministradorDragon dragones;
    AdminAtaque ataques;
    Contador reloj;

    dragones.GenerarDragones(10,1,5,ventana);

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
                if (event.mouseButton.button == sf::Mouse::Left){
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
        if (reloj.Esperar(0.1))
        {
            for (auto &&coordenada : coordenadas)
        {
            if(ataques.CheckHit(coordenada)==true)
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
