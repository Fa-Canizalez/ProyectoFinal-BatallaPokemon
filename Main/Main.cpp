
// Todas las librerias a utilizar
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Funciones.cpp"

using namespace std;

int main ()
{
    //Declaracion de variables globales

    string PokemonLista[12] = {"Blastoise", "Gyarados", "Vaporeon", "Charizard", "Arcanine", "Flareon", "Venusaur", "Sceptile", "Leafeon", "Raichu", "Ampharos", "Jolteon"};

    int VidaPokemones[12] = {79, 95, 130, 78, 90, 65, 80, 70, 65, 60, 90, 65};

    int DanhoPokemones[12][2] = 
    {
        {45, 20},
        {30, 20},
        {40, 15},
        {30, 25},
        {30, 20},
        {40, 15},
        {30, 10},
        {30, 15},
        {50, 15},
        {30, 20},
        {25, 15},
        {25, 20},
    };

    int Equipo1[6], Vida1[6], Equipo2[6], Vida2[6];
    int opcionMenu = 0, opcionBatalla = 0;
    int PokemonActual1 = 0, PokemonActual2 = 0, turno = 1, ganador, Seleccionado = 0;

    string Jugador1 = "", Jugador2 = "", NombrePartida = "";
    bool juego = false;

    //Inicio del Juego
    system("cls"); // Comando para limpiar la pantalla de la consola 

    Logo(); // Funcion para generarl el logo de POKÉMON en ASCII
    Bienvenida(); // Funcion para imprimir un banner de bienvenida inicial
    pausar(); //Detiene la ejecucion del programa mientras espera una accion del usuario


while (opcionMenu != 3) // Bucle encargado de la repeticion del MENU PRINCIPAL
{
    opcionMenu = GenerarMenu(); //Funcion para generar el Menu incial dl juego

    switch (opcionMenu)
    {
        case 1: //Nueva Partida
            NombrePartida = NuevaPartida(); //Funcion para la creación de una partida nueva

            //Funciones para la creacion de los perfiles de cada jugador
            PerfilJugador (1, Jugador1); 
            SeleccionEquipo(Jugador1, Equipo1, Vida1, 6);
            
            PerfilJugador (2, Jugador2);
            SeleccionEquipo(Jugador2, Equipo2, Vida2, 6);

            juego = true; // Se cambia el estado del juego para pasar a la batalla

            cout << "\n---AUTOGUARDADO---\n";
            GuardarPartida(NombrePartida, Jugador1, Equipo1, Vida1, PokemonActual1, Jugador2, Equipo2, Vida2, PokemonActual2, turno); //Funcion para guardar la nueva partida
            break;

        case 2: 
            if (CargarPartida (NombrePartida, Jugador1, Equipo1, Vida1, PokemonActual1, Jugador2, Equipo2, Vida2, PokemonActual2, turno)) //Funcion para cargar una partida 
            {
                juego = true; // La carga correcta de la partida cambia el estado del juego para ir a la batalla
            }
            break;

        case 3: //Salir
            cout << "\nSaliendo del juego...\nHasta la proxima!\n";
            juego = false; //Se cambia el estado del juego para salir del bucle y salir del juego
        break;
    }

    while (juego == true) // Se entra al bucle si se cambio el estado de juego a true
    {
        verificacion(Jugador1, Jugador2, Equipo1, Equipo2, Vida1, Vida2, turno, juego, ganador, PokemonActual1, PokemonActual2); //Funcion para verificar que Pokémones siguen vivos
        
        if (juego == false) break; //Si se cambia el estado del juego se rompe el bucle que controla la batalla

        opcionBatalla = menu(turno, Jugador1, Jugador2); // Funcion para generar el Menu de opciones dentro de la batalla
        
            switch (opcionBatalla)
            {
                case 1:
                    ataque1(Vida1, Vida2, Equipo1, Equipo2, DanhoPokemones, PokemonActual1, PokemonActual2, turno); //Funcion para utilizar el Ataque 1
                break;

                case 2:
                    ataque2(Vida1, Vida2, Equipo1, Equipo2, DanhoPokemones, PokemonActual1, PokemonActual2, turno); // Funcion para el Ataque 2
                break;

                case 3:
                    cambio(ListaPokemon, Equipo1, Equipo2, Vida1, Vida2, PokemonActual1, PokemonActual2, Seleccionado, turno); //Funcion que permite cambiar de Pokémon durante la batalla
                break; 

                case 4:
                    rendirse(ganador, juego, turno); // Le permite al jugador rendirse y salir de la batalla
                break;

                default:
                    OpcionInvalida(turno); //Funcion que detecta una opcion valida y genera la perdida del turno de uno de los jugadores
                break;
            }

            if (juego == false) // Evalua si ha cambiado el estado del juego
            {
                break; // Permite romper el bucle en caso de que cambie el estado del juego a false
            }
        
    }

    opcionMenu = 3; // Se le asigna un valor a la variable que permite salir del bucle que controla el programa
}


    return 0;
}
