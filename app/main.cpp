#include <iostream>
#include <string>
#include <stdlib.h>
#include "funciones.h"

using namespace std;

int main() {
    
    Datos Ventas[20000];
    leerArchivo(Ventas);
    mostrarStruct(Ventas);

    return 0;
}