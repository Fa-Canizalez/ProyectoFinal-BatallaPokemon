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

void pausar() // Permite detener el programa, y espera una accion del usuario. (Proporcionado por Gemini AI)

/*La IA sugirio el uso de las funciones de entrda cin.peek, cin.ignore y cin.get, como una opcion para 
detener momentaneamente la ejecución del programa, a partir de esa sugerencia se investigo el uso de estas funciones
para el desarrollo de la función pausar() */

{
    cout << "\nPresione Enter para continuar..."; // Mensaje para el usuario
    if (cin.peek() == '\n') // Verifica si quedó un salto de línea 
        cin.ignore(); // Ignora el salto de linea
    cin.get(); // Detiene el programa hasta que se ejecute la accion solicitada
}

bool Invalido() // Validación del tipo de dato de la entrada del usuario (Proporcionado por Gemini AI)

/*La IA brindó los comandos a utilizar para evitar un bucle infinito si un usuario ingresa un tipo de dato
de entrada erroneo, el equipo adapto lo proporcionado por la IA a una función reutilizable en otras partes del codigo*/
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

    //Funcion para seleccionar Equipos Pokémon
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

//Funciones para el Guardado de datos

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

//Funciones para el desarrollo de la BATALLA

    //Funcion de verificacion de la vida de los Pokémon
void verificacion(string j1, string j2, int poke1[], int poke2[], int vidaJ1[], int vidaJ2[], int &turno, bool &juego, int &ganador, int &actualJ1, int &actualJ2)
{
    //Evalúa si el Pokémon Actual del Jugador 1 se quedó sin vida despues del último ataque
    if (vidaJ1[actualJ1] <= 0)
    {
        cout << "\n======================================================";
        cout << "\n EL POKEMON " << ListaPokemon[poke1[actualJ1]] << " DE " << j1 << " SE HA DEBILITADO!";
        cout << "\n======================================================\n";

        int siguienteJ1 = -1; //Indicador de posicion neutro
        for (int i = 0; i < 6; i++) //Recorre el arreglo de vida del Equipo del Jugador 1
        {
            if (vidaJ1[i] > 0) //Condicion para detectar un Pokémon con vida restante
            {
                siguienteJ1 = i; // Se cambia el valor de la variable para guardar la posicion numerica del Pokémon vivo
                break; // Detiene el ciclo
            }
        }

        if (siguienteJ1 != -1) // Verifica si se encontro o no un Pokémon con vida
        {
            actualJ1 = siguienteJ1; // Se le asigna el nuevo valor a la variable para continuar el juego 
            
            cout << "\n  ["<< j1 << "]"<< " retira a su Pokemon debilitado...";
            cout << "\n   " << j1 << " envia a " << ListaPokemon[poke1[actualJ1]] << " a la batalla!\n";
            pausar();
            //Se finaliza la función sin modificar el estado del juego ni del ganador
            return;
        }
        else
        {
            //En caso de no encontrar un Pokémon vivo se le asigna como ganador al Jugador 2
            ganador = 2;
            juego = false; // Cambia el estado del juego para salir del bucle de la batalla
            return;
        }
    }

    //Proceso adaptado con las variables del Jugador 2
    else if (vidaJ2[actualJ2] <= 0)
    {
        cout << "\n======================================================";
        cout << "\n EL POKEMON " << ListaPokemon[poke2[actualJ2]] << " DE " << j2 << " SE HA DEBILITADO!";
        cout << "\n======================================================\n";

        int siguienteJ2 = -1;
        for (int i = 0; i < 6; i++)
        {
            if (vidaJ2[i] > 0)
            {
                siguienteJ2 = i;
                break;
            }
        }

        if (siguienteJ2 != -1)
        {
            actualJ2 = siguienteJ2;
            
            cout << "\n  ["<< j2 << "]" << " retira a su Pokemon debilitado...";
            cout << "\n   " << j2 << " envia a " << ListaPokemon[poke2[actualJ2]] << " a la batalla!\n";
            pausar();
            return;
        }
        else
        {
            ganador = 1;
            juego = false;
            return;
        }
    }
}

    //Función para menú de la batalla
