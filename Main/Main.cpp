
// Todas las librerias a utilizar
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Funciones.h"

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

    return 0;
}
