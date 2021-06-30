#include <iostream>
#include <string>
#include <stdlib.h>
#include "funciones.h"
#include <fstream> //Libreria para lectura y escritura en archivos
#include <sstream> //Libreria para lectura y asignacion a variables de datos de archivos
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    if (argc > 1){
        string datos(argv[1]);
        ifstream archivo(datos);


        if (archivo){
                Datos Ventas[20000];
                leerArchivo(Ventas);
                //mostrarStruct(Ventas);
                //regresionLineal(Ventas);
                exponencial(Ventas);
                cout << "Tarea realizada" << endl;

        }
        else{
            cout << "no ha ingresado datos" << endl;
        }

    }
    else{
        cout << "no ha ingresado datos" << endl;
    }

    




    return 0;
}