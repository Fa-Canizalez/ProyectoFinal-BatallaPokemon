#ifdef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <limits>
#include <fstream>
#include <string>

using namespace std;

//Funciones para usos basicos
void Logo();
void Bienvenida();
void pausar();
bool Invalido();

//Funciones para la configuracion inicial
int GenerarMenu();
string NuevaPartida();
void PerfilJugador(int NumeroJugador, string &j1);
void SeleccionEquipo(string NombreJugador, int EquipoActual[6], int Vida[6], int Maximo);

//Funciones para el desarrollo de la BATALLA POKÉMON
void verificacion(string j1, string j2, int poke1[], int poke2[], int vidaJ1[], int vidaJ2[], int &turno, bool &juego, int &ganador, int &actualJ1, int &actualJ2);
int menu(int turno, string j1, string j2);
void ataque1(int vidaJ1[], int vidaJ2[], int poke1[], int poke2[], int dano[12][2], int actualJ1, int actualJ2, int &turno);
void ataque2(int vidaJ1[], int vidaJ2[], int poke1[], int poke2[], int dano[12][2], int actualJ1, int actualJ2, int &turno);
void cambio(string ListaPokemon[], int poke1[], int poke2[], int vidaJ1[], int vidaJ2[], int &actualJ1, int &actualJ2, int &newSelect, int &turno);
void rendirse(int &ganador, bool &juego, int &turno);
void OpcionInvalida(int &turno);


//Funciones para guardar datos
void GuardarPartida(string NombreArchivo, string j1, int Equipo1[], int Vida1[], int ActualJ1, string j2, int Equipo2[], int Vida2[], int ActualJ2, int turno);
bool CargarPartida(string &NombreArchivo, string &j1, int EquipoJ1[], int Vida1[], int &ActualJ1, string &j2, int EquipoJ2[], int Vida2[], int &ActualJ2, int &turno)

//Funcion para determinar el Final de la Partida
void DeterminarGanador(int ganador, string j1, string j2);

#endif