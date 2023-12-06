# Modelamiento 

Nuestro modelamiento fue muy abrupto al inicio pues mientras desarrollabamos más el proyecto, notabamos que más cosas en realidad se podrian incluir en otras por asi decirlo, simplemente parte del proceso de desarrollo y descubrimiento del modo de realizar nuestro juego.

### Clases

* Conevision
* Entities
* headMeezek
* Meezek
* Particle
* Resources
* Rick
* Scenery
* Text
* Videogame
* Weapon

# Modelamiento Final

### Clase Conevision

Public:
* Constructores de la Clase
* Booliano para checkear si rick esta dentro de la zona de vision

### Clase Entities

Private:
* Puntero Rick
* Variables QGraphicsView, QScreen <- para la resolucion
* Posición de la cámara en X, Y
* Flotante Aleatorio

Public:
* Metodos para los cálculos de los comportamientos de los meezeks y sus rotaciones respectivas de los sprites
* Setter, Getter

### Clase headMeezek

-> Clase construida para llevar a cabo las constantes del movimiento de los meezek

### Clase Meezek

Private:
* Stat-checkeos de los Meezeks (enemigos)
* Constantes para el Sprite
* FX
* Constantes para la física implementada (MRUA)

Public:
* Getter, Setter y actualizaciones para el sprite y stat-checkers de nuevo

Slots:
* Animaciones segun la señal

Signal:
* Rick pasa de vivo a muerto segun esta señal

### Clase Particle

Private:
* Constantes y variables para la física implementada (Habilidad/Especial)

Public:
* Constructores, actualizar la posición y el checkeo de colision

### Clase Resources

Public:
* Todas las rutas de los recursos utilizados para el juego (Sprites, Imagenes, Videos, etc...)

### Clase Rick

Public:
* Metodos para actualizar el sprite y Stat-checkeaer a nuestro protagonista

Slots:
* Animación de golpe

### Clase Scenery

Private:
* Pixmap, GraphicsScene  <- para nuestro mapa o escenario de juego

Public:
* Constructor de la clase y las máscaras de colisión

### Clase Texto

Private:
* Guarda los items encargados de dibujar texto
* Guarda la fuente especial usada para nuestro juego

Public:
* Constructora y un metodo para cambiar texto de manera eficaz

### Clase Weapon

Private:
* Checkeo de si el arma fue lanzada
* Constantes para el calculo de la friccion ejercida en el cuerpo
* Colisión y Sonido

Public:
* Constructora de Clase
* Getter, Setter y Inicializacion de la vel inicial una vez soltada de las manos de rick


### Clase Videojuego
-> Esta es la clase más vasta y grande de nuestro proyecto

Private:
* Lleva los punteros de todos nuestro personajes puesto en escena (Rick, Meezeks, Arma <- ese no es personaje pero si es algo que ponemos en escena)
* Lleva toda la información relacionada con la reproducción de audios con respecto a las acciones que se realizan (Golpe->Suena, ArmaLanzada->Suena, etc)
* Listado de Meezeks para verificar cuantos hay en escena y asi dar por terminado un nivel
* El escenario donde se juega (Mapas)
* Habilidad principal de rick
* Las dimensiones para nuestro sistema de cámara dinamico
* Contadores para la habilidad de energia cinetica
* Los estados de las teclas presionadas (Movimiento WASD)
* Valor del Combo

Public:
* Instancia del juego entero
* Lanzar Arma
* Habilitar el poder
* Inicializar videojuego
* Muerte del Rick, Finalizar Juego, Animación del menu principal
* Cada nivel implementado (LVL1,LVL2,LVL3)
* Reproducción del video inicial
* Status

Signals:
* Cambio de nivel y realizar animación de golpe (Esto es más para que se reproduzca de manera correcta)





