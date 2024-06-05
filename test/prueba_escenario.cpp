#include <Escenario.hpp>
#include <iostream>


/*int main() {
    const int filas = 25;
    const int columnas = 25;

    // Declarar una matriz estática de 25x25
    int matriz[filas][columnas];

    // Configurar el generador de números aleatorios
    std::random_device rd;  // Objeto para obtener una semilla
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_int_distribution<> dis(1, 3); // Distribución uniforme entre 1 y 3

    // Llenar la matriz con números aleatorios del 1 al 3
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = dis(gen);
        }
    }

    // Agrupar los números 3
    bool encontrado = false;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] == 3 && !encontrado) {
                encontrado = true;
            } else if (matriz[i][j] == 3 && encontrado) {
                matriz[i][j] = matriz[i][j-1];
                matriz[i][j-1] = 3;
            }
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Mapa");
    Escenario escenario;
    return 0;
}
