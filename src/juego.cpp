#include <iostream>
#include <SFML/Graphics.hpp>
#include <Personaje.hpp>
#include <AdministradorDragon.hpp>
#include <AdminAtaque.hpp>
#include <Contador.hpp>
#include <Nivel.hpp>
#include <Mapa.hpp>

using namespace std;

int main()
{
    sf::Vector2f dimencionesVentana(800, 600);
    sf::RenderWindow window(sf::VideoMode(dimencionesVentana.x, dimencionesVentana.y), "Game");
    Personaje personaje(dimencionesVentana);
    AdministradorDragon dragones;
    AdminAtaque ataques;
    Contador DescansoDaño, DescansoAtaque, DescansoDañoRecibido;
    AdministradorNivel nivel;
    Mapa mapa;

    while (window.isOpen())
    {
        dragones.GenerarDragones(nivel.GetNivelActual(), 1, 5, dimencionesVentana);
        mapa.Elegirmapa();
        while (dragones.ExistenDragones())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return 0;
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (DescansoAtaque.Esperar(0.5))
                    {
                        cout << "Click" << endl;
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {

                            ataques.NuevoAtaque(personaje.GetPosicion(),
                                                event.mouseButton.x,
                                                event.mouseButton.y);
                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        personaje.Teletransporte();
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
                    if (ataques.CheckHit(coordenada))
                    {
                        dragones.EliminarDragon(coordenada);
                    }
                }
            }

            if (DescansoDañoRecibido.Esperar(0.1))
            {
                for (auto &&coordenada : coordenadas)
                {
                    if (personaje.VerificarEstado(coordenada))
                    {
                        personaje.RecibirDaño();
                        if (personaje.GetVida() <= 0)
                        {
                            return 0;
                            break;
                        }
                    }
                }
            }
            window.clear();
            mapa.draw(window);
            personaje.draw(window);
            dragones.draw(window);
            ataques.draw(window);

            window.display();
        }
        ataques.EliminarTodo();
        nivel.SiguienteNivel();
        personaje.TeletransportarOrigen();
    }
    return 0;
}
