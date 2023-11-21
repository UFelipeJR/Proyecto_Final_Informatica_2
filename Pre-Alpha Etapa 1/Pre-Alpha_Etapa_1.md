# Modelamiento 

### Clases

* Clase Rick 
* Clase Mezeek
* Clase Escenario - Scenary
* Clase Entidades - Entity
* Clase Videojuego - Videogame
* Clase Arma - Weapon
* Clase Rick 
* Clase Recursos
* Clase conoVision


# Modelamiento Inicial Propenso a Cambios

### Clase Rick

Private:

    *Estados: Variables bool para indicar los estados del movimiento.
    *Variable para el manejo de sprites, como QPixmap y QTimer.
    *items de colisión
    *Sonidos

Public
    *Constructor
    *Destructor
    *Métodos de actualización y recorte de sprite
    *Métodos getter y setter

Private slots:
    *animacion
    *slots de ataque

### Clase Mezeek
Private:

    *Estados: Variables booleanas para indicar los estados del movimiento.
    *Manejo de sprites: Variables para el manejo de sprites, como QPixmap y QTimer.
    Items de colisión: Elementos relacionados con la detección de colisiones.
    Sonidos: Elementos relacionados con la reproducción de sonidos.

Public:

    *Constructor: Método para inicializar objetos de la clase.
    *Destructor: Método para liberar recursos y memoria cuando un objeto de la clase se destruye.
    *Métodos de actualización y recorte de sprite: Funciones para actualizar y recortar el sprite que se muestra en la interfaz gráfica.
    *Métodos getter y setter: Funciones públicas para acceder y modificar propiedades privadas de la clase.

Private slots:

    *Animación: Función de ranura que maneja la animación del objeto.
    *Slots de ataque: 


### Clase videogame
    Private:

    Contiene instancias de Rick, Mezeek, QTimer, QGraphicsView, QGraphicsScene, entities, coneVision, scenery, y un mapa de estados de teclas.
    Public:

    Constructor y destructor de la aplicación.
    Métodos para eventos de teclado y ratón.
    Métodos para controlar el juego, actualizar la visión de cono, mover los personajes y gestionar rotaciones.
    Slots:

    game: Función que gestiona la lógica principal del juego.
    Signals:

    punch: Señal



NOTA: EL resto del modelamiento está pendiente por ser publicado en el informe