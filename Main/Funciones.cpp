#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "funciones.h"

using namespace std;

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


