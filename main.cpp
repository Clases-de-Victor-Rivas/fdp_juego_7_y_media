/**
Programa:       Juego de las 7 y media.
Autor:          Víctor Rivas <vrivas@ujaen.es>
Fecha:          07-Nov-2020
Versión:        4
Descripción:    Creo dos jugadores, para que puedan jugar. En esta versión, solo guardo sus puntos; más adelante guardaré las cartas que le han salido.
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Declaramos el struct carta
    struct Carta {
        // Valor es un char que puede tomar los valores de '1' a '7', más 'J' (Sota), 'Q' (Caballo) y 'K' (Rey)
        char valor;
        // Palo es un string que puede tomar los valores "Oros", "Copas", "Espadas" y "Bastos"
        string palo;
        // Puntuación toma los valores 1 a 7, y también 0.5 (todas las Sotas, Caballos y Reyes valen 0.5)
        double puntuacion;
    };

   // Máximo número de cartas de la baraja
   const int MAX_CARTAS = 40;

   // Baraja de cartas inicializada por el método de la "fuerza" bruta.
   Carta baraja[40] =  {
        {'1',"Oros",1},{'2',"Oros",2},{'3',"Oros",3},{'4',"Oros",5},{'5',"Oros",1},
        {'6',"Oros",6},{'7',"Oros",7},{'J',"Oros",0.5},{'Q',"Oros",0.5},{'K',"Oros",0.5},
        {'1',"Copas",1},{'2',"Copas",2},{'3',"Copas",3},{'4',"Copas",5},{'5',"Copas",1},
        {'6',"Copas",6},{'7',"Copas",7},{'J',"Copas",0.5},{'Q',"Copas",0.5},{'K',"Copas",0.5},
        {'1',"Espadas",1},{'2',"Espadas",2},{'3',"Espadas",3},{'4',"Espadas",5},{'5',"Espadas",1},
        {'6',"Espadas",6},{'7',"Espadas",7},{'J',"Espadas",0.5},{'Q',"Espadas",0.5},{'K',"Espadas",0.5},
        {'1',"Bastos",1},{'2',"Bastos",2},{'3',"Bastos",3},{'4',"Bastos",5},{'5',"Bastos",1},
        {'6',"Bastos",6},{'7',"Bastos",7},{'J',"Bastos",0.5},{'Q',"Bastos",0.5},{'K',"Bastos",0.5}
   }; // Fin de inicialización de la baraja

       // Intercambio cartas al azar. Se hace asignación de structs enteros.
    for( int i=0; i<MAX_CARTAS-10; ++i ) {
        int intercambiar_con = rand()%MAX_CARTAS;
        Carta aux = baraja[i];
        baraja[i] = baraja[intercambiar_con];
        baraja[intercambiar_con]=aux;
   }

   // Declaro el struct Player
   // Aunque lo he puesto aquí, por seguir con la progresión en las versiones, en la siguiente versión irá al principio, con al declaración de todos los structs
   struct Player {
        string nombre;
        double puntos;
   };

   // Defino dos Playeres
   Player player1 = {"Ana", 0};
   Player player2 = {"Benito", 0};



    // Comprobamos que funciona:
    cout << "Los jugadores son: " << endl;
    cout << player1.nombre << " con " << player1.puntos << " puntos" << endl;
    cout << player2.nombre << " con " << player2.puntos << " puntos" << endl;
    cout << endl;

    return 0;
}


