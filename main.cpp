/**
Programa:       Juego de las 7 y media.
Autor:          Víctor Rivas <vrivas@ujaen.es>
Fecha:          07-Nov-2020
Versión:        6
Descripción:    Almacenamos para cada jugador las cartas que le van saliendo.
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
        {'1',"Oros",1},{'2',"Oros",2},{'3',"Oros",3},{'4',"Oros",4},{'5',"Oros",5},
        {'6',"Oros",6},{'7',"Oros",7},{'J',"Oros",0.5},{'Q',"Oros",0.5},{'K',"Oros",0.5},
        {'1',"Copas",1},{'2',"Copas",2},{'3',"Copas",3},{'4',"Copas",4},{'5',"Copas",5},
        {'6',"Copas",6},{'7',"Copas",7},{'J',"Copas",0.5},{'Q',"Copas",0.5},{'K',"Copas",0.5},
        {'1',"Espadas",1},{'2',"Espadas",2},{'3',"Espadas",3},{'4',"Espadas",4},{'5',"Espadas",5},
        {'6',"Espadas",6},{'7',"Espadas",7},{'J',"Espadas",0.5},{'Q',"Espadas",0.5},{'K',"Espadas",0.5},
        {'1',"Bastos",1},{'2',"Bastos",2},{'3',"Bastos",3},{'4',"Bastos",4},{'5',"Bastos",5},
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
        // Nombre del jugador/a
        string nombre;

        // Puntos que lleva en la partida por las cartas que le salen
        double puntos;

        // Si es true, puede seguir jugando; si es false, no.
        bool sigue_jugando;

        // Cartas que le van saliendo durante la partida
        Carta mis_cartas[MAX_CARTAS];

        // Número de cartas que le han salido
        int num_cartas;
   };

   // Defino dos Playeres
   Player player1 = {"Ana", 0, true};
   Player player2 = {"Benito", 0, true};


   // Empieza la partida a partir de aquí

   // Proxima_carta indica la próxima carta a repartir
   int proxima_carta = 0;

   // Asigno primero una carta a cada uno
   player1.mis_cartas[player1.num_cartas]=baraja[proxima_carta];
   player1.puntos+=baraja[proxima_carta].puntuacion;
   cout << "La primera carta para " << player1.nombre << " es "
        << baraja[proxima_carta].valor << "-" << baraja[proxima_carta].palo[0] << endl;
   ++player1.num_cartas;
   ++proxima_carta;

   player2.mis_cartas[player2.num_cartas]=baraja[proxima_carta];
   player2.puntos+=baraja[proxima_carta].puntuacion;
   cout << "La primera carta para " << player2.nombre << " es "
        << baraja[proxima_carta].valor << "-" << baraja[proxima_carta].palo[0] << endl;
   ++player2.num_cartas;
   ++proxima_carta;


    // Reparto cartas alternativamente a uno y a otro.
   do {
        char respuesta;
        // Si el jugador/a 1 puede seguir jugando, le pregunto si quiere más cartas.
        if( player1.sigue_jugando ) {
            cout << endl
                << player1.nombre << " tienes " << player1.puntos << " puntos. " << endl;
            cout << "  ¿Quieres otra carta? ";
            cin >> respuesta;
            if (respuesta=='S' || respuesta=='s') {
                // Añado la carta que le ha salido
                player1.mis_cartas[player1.num_cartas]=baraja[proxima_carta];
                // Añado la puntuación de la carta
                player1.puntos+=baraja[proxima_carta].puntuacion;
                cout << "  Se te añade una carta con " << baraja[proxima_carta].puntuacion << " puntos; ahora tienes "
                    << player1.puntos << " puntos. " << endl;

                // Actualizo contadores
                ++player1.num_cartas;
                ++proxima_carta;
            } else {
                player1.sigue_jugando = false;
            }
        }


        // Si el jugador/a 2 puede seguir jugando, le pregunto si quiere más cartas.
        if( player2.sigue_jugando ) {
            cout << endl
                << player2.nombre << " tienes " << player2.puntos << " puntos. " << endl;
            cout << "  ¿Quieres otra carta? ";
            cin >> respuesta;
            if (respuesta=='S' || respuesta=='s') {
                // Añado la carta que le ha salido
                player2.mis_cartas[player2.num_cartas]=baraja[proxima_carta];
                // Añado la puntuación de la carta
                player2.puntos+=baraja[proxima_carta].puntuacion;
                cout << "  Se te añade una carta con " << baraja[proxima_carta].puntuacion << " puntos; ahora tienes "
                    << player2.puntos << " puntos. " << endl;

                // Actualizo contadores
                ++player2.num_cartas;
                ++proxima_carta;
            } else {
                player2.sigue_jugando = false;
            }
        }

   } while ( player1.sigue_jugando || player2.sigue_jugando );


    // Imprimimos las puntuaciones
    cout << endl << endl;
    cout << "Los jugadores han quedado así: " << endl << endl;
    cout << player1.nombre << " con " << player1.puntos << " puntos" << endl;
    for ( int i=0; i<player1.num_cartas; ++i ) {
        cout << "   " << player1.mis_cartas[i].valor << "-" << player1.mis_cartas[i].palo[0] << endl;
    }
    cout << player2.nombre << " con " << player2.puntos << " puntos" << endl;
    for ( int i=0; i<player2.num_cartas; ++i ) {
        cout << "   " << player2.mis_cartas[i].valor << "-" << player2.mis_cartas[i].palo[0] << endl;
    }

    cout << endl;

    return 0;
}
