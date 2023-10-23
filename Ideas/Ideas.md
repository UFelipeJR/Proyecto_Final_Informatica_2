# Ideas Proyecto Informática II

## Integrantes
* Felipe Jiménez Ramírez
* Santiago Pareja Pareja

## Episodio base:
* Rick and Morty Episodio 5 Temporada 1 

## Posibles nombres del juego:

* Intruder
* Intruder: Rick and Morty Adventure
* Meeseeks Invasion

## Historia del episodio:

El episodio trata sobre unas criaturas llamadas Meeseeks, quienes fueron creadas para realizar una tarea en específico y después morir, Rick y Morty deciden ir de aventura a otra dimensión, mientras que el resto de la familia hacían uso de una caja generadora de Meeseeks para realizar varias tareas. El problema empieza cuando Jerry, el papá de Morty desea mejorar su técnica de golf, pero estas criaturas se ven incapaces de ayudar en esta tarea, todo termina por descontrolarse al punto de que un Meeseek busca ayuda en otro de su misma especie, hasta que les da una crisis existencial y deciden matar a Jerry, ya que este era incapaz de lograr su objetivo, para acabar con su tormento, finalmente Jerry logra mejorar su técnica haciendo que todos los Meeseeks desaparezcan.

## Argumento del videojuego:

El videojuego Intruder funciona a modo de spinoff o what if, en el que los Meeseeks terminan por convertirse en una plaga que se extendería a lo largo del mundo, los Meeseeks lograron matar a Jerry, pero se dieron cuenta de que esta acción no era la solución del problema, y en búsqueda de un sentido de su existencia, decidieron tomar la vida de la humanidad.

## Primera parte del juego:

Cinematica Inicial...

Opción de saltar cinematica si/no

Introducir a rick, fecha distinta al episodio, ponemos a rick en una habitacion y lo ponemos al frente de un intercom y que le hable. Aqui rick dice "jerry eres un idiota" y se pone
la pantalla en negro para la transicion al menu del juego como tal.

### Pancarta del menu principal...
    INTRUDER
    // Diseño principal

    JUGAR

    AJUSTES -> Volumen

    SALIR

    JUGAR -> Accede a la historia del juego

## Desarrollo del juego:

La cinematica introductoria

![Alt text](https://i.imgur.com/FE5xGGH.png)

Primer acto (Clean up), Se muestra la cinematica del restaurante, se hace un timelapse
entra rick desde un portal y mata a todos los meeseks del cuarto, aqui es donde
tiene que buscar una llave para desbloquear la puerta de atrás y poder ver el
congelador donde tenian a jerry, que pues en esta ocasión ya esta muerto.

![](https://i.imgur.com/TOVoW41.png)

Segundo acto (Avenue), el nivel de la calle, para darle una entrada mucho más organica y coherente a la llegada de la casa de los padres de morty y para mostrar el caos generado por la plaga

![](https://i.imgur.com/HvldZUT.png)

![](https://i.imgur.com/EYYnvTD.png)

Tercer acto (Full house), el nivel de la casa, para darle un final rick logra llegar a la casa donde encuentra a beth como rehen de varios meeseks, el nivel más grande y complicado del juego por ahora esta en etapa de definción.

Creditos finales.

## Visualización del HUD

![](https://i.imgur.com/aFexfc4.png)

## Mécanicas del juego:

### *Tipo de vista*: Cenital

### *Juego en el que nos basamos*:

* Hotline Miami
![Alt text](https://i.imgur.com/2aWPpyj.jpg)
[Enlace Video](https://www.youtube.com/watch?v=fGzsLU4slGk)<br>
Hotline miami es un juego que funciona de la misma vista que seleccionamos, es un juego arcade shooter, con un estilo artistico de pixeles, y mucha sangre, decidimos optar por este juego ya que aparte de ser una aproximación muy bien enfocada tenemos bastantes ideas para implementar con la manera que ponemos el juego a disposición. No obstante tenemos en cuenta de que fiel al juego no será.



## *Escenarios*:

* Pueblo:

![Alt text](https://i.imgur.com/2Zsf7pv.png)

* Restaurante:

![Alt text](https://i.imgur.com/YuO80uI.png)
 

## *Movimiento*:

El movimiento constara de 8 direcciones, especificamente norte, sur, este, oeste, nordeste, noreste, sureste, surdeste, para los controles seran especificamente W, A, S, D.

Para la cuestión de apuntar, será construido con el cursor, el cual dara la dirección de donde estara apuntando nuestro personaje.

## *Combate*:
El tipo de combate que deseamos implementar es de tipo melee, que en pocas es combate mano a mano o dicho de otra manera cuerpo a cuerpo, en ese orden de ideas, los ataques disponibles serían un golpe convencional y el uso de un bate, también se desea incluir una modalidad tipo glory kill, la cuál se basa en un tipo de remate.

## *Enemigos*:

![Alt text](https://i.imgur.com/3tfr5eE.png)<br>

Los enemigos serán los Meeseeks, que como se logra observar son el mismo modelo, pero con algunos cambios, lo cual vuelve más sencillo el proceso de creación de los sprites.

## *Puntuación*:

Para nuestro juego implementaremos un sistema de puntuación un poco simple pero muy efectivo que se basara en un multiplicador por combo, cada enemigo se supone que da 500 puntos, pero con la mecánica que vamos a implementar por cada enemigo abatido consecutivo dara eso multiplicado por el anterior, es decir si matas 2, terminara 2x500, equivaliendo a mil, para modo del juego este no tendra ningún tipo de limite, salvo que ya no hayan enemigos por matar o el jugador muera en el intento de mantener la racha.


## *Música*:

Por definir. 