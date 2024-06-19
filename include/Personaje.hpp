#pragma once
#include <Imagen.hpp>
#include <Contador.hpp>

class Personaje
{
private:
    Imagen prota, barraVida;
    Contador reloj;
    float offsetX, offsetY;
    double velocidad = 5;
    bool teletransporteHabilitado = false;
    sf::Vector2f dimencionesVentana;
    int CantidadVida = 4;

public:
    Personaje(sf::Vector2f posicion)
    {
        dimencionesVentana = posicion;
        this->prota.cambiarImagen(1, 61);
        this->barraVida.cambiarImagen(61, 50);
        barraVida.mover(posicion.x / 2, posicion.y / 2 + 10);
        prota.mover(posicion.x / 2, posicion.y / 2);
    }
    void ActualizarVida()
    {
        switch (CantidadVida)
        {
        case 4:
            barraVida.cambiarImagen(61, 50);
            break;
        case 3:
            barraVida.cambiarImagen(62, 50);
            break;
        case 2:
            barraVida.cambiarImagen(60, 50);
            break;
        case 1:
            barraVida.cambiarImagen(63, 50);
            break;
        case 0:
            barraVida.cambiarImagen(60, 1);
            break;
        default:
            break;
        }
    }
    void RecibirDaño()
    {
            CantidadVida--;
            ActualizarVida();
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(prota.getSprite());
        window.draw(barraVida.getSprite());
    }

    sf::Vector2f GetPosicion()
    {
        return prota.coordenadas;
    }

    void MoverAlPersonaje(float offsetX, float offsetY)
    {
        offsetX = offsetX * velocidad;
        offsetY = offsetY * velocidad;
        prota.mover(offsetX, offsetY);
        barraVida.mover(offsetX, offsetY);
        velocidad = 10;
    }

    void TeletransportarOrigen()
    {
        prota.mover(-prota.coordenadas.x,-prota.coordenadas.y);
        barraVida.mover(-barraVida.coordenadas.x,-barraVida.coordenadas.y);

        prota.mover(dimencionesVentana.x / 2, dimencionesVentana.y / 2);
        barraVida.mover(dimencionesVentana.x / 2, dimencionesVentana.y / 2 + 10);
        
    }

    void Correr()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (GetPosicion().x > 0)
            {
                MoverAlPersonaje(-1, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (GetPosicion().x < dimencionesVentana.x - 32)
            {
                MoverAlPersonaje(1, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (GetPosicion().y > 0)
            {
                MoverAlPersonaje(0, -1);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (GetPosicion().y < dimencionesVentana.y - 52)
            {
                MoverAlPersonaje(0, 1);
            }
        }
    }
    void Teletransporte()
    {
        if (reloj.Esperar(2))
        {
            this->teletransporteHabilitado = true;
            this->velocidad = 150;
            Correr();
        }
    }
    bool VerificarEstado(sf::Vector2f enemigo){
        if (enemigo.x - prota.coordenadas.x < 32 &&
            enemigo.x - prota.coordenadas.x > -32 &&
            enemigo.y - prota.coordenadas.y < 32 &&
            enemigo.y - prota.coordenadas.y > -32)
        {
            return true;
        }else {
            return false;
        }
    }
    int GetVida(){
        return CantidadVida;
    }

    ~Personaje() {}
};