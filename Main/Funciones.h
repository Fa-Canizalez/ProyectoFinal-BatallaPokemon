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

//Funciones para guardar datos
void GuardarPartida(string NombreArchivo, string j1, int Equipo1[], int Vida1[], int ActualJ1, string j2, int Equipo2[], int Vida2[], int ActualJ2, int turno);
bool CargarPartida(string &NombreArchivo, string &j1, int EquipoJ1[], int Vida1[], int &ActualJ1, string &j2, int EquipoJ2[], int Vida2[], int &ActualJ2, int &turno)

#endif