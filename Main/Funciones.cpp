#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "funciones.h"

using namespace std;

//Declaracion de variables a utilizar
string ListaPokemon[12] = {"Blastoise", "Gyarados", "Vaporeon", "Charizard", "Arcanine", "Flareon", "Venusaur", "Sceptile", "Leafeon", "Raichu", "Ampharos", "Jolteon"};
int VidaPokemones[12] = {79, 95, 130, 78, 90, 65, 80, 70, 65, 60, 90, 65};
int TotalPokemon = 12;


//Funciones de usos basicos

void Logo() //Imprime en la consola el logo de Pókemon en formato ASCII
{
    // Se utiliza R "()" para definir un "Raw String" que permita compilar caracteres especiales
    cout << R"(
                                      ,'\
         _.----.       ____         ,'  _\   ___    ___     ___
     _,-'       `.    |    |  /`.   \,-'    |   \  /   |   |    \  |`.
    \      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
     \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
       \    \/   /,' _`.|       ,'/ / / /   |          ,' _`.|     |  |
        \     ,-'/  / \ \     ,'  | \/ / ,`.|         /  / \ \  |     |
         \    \ |   \_/  |    `-. \    `'  /|  |    ||   \_/  | |\    |
          \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
           \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
            \_.-'       |__|    `-._ |               '-.|    '-.| |   |
                                    `'                            '-._|
    )" << "\n";
}

void Bienvenida() // Banner inicial de bienvenida a los jugadores
{
    cout << "                    ========================================\n";
    cout << "                        BIENVENIDOS A LA BATALLA POKEMON               \n";
    cout << "                    ========================================\n";
}

void pausar() // Permite detener el programa, y espera una accion del usuario.

{
    cout << "\nPresione Enter para continuar..."; // Mensaje para el usuario
    if (cin.peek() == '\n') // Verifica si quedó un salto de línea
        cin.ignore(); // Ignora el salto de linea
    cin.get(); // Detiene el programa hasta que se ejecute la accion solicitada
}

bool Invalido() // Validación del tipo de dato de la entrada del usuario
{
    if (cin.fail()) // Verifica si la entrada falló
    {
        cin.clear(); // Limpia el error que presenta 'cin'
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Borra todos los caracteres inválidos
        cout << "\nEntrada invalida! Por favor, ingresa un numero entero.\n";
        pausar(); // Detiene el programa para que el usuario lea el 'Error'
        return true; // Retorna que SÍ hubo un error
    }
    return false; // Retorna false si NO hubo un error
}

//Funciones para la configuracion inicial 

int GenerarMenu() //Genera el menu principal del juego 
{
    int opcion;

    do
    {

        cout << endl<< endl;
        cout << "=====================\n"; //Se imprimen las opciones disponibles en el menu
        cout << "         MENU       \n";
        cout << "=====================\n";
        cout << "1. Nueva partida\n";
        cout << "2. Cargar partida\n";
        cout << "3. Salir\n";
        cout << "=====================\n";
        cout << "Para continuar seleccione una opcion: ";
        cin >> opcion;

        if (Invalido()) //Validación del tipo de dato de entrada del usuario
        {
            opcion = 0; // Se asigna un valor fuera de rango para forzar la repeticion del while
            continue; // Detiene la iteracion/ repeticion del bucle y comprueba directamente 
        }

        else if (opcion < 1 || opcion > 3)
        {
            cout << "\nOpcion invalida. Intenta nuevamente. \n" << endl;
        }

    } while (opcion < 1 || opcion > 3);

    return opcion;
}

string NuevaPartida()
{
    string NombrePartida;

    cout << "=========================================\n";
    cout << "            PARTIDA NUEVA              \n";
    cout << "=========================================\n\n";

    cout << "Ingrese un nombre para la nueva partida: ";
    cin >> NombrePartida;

    NombrePartida = NombrePartida + ".txt"; //Estandariza la extension del archivo creado

    ofstream archivo;
    archivo.open(NombrePartida); // Abre/crea un archivo 

    if (!archivo.is_open()) //Validacion para determinar si se creo el archivo
    {
        cout << "Error al crear la partida.\n";
        return ""; // Retorna un string vacio como indicador de un error
    }
    else
    {
        cout << "Partida '" << NombrePartida << "' creada con exito!\n"; //Aviso al jugador de la creacion de la partida
        archivo.close(); // Cierre del archivo creado

        pausar(); //Se detiene la ejecución del programa
    }

    return NombrePartida;
}

void PerfilJugador(int NumeroJugador, string &j1) // Funcion para la creacion de perfiles
{
    system("cls"); // Comando del sistema operativo para limpiar la pantalla de la terminal

    cout << "===================\n";
    cout << "     JUGADOR " << NumeroJugador << "\n";
    cout << "===================\n\n";

    cout << "Ingrese su nombre de usuario: ";
    cin >> j1;
}

void SeleccionEquipo(string NombreJugador, int EquipoActual[6], int Vida[6], int Maximo)

{
    int opcion;

    for (int i = 0; i < Maximo; i++)
    {
        do
        {
            system("cls"); // Comando para limpiar la pantalla de la consola
            cout << "======================================================\n";
            cout << "   SELECCIONA A TU EQUIPO " << NombreJugador << "!       \n";
            cout << "======================================================\n\n";

            cout << "Tu equipo actual (" << i << "/" << Maximo << "):\n"; //For anidado para mostrar los Pokémon que se integran al equipo
            for (int j = 0; j < i; j++)
            {
                cout << " - " << ListaPokemon[EquipoActual[j]] << "\n";
            }

            if (i == 0)
            {
                cout << " [Vacio]\n";
            }

            cout << "\n------------------------------------------------------\n";
            cout << "Elige tu Pokemon numero " << i + 1 << ":\n";

            for (int k = 0; k < 12; k++)
            {
                cout << k + 1 << " - " << ListaPokemon[k] << "\n";
            }

            cout << "\nSelecciona un pokemon (1 - 12): ";
            cin >> opcion;

            if (Invalido())
            {
                opcion = -1; //Se le asigna un valor fuera de rango para forzar la repetición del bucle
                continue;
            }

            if (opcion < 1 || opcion > 12)
            {
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                pausar();
                continue;
            }

            bool Seleccionado = false; // Bander para el control de duplicados, inicia asumiendo el Pokemon disponible
            for (int j = 0; j < i; j++) //Recorre el arreglo del equipo
            {
                if (EquipoActual[j] == (opcion - 1)) // Se resta uno para comparar el Pokémon en el espacio correcto del arreglo
                {
                    Seleccionado = true; //Indicador de que el Pokémon ya se encuentra en el equipo
                    break; //Se rompe el bucle de busqueda de duplicados
                }
            }

            if (Seleccionado)
            {
                cout << "\n--ATENCION!--\n"<< ListaPokemon[opcion - 1] << " ya forma parte de tu equipo.\n";
                cout << "Por favor, selecciona un Pokemon diferente. \n";
                pausar();
                opcion = -1; //Invalida la opcion para poder pedir la entrada nuevamente
            }
        }

        while (opcion < 1 || opcion > 12);

        EquipoActual[i] = opcion - 1; //Permite registrar el indice del Pokémon seleccionado en el lugar correcto

        Vida[i] = VidaPokemones[EquipoActual[i]]; //Obtiene el valor de la vida del Pokémon seleccionado del arreglo general de vida 

        cout << "\n"
            << ListaPokemon[EquipoActual[i]] << " se ha unido a tu equipo!\n";
        pausar();
    }

    system("cls");

    cout << "======================================================\n";
    cout << "   TU EQUIPO ESTA COMPLETO " << NombreJugador << "!       \n";
    cout << "======================================================\n\n";

    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << " - " << ListaPokemon[EquipoActual[i]] << "\n";
    }

    pausar();
}

void GuardarPartida(string NombreArchivo, string j1, int Equipo1[], int Vida1[], int ActualJ1, string j2, int Equipo2[], int Vida2[], int ActualJ2, int turno)
{
    ofstream archivo;
    archivo.open(NombreArchivo);

    if (!archivo.is_open())
    {
        cout << "\n--ERROR--\nNo se pudo guardar la partida.\n";
        return;
    }

    //Se registran las variables de control de estado del juego
    archivo << j1 << "\n";
    archivo << j2 << "\n";
    archivo << ActualJ1 << "\n";
    archivo << ActualJ2 << "\n";
    archivo << turno << "\n";

    //Escribe el numero de Pokémon y sus puntos de vida, del Equipo del Jugador 1
    for (int i = 0; i < 6; i++)
    {
        archivo << Equipo1[i] << " " << Vida1[i] << "\n";
    }

    //Para las variables del Equipo del Jugador 2
    for (int i = 0; i < 6; i++)
    {
        archivo << Equipo2[i] << " " << Vida2[i] << "\n";
    }

    archivo.close();
    cout << "Partida guardada exitosamente!\n";
}

bool CargarPartida(string &NombreArchivo, string &j1, int EquipoJ1[], int Vida1[], int &ActualJ1, string &j2, int EquipoJ2[], int Vida2[], int &ActualJ2, int &turno)
{
    system("cls");

    cout << "=========================================\n";
    cout << "            CARGAR PARTIDA               \n";
    cout << "=========================================\n\n";

    cout << "Ingrese el nombre de su partida: ";
    cin >> NombreArchivo;

    NombreArchivo = NombreArchivo + ".txt";

    ifstream archivo;
    archivo.open(NombreArchivo);

    if (!archivo.is_open()) //Evalúa si el archivo no existe o si el nombre ingresado es incorrecto
    {
        cout << "\nNo se encontro ninguna partida con el nombre '" << NombreArchivo << "'\n";
        cout << "Intentelo nuevamente.\n\n";

        NombreArchivo = ""; //Reinicia el nombre a vacio para no cargar ninguna partida
        pausar();
        return false; //Retorna falso para volver a mostrar el menu inicial
    }

    //Se extraen las variables en el mismo orden en el que se guardaron
    archivo >> j1;
    archivo >> j2;
    archivo >> ActualJ1;
    archivo >> ActualJ2;
    archivo >> turno;

    // Se extraen por parejas ordenadas el numero y vida de los Pokémon del Jugador 1
    for (int i = 0; i < 6; i++)
    {
        archivo >> EquipoJ1[i] >> Vida1[i];
    }

    // Del mismo modo para los Pokémon del Jugador 2
    for (int i = 0; i < 6; i++)
    {
        archivo >> EquipoJ2[i] >> Vida2[i];
    }

    archivo.close();

    cout << "\nLa partida '" << NombreArchivo << "' se cargo con exito!\n";
    cout << "Jugadores en la batalla: " << j1 << " VS " << j2 << "\n\n";

    pausar();
    return true;
}