int menu(int turno, string j1, string j2)
{
    int opcion;
    cout << endl<< endl;
cout << "=========================================\n";
cout << "           ES TU TURNO: " << (turno == 1 ? j1 : j2) << "!\n"; // Se usa un operador ternario para modificar el nombre en base al turno actual (1 o 2)
cout << "=========================================\n" 
        << "1. Usar ataque 1 \n"
        << "2. Usar ataque 2\n"
        << "3. Cambiar pokemon\n"
        << "4. Rendirse \n";
cout << "=========================================\n";
    cout << "Para continuar seleccione una opcion: ";
    cin >> opcion;

    if (Invalido()) //Validacion del tipo de entrada
    {
        opcion = 0;
    }

    else if (opcion < 1 || opcion > 4)
    {
        cout << "\nOpcion invalida. Intenta nuevamente. \n" << endl;
    }

    return opcion;
}

    // Función Ataque 1
void ataque1(int vidaJ1[], int vidaJ2[], int poke1[], int poke2[], int dano[12][2], int actualJ1, int actualJ2, int &turno)
{
    cout << "\nUsaste el ataque 1!\n" << endl;
    if (turno == 1)
    {
        //Se resta de la vida del rival el daño correspondiente al Pokémon actual y la columna de ataque '0'  
        vidaJ2[actualJ2] = vidaJ2[actualJ2] - dano[poke1[actualJ1]][0]; 

        if (vidaJ2[actualJ2] < 0) //Control para no mostrar valores negativos de vida 
        {
            vidaJ2[actualJ2] = 0;
        }
        cout << "Vida del rival: " << vidaJ2[actualJ2] << endl;
        turno = 2; // Se alterna el indicador de turno para darle paso al siguiente jugador
    }
    else
    {
        vidaJ1[actualJ1] = vidaJ1[actualJ1] - dano[poke2[actualJ2]][0];

        if (vidaJ1[actualJ1] < 0)
        {
            vidaJ1[actualJ1] = 0;
        }
        cout << "Vida del rival: " << vidaJ1[actualJ1] << endl;
        turno = 1; // Se alterna el indicador de turno
    }
}

    // Función Ataque 2
void ataque2(int vidaJ1[], int vidaJ2[], int poke1[], int poke2[], int dano[12][2], int actualJ1, int actualJ2, int &turno)
{
    cout << "\nUsaste el ataque 2!\n" << endl;
    if (turno == 1)
    {
        //Se resta de la vida del rival el daño correspondiente al Pokémon actual y la columna de ataque '1'
        vidaJ2[actualJ2] = vidaJ2[actualJ2] - dano[poke1[actualJ1]][1];

        if (vidaJ2[actualJ2] < 0)
        {
            vidaJ2[actualJ2] = 0;
        }
        cout << "Vida del rival: " << vidaJ2[actualJ2] << endl;
        turno = 2;
    }
    else
    {
        vidaJ1[actualJ1] = vidaJ1[actualJ1] - dano[poke2[actualJ2]][1];

        if (vidaJ1[actualJ1] < 0)
        {
            vidaJ1[actualJ1] = 0;
        }
        cout << "Vida del rival: " << vidaJ1[actualJ1] << endl;
        turno = 1;
    }
}

    // Función para cambiar pokemon
