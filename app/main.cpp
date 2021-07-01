#include <iostream>
#include <string>
#include <stdlib.h>
#include "funciones.h"
#include <fstream> //Libreria para lectura y escritura en archivos
#include <sstream> //Libreria para lectura y asignacion a variables de datos de archivos
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    // Ejecución con archivo
    if (argc > 1){
        string datos(argv[1]);
        ifstream archivo(datos);
        if (archivo){
                Datos Ventas[20000];
                leerArchivo(Ventas);
                regresionLineal(Ventas);
                exponencial(Ventas);
                suavizacionExponencial(Ventas);
                mediasMovilesSimple(Ventas);
                cout << "Programa finalizado" << endl;

        }
        else{
            cout << "Datos mal ingresados" << endl;
        }

    }
    // Ejecución sin archivo
    else{
        mostrarIntegrantes();
    }

    




    return 0;
}