# Dungeon Crawler
# Descripcion 
"Un "dungeon crawl" es un tipo de escenario en juegos de rol de fantasía 
en el que los héroes exploran un entorno de laberinto (un "calabozo"), 
luchando contra varios monstruos, evitando trampas, resolviendo acertijos y saqueando cualquier tesoro que puedan encontrar. 
Los videojuegos y juegos de mesa que presentan predominantemente elementos de "dungeon crawl" se consideran parte de este género."
En este proyecto se piensa adoptar esta idea para hacer un videojuego de vista superior influenciado por el juego "Moonlighter" del estudio "11 bit studios"

# Objetivo 
Realizar una demo jugable con la tematica de un Dungeon Crawler donde se pueda atacar a los enemigos y a la vez estos te ataquen para poder matarte

# Carpetas 
- bin/ - Contiene los ejecutables del proyecto 
- src/ - Contiene el codigo fuente 
- include/ - Los archivos de cabecera 
- assets/ - Contiene los recursos del proyecto 
- docs/ - Contiene la documentacion del archivo 

# Funcionamiento 
## Ataque.hpp
- La clase Ataque maneja una entidad de ataque en un juego, controlando su posición, movimiento, animación y duración activa. 
- Utiliza una instancia de Imagen para representar el ataque, moviéndola desde coordenadas iniciales (x, y) a finales (fx, fy) y cambiando su imagen cada pocos pasos para simular animación. 
- También incluye métodos para dibujar el ataque en una ventana y para verificar si el ataque sigue activo basándose en un temporizador interno.

## Dragon.hpp
- La clase Dragon maneja una entidad de dragón en un juego, controlando su nivel, posición y movimiento. 
- Utiliza una instancia de Imagen para representar el dragón, permitiendo actualizar su nivel y moverlo hacia unas coordenadas específicas, ajustando su imagen para simular animación. 
- Incluye métodos para incrementar o decrementar el nivel, mover el dragón siguiendo unas coordenadas dadas y dibujar el dragón en una ventana.

## Imagen.hpp
- La clase Imagen gestiona sprites en un juego utilizando SFML. 
- Carga una textura de archivo, permite cambiar la porción visible de la textura basada en coordenadas dadas, y maneja el movimiento y posicionamiento del sprite. 
- Verifica que las coordenadas estén dentro de un rango válido y proporciona métodos para obtener el sprite, cambiar su imagen, posicionarlo y moverlo. 
- Si no se puede cargar la textura, lanza un error.

## Personaje.hpp 
- La clase Personaje gestiona un personaje en un juego, combinando una forma rectangular de SFML y una imagen (Imagen). 
- Inicializa el personaje con una posición y color, y ajusta el sprite de Imagen a la misma posición. Proporciona métodos para mover el personaje, obtener su posición actual y dibujarlo en una ventana. 
- La velocidad de movimiento es configurable y la imagen del personaje se establece inicialmente a una porción específica de la textura.

- Jose Manuel Velazquez 23110161
- Andres Flores Bañuelos 23110155