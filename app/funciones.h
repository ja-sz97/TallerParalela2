#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

struct Datos {
    string created;
    int ventasTotales = 0;
};

typedef Datos Ventas[20000];


void leerArchivo(Datos Ventas []);
void mostrarStruct(Datos Ventas []);

#endif //APP_FUNCIONES_H