void cambio(string ListaPokemon[], int poke1[], int poke2[], int vidaJ1[], int vidaJ2[], int &actualJ1, int &actualJ2, int &newSelect, int &turno)
{
    // Menú que muestra los pokemon disponibles para cambiar
    cout << "\n================================" << endl;
    cout << "     POKEMONS EN TU EQUIPO:     " << endl;
    cout << "================================" << endl;

    if (turno == 1)
    {
        for (int i = 0; i < 6; i++) // Enumera a los Pokémon del Equipo del jugador 1
        {
            cout << i + 1 << "- " << ListaPokemon[poke1[i]] << " - Vida: " << vidaJ1[i] << endl;
            
            if (i == actualJ1) cout << " [EN COMBATE]"; // Recordatorio del Pokémon en uso
            if (vidaJ1[i] <= 0) cout << " [DEBILITADO]"; // Advertencia de Pokémon sin puntos de vida (no seleccionable)
            cout << endl;
        }

        cout << "\nEscoge un nuevo pokemon (1 - 6): " << endl;
        cin >> newSelect;

        if (Invalido())
        {
            newSelect = -1;
        }

        //Evaluacion para la seleccion de Pokémon debilitado o Pokémon en uso
        while (newSelect < 1 || newSelect > 6 || vidaJ1[newSelect - 1] <= 0 || (newSelect - 1) == actualJ1)
        {
            
            if (newSelect == -1) // Validacion para el tipo de dato de entrada
            {
                cout << "Ingrese unicamente un numero entero (1 - 6): ";
                cin >> newSelect;
                if (Invalido()) newSelect = -1;
            }
            //Subcondicion para impedir seleccionar el Pokémon en uso
            else if (newSelect >= 1 && newSelect <= 6 && (newSelect - 1) == actualJ1)
            {
                cout << "Pokemon en batalla. Selecciona uno diferente! : ";
                cin >> newSelect;
                if (Invalido()) newSelect = -1;
            }
            else 
            {
                cout << "Opcion incorrecta o Pokemon debilitado. Elige uno con vida: ";
                cin >> newSelect;
                if (Invalido()) newSelect = -1;
            }
        }

        //Realiza el cambio de Pokémon ajustandolo al índice base 0 del arreglo
        actualJ1 = newSelect - 1;

        cout << "\nHas envidado a " << ListaPokemon[poke1[actualJ1]] << " a la batalla!" << endl;
        turno = 2; //Cambio de turno
    }
    else
    {
        // Proceso adaptado a las varibales del Jugador 2
        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << "- " << ListaPokemon[poke2[i]] << " - Vida: " << vidaJ2[i] << endl;
            
            if (i == actualJ2) cout << " [EN COMBATE]";
            if (vidaJ2[i] <= 0) cout << " [DEBILITADO]";
            cout << endl;
        }

        cout << "\nEscoge un nuevo pokemon (1 - 6): " << endl;
        cin >> newSelect;

        if (Invalido())
        {
            newSelect = -1;
        }

        while (newSelect < 1 || newSelect > 6 || vidaJ2[newSelect - 1] <= 0 || (newSelect - 1) == actualJ2)
        {
            
            if(newSelect == -1)
            {
                cout << "Ingrese unicamente un numero entero (1 - 6): ";
                cin >> newSelect;
                if (Invalido()) newSelect = -1;
            }
            else if (newSelect >= 1 && newSelect <= 6 && (newSelect - 1) == actualJ2)
            {
                cout << "Pokemon en batalla. Selecciona uno diferente! : ";
                cin >> newSelect;
                if (Invalido()) newSelect = -1;
            }
            else
            {
            cout << "Opcion incorrecta o Pokemon debilitado. Elige uno con vida: ";
            cin >> newSelect;
            if (Invalido()) newSelect = -1;
            }
        }

        actualJ2 = newSelect - 1;

        cout << "\nHas envidado a " << ListaPokemon[poke2[actualJ2]] << " a la batalla!" << endl;
        turno = 1;
}
}

    // Función para rendirse
void rendirse(int &ganador, bool &juego, int &turno)
{
    cout << "Te has rendido " << endl;
    if (turno == 1)
    {
        ganador = 2; // Al rendirse el Jugador 1 se asigna como ganador el Jugador 2
        juego = false; // Se desactiva el juego 
    }
    else
    {
        ganador = 1; // Al rendirse el Jugador 2 se asigna como ganador al Jugador 1
        juego = false; // Desactivación del juego 
    }
}

    // Función para opción invalida
void OpcionInvalida(int &turno)
{
    cout << "Opcion invalida. Pierdes turno." << endl;
    if (turno == 1)
    {
        turno = 2; 
    }
    else
    {
        turno = 1;
    }
}

//Funciones el final de la partida

    //Funcion para determinar ganador
    void DeterminarGanador(int ganador, string j1, string j2)
{
    if (ganador == 1)
    {
        cout << "======================\n";
        cout << "  EL GANADOR ES " << j1 << "\n";
        cout << "======================\n";
        cout << "\nMUCHAS FELICIDADES " << j1 << endl;
    }
    else
    {
        cout << "======================\n";
        cout << "  EL GANADOR ES " << j2 << "\n";
        cout << "======================\n";
        cout << "\nMUCHAS FELICIDADES " << j2 << endl;
    }

    cout << " ----- GRACIAS POR JUGAR! -----\n";
    cout << "\n    Saliendo del juego.... " << endl;

    }





